/* Cenfotec – Costa Rica
 * Estructura de Datos – 2018-02
 * Nombre del archivo: Mano.cpp
 * Autor: Ángel Marín, Christhian Montes, Daniel Rodriguez
 * e-mail: amarint@cenfotec.com,cmontesa@ucenfotec.ac.cr,drodriguezr@ucenfotec.ac.cr
 * ProyectoNo2Juego – Proyecto juego con estructuras
 * Fecha de creación: Julio del 2018
 * Fecha de último cambio: Agosto del 2018
 */

#include "Mano.h"

Mano::Mano() {

}

void Mano::setListaCartas(ListaCartas pLista) {
    listaCartas = pLista;
}

ListaCartas Mano::getListaCartas() {
    return listaCartas;
}

void Mano::eliminarCartaDeMano(Carta pCarta) {
    listaCartas.eliminarCarta(pCarta);
}

string Mano::imprimirMano() {
    return listaCartas.verListaCartas();
}
