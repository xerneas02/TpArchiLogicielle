#include "grille.hpp"
#include "mt.hpp"
#include <vector>

Grille::Grille(int largeur, int hauteur) : largeur(largeur), hauteur(hauteur) {
    cellules.resize(largeur, std::vector<std::vector<Individu*>>(hauteur));
}

Grille::~Grille() {
    for (int x = 0; x < largeur; ++x) {
        for (int y = 0; y < hauteur; ++y) {
            for (Individu* individu : cellules[x][y]) {
                delete individu;
            }
        }
    }
}

void Grille::ajouterIndividu(Individu* individu, int x, int y) {
    cellules[x][y].push_back(individu);
}

void Grille::deplacerIndividus() {
    for (int i = 0; i < largeur; ++i) {
        for (int j = 0; j < hauteur; ++j) {
            for (auto it = cellules[i][j].begin(); it != cellules[i][j].end();) {
                Individu* individu = *it;

                // Avancez le temps de l'individu
                individu->avanceTemps();

                // Obtenir les nouvelles coordonnées pour l'individu
                int nouvelleX = mt_uniform(0, largeur);
                int nouvelleY = mt_uniform(0, hauteur);

                it = cellules[i][j].erase(it);

                // Déplacez l'individu aux nouvelles coordonnées
                ajouterIndividu(individu, nouvelleX, nouvelleY);

            }
        }
    }
}