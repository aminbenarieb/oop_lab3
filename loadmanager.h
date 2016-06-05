#ifndef LOADMANAGER_H
#define LOADMANAGER_H

#include "basestream.h"

class LoadManager
{
private:
    BaseStream *stream;

public:
    LoadManager();
    ~LoadManager();

     BaseObject* loadObject(const StreamInfo*);
     BaseCamera* loadCamera(const StreamInfo *);
};

#endif // LOADMANAGER_H
