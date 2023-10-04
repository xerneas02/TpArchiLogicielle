#include "__base__.hpp"
#include "grille.hpp"
#include "mt.hpp"

Grille::Grille(int longueur, int hauteur, int nb_individus_max) : 
    nb_individus(nb_individus_max), 
    longueur(longueur), 
    hauteur(hauteur) 
{
    check(longueur > 0);
    check(hauteur > 0);
    check(nb_individus_max > 0);

    cellules1D = vector<vector<Individu*>>(longueur*hauteur);
    repeat(x, longueur)
    {
        repeat(y, hauteur)
        {
            cellules1D.push_back(vector<Individu*>(8));
        }
    }

    individus = make_array(Individu, nb_individus_max);
    repeat(i, nb_individus_max){ individus[i] = Individu(); }
}

vector<Individu*>& Grille::getCell(int x, int y)
{
    return cellules1D[y*longueur+x];
}


void Grille::reset(int nb_infected, int dE, int dI, int dR)
{
    repeat(x, longueur)
    {
        repeat(y, hauteur)
        {
            getCell(x,y).clear();
        }
    }
    repeat(i, nb_individus)
    {
        ajouterIndividu(i, rngX(), rngY());
        individus[i].reset(dE, dI, dR);
    }
    repeat(i, nb_infected)
    {
        individus[i].setStatut(Statut::Infected);
    }
}

Grille::~Grille() 
{       
    while(!cellules1D.empty())
    {
        cellules1D.pop_back();
    }
    free(individus);
    longueur = 0;
    hauteur = 0;
    nb_individus = 0;
    individus = null;
}

void Grille::ajouterIndividu(int idx, int x, int y) 
{
    getCell(x,y).push_back(&individus[idx]);
    individus[idx].x = x;
    individus[idx].y = y;
}

int Grille::rngX() { return mt_genrand_int32() % longueur; }
int Grille::rngY() { return mt_genrand_int32() % hauteur; }

void Grille::moveIndividuRngPos(int idx)
{
    // Obtenir les nouvelles coordonnées pour l'individu
    int nouvelleX = rngX();
    int nouvelleY = rngY();

    Individu* individu = &individus[idx];
    auto c = getCell(individu->x, individu->y);
    // joy of C++...
    c.erase(std::find(c.begin(), c.end(), individu));
    ajouterIndividu(idx, nouvelleX, nouvelleY);
}

void Grille::deplacerIndividus() 
{
    repeat(i, nb_individus)
    {
        Individu& individu = individus[i];

        // Avancez le temps de l'individu
        individu.avanceTemps();
        moveIndividuRngPos(i);
    }
}

int Grille::countAdj(int x, int y)
{
    int nVoisin = 0;
    for (int i = x - 1; i <= x + 1; ++i) 
    {
        for (int j = y - 1; j <= y + 1; ++j) 
        {
            int x_tore = (i + longueur) % longueur;
            int y_tore = (j + hauteur) % hauteur;

            nVoisin += getCell(x_tore,y_tore).size();
        }
    }
    return nVoisin;
}


void Grille::avanceTemps()
{    
    int nVoisin, proba;
    repeat(i, nb_individus)
    {
        if (individus[i].statut == Statut::Susceptible)
        { 
            nVoisin = countAdj(individus[i].x, individus[i].y);
            proba   = 1 - exp(-0.5*nVoisin);

            if (proba < mt_genrand_real1())
            {
                individus[i].setStatut(Statut::Exposed);
            }
        }
    }

    deplacerIndividus();
}

int Grille::countInfected()
{
    int s = 0;
    repeat(i, nb_individus)
    {
        if(individus[i].getStatut() == Statut::Infected){ s++; }
    }
    return s;
}
int Grille::nbIndividus(){ return nb_individus; }