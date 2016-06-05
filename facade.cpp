#include "facade.h"
#include "baseexception.h"
#include "concretecommand.h"
#include "qdebug.h"

Facade::Facade(const CanvasInfo* canvasInfo)
{
    this->action = new Action(canvasInfo);
    this->alertWindowService = new AlertWindowService(new AlertWindowServiceImp);
}

Facade::~Facade()
{
    delete action;
    delete alertWindowService;
}

void Facade::processStream(StreamInfo *streamInfo)
{
    switch(streamInfo->sourceType)
    {
        case SOURCE_FILE:
            if(streamInfo->sourceName == NULL)
            {
                streamInfo->sourceName = alertWindowService->selectFile().c_str();;
            }
            break;
        default:
            throw EmptyStreamSourceException();
            break;
    }
}

void Facade::uploadModelFromFile(StreamInfo streamInfo)
{
    try
    {
        processStream(&streamInfo);

        AddModel addModel(this->action, &streamInfo);
        addModel.execute();
    }
    catch(BaseException& exc)
    {
        qDebug()<<exc.what();
        this->alertWindowService->showErrorMessage(exc.what());
    }
}
void Facade::uploadCameraFromFile(StreamInfo streamInfo)
{
    try
    {
        processStream(&streamInfo);

        AddCamera addCamera(this->action, &streamInfo);
        addCamera.execute();

    }
    catch(BaseException& exc)
    {
        this->alertWindowService->showErrorMessage(exc.what());
    }
}


void Facade::drawScene()
{
    try
    {
        DrawScene drawScene(this->action);
        drawScene.execute();
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
