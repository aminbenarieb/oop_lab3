#include "action.h"

Action::Action()
{
    this->loadManager = BaseManager();
    this->paintManager = BaseManager();
    this->transformManager = BaseManager();
    this->sceneManager = SceneManager();
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
