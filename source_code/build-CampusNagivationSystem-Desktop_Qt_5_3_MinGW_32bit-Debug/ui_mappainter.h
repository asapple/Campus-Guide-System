/********************************************************************************
** Form generated from reading UI file 'mappainter.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAPPAINTER_H
#define UI_MAPPAINTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MapPainter
{
public:

    void setupUi(QWidget *MapPainter)
    {
        if (MapPainter->objectName().isEmpty())
            MapPainter->setObjectName(QStringLiteral("MapPainter"));
        MapPainter->resize(400, 300);

        retranslateUi(MapPainter);

        QMetaObject::connectSlotsByName(MapPainter);
    } // setupUi

    void retranslateUi(QWidget *MapPainter)
    {
        MapPainter->setWindowTitle(QApplication::translate("MapPainter", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class MapPainter: public Ui_MapPainter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAPPAINTER_H
