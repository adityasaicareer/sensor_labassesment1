#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void optical(double sig,double e,double a,double t,int g,float den,int n,int err,int i)
{
    double pr=sig*e*a*pow(t,4);
    double pin=den*pr*n*pow(10,-6);
    
    double vout=g*pin;

    double temp=((100*vout+25)+err)*(1+0.006*i/120);
    FILE *file = fopen("/Users/chowdaryadithyasaividivada/Documents/22BCT0087-LA1/optical.csv", "a");
    if (file == NULL) {
        printf("Error opening file!\n");
    }

    fprintf(file, "%.2lf\n",(temp));

    // Close the file
    fclose(file);
    printf("%lf",vout);
}