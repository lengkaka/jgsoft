#ifndef CUIRADIOBUTTONWIDGET_H
#define CUIRADIOBUTTONWIDGET_H

#include <QButtonGroup>
#include <QRadioButton>
#include <QWidget>
#include <QLabel>
#include "AbstructCustomClass.h"
#include "CustomSignal.h"
class CUIRadioButtonWidget : public QWidget,public AbstructCustomClass
{
    Q_OBJECT
public:
    explicit CUIRadioButtonWidget(QWidget *parent = nullptr);
public:
    void render() override;
    bool submit() override;//提交的时候检测是否必填的都填了
    void hideWidget() override;
    void showWidget() override;
    QList<QRadioButton*> btnRadiolist={};//动态创建按钮的列表
    QLabel *titleLabel=new QLabel();
public slots:
	void setRadioButtonValue();
    void buttonSignalChange();
signals:
    void connectRadioButton();
    void SignalChange(QString name,int value);
};

#endif // CUIRADIOBUTTONWIDGET_H
