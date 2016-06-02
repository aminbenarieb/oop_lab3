#include "facade.h"
#include "baseexception.h"

Facade::Facade()
{
    this->action = new Action();
    this->alertWindowService = new AlertWindowService();
}

Facade::~Facade()
{
    delete action;
    delete alertWindowService;
}

void Facade::uploadModelFromFile()
{

    std::string fileName = alertWindowService->selectFile();

    try
    {
//        AddModel add(task, filename.c_str());
//        add.execute();

//        Draw dr(task);
//        dr.execute();
    }
    catch(BaseException& exc)
    {
        this->alertWindowService->showErrorMessage(exc.what());
    }

}

void Facade::uploadCameraFromFile()
{
}

void Facade::clearScene()
{

}

void Facade::rotateModelX(double angle){}
void Facade::rotateModelY(double angle){}
void Facade::rotateModelZ(double angle){}

void Facade::rotateCameraX(double angle){}
void Facade::rotateCameraY(double angle){}
void Facade::rotateCameraZ(double angle){}

void Facade::scaleModel(double scale){}
void Facade::scaleCamera(double scale){}
