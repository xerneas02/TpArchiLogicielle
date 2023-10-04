#include "individu.h"

// Constructeur avec paramètres
Individu::Individu(int dE, int dI, int dR) : dE(dE), dI(dI), dR(dE) {}

Statut Individu::getStatut() const {
    return statut;
}

void Individu::setStatut(Statut nouveauStatut) {
    statut = nouveauStatut;
}

int Individu::getTempsPasseDansStatut() const {
    return tempsPasseDansStatut;
}

void Individu::setTempsPasseDansStatut(int temps) {
    tempsPasseDansStatut = temps;
}

int Individu::getDE() const {
    return dE;
}

int Individu::getDI() const {
    return dI;
}

int Individu::getDR() const {
    return dR;
}

void Individu::setDE(int duree) {
    dE = duree;
}

void Individu::setDI(int duree) {
    dI = duree;
}

void Individu::setDR(int duree) {
    dR = duree;
}

