#include <stdio.h>
//
// Created by thoma on 28/11/2023.
//

void displayArray(int arr[],int size){
    printf("[");
    for(int i =0;i<size;i++){
        printf(" %d,",arr[i]);
    }
    printf("]\n");
}

int backpack(int objects[],int arrSize,int bpSize){

    if(bpSize == 0){
        return 1;
    }else if(bpSize<0){
        return 0;
    }
    int j;
    for(j=0;j<arrSize;j++){
        if(backpack(objects,arrSize,bpSize-objects[j]) == 1){
            return 1;
        }
    }
    return 0;
}

int main(){
    int capacity = 0;
    scanf("%d",&capacity);

    int objects[100];

    int insertValue = 0;
    int arraySize = 0;
    int stopInsert = 0;
    while(arraySize < 100 && !stopInsert){
        scanf("%d",&insertValue);
        if(insertValue != -1){
            objects[arraySize] = insertValue;
            arraySize++;
        }else{
            stopInsert = 1;
        }
    }
    int canWeFill = backpack(objects, arraySize, capacity);
    if(canWeFill){
        printf("OUI\r\n");
    }
    else{
        printf("NON\r\n");
    }
    return 1;
}