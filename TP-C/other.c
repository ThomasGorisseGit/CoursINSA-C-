#include <stdio.h>
#include <strings.h>
//
// Created by thoma on 29/11/2023.
//

void main(){
    char str1[] = "JAMES, ";
    char str2[15] = "BOND ";
    strcat(str2,str1);
    printf("%s",str2);
    printf("%s",str1);

}