#include<stdio.h>
#define SIZE 2
typedef struct table table;

struct table{
    int a,b;
};

table function_one(table aa[]){
    table b = { aa[0].a-aa[1].a , aa[0].b-aa[1].b};
    return b;
}
table function_two(table aa[]){
    table b = { (aa[0].a*aa[1].a)+((aa[0].b*aa[1].b)*-1),(aa[0].a*aa[1].b)+(aa[0].b*aa[1].a)};
    return b;
}

int main(){
    table number[SIZE];
    for (int i = 0; i < SIZE; i++){
        scanf("%d %d",&number[i].a,&number[i].b);
    }
    table ans = function_one(number);
    table ans_two = function_two(number);
    printf("%d %d\n",ans.a,ans.b);
    printf("%d %d\n",ans_two.a,ans_two.b);
}
