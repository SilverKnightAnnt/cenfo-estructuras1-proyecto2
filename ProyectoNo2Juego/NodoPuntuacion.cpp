/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodoPuntuacion.cpp
 * Author: Steven
 * 
 * Created on August 17, 2018, 10:22 PM
 */

#include "NodoPuntuacion.h"

NodoPuntuacion::NodoPuntuacion() {
    setInfo(NULL);
    setSiguiente(NULL);
    setAnterior(NULL);
}

NodoPuntuacion::NodoPuntuacion(Puntuacion* pNewRecord){
    setInfo(pNewRecord);
    setSiguiente(NULL);
    setAnterior(NULL);
}

NodoPuntuacion::~NodoPuntuacion() {
}

void NodoPuntuacion::setInfo(Puntuacion* newRecord){
    record = newRecord;
}

void NodoPuntuacion::setSiguiente(NodoPuntuacion* nuevo){
    siguiente = nuevo;
}

void NodoPuntuacion::setAnterior(NodoPuntuacion* pNuevo){
    anterior = pNuevo;
}

Puntuacion* NodoPuntuacion::getInfo(){
    return record;
}

NodoPuntuacion* NodoPuntuacion::getSiguiente(){
    return siguiente;
}

NodoPuntuacion* NodoPuntuacion::getAnterior(){
    return anterior;
}

