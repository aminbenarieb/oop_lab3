#ifndef BASESCENE_H
#define BASESCENE_H




class BaseScene
{

private:


public:
    virtual ~BaseScene() {}

    virtual void clear_scene() = 0;
    virtual my_fwd_lst_iterator<Camera*> add_cam(Camera* cam) = 0;
    virtual CompositeObj::iter add_model(BaseObj* model) = 0;
    virtual CompositeObj::iter obj_begin() = 0;
    virtual CompositeObj::iter obj_end() = 0;

    virtual size_t model_count() = 0;
    virtual size_t viewer_count() = 0;
};


#endif // BASESCENE_H
