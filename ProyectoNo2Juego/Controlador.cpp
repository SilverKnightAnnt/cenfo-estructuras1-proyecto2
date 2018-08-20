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

Controlador::Controlador() {
}

Controlador::~Controlador() {
}

void Controlador::setEnableSummon(bool pEnable) {
    enableSummon = pEnable;
}

bool Controlador::getEnableSummon() {
    return enableSummon;
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

void Controlador::colocarCartaEnCampo(int idenCarta, int espacio) {
    Carta c;
    Campo cp;
    Mano m;
    c.setIdentificador(idenCarta);
    NodoCartas* cartaBuscar = obtenerJ1()->getMano().getListaCartas().buscarCartaPorIdentificador(c);

    if (cartaBuscar != NULL) {
        c = cartaBuscar->getCarta();
        cp = obtenerJ1()->getCampo();
        cp.colocarCarta(c, espacio);
        obtenerJ1()->setCampo(cp);
        m = obtenerJ1()->getMano();
        m.eliminarCartaDeMano(c);
        obtenerJ1()->setMano(m);
    }

}

string Controlador::verDetalleCarta(int idenCarta, int pNumJugador) {
    Carta c;
    Campo cmp = obtenerCampoJugador(pNumJugador)->getCampo();
    c.setIdentificador(idenCarta);
    return cmp.verDetalleCarta(c).imprimirCarta();
}

Jugador* Controlador::obtenerCampoJugador(int pNumJugador) {
    if (pNumJugador == 1) {
        return obtenerJ1();
    }

    if (pNumJugador == 2) {
        return obtenerJ2();
    }

    return NULL;
}

void Controlador::obtenerCarta() {
    Baraja bara = obtenerJ1()->getBaraja();
    Mano mano = obtenerJ1()->getMano();
    PilaCartas mazo = bara.getPilaCartas();
    ListaCartas lista = mano.getListaCartas();
    NodoCartas* nodo = mazo.obtenerTope();
    Carta car = nodo->getCarta();
    lista.insertarCarta(car);
    mano.setListaCartas(lista);
    obtenerJ1()->setMano(mano);
    bara.setPilaCartas(mazo);
    obtenerJ1()->setBaraja(bara);
}

int Controlador::obtenerLongitudBarajaJ1() {
    return obtenerJ1()->getBaraja().getPilaCartas().getLongitud();
}

void Controlador::atacar(int pCartaAtacante, int pCartaAtacar) {
    Carta cartaJ1, cartaJ2;
    cartaJ1.setIdentificador(pCartaAtacante);
    cartaJ1 = obtenerJ1()->getCampo().verDetalleCarta(cartaJ1);
    cartaJ2.setIdentificador(pCartaAtacar);
    cartaJ2 = obtenerJ2()->getCampo().verDetalleCarta(cartaJ2);

    if (cartaJ1.getAtaque() > cartaJ2.getDefensa()) {
        int dif = cartaJ1.getAtaque() - cartaJ2.getDefensa();
        obtenerJ2()->setVida((obtenerJ2()->getVida() - dif));
        Campo campoJ2 = obtenerJ2()->getCampo();
        campoJ2.eliminarCarta(cartaJ2);
        obtenerJ2()->setCampo(campoJ2);
    }

    if (cartaJ1.getAtaque() == cartaJ2.getDefensa()) {
        Campo campoJ1 = obtenerJ1()->getCampo();
        Campo campoJ2 = obtenerJ2()->getCampo();
        campoJ1.eliminarCarta(cartaJ1);
        campoJ2.eliminarCarta(cartaJ2);
        obtenerJ1()->setCampo(campoJ1);
        obtenerJ2()->setCampo(campoJ2);
    }

    if (cartaJ1.getAtaque() < cartaJ2.getDefensa()) {
        int dif = cartaJ2.getDefensa() - cartaJ1.getAtaque();
        obtenerJ1()->setVida((obtenerJ1()->getVida() - dif));
        Campo campoJ1 = obtenerJ1()->getCampo();
        campoJ1.eliminarCarta(cartaJ1);
        obtenerJ1()->setCampo(campoJ1);
    }
}



