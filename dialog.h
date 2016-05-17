#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
    class Dialog;
}

/**
 * \class Dialog
 * \brief Classe da primeira tela da sistema. Pega os valores da usuário para realmente iniciar o sistema
 */
class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

    /**
     * Retorna a quantidade de paginas
     * @return retorna a quantidade de paginas
     */
    int getQuantPaginas() const;

    /**
     * Retorna o tamanho da MemoriaFisica
     * @return retorna o tamanho da MemoriaFisica
     */
    int getTamMemoriaFisica() const;

    /**
     * Retorna o tamanho da pagina
     * @return retorna o tamanho da pagina
     */
    int getTamPaginas() const;

private slots:
    /**
     * Altera a interface quanda o usuario muda tamanho da pagina
     * @param arg1 valor alterada pelo usuario
     */
    void on_valTamPaginas_valueChanged(int arg1);

    /**
     * Altera a interface quanda o usuario muda a quantidade de paginas
     * @param arg1 valor alterada pelo usuario
     */
    void on_valQuantPaginas_valueChanged(int arg1);

private:

    Ui::Dialog *ui; /**< Variável que cuida da interação com a interface */
    int tamPaginas = 0; /**< Guarda o tamanho da setor */
    int quantPaginas = 0; /**< Guarda a quantidade de setores */
    int tamMemoriaFisica = 0; /**< Guarda o tamanho da MemoriaFisica */
    QString tamMemoriaFisicaStr; /**< Guarda o valor da tamanho da MemoriaFisica em QString  */
};

#endif // DIALOG_H
