﻿#ifndef CUIRADIOBUTTONWIDGET_H
#define CUIRADIOBUTTONWIDGET_H

#include <QButtonGroup>
#include <QRadioButton>
#include <QWidget>
#include "AbstructCustomClass.h"
class CUIRadioButtonWidget : public QWidget,public AbstructCustomClass
{
    Q_OBJECT
public:
    explicit CUIRadioButtonWidget(QWidget *parent = nullptr);
public:
    void render() override;
    bool submit() override;//提交的时候检测是否必填的都填了
    QList<QRadioButton*> btnRadiolist={};//动态创建按钮的列表
public slots:
	void setRadioButtonValue();
signals:
    void connectRadioButton();
};

#endif // CUIRADIOBUTTONWIDGET_H
