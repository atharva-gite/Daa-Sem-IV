#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100000
#define BLOCK_SIZE 100

void insertion_sort(int arr[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void selection_sort(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    FILE *fp,*ptri,*ptrs;
    time_t t;
    int i,j,n,k;
    int array[N];
    //open the file
    fp = fopen("random_numbers.txt", "w");
    srand((unsigned) time(&t));
    // print 100,000 random numbers
    for( k = 0 ; k < N ; k++ ) 
    {
    int num=rand()%100000;
    fprintf(fp, "%d\n", num);
    }
    // close the file
    fclose(fp);
    //open the file
    fp = fopen("random_numbers.txt", "r");
    k=0;
    // Read each number from the file and store it in the array
    while (fscanf(fp, "%d", &n) == 1) 
    {
        array[k++] = n;
    }

    // Close the file
    fclose(fp);
    ptri= fopen("insertion_sort_time.txt", "w");
    ptrs= fopen("selection_sort_time.txt", "w");
    //clock start
    clock_t start, end;
    for (i=1;i<1001;i++) 
    {
        double insertion_sort_time = 0;
        double selection_sort_time = 0;
        // 1*100= 100 blocks, 2*100=200 blocks and so on
        int size;
        size=i*BLOCK_SIZE;
        // block arr to find out combien de time for sorting 0-99,0-199 and so on
        int block_arr[size];
        for(j = 0; j<size ; j++) 
        {
        block_arr[j] = array[j];
        }

            start = clock();
            insertion_sort(block_arr,size);
            end = clock();
            insertion_sort_time += ((double) (end - start)) / CLOCKS_PER_SEC;
            

            start = clock();
            selection_sort(block_arr,size); 
            end = clock();
            selection_sort_time += ((double) (end - start)) / CLOCKS_PER_SEC;

            fprintf(ptri, "%lf\n",insertion_sort_time);
            fprintf(ptrs, "%lf\n",selection_sort_time);
            }   

    return 0;
}
