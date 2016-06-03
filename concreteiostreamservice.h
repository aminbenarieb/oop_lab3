#ifndef CONCRETEIOSTREAMSERVICE_H
#define CONCRETEIOSTREAMSERVICE_H

#include <QFileDialog>
#include <QMessageBox>

#include "iostreamservice.h"

class AlertWindowServiceImp :  public QDialog, public IOStreamServiceImp
{
    Q_OBJECT

private:
    QString fileName;

public:
    AlertWindowServiceImp();
    ~AlertWindowServiceImp();

    void showErrorMessage(const char*);
    void showInfoMessage(const char*);

    std::string selectFile();
    bool saveFileWithName(const char*);
};

class AlertWindowService :  public IOStreamService
{

public:
    AlertWindowService(IOStreamServiceImp *);
    ~AlertWindowService();

    void showErrorMessage(const char*);
    void showInfoMessage(const char*);

    bool saveFileWithName(const char*);

    std::string selectFile();
};


#endif // CONCRETEIOSTREAMSERVICE_H
