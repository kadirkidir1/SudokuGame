#include "randomgenerate.h"
#include <QRandomGenerator>
#include <QDebug>
#include <random>

randomGenerate::randomGenerate(QObject *parent)
    : QObject{parent}
{
}

QVector<QVector<int>> randomGenerate::getGrid()
{
    QVector<QVector<int>> grid = QVector<QVector<int>>(9, QVector<int>(9, 0));
    fillSudoku(grid);
    printGrid(grid);
    return grid;
}

bool randomGenerate::isValid(QVector<QVector<int>>& grid, int row, int col, int num)
{
    for (int x = 0; x < 9; ++x) {
        if (grid[row][x] == num || grid[x][col] == num)
            return false;
    }

    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (grid[startRow + i][startCol + j] == num)
                return false;
        }
    }

    return true;
}

bool randomGenerate::fillSudoku(QVector<QVector<int>>& grid)
{
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            if (grid[row][col] == 0) {
                QVector<int> numbers {1, 2, 3, 4, 5, 6, 7, 8, 9};

                std::random_device rd;
                std::mt19937 rng(rd());
                std::shuffle(numbers.begin(), numbers.end(), rng);

                for (int num : numbers) {
                    if (isValid(grid, row, col, num)) {
                        grid[row][col] = num;
                        if (fillSudoku(grid))
                            return true;
                        grid[row][col] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void randomGenerate::removeCells(QVector<QVector<int>>& grid, common_usage::Difficulty difficulty) {
    int cellsToRemove = 0;
    switch (difficulty) {
    case common_usage::Difficulty::Easy: cellsToRemove = 30; break;
    case common_usage::Difficulty::Medium: cellsToRemove = 40; break;
    case common_usage::Difficulty::Hard: cellsToRemove = 50; break;
    case common_usage::Difficulty::Expert: cellsToRemove = 60; break;
    }

    int cellsPerBlock = cellsToRemove / 9;
    int remainingCells = cellsToRemove % 9;

    for (int blockRow = 0; blockRow < 3; ++blockRow) {
        for (int blockCol = 0; blockCol < 3; ++blockCol) {
            int cellsToRemoveInBlock = cellsPerBlock + (remainingCells-- > 0 ? 1 : 0);
            removeCellsInBlock(grid, blockRow, blockCol, cellsToRemoveInBlock);
        }
    }
}

void randomGenerate::removeCellsInBlock(QVector<QVector<int>>& grid, int blockRow, int blockCol, int cellsToRemove) {
    int removed = 0;
    while (removed < cellsToRemove) {
        int row = blockRow * 3 + QRandomGenerator::global()->bounded(3);
        int col = blockCol * 3 + QRandomGenerator::global()->bounded(3);
        if (grid[row][col] != 0) {
            grid[row][col] = 0;
            ++removed;
        }
    }
}

void randomGenerate::printGrid(const QVector<QVector<int>>& grid)
{
    for (const auto& row : grid) {
        QString rowString;
        for (int num : row) {
            rowString += QString::number(num) + " ";
        }
        qDebug() << rowString.trimmed();
    }
}
