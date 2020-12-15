#include "marker.h"
#include <QThread>
#include <QDebug>

/**
 * @brief Marker::Marker
 * A marker class to determine the Feeder's position
 *
 */
Marker::Marker(QLCDNumber* lcd)
{
    // Set default GPIO pin
    pin_number = 27;
    ui_lcd = lcd;
}

Marker::Marker(int gpio_pin, QLCDNumber* lcd){
    pin_number = gpio_pin;
    ui_lcd = lcd;
}

bool Marker::istoggle(int prev, int actual){
    if(prev==actual){
        return false;
    }else {
        return true;
    }
}

// Replace with interrupt
/**
 * @brief Marker::infiniteRead
 * The marker sensors are polled continuously.
 * In combination with the motor direction
 * the counting of the position is done.
 */
void Marker::infiniteRead(){
    int increment = 0;
    int previous_increment = 0;
    for (;;) {
             increment = poll();
             if(istoggle(previous_increment, increment)){
                 // Update position when toggled
                 // either by 1: forward, 0: marker passed,
                 // -1: backward
                 MARKER_COUNT += increment;
                 previous_increment = increment;
             }
             // Write new marker count value to LCD in front-end
             // qDebug() << MARKER_COUNT;
             ui_lcd->display(MARKER_COUNT);
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

    // HARDCODED pin 27
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
        // qDebug()  << "Console Mode. Marker detected!\n";
        // Compare with driving direction to increase or decrease counter
        return 1;
    }
    return 0;
}
