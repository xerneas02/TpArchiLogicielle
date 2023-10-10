#ifndef GRILLE_H
#define GRILLE_H

#include "__base__.hpp"
#include "individu.hpp"
#include "mt.hpp"
class Grille 
{
    friend class Individu;
    friend class Simulation;

private:
    int nb_individus;
    Individu* individus;
    int status_count[4];

    int longueur;
    int hauteur;

    vector<vector<Individu*>> cellules1D;
    vector<Individu*>& getCell(int x, int y);

    int rngX();
    int rngY();

public:
    Grille(int longueur, int hauteur, int nb_individus_max);
    ~Grille();

    // Ajouter un individu à la grille
    void moveIndividuRngPos(int idx);
    void ajouterIndividu(int idx, int x, int y);

    void avanceTemps();

    int countInfected();
    int nbIndividus();

    int countVoisinsInfectees(int x, int y);

    // Déplacer tous les individus aléatoirement dans la grille
    void deplacerIndividus();
    void propagation();
    void reset(int nb_infected, int dE, int dI, int dR);
};

#endif // GRILLE_H