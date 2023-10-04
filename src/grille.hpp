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

    int largeur;
    int hauteur;
    vector<vector<vector<Individu*>>> cellules; // Structure de données pour stocker les individus

public:
    Grille(int largeur, int hauteur, int nb_individus_max);
    ~Grille();

    // Ajouter un individu à la grille
    void moveIndividuRngPos(int idx);
    void ajouterIndividu(int idx, int x, int y);

    // Déplacer tous les individus aléatoirement dans la grille
    void deplacerIndividus();
    void reset(int nb_infected, int dE, int dI, int dR);
};

#endif // GRILLE_H