#include <stdio.h>
#include <stdlib.h>

int main()
{
int n,i,j;
printf("Enter the dimensions of the matrix.\n");
scanf("%d",&n);
int A[n][n],B[n][n];
int C[n][n];
printf("Enter the contents of matrix 'A' \n");
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
scanf("%d",&A[i][j]);
}
}
printf("Enter the contents of matrix 'B' \n");
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
scanf("%d",&B[i][j]);
}
}
int s1=B[0][1]-B[1][1];
int s2=A[0][0]+A[0][1];
int s3=A[1][0]+A[1][1];
int s4=B[1][0]-B[0][0];
int s5=A[0][0]+A[1][1];
int s6=B[0][0]+B[1][1];
int s7=A[0][1]-A[1][1];
int s8=B[1][0]+B[1][1];
int s9=A[0][0]-A[1][0];
int s10=B[0][0]+B[0][1];
int p1,p2,p3,p4,p5,p6,p7;
p1=A[0][0]*s1;
p2=s2*B[1][1];
p3=s3*B[0][0];
p4=s4*A[1][1];
p5=s5*s6;
p6=s7*s8;
p7=s9*s10;
C[0][0]=p5+p4-p2+p6;
C[0][1]=p1+p2;
C[1][0]=p3+p4;
C[1][1]=p5+p1-p3-p7;
printf("Matrix A*B is \n");
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
printf("%d\t",C[i][j]);
}
printf("\n");
}
}
