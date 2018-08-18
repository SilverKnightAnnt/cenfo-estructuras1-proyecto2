
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

