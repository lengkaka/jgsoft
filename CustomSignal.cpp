#include "CustomSignal.h"

CustomSignal *CustomSignal::getInstance()
{
    return paraChangeSignal;
}
CustomSignal* CustomSignal::paraChangeSignal = new CustomSignal;
void CustomSignal::Change(QString name,int value)
{
    emit paraChange(name,value);
}

CustomSignal::CustomSignal(QObject *parent) : QObject(parent)
{

}
