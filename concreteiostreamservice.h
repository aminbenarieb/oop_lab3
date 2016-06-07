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

    virtual void showErrorMessage(const char*) override;
    virtual void showInfoMessage(const char*) override;

    virtual std::string selectFile() override;
    virtual bool saveFileWithName(const char*) override;

};

class QAlertWindowService :  public IOStreamService
{

public:
    QAlertWindowService(IOStreamServiceImp *);
    ~QAlertWindowService();

    virtual void showErrorMessage(const char*) override;
    virtual void showInfoMessage(const char*) override;

    virtual bool saveFileWithName(const char*) override;

    virtual std::string selectFile() override;
};


#endif // CONCRETEIOSTREAMSERVICE_H
