/* Cenfotec – Costa Rica
 * Estructura de Datos – 2018-02
 * Nombre del archivo: Campo.cpp
 * Autor: Ángel Marín, Christhian Montes, Daniel Rodriguez
 * e-mail: amarint@cenfotec.com,cmontesa@ucenfotec.ac.cr,drodriguezr@ucenfotec.ac.cr
 * ProyectoNo2Juego – Proyecto juego con estructuras
 * Fecha de creación: Julio del 2018
 * Fecha de último cambio: Agosto del 2018
 */

#include <string>
#include <sstream>
#include "Campo.h"

Campo::Campo() {
    cartas[5];
}

void Campo::colocarCarta(Carta pCarta, int posicion) {
    cartas[posicion] = pCarta;
}

bool Campo::posicionamiento(int posi) {
    if (cartas[posi].getIdentificador() != 0) {
        return true;
    }
    return false;
}

Carta Campo::verDetalleCarta(Carta pCarta) {
    Carta error = Carta(1000, 300, 200);
    for (int i = 0; i < 5; i++) {
        if (cartas[i].getIdentificador() == pCarta.getIdentificador()) {
            return cartas[i];
        }
    }
    return error;
}

void Campo::eliminarCarta(Carta pCarta) {
    Carta dropper[5];
    for (int i = 0; i < 5; i++) {
        if (cartas[i].getIdentificador() == pCarta.getIdentificador()) {
            cartas[i] = dropper[i];
        }
    }
}

string Campo::imprimirCampo() {
    stringstream impresion;
    for (int i = 0; i < 5; i++) {
        impresion << "    | " << cartas[i].getIdentificador() << " |  ";
    }
    return impresion.str();
}