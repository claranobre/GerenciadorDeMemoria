#include "memoriavirtual.h"
#include <iostream>
#include <stdlib.h>
#include<stdio.h>
#include <math.h>

memoriaVirtual::memoriaVirtual(int quantPaginas, int tamPaginas, int tamMemoria)
{
    this->numPaginas = quantPaginas;
    this->tamPaginas = tamPaginas;
    this->tamanho = tamMemoria;
    this->livre = quantPaginas;

    // Inicializando o pool no intervalo [0, quantPaginas]
    Pagina *novo = new Pagina(0, 0, quantPaginas);
    pool.Insert(0, novo);

    this->memoriaVirtual = new char[tamMemoria];
    InicializarArray(memoriaVirtual, tamMemoria);
}
memoriaVirtual::~memoriaVirtual()
{
    info.~Lista();
    pool.~Lista();
    delete memoriaVirtual;
}

int memoriaVirtual::Excluir(string nome)
{
    File *temp;
    for(int i = 0; i< info.Size(); i++){
        info.GetElem(i,temp);
        if(temp->getNome() == nome){

            int tamanho = temp->getTamanho();

            int paginasNecessarias = ceil ((float)tamanho/tamPaginas);

            for(int j = 0; j < paginasNecessarias; j++){
                for(int k = 0; k < tamPaginas; k++){
                    int pos = (temp->getCluster(j)*tamPaginas)+k;
                    memoriaVirtual[pos] = '0';
                }
            }
            info.Remove(i);
            livre += paginasNecessarias;
            AtualizarPool();
            return 1;
        }
    }
    return 0;
}
