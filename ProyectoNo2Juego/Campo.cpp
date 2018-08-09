/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <string>
#include <sstream>
#include "Campo.h"

Campo::Campo() {
    cartas[5];
}

void Campo::colocarCarta(Carta pCarta, int posicion) {
    cartas[posicion] = pCarta;
}

string Campo::imprimirCampo() {
    stringstream impresion;
    for (int i = 0 ; i < 5; i++) {
        impresion << "\n" << i << " | Identificador: " << cartas[i].getIdentificador() << " | Ataque: " << cartas[i].getAtaque() << " | Defensa: " << cartas[i].getDefensa();
    }
    return impresion.str();
}