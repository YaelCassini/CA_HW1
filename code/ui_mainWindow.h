/********************************************************************************
** Form generated from reading UI file 'mainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *Title;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_grain;
    QSpinBox *spinBox_grain;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_speed;
    QSpinBox *spinBox_speed;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_2;
    QSpinBox *spinBox_acce;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_number;
    QLabel *number2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_length;
    QLabel *length;
    QHBoxLayout *horizontalLayout;
    QLabel *label_tension;
    QSpinBox *spinBox_tension;
    QLabel *label;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_0;
    QSlider *Slider;
    QLabel *label_1;
    QPushButton *create;
    QPushButton *show;
    QPushButton *start;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *stop_move;
    QPushButton *change;
    QPushButton *continue_move;
    QPushButton *clear;
    QLabel *pic_label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1045, 657);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Title = new QLabel(centralwidget);
        Title->setObjectName(QString::fromUtf8("Title"));
        Title->setGeometry(QRect(310, 10, 381, 71));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe Devanagari"));
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        Title->setFont(font);
        horizontalLayoutWidget_4 = new QWidget(centralwidget);
        horizontalLayoutWidget_4->setObjectName(QString::fromUtf8("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(20, 100, 1013, 501));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_grain = new QLabel(horizontalLayoutWidget_4);
        label_grain->setObjectName(QString::fromUtf8("label_grain"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Adobe Arabic"));
        font1.setPointSize(12);
        label_grain->setFont(font1);

        horizontalLayout_6->addWidget(label_grain);

        spinBox_grain = new QSpinBox(horizontalLayoutWidget_4);
        spinBox_grain->setObjectName(QString::fromUtf8("spinBox_grain"));
        spinBox_grain->setMinimumSize(QSize(30, 20));

        horizontalLayout_6->addWidget(spinBox_grain);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_speed = new QLabel(horizontalLayoutWidget_4);
        label_speed->setObjectName(QString::fromUtf8("label_speed"));
        label_speed->setFont(font1);

        horizontalLayout_2->addWidget(label_speed);

        spinBox_speed = new QSpinBox(horizontalLayoutWidget_4);
        spinBox_speed->setObjectName(QString::fromUtf8("spinBox_speed"));
        spinBox_speed->setMinimumSize(QSize(30, 20));

        horizontalLayout_2->addWidget(spinBox_speed);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_2 = new QLabel(horizontalLayoutWidget_4);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font1);

        horizontalLayout_8->addWidget(label_2);

        spinBox_acce = new QSpinBox(horizontalLayoutWidget_4);
        spinBox_acce->setObjectName(QString::fromUtf8("spinBox_acce"));
        spinBox_acce->setMinimumSize(QSize(30, 20));

        horizontalLayout_8->addWidget(spinBox_acce);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_number = new QLabel(horizontalLayoutWidget_4);
        label_number->setObjectName(QString::fromUtf8("label_number"));
        label_number->setFont(font1);

        horizontalLayout_5->addWidget(label_number);

        number2 = new QLabel(horizontalLayoutWidget_4);
        number2->setObjectName(QString::fromUtf8("number2"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Adobe Arabic"));
        font2.setPointSize(16);
        number2->setFont(font2);

        horizontalLayout_5->addWidget(number2);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_length = new QLabel(horizontalLayoutWidget_4);
        label_length->setObjectName(QString::fromUtf8("label_length"));
        label_length->setFont(font1);

        horizontalLayout_3->addWidget(label_length);

        length = new QLabel(horizontalLayoutWidget_4);
        length->setObjectName(QString::fromUtf8("length"));
        length->setFont(font2);

        horizontalLayout_3->addWidget(length);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_tension = new QLabel(horizontalLayoutWidget_4);
        label_tension->setObjectName(QString::fromUtf8("label_tension"));
        label_tension->setFont(font1);

        horizontalLayout->addWidget(label_tension);

        spinBox_tension = new QSpinBox(horizontalLayoutWidget_4);
        spinBox_tension->setObjectName(QString::fromUtf8("spinBox_tension"));
        spinBox_tension->setMinimumSize(QSize(30, 20));

        horizontalLayout->addWidget(spinBox_tension);

        label = new QLabel(horizontalLayoutWidget_4);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(70, 16777215));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Adobe Arabic"));
        font3.setPointSize(20);
        label->setFont(font3);

        horizontalLayout->addWidget(label);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_0 = new QLabel(horizontalLayoutWidget_4);
        label_0->setObjectName(QString::fromUtf8("label_0"));
        label_0->setFont(font3);

        horizontalLayout_7->addWidget(label_0);

        Slider = new QSlider(horizontalLayoutWidget_4);
        Slider->setObjectName(QString::fromUtf8("Slider"));
        Slider->setOrientation(Qt::Horizontal);

        horizontalLayout_7->addWidget(Slider);

        label_1 = new QLabel(horizontalLayoutWidget_4);
        label_1->setObjectName(QString::fromUtf8("label_1"));
        label_1->setFont(font3);

        horizontalLayout_7->addWidget(label_1);


        verticalLayout->addLayout(horizontalLayout_7);

        create = new QPushButton(horizontalLayoutWidget_4);
        create->setObjectName(QString::fromUtf8("create"));
        create->setFont(font1);

        verticalLayout->addWidget(create);

        show = new QPushButton(horizontalLayoutWidget_4);
        show->setObjectName(QString::fromUtf8("show"));
        show->setFont(font1);

        verticalLayout->addWidget(show);

        start = new QPushButton(horizontalLayoutWidget_4);
        start->setObjectName(QString::fromUtf8("start"));
        start->setFont(font1);

        verticalLayout->addWidget(start);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        stop_move = new QPushButton(horizontalLayoutWidget_4);
        stop_move->setObjectName(QString::fromUtf8("stop_move"));

        horizontalLayout_9->addWidget(stop_move);

        change = new QPushButton(horizontalLayoutWidget_4);
        change->setObjectName(QString::fromUtf8("change"));

        horizontalLayout_9->addWidget(change);

        continue_move = new QPushButton(horizontalLayoutWidget_4);
        continue_move->setObjectName(QString::fromUtf8("continue_move"));

        horizontalLayout_9->addWidget(continue_move);


        verticalLayout->addLayout(horizontalLayout_9);

        clear = new QPushButton(horizontalLayoutWidget_4);
        clear->setObjectName(QString::fromUtf8("clear"));
        clear->setFont(font1);

        verticalLayout->addWidget(clear);


        horizontalLayout_4->addLayout(verticalLayout);

        pic_label = new QLabel(centralwidget);
        pic_label->setObjectName(QString::fromUtf8("pic_label"));
        pic_label->setGeometry(QRect(90, 0, 151, 101));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1045, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Title->setText(QCoreApplication::translate("MainWindow", "Cardinal\346\240\267\346\235\241\346\233\262\347\272\277\347\256\227\346\263\225\345\261\225\347\244\272", nullptr));
        label_grain->setText(QCoreApplication::translate("MainWindow", "\346\257\217\344\270\252\345\214\272\351\227\264\346\217\222\345\200\274\347\202\271\344\270\252\346\225\260\357\274\232", nullptr));
        label_speed->setText(QCoreApplication::translate("MainWindow", "\345\260\217\350\275\246\351\200\237\345\272\246\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\345\260\217\350\275\246\345\212\240\351\200\237\345\272\246\357\274\232", nullptr));
        label_number->setText(QCoreApplication::translate("MainWindow", "\345\205\263\351\224\256\347\202\271\344\270\252\346\225\260\357\274\232", nullptr));
        number2->setText(QCoreApplication::translate("MainWindow", "    0", nullptr));
        label_length->setText(QCoreApplication::translate("MainWindow", "\350\267\257\347\272\277\346\200\273\351\225\277\345\272\246\357\274\232", nullptr));
        length->setText(QCoreApplication::translate("MainWindow", "    0", nullptr));
        label_tension->setText(QCoreApplication::translate("MainWindow", "\345\217\202\346\225\260\317\204\357\274\232", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "%", nullptr));
        label_0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        create->setText(QCoreApplication::translate("MainWindow", "\347\224\237\346\210\220\350\275\250\350\277\271", nullptr));
        show->setText(QCoreApplication::translate("MainWindow", "\346\230\276\347\244\272\346\217\222\345\200\274\347\202\271", nullptr));
        start->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213\350\277\220\345\212\250", nullptr));
        stop_move->setText(QCoreApplication::translate("MainWindow", "\346\232\202\345\201\234\350\277\220\345\212\250", nullptr));
        change->setText(QCoreApplication::translate("MainWindow", "\346\233\264\346\215\242\345\260\217\350\275\246", nullptr));
        continue_move->setText(QCoreApplication::translate("MainWindow", "\347\273\247\347\273\255\350\277\220\345\212\250", nullptr));
        clear->setText(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272\347\252\227\345\217\243", nullptr));
        pic_label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
