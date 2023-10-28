/*************************************************************************
                           Ensemble  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Ensemble> (fichier Ensemble.h) ----------------
#if ! defined ( ENSEMBLE_H )
#define ENSEMBLE_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes
#define MAX_SIZE 5
//------------------------------------------------------------------ Types

enum crduEstInclus {NON_INCLUSION, INCLUSION_LARGE, INCLUSION_STRICT};
//------------------------------------------------------------------------
// Rôle de la classe <Ensemble>
//
//
//------------------------------------------------------------------------

class Ensemble 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    void Afficher ( void );
    bool EstEgal ( const Ensemble & unEnsemble) const;
    crduEstInclus EstInclus (const Ensemble &unEnsemble) const;
    bool Contains(int value) const;

//-------------------------------------------- Constructeurs - destructeur

    Ensemble ( unsigned int maxSize = MAX_SIZE);
    // Mode d'emploi :
    //
    // Contrat :
    //

    Ensemble ( int t [], unsigned int nbElements);
    // Mode d'emploi :
    //
    // Contrat :
    //


    virtual ~Ensemble ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------currentSize- Méthodes protégées
    bool EnsembleContains(int value, const Ensemble &unEnsemble ) const;
    void sort();
    
//----------------------------------------------------- Attributs protégés


int *ensemble;
unsigned int maxSize;
unsigned int currentSize;

};

//-------------------------------- Autres définitions dépendantes de <Ensemble>

#endif // ENSEMBLE_H

