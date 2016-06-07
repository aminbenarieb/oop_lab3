#include "filestream.h"
#include <stdio.h>

FileStreamImp::FileStreamImp(){}
FileStreamImp::~FileStreamImp(){}

void FileStreamImp::openFile(const char* fileName)
{
    if ((this->file = fopen(fileName, "r")) == NULL)
    {
        throw FileOpenException();
    }
}
void FileStreamImp::closeFile()
{
    fclose(this->file);
}

bool FileStreamImp::readCount(size_t& count)
{
    return fscanf(this->file, "%lu", &count) == 1;
}
bool FileStreamImp::readPoint(double &x, double &y, double &z)
{
    return fscanf(this->file, "%lf %lf %lf", &x, &y, &z) == 3;
}
bool FileStreamImp::readEdge(size_t& from , size_t& to)
{
    return fscanf(this->file, "%lu %lu", &from, &to) == 2;
}

size_t FileStreamImp::readPoints(size_t count, BaseModel* model)
{
    size_t i = 0;
    double x,y,z;
    for (i = 0; i < count && readPoint(x, y, z); i++)
        model->addPoint(x, y, z);
    return i;
}
size_t FileStreamImp::readEdges(size_t count, size_t pointsCount, BaseModel*model)
{
    size_t from, to, i;
    for (i = 0; i < count && readEdge(from, to) && from - 1 < pointsCount && to - 1 < pointsCount; i++)
    {
        model->addEdge( &( model->getPoints()[from-1] ), &( model->getPoints()[to-1] ) );
    }

    return i;
}

bool FileStreamImp::processPoints(BaseModel *model)
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
bool FileStreamImp::processEdges(BaseModel *model)
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


bool FileStreamImp::readParams(double &alpha, double &beta, double &scale)
{
    return fscanf(this->file, "%lf %lf %lf", &alpha, &beta, &scale) == 3;
}
bool FileStreamImp::processParams(double &x, double &y, double &z, double &alpha, double &beta, double &scale)
{
    return readPoint(x,y,z) && readParams(alpha, beta, scale);
}


BaseObject* FileStreamImp::loadModel(const char *fileName, BaseModel *model)
{

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
void FileStreamImp::loadCameraParams(const char*fileName, double &x, double &y, double &z, double &alpha, double &beta, double &scale)
{
    openFile(fileName);
    if ( !this->processParams(x, y, z, alpha, beta, scale) )
    {
        closeFile();
        throw InvalidCameraFileException();
    }
    closeFile();
}




FileStream::FileStream(FileStreamImp *imp, AbstractFactory *factory)
{
    this->imp = imp;
    this->factory = factory;
}
FileStream::~FileStream()
{

}


BaseObject* FileStream::loadModel(const char *fileName)
{
    BaseModel* model = this->factory->createModel();
    if (!model)
    {
        throw MemoryException();
    }

    return this->imp->loadModel(fileName, model);
}
BaseCamera* FileStream::loadCamera(const char*fileName)
{

    double x, y, z, alpha,beta,scale;
    this->imp->loadCameraParams(fileName, x, y, z, alpha,beta,scale);

    BaseCamera* camera = this->factory->createCamera(x, y, z, alpha,beta,scale);
    if (!camera)
    {
        throw MemoryException();
    }

    return camera;
}
