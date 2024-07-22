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
	printf("Nhap so phan tu: ");
	scanf("%d", &n);
		
	int x;  
	printf("Nhap so can tim: ");
	scanf("%d", &x);
	
	int* a = new int [n];
	
	for(int i = 0; i < n ;i++){
		printf("Nhap so o vi tri %d tim: ", i);
		scanf("%d", &a[i]);
	}
	
	
	int LinearSearch = Ls(a,n,x);
	
	printf("So lan dem: %d \n", count);
	
	printf("Vi tri can tim: %d",LinearSearch);
	
	return 0;
}
