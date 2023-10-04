#include "individu.h"
#include <unordered_map>

Individu::Individu(){
    setDureeDeVie(Statut::Susceptible, -1);
    setDureeDeVie(Statut::Exposed, -1);
    setDureeDeVie(Statut::Infected, -1);
    setDureeDeVie(Statut::Recovered, -1);
}

Individu::Individu(int dE, int dI, int dR){
    setDureeDeVie(Statut::Susceptible, -1);
    setDureeDeVie(Statut::Exposed, dE);
    setDureeDeVie(Statut::Infected, dI);
    setDureeDeVie(Statut::Recovered, dR);
}

Statut Individu::getStatut() const {
    return statut;
}

void Individu::setStatut(Statut nouveauStatut) {
    statut = nouveauStatut;
}

int Individu::getTempsPasseDansStatut() const {
    return tempsPasseDansStatut;
}

void Individu::avanceTemps(){
    tempsPasseDansStatut++;

    if (tempsPasseDansStatut >= dureesDeVie[statut]){
        statut = statutSuivant[statut];
        tempsPasseDansStatut = 0;
    }
}

int Individu::getDureeDeVie(Statut statut) const {
    auto it = dureesDeVie.find(statut);
    if (it != dureesDeVie.end()) {
        return it->second; //Accée à la second partie de l'iterateur (la valeur)
    } else {
        return 0;
    }
}

void Individu::setDureeDeVie(Statut statut, int duree){
    dureesDeVie[statut] = duree;
}

