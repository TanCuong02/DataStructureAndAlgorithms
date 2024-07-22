#include<stdio.h>

int count = 0;

int swapCount = 0;

int Swap(int& a, int& b){
	int temp = a;
	a=b;
	b=temp;
}

int bubbleSort(int a[], int n){
	for(int i = 0; i < n-1;i++){
		for(int j = n-1; j > i ; j-- ){
           count++;
          if(a[j-1] > a[j]){
            swapCount++;
			Swap(a[j-1],a[j]);
          }
		}
	}
 
}

int main(){
	int n; scanf("%d", &n);
	
	int a[n];
  
  	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	
  	bubbleSort(a,n);	
  
	printf("%d ", count);
  	printf("%d\n", swapCount);
  
  	for(int i = 0; i < n; i++){
    printf("%d ", a[i]);
    }
           
  return 0;
}
