#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
int value_pin_3=0;
int value_pin_4=0;
int value_pin_17=0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool checkOtherMotorDirection(int pin_value){

    bool is_set = true;

    if(pin_value == 0)
    {
        is_set = false;
    }
    return is_set;
}

void MainWindow::on_pushButton_clicked()
{
    FILE *sysfs_handle = NULL;
    bool isOtherMotorDirection = true;
    isOtherMotorDirection = checkOtherMotorDirection(value_pin_4);

    if(((sysfs_handle = fopen("/sys/class/gpio/gpio3/value", "w")) != NULL) && !isOtherMotorDirection)
    {
        // Switch between binary values
        value_pin_3 = value_pin_3 ? 0 : 1;

        char str_value[2];

        snprintf(str_value, 2*sizeof(char), "%d", value_pin_3);

        fwrite(str_value,  2*sizeof(char), 2, sysfs_handle);
        fclose(sysfs_handle);
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    FILE *sysfs_handle = NULL;
    bool isOtherMotorDirection = true;
    isOtherMotorDirection = checkOtherMotorDirection(value_pin_3);

    if(((sysfs_handle = fopen("/sys/class/gpio/gpio4/value", "w")) != NULL) && !isOtherMotorDirection)
    {
        value_pin_4 = value_pin_4 ? 0 : 1;

        char str_value[2];

        snprintf(str_value, 2*sizeof(char), "%d", value_pin_4);

        fwrite(str_value,  2*sizeof(char), 2, sysfs_handle);
        fclose(sysfs_handle);
    }
}

/**
 * @brief MainWindow::on_pushButton_3_clicked
 * Run motor to fill the Feeder when at position
 * where this motor is connected. The current
 * position is therefor a required condition to
 * run the switch/relais at all.
 */
void MainWindow::on_pushButton_3_clicked()
{
    FILE *sysfs_handle = NULL;

    if((sysfs_handle = fopen("/sys/class/gpio/gpio17/value", "w")) != NULL)
    {
        // Compare with previous state
        value_pin_17 = value_pin_17 ? 0 : 1;

        char str_value[2];

        snprintf(str_value, 2*sizeof(char), "%d", value_pin_17);

        fwrite(str_value,  2*sizeof(char), 2, sysfs_handle);
        fclose(sysfs_handle);
    }
}
