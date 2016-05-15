#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTimer>
#include <QKeyEvent>
#include <QGraphicsView>
#include <QPropertyAnimation>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsSimpleTextItem>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    score = 0;
    time = 0;
    initX = 500;
    //x = 500;
    endX = -50;
    R=0;
    for(int i=0; i<9; i++)
    {
        arrayX[i]=0;
        graphIndex[i]=0;
        item[i]=0;
        correct[i]=false;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_StartButton_clicked()
{
    ui->start->hide();
    ui->StartButton->hide();
    ui->ExitButton->hide();
    ui->background->show();
    ui->timerText->show();
    ui->timerNum->show();
    ui->scoreText->show();
    ui->scoreNum->show();
    ui->reScene->hide();

    time = 30;
    score = 0;
    timer = new QTimer(this);
    timer->setInterval(1000);
    timer->start();
    connect(timer, SIGNAL(timeout()), this, SLOT(timer_timeout()));

    //drum();

    /*drumTimer = new QTimer(this);
    drumTimer->setInterval(10);
    drumTimer->start();
    connect(timer, SIGNAL(timeout()), this, SLOT(animaMove()));*/

}

void MainWindow::on_ExitButton_clicked()
{
    close();
}

void MainWindow::timer_timeout()
{
    ui->timerNum->setText(QString::number(time));
    time--;
    if(time<0)
    {

        ui->background->hide();
        ui->reScene->show();
        ui->StartButton->show();
        ui->ExitButton->show();
        timer->stop();
        //drumTimer->stop();
    }
}

void MainWindow::keyPressEvent(QKeyEvent * event)
{
    if(event->key() == Qt::Key_F )
    {
        if(graphIndex[0]==1 || correct[0]==false || arrayX[0]<=15 || arrayX[0]>=0)
        {
            correct[0]=true;
            score++;
        }
        else if(graphIndex[1]==1 || correct[1]==false || arrayX[1]<=15 || arrayX[1]>=0)
        {
            correct[1]=true;
            score++;
        }
        else if(graphIndex[2]==1 || correct[2]==false || arrayX[2]<=15 || arrayX[2]>=0)
        {
            correct[2]=true;
            score++;
        }
        else if(graphIndex[3]==1 || correct[3]==false || arrayX[3]<=15 || arrayX[3]>=0)
        {
            correct[3]=true;
            score++;
        }
        else if(graphIndex[4]==1 || correct[4]==false || arrayX[4]<=15 || arrayX[4]>=0)
        {
            correct[4]=true;
            score++;
        }
        else if(graphIndex[5]==1 || correct[5]==false || arrayX[5]<=15 || arrayX[5]>=0)
        {
            correct[5]=true;
            score++;
        }
        else if(graphIndex[6]==1 || correct[6]==false || arrayX[6]<=15 || arrayX[6]>=0)
        {
            correct[6]=true;
            score++;
        }
        else if(graphIndex[7]==1 || correct[7]==false || arrayX[7]<=15 || arrayX[7]>=0)
        {
            correct[7]=true;
            score++;
        }
        else if(graphIndex[8]==1 || correct[8]==false || arrayX[8]<=15 || arrayX[8]>=0)
        {
            correct[8]=true;
            score++;
        }
    }
    else if(event->key() == Qt::Key_J)
    {
        if(graphIndex[0]==2 || correct[0]==false || arrayX[0]<=15 || arrayX[0]>=0)
        {
            correct[0]=true;
            score++;
        }
        else if(graphIndex[1]==2 || correct[1]==false || arrayX[1]<=15 || arrayX[1]>=0)
        {
            correct[1]=true;
            score++;
        }
        else if(graphIndex[2]==2 || correct[2]==false || arrayX[2]<=15 || arrayX[2]>=0)
        {
            correct[2]=true;
            score++;
        }
        else if(graphIndex[3]==2 || correct[3]==false || arrayX[3]<=15 || arrayX[3]>=0)
        {
            correct[3]=true;
            score++;
        }
        else if(graphIndex[4]==2 || correct[4]==false || arrayX[4]<=15 || arrayX[4]>=0)
        {
            correct[4]=true;
            score++;
        }
        else if(graphIndex[5]==2 || correct[5]==false || arrayX[5]<=15 || arrayX[5]>=0)
        {
            correct[5]=true;
            score++;
        }
        else if(graphIndex[6]==2 || correct[6]==false || arrayX[6]<=15 || arrayX[6]>=0)
        {
            correct[6]=true;
            score++;
        }
        else if(graphIndex[7]==2 || correct[7]==false || arrayX[7]<=15 || arrayX[7]>=0)
        {
            correct[7]=true;
            score++;
        }
        else if(graphIndex[8]==2 || correct[8]==false || arrayX[8]<=15 || arrayX[8]>=0)
        {
            correct[8]=true;
            score++;
        }
    }
}

void MainWindow::drum()
{
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());
    /*arrayX[0]=500;
    for(int i=1; i<9; i++)
    {
        qrand();
        arrayX[i]=arrayX[i-1]+100+R%200;
        correct[i]=false;
    }
    for(int i=0; i<9; i++)
    {
        qrand();
        if(qrand()%2==1)
        {
            item[i] = new QGraphicsPixmapItem(QPixmap(":/pictures/紅鼓.png"));
            graphIndex[i]=1;
        }
        else if(qrand()%2==0)
        {
            item[i] = new QGraphicsPixmapItem(QPixmap(":/pictures/藍鼓.png"));
            graphIndex[i]=2;
        }
        item[i]->setScale(1.0);
        item[i]->setPos(arrayX[i],90);
    }*/

}


void MainWindow::animaMove()
{
    /*for(int i=0; i<9; i++)
    {
        arrayX[i]=arrayX[i]-step;
        item[i]->setPos(arrayX[i],90);
    }
    if(arrayX[8]<(-50))
    {
        drum();
    }*/
}
