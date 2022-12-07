#include<stdio.h>
#define SIZE 1000
typedef struct score score;

struct score{
    char name[SIZE];
    int math[SIZE];
};

int function(int a,score aa[],int category){
    int max=0,value;
    for (int i = 0; i < a; i++){
        if(aa[i].math[category] > max){
            max = aa[i].math[category];
            value = i;
        }
    }
    return value;
}

int main(){
    int one;
    scanf("%d",&one);
    score number[SIZE];
    for (int i = 0; i < one; i++){
       scanf("%*c%s",number[i].name);
       scanf("%d %d %d",&number[i].math[0],&number[i].math[1],&number[i].math[2]);
    }
    for (int j = 0; j < 3; j++){
        int x;
        x = function(one,number,j);
        printf("%s ",number[x].name);
        printf("%d %d %d\n", number[x].math[0] , number[x].math[1] , number[x].math[2] );
    }
    return 0;
}