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
    this->currentSize = 0;
    this->ensemble = new int[nbElements];
    for(unsigned int i =0;i<nbElements;i++){
        if(this->contains( t[i] ) == false){
            this->ensemble[this->currentSize] = t[i];
            this->currentSize ++;
        }
    }
    this->maxSize = nbElements;
    this->sort();
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
    cout << this->currentSize <<"\r\n";
    cout << this->maxSize <<"\r\n";
    
    cout << "{";
    for (unsigned int i =0;i<this->currentSize;i++){
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
    unsigned int i =0;
    while(i<this->currentSize && !founded){
        if(this->ensemble[i]==value){
            founded = true;
        }
        i++;
    } 
    return founded;
}
void Ensemble::sort(){
    unsigned int i,j;
    int switchVariables;
    for(i = this->currentSize;i>0;i--){
        for(j = 0;j<i-1;j++){
            if(this->ensemble[j+1]<this->ensemble[j]){
                switchVariables = this->ensemble[j+1];
                this->ensemble[j+1] = this->ensemble[j];
                this->ensemble[j] = switchVariables;
            }
        }
    }
}
//----------------------------------------------------- Méthodes protégées

