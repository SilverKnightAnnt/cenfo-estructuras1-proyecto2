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
void limpiar(Jugador*, Jugador*);
void obtenerCarta(Jugador*);
void registrarPuntuacion(int, string);

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
Puntuacion* nuevoPuntaje;
bool gane;
bool enableSummon = true;
bool enableAtack = true;
int conteoTurnos = 1;

void iniciarJuego() {
    limpiar(&jugador1, &jugador2);
    initJugador(&jugador1, 1, 10);
    initJugador(&jugador2, 2, 10);
    cout << "\n¡DUELO!";
    menuJugador();
}

void limpiar(Jugador* pJ1, Jugador* pJ2) {
    gane = false;
    ColaTurnos cola;
    Baraja b;
    Mano m;
    Campo c;
    *pJ1 = Jugador("", 0, b, m, c);
    *pJ2 = Jugador("", 0, b, m, c);
    turnos = cola;
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
    if (enableSummon == true) {
        verMano();
        int iden, espacio;
        Carta c;
        Campo cp;
        Mano m;
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
            m = obtenerJugadorActual()->getMano();
            m.eliminarCartaDeMano(c);
            obtenerJugadorActual()->setMano(m);
        }
        enableSummon = false;
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
    obtenerCarta(turnos.getFrente()->getInfo());
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
        cout << "\n\nGano el jugador " << obtenerJugadorSiguiente()->getAlias() << " por deck out.";
        registrarPuntuacion(100, obtenerJugadorSiguiente()->getAlias());
        gane = true;
    }
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
        gane = true;
        registrarPuntuacion(100, obtenerJugadorSiguiente()->getAlias());
    } else if (vidaJ1 > 0 && vidaJ2 <= 0) {
        cout << "\n\nGano el jugador " << obtenerJugadorActual()->getAlias();
        gane = true;
        registrarPuntuacion(100, obtenerJugadorActual()->getAlias());
    }
}

void mostrarPuntajes() {
    cout << puntuaciones.mostrar();
}

void atacar() {
    if (conteoTurnos != 1 && enableAtack == true) {
        int iden, iden2;
        Carta cartaJ1, cartaJ2;
        verCampo();
        cout << "\n\nIngrese el identificador de la carta atacante: ";
        cin >> iden;
        cartaJ1.setIdentificador(iden);
        cartaJ1 = obtenerJugadorActual()->getCampo().verDetalleCarta(cartaJ1);
        cout << "Ingrese el identificador de la carta a atacar: ";
        cin >> iden2;
        cartaJ2.setIdentificador(iden2);
        cartaJ2 = obtenerJugadorSiguiente()->getCampo().verDetalleCarta(cartaJ2);

        if (cartaJ1.getAtaque() > cartaJ2.getDefensa()) {
            int dif = cartaJ1.getAtaque() - cartaJ2.getDefensa();
            obtenerJugadorSiguiente()->setVida((obtenerJugadorSiguiente()->getVida() - dif));
            Campo campoJ2 = obtenerJugadorSiguiente()->getCampo();
            campoJ2.eliminarCarta(cartaJ2);
            obtenerJugadorSiguiente()->setCampo(campoJ2);
            //registrarPuntuacion(10, obtenerJugadorActual()->getAlias());
        }

        if (cartaJ1.getAtaque() == cartaJ2.getDefensa()) {
            Campo campoJ1 = obtenerJugadorActual()->getCampo();
            Campo campoJ2 = obtenerJugadorSiguiente()->getCampo();
            campoJ1.eliminarCarta(cartaJ1);
            campoJ2.eliminarCarta(cartaJ2);
            obtenerJugadorActual()->setCampo(campoJ1);
            obtenerJugadorSiguiente()->setCampo(campoJ2);
            //registrarPuntuacion(10, obtenerJugadorActual()->getAlias());
            //registrarPuntuacion(10, obtenerJugadorSiguiente()->getAlias());
        }

        if (cartaJ1.getAtaque() < cartaJ2.getDefensa()) {
            int dif = cartaJ2.getDefensa() - cartaJ1.getAtaque();
            obtenerJugadorActual()->setVida((obtenerJugadorActual()->getVida() - dif));
            Campo campoJ1 = obtenerJugadorActual()->getCampo();
            campoJ1.eliminarCarta(cartaJ1);
            obtenerJugadorActual()->setCampo(campoJ1);
            //registrarPuntuacion(-15, obtenerJugadorActual()->getAlias());
        }

        enableAtack = false;
        declararGanador();
    }
}

void registrarPuntuacion(int cantPuntaje, string nomJugador) {
    nuevoPuntaje = puntuaciones.buscar(nomJugador);

    if (nuevoPuntaje != NULL) {
        puntuaciones.eliminar(nomJugador);
        cantPuntaje += nuevoPuntaje->getPuntuacion();
    } else {
        nuevoPuntaje = new Puntuacion();
        nuevoPuntaje->setNomJugador(nomJugador);

    }

    nuevoPuntaje->setPuntuacion(cantPuntaje);
    puntuaciones.insertarOrdenado(nuevoPuntaje);
}