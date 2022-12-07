/* A{維吉尼亞密碼}
#include<stdio.h>
#include<string.h>
#include <ctype.h>
char str[100100];
char key[100100];
char solution[100100];
long long int str_length,key_length;
void encryption(long long int s,long long int k){  //s:str_length k:key_length
    for (int i = 0; i < s; i++){
        if (str[i] >= 'a' && str[i] <= 'z'){
            if(key[i%k] >= 'A' && key[i%k] <= 'Z'){
                solution[i]=(str[i]-'a'+(key[i%k]+32)-'a')%26+'a'; //轉換大->小(+32)
                //solution[i]=(str[i]-'a'+tolower(key[i%k])-'a')%26+'a'; //函式tolower轉換
            }else{
                solution[i]=(str[i]-'a'+key[i%k]-'a')%26+'a';
            }
        }else{
            if(key[i%k] >= 'a' && key[i%k] <= 'z'){
                solution[i]=(str[i]-'A'+(key[i%k]-32)-'A')%26+'A'; //轉換小->大(-32)
                //solution[i]=(str[i]-'A'+ toupper(key[i%k])-'A')%26+'A'; //函式toupper轉換
            }else{
                solution[i]=(str[i]-'A'+key[i%k]-'A')%26+'A';
            }
        }
    }
}
int main(){
    scanf("%s",str);
    scanf("%s",key);
    str_length=strlen(str);
    key_length=strlen(key);
    encryption(str_length,key_length);
    printf("%s\n",solution);
    return 0;
}
*/
/* B{考卷整理}
#include<stdio.h>
#include<string.h>
#include<ctype.h>
int n=0,CCU;
char name[1000][105];
char Tentative[105]={0};
void name_bubber_sort(int k){
    for (int i = 0; i < k-1; i++){
        for (int j = i+1; j < k; j++){
            if(strcmp(name[i],name[j]) > 0){//strcmp(str1,str2) str1>str2傳正 str1==str2傳0 str1<str2傳負
                strcpy(Tentative,name[i]);
                strcpy(name[i],name[j]);
                strcpy(name[j],Tentative);
            }
        }
    }
}
int main(){
    while (scanf("%[^\n]",name[n++])!=EOF){
        getchar();
    }
    name_bubber_sort(n-1);
    for (int j = 0; j < n-1; j++){
        printf("%s\n",name[j]);
    }
    return 0;
}
*/
/* C{字數計算}
#include<stdio.h>
#include<ctype.h>
#include<string.h>
char array[10001010];
long long int length,answer,a=0;
int main(){
    while (fgets(array,sizeof array,stdin)!=NULL){
        length = strlen(array);
        for ( int i=0; i < length; i++){
            if(isalpha(array[i])!=0){
                if(a==0){
                    a=1;
                    answer++;
                }
            }else{
                a=0;
            }
        }
    }
    printf("%lld\n",answer);
    return 0;
}
*/
/* D{詞頻統計}
#include<stdio.h>
#include<string.h>
#include<ctype.h>
char arrasy[200000][200];
char arrasy_two[200000][200];
int number[100000];
char Tentative[20000]={0};
int n,value=0,value_two=0;
void change(int m){ //轉換含式(先把所有讀近來地轉換成小寫)
    int extent;
    for (int i = 0; i < m; i++){
        extent = strlen(arrasy[i]);
        for (int j = 0; j < extent; j++){
            arrasy[i][j]=tolower(arrasy[i][j]);
        }
    }
}
void bubber_sort(int k){ //排列含式(把所有的單詞作排列)
    for (int i = 0; i < k-1; i++){
        for (int j = i+1; j < k; j++){
            if(strcmp(arrasy[i],arrasy[j]) > 0){//strcmp(str1,str2) str1>str2傳正 str1==str2傳0 str1<str2傳負
                strcpy(Tentative,arrasy[i]);
                strcpy(arrasy[i],arrasy[j]);
                strcpy(arrasy[j],Tentative);
            }
        }
    }
}
void calculate(int l){ //計算含式(把陣列中的所有的單詞作計算)然後重複的只計算一次
    for (int i = 0; i < l; i++){
        int ans=1;
        while(strcmp(arrasy[i],arrasy[i+1])==0){
            ans++;
            i++;
        }
        strcpy(arrasy_two[value++],arrasy[i]);
        number[value_two++]=ans;
    }
}
int main(){
    while (scanf("%[^\n \t]",arrasy[n++])!=EOF){
        getchar();
    }
    change(n-1); //轉換小寫
    bubber_sort(n-1); //做排序(可以換排序方法)
    calculate(n-1); //計算出現的單字
    for (int i = 0; i < value; i++){
        printf("%s %d\n",arrasy_two[i],number[i]);
    }
    return 0;
}
*/
/* E{成績統計}
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char array[5000000];
char *token;
long long int answer=0,n=0,a=0;
int main(){
    while (fgets(array,sizeof array,stdin)!=NULL){
        answer=0;
        a=0;
        token=strtok(array, " \n \r");
        while (token!=NULL){
            a++; //防止換行也直接輸出0
            answer+= atoi(token);
            //printf("%s\n",token);
            token=strtok(NULL, " \n\r");
        }
        if(a!=0){
            printf("%lld\n",answer);
        }
    }
    return 0;
}
6 9 420
74 14
214 74 386 47
*/