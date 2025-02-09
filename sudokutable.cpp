#include "sudokutable.h"
#include "ui_sudokutable.h"
#include "randomgenerate.h"
#include <QQmlContext>
#include <QQmlEngine>
#include <QtQuickWidgets/QtQuickWidgets>
#include <qqml.h>
#include <QAbstractTableModel>

sudokuTable& sudokuTable::getInstance()
{
    static sudokuTable instance;
    return instance;
}

sudokuTable::sudokuTable(QWidget *parent)
    : QMainWindow(parent) ,
    ui(new Ui::sudokuTable),
    errorCounter(0)
{
    ui->setupUi(this);

    ui->quickWidget->engine()->rootContext()->setContextProperty("sudokuTable", this);
    ui->quickWidget->setSource(QUrl("qrc:/sudokuTable.qml"));
    ui->quickWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);

    connect(this,
            SIGNAL(atOpenMainMenuBackPressedKey()),
            this,
            SLOT(returnMainMenuFromBackPressedKey()));

    connect(this,
            SIGNAL(cellSelected(int,int,int)),
            this,
            SLOT(onCellSelected(int,int,int)));
}

QVector<QVector<int>> sudokuTable::getGrid() const
{
    return grid;
}

void sudokuTable::onCellSelected(const int row, const int col, const int number)
{
    if(row == -1 || col == -1)
        return;

    if(number == 0)
        clearCellMechanism(row,col);
    else if(number == goalGrid.at(row).at(col)) {
        grid[row][col] = number;
        emit gridChanged();
        controlGameStatus();
    } else
        increaseErrorCounter();
}

void sudokuTable::increaseErrorCounter()
{
    errorCounter++;

    if(errorCounter >= 3)
        gameOver();
    else
        emit sigErrorCount();
}

int sudokuTable::m_errorCounter()
{
    return errorCounter;
}

void sudokuTable::onChoosenDifficulty(const common_usage::Difficulty &diff)
{
    this->errorCounter = 0;
    grid.clear();
    grid = randomGenerate::getGrid();
    goalGrid = grid;
    randomGenerate::removeCells(grid,diff);
    startGrid = grid;

    emit gameStatus(true);
    emit sigErrorCount();
    emit gridChanged();
    atOpenSudokuScreen();
}

void sudokuTable::returnMainMenuFromBackPressedKey()
{
    emit gameStatus(true);
    emit atOpenMainMenu();
}

void sudokuTable::clearCellMechanism(const int row, const int col)
{
    if(grid.at(row).at(col) != 0)
        if(startGrid.at(row).at(col) == 0) {
            grid[row][col] = 0;
            emit gridChanged();
        }
}

void sudokuTable::controlGameStatus()
{
    bool gameFinished = true;
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            if (grid[row][col] == 0)
                gameFinished = false;
        }
    }

    if(gameFinished) {
        emit gameStatus(false);
        emit gameCompleted();
    }
}

void sudokuTable::gameOver()
{
    emit gameStatus(false);
    emit showGameOverPopup();
}

sudokuTable::~sudokuTable()
{
    delete ui;
}


