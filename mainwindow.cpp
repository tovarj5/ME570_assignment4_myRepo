#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionAbout_triggered()
{
    QMessageBox *msgbox = new QMessageBox;

    QString message{"Assignment - 4 - FunWithShape\nCreated by: Jacob Tovar\nOtherMessagesHere..."};
    //(*msgbox).text() = message;
    msgbox->setText(message);
    (*msgbox).show();
}

void MainWindow::on_actionOpen_triggered()
{
    QFileDialog *browse = new QFileDialog;

}

void MainWindow::on_actionSave_triggered()
{

}

void MainWindow::on_actionSave_As_triggered()
{

}

void MainWindow::on_actionExit_triggered()
{

}
