#include "memoriafisica.h"

memoriaFisica::memoriaFisica()
{

}
//Inicializa um array com um valor
void memoriaFisica::InicializarArray(int array[], int tamanho, int valor)
{
    for(int i=0; i<tamanho; i++){
        array[i] = valor;
    }
}

//Inicializa um array com o valor 0
void memoriaFisica::InicializarArray(char array[], int tamanho)
{
    for(int i=0; i<tamanho; i++){
        array[i] = '0';
    }
}
//Retorna se tem espaço suficiente para colocar o dado
bool memoriaFisica::isFree(int tam){
    return livre>=tam;
}

int memoriaFisica::getNumPaginas()
{
    return numPaginas;
}

int memoriaFisica::getTamanho()
{
    return tamanho;
}

int memoriaFisica::getTamPaginas()
{
    return tamPaginas;
}

char memoriaFisica::getMem(int id)
{
    return memoria[id];
}

memoriaFisica::Buscar(string endereco)
{
    File *temp;
    for(int i = 0; i< info.Size(); i++){
        info.GetElem(i,temp);
        if(temp->getEndereco() == endereco){
            char tam[10];

            push_back(temp->getEndereco().c_str());
            itoa(temp->getTamanho(),tam,10); // pega o tamanho e jogar em 'tam'
            push_back(tam);

            int tamanho = temp->getTamanho();
            int PaginasNecessarias = ceil ((float)tamanho/tamPaginas);
            for(int j = 0; j<PaginasNecessarias; j++){
               itoa(temp->getCluster(j), tam, 10);
               if(j == 0)
                   html.push_back(tam);
               else{
                   push_back(", ");
                   push_back(tam);
               }
            }

            for(int j = 0; j < PaginasNecessarias; j++){
                for(int k = 0; k < tamPaginas; k++){
                    int pos = (temp->getCluster(j)*tamPaginas)+k;
                    push_back(memoria[pos]);
                }
            }
        }
    }
}
