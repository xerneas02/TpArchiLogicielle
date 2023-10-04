#ifndef GRILLE_H
#define GRILLE_H

#include <vector>
#include "individu.hpp"

class Grille {
public:
    Grille(int largeur, int hauteur);
    ~Grille();

    // Ajouter un individu à la grille
    void ajouterIndividu(Individu* individu, int x, int y);

    // Déplacer tous les individus aléatoirement dans la grille
    void deplacerIndividus();

private:
    int largeur;
    int hauteur;
    std::vector<std::vector<std::vector<Individu*>>> cellules; // Structure de données pour stocker les individus
    
};

#endif // GRILLE_H