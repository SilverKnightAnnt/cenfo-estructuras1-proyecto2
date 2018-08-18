/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaPuntuaciones.cpp
 * Author: Steven
 * 
 * Created on August 17, 2018, 11:01 PM
 */

#include "ListaPuntuaciones.h"
#include "Puntuacion.h"
#include <sstream>

ListaPuntuaciones::ListaPuntuaciones() {
    setInicio(NULL);
    setUltimo(NULL);
}

ListaPuntuaciones::~ListaPuntuaciones() {
}

void ListaPuntuaciones::setInicio(NodoPuntuacion* pNuevoNodo) {
    inicio = pNuevoNodo;
}

void ListaPuntuaciones::setUltimo(NodoPuntuacion* pNuevoNodo) {
    ultimo = pNuevoNodo;
}

NodoPuntuacion* ListaPuntuaciones::getInicio() {
    return inicio;
}

NodoPuntuacion* ListaPuntuaciones::getUltimo() {
    return ultimo;
}

bool ListaPuntuaciones::esVacio() {
    return inicio == NULL;
}

void ListaPuntuaciones::insertarAlInicio(Puntuacion* pNewRecord) {
    NodoPuntuacion* nuevo = new NodoPuntuacion(pNewRecord);

    if (!esVacio()) {
        nuevo->setAnterior(getUltimo());
        getUltimo()->setSiguiente(nuevo);
    } else {
        setInicio(nuevo);
    }

    setUltimo(nuevo);
}

void ListaPuntuaciones::insertarOrdenado(Puntuacion* pNewRecord) {
    if (esVacio()) {
        insertarAlInicio(pNewRecord);
    } else {
        NodoPuntuacion* nuevo = new NodoPuntuacion(pNewRecord);

        if (pNewRecord->getPuntuacion() < getInicio()->getInfo()->getPuntuacion()) {
            getInicio()->setAnterior(nuevo);
            nuevo->setSiguiente(getInicio());
            setInicio(nuevo);
        } else {
            NodoPuntuacion* aux = getInicio();

            while (aux != NULL) {

                if (aux->getSiguiente() == NULL) {
                    insertarAlInicio(pNewRecord);
                    break;
                }

                if (aux->getInfo()->getPuntuacion() < pNewRecord->getPuntuacion() &&
                        aux->getSiguiente()->getInfo()->getPuntuacion() > pNewRecord->getPuntuacion()) {
                    nuevo->setAnterior(aux);
                    nuevo->setSiguiente(aux->getSiguiente());
                    aux->getSiguiente()->setAnterior(nuevo);
                    aux->setSiguiente(nuevo);
                    break;
                }

                aux = aux->getSiguiente();
            }
        }

    }
}

Puntuacion* ListaPuntuaciones::buscar(string pNombre) {
    NodoPuntuacion* aux = getUltimo();

    while (aux != NULL) {
        if (aux->getInfo()->getNomJugador() == pNombre) {
            return aux->getInfo();
        }
        aux = aux->getAnterior();
    }

    return NULL;
}

string ListaPuntuaciones::mostrar() {
    NodoPuntuacion* aux = getUltimo();
    stringstream contenido;
    int cont = 0;
    contenido << "--------------------------------------- \n";

    while (aux != NULL) {
        contenido << ++cont << "- " << aux->getInfo()->toString() << "\n";
        aux = aux->getAnterior();
    }

    contenido << "--------------------------------------- \n";
    return contenido.str();
}

