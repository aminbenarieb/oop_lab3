#ifndef CONCRETECOMMAND_H
#define CONCRETECOMMAND_H

#include "basecommand.h"
#include "action.h"

class DrawScene : public BaseCommand
{
private:
    Action *action;
public:
    DrawScene(Action*);
    virtual void execute();
};

class ClearScene : public BaseCommand
{
private:
    Action *action;
public:
    ClearScene(Action*);
    virtual void execute();
};

class AddModel : public BaseCommand
{
private:
    Action *action;
    const StreamInfo *streamInfo;
public:
    AddModel(Action*, const StreamInfo*);
    virtual void execute() override;
};

class AddCamera : public BaseCommand
{
private:
    Action *action;
    StreamInfo *streamInfo;
public:
    AddCamera(Action*, StreamInfo*);
    virtual void execute() override;
};

class TransformModel : public BaseCommand
{
private:
    Action *action;
    TransformInfo transformInfo;
public:
    TransformModel(Action*, TransformInfo);
    virtual void execute() override;
};

class TransformCamera : public BaseCommand
{
private:
    Action *action;
    TransformInfo transformInfo;
public:
    TransformCamera(Action*, TransformInfo);
    virtual void execute() override;
};

#endif // CONCRETECOMMAND_H
