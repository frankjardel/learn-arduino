#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    arduino_is_available = false;
    arduino_port_name = "";
    arduino = new QSerialPort;

    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()) {
        if (serialPortInfo.hasVendorIdentifier() && serialPortInfo.hasProductIdentifier()) {
            if (serialPortInfo.vendorIdentifier() == arduino_vendor_id) {
                if (serialPortInfo.productIdentifier() == arduino_product_id) {
                    arduino_port_name = serialPortInfo.portName();
                    arduino_is_available = true;
                }
            }
        }
    }

    if (arduino_is_available) {
        arduino->setPortName(arduino_port_name);
        arduino->open(QSerialPort::ReadWrite);
        arduino->setBaudRate(QSerialPort::Baud9600);
        arduino->setDataBits(QSerialPort::Data8);
        arduino->setParity(QSerialPort::NoParity);
        arduino->setStopBits(QSerialPort::OneStop);
        arduino->setFlowControl(QSerialPort::NoFlowControl);
    } else {
        QMessageBox::warning(this, "Error in port..", "Was not found Arduino.");
        qDebug() << "Error in the port" << this;
    }

    // Check once
    // qDebug() << "Ports Available" << QSerialPortInfo::availablePorts().length();
    // foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()) {
    //     qDebug() << "Has vendor ID: " << serialPortInfo.hasVendorIdentifier();
    //     if (serialPortInfo.hasVendorIdentifier()) {
    //         qDebug() << "Vendor Id: " << serialPortInfo.vendorIdentifier();
    //     }
    //     qDebug() << "Has product ID: " << serialPortInfo.hasProductIdentifier();
    //     if (serialPortInfo.hasProductIdentifier()) {
    //         qDebug() << "Product Id: " << serialPortInfo.productIdentifier();
    //     }
    // }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_On_clicked()
{
    sendCommand("l");
    ui->label->setText("On");
}

void MainWindow::on_Off_clicked()
{
    sendCommand("d");
    ui->label->setText("Off");
}

void MainWindow::on_maintenanceButton_clicked()
{
    sendCommand("m");
    ui->label->setText("Maintenance");
}

void MainWindow::sendCommand(QString command)
{
    if (arduino->isWritable()) {
        arduino->write(command.toStdString().c_str());
    } else {
        qDebug() << "Was not possible send to Arduino";
    };
}
