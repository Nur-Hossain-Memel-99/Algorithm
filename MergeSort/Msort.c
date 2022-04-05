#include<stdio.h>
#include <time.h>
#define CLOCK_PER_SEC 1000
long long int A[60000];
void MergeSort(long long int A[], long int left, long int right);
void Merge(long long int A[], long int left, long int mid, long int right);
int main()
{
    long int n;
    long int i,j,left,mid,right;

    double end;
    clock_t start;

    FILE *fp1;
    FILE *fp;

    fp=fopen("CSE1802014025_input(60000).txt","r");
    fp1=fopen("output(60000).txt","w");
    fscanf(fp,"%ld",&n);

    printf("\nReading data from file...");
    for(i=0; i<n; i++)
        fscanf(fp,"%ld",&A[i]);

    printf("\nData Reading  complete");
    printf("\nSorting process started...WAIT");

    start=clock();
    MergeSort(A,1,n);
    end = ((double) clock()- start)/CLOCK_PER_SEC;

    printf("\nSorting complete.");

    printf("\n\nNo.of data\tTime needed for execution");
    printf("\n============================================");
    printf("\n%ld\t\t%lf",n,end);

    printf("\n\nThis information is added to file named 'output.txt'\n\n");
    fprintf(fp1,"%ld %lf\n",n,end);


    for(i=1;i<=n;i++)
        fprintf(fp1,"%ld\n",A[i]);

    return 0;
}

void MergeSort(long long int A[], long int left, long int right)
{
    long int mid;
    if(left<right)
    {
        mid=((left+right)/2);
        MergeSort(A,left,mid);
        MergeSort(A,mid+1,right);
        Merge(A,left,mid,right);
    }
}

void Merge(long long int A[], long int left, long int mid, long int right)
{
    long int i,j,k;
    long long int L[100000],R[100000];
    long int n1=mid-left+1;
    long int n2=right-mid;
    for(i=1; i<=n1; i++)
    {
        L[i]=A[left+i-1];
    }
    for(j=1; j<=n2; j++)
    {
        R[j]=A[mid+j];
    }

    L[n1+1]=2000000;
    R[n2+1]=2000000;
    i=1;
    j=1;
    for(k=left; k<=right; k++)
    {
        if(L[i]<=R[j])
        {
            A[k]=L[i];
            i=i+1;
        }
        else
        {
            A[k]=R[j];
            j=j+1;
        }
    }
}
