#include<stdio.h>
int main(){
    int array[3][5]={0};
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 5; j++){
            printf("%p\n",&array[i][j]);
        }
    }
    printf("\n");
    printf("&array[1][0]:\n");
    printf("%p\n",&array[1][0]);
    printf("%p\n",(int *)array + 5);
    
}