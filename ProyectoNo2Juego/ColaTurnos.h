/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ColaTurnos.h
 * Author: Steven
 *
 * Created on August 16, 2018, 4:17 PM
 */

#ifndef COLATURNOS_H
#define COLATURNOS_H
#include "NodoTurno.h"
#include <string>

using namespace std;

class ColaTurnos {
public:
    ColaTurnos();
    virtual ~ColaTurnos();
    void setFrente(NodoTurno* nuevoFrente);
    void setFinal(NodoTurno* nuevoFinal);
    void setLongitud(int nuevaLongitud);
    NodoTurno* getFrente();
    NodoTurno* getFinal();
    int getLongitud();
    bool estaVacia();
    void insertarElem(Jugador* nuevoJugador);
    string mostrar();
    void terminarTurno();
private:
    NodoTurno* frente;
    NodoTurno* fin;
    int longitud;
};

#endif /* COLATURNOS_H */

