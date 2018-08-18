/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Mano.h"

Mano::Mano(){
    
}

void Mano::setListaCartas(ListaCartas pLista){
    listaCartas = pLista;
}

ListaCartas Mano::getListaCartas(){
    return listaCartas;
}

void Mano::eliminarCartaDeMano(Carta pCarta){
    listaCartas.eliminarCarta(pCarta);
}

string Mano::imprimirMano(){
    return listaCartas.verListaCartas();
}
