#include<stdio.h>


int sumOfFirstNNumbers(int n) {
    if (n == 0) {
        return 0;
    } else {
        return n + sumOfFirstNNumbers(n - 1);
    }
}

int main(){

  int n; scanf("%d", &n);
  
  int sum = sumOfFirstNNumbers(n);
  
  printf("%d", sum);
return 0;
}
