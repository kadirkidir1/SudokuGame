#ifndef RANDOMGENERATE_H
#define RANDOMGENERATE_H

#include <QObject>
#include <QRandomGenerator>
#include <QVector>
#include "common_usage.h"

class randomGenerate : public QObject
{
    Q_OBJECT
public:
    explicit randomGenerate(QObject *parent = nullptr);
    static QVector<QVector<int>> getGrid();
    static void removeCells(QVector<QVector<int> > &grid, common_usage::Difficulty diff);

signals:
    void sig_createRandomNumbers();

private:

    static void removeCellsInBlock(QVector<QVector<int> > &grid, int blockRow, int blockCol, int cellsToRemove);
private slots:
    static bool fillSudoku(QVector<QVector<int>> &grid);
    static bool isValid(QVector<QVector<int>> &grid, int row, int col, int num);
    static void printGrid(const QVector<QVector<int> > &grid);
};

#endif // RANDOMGENERATE_H
