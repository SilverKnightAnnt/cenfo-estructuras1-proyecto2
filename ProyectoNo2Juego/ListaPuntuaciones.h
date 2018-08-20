/* Cenfotec – Costa Rica
 * Estructura de Datos – 2018-02
 * Nombre del archivo: ListaPuntuaciones.h
 * Autor: Ángel Marín, Christhian Montes, Daniel Rodriguez
 * e-mail: amarint@cenfotec.com,cmontesa@ucenfotec.ac.cr,drodriguezr@ucenfotec.ac.cr
 * ProyectoNo2Juego – Proyecto juego con estructuras
 * Fecha de creación: Julio del 2018
 * Fecha de último cambio: Agosto del 2018
 */

#ifndef LISTAPUNTUACIONES_H
#define LISTAPUNTUACIONES_H
#include "NodoPuntuacion.h"
#include <string>

using namespace std;

class ListaPuntuaciones {
private:
    bool esVacio();
    NodoPuntuacion* inicio;
public:
    ListaPuntuaciones();
    virtual ~ListaPuntuaciones();
    void setInicio(NodoPuntuacion* pNuevoNodo);
    NodoPuntuacion* getInicio();
    void insertarAlInicio(Puntuacion* pNewRecord);
    void insertarOrdenado(Puntuacion* pNewRecord);
    string mostrar();
    Puntuacion* buscar(string pNombre);
    bool eliminar(string pNombre);
};

#endif /* LISTAPUNTUACIONES_H */

