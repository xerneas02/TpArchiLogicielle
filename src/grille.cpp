#include "grille.hpp"
#include "mt.hpp"
#include <vector>

Grille::Grille(int largeur, int hauteur, int nb_individus_max) : nb_individus(nb_individus_max), largeur(largeur), hauteur(hauteur) 
{
    individus = make_array(Individu, nb_individus_max);
    repeat(i, nb_individus_max)
    {
        individus[i] = Individu(0,0,1,1,1);
    }
    cellules.resize(largeur, vector<vector<Individu*>>(hauteur));
}

Grille::~Grille() 
{    
    free(individus);
    individus = null;
}

void Grille::ajouterIndividu(int idx, int x, int y) 
{
    cellules[x][y].push_back(&individus[idx]);
}

void Grille::deplacerIndividus() 
{
    repeat(i, nb_individus)
    {
        Individu* individu = &individus[i];

        // Avancez le temps de l'individu
        individu->avanceTemps();

        // Obtenir les nouvelles coordonnées pour l'individu
        int nouvelleX = mt_genrand_int32() % largeur;
        int nouvelleY = mt_genrand_int32() % hauteur;
        ;
        
        auto c = cellules[individu->x][individu->y];
        // joy of C++...
        c.erase(std::find(c.begin(), c.end(), individu));
        ajouterIndividu(i, nouvelleX, nouvelleY);
    }
}

int Grille::countAdj(int x, int y){
    int nVoisin = 0;
    for (int i = x - 1; i <= x + 1; ++i) {
        for (int j = y - 1; j <= y + 1; ++j) {
            int x_tore = (i + largeur) % largeur;
            int y_tore = (j + hauteur) % hauteur;

            nVoisin += cellules[x_tore][y_tore].size();
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