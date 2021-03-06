#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLCDNumber>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QLCDNumber* getLcd();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_lcdNumber_overflow();

    void on_lcdNumber_customContextMenuRequested(const QPoint &pos);

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
