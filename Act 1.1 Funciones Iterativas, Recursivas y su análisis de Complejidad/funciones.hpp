//
//  funciones.hpp
//  kk
//
//  Created by Andrés Acevedo on 25/08/21.
//

#ifndef funciones_hpp
#define funciones_hpp


#include <stdio.h>
#include <iostream>
using namespace std;

class Funciones{
public:
    int sumaIterativa(int);
    int sumaRecursiva(int);
    int sumaDirecta(int);
};

int Funciones::sumaIterativa(int n){
    int res=0;
    for(int i=0;i<=n;i++){
        res= res+i;
    }
    return res;
};

int Funciones::sumaRecursiva(int n){
    if (n == 0) {
        return 0;
    }
    else{
        return (n + sumaRecursiva(n-1));
    }
};

int Funciones::sumaDirecta(int n){
    int res = (n*(n+1))/2;
    return res;
};

#endif /* funciones_hpp */
