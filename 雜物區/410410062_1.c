#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 1050
int resource_y,resource_x,req;
char shape[100];
int i_shape[max][max];
int req_shape[max][max];
int i_shape_index = 0;
int req_shape_x = 0;
int req_shape_index = 0;
char *token;

//122
void input(){
    scanf("%d %d %d",&resource_y,&resource_x,&req);
    for (int i = 0; i < req; i++){
        scanf("%*c %[^\n]",shape);
        int req_index = 0;
        token = strtok(shape,"x ");
        while (token != NULL){
            i_shape[i][req_index++] = atoi(token);
            token = strtok(NULL,"x ");
            //printf("token: %s\n",token);
        }
        i_shape[i][req_index] = -1;
    }
    if (resource_x){
    }
    
}
void baseline(){
    for (int i = 0; i < req; i++){
        if (i_shape[i][1] != -1){
            if (req_shape_x + i_shape[i][2] <= resource_x && i_shape[i][1] <= resource_y){
                req_shape[req_shape_index][0] = i_shape[i][0];
                req_shape[req_shape_index][1] = i_shape[i][1];
                req_shape[req_shape_index][2] = i_shape[i][2];
                req_shape[req_shape_index][3] = 0;
                req_shape[req_shape_index][4] = req_shape_x;
                req_shape_index++;
                req_shape_x += i_shape[i][2];      
            }
        }
    }
}
void print_share(){
    printf("%d\n",req_shape_index);
    for (int i = 0; i < req_shape_index; i++){
        printf("%d ",req_shape[i][0]);
        printf("%dx%d ",req_shape[i][1],req_shape[i][2]);
        printf("%d %d\n",req_shape[i][3],req_shape[i][4]);
    }
    
}
int main(){
    input();
    baseline();
    print_share();
    return 0;
}
