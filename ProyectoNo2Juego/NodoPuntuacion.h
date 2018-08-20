/* Cenfotec – Costa Rica
 * Estructura de Datos – 2018-02
 * Nombre del archivo: NodoPuntuacion.h
 * Autor: Ángel Marín, Christhian Montes, Daniel Rodriguez
 * e-mail: amarint@cenfotec.com,cmontesa@ucenfotec.ac.cr,drodriguezr@ucenfotec.ac.cr
 * ProyectoNo2Juego – Proyecto juego con estructuras
 * Fecha de creación: Julio del 2018
 * Fecha de último cambio: Agosto del 2018
 */

#ifndef NODOPUNTUACION_H
#define NODOPUNTUACION_H
#include <string>
#include "Puntuacion.h"

using namespace std;

class NodoPuntuacion {
private:
    Puntuacion* record;
    NodoPuntuacion* siguiente;
public:
    NodoPuntuacion();
    NodoPuntuacion(Puntuacion* pNewRecord);
    virtual ~NodoPuntuacion();
    void setInfo(Puntuacion* newRecord);
    void setSiguiente(NodoPuntuacion*);
    Puntuacion* getInfo();
    NodoPuntuacion* getSiguiente();
};

#endif /* NODOPUNTUACION_H */

