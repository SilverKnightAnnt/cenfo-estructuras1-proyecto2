/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Baraja.h"

Baraja::Baraja(){
    
}
    
void Baraja::setPilaCartas(PilaCartas pPila){
    pilaCartas = pPila;
}
    
PilaCartas Baraja::getPilaCartas(){
    return pilaCartas;
}
    
string Baraja::imprimirBaraja(){
    return pilaCartas.verPilaCartas();
}