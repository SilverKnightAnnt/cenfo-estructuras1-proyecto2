/* Cenfotec – Costa Rica
 * Estructura de Datos – 2018-02
 * Nombre del archivo: PilaCartas.cpp
 * Autor: Ángel Marín, Christhian Montes, Daniel Rodriguez
 * e-mail: amarint@cenfotec.com,cmontesa@ucenfotec.ac.cr,drodriguezr@ucenfotec.ac.cr
 * ProyectoNo2Juego – Proyecto juego con estructuras
 * Fecha de creación: Julio del 2018
 * Fecha de último cambio: Agosto del 2018
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
            longitud--;
            return aux;
        }
    }
}

string PilaCartas::verPilaCartas() {
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