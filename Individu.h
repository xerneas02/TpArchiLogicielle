// individu.h

#ifndef INDIVIDU_H
#define INDIVIDU_H

#include <unordered_map>

// Déclaration de l'énumération pour le statut
enum class Statut {
    Susceptible,
    Exposed,
    Infected,
    Recovered
};


class Individu {
public:
    Individu();
    Individu(int dE, int dI, int dR);


    Statut getStatut() const;

    void setStatut(Statut nouveauStatut);


    int getTempsPasseDansStatut() const;


    int getDureeDeVie(Statut statut) const;

    void setDureeDeVie(Statut statut, int duree);

    void avanceTemps();


private:
    Statut statut;

    int tempsPasseDansStatut; //Temps ecoulé dans le statut courrant en jour

    std::unordered_map<Statut, int> dureesDeVie; // Durées de vie des differents status

    std::unordered_map<Statut, Statut> statutSuivant = {
        {Statut::Susceptible, Statut::Exposed    }, 
        {Statut::Exposed,     Statut::Infected   },      
        {Statut::Infected,    Statut::Recovered  },
        {Statut::Recovered,   Statut::Susceptible}
    };

};


#endif // INDIVIDU_H
