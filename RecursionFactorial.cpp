#include<stdio.h>

long giaithua(long n){
	if (n > 0) {
      return n * giaithua(n - 1);
   }
   else {
      return 1;
   }
}

int main() {

   long n; scanf("%ld", &n);

   printf("%ld", giaithua(n));

}

