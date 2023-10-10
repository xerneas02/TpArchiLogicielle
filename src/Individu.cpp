#include "individu.hpp"
#include "grille.hpp"

inline string statutToString(Statut statut) 
{
    switch (statut) 
    {
        case Statut::Susceptible: return "Susceptible";
        case Statut::Exposed:     return "Exposed";
        case Statut::Infected:    return "Infected";
        case Statut::Recovered:   return "Recovered";
        default: return "Unknown";
    }
}

std::ostream& operator<<(std::ostream& os, Statut statut) 
{
    return os << statutToString(statut);
}

Individu::Individu(){ x = 0; y = 0;}

void Individu::reset(int dE, int dI, int dR)
{
    tempsPasseDansStatut = 0;
    statut               = Statut::Susceptible;
    setDureeDeVie(Statut::Susceptible, -1);
    setDureeDeVie(Statut::Exposed,    (int)mt_neg_exp(dE));
    setDureeDeVie(Statut::Infected,   (int)mt_neg_exp(dI)); 
    setDureeDeVie(Statut::Recovered,  (int)mt_neg_exp(dR));
}

Statut Individu::getStatut() const 
{
    return statut;
}

void Individu::setStatut(Statut nouveauStatut) 
{
    statut = nouveauStatut;
}

int Individu::getTempsPasseDansStatut() const 
{
    return tempsPasseDansStatut;
}

void Individu::avanceTemps(Grille& g)
{
    tempsPasseDansStatut++;

    if (getDureeDeVie(statut) != -1 && tempsPasseDansStatut >= getDureeDeVie(statut))
    {
        Statut oldStatut = statut;
        statut = statutSuivant(statut);

        if(statut != oldStatut)
        {
            g.status_count[(int)oldStatut]--;
            g.status_count[(int)statut]++;
        }
        tempsPasseDansStatut = 0;
    }
}

int Individu::getDureeDeVie(Statut statut) const 
{
    return dureesDeVie[(int)statut];
}

void Individu::setDureeDeVie(Statut statut, int duree)
{
    dureesDeVie[(int)statut] = duree;
}


Statut Individu::statutSuivant(Statut s)
{
    return (Statut)(((int)s+1) % 4);
}