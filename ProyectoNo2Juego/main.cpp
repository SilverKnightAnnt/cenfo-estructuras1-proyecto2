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
Jugador* mostrarCartasJugador();
void declararGanador();
void atacar();
void limpiar();
void obtenerCarta(Jugador*);

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

void iniciarJuego() {
    limpiar();
    string aliasJ1, aliasJ2;
    cout << "Jugador 1 -> Ingrese su nickname: ";
    cin >> aliasJ1;
    cout << "Jugador 2 -> Ingrese su nickname: ";
    cin >> aliasJ2;
    controlador.initJ1(aliasJ1, 10);
    controlador.initJ2(aliasJ2, 10);
    cout << "\n¡DUELO!";
    menuJugador();
}

void limpiar() {
    gane = false;
    controlador.reiniciarJuego();
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
        declararGanador();
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
    if (enableSummon == true) {
        verMano();
        int iden, espacio;
        Carta c;
        Campo cp;
        Mano m;
        cout << "\nIngrese el identificador de la carta que desea invocar: ";
        cin >> iden;
        c.setIdentificador(iden);
        NodoCartas* cartaBuscar = controlador.obtenerJ1()->getMano().getListaCartas().buscarCartaPorIdentificador(c);
        if (cartaBuscar != NULL) {
            c = cartaBuscar->getCarta();
            cout << "Digite el espacio al cual la quiere agregar (1-5): ";
            cin >> espacio;
            espacio--;
            cp = controlador.obtenerJ1()->getCampo();
            cp.colocarCarta(c, espacio);
            controlador.obtenerJ1()->setCampo(cp);
            m = controlador.obtenerJ1()->getMano();
            m.eliminarCartaDeMano(c);
            controlador.obtenerJ1()->setMano(m);
        }
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
            << controlador.obtenerJ1()->getAlias();
    controlador.terminarTurnoJugador();
    obtenerCarta(controlador.obtenerJ1());
    enableSummon = true;
    enableAtack = true;
    conteoTurnos++;
}

void obtenerCarta(Jugador* pJugador) {
    if (pJugador->getBaraja().getPilaCartas().getLongitud() > 0) {
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
    } else {
        cout << "\n\nGano el jugador " << controlador.obtenerJ2()->getAlias() << " por deck out.";
        controlador.insertarPuntajes(100, controlador.obtenerJ2()->getAlias());
        //controlador.insertarPuntajes(100, controlador.obtenerJ2()->getAlias());
        gane = true;
    }
}

Jugador* mostrarCartasJugador() {
    int opcion;
    cout << "\n\n1. Ver el detalle de tus cartas"
            "\n2. Ver el detalle de las cartas enemigas"
            "\n\nSeleccione su opci\u00f3n: ";
    cin >> opcion;

    if (opcion == 1) {
        return controlador.obtenerJ1();
    } else if (opcion == 2) {
        return controlador.obtenerJ2();
    }

    cout << "\nOpci\u00f3n incorrecta.";
    return NULL;
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
        Carta cartaJ1, cartaJ2;
        verCampo();
        cout << "\n\nIngrese el identificador de la carta atacante: ";
        cin >> iden;
        cartaJ1.setIdentificador(iden);
        cartaJ1 = controlador.obtenerJ1()->getCampo().verDetalleCarta(cartaJ1);
        cout << "Ingrese el identificador de la carta a atacar: ";
        cin >> iden2;
        cartaJ2.setIdentificador(iden2);
        cartaJ2 = controlador.obtenerJ2()->getCampo().verDetalleCarta(cartaJ2);

        if (cartaJ1.getAtaque() > cartaJ2.getDefensa()) {
            int dif = cartaJ1.getAtaque() - cartaJ2.getDefensa();
            controlador.obtenerJ2()->setVida((controlador.obtenerJ2()->getVida() - dif));
            Campo campoJ2 = controlador.obtenerJ2()->getCampo();
            campoJ2.eliminarCarta(cartaJ2);
            controlador.obtenerJ2()->setCampo(campoJ2);
            //controlador.insertarPuntajes(10, controlador.obtenerJ1()->getAlias());
        }

        if (cartaJ1.getAtaque() == cartaJ2.getDefensa()) {
            Campo campoJ1 = controlador.obtenerJ1()->getCampo();
            Campo campoJ2 = controlador.obtenerJ2()->getCampo();
            campoJ1.eliminarCarta(cartaJ1);
            campoJ2.eliminarCarta(cartaJ2);
            controlador.obtenerJ1()->setCampo(campoJ1);
            controlador.obtenerJ2()->setCampo(campoJ2);
            //controlador.insertarPuntajes(10, controlador.obtenerJ1()->getAlias());
            //controlador.insertarPuntajes(10, controlador.obtenerJ2()->getAlias());
        }

        if (cartaJ1.getAtaque() < cartaJ2.getDefensa()) {
            int dif = cartaJ2.getDefensa() - cartaJ1.getAtaque();
            controlador.obtenerJ1()->setVida((controlador.obtenerJ1()->getVida() - dif));
            Campo campoJ1 = controlador.obtenerJ1()->getCampo();
            campoJ1.eliminarCarta(cartaJ1);
            controlador.obtenerJ1()->setCampo(campoJ1);
            //controlador.insertarPuntajes(-15, controlador.obtenerJ1()->getAlias());
        }

        enableAtack = false;
        declararGanador();
    }
}