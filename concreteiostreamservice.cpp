#include "concreteiostreamservice.h"


//MARK: Implementor

QAlertWindowServiceImp::QAlertWindowServiceImp()
{

}

QAlertWindowServiceImp::~QAlertWindowServiceImp()
{

}

void QAlertWindowServiceImp::showErrorMessage(const char* text)
{
    QMessageBox::warning(this,"Unexpecter error occured", QString(text), QMessageBox::Ok);
}

void QAlertWindowServiceImp::showInfoMessage(const char *text)
{
       QMessageBox alertWindow;
       alertWindow.setText(text);
       alertWindow.exec();
}

std::string QAlertWindowServiceImp::selectFile()
{
    fileName = QFileDialog::getOpenFileName(0, "Upload file", "", "*.txt");

    return fileName.toStdString();
}

bool QAlertWindowServiceImp::saveFileWithName(const char*)
{

    return false;
}

//MARK: Refined Class

QAlertWindowService::QAlertWindowService(IOStreamServiceImp *imp){

    this->imp = imp;

}

QAlertWindowService::~QAlertWindowService()
{
    this->imp = nullptr;
}

void QAlertWindowService::showErrorMessage(const char* text)
{
    this->imp->showErrorMessage(text);
}

void QAlertWindowService::showInfoMessage(const char *text)
{
       this->imp->showInfoMessage(text);
}

std::string QAlertWindowService::selectFile()
{
    return this->imp->selectFile();
}

bool QAlertWindowService::saveFileWithName(const char* fileName)
{
    return imp->saveFileWithName(fileName);
}
