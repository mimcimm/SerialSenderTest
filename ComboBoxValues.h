#ifndef COMBOBOXVALUES_H
#define COMBOBOXVALUES_H
#include <QSerialPort>

class ComboBoxValues
{
public:
    ComboBoxValues(QWidget *parent = nullptr);
    ~ComboBoxValues();
    static void setParity(QSerialPort *serial,QString value){
       if(value == "NoParity") serial->setParity(QSerialPort::NoParity);
       else if(value == "EvenParity") serial->setParity(QSerialPort::EvenParity);
       else if(value == "OddParity") serial->setParity(QSerialPort::OddParity);
       else if(value == "SpaceParity") serial->setParity(QSerialPort::SpaceParity);
       else if(value == "MarkParity") serial->setParity(QSerialPort::MarkParity);
       else if(value == "UnknownParity") serial->setParity(QSerialPort::UnknownParity);
    }
    static void setDataBits(QSerialPort *serial,QString value){
       if(value == "Data5") serial->setDataBits(QSerialPort::Data5);
       else if(value == "Data6") serial->setDataBits(QSerialPort::Data6);
       else if(value == "Data7") serial->setDataBits(QSerialPort::Data7);
       else if(value == "Data8") serial->setDataBits(QSerialPort::Data8);
       else if(value == "UnknownDataBits") serial->setDataBits(QSerialPort::UnknownDataBits);
    }
    static void setStopBits(QSerialPort *serial,QString value){
       if(value == "OneStop") serial->setStopBits(QSerialPort::OneStop);
       else if(value == "OneAndHalfStop") serial->setStopBits(QSerialPort::OneAndHalfStop);
       else if(value == "TwoStop") serial->setStopBits(QSerialPort::TwoStop);
       else if(value == "UnknownStopBits")serial->setStopBits(QSerialPort::UnknownStopBits);
    }
    static void setFlowControl(QSerialPort *serial,QString value){
       if(value == "NoFlowControl")  serial->setFlowControl(QSerialPort::NoFlowControl);
       else if(value == "HardwareControl") serial->setFlowControl(QSerialPort::HardwareControl);
       else if(value == "SoftwareControl") serial->setFlowControl(QSerialPort::SoftwareControl);
       else if(value == "UnknownFlowControl") serial->setFlowControl(QSerialPort::UnknownFlowControl);
    }
};

#endif // COMBOBOXVALUES_H
