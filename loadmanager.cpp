#include "loadmanager.h"


LoadManager::LoadManager(BaseStream *stream)
{
    this->stream = stream;
}

LoadManager::~LoadManager()
{
    delete this->stream;
}

BaseObject* LoadManager::loadObject(const StreamInfo *streamInfo)
{
    return this->stream->loadModel(streamInfo->sourceName);
}
BaseCamera* LoadManager::loadCamera(const StreamInfo *streamInfo)
{
    return this->stream->loadCamera(streamInfo->sourceName);
}
