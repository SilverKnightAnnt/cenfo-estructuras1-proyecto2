/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Baraja.h
 * Author: User
 *
 * Created on August 7, 2018, 8:13 PM
 */

#ifndef BARAJA_H
#define BARAJA_H

#include "PilaCartas.h"
#include <string>

using namespace std;

class Baraja {
private:
    PilaCartas pilaCartas;
public:
    Baraja();
    void setPilaCartas(PilaCartas);
    PilaCartas getPilaCartas();
    string imprimirBaraja();
};

#endif /* BARAJA_H */

