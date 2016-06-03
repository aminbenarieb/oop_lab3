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

void Facade::rotateModelX(double){}
void Facade::rotateModelY(double){}
void Facade::rotateModelZ(double ){}

void Facade::rotateCameraX(double){}
void Facade::rotateCameraY(double){}
void Facade::rotateCameraZ(double){}

void Facade::scaleModel(double){}
void Facade::scaleCamera(double){}
