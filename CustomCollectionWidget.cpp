#include "CustomCollectionWidget.h"

#include <QFormLayout>
#include <QGroupBox>
#include <QLabel>
#include <QVBoxLayout>
#include <QDebug>
#include <QSpacerItem>
#include <QComboBox>
#include <QMessageBox>
#include "float.h"

#if defined(_MSC_VER) && (_MSC_VER >= 1600)
# pragma execution_character_set("utf-8")
#endif
CustomCollectionWidget::CustomCollectionWidget(QWidget *parent)
    : QWidget(parent)
{
    ArgumentsClass argument1;//第一个groupbox
    argument1.setGroupName("ctrl_in_computing");
    CustomClass custom1;
    QList<QString> candidateValueList1={};
    candidateValueList1<<tr("不终止程序")<<tr("终止程序");
    QList<bool> ValueList1={};
    ValueList1<<false<<true;
    for (int i=0;i<candidateValueList1.size();i++) {
        custom1.setCandidateValue(candidateValueList1.at(i));
        custom1.setBoolCandidateValue(ValueList1.at(i));
    }
    custom1.initWithBool(tr("stopnow"),false,true);
    argument1.AddArgument(custom1);

    CustomClass custom2;
    QList<QString> candidateValueList2={};
    candidateValueList2<<tr("不显示流场")<<tr("显示流场");
    QList<bool> ValueList2={};
    ValueList2<<false<<true;
    for (int i=0;i<candidateValueList2.size();i++) {
        custom2.setCandidateValue(candidateValueList2.at(i));
        custom2.setBoolCandidateValue(ValueList2.at(i));
    }
    custom2.initWithBool(tr("viewnow"),false,true);
    argument1.AddArgument(custom2);

    CustomClass custom3;
    QList<QString> candidateValueList3={};
    candidateValueList3<<tr("显示特定边界流场")<<tr("自定义显示流场")<<tr("显示全场");
    QList<int> ValueList3={};
    ValueList3<<0<<1<<2;
    for (int i=0;i<candidateValueList3.size();i++) {
        custom3.setCandidateValue(candidateValueList3.at(i));
        custom3.setIntCandidateValue(ValueList3.at(i));
    }
    custom3.initWithInt(tr("viewtype"),2,true);
    argument1.AddArgument(custom3);

    CustomClass custom4;
    QList<QString> candidateValueList4={};
    candidateValueList4<<tr("tecplot")<<tr("plot3D")<<tr("二者");
    QList<int> ValueList4={};
    ValueList4<<0<<1<<2;
    for (int i=0;i<candidateValueList4.size();i++) {
        custom4.setCandidateValue(candidateValueList4.at(i));
        custom4.setIntCandidateValue(ValueList4.at(i));
    }
    custom4.initWithInt(tr("viewformat"),1,true);
    argument1.AddArgument(custom4);
    CustomClass custom5;
    QList<QString> candidateValueList5={};
    candidateValueList5<<tr("无量纲")<<tr("有量纲");
    QList<bool> ValueList5={};
    ValueList5<<0<<1;
    for (int i=0;i<candidateValueList5.size();i++) {
        custom5.setCandidateValue(candidateValueList5.at(i));
        custom5.setBoolCandidateValue(ValueList5.at(i));
    }
    custom5.initWithBool(tr("isdim"),0,true);
    argument1.AddArgument(custom5);

    CustomClass custom6;
    QList<QString> candidateValueList6={};
    candidateValueList6<<tr("不存储时间序列文件")<<tr("存储时间序列文件");
    QList<bool> ValueList6={};
    ValueList6<<0<<1;
    for (int i=0;i<candidateValueList6.size();i++) {
        custom6.setCandidateValue(candidateValueList6.at(i));
        custom6.setBoolCandidateValue(ValueList6.at(i));
    }
    custom6.initWithBool(tr("id_write"),0,true);
    argument1.AddArgument(custom6);
    //data_pos    =   0-数据位于网格节点上1-数据位于网格单元中心处
    CustomClass custom7;
    QList<QString> candidateValueList7={};
    candidateValueList7<<tr("数据位于网格节点上")<<tr("数据位于网格单元中心处");
    QList<bool> ValueList7={};
    ValueList7<<0<<1;
    for (int i=0;i<candidateValueList7.size();i++) {
        custom7.setCandidateValue(candidateValueList7.at(i));
        custom7.setBoolCandidateValue(ValueList7.at(i));
    }
    custom7.initWithBool(tr("data_pos"),0,true);
    argument1.AddArgument(custom7);
    setWidgetList(argument1);

    ArgumentsClass argument2;//第二个groupbox
    argument2.setGroupName("inflow");
    CustomClass custom8;
    double limit=DBL_MIN;
    custom8.initDoubleLineEidt(tr("飞行高度(单位:km)"),-25.0,true,-9999999999,0);
    argument2.AddArgument(custom8);

    CustomClass custom9;
    custom9.initDoubleLineEidt(tr("来流gama值"),1.6666666666666666666666666666667,true);
    argument2.AddArgument(custom9);

    CustomClass custom10;
    custom10.initDoubleLineEidt(tr("来流马赫数"),0.20,true);
    argument2.AddArgument(custom10);

    CustomClass custom11;    
    custom11.initDoubleLineEidt(tr("真实雷诺数(基于特征长度)"),82940.19,true);
    argument2.AddArgument(custom11);

    CustomClass custom12;
    custom12.initDoubleLineEidt(tr("攻角(单位:度)"),20.0,true);
    argument2.AddArgument(custom12);

    CustomClass custom13;
    custom13.initDoubleLineEidt(tr("侧滑角(单位:度)"),0.0,true);
    argument2.AddArgument(custom13);

    CustomClass custom14;
    custom14.initDoubleLineEidt(tr("来流温度(单位:K)"),219.585,true);
    argument2.AddArgument(custom14);

    CustomClass custom15;
    custom15.initDoubleLineEidt(tr("来流压力(单位:Pa)"),-59.9,true);
    argument2.AddArgument(custom15);

    CustomClass custom16;
    custom16.initDoubleLineEidt(tr("来流密度(单位:kg/m³)"),1.14,true,-9999999999,0);
    argument2.AddArgument(custom16);

    CustomClass custom17;
    custom17.initDoubleLineEidt(tr("来流速度(单位:m/s)"),-50.0,true,-999999999,0);
    argument2.AddArgument(custom17);

    CustomClass custom18;
    custom18.initIntLineEidt(tr("等温壁的物面温度(单位:K)"),1000,true);
    argument2.AddArgument(custom18);

    CustomClass custom19;
    custom19.initIntLineEidt(tr("速度空间u方向上并行剖分份数"),1,true);
    argument2.AddArgument(custom19);

    CustomClass custom20;
    custom20.initIntLineEidt(tr("速度空间v方向上并行剖分份数"),1,true);
    argument2.AddArgument(custom20);

    CustomClass custom21;
    custom21.initIntLineEidt(tr("速度空间w方向上并行剖分份数"),1,true);
    argument2.AddArgument(custom21);

    CustomClass custom22;
    custom22.initIntLineEidt(tr("写流场文件的进程数"),1,true);
    argument2.AddArgument(custom22);

    setWidgetList(argument2);

    setGeometry(0,0,530,800);
    button=new QPushButton;
    CustomSignal* customSignal=CustomSignal::getInstance();
    connect(customSignal,&CustomSignal::paraChange,this,&CustomCollectionWidget::updataLayout);
    connect(button,&QPushButton::clicked,this,&CustomCollectionWidget::save);
    render();

}

