/* Cenfotec – Costa Rica
 * Estructura de Datos – 2018-02
 * Nombre del archivo: ListaPuntuaciones.cpp
 * Autor: Ángel Marín, Christhian Montes, Daniel Rodriguez
 * e-mail: amarint@cenfotec.com,cmontesa@ucenfotec.ac.cr,drodriguezr@ucenfotec.ac.cr
 * ProyectoNo2Juego – Proyecto juego con estructuras
 * Fecha de creación: Julio del 2018
 * Fecha de último cambio: Agosto del 2018
 */

#include "ListaPuntuaciones.h"
#include "Puntuacion.h"
#include <sstream>

ListaPuntuaciones::ListaPuntuaciones() {
    setInicio(NULL);
}

ListaPuntuaciones::~ListaPuntuaciones() {
}

void ListaPuntuaciones::setInicio(NodoPuntuacion* pNuevoNodoPuntuacion) {
    inicio = pNuevoNodoPuntuacion;
}

NodoPuntuacion* ListaPuntuaciones::getInicio() {
    return inicio;
}

bool ListaPuntuaciones::esVacio() {
    return inicio == NULL;
}

void ListaPuntuaciones::insertarAlInicio(Puntuacion* pNewRecord) {
    NodoPuntuacion* nuevo = new NodoPuntuacion(pNewRecord);
    if (esVacio()) {
        setInicio(nuevo);
    } else {
        nuevo->setSiguiente(getInicio());
        setInicio(nuevo);
    }
}

void ListaPuntuaciones::insertarOrdenado(Puntuacion* pNewRecord) {
    if (getInicio() == NULL || pNewRecord->getPuntuacion() >=
            getInicio()->getInfo()->getPuntuacion()) {
        insertarAlInicio(pNewRecord);
    } else {
        NodoPuntuacion* nuevoNodo = new NodoPuntuacion(pNewRecord);
        NodoPuntuacion* aux = getInicio();
        while (aux->getSiguiente() != NULL &&
                aux->getSiguiente()->getInfo()->getPuntuacion() >= pNewRecord->getPuntuacion()) {
            aux = aux->getSiguiente();
        }
        nuevoNodo->setSiguiente(aux->getSiguiente());
        aux->setSiguiente(nuevoNodo);
    }
}

Puntuacion* ListaPuntuaciones::buscar(string pNombre) {
    NodoPuntuacion* aux = getInicio();
    while (aux != NULL) {
        if (aux->getInfo()->getNomJugador() == pNombre) {
            return aux->getInfo();
        } else {
            aux = aux->getSiguiente();
        }
    }
    return NULL;
}

string ListaPuntuaciones::mostrar() {
    NodoPuntuacion* aux = getInicio();
    stringstream contenido;
    int cont = 0;
    contenido << "--------------------------------------- \n";

    while (aux != NULL) {
        contenido << ++cont << "- " << aux->getInfo()->toString() << "\n";
        aux = aux->getSiguiente();
    }

    contenido << "--------------------------------------- \n";
    return contenido.str();
}

bool ListaPuntuaciones::eliminar(string pNombre) {
    if (esVacio()) {
        return false;
    } else {
        if (getInicio()->getInfo()->getNomJugador() == pNombre) {
            setInicio(getInicio()->getSiguiente());
            return true;
        } else {
            NodoPuntuacion* aux = getInicio();
            while (aux != NULL && aux->getSiguiente() != NULL &&
                    aux->getSiguiente()->getInfo()->getNomJugador() !=
                    pNombre) {
                aux = aux->getSiguiente();
            }
            if (aux != NULL && aux->getSiguiente() != NULL) {
                aux->setSiguiente(aux->getSiguiente()->getSiguiente());
                return true;
            }
        }
    }
    return false;
}

