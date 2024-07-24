#include<stdio.h>

int count = 0;

int swapCount = 0;


int Swap(int& a, int& b){
	int temp = a;
	a=b;
	b=temp;
}

int SelectionSort(int a[], int n){
  int min;
	for(int i = 0; i < n-1;i++){
      min = i;
		for(int j = i+1; j <n ;j++ ){
           count++;
          if(a[j] < a[min]){
            min = j;
          }
		}
 if(min != i){
            swapCount++;
			Swap(a[min],a[i]);
          }
	}
 
}

int main(){
	int n; scanf("%d", &n);
	
	int a[n];
  
  	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	
  	SelectionSort(a,n);	
  
	printf("%d ", count);
  	printf("%d\n", swapCount);
  
  	for(int i = 0; i < n; i++){
    printf("%d ", a[i]);
    }
           
  return 0;
}
