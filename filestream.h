#ifndef FILESTREAM_H
#define FILESTREAM_H

#include "basestream.h"
#include "baseexception.h"

class FileOpenException : public BaseException
{
public:
    virtual const char* what()
    {
        return "Unable to open file.";
    }
};

class InvalidFileException : public BaseException
{
    virtual const char* what()
    {
        return "File is corrupted or has unsupported format.";
    }
};
class InvalidModelFileException : public InvalidFileException
{
public:
    virtual const char* what()
    {
        return "Model file is corrupted or has unsupported format.";
    }
};
class InvalidCameraFileException : public InvalidFileException
{
public:
    virtual const char* what()
    {
        return "Camera file is corrupted or has unsupported format.";
    }
};

class FileStreamImp : public BaseStreamImp
{
private:
    FILE* file;

    bool readCount(size_t&);
    bool readPoint(double &, double &, double &);
    bool readEdge(size_t&, size_t&);

    size_t readPoints(size_t,BaseModel*);
    size_t readEdges(size_t, size_t, BaseModel*);

    bool processPoints(BaseModel *);
    bool processEdges(BaseModel *);


    bool readParams(double &,double &,double &);
    bool processParams(double &,double &,double &, double &,double &,double &);


    void openFile(const char*);
    void closeFile();

public:
    FileStreamImp();
    ~FileStreamImp();
    virtual BaseObject* loadModel(const char*, BaseModel *) override;
    virtual void loadCameraParams(const char*, double &,double &,double &, double &,double &,double &) override;
};

class FileStream : public BaseStream
{
public:
    FileStream(FileStreamImp *, AbstractFactory *);
    ~FileStream();

    virtual BaseObject* loadModel(const char*) override;
    virtual BaseCamera* loadCamera(const char*) override;
};

#endif // FILESTREAM_H
