/* Cenfotec – Costa Rica
 * Estructura de Datos – 2018-02
 * Nombre del archivo: NodoCartas.cpp
 * Autor: Ángel Marín, Christhian Montes, Daniel Rodriguez
 * e-mail: amarint@cenfotec.com,cmontesa@ucenfotec.ac.cr,drodriguezr@ucenfotec.ac.cr
 * ProyectoNo2Juego – Proyecto juego con estructuras
 * Fecha de creación: Julio del 2018
 * Fecha de último cambio: Agosto del 2018
 */

#include "NodoCartas.h"

NodoCartas::NodoCartas() {
    setSiguiente(NULL);
}

void NodoCartas::setCarta(Carta pCarta) {
    carta = pCarta;
}

Carta NodoCartas::getCarta() {
    return carta;
}

void NodoCartas::setSiguiente(NodoCartas* pSiguiente) {
    siguiente = pSiguiente;
}

NodoCartas* NodoCartas::getSiguiente() {
    return siguiente;
}

