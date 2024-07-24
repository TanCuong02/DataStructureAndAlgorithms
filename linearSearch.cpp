#include <stdio.h>

int count = 0;

int Ls(int a[], int n, int x){
	for(int i = 0; i< n; i++){
		count++;
		if(a[i]==x){
			return i;
		}
	}
	return -1;
}

int main(){
int n;	
	scanf("%d", &n);
		
	int x;  
	scanf("%d", &x);
	
	int* a = new int [n];
	
	for(int i = 0; i < n ;i++){
		scanf("%d", &a[i]);
	}
	
	
	int LinearSearch = Ls(a,n,x);
	
	printf("%d \n", count);
	
	printf("%d",LinearSearch);
	
	return 0;
}
