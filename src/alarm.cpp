#include "alarm.h"
#include <iostream>

#define THRESHOLD 30

void checkTemperature(int temp) {
    if (temp > THRESHOLD) {
        std::cout << "WARNUNG! Temperatur zu hoch: " << temp << " Celcius" << std::endl;
    } else {
        std::cout << "Temperatur normal: " << temp << " Celcius" << std::endl;
    }
}