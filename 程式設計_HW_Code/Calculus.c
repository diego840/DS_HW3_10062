#include<stdio.h>
int pow_two(int x,int a){
    int num=1;
    if(a==0){
        return num;
    }else{
        for (int i = 0; i < a; i++){
            num*=x;  
        }
    }  
    return num;
}
int main(){
    long long int ans=0;
    int a,b;
    int array[1000];
    int array_two[1000];
    scanf("%d %d",&a,&b);
    for (int i = 0; i <= a; i++){
        scanf("%d",&array[i]);
    }
    for (int j = 0; j <= a; j++){
        array[j]*=j;
        array_two[j]=array[j];
        if(j>1){
            array[j]*=pow_two(b,j-1);
        }
        printf("%d\n",array[j]);
        ans+=array[j];
    }
    for (int k=1; k <= a; k++){
        printf("%d",array_two[k]);
    }
    printf("\n");
    printf("%lld",ans);
    return 0;
}