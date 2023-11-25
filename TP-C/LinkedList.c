//
// Created by thoma on 25/11/2023.
//

#include <stdio.h>
#include <malloc.h>

typedef struct Case {
    int valeur;
    struct Case* prochain;
}Case;

typedef struct list{
    Case* current;
    Case* last;
}Liste;


Liste* init(){
    Case* first = malloc(sizeof(Case));
    first->valeur = 0;

    Liste* maListe = malloc(sizeof (Liste));
    maListe->current = first;
    maListe->last = first;
    maListe->current->prochain = NULL;
    return maListe;
}

void ajouterEnFin(Liste* liste, int valeur){
    liste->last->prochain = malloc(sizeof (Case));
    liste->last = liste->last->prochain;
    liste->last->valeur = valeur;
    liste->last->prochain=NULL;
}

void afficher(Liste liste){
    while(liste.current != NULL){
        printf(" %d |",liste.current->valeur);
        liste.current = liste.current->prochain;
    }
}

void ajouterAuDebut(Liste* liste, int valeur){
    Case* maCase = malloc(sizeof (Case));
    maCase->valeur = valeur;
    maCase->prochain = liste->current;
    liste->current = maCase;
}
int pop(Liste* liste){
    int val = liste->last->valeur;
    Case* parse = liste->current;
    while(parse->prochain->prochain != NULL){
        parse = parse->prochain;
        liste->last = parse;
    }
    parse->prochain->valeur = 0;
    parse->prochain = NULL;
    return val;
}
int main(){

    Liste * maListe = init();
    ajouterEnFin(maListe, 10);
    ajouterEnFin(maListe, 10);
    ajouterEnFin(maListe, 10);
    ajouterEnFin(maListe, 10);
    ajouterEnFin(maListe, 12);
    ajouterAuDebut(maListe,1);
    ajouterAuDebut(maListe,99);

    int val = pop(maListe);
    afficher(*maListe);

    printf("\n Val pop : %d",val);
}