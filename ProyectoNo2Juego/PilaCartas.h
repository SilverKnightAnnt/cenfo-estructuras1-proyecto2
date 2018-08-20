/* Cenfotec – Costa Rica
 * Estructura de Datos – 2018-02
 * Nombre del archivo: PilaCartas.h
 * Autor: Ángel Marín, Christhian Montes, Daniel Rodriguez
 * e-mail: amarint@cenfotec.com,cmontesa@ucenfotec.ac.cr,drodriguezr@ucenfotec.ac.cr
 * ProyectoNo2Juego – Proyecto juego con estructuras
 * Fecha de creación: Julio del 2018
 * Fecha de último cambio: Agosto del 2018
 */

#ifndef PILACARTAS_H
#define PILACARTAS_H

#include "NodoCartas.h"
#include <string>

using namespace std;

class PilaCartas {
private:
    NodoCartas* tope;
    int longitud = 0;
    bool pilaVacia();
public:
    Baraja();
    void setTope(NodoCartas*);
    NodoCartas* getTope();
    void setLongitud(int);
    int getLongitud();
    void insertarCarta(Carta);
    NodoCartas* obtenerTope();
    string verPilaCartas();
};

#endif /* PILACARTAS_H */

