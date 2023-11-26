#include <stdio.h>
#include <malloc.h>

//
// Created by thoma on 26/11/2023.
//
typedef struct {
    int allocated;
    int filled;
    int *array;
} Pile;
int isFull(Pile p){
    return p.filled == 0;
}
int isEmpty(Pile p){
    return p.filled == p.allocated;
}
void push(Pile *p, int element){
    if(!isFull(*p)){
        p->array[p->filled-1] = element;
        p->filled--;
    }
}
Pile * init(){
    Pile *p = malloc(sizeof(Pile));
    p->allocated=10;
    p->filled= p->allocated;
    return p;
}

int main(){


}