#include<stdio.h>

int count = 0;

int BinarySearch(int n, int x, int a[], int left, int right){
	
	if(left>right) return -1;
	int mid = (left+right)/2;
	
	for(int i = 0; i < n; i++){
		count++;
		if(a[mid]== x) return mid;
		if(a[mid] < x) return BinarySearch(n,x,a,mid+1,right);
		if(a[mid] > x) return BinarySearch(n,x,a,left,mid-1);
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
	
	int binary = BinarySearch(n,x,a,0,n-1);
	
	printf("%d \n", count);
	printf("%d", binary);
}
