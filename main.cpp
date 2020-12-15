#include "mainwindow.h"
#include "marker.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    int output_pin_array[] = {3, 4};
    int input_pin_array[] = {27, 22};

    FILE *sysfs_handle = NULL;
    // Export access to pins in general
    if((sysfs_handle = fopen("/sys/class/gpio/export", "w")) != NULL)
    {
            fwrite("3", sizeof(char), 2, sysfs_handle);
            fclose(sysfs_handle);
    }

    // Set pin 3 from GPIO as output
    if((sysfs_handle = fopen("/sys/class/gpio/gpio3/direction", "w")) != NULL)
    {
            fwrite("out", sizeof(char), 4, sysfs_handle);
            fclose(sysfs_handle);
    }

    // Export access to pins in general
    if((sysfs_handle = fopen("/sys/class/gpio/export", "w")) != NULL)
    {
            fwrite("4", sizeof(char), 2, sysfs_handle);
            fclose(sysfs_handle);
    }


    // Set pin 4 from GPIO as output
    if((sysfs_handle = fopen("/sys/class/gpio/gpio4/direction", "w")) != NULL)
    {
            fwrite("out", sizeof(char), 4, sysfs_handle);
            fclose(sysfs_handle);
    }

    // Export access to pins in general
    if((sysfs_handle = fopen("/sys/class/gpio/export", "w")) != NULL)
    {
            fwrite("17", sizeof(char), 2, sysfs_handle);
            fclose(sysfs_handle);
    }


    // Set pin 17 from GPIO as output
    if((sysfs_handle = fopen("/sys/class/gpio/gpio17/direction", "w")) != NULL)
    {
            fwrite("out", sizeof(char), 4, sysfs_handle);
            fclose(sysfs_handle);
    }

    // Export access to pins in general
    if((sysfs_handle = fopen("/sys/class/gpio/export", "w")) != NULL)
    {
            fwrite("27", sizeof(char), 2, sysfs_handle);
            fclose(sysfs_handle);
    }


    // Set pin 27 from GPIO as input
    if((sysfs_handle = fopen("/sys/class/gpio/gpio27/direction", "w")) != NULL)
    {
            fwrite("in", sizeof(char), 4, sysfs_handle);
            fclose(sysfs_handle);
    }

    MainWindow w;
    w.show();

    Marker positionMarker = Marker(27, w.getLcd());
    positionMarker.init();

    return a.exec();
}
