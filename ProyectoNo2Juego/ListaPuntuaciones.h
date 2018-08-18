/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaPuntuaciones.h
 * Author: Steven
 *
 * Created on August 17, 2018, 11:01 PM
 */

#ifndef LISTAPUNTUACIONES_H
#define LISTAPUNTUACIONES_H
#include "NodoPuntuacion.h"
#include <string>

using namespace std;

class ListaPuntuaciones {
public:
    ListaPuntuaciones();
    virtual ~ListaPuntuaciones();
    void setInicio(NodoPuntuacion* pNuevoNodo);
    NodoPuntuacion* getInicio();
    void setUltimo(NodoPuntuacion* pNuevoNodo);
    NodoPuntuacion* getUltimo();
    void insertarAlInicio(Puntuacion* pNewRecord);
    void insertarOrdenado(Puntuacion* pNewRecord);
    string mostrar();
    Puntuacion* buscar(string pNombre);
private:
    bool esVacio();
    NodoPuntuacion* inicio;
    NodoPuntuacion* ultimo;
};

#endif /* LISTAPUNTUACIONES_H */

