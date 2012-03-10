#include "settingdialog.h"
#include <QtGui>

SettingDialog::SettingDialog(QWidget *parent) :
    QDialog(parent)
{
    sensitivityLabel = new QLabel(tr("Sensitivity :"),this);
    sensitivitySpin = new QSpinBox(this);
    maxDigitLabel = new QLabel(tr("Maximum Digit :"),this);
    maxDigitSpin = new QSpinBox(this);
    okButton = new QPushButton(tr("Ok"),this);
    cancelButton = new QPushButton(tr("Cancel"),this);

    //*******Signal-Slot**********
    connect(cancelButton,SIGNAL(clicked()),this,SLOT(close()));



    //*******Layout*************
    QGridLayout *mainGridLayout = new QGridLayout;
    mainGridLayout->addWidget(this->sensitivityLabel,0,0);
    mainGridLayout->addWidget(this->sensitivitySpin,0,1);

    mainGridLayout->addWidget(this->maxDigitLabel,1,0);
    mainGridLayout->addWidget(this->maxDigitSpin,1,1);

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(okButton);
    buttonLayout->addWidget(cancelButton);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(mainGridLayout);
    mainLayout->addLayout(buttonLayout);

    setLayout(mainLayout);

}
void SettingDialog::readSettings()
{

}
