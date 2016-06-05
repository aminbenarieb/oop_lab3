#include "tester.h"
#include "concretefactory.h"
#include "filestream.h"

Tester::Tester(Facade *value) : facade(value){}
Tester::~Tester(){}

void Tester::setFacade(Facade *value)
{
    facade = value;
}

void Tester::loadModel()
{
    facade->uploadModelFromFile({SOURCE_FILE, "/Users/aminbenarieb/Desktop/1.txt"});
}
