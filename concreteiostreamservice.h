#ifndef CONCRETEIOSTREAMSERVICE_H
#define CONCRETEIOSTREAMSERVICE_H

#include <QFileDialog>
#include <QMessageBox>

#include "iostreamservice.h"

class QAlertWindowServiceImp :  public QDialog, public IOStreamServiceImp
{
    Q_OBJECT

private:
    QString fileName;

public:
    QAlertWindowServiceImp();
    ~QAlertWindowServiceImp();

    void showErrorMessage(const char*);
    void showInfoMessage(const char*);

    std::string selectFile();
    bool saveFileWithName(const char*);
};

class QAlertWindowService :  public IOStreamService
{

public:
    QAlertWindowService(IOStreamServiceImp *);
    ~QAlertWindowService();

    void showErrorMessage(const char*);
    void showInfoMessage(const char*);

    bool saveFileWithName(const char*);

    std::string selectFile();
};


#endif // CONCRETEIOSTREAMSERVICE_H
