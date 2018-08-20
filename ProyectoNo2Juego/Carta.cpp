/* Cenfotec – Costa Rica
 * Estructura de Datos – 2018-02
 * Nombre del archivo: Carta.cpp
 * Autor: Ángel Marín, Christhian Montes, Daniel Rodriguez
 * e-mail: amarint@cenfotec.com,cmontesa@ucenfotec.ac.cr,drodriguezr@ucenfotec.ac.cr
 * ProyectoNo2Juego – Proyecto juego con estructuras
 * Fecha de creación: Julio del 2018
 * Fecha de último cambio: Agosto del 2018
 */

#include <string>
#include <sstream>
#include "Carta.h"

using namespace std;

Carta::Carta() {
    setIdentificador(0);
    setAtaque(0);
    setDefensa(0);
}

Carta::Carta(int pIden, int pAtk, int pDef) {
    setIdentificador(pIden);
    setAtaque(pAtk);
    setDefensa(pDef);
}

void Carta::setIdentificador(int pIdentificador) {
    identificador = pIdentificador;
}

int Carta::getIdentificador() {
    return identificador;
}

void Carta::setAtaque(int pAtaque) {
    ataque = pAtaque;
}

int Carta::getAtaque() {
    return ataque;
}

void Carta::setDefensa(int pDefensa) {
    defensa = pDefensa;
}

int Carta::getDefensa() {
    return defensa;
}

string Carta::imprimirCarta() {
    stringstream impresion;
    impresion << "\nIdentificador: " << getIdentificador() << " | Ataque: "
            << getAtaque() << " | Defensa: " << getDefensa();
    return impresion.str();
}
