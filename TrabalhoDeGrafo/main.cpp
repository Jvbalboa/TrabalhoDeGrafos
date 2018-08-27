#include <iostream>
#include <stdio.h>
#include <string>
#include "GrafoLista.h"
#include "GrafoMatriz.h"
#include "ModuloLeitura.h"

//AUTOR: JOÃO VICTOR DUTRA BALBOA

using namespace std;

void LerArquivo();

int main()
{

    int escolha, tam, aux, idNo, noOrigem, noDestino, peso;
    do
    {
        cout << "\t\t\tEscolha a opção: \n1 -> Grafo por lista de adjacência \n2 -> Grafo por matriz de adjacência \n3 -> Ler arquivo do trabalho \nOutros valores -> Sair" << endl;
        cin >> escolha;
        switch(escolha)
        {
            case 1:
            {
                cout << "\t\t\tGrafo por lista de adjacência " << endl;
                cout << "Tamanho máximo do grafo: ";
                cin >> tam;
                GrafoLista gl(tam);
                do
                {
                    cout << "\t\t\tEscolha a opção: \n1 -> Inserir nó \n2 -> Inserir aresta \n3 -> Excluir nó \n4 -> Excluir aresta \n5 -> Grau do nó \n6 -> Número de nós \nOutros valores -> Voltar ao menu" << endl;
                    cin >> aux;
                    switch(aux)
                    {
                        case 1:
                        {
                            cout << "Nó id: ";
                            cin >> idNo;
                            gl.insereNo(idNo);
                            cout << "Inserindo nó..." << endl;
                            break;
                        }
                        case 2:
                        {
                            cout << "Nó de origem: ";
                            cin >> noOrigem;
                            cout << "Nó de destino: ";
                            cin >> noDestino;
                            cout << "Peso aresta: ";
                            cin >> peso;
                            gl.insereAresta(noOrigem, noDestino, peso);
                            cout << "Inserindo aresta..." << endl;
                             break;
                        }
                        case 3:
                        {
                            cout << "Nó id: ";
                            cin >> idNo;
                            gl.removeNo(idNo);
                            break;
                        }
                        case 4:
                        {
                            cout << "Nó de origem: ";
                            cin >> noOrigem;
                            cout << "Nó de destino: ";
                            cin >> noDestino;
                            cout << "Peso aresta: ";
                            cin >> peso;
                            gl.removeAresta(noOrigem, noDestino, peso);
                            cout << "Removendo aresta..." << endl;
                            break;
                        }
                        case 5:
                        {
                            cout << "Nó id: ";
                            cin >> idNo;
                            cout << "Grau: " << gl.getGrauNo(idNo) << endl;
                            break;
                        }
                        case 6:
                        {
                            cout << "Número de nós: " << gl.getNumNos() << endl;
                            break;
                        }
                    }
                } while(aux > 0 && aux <= 6);
                break;
                }

            case 2:
            {
                cout << "\t\t\tGrafo por matriz de adjacência " << endl;
                cout << "Tamanho máximo do grafo: ";
                cin >> tam;
                GrafoMatriz gm(tam);
                do
                {
                    cout << "\t\t\tEscolha a opção: \n1 -> Inserir nó \n2 -> Inserir aresta \n3 -> Excluir nó \n4 -> Excluir aresta \n5 -> Grau do nó \n6 -> Número de nós \nOutros valores -> Voltar ao menu" << endl;
                    cin >> aux;
                    switch(aux)
                    {
                        case 1:
                        {
                            cout << "Inserindo nó..." << endl;
                            gm.insereNo();
                            break;
                        }
                        case 2:
                        {
                            cout << "Nó de origem: ";
                            cin >> noOrigem;
                            cout << "Nó de destino: ";
                            cin >> noDestino;
                            cout << "Peso aresta: ";
                            cin >> peso;
                            gm.insereAresta(noOrigem, noDestino, peso);
                            cout << "Inserindo aresta..." << endl;
                             break;
                        }
                        case 3:
                        {
                            cout << "Nó id: ";
                            cin >> idNo;
                            gm.removeNo(idNo);
                            cout << "Removendo nó..." << endl;
                            break;
                        }
                        case 4:
                        {
                            cout << "Nó de origem: ";
                            cin >> noOrigem;
                            cout << "Nó de destino: ";
                            cin >> noDestino;
                            gm.removeAresta(noOrigem, noDestino);
                            cout << "Removendo aresta..." << endl;
                            break;
                        }
                        case 5:
                        {
                            cout << "Nó id: ";
                            cin >> idNo;
                            cout << "Grau: " << gm.getGrauNo(idNo) << endl;
                            break;
                        }
                        case 6:
                        {
                            cout << "Número de nós: " << gm.getNumNos() << endl;
                            break;
                        }
                    }
                } while(aux > 0 && aux <= 6);
                break;
            }
            case 3:
                LerArquivo();
                break;
        }
    } while(escolha > 0 && escolha <= 3);
    return 0;
}

