#ifndef CUICOMBOBOXWIDGET_H
#define CUICOMBOBOXWIDGET_H

#include "AbstructCustomClass.h"
#include <QComboBox>
#include <QWidget>
#include <QLabel>
class CUIComboBoxWidget : public QWidget,public AbstructCustomClass
{
    Q_OBJECT
public:
    explicit CUIComboBoxWidget(QWidget *parent = nullptr);
    void render() override;
    bool submit() override;
private:
    QStringList strList;
    QComboBox *combox=new QComboBox();
    QLabel *titleLabel=new QLabel();
public slots:
    void setComboBoxValue();
signals:

};

#endif // CUICOMBOBOXWIDGET_H
