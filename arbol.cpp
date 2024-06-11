#include "arbol.h"
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define BLUE    "\033[34m"
#define YELLOW  "\033[33m"

Nodo *crearNodo(int dato, float coord_x, float coord_y) {
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato = dato;
    nuevo_nodo->der = NULL;
    nuevo_nodo->izq = NULL;
    nuevo_nodo->coord_x = coord_x;
    nuevo_nodo->coord_y = coord_y;
    return nuevo_nodo;
}

void insertarNodo(Nodo *&arbol, int dato, float coord_x, float coord_y) {
    if (arbol == NULL) { // Si el árbol está vacío
        Nodo *nuevo_nodo = crearNodo(dato, coord_x, coord_y);
        arbol = nuevo_nodo;
    } else { // Si el árbol tiene un nodo o más
        float valorRaiz = arbol->coord_y; // Nos da el valor de la raíz
        if (coord_y <= valorRaiz) { // Evalúa si la coordenada Y es menor o igual a la raíz, insertamos en árbol izquierdo
            insertarNodo(arbol->izq, dato, coord_x, coord_y);
        } else { // Si es mayor, lo insertamos en el árbol derecho
            insertarNodo(arbol->der, dato, coord_x, coord_y);
        }
    }
}

void preOrder(Nodo *arbol) {
    if (arbol == NULL) return;
    std::cout << RED << "Coordenada Y: " << arbol->coord_y << RESET << "Dato: " << arbol->dato << ", Coordenada X: " << arbol->coord_x <<std::endl;
    preOrder(arbol->izq);
    preOrder(arbol->der);
}

void inOrder(Nodo *arbol) {
    if (arbol == NULL) return;
    inOrder(arbol->izq);
    std::cout << RED << "Coordenada Y: " << arbol->coord_y << RESET <<"Dato: " << arbol->dato << ", Coordenada X: " << arbol->coord_x << std::endl;
    inOrder(arbol->der);
}

void postOrder(Nodo *arbol) {
    if (arbol == NULL) return;
    postOrder(arbol->izq);
    postOrder(arbol->der);
    std::cout << RED << "Coordenada Y: " << arbol->coord_y<< RESET << "Dato: " << arbol->dato << ", Coordenada X: " << arbol->coord_x  << std::endl;
}
