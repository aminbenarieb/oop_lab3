#ifndef IOSTREAMSERVICE_H
#define IOSTREAMSERVICE_H

#include <QString>
class IOStreamService
{

public:
    virtual ~IOStreamService(){}

    virtual void showErrorMessage(const char*) = 0;
    virtual void showInfoMessage(const char*) = 0;

    virtual std::string selectFile() = 0;
    virtual bool saveFileWithName(const char*) = 0;
};


#endif // IOSTREAMSERVICE_H
