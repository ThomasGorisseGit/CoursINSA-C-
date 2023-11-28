#include <stdio.h>
//
// Created by thoma on 28/11/2023.
//

int isPalindrome(int array[], int size){
    int j = size-1;
    int i = 0 ;
    int isPalindrome = 1;
    while(i<j && isPalindrome){
        if(array[i] != array[j]){
            isPalindrome = 0;
        }
        i++;
        j--;
    }
    return isPalindrome;
}
int main(){


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

    printf("%d\r\n",
           isPalindrome(objects,arraySize)
           );
}