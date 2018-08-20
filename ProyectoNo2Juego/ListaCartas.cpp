/* Cenfotec – Costa Rica
 * Estructura de Datos – 2018-02
 * Nombre del archivo: ListaCartas.cpp
 * Autor: Ángel Marín, Christhian Montes, Daniel Rodriguez
 * e-mail: amarint@cenfotec.com,cmontesa@ucenfotec.ac.cr,drodriguezr@ucenfotec.ac.cr
 * ProyectoNo2Juego – Proyecto juego con estructuras
 * Fecha de creación: Julio del 2018
 * Fecha de último cambio: Agosto del 2018
 */

#include <string>
#include <iostream>
#include <sstream>
#include "ListaCartas.h"

ListaCartas::ListaCartas() {
    setCabeza(NULL);
    setTamanno(0);
}

void ListaCartas::setTamanno(int pTamanno) {
    tamanno = pTamanno;
}

int ListaCartas::getTamanno() {
    return tamanno;
}

void ListaCartas::setCabeza(NodoCartas* pNodo) {
    cabeza = pNodo;
}

NodoCartas* ListaCartas::getCabeza() {
    return cabeza;
}

bool ListaCartas::listaVacia() {
    if (getCabeza() == NULL) {
        return true;
    }
    return false;
}

void ListaCartas::insertarCarta(Carta pCarta) {
    NodoCartas* nuevoNodo = new NodoCartas();
    nuevoNodo->setCarta(pCarta);
    if (listaVacia()) {
        setCabeza(nuevoNodo);
    } else {
        nuevoNodo->setSiguiente(getCabeza());
        setCabeza(nuevoNodo);
    }
    tamanno++;
}

string ListaCartas::verListaCartas() {
    stringstream concat;
    if (getCabeza() != NULL) {
        NodoCartas* aux = getCabeza();
        while (aux != NULL) {
            concat << aux->getCarta().imprimirCarta();
            aux = aux->getSiguiente();
        }
    }
    return concat.str();
}

NodoCartas* ListaCartas::buscarCartaPorIdentificador(Carta pCarta) {
    if (listaVacia()) {
        return NULL;
    } else {
        NodoCartas* aux = getCabeza();
        while (aux != NULL) {
            if (aux->getCarta().getIdentificador() == pCarta.getIdentificador()) {
                return aux;
            } else {
                aux = aux->getSiguiente();
            }
        }
    }
}

void ListaCartas::eliminarCarta(Carta pCartaEliminar) {
    if (listaVacia()) {
    } else {
        if (getCabeza()->getCarta().getIdentificador() == pCartaEliminar.getIdentificador()) {
            setCabeza(getCabeza()->getSiguiente());
        } else {
            NodoCartas* aux = getCabeza();
            while (aux != NULL && aux->getSiguiente() != NULL && aux->getSiguiente()->getCarta().getIdentificador() !=
                    pCartaEliminar.getIdentificador()) {
                aux = aux->getSiguiente();
            }
            if (aux != NULL && aux->getSiguiente() != NULL) {
                aux->setSiguiente(aux->getSiguiente()->getSiguiente());
            }
        }
    }
}