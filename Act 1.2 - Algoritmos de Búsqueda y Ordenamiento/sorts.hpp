#ifndef sorts_hpp
#define sorts_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstring>
#include <list>

using namespace std;

template <class T>
class Sorts{
private:
    void swap(int,int,vector<T>&);
    void copiaArray(vector<T>&, vector<T>&, int, int);
    void juntaArray(vector<T>&, vector<T>&, int, int,int);
    void Split(vector<T>&, vector<T>&, int, int);
public:
    vector<T> ordenaBurbuja(vector<T>&);
    vector<T> ordenaSeleccion(vector<T>&);
    vector<T> ordenaMerge(const vector<T>&);
    int busqBinaria(vector<T>& ,int);
    int busqSecuencial(vector<T>& ,int);
};

template <class T>
void Sorts<T>::swap(int i, int j, vector<T> &v){
    T aux = v[i];
    v[i]=v[j];
    v[j]=aux;
}

template <class T>
vector<T> Sorts<T>::ordenaBurbuja(vector<T> &v){
    for (int i = v.size()-1;i>0;i--) {
        for (int j = 0; j < i; j++) {
            if(v[j]>v[j+1]){
                swap(j,j+1,v);
            }
        }
    }
    return v;
}

template <class T>
vector<T> Sorts<T>::ordenaSeleccion(vector<T> &v){
    int aux;
    for (int i = v.size() - 1; i > 0; i--) {
        aux = 0;
        for (int j = 1; j <= i; j++) {
            if (v[j] > v[aux]) {
                aux = j;
            }
        }
        if (aux != i) {
            swap(i,aux,v);
        }
    }
    return v;
}

template <class T>
void Sorts<T>::copiaArray(vector<T> &A, vector<T> &B, int low, int high) {
    for (int i = low; i <= high; i++) {
        A[i] = B[i];
    }
}

template <class T>
void Sorts<T>::juntaArray(vector<T> &A, vector<T> &B, int low, int mid, int high) {
    int i, j, k;

    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid &&j <= high) {
        if (A[i] < A[j]) {
            B[k] = A[i];
            i++;
        } else {
            B[k] = A[j];
            j++;
        }
        k++;
    }
    if (i > mid) {
        for (; j <= high; j++) {
            B[k++] = A[j];
        }
    } else {
        for (; i <= mid; i++) {
            B[k++] = A[i];
        }
    }
}

template <class T>
void Sorts<T>::Split(vector<T> &A, vector<T> &B, int low, int high) {
    int mid;

    if ( (high - low) < 1 ) {
        return;
    }
    mid = (high + low) / 2;
    Split(A, B, low, mid);
    Split(A, B, mid + 1, high);
    juntaArray(A, B, low, mid, high);
    copiaArray(A, B, low, high);
}

template <class T>
vector<T> Sorts<T>::ordenaMerge(const vector<T> &source) {
    vector<T> v(source);
    vector<T> tmp(v.size());

    Split(v, tmp, 0, v.size() - 1);
    return v;
}


template<class T>
int Sorts<T>::busqSecuencial(vector<T> &v, int valor){
    for(int i=0; i<v.size();i++){
        if(v[i]==valor){
            return i;
        }
    }
    return -1;
}

template <class T>
int Sorts<T>::busqBinaria(vector<T> &v, int valor){
    int low=0;
    int high= v.size()-1;
    while(high-low!=1){
        int mid=(low+high)/2;
        if (valor == v[mid]){
            return mid;
        }
        if(v[mid]>valor){
            high=mid;
        }
        else{
            low=mid;
        }
    }
    return -1;
}

#endif /* sorts_hpp */
