/********************************************************************************
** Form generated from reading UI file 'sudokutable.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUDOKUTABLE_H
#define UI_SUDOKUTABLE_H

#include <QtCore/QVariant>
#include <QtQuickWidgets/QQuickWidget>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_sudokuTable
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QQuickWidget *quickWidget;

    void setupUi(QMainWindow *sudokuTable)
    {
        if (sudokuTable->objectName().isEmpty())
            sudokuTable->setObjectName("sudokuTable");
        sudokuTable->resize(844, 582);
        sudokuTable->setMinimumSize(QSize(0, 0));
        sudokuTable->setMaximumSize(QSize(1440, 3120));
        centralwidget = new QWidget(sudokuTable);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setMaximumSize(QSize(1440, 3120));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        quickWidget = new QQuickWidget(centralwidget);
        quickWidget->setObjectName("quickWidget");
        quickWidget->setResizeMode(QQuickWidget::ResizeMode::SizeRootObjectToView);

        verticalLayout->addWidget(quickWidget);

        sudokuTable->setCentralWidget(centralwidget);

        retranslateUi(sudokuTable);

        QMetaObject::connectSlotsByName(sudokuTable);
    } // setupUi

    void retranslateUi(QMainWindow *sudokuTable)
    {
        sudokuTable->setWindowTitle(QCoreApplication::translate("sudokuTable", "sudokuTable", nullptr));
    } // retranslateUi

};

namespace Ui {
    class sudokuTable: public Ui_sudokuTable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUDOKUTABLE_H
