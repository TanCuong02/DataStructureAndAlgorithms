#include <stdio.h>


int max(int a[], int n)
{
  if(n==0) return -1;
  if(n == 1){
      return a[0];
  }else{
      if(a[n - 1] > max(a, n-1)){
          return a[n-1];
      }else{
      	return max(a, n-1);
      }
  }
}

int min(int a[], int n)
{
  if(n==0) return -1;
  if(n == 1){
      return a[0];
  }else{
      if(a[n-1] < min(a, n-1)){
          return a[n-1];
      }else{
      	return min(a, n-1);
      }
  }
}
int main()
{
    int n;  scanf("%d", &n);
    int a[n];
    
     for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    
    printf("%d ", max(a, n));
    printf("%d ", min(a, n));
    return 0;
}
