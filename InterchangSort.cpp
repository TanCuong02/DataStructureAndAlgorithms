#include<stdio.h>

int count = 0;

int swapCount = 0;

int Swap(int& a, int& b){
	int temp = a;
	a=b;
	b=temp;
}

int interchangeSort(int a[], int n){
	for(int i = 0; i < n-1;i++){
		for(int j = i+1; j <n ;j++ ){
           count++;
          if(a[i] > a[j]){
            swapCount++;
			Swap(a[i],a[j]);
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
	
  	interchangeSort(a,n);	
  
	printf("%d ", count);
  	printf("%d\n", swapCount);
  
  	for(int i = 0; i < n; i++){
    printf("%d ", a[i]);
    }
           
  return 0;
}
