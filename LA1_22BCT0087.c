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
    printf("1.Thermoelectric\n2.Thermoresistive\n3.Thermo-Optical\n4.Thermo-aqustic\n5.CCD sensor");
    scanf("%d",&n);
    switch(n)
    {
        case 1:
            printf("You choose Thermoelectric\n");
            double s;
            printf("Enter the seebeckcoefficient in 10^-6 order:");
            scanf("%lf",&s);
            double s1=s;
            double v;
            printf("Enter the voltage in mv order:");
            scanf("%lf",&v);
            double v1=v*pow(10,-3);

            for(int i=1;i<=1000;i++)
            {
                int min = 0, max = 40;
                int randomValue = min + rand() % (max - min + 1);
                double error=-2.5+rand()%(6);
                printf("%d",randomValue);
                thermoelectric(v1,s1,randomValue,error,i);

            }
            break;
        case 2:

            printf("Ente the Resistance calculated:");
            float rcal;
            FILE *file=fopen("/Users/chowdaryadithyasaividivada/Documents/22BCT0087-LA1/resistivedata.csv","r");
            char line[5];
            // float t,double rt,double alpha,double rcal)
            int min = 100, max = 125;
            int randomValue = min + rand() % (max - min + 1);
            for(int i=1;i<=1000;i++)
            {
                printf("%s",line);
                double min = -1;
                double max= 1;
                double err = min + rand() %(3);
                rcal=atof(line);
                tempcalculate(0,100,0.00385,randomValue,err,i);

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
            
            for(int i=1;i<=1000;i++)
            {
                int min = 100, max = 500;
                int randomValue = min + rand() % (max - min + 1);
                double l = -2.0, h = 2.0;
                double err = l + rand() % (5);
                optical(sig,em,A,randomValue,g,den,n,err,i);
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
            
            for(int i=1;i<=1000;i++)
            {
                double min = -1.5; double max= 1.5;
                double err = (rand() / (double)RAND_MAX) * 3 - 1.5;
                double randomValue = (double)rand() / RAND_MAX;
                aqustic(k,randomValue,so,err,i);
            }
            break;
        case 5:
            
        default:
            printf("Wrong option entered");


    }
}