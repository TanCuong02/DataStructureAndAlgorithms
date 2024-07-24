#include<stdio.h>

int compare = 0;
int move = 0;

int InsertionSort(int n, int a[]){

  int pos;
  int index;
  
	for(int i = 1; i < n; i++){
    	index = a[i];
      	for(pos = i; pos > 0; pos--){
         compare++;
        if(a[pos-1] > index) {
          	a[pos] = a[pos-1];
		}else break;
      move++;
		}
        a[pos] = index;
   }
}

int main(){
	int n; scanf("%d", &n);
	
	int a[n];
  
  	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
  
  
  	InsertionSort(n,a);	
	
  
	printf("%d ", compare);
  	printf("%d\n", move);
  
  	for(int i = 0; i < n; i++){
    printf("%d ", a[i]);
    }
           
  return 0;
}
