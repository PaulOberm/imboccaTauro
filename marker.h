#ifndef MARKER_H
#define MARKER_H

#include <QThread>
#include <QLCDNumber>

class Marker
{
private:
    // GPIO pin to poll from
    int pin_number;
    // Marker count as position of the feeder
    int MARKER_COUNT = 0;
    QLCDNumber* ui_lcd;

    // Thread where poll has to run
    std::thread RxThread;

    void infiniteRead();
    bool istoggle(int, int);

public:
    Marker(QLCDNumber* lcd);
    Marker(int gpio_pin, QLCDNumber* lcd);

    void init();
    int poll();
};

#endif // MARKER_H
