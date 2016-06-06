#ifndef LOADMANAGER_H
#define LOADMANAGER_H

#include "basestream.h"
#include "filestream.h"
#include "concretefactory.h"

class LoadManager
{
private:
    BaseStream *stream;

public:
    LoadManager(BaseStream *);
    ~LoadManager();

     BaseObject* loadObject(const StreamInfo*);
     BaseCamera* loadCamera(const StreamInfo *);
};

#endif // LOADMANAGER_H
