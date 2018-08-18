/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Puntuacion.h
 * Author: Steven
 *
 * Created on August 17, 2018, 10:25 PM
 */

#ifndef PUNTUACION_H
#define PUNTUACION_H
#include <string>

using namespace std;

class Puntuacion {
public:
    Puntuacion();
    virtual ~Puntuacion();
    void setNomJugador(string pNomPlayer);
    void setPuntuacion(int pPuntuacion);
    string getNomJugador();
    int getPuntuacion();
    string toString();
private:
    string nomJugador;
    int puntuacion;
};

#endif /* PUNTUACION_H */

