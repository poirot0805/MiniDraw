/********************************************************************************
** Form generated from reading UI file 'paintcontroller.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAINTCONTROLLER_H
#define UI_PAINTCONTROLLER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PaintController
{
public:

    void setupUi(QWidget *PaintController)
    {
        if (PaintController->objectName().isEmpty())
            PaintController->setObjectName(QString::fromUtf8("PaintController"));
        PaintController->resize(400, 300);

        retranslateUi(PaintController);

        QMetaObject::connectSlotsByName(PaintController);
    } // setupUi

    void retranslateUi(QWidget *PaintController)
    {
        PaintController->setWindowTitle(QCoreApplication::translate("PaintController", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PaintController: public Ui_PaintController {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAINTCONTROLLER_H
