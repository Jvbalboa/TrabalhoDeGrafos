#include <iostream>
#include "No.h"

using namespace std;

No::No()
{
    id = -1;
    grau = 0;
    primeiraAresta = NULL;
    ultimaAresta = NULL;
}

No::No(int id)
{
    this->id = id;
    grau = 0;
    primeiraAresta = NULL;
    ultimaAresta = NULL;
}

No::~No()
{
    cout << "Destruindo Nó" << endl;
    Aresta *a;
    while(a != NULL)
    {
        Aresta *b = a;
        a = a->getProx();
        delete b;
    }
}

int No::getGrau()
{
    return grau;
}

void No::insereAresta(int idNo, int peso)
{
    Aresta *a = new Aresta(idNo, peso, ultimaAresta, NULL);
    if(primeiraAresta == NULL)
        primeiraAresta = a;
    else
        ultimaAresta->setProx(a);
    ultimaAresta = a;
    grau++;
}

void No::removeAresta(int idNo, int peso)
{
    Aresta *a = primeiraAresta;
    bool achou = false;
    while(achou != true && a != NULL)
    {
        if(a->getInfo() == idNo && a->getPeso() == peso)
            achou = true;
        else
            a = a->getProx();
    }
    if(achou)
    {
        if(grau = 1)
        {
            primeiraAresta = NULL;
            ultimaAresta = NULL;
        }
        if(a == primeiraAresta && grau != 1)
        {
            a->getProx()->setAnt(NULL);
            primeiraAresta = a->getProx();
        }
        if(a==ultimaAresta && grau != 1)
        {
            a->getAnt()->setProx(NULL);
            ultimaAresta = a->getAnt();
        }
        else
        {
            a->getAnt()->setProx(a->getProx());
            a->getProx()->setAnt(a->getAnt());
        }
        delete a;
        grau--;
    }
    else
        cout << "Aresta não encontrada" << endl;
}

int No::getId()
{
    return id;
}

void No::setId(int id)
{
    this->id = id;
}

Aresta* No::getPrimeiraAresta()
{
    return primeiraAresta;
}

void No::limparNo()
{
    cout << "Limpando Nó" << endl;
    Aresta *a;
    while(a != NULL)
    {
        Aresta *b = a;
        a = a->getProx();
        delete b;
    }
}
