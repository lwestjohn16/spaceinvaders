#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    for(int i = 0; i < 11; i++){
        for(int j = 0; j < 5; j++){
            rhynoc[i][j] = new enemy((i*50),(j*50));
        }
    }
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
}
