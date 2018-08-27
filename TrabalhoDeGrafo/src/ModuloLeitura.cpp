#include "ModuloLeitura.h"
#include "GrafoLista.h"
#include "GrafoMatriz.h"
#include <iostream>
#include <stdio.h>

using namespace std;

ModuloLeitura::ModuloLeitura()
{
    //ctor
}

ModuloLeitura::~ModuloLeitura()
{
    //dtor
}

GrafoLista* ModuloLeitura::lerGrafoPonderadoLista(char arquivo[200])
{
    FILE *arq;
    arq = fopen(arquivo, "rt");
    int tam, noOrigem, noDestino, peso;
    fscanf(arq, "%d",&tam);
    GrafoLista *g = new GrafoLista(tam);
    for(int i = 0; i < tam; i++)
        g->insereNo(i);
    int linha = 0;
    while (!feof(arq))
    {
        fscanf(arq, "%d %d %d",&noOrigem, &noDestino, &peso);
        g->insereAresta(noOrigem, noDestino, peso);
    }
    return g;
}

GrafoLista* ModuloLeitura::lerGrafoNaoPonderadoLista(char arquivo[200])
{
    FILE *arq;
    arq = fopen(arquivo, "rt");
    int tam, noOrigem, noDestino;
    fscanf(arq, "%d",&tam);
    GrafoLista *g = new GrafoLista(tam);
    for(int i = 0; i < tam; i++)
        g->insereNo(i);
    int linha = 0;
    while (!feof(arq))
    {
        fscanf(arq, "%d %d",&noOrigem, &noDestino);
        g->insereAresta(noOrigem, noDestino, 0);
        linha++;
    }
    return g;
}

GrafoMatriz* ModuloLeitura::lerGrafoPonderadoMatriz(char arquivo[200])
{
    FILE *arq;
    arq = fopen(arquivo, "rt");
    int tam, noOrigem, noDestino, peso;
    fscanf(arq, "%d",&tam);
    GrafoMatriz *g = new GrafoMatriz(tam);
    for(int i = 0; i < tam; i++)
        g->insereNo();
    int linha = 0;
    while (!feof(arq))
    {
        fscanf(arq, "%d %d %d",&noOrigem, &noDestino, &peso);
        g->insereAresta(noOrigem, noDestino, peso);
        linha++;
    }
    return g;
}

GrafoMatriz* ModuloLeitura::lerGrafoNaoPonderadoMatriz(char arquivo[200])
{
    FILE *arq;
    arq = fopen(arquivo, "rt");
    int tam, noOrigem, noDestino;
    fscanf(arq, "%d",&tam);
    GrafoMatriz *g = new GrafoMatriz(tam);
    for(int i = 0; i < tam; i++)
        g->insereNo();
    int linha = 0;
    while (!feof(arq))
    {
        fscanf(arq, "%d %d",&noOrigem, &noDestino);
        g->insereAresta(noOrigem, noDestino, 0);
        linha++;
    }
    return g;
}
