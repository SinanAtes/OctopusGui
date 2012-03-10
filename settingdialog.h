#ifndef SETTINGDIALOG_H
#define SETTINGDIALOG_H

#include <QDialog>
#include <QString>

class QLabel;
class QSpinBox;
class QPushButton;

class SettingDialog : public QDialog
{
    Q_OBJECT
private:
    QLabel *sensitivityLabel;
    QSpinBox *sensitivitySpin;
    QLabel *maxDigitLabel;
    QSpinBox *maxDigitSpin;
    QPushButton *okButton;
    QPushButton *cancelButton;
public:
    int maxDigit;
    int sensitivity;
    SettingDialog(QWidget *parent = 0);
    void readSettings();
    void writeSettings();
    void setSettings();
};

#endif // SETTINGDIALOG_H
