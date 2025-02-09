#ifndef SUDOKUTABLE_H
#define SUDOKUTABLE_H

#include <QMainWindow>
#include "randomgenerate.h"
#include "common_usage.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class sudokuTable;
}
QT_END_NAMESPACE

class sudokuTable : public QMainWindow
{
    Q_OBJECT
    Q_PROPERTY(QVector<QVector<int>> getGrid READ getGrid NOTIFY gridChanged)
    Q_PROPERTY(int m_errorCounter READ m_errorCounter NOTIFY sigErrorCount)

public:
    static sudokuTable& getInstance();
    sudokuTable(QWidget *parent = nullptr);
    QVector<QVector<int> > getGrid() const;
    ~sudokuTable();

public slots:
    void onCellSelected(int row, int col, int number);
    void increaseErrorCounter();
    int m_errorCounter();

private slots:
    void onChoosenDifficulty(const common_usage::Difficulty& diff);
    void returnMainMenuFromBackPressedKey();
    void clearCellMechanism(const int row, const int col);
    void controlGameStatus();

private:
    Ui::sudokuTable *ui;
    randomGenerate sudokuVector;
    QVector<QVector<int>> grid;
    QVector<QVector<int>> goalGrid;
    QVector<QVector<int>> startGrid;
    int errorCounter;
    void gameOver();

signals:
    void gridChanged();
    void sigErrorCount();
    void sigGameOver();
    void cellSelected(const int row, const int col, const int number);
    void atOpenSudokuScreen();
    void atOpenMainMenu();
    void atOpenMainMenuBackPressedKey();
    void showGameOverPopup();
    void gameStatus(const bool& status);
    void gameCompleted();

};
#endif // SUDOKUTABLE_H
