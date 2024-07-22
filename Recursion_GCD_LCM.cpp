#include <stdio.h>
int UCLN(int a, int b)
{
    while ( a != b)
    {
        if (a > b)
            a = a - b;
        else
            b = b - a;
    }
    return a; 
}

int BSCNN(int a, int b) {
    return (a * b) / UCLN(a, b);
}
 
int main()
{
    int a, b;
    scanf("%d",&a);
    scanf("%d",&b);
  
    printf("%d ", UCLN(a, b));
    printf("%d ", BSCNN(a, b));
}
