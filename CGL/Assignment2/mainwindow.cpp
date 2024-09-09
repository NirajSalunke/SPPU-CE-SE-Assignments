#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QImage"
#include <QColorDialog>
#include <QMessageBox>
#include "algorithm"
using namespace std;
#define height 400
#define width 400

QImage img(height,width,QImage::Format_RGB888);
QRgb qrgb(qRgb(255,255,255));
int ver,a[20],b[20],i,y,xi[20],j,temp,k; // variables used in scan line algorithm
float slopes[20],dx,dy;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    for(int i =0;i<height;++i){
        for (int j = 0;j<width;++j){
            img.setPixel(i,j,qRgb(0,0,0));
        }
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
    ver = 0;
}

Line Obj1;
Fill Obj2;
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QMessageBox messageBox;
    if(
       ui->plainTextEdit->toPlainText().isEmpty() ||
       ui->plainTextEdit_2->toPlainText().isEmpty() ||
       ui->plainTextEdit_3->toPlainText().isEmpty() ||
       ui->plainTextEdit_4->toPlainText().isEmpty()
    ){
        messageBox.information(0,"Alert","Fields cannot be empty");
    }
    else{
        int x1 = ui->plainTextEdit->toPlainText().toInt();
        int y1 = ui->plainTextEdit_2->toPlainText().toInt();
        int x2 = ui->plainTextEdit_3->toPlainText().toInt();
        int y2 = ui->plainTextEdit_4->toPlainText().toInt();
        a[ver] = x2;
        b[ver] = y2;
        ver++;
        Obj1.DDALine(x1,y1,x2,y2,ui);

    }
}

void MainWindow::on_pushButton_2_clicked()
{
    for(int i =0;i<height;++i){
        for (int j = 0;j<width;++j){
            img.setPixel(i,j,qRgb(0,0,0));
        }
    }
    ui->plainTextEdit->clear();
    ui->plainTextEdit_2->clear();
    ui->plainTextEdit_3->clear();
    ui->plainTextEdit_4->clear();
    ui->label->setPixmap(QPixmap::fromImage(img));
}


void MainWindow::on_pushButton_3_clicked()
{
    // obj.ScanFill(ui);
    Obj2.ScanFill(ui);
}


void MainWindow::on_pushButton_4_clicked()
{
    QRgb color(QColorDialog::getColor().rgb());
    qrgb = color;
}


void Line::DDALine(int x1, int y1, int x2, int y2, Ui::MainWindow *ui) {
    float dx, dy, steps, xinc, yinc;
    dx = x2 - x1;
    dy = y2 - y1;

    steps = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);

    xinc = dx / steps;
    yinc = dy / steps;

    float x = x1, y = y1;

    for (int i = 0; i <= steps; i++) {
        img.setPixel(round(x), round(y), qrgb);
        x += xinc;
        y += yinc;
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}
void Fill::ScanFill(Ui::MainWindow *ui) {

    a[ver] = a[0];
    b[ver] = b[0];


    for (int i = 0; i < ver; i++) {
        int dy = b[i+1] - b[i];
        int dx = a[i+1] - a[i];


        if (dy == 0) {
            slopes[i] = 1.0;
        } else if (dx == 0) {
            slopes[i] = 0.0;
        } else {
            slopes[i] = (float)dx / dy;
        }
    }


    for (int i = 0; i < height; i++) {
        int k = 0;


        for (int j = 0; j < ver; j++) {
            if ((b[j+1] <= i && b[j] > i) || (b[j+1] > i && b[j] <= i)) {
                xi[k] = int(a[j] + slopes[j] * (i - b[j]));
                k++;
            }
        }


        sort(xi, xi + k);


        for (int j = 0; j < k; j += 2) {
            if (j + 1 < k) {  // Ensure we have a valid pair
                DDALine(xi[j], i, xi[j+1], i, ui);
            }
        }
    }
}


