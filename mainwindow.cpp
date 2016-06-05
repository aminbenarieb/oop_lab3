#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QKeyEvent>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    facade(new Facade()),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::display(){

    this->show();
}


void MainWindow::keyPressEvent(QKeyEvent *event)
{

    switch(event->key())
    {
        case Qt::Key_Escape:
            this->close();
            break;
        default:
            QWidget::keyPressEvent(event);
    }
}


void MainWindow::on_buttonUploadModel_clicked()
{
    this->facade->uploadModelFromFile({SOURCE_FILE, NULL});
}

void MainWindow::on_buttonUploadCamera_clicked()
{
    this->facade->uploadCameraFromFile({SOURCE_FILE, NULL});
}

void MainWindow::on_buttonQuit_clicked()
{
    this->facade->clearScene();
    QApplication::quit();
}
