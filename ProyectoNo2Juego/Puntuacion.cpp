/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Puntuacion.cpp
 * Author: Steven
 * 
 * Created on August 17, 2018, 10:25 PM
 */

#include "Puntuacion.h"
#include <sstream>

Puntuacion::Puntuacion() {
    setPuntuacion(0);
}

Puntuacion::~Puntuacion() {
}

void Puntuacion::setNomJugador(string pNomPlayer){
    nomJugador = pNomPlayer;
}

void Puntuacion::setPuntuacion(int pPuntuacion){
    puntuacion = pPuntuacion;
}

string Puntuacion::getNomJugador(){
    return nomJugador;
}

int Puntuacion::getPuntuacion(){
    return puntuacion;
}

string Puntuacion::toString(){
    stringstream contenido;
    contenido << "Nombre: " << getNomJugador()
            << "Puntaje: " << getPuntuacion() << "\n";
    return contenido.str();
}

