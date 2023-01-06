/********************************************************************************
** Form generated from reading UI file 'querywidget.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUERYWIDGET_H
#define UI_QUERYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QueryWidget
{
public:
    QGridLayout *gridLayout;
    QWidget *widget;
    QFormLayout *formLayout;
    QLabel *label;
    QTextEdit *textEditBuildings;
    QWidget *widget_2;
    QFormLayout *formLayout_3;
    QLabel *label_3;
    QTextEdit *textEditService;
    QPushButton *BtnReturn;
    QWidget *widget_3;
    QFormLayout *formLayout_2;
    QLabel *label_4;
    QLineEdit *lineEditFindService;
    QTextEdit *textEditFindService;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout;
    QLabel *label_5;
    QTextEdit *textEditServiceTransfer;

    void setupUi(QWidget *QueryWidget)
    {
        if (QueryWidget->objectName().isEmpty())
            QueryWidget->setObjectName(QStringLiteral("QueryWidget"));
        QueryWidget->resize(788, 466);
        QFont font;
        font.setFamily(QString::fromUtf8("\351\232\266\344\271\246"));
        font.setPointSize(11);
        QueryWidget->setFont(font);
        gridLayout = new QGridLayout(QueryWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        widget = new QWidget(QueryWidget);
        widget->setObjectName(QStringLiteral("widget"));
        formLayout = new QFormLayout(widget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        textEditBuildings = new QTextEdit(widget);
        textEditBuildings->setObjectName(QStringLiteral("textEditBuildings"));
        textEditBuildings->setReadOnly(true);

        formLayout->setWidget(1, QFormLayout::LabelRole, textEditBuildings);


        gridLayout->addWidget(widget, 0, 0, 1, 1);

        widget_2 = new QWidget(QueryWidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        formLayout_3 = new QFormLayout(widget_2);
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        label_3 = new QLabel(widget_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_3);

        textEditService = new QTextEdit(widget_2);
        textEditService->setObjectName(QStringLiteral("textEditService"));
        textEditService->setReadOnly(true);

        formLayout_3->setWidget(1, QFormLayout::LabelRole, textEditService);


        gridLayout->addWidget(widget_2, 1, 0, 1, 1);

        BtnReturn = new QPushButton(QueryWidget);
        BtnReturn->setObjectName(QStringLiteral("BtnReturn"));

        gridLayout->addWidget(BtnReturn, 2, 0, 1, 1);

        widget_3 = new QWidget(QueryWidget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        formLayout_2 = new QFormLayout(widget_3);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label_4 = new QLabel(widget_3);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_4);

        lineEditFindService = new QLineEdit(widget_3);
        lineEditFindService->setObjectName(QStringLiteral("lineEditFindService"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, lineEditFindService);

        textEditFindService = new QTextEdit(widget_3);
        textEditFindService->setObjectName(QStringLiteral("textEditFindService"));
        textEditFindService->setReadOnly(true);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, textEditFindService);


        gridLayout->addWidget(widget_3, 0, 1, 1, 1);

        widget_4 = new QWidget(QueryWidget);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        verticalLayout = new QVBoxLayout(widget_4);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_5 = new QLabel(widget_4);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout->addWidget(label_5);

        textEditServiceTransfer = new QTextEdit(widget_4);
        textEditServiceTransfer->setObjectName(QStringLiteral("textEditServiceTransfer"));
        textEditServiceTransfer->setReadOnly(true);

        verticalLayout->addWidget(textEditServiceTransfer);


        gridLayout->addWidget(widget_4, 1, 1, 1, 1);


        retranslateUi(QueryWidget);

        QMetaObject::connectSlotsByName(QueryWidget);
    } // setupUi

    void retranslateUi(QWidget *QueryWidget)
    {
        QueryWidget->setWindowTitle(QApplication::translate("QueryWidget", "Form", 0));
        label->setText(QApplication::translate("QueryWidget", "\345\221\250\350\276\271\345\273\272\347\255\221\347\211\251\357\274\232", 0));
        label_3->setText(QApplication::translate("QueryWidget", "\345\221\250\350\276\271\346\234\215\345\212\241\357\274\232", 0));
        BtnReturn->setText(QApplication::translate("QueryWidget", "\350\277\224\345\233\236", 0));
        label_4->setText(QApplication::translate("QueryWidget", "\346\234\215\345\212\241\346\237\245\350\257\242\357\274\232", 0));
        label_5->setText(QApplication::translate("QueryWidget", "\350\267\257\347\272\277\357\274\232", 0));
    } // retranslateUi

};

namespace Ui {
    class QueryWidget: public Ui_QueryWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUERYWIDGET_H
