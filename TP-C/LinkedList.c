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

int getValue(Liste liste,int index){
    int i=0;
    Case* parse = liste.current;
    while(i<index && parse->prochain != NULL){
        parse = parse->prochain;
        i++;
    }
    if(parse->prochain == NULL && i!=index) return -1;
   return parse->valeur;
}
int getIndex(Liste liste,int element){
    Case* parse = liste.current;
    int founded = 0;
    int index =0;
    while(parse->prochain != NULL && !founded)
    {
        if(element == parse->valeur){
            founded = 1;
        }else{
            index++;
        }
        parse = parse->prochain;

    }
    if(founded == 0) index = -1;
    return index;

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

    printf("\n Val pop : %d\n",val);
    printf("GetValue : ");
    printf("%d\t",getValue(*maListe,0));
    printf("%d\t",getValue(*maListe,100));
    printf("%d\n",getValue(*maListe,3));
    printf("GetIndex : ");
    printf("%d\t",getIndex(*maListe,99));
    printf("%d\t",getIndex(*maListe,0));
    printf("%d\n",getIndex(*maListe,100));


}