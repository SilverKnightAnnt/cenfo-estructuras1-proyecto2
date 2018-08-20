/* Cenfotec – Costa Rica
 * Estructura de Datos – 2018-02
 * Nombre del archivo: Campo.h
 * Autor: Ángel Marín, Christhian Montes, Daniel Rodriguez
 * e-mail: amarint@cenfotec.com,cmontesa@ucenfotec.ac.cr,drodriguezr@ucenfotec.ac.cr
 * ProyectoNo2Juego – Proyecto juego con estructuras
 * Fecha de creación: Julio del 2018
 * Fecha de último cambio: Agosto del 2018
 */

#ifndef CAMPO_H
#define CAMPO_H

#include "Carta.h"
#include <string>

using namespace std;

class Campo {
private:
    Carta cartas[5];
public:
    Campo();
    void colocarCarta(Carta, int);
    bool posicionamiento(int);
    Carta verDetalleCarta(Carta);
    string imprimirCampo();
    void eliminarCarta(Carta);
};

#endif /* CAMPO_H */

