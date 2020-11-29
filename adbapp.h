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
    void adbDevices();
    void executeCommand(const QStringList &args);
    void clearField();

private:
    QProcess m_adb;
    QString m_output;
};
#endif // ADBAPP_H
