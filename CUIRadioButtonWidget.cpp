#include "CUIRadioButtonWidget.h"

#include <QButtonGroup>
#include <QFormLayout>
#include <QDebug>
CUIRadioButtonWidget::CUIRadioButtonWidget(QWidget *parent) : QWidget(parent)
{
	_config = getconfig();



}

void CUIRadioButtonWidget::render()
{
    QRadioButton *btnRadio;
    QHBoxLayout *Hlayout=new QHBoxLayout();

    switch (_config.getDataType()) {

    case QStringType:
    {
        int total= _config.candidateValue().size();
        for(int i=0;i<total;i++)
        {
            btnRadio=new QRadioButton;

            btnRadio->setText(_config.candidateValue().at(i));
            if(_config.defaultValue()== _config.candidateValue().at(i))
                btnRadio->setChecked(true);
            btnRadiolist.append(btnRadio);
            Hlayout->addWidget(btnRadio);
        }
		break;
    }
    case IntType:
    {
        int total= _config.IntCandidateValue().size();
        for(int i=0;i<total;i++)
        {
            btnRadio=new QRadioButton;

            btnRadio->setText(QString::number(_config.IntCandidateValue().at(i)));
            if(_config.IntDefaultValue()== _config.IntCandidateValue().at(i))
                btnRadio->setChecked(true);
            btnRadiolist.append(btnRadio);
            Hlayout->addWidget(btnRadio);
        }
		break;
    }
    case BoolType:
    {
        int total= _config.candidateValue().size();
        for(int i=0;i<total;i++)
        {
            btnRadio=new QRadioButton;

            btnRadio->setText(_config.candidateValue().at(i));
            if(_config.BoolDefaultValue()== _config.BoolCandidateValue().at(i))
                btnRadio->setChecked(true);
            btnRadiolist.append(btnRadio);
            Hlayout->addWidget(btnRadio);
        }
		break;
    }
    case DoubleType:
    {
		break;
    }
    }
    for (int i=0;i<btnRadiolist.size();i++) {
        connect(btnRadiolist.at(i),&QRadioButton::toggled,this,&CUIRadioButtonWidget::setRadioButtonValue);
    }
    setLayout(Hlayout);
    this->layout()->setContentsMargins(0,0,0,0);


}


bool CUIRadioButtonWidget::submit()
{
    return true;
}

void CUIRadioButtonWidget::setRadioButtonValue()
{

    for (int i = 0; i < btnRadiolist.size(); i++)
	{
		if (btnRadiolist.at(i)->isChecked())
		{
            _config.setIntValue(i);
		}
	}

}
