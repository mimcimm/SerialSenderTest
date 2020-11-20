#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QErrorMessage>
#include <QSerialPort>
#include <QDebug>
#include <QThread>
#include <QFile>
#include <QDir>
#include <QFileDialog>
#include <QMessageBox>
#include <QTimer>
#include <QThread>
#include <QSerialPortInfo>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QSerialPort* serial;
    QByteArray serialData ;
    void initializeSerialPort();
    void writeData(QByteArray data);
    void showMessageBox(QString error);


private slots:
    void openButtonClicked();
    void closeButtonClicked();
    void sendButtonClicked();
};
#endif // MAINWINDOW_H
