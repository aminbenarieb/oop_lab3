#include "scenemanager.h"
#include "concretescene.h"

SceneManager::SceneManager()
{
    this->scene = new ConcreteScene;
}
SceneManager::~SceneManager()
{
    delete scene;
}

void SceneManager::clear()
{
    this->scene->clear();
}

Iterator<BaseCamera *>& SceneManager::currentCamera()
{
    return camera;
}
Iterator<BaseObject *>& SceneManager::currentObject()
{
    return object;
}

Iterator<BaseObject *> SceneManager::addObject(BaseObject *object)
{
    return (currentObject() = this->scene->addObject(object));
}
Iterator<BaseCamera *> SceneManager::addCamera(BaseCamera *camera)
{
    return (currentCamera() = this->scene->addCamera(camera));
}
