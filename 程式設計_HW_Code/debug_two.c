#include<stdio.h>
long long int n,x,ans=0;
int array[300100];                    
int function(int a,int b,int c){ //a是要找的數字,b是陣列長度,c是範圍初始值
    int left=c+1;
    int right=b-1;
    while (left<right){  //
        int mid = left+(right-left)/2;
        //printf("left=%d  mid=%d right=%d\n",left,mid,right);
        if (array[mid]>=a){
            right = mid-1;
        }else {
            left = mid+1;
        }
    }
    if (array[left]<a && left<b){
        left++; 
    }
    return left;
}
int main(){
    scanf("%lld %lld",&n,&x);
    for (int i = 0; i < n ;i++){
        scanf("%d",&array[i]);
    }
    for (int j = 0; j < n-1;j++){
        long long int key=x-array[j];
        ans+=(n-function(key,n,j));

    }
    printf("%lld",ans);
    
    return 0;
}