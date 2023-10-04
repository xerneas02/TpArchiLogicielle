#include "grille.hpp"
#include "mt.hpp"
#include <vector>

Grille::Grille(int largeur, int hauteur, int nb_individus_max) : nb_individus(nb_individus_max), largeur(largeur), hauteur(hauteur) 
{
    individus = make_array(Individu, nb_individus_max);
    cellules.resize(largeur, vector<vector<Individu*>>(hauteur));
}

void Grille::reset(int nb_infected, int dE, int dI, int dR)
{
    repeat(i, nb_individus)
    {
        moveIndividuRngPos(i);
        individus[i].reset(dE, dI, dR);
    }
    repeat(i, nb_infected)
    {
        individus[i].setStatut(Statut::Infected);
    }
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

void Grille::moveIndividuRngPos(int idx)
{
    // Obtenir les nouvelles coordonnées pour l'individu
    int nouvelleX = mt_genrand_int32() % largeur;
    int nouvelleY = mt_genrand_int32() % hauteur;

    Individu* individu = &individus[idx];
    auto c = cellules[individu->x][individu->y];
    // joy of C++...
    c.erase(std::find(c.begin(), c.end(), individu));
    ajouterIndividu(idx, nouvelleX, nouvelleY);
}

void Grille::deplacerIndividus() 
{
    repeat(i, nb_individus)
    {
        Individu* individu = &individus[i];

        // Avancez le temps de l'individu
        individu->avanceTemps();
        moveIndividuRngPos(i);
    }
}