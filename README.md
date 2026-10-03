# UAV-s-distance-calculator
This project make for education.


# UAV Communication Distance Calculator

A C program for calculating the three-dimensional distance between an Unmanned Aerial Vehicle (UAV) and a signal receiver, as well as estimating the signal propagation time between them.

This project demonstrates the basic physics and mathematics used in UAV communication systems.

---

## Overview

The program generates a random 3D position for a UAV and asks the user to enter the 3D position of a receiver.

It then calculates:

- UAV position `(X, Y, Z)`
- Receiver position `(X, Y, Z)`
- 3D distance between the UAV and receiver
- Signal propagation time
- Signal propagation time in microseconds

The program assumes that radio waves travel at approximately the speed of light:

\[
c = 3.0 \times 10^8 \text{ m/s}
\]

---

## Features

- Generate a random UAV position
- Input receiver coordinates
- Calculate 3D distance
- Calculate radio-wave propagation time
- Display propagation time in seconds
- Display propagation time in microseconds
- Simple C implementation using standard libraries

---

## Physics

### 1. Three-Dimensional Distance

The distance between the UAV and receiver is calculated using the 3D Euclidean distance formula:

\[
d = \sqrt{(x_2-x_1)^2+(y_2-y_1)^2+(z_2-z_1)^2}
\]

Where:

- `d` = Distance between UAV and receiver (m)
- `x1, y1, z1` = UAV coordinates
- `x2, y2, z2` = Receiver coordinates

The C implementation is:

```c
distance = sqrt(
    pow(rx_x - uav_x, 2) +
    pow(rx_y - uav_y, 2) +
    pow(rx_z - uav_z, 2)
);
