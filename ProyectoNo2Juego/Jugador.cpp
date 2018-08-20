/* Cenfotec – Costa Rica
 * Estructura de Datos – 2018-02
 * Nombre del archivo: Jugador.cpp
 * Autor: Ángel Marín, Christhian Montes, Daniel Rodriguez
 * e-mail: amarint@cenfotec.com,cmontesa@ucenfotec.ac.cr,drodriguezr@ucenfotec.ac.cr
 * ProyectoNo2Juego – Proyecto juego con estructuras
 * Fecha de creación: Julio del 2018
 * Fecha de último cambio: Agosto del 2018
 */

#include "Jugador.h"
#include <string>

Jugador::Jugador() {

}

Jugador::Jugador(string pAlias, int pVida, Baraja pBar, Mano pMano, Campo pCamp) {
    alias = pAlias;
    vida = pVida;
    baraja = pBar;
    mano = pMano;
    campo = pCamp;
}

void Jugador::setAlias(string pAlias) {
    alias = pAlias;
}

string Jugador::getAlias() {
    return alias;
}

void Jugador::setVida(int pVida) {
    vida = pVida;
}

int Jugador::getVida() {
    return vida;
}

void Jugador::setBaraja(Baraja pBaraja) {
    baraja = pBaraja;
}

Baraja Jugador::getBaraja() {
    return baraja;
}

void Jugador::setMano(Mano pMano) {
    mano = pMano;
}

Mano Jugador::getMano() {
    return mano;
}

void Jugador::setCampo(Campo pCampo) {
    campo = pCampo;
}

Campo Jugador::getCampo() {
    return campo;
}

string imprimirJugador() {

}