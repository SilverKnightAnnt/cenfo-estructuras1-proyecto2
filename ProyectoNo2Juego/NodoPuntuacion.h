/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodoPuntuacion.h
 * Author: Steven
 *
 * Created on August 17, 2018, 10:22 PM
 */

#ifndef NODOPUNTUACION_H
#define NODOPUNTUACION_H
#include <string>
#include "Puntuacion.h"

using namespace std;

class NodoPuntuacion {
public:
    NodoPuntuacion();
    NodoPuntuacion(Puntuacion* pNewRecord);
    virtual ~NodoPuntuacion();
    void setInfo(Puntuacion* newRecord);
    void setSiguiente(NodoPuntuacion*);
    void setAnterior(NodoPuntuacion* pNuevo);
    Puntuacion* getInfo();
    NodoPuntuacion* getSiguiente();
    NodoPuntuacion* getAnterior();
    
private:
    Puntuacion* record;
    NodoPuntuacion* siguiente;
    NodoPuntuacion* anterior;
};

#endif /* NODOPUNTUACION_H */

