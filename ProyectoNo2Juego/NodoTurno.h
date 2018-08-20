/* Cenfotec – Costa Rica
 * Estructura de Datos – 2018-02
 * Nombre del archivo: NodoTurno.h
 * Autor: Ángel Marín, Christhian Montes, Daniel Rodriguez
 * e-mail: amarint@cenfotec.com,cmontesa@ucenfotec.ac.cr,drodriguezr@ucenfotec.ac.cr
 * ProyectoNo2Juego – Proyecto juego con estructuras
 * Fecha de creación: Julio del 2018
 * Fecha de último cambio: Agosto del 2018
 */

#ifndef NODOTURNOS_H
#define NODOTURNOS_H
#include <stdlib.h>
#include "Jugador.h"

class NodoTurno {
private:
    NodoTurno* siguiente;
    Jugador* jugadorActual;
public:
    NodoTurno();
    NodoTurno(Jugador*);
    virtual ~NodoTurno();
    void setSiguiente(NodoTurno*);
    void setInfo(Jugador*);
    NodoTurno* getSiguiente();
    Jugador* getInfo();
};

#endif /* NODOTURNOS_H */

