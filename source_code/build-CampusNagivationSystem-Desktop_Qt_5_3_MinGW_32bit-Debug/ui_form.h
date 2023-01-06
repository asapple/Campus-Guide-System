/********************************************************************************
** Form generated from reading UI file 'form.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_H
#define UI_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *labelOrigin;
    QLabel *labelTerminal;
    QLineEdit *lineEditTerminal;
    QLineEdit *lineEditOrigin;
    QPushButton *pushBUttonStart;
    QLabel *labelTerminal_2;
    QLabel *labelOrigin_2;
    QComboBox *comboBoxOriginCampus;
    QComboBox *comboBoxTerminalCampus;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *comboBoxStrategy;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelMultiple;
    QSlider *horizontalSlider;
    QLCDNumber *lcdNumber;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButtonRecord;
    QPushButton *pushButtonQuery;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEditTransfer;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEditLeftTime;
    QSpacerItem *horizontalSpacer;
    QLineEdit *lineEditDistance;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_5;
    QLineEdit *lineEditPosition;
    QPushButton *pushButton;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QStringLiteral("Form"));
        Form->resize(802, 314);
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(11);
        Form->setFont(font);
        widget = new QWidget(Form);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 10, 781, 91));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        labelOrigin = new QLabel(widget);
        labelOrigin->setObjectName(QStringLiteral("labelOrigin"));
        QFont font1;
        font1.setPointSize(13);
        labelOrigin->setFont(font1);

        gridLayout->addWidget(labelOrigin, 0, 4, 1, 1);

        labelTerminal = new QLabel(widget);
        labelTerminal->setObjectName(QStringLiteral("labelTerminal"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font2.setPointSize(13);
        font2.setBold(false);
        font2.setWeight(50);
        labelTerminal->setFont(font2);

        gridLayout->addWidget(labelTerminal, 1, 4, 1, 1);

        lineEditTerminal = new QLineEdit(widget);
        lineEditTerminal->setObjectName(QStringLiteral("lineEditTerminal"));

        gridLayout->addWidget(lineEditTerminal, 1, 5, 1, 1);

        lineEditOrigin = new QLineEdit(widget);
        lineEditOrigin->setObjectName(QStringLiteral("lineEditOrigin"));

        gridLayout->addWidget(lineEditOrigin, 0, 5, 1, 1);

        pushBUttonStart = new QPushButton(widget);
        pushBUttonStart->setObjectName(QStringLiteral("pushBUttonStart"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font3.setPointSize(16);
        font3.setBold(true);
        font3.setUnderline(true);
        font3.setWeight(75);
        pushBUttonStart->setFont(font3);
        pushBUttonStart->setStyleSheet(QStringLiteral("QPushButton { background-color: rgb(128,138,135); } QPushButton:pressed { background-color: rgb(245,245,245); }"));

        gridLayout->addWidget(pushBUttonStart, 0, 8, 2, 1);

        labelTerminal_2 = new QLabel(widget);
        labelTerminal_2->setObjectName(QStringLiteral("labelTerminal_2"));
        labelTerminal_2->setFont(font2);

        gridLayout->addWidget(labelTerminal_2, 1, 0, 1, 1);

        labelOrigin_2 = new QLabel(widget);
        labelOrigin_2->setObjectName(QStringLiteral("labelOrigin_2"));
        labelOrigin_2->setFont(font1);

        gridLayout->addWidget(labelOrigin_2, 0, 0, 1, 1);

        comboBoxOriginCampus = new QComboBox(widget);
        comboBoxOriginCampus->setObjectName(QStringLiteral("comboBoxOriginCampus"));

        gridLayout->addWidget(comboBoxOriginCampus, 0, 1, 1, 1);

        comboBoxTerminalCampus = new QComboBox(widget);
        comboBoxTerminalCampus->setObjectName(QStringLiteral("comboBoxTerminalCampus"));

        gridLayout->addWidget(comboBoxTerminalCampus, 1, 1, 1, 1);

        widget_2 = new QWidget(Form);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(10, 100, 191, 41));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font4.setPointSize(11);
        font4.setItalic(false);
        widget_2->setFont(font4);
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        comboBoxStrategy = new QComboBox(widget_2);
        comboBoxStrategy->setObjectName(QStringLiteral("comboBoxStrategy"));

        horizontalLayout_2->addWidget(comboBoxStrategy);

        widget_3 = new QWidget(Form);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setGeometry(QRect(270, 100, 291, 40));
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        labelMultiple = new QLabel(widget_3);
        labelMultiple->setObjectName(QStringLiteral("labelMultiple"));

        horizontalLayout_3->addWidget(labelMultiple);

        horizontalSlider = new QSlider(widget_3);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setMinimum(1);
        horizontalSlider->setMaximum(10);
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(horizontalSlider);

        lcdNumber = new QLCDNumber(widget_3);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        QFont font5;
        font5.setBold(true);
        font5.setItalic(false);
        font5.setUnderline(false);
        font5.setWeight(75);
        font5.setStyleStrategy(QFont::NoAntialias);
        lcdNumber->setFont(font5);
        lcdNumber->setStyleSheet(QStringLiteral(""));

        horizontalLayout_3->addWidget(lcdNumber);

        widget_4 = new QWidget(Form);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setGeometry(QRect(572, 100, 221, 81));
        horizontalLayout_4 = new QHBoxLayout(widget_4);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        pushButtonRecord = new QPushButton(widget_4);
        pushButtonRecord->setObjectName(QStringLiteral("pushButtonRecord"));
        pushButtonRecord->setIconSize(QSize(30, 30));

        horizontalLayout_4->addWidget(pushButtonRecord);

        pushButtonQuery = new QPushButton(widget_4);
        pushButtonQuery->setObjectName(QStringLiteral("pushButtonQuery"));

        horizontalLayout_4->addWidget(pushButtonQuery);

        widget_6 = new QWidget(Form);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        widget_6->setGeometry(QRect(14, 150, 551, 39));
        horizontalLayout_6 = new QHBoxLayout(widget_6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_2 = new QLabel(widget_6);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_6->addWidget(label_2);

        label_3 = new QLabel(widget_6);
        label_3->setObjectName(QStringLiteral("label_3"));
        QFont font6;
        font6.setPointSize(9);
        label_3->setFont(font6);

        horizontalLayout_6->addWidget(label_3);

        lineEditTransfer = new QLineEdit(widget_6);
        lineEditTransfer->setObjectName(QStringLiteral("lineEditTransfer"));

        horizontalLayout_6->addWidget(lineEditTransfer);

        widget_5 = new QWidget(Form);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        widget_5->setGeometry(QRect(10, 200, 797, 47));
        horizontalLayout = new QHBoxLayout(widget_5);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lineEditLeftTime = new QLineEdit(widget_5);
        lineEditLeftTime->setObjectName(QStringLiteral("lineEditLeftTime"));
        lineEditLeftTime->setReadOnly(true);

        horizontalLayout->addWidget(lineEditLeftTime);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        lineEditDistance = new QLineEdit(widget_5);
        lineEditDistance->setObjectName(QStringLiteral("lineEditDistance"));
        lineEditDistance->setReadOnly(true);

        horizontalLayout->addWidget(lineEditDistance);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        label_5 = new QLabel(widget_5);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout->addWidget(label_5);

        lineEditPosition = new QLineEdit(widget_5);
        lineEditPosition->setObjectName(QStringLiteral("lineEditPosition"));
        lineEditPosition->setReadOnly(true);

        horizontalLayout->addWidget(lineEditPosition);

        pushButton = new QPushButton(Form);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(20, 250, 101, 51));

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", 0));
        labelOrigin->setText(QApplication::translate("Form", "\350\265\267\347\202\271\357\274\232", 0));
        labelTerminal->setText(QApplication::translate("Form", "\347\273\210\347\202\271\357\274\232", 0));
        pushBUttonStart->setText(QApplication::translate("Form", "\345\274\200\345\247\213", 0));
        labelTerminal_2->setText(QApplication::translate("Form", "\347\273\210\347\202\271\346\240\241\345\214\272\357\274\232", 0));
        labelOrigin_2->setText(QApplication::translate("Form", "\350\265\267\347\202\271\346\240\241\345\214\272\357\274\232", 0));
        comboBoxOriginCampus->clear();
        comboBoxOriginCampus->insertItems(0, QStringList()
         << QApplication::translate("Form", "\350\245\277\345\234\237\345\237\216\346\240\241\345\214\272", 0)
         << QApplication::translate("Form", "\346\262\231\346\262\263\346\240\241\345\214\272", 0)
        );
        comboBoxTerminalCampus->clear();
        comboBoxTerminalCampus->insertItems(0, QStringList()
         << QApplication::translate("Form", "\350\245\277\345\234\237\345\237\216\346\240\241\345\214\272", 0)
         << QApplication::translate("Form", "\346\262\231\346\262\263\346\240\241\345\214\272", 0)
        );
        comboBoxStrategy->clear();
        comboBoxStrategy->insertItems(0, QStringList()
         << QApplication::translate("Form", "\346\234\200\347\237\255\350\267\235\347\246\273", 0)
         << QApplication::translate("Form", "\344\272\244\351\200\232\345\267\245\345\205\267\347\232\204\346\234\200\347\237\255\346\227\266\351\227\264", 0)
         << QApplication::translate("Form", "\351\200\224\345\276\204\346\234\200\347\237\255\350\267\235\347\246\273", 0)
         << QApplication::translate("Form", "\346\234\200\347\237\255\346\227\266\351\227\264", 0)
        );
        labelMultiple->setText(QApplication::translate("Form", "\346\250\241\346\213\237\345\200\215\346\225\260\357\274\232", 0));
        pushButtonRecord->setText(QApplication::translate("Form", "\346\227\245\345\277\227", 0));
        pushButtonQuery->setText(QApplication::translate("Form", "\346\234\215\345\212\241\346\237\245\350\257\242", 0));
        label_2->setText(QApplication::translate("Form", "\351\200\224\347\273\217\345\234\260", 0));
        label_3->setText(QApplication::translate("Form", "\357\274\210\345\246\202\346\234\211\345\244\232\344\270\252\351\200\224\347\273\217\345\234\260\350\257\267\347\224\250\347\251\272\346\240\274\351\232\224\345\274\200\357\274\211", 0));
        lineEditTransfer->setText(QString());
        label_5->setText(QApplication::translate("Form", "\345\275\223\345\211\215\344\275\215\347\275\256\357\274\232", 0));
        pushButton->setText(QApplication::translate("Form", "Map", 0));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H
