#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

double uav_x, uav_y, uav_z;       // UAV's position
double rx_x, rx_y, rx_z;          // Receiver's position
double distance;

double wave_velocity = 3.0e8;     // Radio wave velocity (m/s)
double Time_To_Send_Signal;       // Signal propagation time (s)


// Delay function
void delay(int number_of_seconds)
{
    clock_t start_time = clock();

    while (clock() - start_time <
           number_of_seconds * CLOCKS_PER_SEC)
    {
        // Wait
    }
}


int main()
{
    // Initialize random seed
    srand(time(NULL));

    // Enter Receiver position
    printf("\nEnter Receiver position (X Y Z): ");
    scanf("%lf %lf %lf", &rx_x, &rx_y, &rx_z);

    while (1)
    {
        // Random UAV position
        // X: 0 - 10000 m
        // Y: 0 - 10000 m
        // Z: 0 - 500 m

        uav_x = rand() % 10001;
        uav_y = rand() % 10001;
        uav_z = rand() % 501;

        // Calculate 3D distance
        distance = sqrt(
            pow(rx_x - uav_x, 2) +
            pow(rx_y - uav_y, 2) +
            pow(rx_z - uav_z, 2)
        );

        // Calculate signal propagation time
        Time_To_Send_Signal = distance / wave_velocity;

        // Show result
        printf("\n===== UAV Communication =====\n");

        printf("UAV's position      : (%.2f, %.2f, %.2f) m\n", uav_x, uav_y, uav_z);

        printf("Receiver's position : (%.2f, %.2f, %.2f) m\n",  rx_x, rx_y, rx_z);

        printf("Distance            : %.2f m\n",  distance);

        printf("Signal propagation time : %.9e s\n",  Time_To_Send_Signal);

        printf("Signal propagation time : %.6f us\n", Time_To_Send_Signal * 1.0e6);
        
        delay(1);
    }

    return 0;
}
