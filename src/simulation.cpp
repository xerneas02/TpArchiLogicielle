#include "simulation.hpp"
#include "grille.hpp"
#include "mt.hpp"

Simulation::Simulation(int longueur, int hauteur, int nb_individus_max, int nb_individus_infected, int dE, int dI, int dR) :
    grid(longueur, hauteur, nb_individus_max),
    nb_individus_infected(nb_individus_infected),
    dE(dE),
    dI(dI),
    dR(dR)
{
    check(nb_individus_max-nb_individus_infected >= 0);
    check(dE > 0);
    check(dI > 0);
    check(dR > 0);
    reset();
}

Simulation::~Simulation() {}

void Simulation::reset() 
{
    tour = 0;
    grid.reset(nb_individus_infected, dE, dI, dR);
}

void Simulation::afficher()
{
    cout <<  endl << endl;

    #define bordure_couleur COLOR_FOREGROUND_CYAN 
    cout << bordure_couleur;
    repeat(x, grid.longueur+2) { cout << "#"; }
    cout << '\n';

    repeat(y, grid.hauteur) 
    { 
        cout << bordure_couleur << "#" << COLOR_RESET;

        repeat(x, grid.longueur) 
        {
            if(grid.getCell(x,y).size() == 0)
            {
                cout << ' ';
            }else
            {
                switch (grid.getCell(x,y).back()->getStatut())
                {
                    case Statut::Exposed: cout << COLOR_FOREGROUND_MAGENTA << "E";  break;
                    case Statut::Infected: cout << COLOR_FOREGROUND_RED << "I";  break;
                    case Statut::Susceptible: cout << COLOR_FOREGROUND_YELLOW << "S";  break;
                    case Statut::Recovered: cout << COLOR_FOREGROUND_GREEN << "R";  break;
                    default: todo; break;
                }
            }
        }
        cout << bordure_couleur << "#" << COLOR_RESET << '\n';
    }
    repeat(x, grid.longueur+2) { cout << bordure_couleur << "#"; }
    cout << COLOR_RESET << '\n';

    int nbInfected = grid.countInfected();
    cout <<  "tour " << tour << ", " << nbInfected << " / " <<grid.nbIndividus() << " ( " << nbInfected*100.0/grid.nbIndividus() << " % ) infected" << endl;
}


void Simulation::simuler(int nb_iteration)
{
    repeat(i, nb_iteration)
    {
        afficher();
        tour++;
        grid.avanceTemps();
    }
}