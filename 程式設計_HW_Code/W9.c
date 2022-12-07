
/* A{排隊}
#include<stdio.h>
int height[600];
int main(){
    int a,b,c,max;
    scanf("%d %d",&a,&b);
    for (int i = 0; i < a; i++){
        scanf("%d",&height[i]);
        for(int j=0;j < i; j++){
            if (height[i]<height[j]){
                max = height[j];
                height[j]=height[i];
                height[i]=max;
            }
        }
    }
    for (int j = 0; j < b; j++){
        scanf("%d",&c);
        printf("%d\n",height[c-1]);
    }
    return 0;
}
*/
/* B{洞穴密碼} */
#include <stdio.h>
int fir_matrix[550][550];
int sec_matrix[550][550];
int third_matrix[550][550];
void input_function(int row, int column, int aa[][550])
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            scanf("%d", &aa[i][j]);
        }
    }
}
void multiply_function(int row, int m, int column, int aa[][550])
{ // 2 3 1
    int max = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            for (int k = 0; k < m; k++)
            {
                max += fir_matrix[i][k] * sec_matrix[k][j];
            }
            third_matrix[i][j] = max;
            max = 0;
        }
    }
}
void output_function(int row, int column, int aa[][550])
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            printf("%d ", aa[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int n, m, r;
    scanf("%d %d %d", &n, &m, &r);
    input_function(n, m, fir_matrix);
    input_function(m, r, sec_matrix);
    multiply_function(n, m, r, third_matrix);
    output_function(n, r, third_matrix);
    return 0;
}
/* C{數數兒}
#include<stdio.h>
long long int array[100001];
int BinarySearch_function(int left,int right,long long int focus){
    if (left < right){
        int mid = (left+right)/2;
        if (mid==0){
            if (array[left]==focus){
                return left;
            }else if(array[right]==focus){
                return right;
            }else{
                return -1;
            }
        }else if(mid==left){
            return -1;
        }else{
            if (array[mid] < focus)
                return BinarySearch_function(mid,right,focus);
            else if(array[mid] > focus)
                return BinarySearch_function(left,mid,focus);
            else
                return mid;
        }
    }
}
int main(){
    int n,q;
    long long int x;
    scanf("%d %d",&n,&q);
    for (int j = 0; j < n; j++){
        scanf("%lld",&array[j]);
    }
    for (int i = 0; i < q; i++){
        scanf("%lld",&x);
        if (BinarySearch_function(0,n,x)!=-1)
            printf("YES\n");
        else
            printf("No\n");
    }
    return 0;
}
*/
/* D{重量調整}
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
*/