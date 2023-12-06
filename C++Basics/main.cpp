//
// Created by thoma on 05/12/2023.
//
#include <cstring>
#include "Personne.h"
int main(){
    char unNom [10];
    std::strcpy(unNom,"marie");
    Personne p(unNom);
    p.Afficher();
    unNom[0] = 'M';
    p.Afficher();
    return 0;
}