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
    individus[idx].x = x;
    individus[idx].y = y;
    getCell(x,y).push_back(&individus[idx]);
}

int Grille::rngX() { return mt_genrand_int32() % longueur; }
int Grille::rngY() { return mt_genrand_int32() % hauteur; }

void Grille::moveIndividuRngPos(int idx)
{
    // Obtenir les nouvelles coordonnées pour l'individu
    int nouvelleX = rngX();
    int nouvelleY = rngY();

    Individu* individu = &individus[idx];
    // auto is a joke
    vector<Individu*>& c = getCell(individu->x, individu->y);
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

void Grille::propagation()
{
    int nbVoisinInfected;

    repeat(i, nb_individus)
    {
        if (individus[i].statut == Statut::Susceptible)
        { 
            nbVoisinInfected = countVoisinsInfectees(individus[i].x, individus[i].y);
            auto proba   = 1 - exp(-0.5*nbVoisinInfected);

            if (proba > mt_genrand_real1())
            {
                individus[i].setStatut(Statut::Exposed);
            }
        }
    }
}


int Grille::countVoisinsInfectees(int x, int y)
{
    int nbInfected = 0;
    for (int i = x - 1; i <= x + 1; i-=-1) 
    {
        for (int j = y - 1; j <= y + 1; j-=-1) 
        {
            int x_tore = (i + longueur) % longueur;
            int y_tore = (j + hauteur ) % hauteur;

            for(auto v : getCell(x_tore,y_tore))
            {
                if(v->getStatut() == Statut::Infected){ nbInfected++; }
            }
        }
    }
    return nbInfected;
}


void Grille::avanceTemps()
{    
    propagation();
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