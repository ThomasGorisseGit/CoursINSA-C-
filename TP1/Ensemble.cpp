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
unsigned int Ensemble::Ajuster(int delta){
    if(delta>0){
        this->maxSize += delta;
    }
    else if( (delta<0) && (this->maxSize - delta >= this->currentSize) ){
        this->maxSize -= delta;
    }
    return this->maxSize;
}
bool Ensemble::Retirer( int element ){

    bool founded = false;
    int i =0;
    while(!founded && i<this->currentSize)
    {
        if(this->ensemble[i] == element){
            founded = true;
            this->ensemble [i] = this->ensemble[this->currentSize-1];
            this->currentSize--;
        }
        i++;
    }

    this->maxSize = this->currentSize;
    return false;
}
crduAjouter Ensemble::Ajouter (int value) {
    if(this->Contains(value)) return DEJA_PRESENT;
    else if(this->currentSize == this->maxSize) return PLEIN;
    else{
        this->ensemble[currentSize] = value;
        this->currentSize++;
        this->sort();
        return AJOUTE;
    }
}

crduEstInclus Ensemble::EstInclus (const Ensemble &unEnsemble) const {
    if (this->EstEgal(unEnsemble))
    {
        return INCLUSION_LARGE;
    }
    else if(this->currentSize < unEnsemble.currentSize)
    {   
        int i=0;
        while (i<this->currentSize)
        {   
            if(!unEnsemble.Contains(this->ensemble[i]))
            {
                return NON_INCLUSION;
            }
            i++;
        }
        return INCLUSION_STRICT;
    }
    return NON_INCLUSION;
}

bool Ensemble::EstEgal ( const Ensemble & unEnsemble) const {
    if (this->currentSize != unEnsemble.currentSize)
    {
        return false;
    }
    bool isEqual=true;
    unsigned int i =0;
    while(i< this->currentSize && isEqual )
    {
        if(this->ensemble[i] != unEnsemble.ensemble[i])
        {
            isEqual=false;
        }
        i++;
    }
    return isEqual;
}


void Ensemble::Afficher(){
    cout << this->currentSize <<"\r\n";
    cout << this->maxSize <<"\r\n";
    cout << "{";
    for (unsigned int i =0;i<this->currentSize;i++){
        cout << this->ensemble[i];
        if(i<this->currentSize-1){
            cout << ",";
        }
    }
    cout << "} \r\n";
}
bool Ensemble::Contains(int value) const{
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
        if(this->Contains( t[i] ) == false){
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



//------------------------------------------------------------------ PRIVE


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
