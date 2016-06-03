#include "concreteiostreamservice.h"


//MARK: Implementor

AlertWindowServiceImp::AlertWindowServiceImp()
{

}

AlertWindowServiceImp::~AlertWindowServiceImp()
{

}

void AlertWindowServiceImp::showErrorMessage(const char* text)
{
    QMessageBox::warning(this,"Unexpecter error occured", QString(text), QMessageBox::Ok);
}

void AlertWindowServiceImp::showInfoMessage(const char *text)
{
       QMessageBox alertWindow;
       alertWindow.setText(text);
       alertWindow.exec();
}

std::string AlertWindowServiceImp::selectFile()
{
    fileName = QFileDialog::getOpenFileName(0, "Upload file", "", "*.txt");

    return fileName.toStdString();
}

bool AlertWindowServiceImp::saveFileWithName(const char*)
{

    return false;
}

//MARK: Refined Class

AlertWindowService::AlertWindowService(IOStreamServiceImp *imp){

    this->imp = imp;

}

AlertWindowService::~AlertWindowService()
{
    this->imp = nullptr;
}

void AlertWindowService::showErrorMessage(const char* text)
{
    this->imp->showErrorMessage(text);
}

void AlertWindowService::showInfoMessage(const char *text)
{
       this->imp->showInfoMessage(text);
}

std::string AlertWindowService::selectFile()
{
    this->imp->selectFile();
}

bool AlertWindowService::saveFileWithName(const char* fileName)
{
    return imp->saveFileWithName(fileName);
}
