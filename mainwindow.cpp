#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include <iostream>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    AbrirDialog();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete memoriaFisica;
}

void MainWindow::AbrirDialog()
{
    Dialog dialog;
    dialog.exec();
    memoriaFisica = new memoriaFisica(dialog.getQuantPaginas(), dialog.getTamPaginas(), dialog.getTamMemoriaFisica());
    Plotar();
}

void MainWindow::Plotar()
{

    QString grafico;
    grafico.push_back("<style type='text/css'>");
    grafico.push_back(".celula{border-collapse:collapse;border-color:#3366FF;}.celula th{font-family:Arial, sans-serif;font-weight:normal;padding:10px 10px;border-style:solid;border-width:1px;border-color:#3366FF;background-color:#f0f0f0;}");
    grafico.push_back("</style>");
    grafico.push_back("<table class='celula'>");

    int cont = 0;
    for(int i = 0; i < memoriaFisica->getNumPaginas(); i++){
        grafico.push_back("<tr>");
        for(int j = 0; j < memoriaFisica->getTamPaginas(); j++){
            grafico.push_back("<th>");
            grafico.push_back(memoriaFisica->getMemoria(cont));
            grafico.push_back("</th>");
            cont++;
        }
        grafico.push_back("</tr>");
    }

    grafico.push_back("</table>");
    ui->grafico->setText(grafico);
}

void MainWindow::on_salvar_clicked()
{
   numero = ui->CampoNumero->text();
   valor = ui->CampoValor->text();

   QByteArray aux;
   aux = valor.toLatin1();
   const char *strValor = aux.data();

   if(memoriaFisica->Salvar(strValor, valor.size(), numero.toStdString())){
        Plotar();
   }
}

void MainWindow::on_excluir_clicked()
{
   numero = ui->Camponumero->text();

   if(memoriaFisica->Excluir(numero.toStdString())){
       Plotar();
   }else{
       //Se não tiver o que excluir, mandar uma mensagem
   }
}

void MainWindow::on_listar_clicked()
{
    ui->lista->setText(memoriaFisica->Listar());
}

void MainWindow::on_formatar_clicked()
{
    if(memoriaFisica->Formatar()){
        Plotar();
    }
}

void MainWindow::on_buscar_clicked()
{
    numero = ui->Camponumero->text();
    ui->lista->setText(memoriaFisica->Buscar(numero.toStdString()));
}
