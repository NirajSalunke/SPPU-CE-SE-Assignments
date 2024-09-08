#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void DDA_Line(float x1, float y1, float x2, float y2);
    void CircleMaker(float x1, float y1, int radius);
    void DrawCircle(float xc, float yc, float x1, float y2);
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
