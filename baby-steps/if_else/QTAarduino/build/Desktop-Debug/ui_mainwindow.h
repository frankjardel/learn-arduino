/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.15
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *On;
    QLabel *label;
    QPushButton *closeButton;
    QPushButton *maxButton;
    QPushButton *minButton;
    QPushButton *Off;
    QPushButton *maintenanceButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(656, 340);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setAutoFillBackground(false);
        On = new QPushButton(centralwidget);
        On->setObjectName(QString::fromUtf8("On"));
        On->setGeometry(QRect(60, 100, 271, 34));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 80, 261, 18));
        closeButton = new QPushButton(centralwidget);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));
        closeButton->setGeometry(QRect(510, 60, 84, 34));
        maxButton = new QPushButton(centralwidget);
        maxButton->setObjectName(QString::fromUtf8("maxButton"));
        maxButton->setGeometry(QRect(420, 60, 84, 34));
        minButton = new QPushButton(centralwidget);
        minButton->setObjectName(QString::fromUtf8("minButton"));
        minButton->setGeometry(QRect(330, 60, 84, 34));
        Off = new QPushButton(centralwidget);
        Off->setObjectName(QString::fromUtf8("Off"));
        Off->setGeometry(QRect(330, 100, 261, 34));
        maintenanceButton = new QPushButton(centralwidget);
        maintenanceButton->setObjectName(QString::fromUtf8("maintenanceButton"));
        maintenanceButton->setGeometry(QRect(67, 140, 521, 34));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 656, 30));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(closeButton, SIGNAL(clicked()), MainWindow, SLOT(close()));
        QObject::connect(maxButton, SIGNAL(clicked()), MainWindow, SLOT(showMaximized()));
        QObject::connect(minButton, SIGNAL(clicked()), MainWindow, SLOT(showMinimized()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        On->setText(QCoreApplication::translate("MainWindow", "ON", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Waiting Commannd", nullptr));
        closeButton->setText(QCoreApplication::translate("MainWindow", "Close", nullptr));
        maxButton->setText(QCoreApplication::translate("MainWindow", "Max", nullptr));
        minButton->setText(QCoreApplication::translate("MainWindow", "Min", nullptr));
        Off->setText(QCoreApplication::translate("MainWindow", "OFF", nullptr));
        maintenanceButton->setText(QCoreApplication::translate("MainWindow", "Maintenance", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
