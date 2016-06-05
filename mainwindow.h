#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "basewindow.h"
#include "facade.h"

namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow, public BaseWindow
{
    Q_OBJECT

public:
    Facade *facade;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void display() override;

private:
    Ui::MainWindow *ui;
    void keyPressEvent(QKeyEvent *) override;

private slots:
    void on_buttonUploadCamera_clicked();
    void on_buttonUploadModel_clicked();
    void on_buttonQuit_clicked();

};

#endif // MAINWINDOW_H
