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
    Puntuacion* getInfo();
    NodoPuntuacion* getSiguiente();   
private:
    Puntuacion* record;
    NodoPuntuacion* siguiente;
};

#endif /* NODOPUNTUACION_H */

