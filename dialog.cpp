#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_valTamPaginas_valueChanged(int arg1)
{
    tamPaginas = ui->valTamPaginas->value();
    quantPaginas = ui->valQuantPaginas->value();
    tamMemoriaFisica = tamPaginas*quantPaginas;
    tamMemoriaFisicaStr = QString::number(tamMemoriaFisica);
    ui->valTamMemoriaFisica->setText(tamMemoriaFisicaStr);
}

void Dialog::on_valQuantPaginas_valueChanged(int arg1)
{
    tamPaginas = ui->valTamPaginas->value();
    quantPaginas = ui->valQuantPaginas->value();
    tamMemoriaFisica = tamPaginas*quantPaginas;
    tamMemoriaFisicaStr = QString::number(tamMemoriaFisica);
    ui->valTamMemoriaFisica->setText(tamMemoriaFisicaStr);
}
int Dialog::getTamPaginas() const
{
    return tamPaginas;
}

int Dialog::getTamMemoriaFisica() const
{
    return tamMemoriaFisica;
}

int Dialog::getQuantPaginas() const
{
    return quantPaginas;
}
