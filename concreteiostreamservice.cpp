#include "concreteiostreamservice.h"


AlertWindowService::AlertWindowService(){}

void AlertWindowService::showErrorMessage(const char* text)
{
    QMessageBox::warning(this,"Unexpecter error occured", QString(text), QMessageBox::Ok);
}

void AlertWindowService::showInfoMessage(const char *text)
{
       QMessageBox alertWindow;
       alertWindow.setText(text);
       alertWindow.exec();
}

std::string AlertWindowService::selectFile()
{
    fileName = QFileDialog::getOpenFileName(0, "Upload file", "", "*.txt");

    return fileName.toStdString();
}

bool AlertWindowService::saveFileWithName(const char*)
{

    return false;
}
