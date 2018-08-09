/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Campo.h
 * Author: User
 *
 * Created on August 7, 2018, 8:07 PM
 */

#ifndef CAMPO_H
#define CAMPO_H

#include "Carta.h"
#include <string>

using namespace std;

class Campo {
private:
    Carta cartas[5]; 
public:
    Campo();
    void colocarCarta(Carta,int);
    string imprimirCampo();
};

#endif /* CAMPO_H */

