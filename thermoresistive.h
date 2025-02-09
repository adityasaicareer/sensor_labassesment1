#include <math.h>
#include <stdio.h>

double tempcalculate(float t,double rt,double alpha,double rcal)
{
    double th=((rcal/rt)-1)/alpha+t;

    
    FILE *file = fopen("/Users/chowdaryadithyasaividivada/Documents/22BCT0087-LA1/resist_output.csv", "a");

    // Check if file is opened successfully
    if (file == NULL) {
        printf("Error opening file!\n");
        return -1;
    }

    // If file is empty, write the header
    

    // Write resistance and calculated temperature to CSV
    fprintf(file, "%.2f,%.2f\n", rcal, th);

    // Close the file
    fclose(file);


    if(th>35)
    {
        printf("Fan ON");
    }
    else if(th<60)
    {   
        printf("Heater ON");

    }
    return th;
}

