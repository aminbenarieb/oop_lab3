#include "loadmanager.h"
#include "filestream.h"
#include "concretefactory.h"

LoadManager::LoadManager()
{
    this->stream = new FileStream(new ConcreteFactory);
}

LoadManager::~LoadManager()
{
    delete this->stream;
}

BaseObject* LoadManager::loadObject(const StreamInfo *streamInfo)
{
    return this->stream->loadModel(streamInfo->sourceName);
}
