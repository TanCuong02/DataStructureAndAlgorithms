#include <stdio.h>

int sumOfArr(int a[], int n); 

int sumOfArr(int a[], int n){
	if(n==0) return a[0];
	return a[n] + sumOfArr(a, n-1);
}
int main() {
	
	int n; scanf("%d", &n);
	
   int a[n];
   
   for(int i = 0; i < n; i++){
   		scanf("%d", &a[i]);
   }
  
	
	
   printf("%d ", sumOfArr(a, n-1));   

   return 0;
}
