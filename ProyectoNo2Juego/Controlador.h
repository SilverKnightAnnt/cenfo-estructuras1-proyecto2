/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Controlador.h
 * Author: Steven
 *
 * Created on August 18, 2018, 11:02 PM
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
#include <ctime>

using namespace std;

class Controlador {
public:
    Controlador();
    virtual ~Controlador();
    void setEnableSummon(bool pEnable);
    bool getEnableSummon();
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

private:
    Jugador* obtenerCampoJugador(int pNumJugador);
};

#endif /* CONTROLADOR_H */

