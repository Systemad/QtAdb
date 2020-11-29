#include "adbapp.h"
#include "ui_adbapp.h"
#include <QProcess>

AdbApp::AdbApp(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AdbApp)
{
    ui->setupUi(this);

    //ui->adbOutput->setText("Helli");
    connect(ui->devicesButton, SIGNAL(clicked()), this, SLOT(clearField()));

}

AdbApp::~AdbApp()
{
    delete ui;
}

void AdbApp::clearField(){

    QString exec = "adb";
    QStringList params;
    params << "devices";
    adb.start(exec, params);
    adb.waitForFinished();
    QString output(adb.readAllStandardOutput());
    ui->adbOutput->setText(output);

    adb.kill();
    //ui->adbOutput->clear();
}

