#include<stdio.h>

int giaithua(int n){
	if (n > 0) {
      return n * giaithua(n - 1);
   }
   else {
      return 1;
   }
}

int main() {

   int n; scanf("%d", &n);

   printf("%d", giaithua(n));

}

