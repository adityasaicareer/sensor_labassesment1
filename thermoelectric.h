#include <stdio.h>
#include <math.h>

void thermoelectric(double v,double s,int tcold,double err,int n)
{
    double thot=(((v/s)+tcold)+err)*(1+(0.006)*n/12);
    FILE *file = fopen("/Users/chowdaryadithyasaividivada/Documents/22BCT0087-LA1/electric.csv", "a");
    if (file == NULL) {
        printf("Error opening file!\n");
    }

    fprintf(file, "%lf\n",(thot));

    
    fclose(file);
}