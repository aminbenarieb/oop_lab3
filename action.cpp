#include "action.h"
#include "qdebug.h"

Action::Action(const CanvasInfo *canvasInfo)
{
    this->loadManager      = new LoadManager();
    this->paintManager     = new PaintManager(canvasInfo);
    this->transformManager = BaseManager();
    this->sceneManager     = new SceneManager(new ConcreteScene);
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

void Action::drawScene()
{
    // checking models & cameras ?

    this->paintManager->drawScene(
                this->sceneManager->getScene(),
                this->sceneManager->currentCamera()
                );
}
