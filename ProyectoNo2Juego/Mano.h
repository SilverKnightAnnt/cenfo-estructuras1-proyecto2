/* Cenfotec – Costa Rica
 * Estructura de Datos – 2018-02
 * Nombre del archivo: Mano.h
 * Autor: Ángel Marín, Christhian Montes, Daniel Rodriguez
 * e-mail: amarint@cenfotec.com,cmontesa@ucenfotec.ac.cr,drodriguezr@ucenfotec.ac.cr
 * ProyectoNo2Juego – Proyecto juego con estructuras
 * Fecha de creación: Julio del 2018
 * Fecha de último cambio: Agosto del 2018
 */

#ifndef MANO_H
#define MANO_H

#include "ListaCartas.h"
#include <string>

using namespace std;

class Mano {
private:
    ListaCartas listaCartas;
public:
    Mano();
    void setListaCartas(ListaCartas);
    ListaCartas getListaCartas();
    void eliminarCartaDeMano(Carta);
    string imprimirMano();
};

#endif /* MANO_H */

