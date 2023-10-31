#include <iostream>
#include "Ensemble.h"

using namespace std;

int main(){
    int array[5]  = {1,4,2};
    int array2[8]  = {1,4,2,3,1,12,82,19};
    
    Ensemble e4(array, 3);
    Ensemble e5 (array2,8); 
    e4.Ajuster(4);
    cout << e4.Reunir(e5)<<"\r\n";
    e4.Afficher();

}   