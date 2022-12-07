#include <stdio.h>
int main()
{
    int x, n;
    int a = 0;
    scanf("%d", &n);
    while (n > 0)
    {
        x = n & 1;
        printf("D%d=%d ", a++, x);
        n = n / 2;
    }
}
/*
#include <stdio.h>
int main()
{
    int f, c[5];
    int a = 0;
    scanf("%d", &f);
    while (f > 0)
    {
        c[a] = f % 2;
        a++;
        f = f / 2;
    }
    printf("D3=%d ", c[3]);
    printf("D2=%d ", c[2]);
    printf("D1=%d ", c[1]);
    printf("D0=%d ", c[0]);
}
*/