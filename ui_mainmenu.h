/********************************************************************************
** Form generated from reading UI file 'mainmenu.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINMENU_H
#define UI_MAINMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainMenu
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QPushButton *returnGameButton;
    QGridLayout *gridLayout;
    QPushButton *mediumButton;
    QPushButton *basicButton;
    QPushButton *expertButton;
    QPushButton *hardButton;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QLabel *label_2;

    void setupUi(QWidget *mainMenu)
    {
        if (mainMenu->objectName().isEmpty())
            mainMenu->setObjectName("mainMenu");
        mainMenu->resize(769, 686);
        verticalLayout_2 = new QVBoxLayout(mainMenu);
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(mainMenu);
        label->setObjectName("label");
        QFont font;
        font.setFamilies({QString::fromUtf8("Mallanna")});
        font.setPointSize(31);
        font.setBold(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(label);


        verticalLayout_2->addLayout(horizontalLayout);

        returnGameButton = new QPushButton(mainMenu);
        returnGameButton->setObjectName("returnGameButton");
        returnGameButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #333; \n"
"    color: #f8f8f8; \n"
"    font-size: 18px;\n"
"    font-weight: bold;\n"
"    border-radius: 10px;\n"
"    border: 2px solid #555;\n"
"    padding: 10px 20px; \n"
"    transition: all 0.3s ease-in-out;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #555; \n"
"    border: 2px solid #777; \n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #222; \n"
"    border: 2px solid #999; \n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: #777;\n"
"    color: #aaa;\n"
"    border: 2px solid #999;\n"
"}"));

        verticalLayout_2->addWidget(returnGameButton);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        mediumButton = new QPushButton(mainMenu);
        mediumButton->setObjectName("mediumButton");
        mediumButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #333; \n"
"    color: #f8f8f8; \n"
"    font-size: 18px;\n"
"    font-weight: bold;\n"
"    border-radius: 10px;\n"
"    border: 2px solid #555;\n"
"    padding: 10px 20px; \n"
"    transition: all 0.3s ease-in-out;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #555; \n"
"    border: 2px solid #777; \n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #222; \n"
"    border: 2px solid #999; \n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: #777;\n"
"    color: #aaa;\n"
"    border: 2px solid #999;\n"
"}"));

        gridLayout->addWidget(mediumButton, 0, 1, 1, 1);

        basicButton = new QPushButton(mainMenu);
        basicButton->setObjectName("basicButton");
        basicButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #333; \n"
"    color: #f8f8f8; \n"
"    font-size: 18px;\n"
"    font-weight: bold;\n"
"    border-radius: 10px;\n"
"    border: 2px solid #555;\n"
"    padding: 10px 20px; \n"
"    transition: all 0.3s ease-in-out;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #555; \n"
"    border: 2px solid #777; \n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #222; \n"
"    border: 2px solid #999; \n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: #777;\n"
"    color: #aaa;\n"
"    border: 2px solid #999;\n"
"}"));
        basicButton->setIconSize(QSize(17, 16));

        gridLayout->addWidget(basicButton, 0, 0, 1, 1);

        expertButton = new QPushButton(mainMenu);
        expertButton->setObjectName("expertButton");
        expertButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #333; \n"
"    color: #f8f8f8; \n"
"    font-size: 18px;\n"
"    font-weight: bold;\n"
"    border-radius: 10px;\n"
"    border: 2px solid #555;\n"
"    padding: 10px 20px; \n"
"    transition: all 0.3s ease-in-out;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #555; \n"
"    border: 2px solid #777; \n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #222; \n"
"    border: 2px solid #999; \n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: #777;\n"
"    color: #aaa;\n"
"    border: 2px solid #999;\n"
"}"));

        gridLayout->addWidget(expertButton, 1, 1, 1, 1);

        hardButton = new QPushButton(mainMenu);
        hardButton->setObjectName("hardButton");
        hardButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #333; \n"
"    color: #f8f8f8; \n"
"    font-size: 18px;\n"
"    font-weight: bold;\n"
"    border-radius: 10px;\n"
"    border: 2px solid #555;\n"
"    padding: 10px 20px; \n"
"    transition: all 0.3s ease-in-out;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #555; \n"
"    border: 2px solid #777; \n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #222; \n"
"    border: 2px solid #999; \n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: #777;\n"
"    color: #aaa;\n"
"    border: 2px solid #999;\n"
"}"));

        gridLayout->addWidget(hardButton, 1, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);

        verticalLayout->addItem(verticalSpacer);

        label_2 = new QLabel(mainMenu);
        label_2->setObjectName("label_2");
        QFont font1;
        font1.setPointSize(9);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignmentFlag::AlignBottom|Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft);

        verticalLayout->addWidget(label_2);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(mainMenu);

        QMetaObject::connectSlotsByName(mainMenu);
    } // setupUi

    void retranslateUi(QWidget *mainMenu)
    {
        mainMenu->setWindowTitle(QCoreApplication::translate("mainMenu", "Form", nullptr));
        label->setText(QCoreApplication::translate("mainMenu", "Sudoku", nullptr));
        returnGameButton->setText(QCoreApplication::translate("mainMenu", "Oyuna D\303\266n", nullptr));
        mediumButton->setText(QCoreApplication::translate("mainMenu", "Medium", nullptr));
        basicButton->setText(QCoreApplication::translate("mainMenu", "Basic", nullptr));
        expertButton->setText(QCoreApplication::translate("mainMenu", "Expert", nullptr));
        hardButton->setText(QCoreApplication::translate("mainMenu", "Hard", nullptr));
        label_2->setText(QCoreApplication::translate("mainMenu", "Version 1.0..0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainMenu: public Ui_mainMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENU_H
