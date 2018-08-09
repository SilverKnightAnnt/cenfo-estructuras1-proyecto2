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
void verMano();

int main(int argc, char** argv) {
    cout << "¡Bienvenido a ************!";
    mostrarMenu();
    return 0;
}

void mostrarMenu() {
    int opcionMenu = -1;
    do {
        cout << "\n\nMenú principal"
                "\n1. Iniciar juego.\n2. Ver mano.\n3. Salir.\n\nSeleccione su opción: ";
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
            verMano();
            break;
        default:
            cout << "Opción incorrecta.";
    }
}

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

void verMano(){
    string alias;
    Jugador j;
    cout << "Ingrese el alias del jugador para ver la mano: ";
    cin >> alias;
    j.setAlias(alias);
    if(jugador1.getAlias() == alias){
        cout << jugador1.getMano().imprimirMano();
        cout << "\n\n" << jugador1.getBaraja().imprimirBaraja();
    }else if (jugador2.getAlias() == alias){
        cout << jugador2.getMano().imprimirMano();
         cout << "\n\n" << jugador2.getBaraja().imprimirBaraja();
    }
}

