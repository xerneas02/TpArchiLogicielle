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

    simulation_nb = 0;
    result = null;

    reset();
}

Simulation::~Simulation() 
{
    if(result != null) { fclose(result); }
}

void Simulation::reset() 
{
    simulation_nb++;
    tour = 0;
    grid.reset(nb_individus_infected, dE, dI, dR);

    if(result != null) { fclose(result); }


    char file_name[128];
    sprintf(file_name, "resultat/resultat_%i.csv", simulation_nb);

    remove(file_name);

    result = fopen((const char*)file_name, "w+");
    #define SEP ";"
    if(result){ fprintf(result, "Susceptible" SEP "Exposed" SEP "Infected" SEP "Recovered\n"); }
}

void Simulation::afficher()
{
    cout <<  endl << endl;


    cout <<  " ";
    repeat(x, grid.longueur) { cout << x%10; }
    cout <<  "\n";

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
                    case Statut::Exposed    : cout << COLOR_FOREGROUND_MAGENTA << "E"; break;
                    case Statut::Infected   : cout << COLOR_FOREGROUND_RED     << "I"; break;
                    case Statut::Susceptible: cout << COLOR_FOREGROUND_YELLOW  << "S"; break;
                    case Statut::Recovered  : cout << COLOR_FOREGROUND_GREEN   << "R"; break;
                    default: todo; break;
                }
            }
        }
        cout << bordure_couleur << "#" << COLOR_RESET << y%10 << '\n';
    }
    repeat(x, grid.longueur+2) { cout << bordure_couleur << "#"; }
    cout << COLOR_RESET << '\n';

    int nbInfected = grid.countInfected();
    cout <<  "tour " << tour << ", " << nbInfected << " / " <<grid.nbIndividus() << " ( " << nbInfected*100.0/grid.nbIndividus() << " % ) infected" << endl;
}

void Simulation::fileSaveStep()
{
    if(result == null){ return; }
    int count[4] = {0,0,0,0};
    repeat(i, grid.nb_individus)
    {
        count[(int)(grid.individus[i].getStatut())]++;
    }
    fprintf(result, "%i" SEP "%i" SEP "%i" SEP "%i\n", count[0], count[1], count[2], count[3]);
}

void Simulation::simuler(int nb_iteration)
{
    repeat(i, nb_iteration)
    {
        fileSaveStep();
        tour++;
        grid.avanceTemps();
    }
}