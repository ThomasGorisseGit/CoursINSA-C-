//
// Created by thoma on 05/12/2023.
//
#include <cstring>
#include "Etudiant.h"
#include <iostream>
static void aff(const Personne *p){
    p->Afficher() ;
    cout << endl;
}

int main(){

    Personne *pp;

    pp = new Personne("A");
    aff(pp);
    delete pp;

    pp = new Etudiant(21,"B");
    aff(pp);
    delete pp;


    return 0;
}