/* Cenfotec – Costa Rica
 * Estructura de Datos – 2018-02
 * Nombre del archivo: Puntuacion.cpp
 * Autor: Ángel Marín, Christhian Montes, Daniel Rodriguez
 * e-mail: amarint@cenfotec.com,cmontesa@ucenfotec.ac.cr,drodriguezr@ucenfotec.ac.cr
 * ProyectoNo2Juego – Proyecto juego con estructuras
 * Fecha de creación: Julio del 2018
 * Fecha de último cambio: Agosto del 2018
 */

#include "Puntuacion.h"
#include <sstream>

Puntuacion::Puntuacion() {
    setPuntuacion(0);
}

Puntuacion::~Puntuacion() {
}

void Puntuacion::setNomJugador(string pNomPlayer) {
    nomJugador = pNomPlayer;
}

void Puntuacion::setPuntuacion(int pPuntuacion) {
    puntuacion = pPuntuacion;
}

string Puntuacion::getNomJugador() {
    return nomJugador;
}

int Puntuacion::getPuntuacion() {
    return puntuacion;
}

string Puntuacion::toString() {
    stringstream contenido;
    contenido << "Nombre: " << getNomJugador()
            << " Puntaje: " << getPuntuacion();
    return contenido.str();
}

