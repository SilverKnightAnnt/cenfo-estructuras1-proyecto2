/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Jugador.h"
#include <string>

Jugador::Jugador(){
    
}

void Jugador::setAlias(string pAlias){
    alias = pAlias;
}

string Jugador::getAlias(){
    return alias;
}

void Jugador::setVida(int pVida){
    vida = pVida;
}

int Jugador::getVida(){
    return vida;
}

void Jugador::setBaraja(Baraja pBaraja){
    baraja = pBaraja;
}

Baraja Jugador::getBaraja(){
    return baraja;
}

void Jugador::setMano(Mano pMano){
    mano = pMano;
}

Mano Jugador::getMano(){
    return mano;
}

void Jugador::setCampo(Campo pCampo){
    campo = pCampo;
}

Campo Jugador::getCampo(){
    return campo;
}

string imprimirJugador(){
    
}