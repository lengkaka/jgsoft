#ifndef CUSTOMCOLLECTIONWIDGET_H
#define CUSTOMCOLLECTIONWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QFormLayout>
#include <QGroupBox>
#include "AbstructCustomClass.h"
#include "ArgumentsClass.h"
#include "CUIRadioButtonWidget.h"
#include "CUIComboBoxWidget.h"
#include "CUILineEditWidget.h"
#include "CustomSignal.h"
class CustomCollectionWidget : public QWidget
{
    Q_OBJECT


public:
    CustomCollectionWidget(QWidget *parent = nullptr);
    ~CustomCollectionWidget();
private:
    void render();
    bool submit();// 提交的时候检测是否必填的都填了，循环遍历
    void setWidgetList(ArgumentsClass c);//把参数组对象传到参数组列表里
    void AddCustomObjList(AbstructCustomClass* c);//添加组件到组件列表
    QString GroupboxStyle();
    void initGroupBox(QGroupBox *groupbox,ArgumentsClass argument,QVBoxLayout* VBoxLayout2);
    void initCustom(CustomClass custom,QVBoxLayout* VBoxLayout2);
    void initButton(QVBoxLayout* VBoxLayout);

private slots:
    void save();
    void updataLayout(QString name,int value);
private:
    std::vector<AbstructCustomClass*> _customObjList={};//组件列表
    std::vector<ArgumentsClass> _widgetList={};//参数组列表
    QPushButton *button;
};
#endif // CUSTOMCOLLECTIONWIDGET_H
