#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QTimer>
#include <QPainter>
#include <QKeyEvent>
#include <QRect>
#include "bunker.h"
#include "enemy.h"
#include "player.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *event);

    void stopGame();
    bool checkCollision();
    void movePlayer();
    void resetEnemies();
    void gameIsOver();

private slots:
    void on_close_clicked();
    void on_start_clicked();
    void moveEnemy();
    void bulletFired();

private:
    Ui::MainWindow *ui;
    int score, lives, direction, bulletX, bulletY, shotFired, enemiesLeft;
    player *spyro;
    enemy *rhynoc[11][5];
    bunker *fort[12][3];
    bool gameOver, moveDown;
    QTimer *timer;
    QTimer *timer2;
    QMediaPlayer *music;
};

#endif // MAINWINDOW_H
