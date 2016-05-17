#include "paginas.h"

paginas::paginas(int id){
    this->id = id;
}

paginas::paginas(int id, int inicio, int fim){
    this->inicio = inicio;
    this->fim = fim;
    this->id = id;
}

paginas::~paginas()
{

}

int paginas::getInicio()
{
    return inicio;
}

int paginas::getFim()
{
    return fim;
}

int paginas::getId()
{
    return id;
}
