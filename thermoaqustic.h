#include <stdio.h>
#include <math.h>

void aqustic(double k,double p,double s)
{
    double v=(s*p)+pow(k*p,2);
    printf("The Voltage produced in the sensor is %.2f\n",v);
    int a=100;
    int b=50;
   
    double temp=(a*v)+b;

    FILE *file = fopen("/Users/chowdaryadithyasaividivada/Documents/22BCT0087-LA1/aqustic.csv", "a");
    if (file == NULL) {
        printf("Error opening file!\n");
    }

    fprintf(file, "%lf\n",temp);

    // Close the file
    fclose(file);

}