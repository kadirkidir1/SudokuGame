#include "screenmanager.h"
#include "mainmenu.h"
#include "sudokutable.h"
#include <QStackedWidget>
#include <QVBoxLayout>

screenManager::screenManager(QWidget *parent)
    : QWidget{parent}
{
    m_stackedWidget = new QStackedWidget(this);
    allocateMemory();
    insertWidgetToStacked();
    setSignalSlotConnectionBetweenScreens();
}

void screenManager::createSudokuTable()
{
    m_sudokuTable = &sudokuTable::getInstance();
}

void screenManager::insertWidgetToStacked()
{
    QVBoxLayout* vbox = new QVBoxLayout(this);
    vbox->addWidget(m_stackedWidget);

    m_stackedWidget->insertWidget(e_mainScreen, m_mainMenu);
    m_stackedWidget->insertWidget(e_sudokuTableScreen, m_sudokuTable);
}

void screenManager::allocateMemory()
{
    createSudokuTable();
    m_mainMenu = new mainMenu;
}

void screenManager::setSignalSlotConnectionBetweenScreens()
{
    connect(m_mainMenu,
            SIGNAL(atChoosenDifficulty(common_usage::Difficulty)),
            m_sudokuTable,
            SLOT(onChoosenDifficulty(common_usage::Difficulty)));

    connect(m_sudokuTable,
            SIGNAL(atOpenSudokuScreen()),
            this,
            SLOT(openSudokuScreen()));

    connect(m_sudokuTable,
            SIGNAL(atOpenMainMenu()),
            this,
            SLOT(openMainMenuScreen()));

    connect(m_mainMenu,
            SIGNAL(atOpenGameScreen()),
            this,
            SLOT(openSudokuScreen()));

    connect(m_sudokuTable,
            SIGNAL(gameStatus(bool)),
            m_mainMenu,
            SLOT(onGameStatus(bool)));
}

void screenManager::openMainMenuScreen()
{
    lastScreenIndex = static_cast<Screens>(m_stackedWidget->currentIndex());
    m_stackedWidget->setCurrentIndex(e_mainScreen);
}

void screenManager::openSudokuScreen()
{
    lastScreenIndex = static_cast<Screens>(m_stackedWidget->currentIndex());
    m_stackedWidget->setCurrentIndex(e_sudokuTableScreen);
}
