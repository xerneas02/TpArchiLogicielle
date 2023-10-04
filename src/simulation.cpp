#include "simulation.hpp"
#include "grille.hpp"
#include "mt.hpp"

Simulation::Simulation(int largeur = 300, int hauteur = 300, int nb_individus_max = 20000, int nb_individus_infected = 20, int dE = 3, int dI = 7, int dR = 365) :
    nb_individus_infected(nb_individus_infected),
    dE(dE),
    dI(dI),
    dR(dR),
{
    grid = Grille(largeur, hauteur, nb_individus_max);
    nb_individus_infected = nb_individus_infected;
    reset();
}

Simulation::~Simulation() {}

void Simulation::reset() 
{
    grid.reset(nb_individus_infected, dE, dI, dR);
}

void Simulation::afficher()
{
    #define bordure_couleur COLOR_FOREGROUND_CYAN 
    cout << bordure_couleur;
    repeat(x, grid.largeur+2) { cout << "#"; }
    cout << '\n';

    repeat(y, grid.hauteur) 
    { 
        cout << bordure_couleur << "#" << COLOR_RESET;

        repeat(x, grid.largeur) 
        {
            if(grid.cellules[x][y].size() == 0)
            {
                cout << ' ';
            }else
            {
                switch (grid.cellules[x][y].back()->getStatut())
                {
                    case Statut::Exposed: cout << COLOR_FOREGROUND_MAGENTA << "E";  break;
                    case Statut::Infected: cout << COLOR_FOREGROUND_RED << "I";  break;
                    case Statut::Susceptible: cout << COLOR_FOREGROUND_YELLOW << "S";  break;
                    case Statut::Recovered: cout << COLOR_FOREGROUND_GREEN << "R";  break;
                    default: todo; break;
                }
            }
        }
        cout << '\n';
        cout << bordure_couleur << "#" << COLOR_RESET;
    }
    repeat(x, grid.largeur+2) { cout << bordure_couleur << "#" << COLOR_RESET; }
    cout << endl;
}


void Simulation::simuler(int nb_iteration)
{
    repeat(i, nb_iteration)
    {
        grid.avanceTemps();
        afficher();
    }
}