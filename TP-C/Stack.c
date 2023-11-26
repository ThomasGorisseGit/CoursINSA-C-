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
void display(Pile p){
    if(!isEmpty(p)){

        for(int i =0;i<p.allocated - p.filled;i++){
            printf("| %d |\n",p.array[p.filled+i]);
        }
        printf("|___|");

    }
    else{
        printf("Stack is empty\n");
    }
}

int pop(Pile *p){
    int elem = p->array[p->filled];
    p->filled++;
    return elem;
}
Pile * init(){
    Pile *p = malloc(sizeof(Pile));
    p->allocated=10;
    p->filled= p->allocated;
    return p;
}

int main(){
    Pile *p = init();
    display(*p);
    push(p,3);
    push(p,4);
    push(p,5);
    display(*p);
    int elem = pop(p);
    printf("\n Pop item : %d\n",elem);
    push(p,2);
    display(*p);
}