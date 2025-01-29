#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
// for arduino
#include <QSerialPort>
#include <QSerialPortInfo>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_On_clicked();

    void on_Off_clicked();

    void on_maintenanceButton_clicked();

private:
    Ui::MainWindow *ui;

    // for arduino
    void sendCommand(QString);

    QSerialPort* arduino;

    static const quint16 arduino_vendor_id = 6790;
    static const quint16 arduino_product_id = 29987;

    QString arduino_port_name;
    bool arduino_is_available;
};
#endif // MAINWINDOW_H
