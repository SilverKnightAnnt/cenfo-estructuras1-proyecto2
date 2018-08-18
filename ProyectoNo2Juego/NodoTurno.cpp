/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodoTurnos.cpp
 * Author: Steven
 * 
 * Created on August 16, 2018, 4:08 PM
 */

#include "NodoTurno.h"

NodoTurno::NodoTurno() {
    setInfo(NULL);
    setSiguiente(NULL);
}

NodoTurno::NodoTurno(Jugador* nuevoJugador) {
    setInfo(nuevoJugador);
    setSiguiente(NULL);
}

NodoTurno::~NodoTurno() {
}

void NodoTurno::setSiguiente(NodoTurno* pSiguiente) {
    siguiente = pSiguiente;
}

void NodoTurno::setInfo(Jugador* pNuevo) {
    jugadorActual = pNuevo;
}

NodoTurno* NodoTurno::getSiguiente() {
    return siguiente;
}

Jugador* NodoTurno::getInfo() {
    return jugadorActual;
}


