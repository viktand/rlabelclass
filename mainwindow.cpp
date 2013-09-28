#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "rlabel.h"

QrLabel *rLabel;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    rLabel=new QrLabel(ui->centralWidget);
    QImage im(":/new/prefix1/cat");
    rLabel->setPixmap(QPixmap::fromImage(im));
    QRect rc;
    rc.setX(100);
    rc.setY(70);
    rc.setWidth(im.width());
    rc.setHeight(im.height());
    rLabel->setGeometry(rc);
    rLabel->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_dial_valueChanged(int value)
{
    rLabel->rotor(value);
    ui->label->setText(QString::number(rLabel->getDegree()));
}

void MainWindow::on_pushButton_clicked()
{
    rLabel->setDegree(90);
}
