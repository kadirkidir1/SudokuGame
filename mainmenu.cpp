#include "mainmenu.h"
#include "ui_mainmenu.h"

mainMenu::mainMenu(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::mainMenu)
    , isGameStatus(false)
{
    ui->setupUi(this);
    setReturnGameButton(isGameStatus);
}

mainMenu::~mainMenu()
{
    delete ui;
}

void mainMenu::on_basicButton_clicked()
{
    emit atChoosenDifficulty(common_usage::Difficulty::Easy);
}

void mainMenu::on_mediumButton_clicked()
{
    emit atChoosenDifficulty(common_usage::Difficulty::Medium);
}

void mainMenu::on_hardButton_clicked()
{
    emit atChoosenDifficulty(common_usage::Difficulty::Hard);
}

void mainMenu::on_expertButton_clicked()
{
    emit atChoosenDifficulty(common_usage::Difficulty::Expert);
}

void mainMenu::onGameStatus(const bool &status)
{
    isGameStatus = status;
    setReturnGameButton(isGameStatus);
}

void mainMenu::setReturnGameButton(const bool &status)
{
    ui->returnGameButton->setVisible(status);
}

void mainMenu::on_returnGameButton_clicked()
{
    emit atOpenGameScreen();
}

