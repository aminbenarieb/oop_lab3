#include "paintmanager.h"
#include "concretepainter.h"
#include "concretecanvas.h"

PaintManager::PaintManager(const CanvasInfo *canvasInfo)
{
    this->canvas = new Canvas(new QCanvasImp(canvasInfo));
    this->painter = new Painter;
}


PaintManager::~PaintManager()
{
    delete this->canvas;
    delete this->painter;
}


void PaintManager::drawObject(BaseObject *object, BaseCamera *camera)
{
     this->painter->draw(this->canvas, object, camera);
}

void PaintManager::drawObject(CompositeObject *object, BaseCamera *camera)
{
    for (Iterator<BaseObject*> it = object->begin(); it != object->end(); it++)
        this->painter->draw(this->canvas, *it, camera);
}

void PaintManager::drawScene(BaseScene *scene, Iterator<BaseCamera *> &cameraIterator)
{
    this->canvas->clear();

    for (Iterator<BaseObject*> it = scene->compositorBegin(); it != scene->compositorEnd(); it++)
    {
        if ((*it)->addObject(nullptr))
            this->drawObject(static_cast<CompositeObject*>(*it), *cameraIterator);
        else
            this->drawObject(*it, *cameraIterator);
    }
}
