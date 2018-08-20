/* Cenfotec – Costa Rica
 * Estructura de Datos – 2018-02
 * Nombre del archivo: Baraja.h
 * Autor: Ángel Marín, Christhian Montes, Daniel Rodriguez
 * e-mail: amarint@cenfotec.com,cmontesa@ucenfotec.ac.cr,drodriguezr@ucenfotec.ac.cr
 * ProyectoNo2Juego – Proyecto juego con estructuras
 * Fecha de creación: Julio del 2018
 * Fecha de último cambio: Agosto del 2018
 */

#ifndef BARAJA_H
#define BARAJA_H

#include "PilaCartas.h"
#include <string>

using namespace std;

class Baraja {
private:
    PilaCartas pilaCartas;
public:
    Baraja();
    void setPilaCartas(PilaCartas);
    PilaCartas getPilaCartas();
    string imprimirBaraja();
};

#endif /* BARAJA_H */

