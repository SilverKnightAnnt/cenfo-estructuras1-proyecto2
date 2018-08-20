/* Cenfotec – Costa Rica
 * Estructura de Datos – 2018-02
 * Nombre del archivo: ListaCartas.h
 * Autor: Ángel Marín, Christhian Montes, Daniel Rodriguez
 * e-mail: amarint@cenfotec.com,cmontesa@ucenfotec.ac.cr,drodriguezr@ucenfotec.ac.cr
 * ProyectoNo2Juego – Proyecto juego con estructuras
 * Fecha de creación: Julio del 2018
 * Fecha de último cambio: Agosto del 2018
 */

#ifndef LISTACARTAS_H
#define LISTACARTAS_H

#include <string>
#include "NodoCartas.h"

class ListaCartas {
private:
    NodoCartas* cabeza;
    int tamanno;
    bool listaVacia();
public:
    ListaCartas();
    void setTamanno(int);
    int getTamanno();
    void setCabeza(NodoCartas*);
    NodoCartas* getCabeza();
    void insertarCarta(Carta);
    string verListaCartas();
    NodoCartas* buscarCartaPorIdentificador(Carta);
    void eliminarCarta(Carta);
};

#endif /* LISTACARTAS_H */

