//
// Created by thoma on 05/12/2023.
//

#ifndef C_BASICS_PERSONNE_H
#define C_BASICS_PERSONNE_H

#include <iostream>
#include <cstring>

using namespace std;
class Personne{
    public:
        Personne(const char * leNom){
            nom = new char[20];
            strcpy(this->nom,leNom);
        }


    virtual void Afficher() const;

protected:
        char * nom;
};
#endif //C_BASICS_PERSONNE_H

void Personne::Afficher() const {
    cout <<nom;
}