CustomCollectionWidget::~CustomCollectionWidget()
{
}

void CustomCollectionWidget::render()
{
    QVBoxLayout* VBoxLayout = new QVBoxLayout();//设置垂直布局
    for (int i =0;i<_widgetList.size();i++) {
        //QFormLayout* FormLayout = new QFormLayout();//设置Form布局
        QVBoxLayout* VBoxLayout2 = new QVBoxLayout();
        ArgumentsClass argument=_widgetList.at(i);
        QGroupBox *groupbox=new QGroupBox();
        //initGroupBox(groupbox,argument,FormLayout);//初始化groupbox
        initGroupBox(groupbox,argument,VBoxLayout2);//初始化groupbox
        std::vector<CustomClass> argumentList=argument.getArgument();
        for (int j=0;j<argumentList.size();j++) {
            CustomClass custom=argumentList.at(j);//参数对象列表
            initCustom(custom,VBoxLayout2);//初始化参数列表
        }
        VBoxLayout->addWidget(groupbox);
    }
    VBoxLayout->addStretch();
    initButton(VBoxLayout);//初始化按钮布局
    setLayout(VBoxLayout);

}

bool CustomCollectionWidget::submit()
{
    for(int i=0;i<_customObjList.size();i++)
    {
        if(!_customObjList.at(i)->submit()){
            return false;
        }
    }
    return true;
}

void CustomCollectionWidget::setWidgetList(ArgumentsClass c)
{
    _widgetList.push_back(c);
}

void CustomCollectionWidget::AddCustomObjList(AbstructCustomClass* c)
{
    _customObjList.push_back(c);
}

QString CustomCollectionWidget::GroupboxStyle()
{
    QString style="QGroupBox"
                  "{"
                  "margin-top:18px;"
                  "}"
                  "QGroupBox:title"
                  "{"
                  "subcontrol-origin: margin;"
                  "subcontrol-position: top left;"
                  "left: -3px;"
                  "padding:0 1px;"
                  "}";
    return style;
}

