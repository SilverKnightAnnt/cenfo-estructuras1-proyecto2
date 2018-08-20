/* Cenfotec – Costa Rica
 * Estructura de Datos – 2018-02
 * Nombre del archivo: Carta.h
 * Autor: Ángel Marín, Christhian Montes, Daniel Rodriguez
 * e-mail: amarint@cenfotec.com,cmontesa@ucenfotec.ac.cr,drodriguezr@ucenfotec.ac.cr
 * ProyectoNo2Juego – Proyecto juego con estructuras
 * Fecha de creación: Julio del 2018
 * Fecha de último cambio: Agosto del 2018
 */

#ifndef CARTA_H
#define CARTA_H

#include <string>

using namespace std;

class Carta {
private:
    int identificador;
    int ataque;
    int defensa;
public:
    Carta();
    Carta(int,int,int);
    void setIdentificador(int);
    int getIdentificador();
    void setAtaque(int);
    int getAtaque();
    void setDefensa(int);
    int getDefensa();
    string imprimirCarta();
};

#endif /* CARTA_H */

