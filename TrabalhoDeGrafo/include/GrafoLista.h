#ifndef GRAFOLISTA_H
#define GRAFOLISTA_H
#include "No.h"
#include "Aresta.h"

class GrafoLista
{
    private:
        No *nos;
        int ultimo;
        int numMax;

    public:
        GrafoLista(int tam);
        ~GrafoLista();
        void insereNo(int id);
        void removeNo(int id);
        void insereAresta(int noOrigem, int noDestino, int peso);
        void removeAresta(int noOrigem, int noDestino, int peso);
        int getUltimo();
        int getNumMax();
        int getNumNos();
        int getGrauNo(int id);

};

#endif // GRAFOLISTA_H
