#include<stdio.h>
long long int N,X;
long long int array[10000];

int dfs(int a,int b){
    if (b==X) return 1;
    if (a==N) return 0;
    return dfs(a+1,b)+dfs(a+1,array[a]+b);
}
int main(){
    scanf("%lld%lld",&N,&X);
    for (int i = 0;i < N;i++){
        scanf("%lld",&array[i]);
    }
    if(dfs(0,0)!=0){
        printf("YES\n");
    }else{
        printf("NO\n");
    }
    return 0;
}