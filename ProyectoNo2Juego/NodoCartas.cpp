/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "NodoCartas.h"

NodoCartas::NodoCartas(){
    setSiguiente(NULL);
}

void NodoCartas::setCarta(Carta pCarta){
    carta = pCarta;
}

Carta NodoCartas::getCarta(){
    return carta;
}

void NodoCartas::setSiguiente(NodoCartas* pSiguiente){
    siguiente = pSiguiente;
}

NodoCartas* NodoCartas::getSiguiente(){
    return siguiente;
}

