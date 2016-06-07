#include "scenemanager.h"

SceneManager::SceneManager(BaseScene *scene)
{
    this->scene = scene;
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
    return (this->object = this->scene->addObject(object));
}
Iterator<BaseCamera *> SceneManager::addCamera(BaseCamera *camera)
{
    return (this->camera = this->scene->addCamera(camera));
}

BaseScene* SceneManager::getScene()
{
    return this->scene;
}
