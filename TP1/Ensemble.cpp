/*************************************************************************
                           Ensemble  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Ensemble> (fichier Ensemble.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Ensemble.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Ensemble::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
Ensemble & Ensemble::operator = ( const Ensemble & unEnsemble )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur


Ensemble::Ensemble (unsigned int maxSize )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Ensemble> utilisant la maxSize" << endl;
#endif
    this->ensemble = new int[maxSize];
    this->maxSize = maxSize;
    this->currentSize = 0;

} //----- Fin de Ensemble

Ensemble::Ensemble(int t [], unsigned int nbElements){
    //Insertion des valeurs qui ne sont pas déjà contenues dans l'ensemble
    int nbInsert = 0;
    this->ensemble = new int[nbElements];
    for(int i =0;i<nbElements;i++){
        if(!this->contains( t[i] )){
            this->ensemble[nbInsert] = t[i];
            nbInsert ++;
        }
    }

    this->currentSize = nbInsert;
    this->maxSize = nbElements;
}


Ensemble::~Ensemble ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Ensemble>" << endl;
#endif
    delete this->ensemble;
} //----- Fin de ~Ensemble

void Ensemble::Afficher(){
    cout << "{";
    for (int i =0;i<this->currentSize;i++){
        cout << this->ensemble[i];
        if(i<this->currentSize-1){
            cout << ", ";
        }
    }
    cout << "} \r\n";
}

//------------------------------------------------------------------ PRIVE

bool Ensemble::contains(int value){
    bool founded = false;
    int i =0;
    while(i<this->currentSize && !founded){
        if(this->ensemble[i]==value){
            founded = true;
        }
        i++;
    } 
    return founded;
}
//----------------------------------------------------- Méthodes protégées

