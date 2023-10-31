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
enum crduAjouter {DEJA_PRESENT,PLEIN,AJOUTE};
//------------------------------------------------------------------------
// Rôle de la classe <Ensemble>
//
//
//------------------------------------------------------------------------

class Ensemble 
{
    // Cette classe permet la gestion d'un ensemble d'entiers.
    // Elle est composée d'un ensemble d'entier,
    // d'une taille courante correspondant au nombre d'éléments de l'entier.
    // d'une taille maximale correspondant au nombre d'éléments maximal que l'ensemble peut contenir.

    // Vous trouverez ci-dessous la liste des méthodes utilisées et utilisables par l'ensemble : 

public:
//----------------------------------------------------- Méthodes publiques
  
    void Afficher ( void );
    // Méthode d'affichange, sans parametres
    // Mode d'emploi : Appeler simplement la fonction sur un ensemble 

    bool EstEgal ( const Ensemble & unEnsemble) const;
    // Méthode qui vérifie l'égalité entre deux ensembles.
    // Aucuns ensemble n'est modifié.
    // Mode d'emploi : 
    // Appeler sur un ensemble la méthode et en passant un second ensemble en paramètre.
    // return true s'ils sont égaux et false s'ils ne le sont pas.

    bool Contains(int value) const;
    // Méthode qui prends en paramètre une valeur et qui return true si elle est incluse dans l'ensemble et false sinon.
    // Utilisable sur n'importe quel ensemble. Celui-ci ne sera pas modifié.

    crduEstInclus EstInclus (const Ensemble &unEnsemble) const;
    // Méthode qui utilise l'enum crduEstInclus pour retourner une valeure. Il prends en paramètre un ensemble ( celui-ci ne sera pas modifié)
    // La méthode s'utilise sur un ensemble et ne le modifie pas. Elle renvoie le type d'inclusion (Non inclus, inclusion large, inclusion stricte)

    crduAjouter Ajouter( int value);
    // Méthode qui prends en paramètre une valeur et renvoie le status de l'ajout.
    // DEJA_PRESENT si l'element est déjà dans l'ensemble,
    // PLEIN si la currentCard de l'ensemble est égale à la cardinalité maximale
    // AJOUTE si l'element a été ajouté
    // Cette méthode s'appelle sur n'importe quel ensemble et essaye d'ajouter la valeur passé en paramètre à l'ensemble.

    unsigned int Ajuster(int delta);
    // Méthode qui prends un entier en paramètre afin d'ajuster la cardinalité d'un ensemble (augmentation ou diminution de la cardinalité maximale)
    // Cette méthode essaye de modifier la cardinalité de l'ensemble courant.
    // Elle renvoie la cardinalité maximale de l'ensemble après les potentielles modifications
    // Il est possible lors d'une diminution de rencontrer un echec lorsque la cardinalité maximale - l'ajustement soit inférieur a la cardinalité courrante.

    bool Retirer( int element );
    // Cette méthode modifie l'ensemble courrant en essayant de retirer l'element (entier) passé en paramètre.
    // elle renvoie true si l'élement a été supprimé, false sinon.
    // L'ensemble se retrouve trié, avec l'élement supprimé s'il était contenu dans l'ensemble.
    // la cardinalité maximale toujours rendue égale à la cardinalité courrante
    unsigned int Retirer(const Ensemble & unEnsemble);
    // Cette méthode retire tous les élements contenus dans l'ensemble unEnsemble de l'ensemble courrant.
    // Si les valeurs de unEnsemble sont contenues dans l'ensemble courrant alors elles sont supprimés.
    // La méthode prends donc en paramètre un ensemble d'élements a supprimer.
    // Elle renvoie le nombre d'élements supprimés de l'ensemble courrant.
    // l'ensemble passé en paramètre n'est pas modifié

    int Reunir (const Ensemble & unEnsemble);
    // Cette méthode prends en paremètre un ensemble (qui ne sera pas modifié) et ajoute tous les elements contenus dans unEnsemble à l'ensemble courrant
    // Si l'ensemble courrant est ré-ajusté, alors la valeur de retour est négative.
    // La méthode retourne le nombre d'élement ajouté à l'élement courrant.
    // L'ensemble courant est égal à l'union des deux ensemble (trié).

    unsigned int Intersection (const Ensemble & unEnsemble);
    // Cette méthode prends en paramètre un ensemble (qui ne sera pas modifié)
    // Et réalise l'intersection des deux ensembles. 
    // Cette intersection sera stockée dans l'ensemble courrant.
    // Tous les éléments de l'ensemble qui ne sont pas contenus dans unEnsemble seront supprimés.
    // La cardinalité maximale devient égale à la cardinalité courrante.
    // Cette méthode renvoie le nombre d'éléments supprimés de l'ensemble courrant

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
    void sort();
    
//----------------------------------------------------- Attributs protégés


    int *ensemble; // Liste d'entier
    unsigned int maxSize; // Taille maximale de l'ensemble
    unsigned int currentSize; // Nombre d'éléments contenus dans l'ensemble

};

//-------------------------------- Autres définitions dépendantes de <Ensemble>

#endif // ENSEMBLE_H

