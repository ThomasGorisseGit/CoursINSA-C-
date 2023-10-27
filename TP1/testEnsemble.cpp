#include <iostream>
#include "Ensemble.h"

using namespace std;

int main(){
    int array[5]  = {1,4,2};
    int array2[5]  = {1,4,2,3,1};
    Ensemble e (5);
    e.Afficher();
   
    Ensemble e2 (3);
    e2.Afficher();
   
    Ensemble e3 (0);
    e3.Afficher();

    Ensemble e4(array, 3);
    e4.Afficher();
    Ensemble e5 (array2,5); 
    e5.Afficher();
    cout << e4.EstInclus(e5) << "\r\n"; 
    

ls -labs
}   