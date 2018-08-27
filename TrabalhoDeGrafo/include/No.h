#ifndef NO_H
#define NO_H
#include "Aresta.h"

class No
{
    private:
        int id;
        int grau;
        Aresta *primeiraAresta;
        Aresta *ultimaAresta;

    public:
        No();
        No(int id);
        ~No();
        int getGrau();
        void insereAresta(int idNo, int peso);
        void removeAresta(int idNo, int peso);
        int getId();
        void setId(int id);
        Aresta* getPrimeiraAresta();
        void limparNo();
};

#endif // NO_H
