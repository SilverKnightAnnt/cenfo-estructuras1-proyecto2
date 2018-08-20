/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Mano.h
 * Author: User
 *
 * Created on August 7, 2018, 8:12 PM
 */

#ifndef MANO_H
#define MANO_H

#include "ListaCartas.h"
#include <string>

using namespace std;

class Mano {
private:
    ListaCartas listaCartas;
public:
    Mano();
    void setListaCartas(ListaCartas);
    ListaCartas getListaCartas();
    void eliminarCartaDeMano(Carta);
    string imprimirMano();
};

#endif /* MANO_H */

