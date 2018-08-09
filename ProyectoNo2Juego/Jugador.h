/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Jugador.h
 * Author: User
 *
 * Created on August 7, 2018, 8:13 PM
 */

#ifndef JUGADOR_H
#define JUGADOR_H

#include "Baraja.h"
#include "Mano.h"
#include <string>

using namespace std;

class Jugador {
private:
    string alias;
    int vida;
    Baraja baraja;
    Mano mano;
public:
    Jugador();
    void setAlias(string);
    string getAlias();
    void setVida(int);
    int getVida();
    void setBaraja(Baraja);
    Baraja getBaraja();
    void setMano(Mano);
    Mano getMano();
    string imprimirJugador();
};

#endif /* JUGADOR_H */

