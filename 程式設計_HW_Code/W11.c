/* A{點名}
#include<stdio.h>
#include<string.h>
#define SIZE 105
int n,q,x;
char Name_two[101];
char Value;
unsigned long long int ID_two;
typedef struct {
    char Name[101];
    unsigned long long int ID;
    int Score[3];    
}student;
int main(){
    scanf("%d %d",&n,&q);

    student number[SIZE];
    for (int i = 0; i < n; i++){
        scanf("%s",number[i].Name);
        scanf("%llu",&number[i].ID);
        scanf("%d%d%d",&number[i].Score[0],&number[i].Score[1],&number[i].Score[2]);
    }
    for (int j = 0; j < q; j++){
        scanf("%d",&x);
        if(x==1){
            scanf("%s",Name_two);
            for (int k = 0; k < n; k++){
                if(strcmp(Name_two,number[k].Name)==0){
                    printf("%llu\n",number[k].ID);
                }
            }
        }else if(x==2){
            scanf("%s",Name_two);
            for (int k = 0; k < n; k++){
                if(strcmp(Name_two,number[k].Name)==0){
                    scanf("%*c%c",&Value);
                    if(Value=='L'||Value=='l') printf("%d\n",number[k].Score[0]);
                    else if (Value=='C'||Value=='c') printf("%d\n",number[k].Score[1]);
                    else printf("%d\n",number[k].Score[2]);
                }
            }
        }else if(x==3){
            scanf("%llu",&ID_two);
            for (int ii = 0; ii < n; ii++){
                if(ID_two==number[ii].ID) printf("%s\n",number[ii].Name);
            }    
        }else{
            scanf("%llu",&ID_two);
            scanf("%*c%c",&Value);
            for (int jj = 0;jj < n;jj++){
                if(ID_two==number[jj].ID){
                    if(Value=='L'||Value=='l') printf("%d\n",number[jj].Score[0]);
                    else if (Value=='C'||Value=='c') printf("%d\n",number[jj].Score[1]);
                    else printf("%d\n",number[jj].Score[2]); 
                }
            }
            
        }
    }
    return 0;
}
//5 4 
//Watame 410410606 100 100 40
//Baelz 410410229 76 80 100
//Watson 410410913 99 98 100 
//Kanata 410411227 75 85 45
//Botan 410410814 68 95 80
//1 Watame
//2 Baelz E
//3 410410913
//4 410411227 L
*/
/* B{藍鯊遊戲}
#include<stdio.h>
unsigned long long int x,y;
int a,b,c;
int main(){
    scanf("%llu%llu",&x,&y);
    while (x>0||y>0){
        if((x%2)&(y%2)) a++;
        if((x%2)|(y%2)) b++;
        if((x%2)^(y%2)) c++;
        x/=2;
        y/=2;
    }
    printf("%d %d %d\n",a,b,c);
    return 0;  
}
*/ 
/* B{藍鯊遊戲}_第二種解法
#include<stdio.h>
int one[100];
int two[100];
unsigned long long int x,y;
int n,i=0,number;
long long int first=0,second=0,third=0;
int Calculate(unsigned long long int a){
    while (a>0){
        a/=2;
        i++;
    }
    return i;
}
void Conversion(int num,unsigned int z,int* array){
    for (int i = num-1; i >= 0; i--){
        if(z>0){
            array[i]=z%2;
            z/=2;
        }else{
            array[i]=0;
        }
    }
}
int main(){
    scanf("%llu%llu",&x,&y);
    if (x>y) number=Calculate(x);
    else number=Calculate(y);
    Conversion(number,x,one);
    Conversion(number,y,two);
    for (int k = 0; k < number; k++){
        if(one[k]&two[k]) first++;;
        if(one[k]|two[k]) second++;
        if(one[k]^two[k]) third++;
    }
    printf("%lld %lld %lld\n",first,second,third);
    return 0;
}
*/
/* C{西薩密碼}
#include<stdio.h>
#include<string.h>
#define SIZE 100000
typedef unsigned long long int ulli;
ulli t,length,A_x=0,length_two; //A_x當作Answer的長度
int  T[SIZE]; //存放%256的值
int HEX=4; 
char Ciphertext[SIZE]={0}; //存放的密鑰
char Answer[SIZE]={0}; //存放的明文
void FIRST_XOR(int a,int b){        //進行第一次XOR
    for (int i = a-1; i >= 0; i--){
        Answer[A_x++]=T[i]^Ciphertext[A_x%b];//^Ciphertext[((A_x%b)+(b-1))%b]
    }
}
void SECOND_XOR(int a,int b){       //進行第二次XOR
    for (int i = a-1; i >= 0; i--){
        Answer[i]^=Ciphertext[(a-i-1)%b];
    }
}
int main(){
    scanf("%s",Ciphertext);
    length=strlen(Ciphertext);
    while (scanf("%llu",&t) != EOF){
        for (int i = 0; i < 4; i++){
            T[i]=t%256; 
            //printf("T[%d] = %d\n",i,T[i]); //test轉換  T[3]=44={4*16+4*1}=68(10)
            t/=256;
        }
        FIRST_XOR(HEX,length);
    }
    //printf("%llu\n",A_x);
    SECOND_XOR(A_x,length);
    printf("%s\n",Answer);
}
*/
/* C{西薩密碼}_第二種解法
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char ary[100000]={0};
char ans[1000000000]={0};
unsigned long long int numAry[55];
unsigned long long int num,len=0,aryLen;


int main(){
    scanf("%s",ary);
    aryLen=strlen(ary);
    while(scanf("%llu",&num)!=EOF){
        for(int j=3;j>=0;j--){
            numAry[j]=num%256;
            num/=256;
        }
        for(int j=0;j<4;j++){
            ans[len]=numAry[j]^ary[len%aryLen];
            len++;
        }
    }
    for(int i=len-1;i>=0;i--){
        ans[i]=ans[i]^ary[(len-1-i)%aryLen];
    }
    printf("%s\n",ans);
}
*/