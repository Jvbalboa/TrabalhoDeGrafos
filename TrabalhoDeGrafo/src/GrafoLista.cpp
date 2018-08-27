#include <iostream>
#include "GrafoLista.h"

using namespace std;

GrafoLista::GrafoLista(int tam)
{
    ultimo = -1;
    nos = new No[tam];
    numMax = tam;
}

GrafoLista::~GrafoLista()
{
    cout << "Destruindo Grafo" << endl;
    for(int i = 0; i < numMax; i++)
    {
        No *p = &nos[i];
        p->limparNo();
        delete p;
    }
}

int GrafoLista::getUltimo()
{
    return ultimo;
}

int GrafoLista::getNumMax()
{
    return numMax;
}

int GrafoLista::getNumNos()
{
    return ultimo + 1;
}

void GrafoLista::insereNo(int id)
{
    if(nos[id].getId() == -1)
        nos[id].setId(id);
    else if(ultimo + 1 == numMax)
    {
        No *listaNova = new No[numMax*2];
        for(int i = 0; i < numMax; i++)
            listaNova[i] = nos[i];
        listaNova[numMax].setId(id);
        numMax *= 2;
        nos = listaNova;
        delete listaNova;
    }
    else
        nos[ultimo + 1].setId(id);
    ultimo++;
}

void GrafoLista::removeNo(int id)
{
    int i = id;
    if(nos[i].getId() != id)
        for(i = 0; i <= ultimo; i++)
            if(nos[i].getId() == id)
                break;
    if(i <= ultimo)
    {
        Aresta *a = nos[i].getPrimeiraAresta();
        while(a != NULL)
        {
            Aresta *b = a;
            a = a->getProx();
            delete b;
        }
        for(int k = id; k < ultimo; k++)
            nos[k] = nos[k+1];
        ultimo--;
        Aresta *aux;
        for(int k = 0; k < ultimo; k++)
        {
            aux = nos[k].getPrimeiraAresta();
            while(aux != NULL)
            {
                if(aux->getInfo() == id)
                    nos[k].removeAresta(nos[k].getId(), aux->getPeso());
                aux = aux->getProx();
            }
        }
    }
    else
        cout << "Nó inexistente" << endl;
}

void GrafoLista::insereAresta(int noOrigem, int noDestino, int peso)
{
    int i = noOrigem;
    if(nos[i].getId() != noOrigem)
        for(i = 0; i <= ultimo; i++)
            if(nos[i].getId() == noOrigem)
                break;
    if(i <= ultimo)
    {
        nos[i].insereAresta(noDestino, peso);
        i = noDestino;
        if(nos[i].getId() != noDestino)
            for(i = 0; i <= ultimo; i++)
                if(nos[i].getId() == noDestino)
                    break;
        if(i <= ultimo)
            nos[i].insereAresta(noOrigem, peso);
        else
            cout << "Nó inexistente" << endl;
    }
    else
        cout << "Nó inexistente" << endl;
}

void GrafoLista::removeAresta(int noOrigem, int noDestino, int peso)
{
    int i = noOrigem;
    if(nos[i].getId() != noOrigem)
        for(i = 0; i <= ultimo; i++)
            if(nos[i].getId() == noOrigem)
                break;
    if(i <= ultimo)
    {
        nos[i].removeAresta(noDestino, peso);
        int i = noDestino;
        if(nos[i].getId() != noDestino)
            for(i = 0; i <= ultimo; i++)
                if(nos[i].getId() == noDestino)
                    break;
        if(i <= ultimo)
            nos[i].removeAresta(noOrigem, peso);
        else
            cout << "Nó inexistente" << endl;
    }
    else
        cout << "Nó inexistente" << endl;
}

int GrafoLista::getGrauNo(int id)
{
    int i = id;
    if(nos[i].getId() == id)
        return nos[i].getGrau();
    else if(nos[i].getId() != id)
        for(i = 0; i <= ultimo; i++)
            if(nos[i].getId() == id)
                break;
    if(i <= ultimo)
        return nos[i].getGrau();
    else
        cout << "Nó inexistente" << endl;
}
