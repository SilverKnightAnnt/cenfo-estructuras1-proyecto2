/* Cenfotec – Costa Rica
 * Estructura de Datos – 2018-02
 * Nombre del archivo: NodoPuntuacion.cpp
 * Autor: Ángel Marín, Christhian Montes, Daniel Rodriguez
 * e-mail: amarint@cenfotec.com,cmontesa@ucenfotec.ac.cr,drodriguezr@ucenfotec.ac.cr
 * ProyectoNo2Juego – Proyecto juego con estructuras
 * Fecha de creación: Julio del 2018
 * Fecha de último cambio: Agosto del 2018
 */

#include "NodoPuntuacion.h"

NodoPuntuacion::NodoPuntuacion() {
    setInfo(NULL);
    setSiguiente(NULL);
}

NodoPuntuacion::NodoPuntuacion(Puntuacion* pNewRecord) {
    setInfo(pNewRecord);
    setSiguiente(NULL);
}

NodoPuntuacion::~NodoPuntuacion() {
}

void NodoPuntuacion::setInfo(Puntuacion* newRecord) {
    record = newRecord;
}

void NodoPuntuacion::setSiguiente(NodoPuntuacion* nuevo) {
    siguiente = nuevo;
}

Puntuacion* NodoPuntuacion::getInfo() {
    return record;
}

NodoPuntuacion* NodoPuntuacion::getSiguiente() {
    return siguiente;
}