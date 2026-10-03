#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double uav_x, uav_y, uav_z;       // UAV's position
double rx_x, rx_y, rx_z;          // Receiver's position
double distance;
double wave_velocity = 3.0e8;     
double Time_To_Send_Signal;
int main()
{
     
        uav_x = rand() % 10001;
        uav_y = rand() % 10001;
        uav_z = rand() % 5001;      

        printf("\nEnter Receiver position (X Y Z): ");
        scanf("%lf %lf %lf", &rx_x, &rx_y, &rx_z);

        // Calculate 3D distance
        distance = sqrt(
            pow(rx_x - uav_x, 2) +
            pow(rx_y - uav_y, 2) +
            pow(rx_z - uav_z, 2)
        );

        // Show result
        printf("\n===== UAV Communication Distance =====\n");

        printf("UAV's position      : (%.2f, %.2f, %.2f) m\n",
               uav_x, uav_y, uav_z);

        printf("Receiver's position : (%.2f, %.2f, %.2f) m\n",
               rx_x, rx_y, rx_z);

        printf("Distance            : %.2f m\n", distance);

        // Calculate the time that use to send the signal to UAV
        Time_To_Send_Signal = distance / wave_velocity;
        printf("Time to send the signal : %.9e s\n", Time_To_Send_Signal);
        printf("Signal propagation time : %.6f us\n", Time_To_Send_Signal * 1.0e6);
    
    return 0;

}
