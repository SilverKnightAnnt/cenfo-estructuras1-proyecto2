/* Cenfotec – Costa Rica
 * Estructura de Datos – 2018-02
 * Nombre del archivo: ColaTurnos.h
 * Autor: Ángel Marín, Christhian Montes, Daniel Rodriguez
 * e-mail: amarint@cenfotec.com,cmontesa@ucenfotec.ac.cr,drodriguezr@ucenfotec.ac.cr
 * ProyectoNo2Juego – Proyecto juego con estructuras
 * Fecha de creación: Julio del 2018
 * Fecha de último cambio: Agosto del 2018
 */

#ifndef COLATURNOS_H
#define COLATURNOS_H
#include "NodoTurno.h"
#include <string>

using namespace std;

class ColaTurnos {
private:
    NodoTurno* frente;
    NodoTurno* fin;
    int longitud;
public:
    ColaTurnos();
    virtual ~ColaTurnos();
    void setFrente(NodoTurno* nuevoFrente);
    void setFinal(NodoTurno* nuevoFinal);
    void setLongitud(int nuevaLongitud);
    NodoTurno* getFrente();
    NodoTurno* getFinal();
    int getLongitud();
    bool estaVacia();
    void insertarElem(Jugador* nuevoJugador);
    string mostrar();
    void terminarTurno();
};

#endif /* COLATURNOS_H */

