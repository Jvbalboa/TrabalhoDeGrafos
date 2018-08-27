#include <iostream>
#include "Aresta.h"

using namespace std;

Aresta::Aresta()
{
    idNo = 0;
    peso = 0;
    prox = 0;
    ant = 0;
}

Aresta::Aresta(int idNo, Aresta *ant, Aresta *prox)
{
    this->idNo = idNo;
    this->ant = ant;
    this->prox = prox;
    peso = 0;
}

Aresta::Aresta(int idNo, int peso, Aresta *ant, Aresta *prox)
{
    this->idNo = idNo;
    this->ant = ant;
    this->prox = prox;
    this->peso = peso;
}

Aresta::~Aresta()
{
    cout << "Destruindo Aresta" << endl;
}

void Aresta::setProx(Aresta* a)
{
    prox = a;
}

void Aresta::setAnt(Aresta* a)
{
    ant = a;
}

Aresta* Aresta::getProx()
{
    return prox;
}

Aresta* Aresta::getAnt()
{
    return ant;
}

int Aresta::getInfo()
{
    return idNo;
}

int Aresta::getPeso()
{
    return peso;
}
