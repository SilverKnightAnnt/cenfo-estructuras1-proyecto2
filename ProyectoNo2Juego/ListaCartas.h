/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaCartas.h
 * Author: User
 *
 * Created on August 7, 2018, 8:14 PM
 */

#ifndef LISTACARTAS_H
#define LISTACARTAS_H

#include <string>
#include "NodoCartas.h"

class ListaCartas {
private:
    NodoCartas* cabeza;
    int tamanno;
    bool listaVacia();
public:
    ListaCartas();
    void setTamanno(int);
    int getTamanno();
    void setCabeza(NodoCartas*);
    NodoCartas* getCabeza();
    void insertarCarta(Carta);
    string verListaCartas();
    NodoCartas* buscarCartaPorIdentificador(Carta);
    void eliminarCarta(Carta);
};

#endif /* LISTACARTAS_H */

