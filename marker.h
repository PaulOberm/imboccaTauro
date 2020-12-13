#ifndef MARKER_H
#define MARKER_H

#include <QThread>

class Marker
{
private:
    // GPIO pin to poll from
    int pin_number;
    // Marker count as position of the feeder
    int MARKER_COUNT = 0;

    // Thread where poll has to run
    std::thread RxThread;

    void infiniteRead();

public:
    Marker();
    Marker(int gpio_pin);

    void init();
    int poll();
};

#endif // MARKER_H
