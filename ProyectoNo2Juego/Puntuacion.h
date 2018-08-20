/* Cenfotec – Costa Rica
 * Estructura de Datos – 2018-02
 * Nombre del archivo: Puntuacion.h
 * Autor: Ángel Marín, Christhian Montes, Daniel Rodriguez
 * e-mail: amarint@cenfotec.com,cmontesa@ucenfotec.ac.cr,drodriguezr@ucenfotec.ac.cr
 * ProyectoNo2Juego – Proyecto juego con estructuras
 * Fecha de creación: Julio del 2018
 * Fecha de último cambio: Agosto del 2018
 */

#ifndef PUNTUACION_H
#define PUNTUACION_H
#include <string>

using namespace std;

class Puntuacion {
private:
    string nomJugador;
    int puntuacion;
public:
    Puntuacion();
    virtual ~Puntuacion();
    void setNomJugador(string pNomPlayer);
    void setPuntuacion(int pPuntuacion);
    string getNomJugador();
    int getPuntuacion();
    string toString();
};

#endif /* PUNTUACION_H */

