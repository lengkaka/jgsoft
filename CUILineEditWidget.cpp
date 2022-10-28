#include "CUILineEditWidget.h"
#include <QDebug>
#include <QDoubleValidator>
#include <QLabel>
#include <QToolTip>
#include <QFormLayout>

CUILineEditWidget:: CUILineEditWidget (QWidget *parent) : QWidget(parent)
{
	_config = getconfig();
    connect(_LineEdit,&QLineEdit::textEdited,this,&CUILineEditWidget::setLineEditValue);
}
void CUILineEditWidget::render()
{
    QHBoxLayout *Hlayout=new QHBoxLayout();
    QSizePolicy LineEditSizePolicy = _LineEdit->sizePolicy();
    LineEditSizePolicy.setHorizontalPolicy(QSizePolicy::Expanding);
    _LineEdit->setSizePolicy(LineEditSizePolicy);

    QSizePolicy LabelSizePolicy = _unidade->sizePolicy();
    LabelSizePolicy.setHorizontalPolicy(QSizePolicy::Fixed);
    _unidade->setSizePolicy(LabelSizePolicy);
    switch (_config.getDataType()) {
    case DoubleType:
    {
        _LineEdit->setText(QString::number(_config.DoubleDefaultValue(),'f',10));
        if(_config.getUnidade()!="")
        {
            _unidade->setText(_config.getUnidade());

        }
        else {
            _unidade->setText("  ");
        }
		break;
    }
    case IntType:
    {
        _LineEdit->setText(QString::number(_config.IntDefaultValue()));
        if(_config.getUnidade()!="")
        {
            _unidade->setText(_config.getUnidade());
        }
        else {
            _unidade->setText("  ");
        }
		break;
    }
    case QStringType:
    {
        _LineEdit->setText(_config.defaultValue());
        if(_config.getUnidade()!="")
        {
            _unidade->setText(_config.getUnidade());
        }
        else {
            _unidade->setText("  ");
        }
        break;
    }
    case BoolType:
    {
		break;
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

void CUILineEditWidget::setLineEditValue()
{
    switch (_config.getDataType()) {
    case DoubleType:
    {
        _config.setDoubleValue(_LineEdit->text().toDouble());
        break;
    }
    case IntType:
    {
        _config.setIntValue(_LineEdit->text().toInt());
        break;
    }
    case BoolType:
    {
        break;
    }
    case QStringType:
    {
        _config.setValue(_LineEdit->text());
        break;
    }
    }
}

