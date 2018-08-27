#ifndef GRAFOMATRIZ_H
#define GRAFOMATRIZ_H


class GrafoMatriz
{
    private:
        int **no;
        int ordem;
        int numNos;
    public:
        GrafoMatriz(int ordem);
        ~GrafoMatriz();
        void insereNo();
        void removeNo(int id);
        void insereAresta(int noOrigem, int noDestino, int peso);
        void removeAresta(int noOrigem, int noDestino);
        int getUltimo();
        int getNumMax();
        int getNumNos();
        int getGrauNo(int id);
        void imprime();

};

#endif // GRAFOMATRIZ_H
