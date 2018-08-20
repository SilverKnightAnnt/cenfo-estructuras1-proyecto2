/* Cenfotec – Costa Rica
 * Estructura de Datos – 2018-02
 * Nombre del archivo: NodoTurno.cpp
 * Autor: Ángel Marín, Christhian Montes, Daniel Rodriguez
 * e-mail: amarint@cenfotec.com,cmontesa@ucenfotec.ac.cr,drodriguezr@ucenfotec.ac.cr
 * ProyectoNo2Juego – Proyecto juego con estructuras
 * Fecha de creación: Julio del 2018
 * Fecha de último cambio: Agosto del 2018
 */

#include "NodoTurno.h"

NodoTurno::NodoTurno() {
    setInfo(NULL);
    setSiguiente(NULL);
}

NodoTurno::NodoTurno(Jugador* nuevoJugador) {
    setInfo(nuevoJugador);
    setSiguiente(NULL);
}

NodoTurno::~NodoTurno() {
}

void NodoTurno::setSiguiente(NodoTurno* pSiguiente) {
    siguiente = pSiguiente;
}

void NodoTurno::setInfo(Jugador* pNuevo) {
    jugadorActual = pNuevo;
}

NodoTurno* NodoTurno::getSiguiente() {
    return siguiente;
}

Jugador* NodoTurno::getInfo() {
    return jugadorActual;
}