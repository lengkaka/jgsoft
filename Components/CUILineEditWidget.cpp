#include "CUILineEditWidget.h"
#include <QDebug>
#include <QDoubleValidator>
#include <QLabel>
#include <QToolTip>
#include <QFormLayout>

CUILineEditWidget:: CUILineEditWidget (QWidget *parent) : QWidget(parent)
{

}
void CUILineEditWidget::render()
{
    //接收配置
    CustomClass custom=getconfig();
    //setValidator提供了一个确保一个字符串包含一个在一定有效范围内的整数的验证器
    //设置配置
    QHBoxLayout *Hlayout=new QHBoxLayout();
    QSizePolicy LineEditSizePolicy = _LineEdit->sizePolicy();
    LineEditSizePolicy.setHorizontalPolicy(QSizePolicy::MinimumExpanding);
    _LineEdit->setSizePolicy(LineEditSizePolicy);

    QSizePolicy LabelSizePolicy = _unidade->sizePolicy();
    LabelSizePolicy.setHorizontalPolicy(QSizePolicy::Fixed);
    _unidade->setSizePolicy(LabelSizePolicy);
    switch (custom.getDataType()) {
    case DoubleType:
    {

        _LineEdit->setText(QString::number(custom.DoubleDefaultValue(),'f',20));

        if(custom.getUnidade()!="")
        {
            _unidade->setText(custom.getUnidade());

        }
        else {
            _unidade->setText("  ");


        }

    }
    case IntType:
    {
        _LineEdit->setText(QString::number(custom.IntDefaultValue()));

        if(custom.getUnidade()!="")
        {
            _unidade->setText(custom.getUnidade());


        }
        else {
            _unidade->setText("  ");

        }

    }
    case QStringType:
    {

    }
    case BoolType:
    {

    }
    }
    Hlayout->addWidget(_LineEdit);
    Hlayout->addWidget(_unidade);
    setLayout(Hlayout);
    this->layout()->setContentsMargins(0,0,0,0);

}
bool CUILineEditWidget::submit()
{
    return true;
}

