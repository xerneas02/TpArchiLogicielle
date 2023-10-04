#include "__base__.hpp"
#include "individu.hpp"

int main() 
{
    // Création d'un objet Individu avec des durées de vie initiales
    Individu individu(0, 0, 2, 3, 5);
    
    // Obtention du statut initial
    cout << "Statut initial : " << individu.getStatut() << endl;
    // Obtention des nouvelles durées de vie
    cout << "Nouvelle durée de vie pour Exposed : " << individu.getDureeDeVie(Statut::Exposed) << " jour" << endl;
    cout << "Nouvelle durée de vie pour Infected : " << individu.getDureeDeVie(Statut::Infected) << " jours" << endl;
    cout << "Nouvelle durée de vie pour Recovered : " << individu.getDureeDeVie(Statut::Recovered) << " jours" << endl;

    individu.setStatut(Statut::Exposed);

    cout << "Nouveau statut : " << individu.getStatut() << endl;
    // Avance du temps de 4 jours
    repeat(i, 4) 
    {
        individu.avanceTemps();
    }

    // Obtention du nouveau statut et de la durée de vie dans le statut actuel
    cout << "Nouveau statut : " << individu.getStatut() << endl;
    cout << "Temps passé dans le statut actuel : " << individu.getTempsPasseDansStatut() << " jours" << endl;

    // Avance du temps de 4 jours
    repeat(i, 4) 
     {
        individu.avanceTemps();
    }

    // Obtention du nouveau statut et de la durée de vie dans le statut actuel
    cout << "Nouveau statut : " << individu.getStatut() << endl;
    cout << "Temps passé dans le statut actuel : " << individu.getTempsPasseDansStatut() << " jours" << endl;

    // Avance du temps de 10 jours
    repeat(i, 10)
    {
        individu.avanceTemps();
    }

    // Obtention du nouveau statut et de la durée de vie dans le statut actuel
    cout << "Nouveau statut : " << individu.getStatut() << endl;
    cout << "Temps passé dans le statut actuel : " << individu.getTempsPasseDansStatut() << " jours" << endl;

    return 0;
}
