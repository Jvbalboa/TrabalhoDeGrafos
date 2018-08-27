#ifndef MODULOLEITURA_H
#define MODULOLEITURA_H
#include "GrafoLista.h"
#include "GrafoMatriz.h"

class ModuloLeitura
{
    public:
        ModuloLeitura();
        virtual ~ModuloLeitura();
        GrafoLista* lerGrafoPonderadoLista(char arquivo[200]);
        GrafoLista* lerGrafoNaoPonderadoLista(char arquivo[200]);
        GrafoMatriz* lerGrafoPonderadoMatriz(char arquivo[200]);
        GrafoMatriz* lerGrafoNaoPonderadoMatriz(char arquivo[200]);
};

#endif // MODULOLEITURA_H
