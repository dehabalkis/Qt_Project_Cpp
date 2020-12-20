//DEHA

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QString>

#include <iostream>

#include <QKeyEvent>

#include<QVector>

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


protected:

    virtual void keyPressEvent(QKeyEvent *event);


private:
    Ui::MainWindow *ui;

    QString toGuess = "SICK AG";

    QVector<QString> keyStrokes;

    int getNumberofFailures();

    void refreshNumberofFailures();

    void refreshWord();

};
#endif // MAINWINDOW_H
