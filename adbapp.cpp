#include "adbapp.h"
#include "ui_adbapp.h"
#include <QProcess>
#include <flattabwidget.h>

AdbApp::AdbApp(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AdbApp)
{
    ui->setupUi(this);
    //ui->fastbootTab->setTabText("");

    //ui->adbTab->addPage("Page 1", new QWidget());
    //ui->adbTab->addPage("Page haha", new QWidget());

    //ui->menubar->addPage("Dynamic");

    //connect(ui->devicesButton, SIGNAL(clicked()), this, SLOT(adbDevices()));
    //connect(ui->clearButton, SIGNAL(clicked()), this, SLOT(clearField()));
}

AdbApp::~AdbApp()
{
    delete ui;
}

void AdbApp::clearField()
{
    //ui->adbOutput->clear();
}

void AdbApp::adbDevices()
{
    QStringList arguments;
    arguments << "devices";
    executeCommand(arguments);
}

void AdbApp::executeCommand(const QStringList &args)
{
    m_output = "";
    QString exec = "adb";
    QStringList arguments;
    arguments << args;

    m_adb.start(exec, arguments);
    m_adb.waitForFinished();
    m_output = m_adb.readAllStandardOutput();
    //ui->adbOutput->setText(m_output);
}
