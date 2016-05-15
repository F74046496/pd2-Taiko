#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QTimer>
#include <QKeyEvent>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPropertyAnimation>
#include <QGraphicsPixmapItem>
#include <QGraphicsSimpleTextItem>
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

    void drum();

private slots:
    void on_StartButton_clicked();

    void timer_timeout();

    void on_ExitButton_clicked();

    void animaMove();

    void keyPressEvent(QKeyEvent * event);

private:
    Ui::MainWindow *ui;

    int time;
    int score;
    int initX;
    int endX;
    int R;
    int arrayX[9];
    int graphIndex[9];
    bool correct[9];
    QGraphicsPixmapItem *item[9];

    const int step = 1;
    //int x;
    QTimer *timer;
    QTimer *drumTimer;
};

#endif // MAINWINDOW_H
