/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Controlador.cpp
 * Author: Steven
 * 
 * Created on August 18, 2018, 11:02 PM
 */

#include "Controlador.h"

static ColaTurnos turnos;
static ListaPuntuaciones puntuaciones;
Puntuacion* nuevoPuntaje;
Jugador J1;
Jugador J2;

Controlador::Controlador() {
}

Controlador::~Controlador() {
}

Jugador* Controlador::obtenerJ1() {
    return turnos.getFrente()->getInfo();
}

Jugador* Controlador::obtenerJ2() {
    return turnos.getFinal()->getInfo();
}

void Controlador::reiniciarJuego() {
    ColaTurnos nuevosTurnos;
    turnos = nuevosTurnos;
    Baraja b;
    Mano m;
    Campo c;
    J1 = Jugador("", 0, b, m, c);
    J2 = Jugador("", 0, b, m, c);
}

string Controlador::mostrarJugadores() {
    return turnos.mostrar();
}

string Controlador::mostrarPuntajes() {
    return puntuaciones.mostrar();
}

void Controlador::insertarJugador(Jugador* pJugador) {
    turnos.insertarElem(pJugador);
}

void Controlador::initJ1(string aliasJ1, int vidaJ1) {
    J1.setAlias(aliasJ1);
    J1.setVida(vidaJ1);
    generarBarajaJugador(&J1);
    generarManoJugador(&J1);
    insertarJugador(&J1);
}

void Controlador::initJ2(string aliasJ2, int vidaJ2) {
    J2.setAlias(aliasJ2);
    J2.setVida(vidaJ2);
    generarBarajaJugador(&J2);
    generarManoJugador(&J2);
    insertarJugador(&J2);
}

void Controlador::insertarPuntajes(int cantPuntos, string nomJugador) {
    nuevoPuntaje = puntuaciones.buscar(nomJugador);

    if (nuevoPuntaje != NULL) {
        puntuaciones.eliminar(nomJugador);
        cantPuntos += nuevoPuntaje->getPuntuacion();
    } else {
        nuevoPuntaje = new Puntuacion();
        nuevoPuntaje->setNomJugador(nomJugador);

    }

    nuevoPuntaje->setPuntuacion(cantPuntos);
    puntuaciones.insertarOrdenado(nuevoPuntaje);
}

void Controlador::terminarTurnoJugador() {
    turnos.terminarTurno();
}

void Controlador::generarBarajaJugador(Jugador* pJugador) {
    srand((int) time(0));
    int i = 0;
    while (i++ < 20) {
        int atk = (rand() % 10) + 1;
        int def = (rand() % 10) + 1;
        Carta carta = Carta(i, atk, def);
        Baraja baraja = pJugador->getBaraja();
        PilaCartas mazo = baraja.getPilaCartas();
        mazo.insertarCarta(carta);
        baraja.setPilaCartas(mazo);
        pJugador->setBaraja(baraja);
    }
}

void Controlador::generarManoJugador(Jugador* pJugador) {
    int j = 0;
    while (j++ < 5) {
        Baraja bara = pJugador->getBaraja();
        Mano mano = pJugador->getMano();
        PilaCartas mazo = bara.getPilaCartas();
        ListaCartas lista = mano.getListaCartas();
        NodoCartas* nodo = mazo.obtenerTope();
        Carta car = nodo->getCarta();
        lista.insertarCarta(car);
        mano.setListaCartas(lista);
        pJugador->setMano(mano);
        bara.setPilaCartas(mazo);
        pJugador->setBaraja(bara);
    }
}



