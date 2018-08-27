#ifndef ARESTA_H
#define ARESTA_H

class Aresta
{
    private:
        int idNo;
        int peso;
        Aresta *prox;
        Aresta *ant;

    public:
        Aresta();
        Aresta(int idNo, Aresta *ant, Aresta *prox);
        Aresta(int idNo, int peso, Aresta *ant, Aresta *prox);
        ~Aresta();
        void setProx(Aresta *a);
        Aresta* getProx();
        void setAnt(Aresta *a);
        Aresta* getAnt();
        int getInfo();
        int getPeso();
};

#endif // ARESTA_H
