#include "action.h"
#include "qdebug.h"

Action::Action()
{
    this->loadManager = LoadManager();
    this->paintManager = BaseManager();
    this->transformManager = BaseManager();
    this->sceneManager = SceneManager();
}

Action::~Action(){}

void Action::uploadModel(StreamInfo streamInfo)
{
    this->sceneManager.addObject( this->loadManager.loadObject(streamInfo) );
    qDebug()<<*(this->sceneManager.currentCamera());
}

void Action::uploadCamera(StreamInfo)
{

}
