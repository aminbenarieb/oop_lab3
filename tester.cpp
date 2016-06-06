#include "tester.h"
#include "concretefactory.h"
#include "filestream.h"

Tester::Tester(Facade *facadeVal, QApplication *appVal) : facade(facadeVal), app(appVal){}
Tester::~Tester(){
    this->facade = nullptr;
    this->app    = nullptr;
}

void Tester::setFacade(Facade *value)
{
    facade = value;
}

void Tester::loadModel()
{
    facade->uploadModelFromFile({SOURCE_FILE, "/Users/aminbenarieb/GitHub/uni/oop/lab3/model.txt"});
}

void Tester::loadCamera()
{
    facade->uploadCameraFromFile({SOURCE_FILE, "/Users/aminbenarieb/GitHub/uni/oop/lab3/camera.txt"});
}

void Tester::drawScene()
{
    facade->drawScene();
}

void Tester::transformModel()
{
    facade->transformModel({TRANSFORM_ROTATE_X, 1});
    facade->transformModel({TRANSFORM_ROTATE_Y, 1});
    facade->transformModel({TRANSFORM_ROTATE_Z, 1});
    facade->transformModel({TRANSFORM_SCALE, 1});
}


void Tester::transformCamera()
{
    facade->transformCamera({TRANSFORM_ROTATE_X, 1});
    facade->transformCamera({TRANSFORM_ROTATE_Y, 1});
    facade->transformCamera({TRANSFORM_ROTATE_Z, 1});
    facade->transformCamera({TRANSFORM_SCALE, 1});
}
