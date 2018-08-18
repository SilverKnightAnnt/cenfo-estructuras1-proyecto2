/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: User
 *
 * Created on August 7, 2018, 8:01 PM
 */
#include "Carta.h"
#include "Campo.h"
#include "Mano.h"
#include "Jugador.h"
#include "ListaCartas.h"
#include "NodoTurno.h"
#include "ColaTurnos.h"
#include "Puntuacion.h"
#include "ListaPuntuaciones.h"
#include <cstdlib>
#include <string>
#include <iostream>
#include <ctime>

using namespace std;

void mostrarMenu();
void procesarOpcionMenu(int*);
void iniciarJuego();
void generarBarajaJugador(Jugador*);
void generarManoJugador(Jugador*);
void menuJugador();
void procesarOpcionMenuJugador(int*);
void verMano();
void colocarCartaEnCampo();
void verCampo();
void verDetalleCarta();
void mostrarJugadores();
void terminarTurno();
Jugador* obtenerJugadorActual();
Jugador* obtenerJugadorSiguiente();
Jugador* mostrarCartasJugador();
void initJugador(Jugador*, int, int);
void declararGanador();
void atacar();
void mostrarPuntajes();

int main(int argc, char** argv) {
    cout << "¡Bienvenido a ************!";
    mostrarMenu();
    return 0;
}

void mostrarMenu() {
    int opcionMenu = -1;
    do {
        cout << "\n\nMen\u00fa principal"
                "\n1. Iniciar juego.\n2. Ranking.\n3. Salir.\n\nSeleccione su opci\u00f3n: ";
        cin >> opcionMenu;
        procesarOpcionMenu(&opcionMenu);
    } while (opcionMenu != 3);
}

void procesarOpcionMenu(int* pOpcion) {
    switch (*pOpcion) {
        case 1:
            iniciarJuego();
            break;
        case 2:
            mostrarPuntajes();
            break;
        case 3:
            break;
        default:
            cout << "Opci\u00f3n incorrecta.";
    }
}

static ColaTurnos turnos;
static ListaPuntuaciones puntuaciones;
Jugador jugador1;
Jugador jugador2;
Puntuacion nuevoPuntaje;

void iniciarJuego() {
    initJugador(&jugador1, 1, 10);
    initJugador(&jugador2, 2, 10);
    cout << "\n¡DUELO!";
    menuJugador();
}

