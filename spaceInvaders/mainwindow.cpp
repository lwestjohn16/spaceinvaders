#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    score = 0;
    lives = 3;
    for(int i = 0; i < 11; i++){
        for(int j = 0; j < 5; j++){
            rhynoc[i][j] = new enemy((i*50),(j*50));
            if(i == 0)
            {
                rhynoc[i][j].value = 30;
            }
            else if((i == 1) || (i == 2))
            {
                rhynoc[i][j].value = 20;
            }
            else if((i == 3) || (i == 4))
            {
                rhynoc[i][j].value = 10;
            }
        }
    }
    music= new QMediaPlayer();
    QMediaPlaylist *playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("qrc:/sound/alpineRidge.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);
    music->setPlaylist(playlist);
    timer = new QTimer();
    timer->setInterval(50);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_close_clicked()
{
    close();
}


void MainWindow::on_start_clicked()
{
    ui->start->hide();
    ui->controls->hide();
    ui->close->hide();
    ui->title->hide();
    ui->description->hide();
    gameOver = false;
    score = 0;
    music->play();
    timer->start();
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 11; j++)
        {
            if(i == 0)
            {
                painter.drawImage(rhynoc[i][j].rect, (QUrl("qrc:/image/leprechaun.png")));
            }
            else if((i == 1) || (i == 2))
            {
                painter.drawImage(rhynoc[i][j].rect, (QUrl("qrc:/image/barrelRhynoc.png")));
            }
            else if((i == 3) || (i == 4))
            {
                painter.drawImage(rhynoc[i][j].rect, (QUrl("qrc:/image/pirate.png")));
            }
        }
    }
    painter.drawImage(spyro->rect, (QUrl("qrc:/image/spyro.png")));
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(this->key() == Qt::Key_Right || this->key() == Qt::Key_D)
    {
        spyro->moveRight();
    }
    if(this->key() == Qt:: Key_Left || this->key() == Qt:: Key_A)
    {

    }
}
