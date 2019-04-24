#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    score = 0;
    lives = 3;
    direction = 0;
    moveDown = false;
    shotFired = 0;
    enemiesLeft = 55;
    shotFired = 0;
    bulletX = 1000;
    bulletY = 1000;
    for(int i = 0; i < 11; i++){
        for(int j = 0; j < 5; j++){
            rhynoc[i][j] = new enemy((i*50),((j*50)+50));
            rhynoc[i][j]->setDead(false);
            if(i == 0){
                rhynoc[i][j]->setValue(30);
            } else if((i == 1) || (i == 2)){
                rhynoc[i][j]->setValue(20);
            } else if((i == 3) || (i == 4)){
                rhynoc[i][j]->setValue(10);
            }
        }
    }
    spyro = new player();
    music= new QMediaPlayer();
    QMediaPlaylist *playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("qrc:/sound/alpineRidge.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);
    music->setPlaylist(playlist);
    timer = new QTimer();
    timer->setInterval(10);
    timer2 = new QTimer();
    timer2->setInterval(1000);
    connect(timer, SIGNAL(timeout()), this, SLOT(bulletFired()));
    connect(timer2, SIGNAL(timeout()), this, SLOT(moveEnemy()));
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_close_clicked(){
    close();
}


void MainWindow::on_start_clicked(){
    ui->start->hide();
    ui->controls->hide();
    ui->close->hide();
    ui->title->hide();
    ui->description->hide();
    gameOver = false;
    score = 0;
    music->play();
    timer->start();
    timer2->start();
}

void MainWindow::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    QPixmap lep(":/image/leprechaun.png");
    QPixmap barrel(":/image/barrelrhinoc.png");
    QPixmap pirate(":/image/pirate.png");
    QPixmap spy(":/image/spyro.png");\
    QPixmap bullet(":/image/fireball.png");
    for(int i = 0; i < 11; i++){
        for(int j = 0; j < 5; j++){
            if((j == 0) && (rhynoc[i][j]->getDead() == false)){
                painter.drawPixmap(rhynoc[i][j]->getX(), rhynoc[i][j]->getY(), 50, 50, lep);
            }else if(((j == 1) || (j == 2)) && (rhynoc[i][j]->getDead() == false)){
                painter.drawPixmap(rhynoc[i][j]->getX(), rhynoc[i][j]->getY(), 50, 50, barrel);
            }else if(((j == 3) || (j == 4)) && (rhynoc[i][j]->getDead() == false)){
                painter.drawPixmap(rhynoc[i][j]->getX(), rhynoc[i][j]->getY(), 50, 50, pirate);
            }
        }
    }
    painter.drawPixmap(spyro->getX(), spyro->getY(), 50, 50, spy);
    if(shotFired == 1){painter.drawPixmap(bulletX, bulletY, 25, 25, bullet);}
}

void MainWindow::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_Right || event->key() == Qt::Key_D){
        spyro->moveRight();
    } if(event->key() == Qt::Key_Left || event->key() == Qt::Key_A){
        spyro->moveLeft();
    } if(event->key() == Qt::Key_W){
        if(shotFired == 0){
            shotFired = 1;
            bulletX = spyro->getX()+12;
            bulletY = spyro->getY()+25;
        }
    }
}

void MainWindow::moveEnemy(){
    for(int i = 0; i < 11; i++){
        for(int j = 0; j < 5; j++){
            if(rhynoc[i][j]->getDead() == false && rhynoc[i][j]->getX()+50 >= this->width() && direction == 0){
                moveDown = true;
            } else if(rhynoc[i][j]->getDead() == false && rhynoc[i][j]->getX() <= 0 && direction == 1){
                moveDown = true;
            } else{
                moveDown = false;
            }
        }
    }
    if(direction == 0){
        for(int i = 0; i < 11; i++){
            for(int j = 0; j < 5; j++){
                if(moveDown == true){
                    rhynoc[i][j]->moveY(50);
                    direction = 1;
                } else{
                    rhynoc[i][j]->moveX(50);
                }
            }
        }
    } else if(direction == 1){
        for(int i = 0; i < 11; i++){
            for(int j = 0; j < 5; j++){
                if(moveDown == true){
                    rhynoc[i][j]->moveY(50);
                    direction = 0;
                } else{
                    rhynoc[i][j]->moveX(-50);
                }
            }
        }
    }
    update();
}

bool MainWindow::checkCollision(){
    for(int i = 0; i < 11; i++){
        for(int j = 0; j < 5; j++){
            if((bulletY >= rhynoc[i][j]->getY()) || (bulletY <= rhynoc[i][j]->getY()+50) ||
                        (bulletY+25 >= rhynoc[i][j]->getY()) || (bulletY+25 <= rhynoc[i][j]->getY()+50)){
                if((bulletX >= rhynoc[i][j]->getX()) || (bulletX <= rhynoc[i][j]->getX()+50) ||
                            (bulletX+25 >= rhynoc[i][j]->getX()) || (bulletX+25 <= rhynoc[i][j]->getX()+50)){
                    rhynoc[i][j]->setDead(true);
                    enemiesLeft -= 1;
                    score += rhynoc[i][j]->getValue();
                    return true;
                }
            }
        }
    }
    return false;
}

void MainWindow::bulletFired(){
    if(checkCollision()){
        shotFired = 0;
        if(enemiesLeft == 0){
            resetEnemies();
        }
        bulletX = 1000;
        bulletY = 1000;
    } else if(bulletY < 0){
        shotFired = 0;
        bulletX = 1000;
        bulletY = 1000;
    } else{
        bulletY += 25;
    }
    update();
}

void MainWindow::resetEnemies(){
    for(int i = 0; i < 11; i++){
        for(int j = 0; j < 5; j++){
            rhynoc[i][j] = new enemy((i*50),((j*50)+50));
            rhynoc[i][j]->setDead(false);
            if(i == 0){
                rhynoc[i][j]->setValue(30);
            } else if((i == 1) || (i == 2)){
                rhynoc[i][j]->setValue(20);
            } else if((i == 3) || (i == 4)){
                rhynoc[i][j]->setValue(10);
            }
        }
    }
    enemiesLeft = 55;
}
