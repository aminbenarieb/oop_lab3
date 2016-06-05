#include "action.h"
#include "qdebug.h"

Action::Action()
{
    this->loadManager = new LoadManager();
    this->paintManager = BaseManager();
    this->transformManager = BaseManager();
    this->sceneManager = new SceneManager();
}

Action::~Action(){

    delete this->loadManager;
    delete this->sceneManager;
}

void Action::uploadModel(const StreamInfo *streamInfo)
{
    this->sceneManager->addObject(  this->loadManager->loadObject(streamInfo) );
}

void Action::uploadCamera(const StreamInfo *streamInfo)
{
    this->sceneManager->addCamera( this->loadManager->loadCamera( streamInfo ) );
}
