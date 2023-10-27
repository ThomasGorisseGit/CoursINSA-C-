#include <iostream>
#include "Ensemble.h"

using namespace std;

int main(){
    int array[5]  = {1,4,2,3,1};
   
    Ensemble e (5);
    e.Afficher();
   
    Ensemble e2 (3);
    e2.Afficher();
   
    Ensemble e3 (0);
    e3.Afficher();

    Ensemble e4;
    e4.Afficher();
    Ensemble e5 (array,5); 
    e5.Afficher();
    cout << e4.EstEgal(e) << "\r\n"; 
    cout << e4.EstEgal(e5) << "\r\n"; 


}   