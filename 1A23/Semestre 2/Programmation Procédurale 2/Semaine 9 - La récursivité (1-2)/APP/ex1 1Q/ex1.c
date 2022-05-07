#include <stdio.h>
#include <stdlib.h>

int* inverseRec(int t[],int n, int i)
{
    int temp;
    if(i>=(n+1)/2 )
      return t;
    else{
      temp = t[i];
      t[i]=t[n-i];
      t[n-i]=temp;
      return inverseRec(t,n,i+1);
    }
}

int main()
{
      int i, n;

      printf("La taille du tableau ");  
      scanf("%d",&n);

      int t[n];
      int *ti;

      for(i=0;i<n;i++){
         printf("t[%d]=",i);
         scanf("%d",&t[i]);
      }
      ti=inverseRec(t,n-1,0);
      printf("\nle tableau inverse est: \n");
      for(i=0;i<n;i++)
         printf("\nt[%d]=%d",i,ti[i]);

    return 0;
}