#include <stdio.h>
#include <math.h>
double lnn(double n)
{
return log(n);
}
double logg2(double n)
{
return log2(n);
}
double power(double i,double a)
{
return pow(i,a);
}
int main() 
{
int i;
printf("n\tln(n)\tnln(n)\tln(ln(n))\tlg(n)\tlg(lg(n))\tn³\t√lgn\t2^{lgn}\tlg²n\n");
for(i=1;i<101;i++)
{
printf("%d\t%0.3f\t%0.3f\t%0.3f\t\t%0.3f\t%0.3f\t  \t%d\t  %0.3f\t%0.1f\t%0.3f\n",i,lnn(i),i*lnn(i),lnn(lnn(i)),logg2(i),logg2(logg2(i)),i*i*i,power(logg2(i),0.5),power(2,logg2(i)),power(logg2(i),2));
}
}