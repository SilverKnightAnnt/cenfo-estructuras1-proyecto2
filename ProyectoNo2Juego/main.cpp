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

int main(int argc, char** argv) {
    cout << "¡Bienvenido a ************!";
    mostrarMenu();
    return 0;
}

void mostrarMenu() {
    int opcionMenu = -1;
    do {
        cout << "\n\nMenú principal"
                "\n1. Iniciar juego.\n2. Ranking.\n3. Salir.\n\nSeleccione su opción: ";
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
            break;
        case 3:
            break;
        default:
            cout << "Opción incorrecta.";
    }
}

static ColaTurnos turnos;
Jugador jugador1;
Jugador jugador2;

void iniciarJuego() {
    string aliasJ1, aliasJ2;
    cout << "Jugador 1 -> Ingrese su nickname: ";
    cin >> aliasJ1;
    jugador1.setAlias(aliasJ1);
    jugador1.setVida(10);
    generarBarajaJugador(&jugador1);
    generarManoJugador(&jugador1);
    cout << "Jugador 2 -> Ingrese su nickname: ";
    cin >> aliasJ2;
    jugador2.setAlias(aliasJ2);
    jugador2.setVida(10);
    generarBarajaJugador(&jugador2);
    generarManoJugador(&jugador2);
    turnos.insertarElem(&jugador1);
    turnos.insertarElem(&jugador2);
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
        cout << "\n\n***********************\nInicia el turno del jugador "
                << turnos.getFrente()->getInfo()->getAlias() <<
                "\n***********************";
        cout << "\n\nMenú del jugador"
                "\n1. Ver mano.\n2. Colocar carta.\n3. Ver campo."
                "\n4. Ver detalle de carta en campo.\n5. Atacar."
                "\n6. Terminar turno.\n\nSeleccione su opción: ";
        cin >> opcionMenuJugador;
        procesarOpcionMenuJugador(&opcionMenuJugador);
    } while (opcionMenuJugador != 7);
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

            break;
        case 6:
            terminarTurno();
            break;
        case 7:
            mostrarJugadores();
            break;
        default:
            cout << "Opción incorrecta.";
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
    cout << jugador2.getCampo().imprimirCampo();
    cout << "\n---------------------------------------------------------";
    cout << "\n" << jugador1.getCampo().imprimirCampo();
}

void verDetalleCarta() {
    verCampo();
    int iden;
    Carta c;
    cout << "Ingrese el identificador de la carta que desea ver: ";
    cin >> iden;
    c.setIdentificador(iden);
    cout << "\n***********************************************************";
    cout << obtenerJugadorActual()->getCampo().verDetalleCarta(c).imprimirCarta();
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