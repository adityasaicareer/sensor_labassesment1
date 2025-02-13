#include <math.h>
#include <stdio.h>

double tempcalculate(float t,double rt,double alpha,double rcal,double err,int n)
{
    double th=((((rcal/rt)-1)/alpha+t)+err)*(1+(0.006)*(n/12));

    
    FILE *file = fopen("/Users/chowdaryadithyasaividivada/Documents/22BCT0087-LA1/resist_output.csv", "a");

    
    if (file == NULL) {
        printf("Error opening file!\n");
        return -1;
    }

    fprintf(file, "%.2f\n",th);

    // Close the file
    fclose(file);
    return th;
}

