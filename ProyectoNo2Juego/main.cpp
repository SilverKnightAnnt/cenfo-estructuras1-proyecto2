/* Cenfotec – Costa Rica
 * Estructura de Datos – 2018-02
 * Nombre del archivo: main.cpp
 * Autor: Ángel Marín, Christhian Montes, Daniel Rodriguez
 * e-mail: amarint@cenfotec.com,cmontesa@ucenfotec.ac.cr,drodriguezr@ucenfotec.ac.cr
 * ProyectoNo2Juego – Proyecto juego con estructuras
 * Fecha de creación: Julio del 2018
 * Fecha de último cambio: Agosto del 2018
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
void verReglasJuego();
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
    cout << "¡Bienvenido a Selts!";
    mostrarMenu();
    return 0;
}

void mostrarMenu() {
    int opcionMenu = -1;
    do {
        cout << "\n\nMen\u00fa principal"
                "\n1. Reglas del juego.\n2. Iniciar juego.\n3. Ranking."
                "\n4. Salir.\n\nSeleccione su opci\u00f3n: ";
        cin >> opcionMenu;
        procesarOpcionMenu(&opcionMenu);
    } while (opcionMenu != 4);
}

void procesarOpcionMenu(int* pOpcion) {
    switch (*pOpcion) {
        case 1:
            verReglasJuego();
            break;
        case 2:
            iniciarJuego();
            break;
        case 3:
            cout << controlador.mostrarPuntajes();
            break;
        case 4:
            break;
        default:
            cout << "Opci\u00f3n incorrecta.";
    }
}

bool gane;
int conteoTurnos = 1;
Jugador jugador1, jugador2;

void verReglasJuego() {
    cout << "\n\n----------------------------------°°°°°°°----------------------------------"
            "\n------------------------------REGLAS DEL JUEGO------------------------------------"
            "\n[1]--> No se puede atacar en el primer turno puesto que el enemigo no posee defensas."
            "\n[2]--> Cada carta posee un identificador, un ataque y una defensa."
            "\n[3]--> Si el ataque de una carta es mayor a la defensa de una carta enemiga, "
            "\n       la carta con el mayor ataque gana la batalla y por ende destruye a su oponente."
            "\n[4]--> Si la defensa de la carta enemiga es mayor al ataque de la carta aliada,"
            "\n       la carta enemiga gana la contienda y por ende destruye a la carta aliada."
            "\n[5]--> Si tanto el ataque como la defensa de dos cartas son iguales ambas cartas se destruyen."
            "\n[6]--> La vida disminuye en cuanto a la diferencia entre el ataque y la defensa de las cartas en combate."
            "\n       C1 => Atk: 10 C2 => Def: 7  ||| Dif: 3 |||"
            "\n[7]--> Después de cada turno se toma una carta del mazo y se agrega a la mano."
            "\n[8]--> Si no hay cartas que tomar del mazo se pierde el juego por deck out."
            "\n[9]--> Solo se permite una invocación por turno."
            "\n[10]-> No se puede invocar una carta en el campo si ya hay una carta en el mismo espacio."
            "\n[11]-> Gana el jugador que logre llevar la vida de su oponente a 0."
            "\n\n----------------------------------_:_:_:_:_:----------------------------------\n\n";
}

void iniciarJuego() {
    limpiar(&jugador1, &jugador2);
    initJugador(&jugador1, 1, 10);
    initJugador(&jugador2, 2, 10);
    if (jugador1.getAlias() == jugador2.getAlias()) {
        cout << "\n\nYa hay un jugador con dicho nombre.";
    } else {
        cout << "\n¡DUELO!";
        menuJugador();
    }
}

void limpiar(Jugador* pJ1, Jugador* pJ2) {
    gane = false;
    conteoTurnos = 1;
    controlador.setEnableAtack(true);
    controlador.setEnableSummon(true);
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
        cout << "\n\n---------------------------------------------\nTurno del jugador "
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
            break;
        default:
            cout << "Opci\u00f3n incorrecta.";
    }
}

void verMano() {
    cout << controlador.obtenerJ1()->getMano().imprimirMano();
}

void colocarCartaEnCampo() {
    verCampo();
    if (controlador.getEnableSummon()) {
        cout << "\n\n";
        verMano();
        int iden, espacio;
        cout << "\n\nIngrese el identificador de la carta que desea invocar: ";
        cin >> iden;
        cout << "Digite el espacio al cual la quiere agregar (1-5): ";
        cin >> espacio;
        if (iden > 0 && iden < 21 && espacio > 0 && espacio < 6) {
            espacio--;
            controlador.colocarCartaEnCampo(iden, espacio);
        } else {
            cout << "\n\nEl número debe ser válido.";
        }
    }
}

void verCampo() {
    cout << "\n\n" << controlador.obtenerJ2()->getAlias() << " Vida: "
            << controlador.obtenerJ2()->getVida() << "\n\n";
    cout << controlador.obtenerJ2()->getCampo().imprimirCampo();
    cout << "\n---------------------------------------------------------";
    cout << "\n" << controlador.obtenerJ1()->getCampo().imprimirCampo();
    cout << "\n\n" << controlador.obtenerJ1()->getAlias() << " Vida: "
            << controlador.obtenerJ1()->getVida();
}

void verDetalleCarta() {
    verCampo();
    int iden, numJugador;
    cout << "\n\n1. Ver el detalle de tus cartas"
            "\n2. Ver el detalle de las cartas enemigas"
            "\n\nSeleccione su opci\u00f3n: ";
    cin >> numJugador;
    if (numJugador == 1 || numJugador == 2) {
        cout << "\nIngrese el identificador de la carta que desea ver: ";
        cin >> iden;
        if (iden > 0) {
            cout << "\n***********************************************************";
            cout << controlador.verDetalleCarta(iden, numJugador);
            cout << "\n***********************************************************";
        } else {
            cout << "\n\nIdentificador inválido.";
        }
    } else {
        cout << "\n\nEl número debe ser 1 ó 2.";
    }
}

void terminarTurno() {
    cout << "\nTermino el turno del jugador "
            << controlador.obtenerJ1()->getAlias();
    controlador.terminarTurnoJugador();
    obtenerCarta();
    controlador.setEnableSummon(true);
    controlador.setEnableAtack(true);
    conteoTurnos++;
}

void obtenerCarta() {
    if (controlador.obtenerLongitudBarajaJ1() > 0) {
        controlador.obtenerCarta();
        cout << "\n\nSe agregó una carta a la mano.";
    } else {
        cout << "\n\nGanó el jugador " << controlador.obtenerJ2()->getAlias() << " por deck out.";
        controlador.insertarPuntajes(100, controlador.obtenerJ2()->getAlias());
        gane = true;
    }
}

void declararGanador() {
    int vidaJ1 = controlador.obtenerJ1()->getVida();
    int vidaJ2 = controlador.obtenerJ2()->getVida();

    if (vidaJ1 <= 0 && vidaJ2 > 0) {
        cout << "\n\nGanó el jugador " << controlador.obtenerJ2()->getAlias();
        gane = true;
        controlador.insertarPuntajes(100, controlador.obtenerJ2()->getAlias());
    } else if (vidaJ1 > 0 && vidaJ2 <= 0) {
        cout << "\n\nGanó el jugador " << controlador.obtenerJ1()->getAlias();
        gane = true;
        controlador.insertarPuntajes(100, controlador.obtenerJ1()->getAlias());
    }
}

void atacar() {
    if (conteoTurnos != 1 && controlador.getEnableAtack()) {
        int iden, iden2;
        verCampo();
        cout << "\n\nIngrese el identificador de la carta atacante: ";
        cin >> iden;
        cout << "Ingrese el identificador de la carta a atacar: ";
        cin >> iden2;
        controlador.atacar(iden, iden2);
        declararGanador();
    }
}