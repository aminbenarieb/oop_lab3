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
public:
    virtual const char* what()
    {
        return "File is corrupted or has unsupported format.";
    }
};

class FileStream : public BaseStream
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
    FileStream(AbstractFactory *);
    ~FileStream();

    virtual BaseObject* loadModel(const char*);
    virtual BaseCamera* loadCamera(const char*);
};

#endif // FILESTREAM_H
