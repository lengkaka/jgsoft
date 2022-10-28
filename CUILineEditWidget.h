#ifndef CUILINEEDITWIDGET_H
#define CUILINEEDITWIDGET_H

#include <QLineEdit>
#include <QWidget>
#include <QLabel>
#include "AbstructCustomClass.h"
class CUILineEditWidget : public QWidget,public AbstructCustomClass
{
    Q_OBJECT
public:
    explicit CUILineEditWidget(QWidget *parent = nullptr);
    void render() override;
    bool submit() override;
private:
    QLineEdit *_LineEdit=new QLineEdit();
    QLabel *_unidade=new QLabel();
private slots:
    void setLineEditValue();
signals:

};

#endif // CUILINEEDITWIDGET_H
