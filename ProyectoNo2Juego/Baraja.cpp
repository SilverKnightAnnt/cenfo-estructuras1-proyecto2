/* Cenfotec – Costa Rica
 * Estructura de Datos – 2018-02
 * Nombre del archivo: Baraja.cpp
 * Autor: Ángel Marín, Christhian Montes, Daniel Rodriguez
 * e-mail: amarint@cenfotec.com,cmontesa@ucenfotec.ac.cr,drodriguezr@ucenfotec.ac.cr
 * ProyectoNo2Juego – Proyecto juego con estructuras
 * Fecha de creación: Julio del 2018
 * Fecha de último cambio: Agosto del 2018
 */

#include "Baraja.h"

Baraja::Baraja() {

}

void Baraja::setPilaCartas(PilaCartas pPila) {
    pilaCartas = pPila;
}

PilaCartas Baraja::getPilaCartas() {
    return pilaCartas;
}

string Baraja::imprimirBaraja() {
    return pilaCartas.verPilaCartas();
}