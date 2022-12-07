/*
    二分搜尋法
*/
#include<stdio.h>
long long int N,M,ans,B;
long long int num;
long long int array[100100];
int function(int a,int b){ //b是陣列長度,a是要找的數字
    int left=0;
    int right=b-1;
    while (left<=right){  //要加等於是因為有可能為left或right
        int mid = left+(right-left)/2;
        if (array[mid]>a){
            right = mid-1;
        }else if (array[mid]<a){
            left = mid+1;
        }else{
            return mid;
            break;
        }
    }
    return -1;
}
int main(){ 
    scanf("%lld",&N);
    for (int i = 0; i < N; i++){
        scanf("%lld",&array[i]);
    }  
    scanf("%lld",&M);
    for (int j = 0; j < M; j++){
        scanf("%lld",&ans);
        B=function(ans,N);
        if (B!=-1){
            printf("%lld\n",B+1);
        }else{
            printf("-1\n");
        }
    }
    
    return 0;
}