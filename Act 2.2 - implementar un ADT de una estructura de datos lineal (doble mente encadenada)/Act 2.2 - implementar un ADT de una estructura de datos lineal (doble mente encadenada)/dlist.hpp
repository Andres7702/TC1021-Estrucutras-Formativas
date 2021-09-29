

#ifndef list_hpp
#define list_hpp
#include <stdio.h>

#include <string>
#include <sstream>

template <class T> class DList;

//CLASE LINK: Objeto que consiste de un valor y un apuntador hacia otro objeto Link//

template <class T>
class Link {
private:
    
    //CONSTRUCTORES//
    
    Link(T);
    Link(T, Link<T>*, Link<T>*);
    Link(const Link<T>&);

    //VARIABLES DE LINK//
    
    T value; //Valor dentro de link
    Link<T> *next; //Apuntador a siguiente objeto
    Link<T> *previous; //Apuntador a objeto previo

    //CLASE AMIGA//
    
    friend class DList<T>;
    
};

//DEFINICION DE CONSTRUCTORES//

template <class T>
Link<T>::Link(T val) : value(val), next(0), previous(0) {}

template <class T>
Link<T>::Link(T val, Link* nxt, Link* prv) : value(val), next(nxt), previous(prv)  {}

template <class T>
Link<T>::Link(const Link<T> &source) : value(source.value), next(source.next), previous(source.previous) {}


///

//CLASE LIST: Manejador de objetos de tipo Link//

template <class T>
class DList {
public:
    
    //CONSTRUCTORES//
    
    DList();
    DList(const DList<T>&);

    //METODOS//
    
    void insertion(T);
    void update(int, T) const;
    int search(T) const;
    void deleteAt(int);
    std::string toStringForward() const;
    std::string toStringBackward() const;

private:
    
    void addFirst(T val);
    void deleteFirst();
    bool empty() const;
    
    //VARIABLES DE LIST//
    
    Link<T> *head; //Apuntador al inicio de la lista
    Link<T> *tail;
    int size; //Variable de tamaño de lista

};

//DEFINICION DE CONSTRUCTORES//

template <class T>
DList<T>::DList() : head(0), size(0), tail(0) {}


//empty: devuelve true si no hay ningun elemento en la lista//

template <class T>
bool DList<T>::empty() const {
    return (head == 0);
}


//addFirst: Crea un Link nuevo con un valor recibido y despues lo hace head de la lista.//

template <class T>
void DList<T>::addFirst(T val){
    Link<T> *newLink;

    newLink = new Link<T>(val);
    newLink->next = head;
    newLink->previous = head;
    
    head = newLink;
    tail = newLink;
    size++;
}


//insertion: Recibe un valor y crea un Link nuevo y lo agrega al final de lista.//

template <class T>
void DList<T>::insertion(T val) {
    Link<T> *newLink, *p;
    
    p = head;
    
    if(empty()){
        addFirst(val);
    }
    else{
        newLink = new Link<T>(val);
        
        while(p->next != 0){
            p = p->next;
        }
        
        newLink->next = 0;
        newLink->previous = p;
        p->next = newLink;
        
        tail = newLink;
    }
    
    size++;
}


//search: Recibe un valor y devuelve la posicion en la lista de dicho valor//

template <class T>
int DList<T>::search(T val) const {
    Link<T> *p;
    
    p = head;
    int aux = 0;
    
    while (p != 0){
        if (p->value == val){
            return aux;
        }
        aux++;
        p = p->next;
    }
    return -1;
}


//update: recibe un int de posicion y un valor. Cambia el valor actual del Link//
//de posicion, por el valor nuevo recibido//

template <class T>
void DList<T>::update(int pos, T val) const{
    int aux = 0;
    Link<T> *p;
    
    if (pos > 0 or pos <= size){
        p = head;
        
        while (aux != pos){
            p = p->next;
            aux++;
        }
        
        p->value = val;
    }
}


//deleteAt: Recibe un valor de posicion y elimina ese Link de la lista//

template <class T>
void DList<T>::deleteAt(int pos) {
    Link<T> *p1;
    Link<T> *p2;
    
    p1 = head;
    int aux = 0;
    
    if ((pos > 0 or pos <= size) and size > 0){
        
        if(pos == 0){
            
            deleteFirst();
        }
        
        else{
            
            while (aux != pos-1){
                p1 = p1->next;
                aux++;
            }
            
            p2 = p1;
            
            p2 = p2->next;
            
            p1->next = p2->next;
            
            p2->next->previous = p1;
            
            delete p2;
            
            size--;
        }
    }
}

//deleteFirst: Elimina el primer elemento de una lista y cambia el head al segundo valor//

template <class T>
void DList<T>::deleteFirst(){
    Link<T> *p;

    p = head;

    head = p->next;
    p->next->previous = 0;

    delete p;
    size--;
}

//toString: Cambia la lista a texto//



template <class T>
std::string DList<T>::toStringForward() const {
    std::stringstream aux;
    Link<T> *p;
    p = head;
    aux << "[";
    while (p != 0) {
        aux << p->value;
        if (p->next != 0) {
            aux << ", ";
        }
        p = p->next;
    }
    aux << "]";
    return aux.str();
}


template <class T>
std::string DList<T>::toStringBackward() const {
    std::stringstream aux;
    Link<T> *p;
    p = tail;
    aux << "[";
    while (p != 0) {
        aux << p->value;
        if (p->previous != 0) {
            aux << ", ";
        }
        p = p->previous;
    }
    aux << "]";
    return aux.str();
}

#endif /* dlist_hpp */
