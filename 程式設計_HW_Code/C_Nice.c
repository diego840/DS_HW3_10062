#include<stdio.h>
int array[100000];
int i=0;
int GCD(int a,int b){
    if(b==0){
        return a;
    }
    int c=a%b;
    a=b;
    b=c;
    return GCD(a,b);
}
int main(){
    while(scanf("%d",&array[i++])!=EOF){
    }
    for (int j= 0; j < i-2; j++){
        array[j+1]=GCD(array[j],array[j+1]);
        //printf("%d\n",array[j+1]);
    }
    printf("%d\n",array[i-2]);
}