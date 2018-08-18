/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PilaCartas.h
 * Author: User
 *
 * Created on August 7, 2018, 8:16 PM
 */

#ifndef PILACARTAS_H
#define PILACARTAS_H

#include "NodoCartas.h"
#include <string>

using namespace std;

class PilaCartas {
private:
    NodoCartas* tope;
    int longitud = 0;
    bool pilaVacia();
public:
    Baraja();
    void setTope(NodoCartas*);
    NodoCartas* getTope();
    void setLongitud(int);
    int getLongitud();
    void insertarCarta(Carta);
    NodoCartas* obtenerTope();
    string verPilaCartas();
};

#endif /* PILACARTAS_H */

