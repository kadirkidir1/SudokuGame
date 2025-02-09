#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H

#include <QObject>
#include <QWidget>
#include <QStackedWidget>
#include "mainmenu.h"
#include "sudokutable.h"

class screenManager : public QWidget
{
    Q_OBJECT
public:
    explicit screenManager(QWidget *parent = nullptr);

signals:

private slots:
    void openMainMenuScreen();
    void openSudokuScreen();
private:
    void createSudokuTable();
    QStackedWidget* m_stackedWidget;
    void insertWidgetToStacked();
    void allocateMemory();
    void setSignalSlotConnectionBetweenScreens();
    mainMenu* m_mainMenu;
    sudokuTable* m_sudokuTable;

    enum Screens{
        e_mainScreen = 0,
        e_sudokuTableScreen,
        e_ScreenMax
    };

    Screens lastScreenIndex;

};

#endif // SCREENMANAGER_H
