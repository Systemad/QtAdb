#ifndef ADBAPP_H
#define ADBAPP_H

#include <QMainWindow>
#include <QPushButton>
#include <QProcess>

QT_BEGIN_NAMESPACE
namespace Ui { class AdbApp; }
QT_END_NAMESPACE

class AdbApp : public QMainWindow
{
    Q_OBJECT

public:
    AdbApp(QWidget *parent = nullptr);
    Ui::AdbApp *ui;
    ~AdbApp();


private slots:
    void clearField();

private:
    QPushButton m_clearFieldButton;
    QProcess adb;
};
#endif // ADBAPP_H
