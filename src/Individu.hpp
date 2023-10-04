#ifndef INDIVIDU_H
#define INDIVIDU_H

#include "__base__.hpp"
#include "mt.hpp"

// Déclaration de l'énumération pour le statut
enum class Statut
{
    Susceptible = 0,
    Exposed = 1,
    Infected = 2,
    Recovered = 3,
};

ostream& operator<<(ostream& os, Statut statut);


class Individu 
{
    friend class Grille;

private:
    int x;
    int y;

    Statut statut;

    int tempsPasseDansStatut; //Temps ecoulé dans le statut courrant en jour
    int dureesDeVie[4]; // Durées de vie des differents status

public:
    Individu(int x, int y, int dE, int dI, int dR);


    Statut getStatut() const;
    void setStatut(Statut nouveauStatut);

    int getTempsPasseDansStatut() const;

    int getDureeDeVie(Statut statut) const;
    void setDureeDeVie(Statut statut, int duree);

    void avanceTemps();

private:
    Statut statutSuivant(Statut s);
    int statutDureesDeVie();
};


#endif // INDIVIDU_H
