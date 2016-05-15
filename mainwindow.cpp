#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTimer>
#include <QKeyEvent>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    score = 0;
    time = 0;
    initX = 500;
    endX = -50;
    y = 90;
    R = 0;
    size = 50;
    ui->start->show();
    ui->background->hide();
    ui->reScene->hide();
    ui->StartButton->show();
    ui->ExitButton->show();
    ui->timerText->hide();
    ui->timerNum->hide();
    ui->scoreText->hide();
    ui->scoreNum->hide();
    ui->drum_0->hide();
    ui->drum_1->hide();
    ui->drum_2->hide();
    ui->drum_3->hide();
    ui->drum_4->hide();
    ui->drum_5->hide();
    ui->drum_6->hide();
    ui->drum_7->hide();
    for(int i=0; i<8; i++)
    {
        Index[i]=1;
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
    ui->drum_0->show();
    ui->drum_1->show();
    ui->drum_2->show();
    ui->drum_3->show();
    ui->drum_4->show();
    ui->drum_5->show();
    ui->drum_6->show();
    ui->drum_7->show();
    ui->drum_0->setGeometry(initX,y,size,size);
    ui->drum_1->setGeometry(initX,y,size,size);
    ui->drum_2->setGeometry(initX,y,size,size);
    ui->drum_3->setGeometry(initX,y,size,size);
    ui->drum_4->setGeometry(initX,y,size,size);
    ui->drum_5->setGeometry(initX,y,size,size);
    ui->drum_6->setGeometry(initX,y,size,size);
    ui->drum_7->setGeometry(initX,y,size,size);

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

        timer->stop();
        ui->background->hide();
        ui->reScene->show();
        ui->StartButton->show();
        ui->ExitButton->show();
        ui->drum_0->hide();
        ui->drum_1->hide();
        ui->drum_2->hide();
        ui->drum_3->hide();
        ui->drum_4->hide();
        ui->drum_5->hide();
        ui->drum_6->hide();
        ui->drum_7->hide();
        ui->drum_0->setGeometry(initX,y,size,size);
        ui->drum_1->setGeometry(initX,y,size,size);
        ui->drum_2->setGeometry(initX,y,size,size);
        ui->drum_3->setGeometry(initX,y,size,size);
        ui->drum_4->setGeometry(initX,y,size,size);
        ui->drum_5->setGeometry(initX,y,size,size);
        ui->drum_6->setGeometry(initX,y,size,size);
        ui->drum_7->setGeometry(initX,y,size,size);

        /*for(int i=0; i<5; i++)
        {
            graphIndex[i]=1;
            correct[i]=false;
        }
        for(int i=5; i<9; i++)
        {
            graphIndex[i]=2;
            correct[i]=false;
        }*/


        drumTimer_0->stop();
        drumTimer_1->stop();
        drumTimer_2->stop();
        drumTimer_3->stop();
        drumTimer_4->stop();
        drumTimer_5->stop();
        drumTimer_6->stop();
        drumTimer_7->stop();
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_F )
    {
        if(ui->drum_0->x()<=25 || ui->drum_0->x()>=0)
        {
            ui->drum_0->hide();
            score++;
            ui->scoreNum->setText(QString::number(score));

        }
        else if(ui->drum_1->x()<=25 || ui->drum_1->x()>=0)
        {
            ui->drum_1->hide();
            score++;
            ui->scoreNum->setText(QString::number(score));
        }
        else if(ui->drum_2->x()<=25 || ui->drum_2->x()>=0)
        {
            ui->drum_2->hide();
            score++;
            ui->scoreNum->setText(QString::number(score));
        }
        else if(ui->drum_3->x()<=25 || ui->drum_3->x()>=0)
        {
            ui->drum_3->hide();
            score++;
            ui->scoreNum->setText(QString::number(score));
        }

    }
    else if(event->key() == Qt::Key_J)
    {

        if(ui->drum_4->x()<=25 || ui->drum_4->x()>=0)
        {
            ui->drum_4->hide();
            score++;
            ui->scoreNum->setText(QString::number(score));
        }
        else if(ui->drum_5->x()<=25 || ui->drum_5->x()>=0)
        {
            ui->drum_5->hide();
            score++;
            ui->scoreNum->setText(QString::number(score));

        }
        else if(ui->drum_6->x()<=25 || ui->drum_6->x()>=0)
        {
            ui->drum_6->hide();
            score++;
            ui->scoreNum->setText(QString::number(score));
        }
        else if(ui->drum_7->x()<=25 || ui->drum_7->x()>=0)
        {
            ui->drum_7->hide();
            score++;
            ui->scoreNum->setText(QString::number(score));
        }
    }
}

/*void MainWindow::drum()
{
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());

    qrand();
    if(qrand()%8==0)
    {
        Index[i]=1;
    }
    else if(qrand()%8==1)
    {
        Index[i]=1;
    }
    else if(qrand()%8==2)
    {
        Index[i]=1;
    }
    else if(qrand()%8==3)
    {
        Index[i]=1;
    }
    else if(qrand()%8==4)
    {
        Index[i]=1;
    }
    else if(qrand()%8==5)
    {
        Index[i]=1;
    }
    else if(qrand()%8==6)
    {
        Index[i]=1;
    }
    else if(qrand()%8==7)
    {
        Index[i]=1;
    }

}*/


/*void MainWindow::animaMove()
{
    for(int i=0; i<9; i++)
    {
        arrayX[i]=arrayX[i]-step;
        item[i]->setPos(arrayX[i],90);
    }
    if(arrayX[8]<(-50))
    {
        drum();
    }
}*/
