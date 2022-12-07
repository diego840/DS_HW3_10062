#include<stdio.h>
int main(){
    int a,b,c,d;
    scanf("%d %d",&a,&b);
    int aa[a];
    for (int i = 0; i < a; i++)
    {
        scanf("%d",&c);
        aa[i] = c;
    }

    for (int j = 0; j < b; j++)
    {
        scanf("%d",&d);
        printf("%d\n",aa[d]);
    }
    return 0;
}