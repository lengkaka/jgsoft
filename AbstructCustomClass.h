#ifndef ABSTRUCTCUSTOMCLASS_H
#define ABSTRUCTCUSTOMCLASS_H


#include "CustomClass.h"

class AbstructCustomClass
{

public:
    AbstructCustomClass();
public:
    virtual void render();
    virtual bool submit();//提交的时候检测是否必填的都填了
    void setconfig(CustomClass config);//设置配置
    CustomClass getconfig();
    virtual void hideWidget();
    virtual void showWidget();
public:
    CustomClass _config;
};
#endif // ABSTRUCTCUSTOMCLASS_H
