#include <stdio.h>
#include <stdlib.h>
#define SIZE 3
void inputArray(int a[], int n)
{
   for (int i = 0; i < n; i++)
   {
      printf("Array is %d: \n",i);
      scanf("%d", &a[i]);
   }
}
int soNguyenTo (int n)
{
   int soNguyenTo = 1;
   for (int i = 0; i < n; i++)
   {
      if (n % i == 0)
      {
           soNguyenTo = 0;
           break;
      }
   }
   return soNguyenTo;
}
int demSoNguyenTo (int a[], int n)
{
   int count = 0;
   for (int i = 0; i < n; i++)
   {
      if (soNguyenTo(a[i]))
           count ++;
   }
   return count;
}
int main(int argc, char* argv[])
{
    int a[SIZE];
    inputArray(a,SIZE);
    int result  = 0;
    result = demSoNguyenTo(a, SIZE);
    printf("Mang a[] co %d phan tu la so nguyen to\n",result);
    return 0;
}
