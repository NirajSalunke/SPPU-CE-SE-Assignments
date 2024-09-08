#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QImage"
using namespace std;

QImage image(500, 500, QImage::Format_RGB888);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::DDA_Line(float x1, float y1, float x2, float y2) {
    float dx = x2 - x1;
    float dy = y2 - y1;
    float xinc, yinc, steps;

    if (abs(dx) > abs(dy)) {
        steps = abs(dx);
    } else {
        steps = abs(dy);
    }

    xinc = dx / steps;
    yinc = dy / steps;

    for (int i = 0; i <= steps; i++) {
        image.setPixel((x1), (y1), qRgb(255, 255, 0));
        x1 += xinc;
        y1 += yinc;
    }
}

void MainWindow::DrawCircle(float xc, float yc, float x1, float y1) {

    image.setPixel(xc + x1, yc + y1, qRgb(255, 255, 0));
    image.setPixel(xc - x1, yc + y1, qRgb(255, 255, 0));
    image.setPixel(xc + x1, yc - y1, qRgb(255, 255, 0));
    image.setPixel(xc - x1, yc - y1, qRgb(255, 255, 0));
    image.setPixel(xc + y1, yc + x1, qRgb(255, 255, 0));
    image.setPixel(xc - y1, yc + x1, qRgb(255, 255, 0));
    image.setPixel(xc + y1, yc - x1, qRgb(255, 255, 0));
    image.setPixel(xc - y1, yc - x1, qRgb(255, 255, 0));
}

void MainWindow::CircleMaker(float xc, float yc, int radius) {
    float X1 = 0;
    float Y1 = radius;
    int d = 3 - 2 * (radius);
    DrawCircle(xc, yc, X1, Y1);

    while (Y1 >= X1) {
        if (d > 0) {
            Y1--;
            d += 4 * (X1 - Y1) + 10;
        } else {
            d += 4 * X1 + 6;
        }
        X1++;
        DrawCircle(xc, yc, X1, Y1);
    }
}

void MainWindow::on_pushButton_clicked() {
    CircleMaker(250, 200, 100);
    CircleMaker(250, 200, 50);
    DDA_Line(250, 250, 335, 250);
    DDA_Line(250, 250, 165, 250);
    DDA_Line(250, 100, 335, 250);
    DDA_Line(250, 100, 165, 250);

    ui->label->setPixmap(QPixmap::fromImage(image));
}
