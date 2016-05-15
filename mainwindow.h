#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QTimer>
#include <QKeyEvent>
#include <QTime>


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
    void on_StartButton_clicked();

    void timer_timeout();

    void on_ExitButton_clicked();

    void drum();

    void keyPressEvent(QKeyEvent *event);

private:
    Ui::MainWindow *ui;

    int time;
    int score;
    int initX;
    int endX;
    int y;
    int R;
    int size;
    int Index[8];
    /*int arrayX[9];
    bool correct[9];
    QGraphicsPixmapItem *item[9];*/

    const int step = 1;
    //int x;
    QTimer *timer;
    QTimer *drumTimer_0;
    QTimer *drumTimer_1;
    QTimer *drumTimer_2;
    QTimer *drumTimer_3;
    QTimer *drumTimer_4;
    QTimer *drumTimer_5;
    QTimer *drumTimer_6;
    QTimer *drumTimer_7;
};

#endif // MAINWINDOW_H
