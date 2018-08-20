/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodoCartas.h
 * Author: User
 *
 * Created on August 7, 2018, 8:22 PM
 */

#ifndef NODOCARTAS_H
#define NODOCARTAS_H

#include "Carta.h"

class NodoCartas {
private:
    Carta carta;
    NodoCartas* siguiente;
public:
    NodoCartas();
    void setCarta(Carta);
    Carta getCarta();
    void setSiguiente(NodoCartas*);
    NodoCartas* getSiguiente();
};

#endif /* NODOCARTAS_H */

