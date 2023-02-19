#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<stdint.h>
#include <sys/time.h>


#define N 100000
#define BLOCK_SIZE 100
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void quick_sort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

void merge(int arr[], int l, int m, int r) //l=left m-middle r=right
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int l, int r)
{
    // left < right
    if (l < r) {
        int m = l + (r - l) / 2;

        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int main() {
    FILE *fp,*ptrm,*ptrq;
    struct timeval start, end;
    int arr[N],k,n,j,i;
    fp = fopen("numbers.txt", "r");
    k=0;
    // Read each number from the file and store it in the array
    while (fscanf(fp, "%d", &n) == 1) 
    {
        arr[k++] = n;
    }

    // Close the file
    fclose(fp);
    ptrm= fopen("merge_sort_time.txt", "w");
    ptrq= fopen("quick_sort_time.txt", "w");
    //clock start
   
    for (i=500;i<1001;i++) 
    {
        double merge_sort_time = 0;
        double quick_sort_time = 0;
        // 1*100= 100 blocks, 2*100=200 blocks and so on
        int size;
        size=i*BLOCK_SIZE;
        // block arr to find out combien de time for sorting 0-99,0-199 and so on
        int block_arrm[size];
        int block_arrq[size];
        for(j = 0; j<size ; j++) 
        {
        block_arrm[j] = arr[j];
        block_arrq[j]=arr[j];
        }

            gettimeofday(&start, NULL);
            merge_sort(block_arrm,0,size-1);
            gettimeofday(&end, NULL);
            uint64_t delta_usm = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);
            

            gettimeofday(&start, NULL);
            quick_sort(block_arrq,0,size-1); 
            gettimeofday(&end, NULL);
            uint64_t delta_usq = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);
            fprintf(ptrm, "%lu\n",delta_usm);
            fprintf(ptrq, "%lu\n",delta_usq);
            }   

    return 0;
}