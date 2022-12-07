#include<stdio.h>
#include<stdlib.h>
#define SIZE 1000
int n;
long long int x2,y2,z2,jj=0;
long long int num[SIZE*SIZE];

int cmp_int(const void* _a , const void* _b){
    long long int* a = (long long int*)_a;    
    long long int* b = (long long int*)_b;
    return *a - *b;
}

typedef struct {
    long long int x;
    long long int y;
}distance;

int main(){
    scanf("%d",&n);
    distance number[SIZE];
    for (int i = 0; i < n; i++){
        scanf("%lld%lld",&number[i].x,&number[i].y);
    }

    for (int j = 0; j < n; j++){
        for (int k = j+1; k < n; k++){
            x2=(number[j].x-number[k].x)*(number[j].x-number[k].x);
            y2=(number[j].y-number[k].y)*(number[j].y-number[k].y);
            z2=(x2+y2);
            num[jj++]=z2;
        }
    }
    qsort(num,jj, sizeof(long long int), cmp_int);
    for (int i = 0; i < jj; i++){
        printf("%lld\n",num[i]);
    }
    return 0;
}