#include<stdio.h>
int main(){
    int a,l,r;
    long long int b=0;
    scanf("%d",&a);
    long long int aa[a];
    for (int i = 0; i < a; i++)
    {
        scanf("%lld",&aa[i]);
    }
    while (scanf("%d %d",&l,&r) != EOF){
        for (int j = (l-1); j < r ; j++){
           b+=aa[j]; 
        }
        printf("%lld\n",b);
        b=0;
    }
    return 0;
}