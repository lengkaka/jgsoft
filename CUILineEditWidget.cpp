#include "CUILineEditWidget.h"
#include <QDebug>
#include <QDoubleValidator>
#include <QLabel>
#include <QToolTip>
#include <QFormLayout>
#if defined(_MSC_VER) && (_MSC_VER >= 1600)
# pragma execution_character_set("utf-8")
#endif
CUILineEditWidget:: CUILineEditWidget (QWidget *parent) : QWidget(parent)
{
	_config = getconfig();
    connect(_LineEdit,&QLineEdit::textEdited,this,&CUILineEditWidget::setLineEditValue);
    connect(_LineEdit,&QLineEdit::textEdited,this,&CUILineEditWidget::limitLineEdit);
}
void CUILineEditWidget::render()
{
    //QHBoxLayout *Hlayout=new QHBoxLayout();
    QFormLayout* FormLayout=new QFormLayout();
    titleLabel->setText(_config.Label());
    titleLabel->setFixedWidth(160);
    QSizePolicy LineEditSizePolicy = _LineEdit->sizePolicy();
    LineEditSizePolicy.setHorizontalPolicy(QSizePolicy::Expanding);
    _LineEdit->setSizePolicy(LineEditSizePolicy);

    switch (_config.getDataType()) {
    case DoubleType:
    {
        _LineEdit->setText(QString::number(_config.DoubleDefaultValue()));

        if(_config.getLimit())
        {
            _LineEdit->setValidator(new QDoubleValidator(_config.getDoubleStartNum(), _config.getDoubleEndNum(),10));
        }
		break;
    }
    case IntType:
    {
        _LineEdit->setText(QString::number(_config.IntDefaultValue()));

		break;
    }
    case QStringType:
    {
        _LineEdit->setText(_config.defaultValue());

        break;
    }
    case BoolType:
    {
		break;
    }
    }
    //Hlayout->addWidget(_LineEdit);
    FormLayout->addRow(titleLabel,_LineEdit);
    setLayout(FormLayout);
    this->layout()->setContentsMargins(0,0,0,0);

}
bool CUILineEditWidget::submit()
{
    if(_config.required())
    {
        if(_LineEdit->text()=="")
        {
            return false;
        }
    }
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

void CUILineEditWidget::limitLineEdit()
{
    if(_config.getLimit())
    {
        if(_LineEdit->text().toDouble() < _config.getDoubleStartNum() || _LineEdit->text().toDouble() > _config.getDoubleEndNum())
        {
            // 错误提示
            QToolTip::showText(_LineEdit->mapToGlobal(QPoint(100, 0)), "请输入正确范围");
            // 设置LineEdit变为红色
            _LineEdit->setStyleSheet("QLineEdit{border:1px solid red }");
        }
        else
        {
            // LineEdit恢复之前的状态
            _LineEdit->setStyleSheet("QLineEdit{border:1px solid gray border-radius:1px}");
        }
    }


}

