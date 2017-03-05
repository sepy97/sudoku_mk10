#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <iterator> // заголовочный файл итераторов
#include <assert.h>
#include <ctime>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_newButton_clicked();

    void pushButton (int num);

    void on_oneButton_clicked();

    void on_twoButton_clicked();

    void on_threeButton_clicked();

    void on_fourButton_clicked();

    void on_fiveButton_clicked();

    void on_sixButton_clicked();

    void on_sevenButton_clicked();

    void on_eightButton_clicked();

    void on_nineButton_clicked();

    void on_clearButton_clicked();

    void on_checkButton_clicked();

    void on_hintButton_clicked();

    void on_sudokuWidget_doubleClicked(const QModelIndex &index);

    void on_hardLevelSlider_valueChanged(int value);

    void insertNumber (QString before, QString after);

    void insertNumber_16 (QString before, QString after);

    void pushButton_16 (int num);

    void on_oneButton_16_clicked();

    void on_twoButton_16_clicked();

    void on_threeButton_16_clicked();

    void on_fourButton_16_clicked();

    void on_fiveButton_16_clicked();

    void on_sixButton_16_clicked();

    void on_sevenButton_16_clicked();

    void on_eightButton_16_clicked();

    void on_nineButton_16_clicked();

    void on_tenButton_16_clicked();

    void on_elevenButton_16_clicked();

    void on_twelveButton_16_clicked();

    void on_thirteenButton_16_clicked();

    void on_fourteenButton_16_clicked();

    void on_fifteenButton_16_clicked();

    void on_sixteenButton_16_clicked();

    int  nineSudokuSave();

    int  nineSudokuLoad();

    int  sixteenSudokuSave();

    int  sixteenSudokuLoad();

    void on_saveButton_clicked();

    void on_loadButton_clicked();

    void on_newButton_pressed();

    void on_newButton_released();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
