#include <iostream>
#include "GrafoMatriz.h"

using namespace std;

GrafoMatriz::GrafoMatriz(int ordem)
{
    no = new int*[ordem+1];
    this->ordem = ordem;
    for(int i = 0; i<ordem+1; i++)
    {
        no[i] = new int[ordem+1];
        for(int j = 0; j<ordem+1; j++)
            no[i][j] = -1;
    }
    numNos = 0;
}

GrafoMatriz::~GrafoMatriz()
{
    for(int i = 0; i<ordem; i++)
        delete no[i];
}

void GrafoMatriz::insereNo()
{
    for(int j = 0; j<ordem+1; j++)
        no[getUltimo()][j] = 0;
    numNos++;
}

void GrafoMatriz::removeNo(int id)
{
    int aux = 0;
    for(int j = 0; j<ordem; j++)
    {
        if(no[id][j] != -1)
            no[id][j] = -1;
        else
            aux++;
    }
    if(aux)
        cout << "Nó inexistente" << endl;
    else
    {
        numNos--;
        for(int i = 0; i<numNos; i++)
            if(i != id)
                no[i][id] = 0;
    }
}

void GrafoMatriz::insereAresta(int noOrigem, int noDestino, int peso)
{
    if(peso == 0)
        peso = 1;
    no[noOrigem][noDestino] =  peso;
    no[noOrigem][ordem+1] = no[noOrigem][ordem+1] + 1;
    no[noDestino][noOrigem] = peso;
    no[noDestino][ordem+1] = no[noDestino][ordem+1] + 1;
}

void GrafoMatriz::removeAresta(int noOrigem, int noDestino)
{
    if(no[noOrigem][noDestino] > 0 && no[noDestino][noOrigem] > 0)
    {
        no[noOrigem][noDestino] = 0;
        no[noOrigem][ordem+1] = no[noOrigem][ordem+1] - 1;
        no[noDestino][noOrigem] = 0;
        no[noDestino][ordem+1] = no[noDestino][ordem+1] - 1;
    }
    else
        cout << "Nó inexistente" << endl;
}

int GrafoMatriz::getUltimo()
{
    return ordem - numNos;
}

int GrafoMatriz::getNumMax()
{
    return ordem;
}

int GrafoMatriz::getNumNos()
{
    return numNos;
}

int GrafoMatriz::getGrauNo(int id)
{
    return no[id][ordem+1];
}

void GrafoMatriz::imprime()
{
    for(int i = 0; i < numNos; i++)
    {
        for(int j = 0; j < ordem+1; j++)
            cout << left << no[i][j];
        cout << endl;
    }
}
