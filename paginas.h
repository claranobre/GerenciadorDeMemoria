#ifndef PAGINAS_H
#define PAGINAS_H

#include "lista.h"

/**
 * \class Paginas
 * \brief Classe que simula as Paginas da Memoria
 */
class Paginas
{
private:
    int id; /**< id da Pagina */
    int inicio;/**< inicio da Pagina */
    int fim; /**< fim da Pagina */

public:
    /**
     * Construtor
     * @param id
     */
    Paginas(int id);

    /**
     * Sobrecarda de construtor
     * @param id
     * @param inicio
     * @param fim
     */
    Paginas(int id, int inicio, int fim);

    /**
     * Destrutor padrão
     */
    ~Paginas();

    /**
     * Retorna o valor do inicio
     * @return inicio
     */
    int getInicio();

    /**
     * Retorna o valor do fim
     * @return fim
     */
    int getFim();

    /**
     * Retorna o valor de id
     * @return id
     */
    int getId();
};

#endif // Paginas_H
