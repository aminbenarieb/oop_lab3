#ifndef CONCRETEIOSTREAMSERVICE_H
#define CONCRETEIOSTREAMSERVICE_H

#include <QFileDialog>
#include <QMessageBox>

#include "iostreamservice.h"

class AlertWindowService : public QDialog, public IOStreamService
{
    Q_OBJECT

private:
    QString fileName;

public:
    AlertWindowService();

    void showErrorMessage(const char*);
    void showInfoMessage(const char*);

    std::string getFileName() = 0;
};


#endif // CONCRETEIOSTREAMSERVICE_H
