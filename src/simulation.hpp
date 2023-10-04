#ifndef SIMULATION_H
#define SIMULATION_H

#include "__base__.hpp"
#include "grille.hpp"
#include "individu.hpp"
#include "mt.hpp"

class Simulation 
{
    friend class Individu;
    friend class Grid;

private:
    Grille grid;
    int nb_individus_infected = 20;
    int dE = 3;
    int dI = 7;
    int dR = 365;
    int tour;

public:
    Simulation(int longueur = 300, int hauteur = 300, int nb_individus_max = 20000, int nb_individus_infected = 20, int dE = 3, int dI = 7, int dR = 365);
    ~Simulation();

    void reset();
    void afficher();

    void simuler(int nb_iteration = 730);
};

#endif 