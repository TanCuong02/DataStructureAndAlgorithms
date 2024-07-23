#include<stdio.h>


long sumOfFirstNNumbers(long  n) {
    if (n == 0) {
        return 0;
    } else {
        return n + sumOfFirstNNumbers(n - 1);
    }
}

int main(){

   long n; scanf("%ld", &n);
  
   long  sum = sumOfFirstNNumbers(n);
  
  printf("%ld", sum);
return 0;
}
