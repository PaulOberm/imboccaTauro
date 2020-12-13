#include "marker.h"
#include <QThread>
#include <QDebug>

Marker::Marker()
{
    // Set default GPIO pin
    pin_number = 27;
}

Marker::Marker(int gpio_pin){
    pin_number = gpio_pin;
}

void Marker::infiniteRead(){
    int increment = 0;
    int previous_increment = 1;
    for (;;) {
             increment = poll();
             // if istoggle(increment, previous_increment)
             // MARKER_COUNT += ...
             // Write new marker count value to LCD in front-end
      }
}

void Marker::init(){
    RxThread = std::thread(&Marker::infiniteRead, this);
}

/**
 * @brief Marker::poll
 * Read GPIO pin and return a count increment either positiv
 * or negativ, when driving forward or backwards correspondingly
 * @return
 * Int Incremental counter value
 */
int Marker::poll() {
    FILE *sysfs_handle = NULL;
    // Check pin state
    bool pin_pressed = false;
    char pin_count[2] = "0";
    const char pressed_string[2] = "0";
    if((sysfs_handle = fopen("/sys/class/gpio/gpio27/value", "r")) != NULL)
    {
            fread(pin_count, sizeof(char), 1, sysfs_handle);
            fclose(sysfs_handle);
            // OV -> False, when button pressed/sensor active
            if(strcmp(pin_count, pressed_string) == 0){
                pin_pressed = true;
            }else {
                pin_pressed = false;
            }
    }

    // Return new count update based on direction of motor

    if(pin_pressed){
        qDebug()  << "Console Mode. Marker detected!\n";
        qDebug() << pin_count;
        // Compare with driving direction to increase or decrease counter
        return int(pin_count);
    }
    return int(pin_count);
}
