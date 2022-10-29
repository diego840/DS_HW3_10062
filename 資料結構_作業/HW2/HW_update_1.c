#include<stdio.h>
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 1050
//  char
char shape[max]; //存每行input的share (字串型態)
char *token; //strtok中的token
//  int
int resource_y,resource_x,req;
//存一條ID中各種型態的shape !use function:[input,Row_sorting,swap,Column_sorting,Print]
int candidate_shape[max][max]; // [Y][X] 
int shape_num[max]; //存一條ID中有多少組的Shape !use function:[input,Row_sorting,swap,Print]
int original_ID[max]; //存sorting前的ID !use function:[input,swap,Print]
int tmp_list[max];  //tmp list !use function:[Row_sorting,swap]
//  輸入
void input(){
    scanf("%d %d %d",&resource_y,&resource_x,&req);
    for (int i = 0; i < req; i++){
        scanf("%*c %[^\n]",shape);
        int req_index = 0;
        token = strtok(shape,"x ");
        while (token != NULL){
            if (req_index > 0){
                candidate_shape[i][req_index-1] = atoi(token);
            }
            req_index++;
            token = strtok(NULL,"x ");
        }
        shape_num[i] = req_index - 1;
        original_ID[i] = i;
        candidate_shape[i][req_index-1] = -1;
    }
}
//  同行share排序,row sorting
int cmpmin(const void * a, const void * b){
    return( *(int*)a - *(int*)b );    
}
int cmpmax(const void * a,const void * b){
    return( *(int*)b - *(int*)a );
}
void Row_Sorting(int x){
    for (int i = 0; i < req; i++){
        if (shape_num[i] > 2){
            for (int j = 0,jj = 0; candidate_shape[i][j] != -1; j = j+2,jj++){
                tmp_list[jj] = candidate_shape[i][j];
            }
            if (x == 0){
                qsort(tmp_list,(shape_num[i]/2),sizeof(int),cmpmin);
            }else{
                qsort(tmp_list,(shape_num[i]/2),sizeof(int),cmpmax);
            }
            for (int k = 0,kk = 0; candidate_shape[i][k] != -1;k = k+2,kk++){
                candidate_shape[i][k] = tmp_list[kk];
                candidate_shape[i][k+1] = resource_y/tmp_list[kk];
            }
        }      
    }
}
//  不同行shape排序,column sorting
void swap(int x, int y){
    int swap_tmp;
    memset(tmp_list,0,sizeof(tmp_list));
    memcpy(tmp_list,candidate_shape[x],sizeof(candidate_shape[x]));
    memcpy(candidate_shape[x],candidate_shape[y],sizeof(candidate_shape[x]));
    memcpy(candidate_shape[y],tmp_list,sizeof(candidate_shape[x]));
    swap_tmp = shape_num[x];
    shape_num[x] = shape_num[y];
    shape_num[y] = swap_tmp;
    swap_tmp = original_ID[x];
    original_ID[x] = original_ID[y];
    original_ID[y] = swap_tmp;
}
void Column_Sorting(int left,int right){
    if (left < right){
        int formula = (left+right)/2;
        int pivot = candidate_shape[formula][0];
        int i = left-1;
        int j = right+1;

        while (1){
            while(candidate_shape[++i][0] > pivot);
            while(candidate_shape[--j][0] < pivot);
            if (i >= j){
                break;
            }
            swap(i,j);
        }
        Column_Sorting(left,i-1);
        Column_Sorting(j+1,right);
    }
}
//  打印
void Print(){
    for (int i = 0; i < req; i++){
        for (int j = 0; candidate_shape[i][j] != -1; j++){
            printf("%d ",candidate_shape[i][j]);   
        }
        printf("\nshape_num: %d original_ID:%d",shape_num[i],original_ID[i]);
        printf("\n");
    }
}
//  main
int main(){
    input();
    Row_Sorting(1);
    Column_Sorting(0,req-1);
    Print();
    return 0;
}