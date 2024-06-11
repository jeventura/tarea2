#ifndef ARBOL_H
#define ARBOL_H

#include <iostream>


struct Nodo {
    int dato;
    Nodo *der;
    Nodo *izq;
    float coord_x;
    float coord_y;
};

// Declaración de funciones
Nodo *crearNodo(int, float, float);
void insertarNodo(Nodo *&, int, float, float);
void preOrder(Nodo *);
void inOrder(Nodo *);
void postOrder(Nodo *);

#endif // ARBOL_H
