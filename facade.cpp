#include "facade.h"
#include "baseexception.h"
#include "concretecommand.h"

Facade::Facade()
{
    this->action = new Action();
    this->alertWindowService = new AlertWindowService(new AlertWindowServiceImp);
}

Facade::~Facade()
{
    delete action;
    delete alertWindowService;
}

void Facade::uploadModelFromFile()
{
    try
    {
        const char* fileName = alertWindowService->selectFile().c_str();
        StreamInfo streamInfo = {SOURCE_FILE, fileName};
        AddModel addModel(this->action, streamInfo);
        addModel.execute();
    }
    catch(BaseException& exc)
    {
        this->alertWindowService->showErrorMessage(exc.what());
    }
}
void Facade::uploadCameraFromFile()
{
    try
    {
        const char* fileName = alertWindowService->selectFile().c_str();
        StreamInfo streamInfo = {SOURCE_FILE, fileName};
        AddCamera addCamera(this->action, streamInfo);
        addCamera.execute();
    }
    catch(BaseException& exc)
    {
        this->alertWindowService->showErrorMessage(exc.what());
    }
}

void Facade::clearScene()
{
    try
    {
        ClearScene clearScene(this->action);
        clearScene.execute();
    }
    catch(BaseException& exc)
    {
        this->alertWindowService->showErrorMessage(exc.what());
    }
}

void Facade::transformModel(TransformInfo transformInfo){

    try
    {
        TransformModel transformModel(this->action, transformInfo);
        transformModel.execute();
    }
    catch(BaseException& exc)
    {
        this->alertWindowService->showErrorMessage(exc.what());
    }
}
void Facade::transformCamera(TransformInfo transformInfo){

    try
    {
        TransformCamera transformCamera(this->action, transformInfo);
        transformCamera.execute();
    }
    catch(BaseException& exc)
    {
        this->alertWindowService->showErrorMessage(exc.what());
    }

}
