#include<iostream>



template <typename T>
class Nodo{

public:
    T valor;
    Nodo* siguiente;

    Nodo(int Valor, T* Siguiente):
        valor(Valor), siguiente(siguiente){}

    Nodo(int Valor):
        valor(Valor), siguiente(nullptr){}

};


template<typename T>
class ListaEnlazada{

private:
    Nodo* raiz;

public:
    ListaEnlazada(Nodo* elem):
        raiz(elem){}



}

int main(){

}