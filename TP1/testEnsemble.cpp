#include <iostream>
#include "Ensemble.h"

using namespace std;

int main(){
    int array[5]  = {1,4,2,3,1};
    Ensemble e1 (array, 5);
    Ensemble e2 (-1);

    e1.Afficher();
}   