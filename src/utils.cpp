#include "utils.h"
#include <iostream>

void printStats(int values[], int size) {
    int min = values[0], max = values[0], sum = 0;
    for (int i = 0; i < size; i++) {
        if (values[i] < min) min = values[i];
        if (values[i] > max) max = values[i];
        sum += values[i];
    }
    std::cout << "\n--- Statistik ---" << std::endl;
    std::cout << "Min: " << min << " Celcius" << std::endl;
    std::cout << "Max: " << max << " Celcius" << std::endl;
    std::cout << "Durchschnitt: " << sum / size << " Celcius" << std::endl;
}