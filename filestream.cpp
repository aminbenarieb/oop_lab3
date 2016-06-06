#include "filestream.h"
#include <stdio.h>

FileStream::FileStream(AbstractFactory *factory)
{
    this->factory = factory;
}

FileStream::~FileStream()
{

}

void FileStream::openFile(const char* fileName)
{
    if ((this->file = fopen(fileName, "r")) == NULL)
    {
        throw FileOpenException();
    }
}
void FileStream::closeFile()
{
    fclose(this->file);
}

bool FileStream::readCount(size_t& count)
{
    return fscanf(this->file, "%lu", &count) == 1;
}
bool FileStream::readPoint(double &x, double &y, double &z)
{
    return fscanf(this->file, "%lf %lf %lf", &x, &y, &z) == 3;
}
bool FileStream::readEdge(size_t& from , size_t& to)
{
    return fscanf(this->file, "%lu %lu", &from, &to) == 2;
}

size_t FileStream::readPoints(size_t count, BaseModel* model)
{
    size_t i = 0;
    double x,y,z;
    for (i = 0; i < count && readPoint(x, y, z); i++)
        model->addPoint(x, y, z);
    return i;
}
size_t FileStream::readEdges(size_t count, size_t pointsCount, BaseModel*model)
{
    size_t from, to, i;
    for (i = 0; i < count && readEdge(from, to) && from - 1 < pointsCount && to - 1 < pointsCount; i++)
    {
        model->addEdge( &( model->getPoints()[from-1] ), &( model->getPoints()[to-1] ) );
    }

    return i;
}

bool FileStream::processPoints(BaseModel *model)
{
    size_t count;
    if (!this->readCount(count))
    {
        return false;
    }

    size_t readedCount = this->readPoints(count, model);
    if (readedCount != count)
    {
//        return false;
    }

    return true;
}
bool FileStream::processEdges(BaseModel *model)
{
    size_t count;
    if (!this->readCount(count))
    {
        return false;
    }

    size_t readedCount = this->readEdges(count, model->getPointsCount(), model);
    if (readedCount < count)
    {
        return false;
    }


    return true;
}


bool FileStream::readParams(double &alpha, double &beta, double &scale)
{
    return fscanf(this->file, "%lf %lf %lf", &alpha, &beta, &scale) == 3;
}

bool FileStream::processParams(double &x, double &y, double &z, double &alpha, double &beta, double &scale)
{
    return readPoint(x,y,z) && readParams(alpha, beta, scale);
}


BaseObject* FileStream::loadModel(const char *fileName)
{
    BaseModel* model = this->factory->createModel();
    if (!model)
    {
        throw MemoryException();
    }

    openFile(fileName);
    if (!this->processPoints(model) || !this->processEdges(model))
    {
        delete model;
        closeFile();
        throw InvalidModelFileException();
    }
    closeFile();


    return model;

}
BaseCamera* FileStream::loadCamera(const char*fileName)
{
    double x, y, z, alpha,beta,scale;

    openFile(fileName);
    if ( !this->processParams(x, y, z, alpha, beta, scale) )
    {
        closeFile();
        throw InvalidCameraFileException();
    }

    BaseCamera* camera = this->factory->createCamera(x,y,z,alpha,beta,scale);
    if (!camera)
    {
        closeFile();
        throw MemoryException();
    }

    closeFile();

    return camera;
}
