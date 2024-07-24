#include<stdio.h>

int compare = 0;
int move = 0;

int BinaryInsertion(int a[], int n){
	int left, right, mid;
	int x;
  
  	for(int i = 1; i < n; i++){
     	x = a[i];
      	left = 0;
      	right = i - 1;
      
      	while(left <= right){
          mid = (left + right)/2;
          compare++;
        	if(x < a[mid]) right = mid - 1;
            else left = mid + 1;
      	}
     for(int j = i; j > left; j--){
       	a[j] = a[j-1];
      	move++;
    }
    a[left] = x;
    }
}

int main(){
	int n; scanf("%d", &n);
	
	int a[n];
  
  	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
  
  
  	BinaryInsertion(a, n);	
	
  
	printf("%d ", compare);
  	printf("%d\n", move);
  
  	for(int i = 0; i < n; i++){
    printf("%d ", a[i]);
    }
           
  return 0;
}
