#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "memoriafisica.h"

namespace Ui {
class MainWindow;
}

/**
 * \class MainWindow
 * \brief Classe que tem interação com a segunda tela da interface grafica
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    /**
     * Construtor padrão da classe
     * @param parent
     */
    explicit MainWindow(QWidget *parent = 0);

    /**
      * Destrutor padrão
      */
    ~MainWindow();

    /**
     * Abre a primeira tela do sistema, que configura o sistema
     */
    void AbrirDialog();

    /**
     * Plota o grafico da cluster do HD
     */
    void Plotar();

private slots:
    /**
     * Função chamada ao clicar no botão Salvar
     */
    void on_salvar_clicked();

    /**
     * Função chamada ao clicar no botão Excluir
     */
    void on_excluir_clicked();

    /**
     * Função chamada ao clicar no botão Listar
     */
    void on_listar_clicked();

    /**
     * Função chamada ao clicar no botão Formatar
     */
    void on_formatar_clicked();

    /**
     * Função chamada ao clicar no botão Buscar
     */
    void on_buscar_clicked();

private:
    Ui::MainWindow *ui; /**< variáve que tem ligação com a interface gráfica */
    Disco *memoriaFisica; /**< variável que simula a memoria */
    QString numero; /**< Guarda o valor que está no campo 'numero' que o usuario digita */
    QString valor; /**< Guarda o valor que está no campo 'valor' que o usuario digita */
};

#endif // MAINWINDOW_H
