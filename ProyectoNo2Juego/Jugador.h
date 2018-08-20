/* Cenfotec – Costa Rica
 * Estructura de Datos – 2018-02
 * Nombre del archivo: Jugador.h
 * Autor: Ángel Marín, Christhian Montes, Daniel Rodriguez
 * e-mail: amarint@cenfotec.com,cmontesa@ucenfotec.ac.cr,drodriguezr@ucenfotec.ac.cr
 * ProyectoNo2Juego – Proyecto juego con estructuras
 * Fecha de creación: Julio del 2018
 * Fecha de último cambio: Agosto del 2018
 */

#ifndef JUGADOR_H
#define JUGADOR_H

#include "Baraja.h"
#include "Mano.h"
#include "Campo.h"
#include <string>

using namespace std;

class Jugador {
private:
    string alias;
    int vida;
    Baraja baraja;
    Mano mano;
    Campo campo;
public:
    Jugador();
    Jugador(string, int, Baraja, Mano, Campo);
    void setAlias(string);
    string getAlias();
    void setVida(int);
    int getVida();
    void setBaraja(Baraja);
    Baraja getBaraja();
    void setMano(Mano);
    Mano getMano();
    void setCampo(Campo);
    Campo getCampo();
    string imprimirJugador();
};

#endif /* JUGADOR_H */

