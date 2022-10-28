#include "CUIComboBoxWidget.h"
#include <QWidget>
#include <QDebug>
#include <QFormLayout>

CUIComboBoxWidget::CUIComboBoxWidget(QWidget *parent) : QWidget(parent)
{
	_config = getconfig();
    connect(combox,&QComboBox::currentTextChanged,this,&CUIComboBoxWidget::setComboBoxValue);
}

void CUIComboBoxWidget::render()
{
    QHBoxLayout *Hlayout=new QHBoxLayout();
    for (int i=0;i< _config.candidateValue().size();i++) {
        combox->addItem(_config.candidateValue().at(i));
        if(_config.IntDefaultValue()== _config.IntCandidateValue().at(i)){
            combox->setCurrentIndex(i);
        }
    }
    Hlayout->addWidget(combox);
    setLayout(Hlayout);
    this->layout()->setContentsMargins(0,0,0,0);
}

bool CUIComboBoxWidget::submit()
{
    return true;
}

void CUIComboBoxWidget::setComboBoxValue()
{
    _config.setIntValue(combox->currentIndex());
}