void CustomCollectionWidget::initGroupBox(QGroupBox *groupbox,ArgumentsClass argument, QVBoxLayout* VBoxLayout2)
{
    groupbox->setTitle(argument.getGroupName());
    groupbox->setLayout(VBoxLayout2);
    groupbox->setStyleSheet(GroupboxStyle());
    QSizePolicy GroupBoxSizePolicy = groupbox->sizePolicy();
    GroupBoxSizePolicy.setHorizontalPolicy(QSizePolicy::Minimum);
    GroupBoxSizePolicy.setVerticalPolicy(QSizePolicy::Fixed);
    groupbox->setSizePolicy(GroupBoxSizePolicy);
    if(argument.getGroupName()=="")
    {
        groupbox->setStyleSheet("QGroupBox{border:none}");
        //groupbox->setStyleSheet("border:none");
        groupbox->layout()->setContentsMargins(10,9,9,9);
    }

}

void CustomCollectionWidget::initCustom(CustomClass custom,QVBoxLayout* VBoxLayout2)
{
//    QLabel *labeltitle=new QLabel(custom.Label());
//    labeltitle->setFixedWidth(160);
    switch (custom.getComponentType())
    {
    case RadioButtonType:
    {
        CUIRadioButtonWidget *radiobutton=new CUIRadioButtonWidget();
        AddCustomObjList(radiobutton);
        radiobutton->setconfig(custom);
        radiobutton->render();
        //FormLayout->addRow(radiobutton);
        VBoxLayout2->addWidget(radiobutton);
        break;
    }
    case CheckBoxType:
    {
        break;
    }
    case LineEditType:
    {
        CUILineEditWidget *lineEdit=new CUILineEditWidget();
        AddCustomObjList(lineEdit);
        lineEdit->setconfig(custom);
        lineEdit->render();
        //FormLayout->addRow(lineEdit);
        VBoxLayout2->addWidget(lineEdit);
        break;
    }
    case ComboBoxType:
    {
        CUIComboBoxWidget *combox=new CUIComboBoxWidget();
        AddCustomObjList(combox);
        combox->setconfig(custom);
        combox->render();
        //FormLayout->addRow(combox);
        VBoxLayout2->addWidget(combox);
        break;
    }
    }
}

void CustomCollectionWidget::initButton(QVBoxLayout* VBoxLayout)
{
    button->setText(tr("保存"));
    QSizePolicy buttonSizePolicy = button->sizePolicy();
    buttonSizePolicy.setHorizontalPolicy(QSizePolicy::Fixed);
    buttonSizePolicy.setVerticalPolicy(QSizePolicy::Fixed);
    button->setSizePolicy(buttonSizePolicy);
    QHBoxLayout* HBoxLayout = new QHBoxLayout();
    HBoxLayout->addStretch(1);
    HBoxLayout->addWidget(button,0,Qt::AlignHCenter);
    HBoxLayout->addStretch(1);
    QWidget *widget=new QWidget();
    widget->setLayout(HBoxLayout);
    VBoxLayout->addWidget(widget);
}

void CustomCollectionWidget::save()
{
    if(submit())
    {
        //QMessageBox::information(nullptr,"Message","保存数据成功");
        int size=_customObjList.size();
        for (int i=0;i<size;i++) {
            ComponentType Type=_customObjList.at(i)->getconfig().getComponentType();
            CustomClass config=_customObjList.at(i)->getconfig();
            switch (Type) {
            case RadioButtonType:
            {
                qDebug()<<config.getIntValue();
                break;
            }
            case LineEditType:
            {
                DataType dataType=config.getDataType();
                switch (dataType) {
                case DoubleType:
                {
                    qDebug()<<config.getDoubleValue();
                    break;
                }
                case IntType:
                {
                    qDebug()<<config.getIntValue();
                    break;
                }
                case BoolType:
                {
                    break;
                }
                case QStringType:
                {
                    qDebug()<<config.getValue();
                    break;
                }
                }
                break;
            }
            case ComboBoxType:
            {
                qDebug()<<config.getIntValue();
                break;
            }
            case CheckBoxType:
            {
                break;
            }
            }
        }
    }
    else {
        qDebug()<<"有元素为空";
    }
}

void CustomCollectionWidget::updataLayout(QString name,int value)
{
    if(name=="isdim"&&value==1)
    {
        for (int i=0;i<_customObjList.size();i++) {

            QString title=_customObjList.at(i)->getconfig().Label();
            if(title=="data_pos")
            {
                _customObjList.at(i)->hideWidget();
            }
        }
    }
    else if (name=="isdim"&&value==0) {
        for (int i=0;i<_customObjList.size();i++) {

            QString title=_customObjList.at(i)->getconfig().Label();
            if(title=="data_pos")
            {
                _customObjList.at(i)->showWidget();
            }
        }
    }
}


