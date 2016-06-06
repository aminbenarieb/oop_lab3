#include "concretecommand.h"

DrawScene::DrawScene(Action *action)
{

    this->action = action;

}
void DrawScene::execute()
{
    this->action->drawScene();
}

ClearScene::ClearScene(Action *action){

    this->action = action;

}
void ClearScene::execute()
{
    this->action->clearScene();
}

AddModel::AddModel(Action *action, const StreamInfo* streamInfo){

    this->action = action;
    this->streamInfo = streamInfo;

}
void AddModel::execute()
{
    this->action->uploadModel(streamInfo);
}

AddCamera::AddCamera(Action *action, StreamInfo* streamInfo){

    this->action = action;
    this->streamInfo = streamInfo;

}
void AddCamera::execute()
{
    this->action->uploadCamera(streamInfo);
}

TransformModel::TransformModel(Action *action, const TransformInfo *transformInfo){

    this->action = action;
    this->transformInfo = transformInfo;

}
void TransformModel::execute()
{
    this->action->transformModel(transformInfo);
}

TransformCamera::TransformCamera(Action *action, const TransformInfo *transformInfo){

    this->action = action;
    this->transformInfo = transformInfo;

}
void TransformCamera::execute()
{
    this->action->transformCamera(transformInfo);
}
