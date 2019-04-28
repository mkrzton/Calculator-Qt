#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
private slots:
    void digit_pressed();


    void unary_pressed();
    void binary_pressed();
    void on_Dot_released();

    void on_Clear_released();
    void on_Equal_released();
    void on_Sqrt_released();
    void on_Pow_released();
    void on_Cube_released();
};

#endif // MAINWINDOW_H
