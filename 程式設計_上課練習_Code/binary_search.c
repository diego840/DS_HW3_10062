#include<stdio.h>
#define SIZE 10
int mid;
int bb(int array[], int size,int key){
    int left = 0, right = size, mid;
    while ( left < right){
        mid = (left+right)/2;
        if (array[mid] < key){
            printf("array[%d]\n",mid);
            left = mid;
        }else if (array[mid] > key){
            printf("array[%d]\n",mid);
            right = mid;
        }else
            return mid;
    }
    return -1;
}
int bbb(int array[], int left,int right, int key){
    if (left < right){
        mid = (left+right)/2;
        if (array[mid] < key)
            return bbb(array,mid,right,key);
        else if(array[mid] > key)
            return bbb(array,left,mid,key);
        else
            return mid;
    }
    return -1;
    
}
int main(){
    int score[SIZE] = {45,50,66,76,78,80,85,88,90,95};
    int key = 88,index,index_two;
    index_two = bb(score,SIZE,key);
    index = bbb(score,0,SIZE,key);
    if (index != -1){
        printf("found %d at  score[%d]: %d\n", key, index, score[index]);
        printf("found %d at  score[%d]: %d\n", key, index_two, score[index_two]);
    }else
        printf("not found\n"); 
}