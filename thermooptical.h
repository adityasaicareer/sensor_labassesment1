#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void optical(double sig,double e,double a,double t,int g,float den,int n)
{
    double pr=sig*e*a*pow(t,4);
    double pin=den*pr*n*pow(10,-6);
    printf("%lf",pr);
    double vout=g*pin;

    FILE *file = fopen("/Users/chowdaryadithyasaividivada/Documents/22BCT0087-LA1/optical.csv", "a");
    if (file == NULL) {
        printf("Error opening file!\n");
    }

    fprintf(file, "%.2lf\n",(vout));

    // Close the file
    fclose(file);
    printf("%lf",vout);
}