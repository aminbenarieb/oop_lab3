#include "action.h"

Action::Action()
{
    this->scene = new ConcreteScene();
    this->loadManager = BaseManager(); //worker
    this->paintManager = BaseManager();
    this->transformManager = BaseManager();
    this->sceneManager = BaseManager(); //employe
}

Action::~Action()
{
    delete this->scene;
}


void Action::uploadModel(StreamInfo)
{

}

void Action::uploadCamera(StreamInfo)
{

}
