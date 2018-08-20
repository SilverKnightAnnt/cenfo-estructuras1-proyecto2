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
#include "Campo.h"
#include "Mano.h"
#include "Jugador.h"
#include "Controlador.h"
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
void terminarTurno();
void declararGanador();
void atacar();
void limpiar(Jugador* pJ1, Jugador* pJ2);
void obtenerCarta();
void initJugador(Jugador*, int, int);

static Controlador controlador;

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
            cout << controlador.mostrarPuntajes();
            break;
        case 3:
            break;
        default:
            cout << "Opci\u00f3n incorrecta.";
    }
}

bool gane;
bool enableSummon = true;
bool enableAtack = true;
int conteoTurnos = 1;
Jugador jugador1,jugador2;

void iniciarJuego() {
    limpiar(&jugador1, &jugador2);
    initJugador(&jugador1, 1, 10);
    initJugador(&jugador2, 2, 10);
    cout << "\n¡DUELO!";
    menuJugador();
}

void limpiar(Jugador* pJ1, Jugador* pJ2) {
    gane = false;
    Baraja b;
    Mano m;
    Campo c;
    *pJ1 = Jugador("", 0, b, m, c);
    *pJ2 = Jugador("", 0, b, m, c);
    controlador.reiniciarJuego();
}

void initJugador(Jugador* pJugador, int pNumPlayer, int pVidaPlayer) {
    string alias;
    cout << "Jugador " << pNumPlayer << "-> Ingrese su nickname: ";
    cin >> alias;
    pJugador->setAlias(alias);
    pJugador->setVida(pVidaPlayer);
    controlador.generarBarajaJugador(pJugador);
    controlador.generarManoJugador(pJugador);
    controlador.insertarJugador(pJugador);
}

void menuJugador() {
    int opcionMenuJugador = -1;
    do {
        cout << "\n\n---------------------------------------------\nInicia el turno del jugador "
                << controlador.obtenerJ1()->getAlias() <<
                "\n---------------------------------------------";
        cout << "\n\nMen\u00fa del jugador"
                "\n1. Ver mano.\n2. Colocar carta.\n3. Ver campo."
                "\n4. Ver detalle de carta en campo.\n5. Atacar."
                "\n6. Terminar turno.\n\nSeleccione su opci\u00f3n: ";
        cin >> opcionMenuJugador;
        procesarOpcionMenuJugador(&opcionMenuJugador);
    } while (gane == false);
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
            cout << controlador.mostrarJugadores();
            break;
        default:
            cout << "Opci\u00f3n incorrecta.";
    }
}

void verMano() {
    cout << controlador.obtenerJ1()->getMano().imprimirMano();
}

void colocarCartaEnCampo() {
    if (enableSummon) {
        verMano();
        int iden, espacio;
        cout << "\nIngrese el identificador de la carta que desea invocar: ";
        cin >> iden;
        cout << "Digite el espacio al cual la quiere agregar (1-5): ";
        cin >> espacio;
        espacio--;
        controlador.colocarCartaEnCampo(iden, espacio);
        enableSummon = false;
    }
}

void verCampo() {
    cout << "\n\n" << controlador.obtenerJ2()->getAlias() << " Vida: " << controlador.obtenerJ2()->getVida() << "\n\n";
    cout << controlador.obtenerJ2()->getCampo().imprimirCampo();
    cout << "\n---------------------------------------------------------";
    cout << "\n" << controlador.obtenerJ1()->getCampo().imprimirCampo();
    cout << "\n\n" << controlador.obtenerJ1()->getAlias() << " Vida: " << controlador.obtenerJ1()->getVida();
}

void verDetalleCarta() {
    verCampo();
    int iden, numJugador;
    cout << "\n\n1. Ver el detalle de tus cartas"
            "\n2. Ver el detalle de las cartas enemigas"
            "\n\nSeleccione su opci\u00f3n: ";
    cin >> numJugador;
    cout << "\nIngrese el identificador de la carta que desea ver: ";
    cin >> iden;
    cout << "\n***********************************************************";
    cout << controlador.verDetalleCarta(iden, numJugador);
    cout << "\n***********************************************************";
}

void terminarTurno() {
    cout << "\nTermino el turno del jugador "
            << controlador.obtenerJ1()->getAlias();
    controlador.terminarTurnoJugador();
    obtenerCarta();
    enableSummon = true;
    enableAtack = true;
    conteoTurnos++;
}

void obtenerCarta() {
    if (controlador.obtenerLongitudBarajaJ1() > 0) {
        controlador.obtenerCarta();
    } else {
        cout << "\n\nGano el jugador " << controlador.obtenerJ2()->getAlias() << " por deck out.";
        controlador.insertarPuntajes(100, controlador.obtenerJ2()->getAlias());
        gane = true;
    }
}

void declararGanador() {
    int vidaJ1 = controlador.obtenerJ1()->getVida();
    int vidaJ2 = controlador.obtenerJ2()->getVida();

    if (vidaJ1 <= 0 && vidaJ2 > 0) {
        cout << "\n\nGano el jugador " << controlador.obtenerJ2()->getAlias();
        gane = true;
        controlador.insertarPuntajes(100, controlador.obtenerJ2()->getAlias());
    } else if (vidaJ1 > 0 && vidaJ2 <= 0) {
        cout << "\n\nGano el jugador " << controlador.obtenerJ1()->getAlias();
        gane = true;
        controlador.insertarPuntajes(100, controlador.obtenerJ1()->getAlias());
    }
}

void atacar() {
    if (conteoTurnos != 1 && enableAtack == true) {
        int iden, iden2;
        verCampo();
        cout << "\n\nIngrese el identificador de la carta atacante: ";
        cin >> iden;
        cout << "Ingrese el identificador de la carta a atacar: ";
        cin >> iden2;
        controlador.atacar(iden, iden2);
        enableAtack = false;
        declararGanador();
    }
}