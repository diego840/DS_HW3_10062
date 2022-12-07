// #include<stdio.h>
// int GCD(int a, int b){  //最大公倍數
//     if (b) while ((a %= b) && (b %= a));
//     return a+b;
// }
// int LCM(int a, int b){
//     return a * b / GCD(a,b);
// }

// #include <string.h>
// #include <stdio.h>
// int main(){
//    const char str[80] = "This is - www.gitbook.net - website";
//    char *token;
//    token = strtok(str," -");
//    while( token != NULL ) {
//         printf( "%s", token );
//         token = strtok(NULL," -");
//     }
//    return(0);
// }

// #include<string.h>
// strcpy(存放複製的字串,將要被複製的字串);
// strncpy(存放複製的字串,將要被複製的字串,規定的數量的字元);//不會補'\0'要自己加
// strcat(要被串接的原字串,要做串接的字串);
// strncat(要被串接的原字串,要做串接的字串,規定要做串接的字串的串接數量);
// strcmp(字串1,字串2); //字串1<字串2回傳(負值) 字串1>字串2回傳(正值) 相等回傳(0)
// strncmp(字串1,字串2,最多比到第幾個字元);

// #include<stdio.h>
// char array[10001010];
// fgets(array,sizeof array,stdin)
// while(fgets(array,sizeof array,stdin)!=NULL) 


// #include<stdlib.h>
//     double atof (const char * str);//將字串轉換成double
//     int atoi (const char * str);//將字串轉換成int
//     long long int atoll (const char * str);//將字串轉換成long long int




// #include<stdio.h>
// #include<ctype.h>  //<ctype.h>
// int main(){
//     char input;
//     input = getchar();
//     isalpha(input);//檢查英文字母['A'~'Z','a'~'z']
//     isdigit(input);//檢查阿拉伯數字['0'~'9']
//     isalnum(input);//檢查阿拉伯數字['0'~'9']
//     isdigit(input);//檢查16進位數字['0'~'9','A'~'F','a'~'f']
//     islower(input);//判斷字元是否為小寫英文字母['a'~'z']
//     isupper(input);//會判斷該字元是否為大寫英文字母['A'~'F']
//     tolower(input);//會將輸入的字母從小寫轉大寫
//     toupper(input);//會將輸入的字母從大寫轉小寫
//     isblank(input);//檢查分類:空格 ['\t',' ']
//     isspace(input);//檢查分類:空白字元 ['\','\n','\v','\f','\r',' ']
//     iscntrl(input);//檢查分類:控制字元 [ASCII 碼 0～31,127]
//     ispunct(input);//檢查分類:英式符號 (不含空白) [!”#$%&’()*+,-./:;<=>?@[\]^_”{]
//     isprint(input);//檢查分類:可顯示字元 [ASCII 碼 32～126]
//     isgraph(input);//檢查分類:可顯示字元(不含空白) [ASCII 碼 32～126]
// }

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 100
int cmp(const void *a,const void *b){
    return strcmp(*(const char**)a,*(const char**)b);//排序(由小到大)
    //return strcmp(*(const char**)b,*(const char**)a);//排序(由大到小)
}
int main(){
    char **arr=(char**)calloc(10000,sizeof(char*));
    int i=0;
    arr[i] = (char*)calloc(10000,sizeof(char));
   while (scanf("%s",arr[i])!=EOF){
      i++; //"eat", "teaa", "cat", "hat", "tata", "tae"
      arr[i] = (char*)calloc(10000,sizeof(char));
   }

   qsort(arr,i,sizeof(char*),cmp);


   for (int j = 0; j < i; j++){
      printf("%s ",arr[j]);
   }

   for (int i = 0; i < 2; i++){
      free(arr[i]);
   }
   free(arr);
   return 0;
}

// #include <stdio.h>
// #include <string.h>


// #include <stdlib.h> //*字串不能這樣處理*
// long long int values[] = { 88, 56, 100, 2, 25 };
// int cmpfunc (const void * a, const void * b){
//    return ( *(long long int*)b - *(long long int*)a ); //排序(由大到小)()
//    //return ( *(long long int*)a - *(long long int*)b ); //排序(由小到大)
// }
// qsort(values, 5, sizeof(long long int), cmpfunc); 
// // qsort(陣列開頭, 陣列的寬度, 陣列型態, 比較陣列函式)


// int main(){
//    long long int n,Long;
//    printf("Before sorting the list is: \n");
//    for( n = 0 ; n < 5; n++ ) {
//       printf("%lld ", values[n]);
//    }
//    printf("\n");
//    qsort(values, 5, sizeof(long long int), cmpfunc);

//    printf("After sorting the list is: \n");
//    for( n = 0 ; n < 5; n++ ) {
//       printf("%lld ", values[n]);
//    }  
//   return(0);
// }

// #include<stdio.h>
// #include<stdlib.h>
// #define SIZE 10
// #include<stdbool.h>
// void bubbleSort (int arr[], int len){
//     int i, j,temp;
// 	_Bool exchanged = true; 
//     for (i=0; exchanged && i<len-1; i++){
//         exchanged = false; 
//         for (j=0; j<len-1-i; j++){
//             if (arr[j] > arr[j+1]){
//                 temp = arr[j];
// 				arr[j] = arr[j+1];
// 				arr[j+1] = temp;
//                 exchanged = true;
//             }
//         }
//     }
// }
// int binarty_search(int array[], int start, int end,int key){ //end必須是陣列長度-1
//     int mid,ret=-1;      //{二分搜尋法}
//     while (start <= end){
//         mid = start + (end - start) / 2; //直接平均可能會溢位
//         if(array[mid] < key) start = mid + 1; 
//         else if(array[mid] > key) end = mid - 1;
//         else{
//             ret = mid;
//             break;
//         }
//     }
//     return ret;
// }
// int main(){
//     int key,index;
//     int score[SIZE]={944,542,233,324,101,100,70,45,43,22};
//     bubbleSort(score,SIZE);
//     for (int i = 0; i < SIZE; i++){
//         printf("%d ",score[i]);
//     }
//     printf("\n");
//     return 0;
// }