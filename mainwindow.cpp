#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QKeyEvent>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->canvas->setScene(new QGraphicsScene);

    CanvasInfo canvasInfo = {ui->canvas->scene()};
    facade = new Facade(&canvasInfo);
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

void MainWindow::on_buttonDrawScene_clicked()
{
    this->facade->drawScene();
}


void MainWindow::on_buttonQuit_clicked()
{
    this->facade->clearScene();
    QApplication::quit();
}
