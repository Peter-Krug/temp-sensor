#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sensor.h"
#include "alarm.h"
#include "utils.h"

#define MESSUNGEN 10

int main() {
    srand(time(NULL));
    int werte[MESSUNGEN];

    std::cout << "=== Temperatur-Sensorüberwachung ===" << std::endl;

    for (int i = 0; i < MESSUNGEN; i++) {
        werte[i] = readTemperature();
        checkTemperature(werte[i]);
    }

    printStats(werte, MESSUNGEN);
    return 0;
}