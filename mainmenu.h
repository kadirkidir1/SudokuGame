#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>
#include "common_usage.h"

namespace Ui {
class mainMenu;
}

class mainMenu : public QWidget
{
    Q_OBJECT

public:
    explicit mainMenu(QWidget *parent = nullptr);
    ~mainMenu();

private slots:
    void on_basicButton_clicked();
    void on_mediumButton_clicked();
    void on_hardButton_clicked();
    void on_expertButton_clicked();
    void onGameStatus(const bool& status);
    void on_returnGameButton_clicked();

private:
    Ui::mainMenu *ui;
    bool isGameStatus;
    void setReturnGameButton(const bool& status);

signals:
    void atChoosenDifficulty(const common_usage::Difficulty& diff);
    void atOpenGameScreen();
};

#endif // MAINMENU_H
