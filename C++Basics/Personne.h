//
// Created by thoma on 05/12/2023.
//

#ifndef C_BASICS_PERSONNE_H
#define C_BASICS_PERSONNE_H

#endif //C_BASICS_PERSONNE_H
#include <iostream>
#include <cstring>
using namespace std;
class Personne{
    public:
        Personne(char * leNom){
            nom = new char[20];
            strcpy(this->nom,leNom);
        }
        void Afficher()const
        {
            cout << "nom = "<<nom<<endl;
        }
protected:
        char * nom;
};