void generarBarajaJugador(Jugador* pJugador) {
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

void generarManoJugador(Jugador* pJugador) {
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

void menuJugador() {
    int opcionMenuJugador = -1;
    do {
        cout << "\n\n---------------------------------------------\nInicia el turno del jugador "
                << turnos.getFrente()->getInfo()->getAlias() <<
                "\n---------------------------------------------";
        cout << "\n\nMen\u00fa del jugador"
                "\n1. Ver mano.\n2. Colocar carta.\n3. Ver campo."
                "\n4. Ver detalle de carta en campo.\n5. Atacar."
                "\n6. Terminar turno.\n\nSeleccione su opci\u00f3n: ";
        cin >> opcionMenuJugador;
        procesarOpcionMenuJugador(&opcionMenuJugador);
    } while (obtenerJugadorActual()->getVida() > 0 && obtenerJugadorSiguiente()->getVida() > 0);
    declararGanador();
}

void procesarOpcionMenuJugador(int* pOpcionMenuJugador) {
    switch (*pOpcionMenuJugador) {
        case 1:
            verMano();
            break;
        case 2:
            colocarCartaEnCampo();
            break;
        case 3:
            verCampo();
            break;
        case 4:
            verDetalleCarta();
            break;
        case 5:
            atacar();
            break;
        case 6:
            terminarTurno();
            break;
        case 7:
            mostrarJugadores();
            break;
        default:
            cout << "Opci\u00f3n incorrecta.";
    }
}

void verMano() {
    cout << obtenerJugadorActual()->getMano().imprimirMano();
}

void colocarCartaEnCampo() {
    verMano();
    int iden, espacio;
    Carta c;
    Campo cp;
    cout << "\nIngrese el identificador de la carta que desea invocar: ";
    cin >> iden;
    c.setIdentificador(iden);
    NodoCartas* cartaBuscar = obtenerJugadorActual()->getMano().getListaCartas().buscarCartaPorIdentificador(c);
    if (cartaBuscar != NULL) {
        c = cartaBuscar->getCarta();
        cout << "Digite el espacio al cual la quiere agregar (1-5): ";
        cin >> espacio;
        espacio--;
        cp = obtenerJugadorActual()->getCampo();
        cp.colocarCarta(c, espacio);
        obtenerJugadorActual()->setCampo(cp);
    }
}

void verCampo() {
    cout << "\n\n" << obtenerJugadorSiguiente()->getAlias() << " Vida: " << obtenerJugadorSiguiente()->getVida() << "\n\n";
    cout << obtenerJugadorSiguiente()->getCampo().imprimirCampo();
    cout << "\n---------------------------------------------------------";
    cout << "\n" << obtenerJugadorActual()->getCampo().imprimirCampo();
    cout << "\n\n" << obtenerJugadorActual()->getAlias() << " Vida: " << obtenerJugadorActual()->getVida();
}

void verDetalleCarta() {
    verCampo();
    int iden;
    Carta c;
    Campo cmp = mostrarCartasJugador()->getCampo();
    cout << "\nIngrese el identificador de la carta que desea ver: ";
    cin >> iden;
    c.setIdentificador(iden);
    cout << "\n***********************************************************";
    cout << cmp.verDetalleCarta(c).imprimirCarta();
    cout << "\n***********************************************************";
}

void terminarTurno() {
    cout << "\nTermino el turno del jugador "
            << turnos.getFrente()->getInfo()->getAlias();
    turnos.terminarTurno();
}

void mostrarJugadores() {
    cout << turnos.mostrar();
}

Jugador* obtenerJugadorActual() {
    return turnos.getFrente()->getInfo();
}

Jugador* obtenerJugadorSiguiente() {
    return turnos.getFinal()->getInfo();
}

Jugador* mostrarCartasJugador() {
    int opcion;
    cout << "\n\n1. Ver el detalle de tus cartas"
            "\n2. Ver el detalle de las cartas enemigas"
            "\n\nSeleccione su opci\u00f3n: ";
    cin >> opcion;

    if (opcion == 1) {
        return obtenerJugadorActual();
    } else if (opcion == 2) {
        return obtenerJugadorSiguiente();
    }

    cout << "\nOpci\u00f3n incorrecta.";
    return NULL;
}

void initJugador(Jugador* pJugador, int pNumPlayer, int pVidaPlayer) {
    string alias;
    cout << "Jugador " << pNumPlayer << "-> Ingrese su nickname: ";
    cin >> alias;
    pJugador->setAlias(alias);
    pJugador->setVida(pVidaPlayer);
    generarBarajaJugador(pJugador);
    generarManoJugador(pJugador);
    turnos.insertarElem(pJugador);
}

void declararGanador() {
    int vidaJ1 = obtenerJugadorActual()->getVida();
    int vidaJ2 = obtenerJugadorSiguiente()->getVida();

    if (vidaJ1 <= 0 && vidaJ2 > 0) {
        cout << "\n\nGano el jugador " << obtenerJugadorSiguiente()->getAlias();
        nuevoPuntaje.setNomJugador(obtenerJugadorSiguiente()->getAlias());
    } else if (vidaJ1 > 0 && vidaJ2 <= 0) {
        nuevoPuntaje.setNomJugador(obtenerJugadorActual()->getAlias());
        cout << "\n\nGano el jugador " << obtenerJugadorActual()->getAlias();
    }

    nuevoPuntaje.setPuntuacion(1000);
    puntuaciones.insertarOrdenado(&nuevoPuntaje);
}

void mostrarPuntajes() {
    cout << puntuaciones.mostrar();
}

void atacar() {
    int iden, iden2;
    Carta c1, c2;
    verCampo();
    cout << "\n\nIngrese el identificador de la carta atacante: ";
    cin >> iden;
    c1.setIdentificador(iden);
    c1 = obtenerJugadorActual()->getCampo().verDetalleCarta(c1);
    cout << "Ingrese el identificador de la carta a atacar: ";
    cin >> iden2;
    c2.setIdentificador(iden2);
    c2 = obtenerJugadorSiguiente()->getCampo().verDetalleCarta(c2);
    if (c1.getAtaque() > c2.getDefensa()) {
        int dif = c1.getAtaque() - c2.getDefensa();
        obtenerJugadorSiguiente()->setVida((obtenerJugadorSiguiente()->getVida() - dif));
        Campo cp = obtenerJugadorSiguiente()->getCampo();
        cp.eliminarCarta(c2);
        obtenerJugadorSiguiente()->setCampo(cp);
    } else if (c1.getAtaque() == c2.getDefensa()) {
        Campo cp1 = obtenerJugadorActual()->getCampo();
        Campo cp2 = obtenerJugadorSiguiente()->getCampo();
        cp1.eliminarCarta(c1);
        cp2.eliminarCarta(c2);
        obtenerJugadorActual()->setCampo(cp1);
        obtenerJugadorSiguiente()->setCampo(cp2);
    } else if (c1.getAtaque() < c2.getDefensa()) {
        int dif = c2.getDefensa() - c1.getAtaque();
        obtenerJugadorActual()->setVida((obtenerJugadorActual()->getVida() - dif));
        Campo cp = obtenerJugadorActual()->getCampo();
        cp.eliminarCarta(c1);
        obtenerJugadorActual()->setCampo(cp);
    }
}