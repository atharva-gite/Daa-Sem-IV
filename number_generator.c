#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {
   FILE *fp;
   fp = fopen("numbers.txt", "w");
   long long int i, n;
   time_t t;
   
   n = 100000;
   clock_t start, end;
   double cpu_time_used;
     
   start = clock();
   srand((unsigned) time(&t));
   for( i = 0 ; i < n ; i++ ) 
   {
   int num=rand()%100;
   num=num*100000;
   num+=rand();
   fprintf(fp, "%d\n", num);
   }
   end = clock();
   cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
   printf("It took %f seconds to execute \n", cpu_time_used);
   return(0);
}
