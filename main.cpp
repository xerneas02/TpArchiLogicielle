#include <iostream>
#include "individu.h"

int main() {
    // Création d'un objet Individu avec des durées de vie initiales
    Individu individu(2, 3, 5);
    

    // Obtention du statut initial
    std::cout << "Statut initial : " << individu.getStatut() << std::endl;
    // Obtention des nouvelles durées de vie
    std::cout << "Nouvelle durée de vie pour Exposed : " << individu.getDureeDeVie(Statut::Exposed) << " jour" << std::endl;
    std::cout << "Nouvelle durée de vie pour Infected : " << individu.getDureeDeVie(Statut::Infected) << " jours" << std::endl;
    std::cout << "Nouvelle durée de vie pour Recovered : " << individu.getDureeDeVie(Statut::Recovered) << " jours" << std::endl;

    individu.setStatut(Statut::Exposed);

    std::cout << "Nouveau statut : " << individu.getStatut() << std::endl;
    // Avance du temps de 4 jours
    for (int i = 0; i < 4; ++i) {
        individu.avanceTemps();
    }

    // Obtention du nouveau statut et de la durée de vie dans le statut actuel
    std::cout << "Nouveau statut : " << individu.getStatut() << std::endl;
    std::cout << "Temps passé dans le statut actuel : " << individu.getTempsPasseDansStatut() << " jours" << std::endl;

    // Avance du temps de 4 jours
    for (int i = 0; i < 4; ++i) {
        individu.avanceTemps();
    }

    // Obtention du nouveau statut et de la durée de vie dans le statut actuel
    std::cout << "Nouveau statut : " << individu.getStatut() << std::endl;
    std::cout << "Temps passé dans le statut actuel : " << individu.getTempsPasseDansStatut() << " jours" << std::endl;

    // Avance du temps de 10 jours
    for (int i = 0; i < 10; ++i) {
        individu.avanceTemps();
    }

    // Obtention du nouveau statut et de la durée de vie dans le statut actuel
    std::cout << "Nouveau statut : " << individu.getStatut() << std::endl;
    std::cout << "Temps passé dans le statut actuel : " << individu.getTempsPasseDansStatut() << " jours" << std::endl;



    return 0;
}
