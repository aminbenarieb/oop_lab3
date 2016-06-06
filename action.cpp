#include "action.h"
#include "qdebug.h"

Action::Action(const CanvasInfo *canvasInfo)
{
    this->loadManager      = new LoadManager();
    this->paintManager     = new PaintManager(canvasInfo);
    this->transformManager = new TransformManager();
    this->sceneManager     = new SceneManager(new ConcreteScene);
}

Action::~Action(){

    delete this->loadManager;
    delete this->sceneManager;
    delete this->paintManager;
    delete this->transformManager;
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
void Action::clearScene()
{
    this->sceneManager->clear();
}

void Action::transformModel(const TransformInfo *transformInfo)
{
    this->transformManager->transformModel( *this->sceneManager->currentObject(), transformInfo);
}
void Action::transformCamera(const TransformInfo *transformInfo)
{
    this->transformManager->transformCamera( *this->sceneManager->currentCamera(), transformInfo);
}
