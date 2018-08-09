/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <string>
#include <sstream>
#include "Carta.h"

using namespace std;

Carta::Carta() {
    setIdentificador(0);
    setAtaque(0);
    setDefensa(0);
}

Carta::Carta(int pIden, int pAtk, int pDef){
    setIdentificador(pIden);
    setAtaque(pAtk);
    setDefensa(pDef);
}

void Carta::setIdentificador(int pIdentificador){
    identificador = pIdentificador;
}

int Carta::getIdentificador(){
    return identificador;
}

 void Carta::setAtaque(int pAtaque){
    ataque = pAtaque;
}

int Carta::getAtaque(){
    return ataque;
}

void Carta::setDefensa(int pDefensa){
    defensa = pDefensa;
}

int Carta::getDefensa(){
    return defensa;
}

string Carta::imprimirCarta(){
    stringstream impresion;
    impresion << "\nIdentificador: " << getIdentificador() << " | Ataque: " << getAtaque() << " | Defensa: " << getDefensa();
    return impresion.str();
}
