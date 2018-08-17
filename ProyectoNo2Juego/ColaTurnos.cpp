/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ColaTurnos.cpp
 * Author: Steven
 * 
 * Created on August 16, 2018, 4:17 PM
 */

#include "ColaTurnos.h"
#include <sstream>

ColaTurnos::ColaTurnos() {
    setFrente(NULL);
    setFinal(NULL);
    setLongitud(0);
}

ColaTurnos::~ColaTurnos() {
}

void ColaTurnos::setFrente(NodoTurno* nuevoFrente) {
    frente = nuevoFrente;
}

void ColaTurnos::setFinal(NodoTurno* nuevoFinal) {
    fin = nuevoFinal;
}

void ColaTurnos::setLongitud(int nuevaLongitud) {
    longitud = nuevaLongitud;
}

NodoTurno* ColaTurnos::getFrente() {
    return frente;
}

NodoTurno* ColaTurnos::getFinal() {
    return fin;
}

int ColaTurnos::getLongitud() {
    return longitud;
}

bool ColaTurnos::estaVacia() {
    return frente == NULL;
}

void ColaTurnos::insertarElem(Jugador* nuevoJugador) {
    NodoTurno* nuevo = new NodoTurno(nuevoJugador);

    if (estaVacia()) {
        setFrente(nuevo);
    } else {
        fin->setSiguiente(nuevo);
    }

    setFinal(nuevo);
    longitud++;
}

string ColaTurnos::mostrar() {
    stringstream contenido;
    NodoTurno* aux = getFrente();

    while (aux != NULL) {
        contenido << "\nAlias: ";
        contenido << aux->getInfo()->getAlias();
        contenido << "\nMano: ";
        contenido << aux->getInfo()->getMano().imprimirMano();
        contenido << "\n";
        aux = aux->getSiguiente();
    }

    return contenido.str();
}

void ColaTurnos::terminarTurno() {
    insertarElem(getFrente()->getInfo());
    NodoTurno* aux = getFrente();
    setFrente(getFrente()->getSiguiente());
    delete aux;
}

