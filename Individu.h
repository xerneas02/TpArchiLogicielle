// individu.h

#ifndef INDIVIDU_H
#define INDIVIDU_H

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

    void setTempsPasseDansStatut(int temps);


    int getDE() const;
    int getDI() const;
    int getDR() const;

    void setDE(int duree);
    void setDI(int duree);
    void setDR(int duree);


private:
    Statut statut;

    int tempsPasseDansStatut; //Temps ecoulé dans le statut courrant

    int dE; //Durré de vie statut Exposed
    int dI; //Durré de vie statut Infected
    int dR; //Durré de vie statut Recovered
};


#endif // INDIVIDU_H
