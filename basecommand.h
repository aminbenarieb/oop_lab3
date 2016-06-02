#ifndef COMMAND_H
#define COMMAND_H


class BaseCommand
{
public:
    virtual ~BaseCommand(){}
    virtual void execute() = 0;
};

#endif // COMMAND_H
