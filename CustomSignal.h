#ifndef CUSTOMSIGNAL_H
#define CUSTOMSIGNAL_H

#include <QObject>

class CustomSignal : public QObject
{
    Q_OBJECT

public:
    //静态不用实例化就可以之间调用
    static CustomSignal* getInstance();//只能获得一个对象实现单例模式
    void Change(QString name,int value);
private://改成private的目的是在类外不能新建对象实现数据的封闭
    explicit CustomSignal(QObject *parent = nullptr);
signals:
    void paraChange(QString name,int value);//人为发送信号,函数声明
private:
    static CustomSignal* paraChangeSignal;

public slots:

};

#endif // CUSTOMSIGNAL_H
