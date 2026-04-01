# Temperature Sensor Monitoring

A modular embedded C++ project that simulates reading temperature values from a sensor, evaluates them against a configurable threshold, and triggers warnings when the threshold is exceeded.

Built to demonstrate software architecture principles: modular design, requirements-based development, and structured testing.

---

## Features

- Simulated sensor readings (0–49 °C)
- Configurable warning threshold (default: 30 °C)
- Console output: `OK` or `WARNING` per measurement
- Statistical summary: Min, Max, Average
- Clean modular structure with header/source separation

---

## Project Structure

```
temp-sensor/
├── src/
│   ├── main.cpp        # Entry point, main measurement loop
│   ├── sensor.cpp      # Sensor simulation (rand-based)
│   ├── alarm.cpp       # Threshold check and console output
│   └── utils.cpp       # Statistical evaluation (Min/Max/Avg)
├── include/
│   ├── sensor.h        # Public interface: readTemperature()
│   ├── alarm.h         # Public interface: checkTemperature()
│   └── utils.h         # Public interface: printStats()
└── README.md
```

---

## Architecture

Dependencies flow strictly top-down — no circular dependencies:

```
         main.cpp
            |
    +-------+-------+
    |               |           |
 sensor          alarm        utils
 (read)       (evaluate)   (statistics)
```

Each module has a single, clearly defined responsibility (Separation of Concerns).

---

## Build & Run

**Requirements:** GCC / G++ (MinGW-w64 on Windows, GCC on Linux/macOS)

```bash
# Compile all modules (from the root folder temp-sensor/)
g++ src/main.cpp src/sensor.cpp src/alarm.cpp src/utils.cpp -Iinclude -o sensor.exe

# Run
./sensor.exe
```

---

## Sample Output

```
=== Temperature Sensor Monitoring ===
OK - Temperature normal: 22 deg C
WARNING! Temperature too high: 37 deg C
OK - Temperature normal: 14 deg C
WARNING! Temperature too high: 43 deg C
OK - Temperature normal: 29 deg C
...

--- Statistics ---
Min:     8 deg C
Max:     45 deg C
Average: 28 deg C
```

---

## Configuration

| Constant       | File       | Default | Description                        |
|----------------|------------|---------|------------------------------------|
| `THRESHOLD`    | alarm.cpp  | `30`    | Warning threshold in degrees C     |
| `MEASUREMENTS` | main.cpp   | `10`    | Number of sensor readings per run  |

---

## Requirements

| ID     | Requirement                                              | Priority |
|--------|----------------------------------------------------------|----------|
| REQ-01 | Read temperature values (simulated: 0–49 °C)             | MUST     |
| REQ-02 | Compare each value against a configurable threshold      | MUST     |
| REQ-03 | Output WARNING if threshold is exceeded                  | MUST     |
| REQ-04 | Output OK if temperature is within normal range          | MUST     |
| REQ-05 | Statistical summary: Min, Max, Average                   | SHOULD   |
| REQ-06 | Configurable number of measurements                      | MAY      |

---

## Documentation

A full project documentation (PDF) is included covering:
- Functional & non-functional requirements
- Software architecture and module design
- Full source code with explanations
- Test log with 10 sample runs (100% pass rate)

---

## License

This project is for demonstration and portfolio purposes.
