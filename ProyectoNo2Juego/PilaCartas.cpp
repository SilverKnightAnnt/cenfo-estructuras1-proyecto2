/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "PilaCartas.h"
#include <sstream>

PilaCartas::Baraja() {
    setTope(NULL);
    setLongitud(0);
}

void PilaCartas::setTope(NodoCartas* pNodo) {
    tope = pNodo;
}

NodoCartas* PilaCartas::getTope() {
    return tope;
}

void PilaCartas::setLongitud(int pLong) {
    longitud = pLong;
}

int PilaCartas::getLongitud() {
    return longitud;
}

bool PilaCartas::pilaVacia() {
    if (getTope() == NULL) {
        return true;
    }
    return false;
}

void PilaCartas::insertarCarta(Carta pCarta) {
    NodoCartas* nuevoNodo = new NodoCartas();
    nuevoNodo->setCarta(pCarta);
    if (pilaVacia()) {
        setTope(nuevoNodo);
    } else {
        nuevoNodo->setSiguiente(getTope());
        setTope(nuevoNodo);
    }
    longitud++;
}

NodoCartas* PilaCartas::obtenerTope() {
    if (pilaVacia()) {
        return NULL;
    } else {
        NodoCartas* aux = getTope();
        while (aux != NULL) {
            setTope(aux->getSiguiente());
            return aux;
        }
    }
    longitud--;
}

string PilaCartas::verPilaCartas(){
     stringstream concat;
    if (getTope() != NULL) {
        NodoCartas* aux = getTope();
        while (aux != NULL) {
            concat << aux->getCarta().imprimirCarta();
            aux = aux->getSiguiente();
        }
    }
    return concat.str();
}