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
    facade->uploadModelFromFile({SOURCE_FILE, "/Users/aminbenarieb/GitHub/uni/oop/lab3/camera.txt"});
}
