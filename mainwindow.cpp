#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ComboBoxValues.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
        int a1;
        int a2;
        int a3;
        int a4;
        int a5;
        int a6;
    setWindowTitle("Hex Veri Gönder");
    connect(ui->openButton,SIGNAL(clicked()),this,SLOT(openButtonClicked()));
    connect(ui->closeButton,SIGNAL(clicked()),this,SLOT(closeButtonClicked()));
    connect(ui->sendButton,SIGNAL(clicked()),this,SLOT(sendButtonClicked()));
    foreach(QSerialPortInfo port, QSerialPortInfo::availablePorts())
        ui->portCombo->addItem(port.portName());

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initializeSerialPort()
{
    int a7;
        int a8;
    QThread *serialThread = new QThread;
    serial = new QSerialPort();
    serial->setParent(NULL);
    serial->moveToThread(serialThread);
    serial->setPortName(ui->portCombo->currentText());
    serial->setBaudRate(ui->baudCombo->currentText().toInt());
    ComboBoxValues::setParity(serial,ui->parityCombo->currentText());
    ComboBoxValues::setDataBits(serial,ui->dataCombo->currentText());
    ComboBoxValues::setStopBits(serial,ui->stopCombo->currentText());
    ComboBoxValues::setFlowControl(serial,ui->flowCombo->currentText());
    connect(serialThread,SIGNAL(finished()),serialThread,SLOT(deleteLater()));
    connect(serialThread,SIGNAL(finished()),serial,SLOT(deleteLater()));
    connect(serial,SIGNAL(readyRead()),this,SLOT(serialPortReceived()));
    connect(serialThread,&QThread::started,[=]()->void{
        if(!serial->open(QIODevice::ReadWrite)) // possible race condition but shouldn't cause any problems at this stage
        {
            qDebug() << "Serial Port açılmıyor";
            qDebug() << "error code = " << serial->error();
            qDebug() << "error string = " << serial->errorString();
            serialThread->quit();
        }else{
            ui->openButton->setEnabled(false);
            ui->sendButton->setEnabled(true);
            qDebug() << "Serial Port acildi";
        }
    });
    serialThread->start();

}

void MainWindow::writeData(QByteArray data)
{
    qDebug()<<"Yazılacak DAta" <<data;
    qDebug()<<"Yazılacak Hex" <<data.toHex();
    if(serial->isWritable()){
        serial->write(data);
    }
}

void MainWindow::showMessageBox(QString error)
{
    QMessageBox msgBox;
    msgBox.setText(error);
    msgBox.exec();
}

void MainWindow::openButtonClicked()
{
    initializeSerialPort();

    //    initializeSerialPort();
    //    writeData(QByteArrayLiteral("\x50\x60\x00\x65\x39\x60"));
    //    serial->flush();
    //    if (serial->isOpen())
    //        serial->close();
    //    serial->deleteLater();
    //     qDebug() << "cihaz kapandı";
}

void MainWindow::closeButtonClicked()
{
    ui->openButton->setEnabled(true);
   ui->sendButton->setEnabled(false);

    if (serial->isOpen())
        serial->close();
    serial->deleteLater();

    qDebug() << "Serial Port kapandı";

    //    initializeSerialPort();
    //    writeData(QByteArrayLiteral("\x11\x11\x00\x65\x39\x00\x65\x39"));
    //    serial->flush();
    //    if (serial->isOpen())
    //        serial->close();
    //    serial->deleteLater();
    //     qDebug() << "cihaz kapandı";
}

void MainWindow::sendButtonClicked()
{
    QByteArray sendMessage;
    if(ui->hexRadioButton->isChecked()){
        sendMessage = QByteArray::fromHex(ui->messageLineEdit->text().toUtf8());
    }else{
         sendMessage = ui->messageLineEdit->text().toUtf8();
    }
    writeData(sendMessage);
    // serial->flush();
    //    writeData(QByteArrayLiteral("\x11\x11\x00\x65\x39\x00\x65\x39"));
    //    serial->flush();
}