void LerArquivo()
{
    ModuloLeitura modulo;
    GrafoLista *grafo_1000_1_lista = modulo.lerGrafoNaoPonderadoLista("C:/Users/JV/Desktop/Arquivos entrada grafos/instancias Grafos não ponderados/grafo_1000_1.txt");
    GrafoMatriz *grafo_1000_1_matriz = modulo.lerGrafoNaoPonderadoMatriz("C:/Users/JV/Desktop/Arquivos entrada grafos/instancias Grafos não ponderados/grafo_1000_1.txt");
    delete grafo_1000_1_lista;
    delete grafo_1000_1_matriz;
    GrafoLista *grafo_1000_2_lista = modulo.lerGrafoNaoPonderadoLista("C:/Users/JV/Desktop/Arquivos entrada grafos/instancias Grafos não ponderados/grafo_1000_2.txt");
    GrafoMatriz *grafo_1000_2_matriz = modulo.lerGrafoNaoPonderadoMatriz("C:/Users/JV/Desktop/Arquivos entrada grafos/instancias Grafos não ponderados/grafo_1000_2.txt");
    delete grafo_1000_2_lista;
    delete grafo_1000_2_matriz;
    GrafoLista *grafo_1000_3_lista = modulo.lerGrafoNaoPonderadoLista("C:/Users/JV/Desktop/Arquivos entrada grafos/instancias Grafos não ponderados/grafo_1000_3.txt");
    GrafoMatriz *grafo_1000_3_matriz = modulo.lerGrafoNaoPonderadoMatriz("C:/Users/JV/Desktop/Arquivos entrada grafos/instancias Grafos não ponderados/grafo_1000_3.txt");
    delete grafo_1000_3_lista;
    delete grafo_1000_3_matriz;
    GrafoLista *grafo_1000_4_lista = modulo.lerGrafoNaoPonderadoLista("C:/Users/JV/Desktop/Arquivos entrada grafos/instancias Grafos não ponderados/grafo_1000_4.txt");
    GrafoMatriz *grafo_1000_4_matriz = modulo.lerGrafoNaoPonderadoMatriz("C:/Users/JV/Desktop/Arquivos entrada grafos/instancias Grafos não ponderados/grafo_1000_4.txt");
    delete grafo_1000_4_lista;
    delete grafo_1000_4_matriz;
    GrafoLista *grafo_1000_5_lista = modulo.lerGrafoNaoPonderadoLista("C:/Users/JV/Desktop/Arquivos entrada grafos/instancias Grafos não ponderados/grafo_1000_5.txt");
    GrafoMatriz *grafo_1000_5_matriz = modulo.lerGrafoNaoPonderadoMatriz("C:/Users/JV/Desktop/Arquivos entrada grafos/instancias Grafos não ponderados/grafo_1000_5.txt");
    delete grafo_1000_5_lista;
    delete grafo_1000_5_matriz;
    GrafoLista *grafo_1000_6_lista = modulo.lerGrafoNaoPonderadoLista("C:/Users/JV/Desktop/Arquivos entrada grafos/instancias Grafos não ponderados/grafo_1000_6.txt");
    GrafoMatriz *grafo_1000_6_matriz = modulo.lerGrafoNaoPonderadoMatriz("C:/Users/JV/Desktop/Arquivos entrada grafos/instancias Grafos não ponderados/grafo_1000_6.txt");
    delete grafo_1000_6_lista;
    delete grafo_1000_6_matriz;
    GrafoLista *grafo_1000_7_lista = modulo.lerGrafoNaoPonderadoLista("C:/Users/JV/Desktop/Arquivos entrada grafos/instancias Grafos não ponderados/grafo_1000_7.txt");
    GrafoMatriz *grafo_1000_7_matriz = modulo.lerGrafoNaoPonderadoMatriz("C:/Users/JV/Desktop/Arquivos entrada grafos/instancias Grafos não ponderados/grafo_1000_7.txt");
    delete grafo_1000_7_lista;
    delete grafo_1000_7_matriz;
    GrafoLista *grafo_1000_8_lista = modulo.lerGrafoNaoPonderadoLista("C:/Users/JV/Desktop/Arquivos entrada grafos/instancias Grafos não ponderados/grafo_1000_8.txt");
    GrafoMatriz *grafo_1000_8_matriz = modulo.lerGrafoNaoPonderadoMatriz("C:/Users/JV/Desktop/Arquivos entrada grafos/instancias Grafos não ponderados/grafo_1000_8.txt");
    delete grafo_1000_8_lista;
    delete grafo_1000_8_matriz;
    GrafoLista *grafo_10000_1_lista = modulo.lerGrafoNaoPonderadoLista("C:/Users/JV/Desktop/Arquivos entrada grafos/instancias Grafos não ponderados/grafo_10000_1.txt");
    GrafoMatriz *grafo_10000_1_matriz = modulo.lerGrafoNaoPonderadoMatriz("C:/Users/JV/Desktop/Arquivos entrada grafos/instancias Grafos não ponderados/grafo_10000_1.txt");
    delete grafo_10000_1_lista;
    delete grafo_10000_1_matriz;
    GrafoLista *grafo_10000_2_lista = modulo.lerGrafoNaoPonderadoLista("C:/Users/JV/Desktop/Arquivos entrada grafos/instancias Grafos não ponderados/grafo_10000_2.txt");
    GrafoMatriz *grafo_10000_2_matriz = modulo.lerGrafoNaoPonderadoMatriz("C:/Users/JV/Desktop/Arquivos entrada grafos/instancias Grafos não ponderados/grafo_10000_2.txt");
    delete grafo_10000_2_lista;
    delete grafo_10000_2_matriz;
    GrafoLista *grafo_10000_3_lista = modulo.lerGrafoNaoPonderadoLista("C:/Users/JV/Desktop/Arquivos entrada grafos/instancias Grafos não ponderados/grafo_10000_3.txt");
    GrafoMatriz *grafo_10000_3_matriz = modulo.lerGrafoNaoPonderadoMatriz("C:/Users/JV/Desktop/Arquivos entrada grafos/instancias Grafos não ponderados/grafo_10000_3.txt");
    delete grafo_10000_3_lista;
    delete grafo_10000_3_matriz;
    GrafoLista *grafo_10000_4_lista = modulo.lerGrafoNaoPonderadoLista("C:/Users/JV/Desktop/Arquivos entrada grafos/instancias Grafos não ponderados/grafo_10000_4.txt");
    GrafoMatriz *grafo_10000_4_matriz = modulo.lerGrafoNaoPonderadoMatriz("C:/Users/JV/Desktop/Arquivos entrada grafos/instancias Grafos não ponderados/grafo_10000_4.txt");
    delete grafo_10000_4_lista;
    delete grafo_10000_4_matriz;
    GrafoLista *grafo_10000_5_lista = modulo.lerGrafoNaoPonderadoLista("C:/Users/JV/Desktop/Arquivos entrada grafos/instancias Grafos não ponderados/grafo_10000_5.txt");
    GrafoMatriz *grafo_10000_5_matriz = modulo.lerGrafoNaoPonderadoMatriz("C:/Users/JV/Desktop/Arquivos entrada grafos/instancias Grafos não ponderados/grafo_10000_5.txt");
    delete grafo_10000_5_lista;
    delete grafo_10000_5_matriz;
    GrafoLista *grafo_10000_6_lista = modulo.lerGrafoNaoPonderadoLista("C:/Users/JV/Desktop/Arquivos entrada grafos/instancias Grafos não ponderados/grafo_10000_6.txt");
    GrafoMatriz *grafo_10000_6_matriz = modulo.lerGrafoNaoPonderadoMatriz("C:/Users/JV/Desktop/Arquivos entrada grafos/instancias Grafos não ponderados/grafo_10000_6.txt");
    delete grafo_10000_6_lista;
    delete grafo_10000_6_matriz;
    GrafoLista *grafo_10000_7_lista = modulo.lerGrafoNaoPonderadoLista("C:/Users/JV/Desktop/Arquivos entrada grafos/instancias Grafos não ponderados/grafo_10000_7.txt");
    GrafoMatriz *grafo_10000_7_matriz = modulo.lerGrafoNaoPonderadoMatriz("C:/Users/JV/Desktop/Arquivos entrada grafos/instancias Grafos não ponderados/grafo_10000_7.txt");
    delete grafo_10000_7_lista;
    delete grafo_10000_7_matriz;
    GrafoLista *grafo_10000_8_lista = modulo.lerGrafoNaoPonderadoLista("C:/Users/JV/Desktop/Arquivos entrada grafos/instancias Grafos não ponderados/grafo_10000_8.txt");
    GrafoMatriz *grafo_10000_8_matriz = modulo.lerGrafoNaoPonderadoMatriz("C:/Users/JV/Desktop/Arquivos entrada grafos/instancias Grafos não ponderados/grafo_10000_8.txt");
    delete grafo_10000_8_lista;
    delete grafo_10000_8_matriz;
    GrafoLista *grafo_125_lista = modulo.lerGrafoPonderadoLista("C:/Users/JV/Desktop/Arquivos entrada grafos/Instâncias Grafos Ponderados/grafo_125.txt");
    GrafoMatriz *grafo_125_matriz = modulo.lerGrafoPonderadoMatriz("C:/Users/JV/Desktop/Arquivos entrada grafos/Instâncias Grafos Ponderados/grafo_125.txt");
    delete grafo_125_lista;
    delete grafo_125_matriz;
    GrafoLista *grafo_209_lista = modulo.lerGrafoPonderadoLista("C:/Users/JV/Desktop/Arquivos entrada grafos/Instâncias Grafos Ponderados/grafo_209.txt");
    GrafoMatriz *grafo_209_matriz = modulo.lerGrafoPonderadoMatriz("C:/Users/JV/Desktop/Arquivos entrada grafos/Instâncias Grafos Ponderados/grafo_209.txt");
    delete grafo_209_lista;
    delete grafo_209_matriz;
    GrafoLista *grafo_235_lista = modulo.lerGrafoPonderadoLista("C:/Users/JV/Desktop/Arquivos entrada grafos/Instâncias Grafos Ponderados/grafo_235.txt");
    GrafoMatriz *grafo_235_matriz = modulo.lerGrafoPonderadoMatriz("C:/Users/JV/Desktop/Arquivos entrada grafos/Instâncias Grafos Ponderados/grafo_235.txt");
    delete grafo_235_lista;
    delete grafo_235_matriz;
    GrafoLista *grafo_526_lista = modulo.lerGrafoPonderadoLista("C:/Users/JV/Desktop/Arquivos entrada grafos/Instâncias Grafos Ponderados/grafo_526.txt");
    GrafoMatriz *grafo_526_matriz = modulo.lerGrafoPonderadoMatriz("C:/Users/JV/Desktop/Arquivos entrada grafos/Instâncias Grafos Ponderados/grafo_526.txt");
    delete grafo_526_lista;
    delete grafo_526_matriz;
    GrafoLista *grafo_585_lista = modulo.lerGrafoPonderadoLista("C:/Users/JV/Desktop/Arquivos entrada grafos/Instâncias Grafos Ponderados/grafo_585.txt");
    GrafoMatriz *grafo_585_matriz = modulo.lerGrafoPonderadoMatriz("C:/Users/JV/Desktop/Arquivos entrada grafos/Instâncias Grafos Ponderados/grafo_585.txt");
    delete grafo_585_lista;
    delete grafo_585_matriz;
    GrafoLista *grafo_609_lista = modulo.lerGrafoPonderadoLista("C:/Users/JV/Desktop/Arquivos entrada grafos/Instâncias Grafos Ponderados/grafo_609.txt");
    GrafoMatriz *grafo_609_matriz = modulo.lerGrafoPonderadoMatriz("C:/Users/JV/Desktop/Arquivos entrada grafos/Instâncias Grafos Ponderados/grafo_609.txt");
    delete grafo_609_lista;
    delete grafo_609_matriz;
    GrafoLista *grafo_643_lista = modulo.lerGrafoPonderadoLista("C:/Users/JV/Desktop/Arquivos entrada grafos/Instâncias Grafos Ponderados/grafo_643.txt");
    GrafoMatriz *grafo_643_matriz = modulo.lerGrafoPonderadoMatriz("C:/Users/JV/Desktop/Arquivos entrada grafos/Instâncias Grafos Ponderados/grafo_643.txt");
    delete grafo_643_lista;
    delete grafo_643_matriz;
    GrafoLista *grafo_658_lista = modulo.lerGrafoPonderadoLista("C:/Users/JV/Desktop/Arquivos entrada grafos/Instâncias Grafos Ponderados/grafo_658.txt");
    GrafoMatriz *grafo_658_matriz = modulo.lerGrafoPonderadoMatriz("C:/Users/JV/Desktop/Arquivos entrada grafos/Instâncias Grafos Ponderados/grafo_658.txt");
    delete grafo_658_lista;
    delete grafo_658_matriz;
    GrafoLista *grafo_1000_lista = modulo.lerGrafoPonderadoLista("C:/Users/JV/Desktop/Arquivos entrada grafos/Instâncias Grafos Ponderados/grafo_1000.txt");
    GrafoMatriz *grafo_1000_matriz = modulo.lerGrafoPonderadoMatriz("C:/Users/JV/Desktop/Arquivos entrada grafos/Instâncias Grafos Ponderados/grafo_1000.txt");
    delete grafo_1000_lista;
    delete grafo_1000_matriz;
    GrafoLista *grafo_1317_lista = modulo.lerGrafoPonderadoLista("C:/Users/JV/Desktop/Arquivos entrada grafos/Instâncias Grafos Ponderados/grafo_1317.txt");
    GrafoMatriz *grafo_1317_matriz = modulo.lerGrafoPonderadoMatriz("C:/Users/JV/Desktop/Arquivos entrada grafos/Instâncias Grafos Ponderados/grafo_1317.txt");
    delete grafo_1317_lista;
    delete grafo_1317_matriz;
    GrafoLista *grafo_1619_lista = modulo.lerGrafoPonderadoLista("C:/Users/JV/Desktop/Arquivos entrada grafos/Instâncias Grafos Ponderados/grafo_1619.txt");
    GrafoMatriz *grafo_1619_matriz = modulo.lerGrafoPonderadoMatriz("C:/Users/JV/Desktop/Arquivos entrada grafos/Instâncias Grafos Ponderados/grafo_1619.txt");
    delete grafo_1619_lista;
    delete grafo_1619_matriz;
    GrafoLista *grafo_1807_lista = modulo.lerGrafoPonderadoLista("C:/Users/JV/Desktop/Arquivos entrada grafos/Instâncias Grafos Ponderados/grafo_1807.txt");
    GrafoMatriz *grafo_1807_matriz = modulo.lerGrafoPonderadoMatriz("C:/Users/JV/Desktop/Arquivos entrada grafos/Instâncias Grafos Ponderados/grafo_1807.txt");
    delete grafo_1807_lista;
    delete grafo_1807_matriz;
    GrafoLista *grafo_2203_lista = modulo.lerGrafoPonderadoLista("C:/Users/JV/Desktop/Arquivos entrada grafos/Instâncias Grafos Ponderados/grafo_2203.txt");
    GrafoMatriz *grafo_2203_matriz = modulo.lerGrafoPonderadoMatriz("C:/Users/JV/Desktop/Arquivos entrada grafos/Instâncias Grafos Ponderados/grafo_2203.txt");
    delete grafo_2203_lista;
    delete grafo_2203_matriz;
    GrafoLista *grafo_2430_lista = modulo.lerGrafoPonderadoLista("C:/Users/JV/Desktop/Arquivos entrada grafos/Instâncias Grafos Ponderados/grafo_2430.txt");
    GrafoMatriz *grafo_2430_matriz = modulo.lerGrafoPonderadoMatriz("C:/Users/JV/Desktop/Arquivos entrada grafos/Instâncias Grafos Ponderados/grafo_2430.txt");
    delete grafo_2430_lista;
    delete grafo_2430_matriz;
    GrafoLista *grafo_2769_lista = modulo.lerGrafoPonderadoLista("C:/Users/JV/Desktop/Arquivos entrada grafos/Instâncias Grafos Ponderados/grafo_2769.txt");
    GrafoMatriz *grafo_2769_matriz = modulo.lerGrafoPonderadoMatriz("C:/Users/JV/Desktop/Arquivos entrada grafos/Instâncias Grafos Ponderados/grafo_2769.txt");
    delete grafo_2769_lista;
    delete grafo_2769_matriz;
    GrafoLista *grafo_3204_lista = modulo.lerGrafoPonderadoLista("C:/Users/JV/Desktop/Arquivos entrada grafos/Instâncias Grafos Ponderados/grafo_3204.txt");
    GrafoMatriz *grafo_3204_matriz = modulo.lerGrafoPonderadoMatriz("C:/Users/JV/Desktop/Arquivos entrada grafos/Instâncias Grafos Ponderados/grafo_3204.txt");
    delete grafo_3204_lista;
    delete grafo_3204_matriz;
    GrafoLista *grafo_3596_lista = modulo.lerGrafoPonderadoLista("C:/Users/JV/Desktop/Arquivos entrada grafos/Instâncias Grafos Ponderados/grafo_3596.txt");
    GrafoMatriz *grafo_3596_matriz = modulo.lerGrafoPonderadoMatriz("C:/Users/JV/Desktop/Arquivos entrada grafos/Instâncias Grafos Ponderados/grafo_3596.txt");
    delete grafo_3596_lista;
    delete grafo_3596_matriz;
    GrafoLista *grafo_3777_lista = modulo.lerGrafoPonderadoLista("C:/Users/JV/Desktop/Arquivos entrada grafos/Instâncias Grafos Ponderados/grafo_3777.txt");
    GrafoMatriz *grafo_3777_matriz = modulo.lerGrafoPonderadoMatriz("C:/Users/JV/Desktop/Arquivos entrada grafos/Instâncias Grafos Ponderados/grafo_3777.txt");
    delete grafo_3777_lista;
    delete grafo_3777_matriz;
    GrafoLista *grafo_3915_lista = modulo.lerGrafoPonderadoLista("C:/Users/JV/Desktop/Arquivos entrada grafos/Instâncias Grafos Ponderados/grafo_3915.txt");
    GrafoMatriz *grafo_3915_matriz = modulo.lerGrafoPonderadoMatriz("C:/Users/JV/Desktop/Arquivos entrada grafos/Instâncias Grafos Ponderados/grafo_3915.txt");
    delete grafo_3915_lista;
    delete grafo_3915_matriz;
    GrafoLista *grafo_4163_lista = modulo.lerGrafoPonderadoLista("C:/Users/JV/Desktop/Arquivos entrada grafos/Instâncias Grafos Ponderados/grafo_4163.txt");
    GrafoMatriz *grafo_4163_matriz = modulo.lerGrafoPonderadoMatriz("C:/Users/JV/Desktop/Arquivos entrada grafos/Instâncias Grafos Ponderados/grafo_4163.txt");
    delete grafo_4163_lista;
    delete grafo_4163_matriz;
    GrafoLista *grafo_4574_lista = modulo.lerGrafoPonderadoLista("C:/Users/JV/Desktop/Arquivos entrada grafos/Instâncias Grafos Ponderados/grafo_4574.txt");
    GrafoMatriz *grafo_4574_matriz = modulo.lerGrafoPonderadoMatriz("C:/Users/JV/Desktop/Arquivos entrada grafos/Instâncias Grafos Ponderados/grafo_4574.txt");
    delete grafo_4574_lista;
    delete grafo_4574_matriz;
    GrafoLista *grafo_5011_lista = modulo.lerGrafoPonderadoLista("C:/Users/JV/Desktop/Arquivos entrada grafos/Instâncias Grafos Ponderados/grafo_5011.txt");
    GrafoMatriz *grafo_5011_matriz = modulo.lerGrafoPonderadoMatriz("C:/Users/JV/Desktop/Arquivos entrada grafos/Instâncias Grafos Ponderados/grafo_5011.txt");
    delete grafo_5011_lista;
    delete grafo_5011_matriz;
    GrafoLista *grafo_5273_lista = modulo.lerGrafoPonderadoLista("C:/Users/JV/Desktop/Arquivos entrada grafos/Instâncias Grafos Ponderados/grafo_5273.txt");
    GrafoMatriz *grafo_5273_matriz = modulo.lerGrafoPonderadoMatriz("C:/Users/JV/Desktop/Arquivos entrada grafos/Instâncias Grafos Ponderados/grafo_5273.txt");
    delete grafo_5273_lista;
    delete grafo_5273_matriz;
    GrafoLista *grafo_5531_lista = modulo.lerGrafoPonderadoLista("C:/Users/JV/Desktop/Arquivos entrada grafos/Instâncias Grafos Ponderados/grafo_5531.txt");
    GrafoMatriz *grafo_5531_matriz = modulo.lerGrafoPonderadoMatriz("C:/Users/JV/Desktop/Arquivos entrada grafos/Instâncias Grafos Ponderados/grafo_5531.txt");
    delete grafo_5531_lista;
    delete grafo_5531_matriz;
    GrafoLista *grafo_6146_lista = modulo.lerGrafoPonderadoLista("C:/Users/JV/Desktop/Arquivos entrada grafos/Instâncias Grafos Ponderados/grafo_6146.txt");
    GrafoMatriz *grafo_6146_matriz = modulo.lerGrafoPonderadoMatriz("C:/Users/JV/Desktop/Arquivos entrada grafos/Instâncias Grafos Ponderados/grafo_6146.txt");
    delete grafo_6146_lista;
    delete grafo_6146_matriz;
    GrafoLista *grafo_6767_lista = modulo.lerGrafoPonderadoLista("C:/Users/JV/Desktop/Arquivos entrada grafos/Instâncias Grafos Ponderados/grafo_6767.txt");
    GrafoMatriz *grafo_6767_matriz = modulo.lerGrafoPonderadoMatriz("C:/Users/JV/Desktop/Arquivos entrada grafos/Instâncias Grafos Ponderados/grafo_6767.txt");
    delete grafo_6767_lista;
    delete grafo_6767_matriz;
    GrafoLista *grafo_7130_lista = modulo.lerGrafoPonderadoLista("C:/Users/JV/Desktop/Arquivos entrada grafos/Instâncias Grafos Ponderados/grafo_7130.txt");
    GrafoMatriz *grafo_7130_matriz = modulo.lerGrafoPonderadoMatriz("C:/Users/JV/Desktop/Arquivos entrada grafos/Instâncias Grafos Ponderados/grafo_7130.txt");
    delete grafo_7130_lista;
    delete grafo_7130_matriz;
    GrafoLista *grafo_7576_lista = modulo.lerGrafoPonderadoLista("C:/Users/JV/Desktop/Arquivos entrada grafos/Instâncias Grafos Ponderados/grafo_7576.txt");
    GrafoMatriz *grafo_7576_matriz = modulo.lerGrafoPonderadoMatriz("C:/Users/JV/Desktop/Arquivos entrada grafos/Instâncias Grafos Ponderados/grafo_7576.txt");
    delete grafo_7576_lista;
    delete grafo_7576_matriz;
    GrafoLista *grafo_8385_lista = modulo.lerGrafoPonderadoLista("C:/Users/JV/Desktop/Arquivos entrada grafos/Instâncias Grafos Ponderados/grafo_8385.txt");
    GrafoMatriz *grafo_8385_matriz = modulo.lerGrafoPonderadoMatriz("C:/Users/JV/Desktop/Arquivos entrada grafos/Instâncias Grafos Ponderados/grafo_8385.txt");
    delete grafo_8385_lista;
    delete grafo_8385_matriz;
    GrafoLista *grafo_8601_lista = modulo.lerGrafoPonderadoLista("C:/Users/JV/Desktop/Arquivos entrada grafos/Instâncias Grafos Ponderados/grafo_8601.txt");
    GrafoMatriz *grafo_8601_matriz = modulo.lerGrafoPonderadoMatriz("C:/Users/JV/Desktop/Arquivos entrada grafos/Instâncias Grafos Ponderados/grafo_8601.txt");
    delete grafo_8601_lista;
    delete grafo_8601_matriz;
    GrafoLista *grafo_8832_lista = modulo.lerGrafoPonderadoLista("C:/Users/JV/Desktop/Arquivos entrada grafos/Instâncias Grafos Ponderados/grafo_8832.txt");
    GrafoMatriz *grafo_8832_matriz = modulo.lerGrafoPonderadoMatriz("C:/Users/JV/Desktop/Arquivos entrada grafos/Instâncias Grafos Ponderados/grafo_8832.txt");
    delete grafo_8832_lista;
    delete grafo_8832_matriz;
    GrafoLista *grafo_9199_lista = modulo.lerGrafoPonderadoLista("C:/Users/JV/Desktop/Arquivos entrada grafos/Instâncias Grafos Ponderados/grafo_9199.txt");
    GrafoMatriz *grafo_9199_matriz = modulo.lerGrafoPonderadoMatriz("C:/Users/JV/Desktop/Arquivos entrada grafos/Instâncias Grafos Ponderados/grafo_9199.txt");
    delete grafo_9199_lista;
    delete grafo_9199_matriz;
    GrafoLista *grafo_9431_lista = modulo.lerGrafoPonderadoLista("C:/Users/JV/Desktop/Arquivos entrada grafos/Instâncias Grafos Ponderados/grafo_9431.txt");
    GrafoMatriz *grafo_9431_matriz = modulo.lerGrafoPonderadoMatriz("C:/Users/JV/Desktop/Arquivos entrada grafos/Instâncias Grafos Ponderados/grafo_9431.txt");
    delete grafo_9431_lista;
    delete grafo_9431_matriz;
    GrafoLista *grafo_9815_lista = modulo.lerGrafoPonderadoLista("C:/Users/JV/Desktop/Arquivos entrada grafos/Instâncias Grafos Ponderados/grafo_9815.txt");
    GrafoMatriz *grafo_9815_matriz = modulo.lerGrafoPonderadoMatriz("C:/Users/JV/Desktop/Arquivos entrada grafos/Instâncias Grafos Ponderados/grafo_9815.txt");
    delete grafo_9815_lista;
    delete grafo_9815_matriz;
}
