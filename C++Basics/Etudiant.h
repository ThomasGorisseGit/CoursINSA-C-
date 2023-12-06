//
// Created by thoma on 06/12/2023.
//

#ifndef C_BASICS_ETUDIANT_H
#define C_BASICS_ETUDIANT_H
#include "Personne.h"
#include <iostream>

class Etudiant : public Personne{
public :
    Etudiant(const int annee,const char * nom):Personne(nom){
        this->annee = annee;
    }
    void Afficher()const;

protected:
    int annee;
};

#endif //C_BASICS_ETUDIANT_H

void Etudiant::Afficher()const{
    Personne::Afficher();
    cout << this->annee << endl;
}
