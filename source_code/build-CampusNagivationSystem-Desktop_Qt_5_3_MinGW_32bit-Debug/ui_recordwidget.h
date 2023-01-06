/********************************************************************************
** Form generated from reading UI file 'recordwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECORDWIDGET_H
#define UI_RECORDWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RecordWidget
{
public:
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButtonClean;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QTextEdit *textEdit;

    void setupUi(QWidget *RecordWidget)
    {
        if (RecordWidget->objectName().isEmpty())
            RecordWidget->setObjectName(QStringLiteral("RecordWidget"));
        RecordWidget->resize(752, 466);
        widget_2 = new QWidget(RecordWidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(620, 410, 115, 50));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButtonClean = new QPushButton(widget_2);
        pushButtonClean->setObjectName(QStringLiteral("pushButtonClean"));

        horizontalLayout_2->addWidget(pushButtonClean);

        widget = new QWidget(RecordWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(480, 410, 115, 50));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        textEdit = new QTextEdit(RecordWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(40, 10, 681, 391));
        textEdit->setReadOnly(true);

        retranslateUi(RecordWidget);

        QMetaObject::connectSlotsByName(RecordWidget);
    } // setupUi

    void retranslateUi(QWidget *RecordWidget)
    {
        RecordWidget->setWindowTitle(QApplication::translate("RecordWidget", "Form", 0));
        pushButtonClean->setText(QApplication::translate("RecordWidget", "\345\210\240\351\231\244\346\227\245\345\277\227", 0));
        pushButton->setText(QApplication::translate("RecordWidget", "\345\210\267\346\226\260", 0));
    } // retranslateUi

};

namespace Ui {
    class RecordWidget: public Ui_RecordWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECORDWIDGET_H
