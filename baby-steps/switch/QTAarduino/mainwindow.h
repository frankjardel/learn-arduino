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
    void on_Red_clicked();

    void on_Green_clicked();

    void on_Yellow_clicked();

    void on_Reset_clicked();

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
