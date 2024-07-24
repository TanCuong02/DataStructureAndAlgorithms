#include<stdio.h>

int move = 0;

int Swap(int& a, int& b){
	int temp = a;
	a=b;
	b=temp;
}

void QuickSort(int a[], int left, int right){
	int i, j, index;
  
  	index = a[(left+right)/2];
  	
  	i = left; j = right;
  
  	while(i < j){
    	while(a[i] < index) i++;
     	while(a[j] > index) j--;
      
      	if( i <= j ) 
        {	if(j!=i){
         	Swap(a[i], a[j]);
           move++;
        }
         i++; j--;
        }
    }
  
 if(left < j) QuickSort(a, left, j);
 if(i < right) QuickSort(a, i, right);
}

int main(){
	int n; scanf("%d", &n);
	int a[n];
  
  	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
  
  
  	QuickSort(a, 0, n-1);	
	
  
  	printf("%d\n", move);
  
  	for(int i = 0; i < n; i++){
    printf("%d ", a[i]);
    }
           
  return 0;
}
