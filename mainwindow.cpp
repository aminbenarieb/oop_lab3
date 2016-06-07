#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QKeyEvent>
#include <QApplication>

#define TRANSFORM_DELTA 1.0

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
    delete facade;
    delete ui;
}

void MainWindow::display(){

    this->show();
}


void MainWindow::keyPressEvent(QKeyEvent *event)
{

    switch(event->key())
    {
    case Qt::Key_W:
        facade->transformModel({TRANSFORM_ROTATE_X, TRANSFORM_DELTA});
        break;
    case Qt::Key_S:
        facade->transformModel({TRANSFORM_ROTATE_X, -TRANSFORM_DELTA});
        break;
    case Qt::Key_A:
        facade->transformModel({TRANSFORM_ROTATE_Y, TRANSFORM_DELTA});
        break;
    case Qt::Key_D:
        facade->transformModel({TRANSFORM_ROTATE_Y, -TRANSFORM_DELTA});
        break;
    case Qt::Key_Q:
        facade->transformModel({TRANSFORM_ROTATE_Z, TRANSFORM_DELTA});
        break;
    case Qt::Key_E:
        facade->transformModel({TRANSFORM_ROTATE_Z, -TRANSFORM_DELTA});
        break;

    case Qt::Key_I:
        facade->transformCamera({TRANSFORM_ROTATE_X, TRANSFORM_DELTA});
        break;
    case Qt::Key_K:
        facade->transformCamera({TRANSFORM_ROTATE_X, -TRANSFORM_DELTA});
        break;
    case Qt::Key_J:
        facade->transformCamera({TRANSFORM_ROTATE_Y, TRANSFORM_DELTA});
        break;
    case Qt::Key_L:
        facade->transformCamera({TRANSFORM_ROTATE_Y, -TRANSFORM_DELTA});
        break;
    case Qt::Key_U:
        facade->transformCamera({TRANSFORM_ROTATE_Z, TRANSFORM_DELTA});
        break;
    case Qt::Key_O:
        facade->transformCamera({TRANSFORM_ROTATE_Z, -TRANSFORM_DELTA});
        break;


    case Qt::Key_Z:
        facade->transformModel({TRANSFORM_SCALE, 2*TRANSFORM_DELTA});
        break;
    case Qt::Key_X:
        facade->transformModel({TRANSFORM_SCALE, (TRANSFORM_DELTA/2)});
        break;

    case Qt::Key_N:
        facade->transformCamera({TRANSFORM_SCALE, 2*TRANSFORM_DELTA});
        break;
    case Qt::Key_M:
        facade->transformCamera({TRANSFORM_SCALE, (TRANSFORM_DELTA/2)});
        break;

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

void MainWindow::on_buttonClearScene_clicked()
{
    this->facade->clearScene();
}


void MainWindow::on_buttonQuit_clicked()
{
    this->facade->clearScene();
    QApplication::quit();
}
