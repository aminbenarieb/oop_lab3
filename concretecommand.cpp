#include "concretecommand.h"

DrawScene::DrawScene(Action *action){

    this->action = action;

}
void DrawScene::execute(){
}

ClearScene::ClearScene(Action *action){

    this->action = action;

}
void ClearScene::execute()
{

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

TransformModel::TransformModel(Action *action, TransformInfo transformInfo){

    this->action = action;
    this->transformInfo = transformInfo;

}
void TransformModel::execute()
{

}

TransformCamera::TransformCamera(Action *action, TransformInfo transformInfo){

    this->action = action;
    this->transformInfo = transformInfo;

}
void TransformCamera::execute()
{

}
