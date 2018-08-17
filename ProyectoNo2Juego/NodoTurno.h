/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodoTurnos.h
 * Author: Steven
 *
 * Created on August 16, 2018, 4:07 PM
 */

#ifndef NODOTURNOS_H
#define NODOTURNOS_H
#include <stdlib.h>
#include "Jugador.h"

class NodoTurno {
public:
    NodoTurno();
    NodoTurno(Jugador*);
    virtual ~NodoTurno();
    void setSiguiente(NodoTurno*);
    void setInfo(Jugador*);
    NodoTurno* getSiguiente();
    Jugador* getInfo();
private:
    NodoTurno* siguiente;
    Jugador* jugadorActual;
};

#endif /* NODOTURNOS_H */

