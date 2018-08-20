/* Cenfotec – Costa Rica
 * Estructura de Datos – 2018-02
 * Nombre del archivo: Controlador.h
 * Autor: Ángel Marín, Christhian Montes, Daniel Rodriguez
 * e-mail: amarint@cenfotec.com,cmontesa@ucenfotec.ac.cr,drodriguezr@ucenfotec.ac.cr
 * ProyectoNo2Juego – Proyecto juego con estructuras
 * Fecha de creación: Julio del 2018
 * Fecha de último cambio: Agosto del 2018
 */

#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include "Carta.h"
#include "Campo.h"
#include "Mano.h"
#include "Jugador.h"
#include "ListaCartas.h"
#include "NodoTurno.h"
#include "ColaTurnos.h"
#include "Puntuacion.h"
#include "ListaPuntuaciones.h"
#include "Controlador.h"
#include <cstdlib>
#include <string>
#include <iostream>
#include <ctime>

using namespace std;

class Controlador {
private:
    Jugador* obtenerCampoJugador(int pNumJugador);
    bool enableSummon = true;
    bool enableAtack = true;
public:
    Controlador();
    virtual ~Controlador();
    void setEnableSummon(bool pEnable);
    bool getEnableSummon();
    void setEnableAtack(bool pEnable);
    bool getEnableAtack();
    Jugador* obtenerJ1();
    Jugador* obtenerJ2();
    void insertarJugador(Jugador* pJugador);
    void insertarPuntajes(int cantPuntos, string nomJugador);
    string mostrarJugadores();
    string mostrarPuntajes();
    void terminarTurnoJugador();
    void reiniciarJuego();
    void initJ1(string aliasJ1, int vidaJ1);
    void initJ2(string aliasJ2, int vidaJ2);
    void generarBarajaJugador(Jugador* pJugador);
    void generarManoJugador(Jugador* pJugador);
    void colocarCartaEnCampo(int idenCarta, int espacio);
    string verDetalleCarta(int idenCarta, int pNumJugador);
    void obtenerCarta();
    int obtenerLongitudBarajaJ1();
    void atacar(int pCartaAtacante, int pCartaAtacar);
};

#endif /* CONTROLADOR_H */

