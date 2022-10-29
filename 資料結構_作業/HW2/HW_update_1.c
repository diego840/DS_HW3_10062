#include<stdio.h>
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 1050
int resource_y,resource_x,req;
char shape[max];
int i_shape[max][max];
int tot_shape[max];
int sort_tmp[max];
char *token;
void input(){
    scanf("%d %d %d",&resource_y,&resource_x,&req);
    for (int i = 0; i < req; i++){
        scanf("%*c %[^\n]",shape);
        int req_index = 0;
        token = strtok(shape,"x ");
        while (token != NULL){
            if (req_index > 0){
                i_shape[i][req_index-1] = atoi(token);
            }
            req_index++;
            token = strtok(NULL,"x ");
        }
        tot_shape[i] = req_index - 1;
        i_shape[i][req_index-1] = -1;
    }

}
int cmpmax(const void * a, const void * b){
    return( *(int*)a - *(int*)b );    
}
int cmpmin(const void * a,const void * b){
    return( *(int*)b - *(int*)a );
}
void Row_Sorting(int x){
    for (int i = 0; i < req; i++){
        if (tot_shape[i] > 2){
            for (int j = 0,jj = 0; i_shape[i][j] != -1; j = j+2,jj++){
                sort_tmp[jj] = i_shape[i][j];
            }
            if (x == 0){
                qsort(sort_tmp,(tot_shape[i]/2),sizeof(int),cmpmax);
            }else{
                qsort(sort_tmp,(tot_shape[i]/2),sizeof(int),cmpmin);
            }
            for (int k = 0,kk = 0; i_shape[i][k] != -1;k = k+2,kk++){
                i_shape[i][k] = sort_tmp[kk];
                i_shape[i][k+1] = resource_y/sort_tmp[kk];
            }
        }      
    }
}
void swap(int x, int y){
    memset(sort_tmp,0,sizeof(sort_tmp));
    memcpy(sort_tmp,i_shape[x],sizeof(i_shape[x]));
    memcpy(i_shape[x],i_shape[y],sizeof(i_shape[x]));
    memcpy(i_shape[y],sort_tmp,sizeof(i_shape[x]));
    int tmp = tot_shape[x];
    tot_shape[x] = tot_shape[y];
    tot_shape[y] = tmp;
}
/*void Column_QuickSort(int left,int right){
    if (left < right){
        int formula = (left+right)/2;
        int pivot = i_shape[formula][0];
        int i = left-1;
        int j = right+1;

        while (1){
            while(i_shape[++i][0] > pivot);
            while(i_shape[--j][0] < pivot);
            if (i >= j){
                break;
            }
            swap(i,j);
        }
        Column_QuickSort(left,i-1);
        Column_QuickSort(j+1,right);
    }
}*/
void Column_QuickSort(int left,int right){
    if (left < right){
        int formula = (left+right)/2;
        int pivot = tot_shape[formula];
        int i = left-1;
        int j = right+1;

        while (1){
            while(tot_shape[++i] < pivot);
            while(tot_shape[--j] > pivot);
            if (i >= j){
                break;
            }
            swap(i,j);
        }
        Column_QuickSort(left,i-1);
        Column_QuickSort(j+1,right);
    }
}13
void Print(){
    for (int i = 0; i < req; i++){
        for (int j = 0; i_shape[i][j] != -1; j++){
            printf("%d ",i_shape[i][j]);   
        }
        printf("\ntot_shape: %d",tot_shape[i]);
        printf("\n");
    }
}
int main(){
    input();
    Row_Sorting(1);
    Column_QuickSort(0,req-1);
    Print();
    
    return 0;
}