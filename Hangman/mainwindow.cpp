#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QKeyEvent>
#include <iostream>

#include "QString"

#include<QVector>

//using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    refreshWord();

    refreshNumberofFailures();


    //ui->background->setPixmap(QPixmap(QString::fromUtf8(":/backgrounds/Hangman12.png")));
}

void MainWindow::keyPressEvent(QKeyEvent *event)//QKeyEvent *i
{

    QString input = event->text().toUpper();

    refreshWord();

    refreshNumberofFailures();

    if(!input.isEmpty()){

        keyStrokes.append(input);

        std::cout << "Taste wurde gedrueckt: "
                  << input.toStdString()
                  << std::endl;

    }
}

int MainWindow:: getNumberofFailures(){

    int numberOfFailures = 0;

    for(QString key : keyStrokes){

        if(!toGuess.contains(key.at(0))){

            numberOfFailures++;
        }
    }
    return numberOfFailures;
}

void MainWindow::refreshNumberofFailures(){

    int numberOfFailures = getNumberofFailures();

    ui->numberOfFailures->setText(QString::number(numberOfFailures));


    QVector<QString> images ={

        ":/backgrounds/Hangman01.png",
        ":/backgrounds/Hangman02.png",
        ":/backgrounds/Hangman03.png",
        ":/backgrounds/Hangman04.png",
        ":/backgrounds/Hangman05.png",
        ":/backgrounds/Hangman06.png",
        ":/backgrounds/Hangman07.png",
        ":/backgrounds/Hangman08.png",
        ":/backgrounds/Hangman09.png",
        ":/backgrounds/Hangman10.png",
        ":/backgrounds/Hangman11.png",
        ":/backgrounds/Hangman12.png"
    };

    ui->background->setPixmap(QPixmap(images[numberOfFailures]));
}

void MainWindow::refreshWord(){

    QString output = "";

    for(int i = 0 ; i < toGuess.size(); ++i){

        if (i !=0){

            output += " ";
        }

        //keyStrokes = {"M"}

        if(keyStrokes.contains(QString(toGuess[i]))){

            output+=toGuess[i];

        }
        else{

            output += "_";

        }

    }

    ui->word->setText(output);

}

MainWindow::~MainWindow()
{
    delete ui;
}

