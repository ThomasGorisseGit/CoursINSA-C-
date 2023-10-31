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
unsigned int Ensemble::Intersection (const Ensemble & unEnsemble){
    int i;
    int nbElemSupp = 0;
    for(i=0;i<this->currentSize;i++){
        //parcours de l'ensemble, si elem[i] n'est pas dans unEnsemble alors 
        if( unEnsemble.Contains(this->ensemble[i]) == false ){
            // On le retirer, on augmente le compteur de 1, et on decremente i de 1 car l'ensemble à perdu un element.
            this->Retirer(this->ensemble[i]);
            nbElemSupp++;
            i--;
        }
    }
    return nbElemSupp;
}


int Ensemble::Reunir( const Ensemble & unEnsemble)
{   
    
    if(unEnsemble.EstInclus(*this) == 1 || unEnsemble.EstInclus(*this) == 2 ) return 0; 
    int nbElemAjoute = 0;
    bool estAjuste = false;

    for(int i=0;i<unEnsemble.currentSize;i++){

        if(this->currentSize == this->maxSize){
            // L'ensemble doit être ajusté Alors le resultat doit être négatif
            this->Ajuster(1);
            estAjuste = true;
        }

        if(this->Ajouter(unEnsemble.ensemble[i]) == 2){
            //Si l'element a été ajouté, on incremente le compteur du nombre d'élément ajouté
            nbElemAjoute++;
        }
    }
    if(estAjuste) nbElemAjoute = -nbElemAjoute;
    // Si l'ensemble a été ajusté alors le résultat est négatif
    this->sort();
    return nbElemAjoute;

}
unsigned int Ensemble::Ajuster(int delta){
    if(delta>0){
        // Si le delta est positif alors on l'ajoute à la taille max
        this->maxSize += delta;
    }
    else if( (delta<0) && (this->maxSize - delta >= this->currentSize) ){
        // S'il est possible de diminuer le delta alors on le fait 
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
            // Recherche de l'élement 
            founded = true;
            this->ensemble [i] = this->ensemble[this->currentSize-1];
            // Echange la position avec le dernier element de l'ensemble
            // Puis on diminue la taille de l'ensemble et on le re-trie
            this->currentSize--;
        }
        i++;
    }

    this->maxSize = this->currentSize;
    this->sort();
    return false;
}
unsigned int Ensemble::Retirer( const Ensemble & unEnsemble){
    unsigned int precedenteCardMax = this->maxSize;
    // On stock l'ancienne cardinalité
    unsigned int nbElemSupp = 0;
    for(int i =0;i<unEnsemble.currentSize;i++){
        if(this->Retirer( unEnsemble.ensemble[i])){
            nbElemSupp++;
        }
        this->maxSize = precedenteCardMax; // We must not change the previous max card -> we set it back to the previous card max (changed in this->Retirer(int element))
    }
    return nbElemSupp;
}
crduAjouter Ensemble::Ajouter (int value) {
    if(this->Contains(value)) return DEJA_PRESENT; 
    else if(this->currentSize == this->maxSize) return PLEIN;
    else{
        // Ajoute à la fin, 
        this->ensemble[currentSize] = value;
        // incrémente la taille
        this->currentSize++;
        //Retrie l'ensemble
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
                // Si un element n'est pas contenu alors l'ensemble n'est pas inclus
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
        // Puisque les deux ensembles sont triés, on verifie que les elements sont egaux un par un.
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
