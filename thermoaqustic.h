#include <stdio.h>
#include <math.h>

void aqustic(double k,double p,double s,double err,int i)
{
    double v=(s*p)+pow(k*p,2);
    
    int a=100;
    int b=25;
   
    double temp=((a*v)+b+err)*(1+(0.006*i/120));

    FILE *file = fopen("/Users/chowdaryadithyasaividivada/Documents/22BCT0087-LA1/aqustic.csv", "a");
    if (file == NULL) {
        printf("Error opening file!\n");
    }

    fprintf(file, "%lf\n",temp);

    // Close the file
    fclose(file);

}