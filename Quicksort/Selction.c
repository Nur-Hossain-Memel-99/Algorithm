#include<stdio.h>
#include <time.h>
#define CLOCK_PER_SEC 1000
long long int data[400000];
int main()
{
    long int n;
    long int i,j,temp,position;

    double end;
    clock_t start;

    FILE *fp1;
    FILE *fp;

    fp=fopen("CSE1802014025_input(400000).txt","r");
    fp1=fopen("output(400000).txt","w");
    fscanf(fp,"%ld",&n);

    printf("\nReading data from file...");
    for(i=0; i<n; i++)
    {
        fscanf(fp,"%ld",&data[i]);
    }

    printf("\nData Reading  complete");
    printf("\nSorting process started...WAIT");

    start=clock();

    for(i = 0; i < (n - 1); i++)
    {
        position=i;
        for(j = i + 1; j < n; j++)
        {
            if(data[position]>data[j])
                position=j;
        }
        if(position != i)
        {
            temp=data[i];
            data[i]=data[position];
            data[position]=temp;
        }
    }
    end = ((double) clock()- start)/CLOCK_PER_SEC;

    printf("\nSorting complete.");

    printf("\n\nNo.of data\tTime needed for execution");
    printf("\n----------|------------------------------");
    printf("\n%ld\t\t%lf",n,end);

    printf("\n\nThis information is added to file named 'output.txt'\n\n");
    fprintf(fp1,"%ld \t%lf\n",n,end);

    for(i=1;i<=n;i++)
        fprintf(fp1,"%ld\n",data[i]);

    return 0;
}
