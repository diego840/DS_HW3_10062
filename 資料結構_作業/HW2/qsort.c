#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define ROW 5
int a[5][3] = {0,0,0,1,1,1,2,2,2,3,3,3,4,4,4};
int b[5];
int swap(int x, int y){
   memcpy(b,a[x],sizeof(a[x]));
   memcpy(a[x],a[y],sizeof(a[x]));
   memcpy(a[y],b,sizeof(a[x]));
}
int main(){
   swap(0,4);
   for (int i = 0; i < 5; i++){
      for (int j = 0; j < 3; j++){
         printf("%d ",a[i][j]);
      }
      printf("\n");
   }
   
   return 0;
}

// #include <stdio.h>
// #include <stdlib.h>

// int values[] = { 88, 56, 100, 2, 25 };

// int cmpmax(const void * a, const void * b){
//     return(*(int*)a - *(int*)b);    
// }
// int cmpmin(const void * a,const void * b){
//     return(*(int*)b - *(int*)a);
// }

// int main(){
//    int n;

//    printf("Before sorting the list is: ");
//    for( n = 0 ; n < 5; n++ ) {
//       printf("%d ", values[n]);
//    }
//    printf("\n");
//    qsort(values, 5, sizeof(int), cmpmax);

//    printf("After sorting the list is: ");
//    for( n = 0 ; n < 5; n++ ) {
//       printf("%d ", values[n]);
//    }
  
//   return(0);
//}