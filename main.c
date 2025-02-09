#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <time.h>
#include "thermoresistive.h"
#include "thermoaqustic.h"
#include "thermoelectric.h"
#include "thermooptical.h"

int main()
{
    int n;
    printf("1.Thermoelectric\n2.Thermoresistive\n3.Thermo-Optical\n4.Thermo-aqustic");
    scanf("%d",&n);
    switch(n)
    {
        case 1:
            printf("You choose Thermoelectric\n");
            int s;
            printf("Enter the seebeckcoefficient in 10^-6 order:");
            scanf("%d",&s);
            double s1=s*pow(10,-6);
            double v;
            printf("Enter the voltage in mv order:");
            scanf("%lf",&v);
            double v1=v*pow(10,-3);

            for(int i=1;i<=100;i++)
            {
                int min = 100, max = 500;
                int randomValue = min + rand() % (max - min + 1);
                printf("%d",randomValue);
                thermoelectric(v1,s1,randomValue);

            }
            break;
        case 2:

            printf("Ente the Resistance calculated:");
            float rcal;
            FILE *file=fopen("/Users/chowdaryadithyasaividivada/Documents/22BCT0087-LA1/resistivedata.csv","r");
            char line[5];
            while(fgets(line,sizeof(line),file))
            {
                printf("%s",line);
                rcal=atof(line);
                printf("the calulated temp is %.2f kelvin",tempcalculate(273,100,0.00385,rcal));

            }
            break;
        case 3:

            printf("Choose Thermooptical\n");
            double sig=5.67*pow(10,-8);
            printf("Enter the Emmicivity:");
            double em;
            scanf("%lf",&em);
            double A;
            printf("Enter the Surface area:");
            scanf("%lf",&A);
            // printf("Enter the temparature in K:");
            // double temp;
            // scanf("%lf",&temp);
            int g;
            printf("Enter the value of G:");
            scanf("%d",&g);
            
            printf("Enter the value of Object density:");
            float den;
            scanf("%f",&den);
            printf("Enter the number of object:");
            int n;
            scanf("%d",&n);
            for(int i=1;i<=100;i++)
            {
                int min = 100, max = 500;
                int randomValue = min + rand() % (max - min + 1);
           
                optical(sig,em,A,randomValue,g,den,n);
            }
            
            break;
        case 4:
            printf("Enter the value of k:");
            double k;
            scanf("%lf",&k);
            printf("Enter the value of so:");
            double so;
            scanf("%lf",&so);
            printf("Let the relation between voltage and the temparature be T=a*v+b and a=100,b=25\n");
            srand(time(0));
            for(int i=1;i<=100;i++)
            {
                double randomValue = (double)rand() / RAND_MAX;
                aqustic(k,randomValue,so);
            }
        default:
            printf("Wrong option entered");


    }
}