#include<stdio.h>
int main(){

}

/*  {Academy} 1
int main(){
    int a;
    scanf("%d", &a);
    if(a >= 0 && a <=100 ){
        if(a >= 90 && a <= 100){
            printf("A+\n");
        }else if(a >= 85 && a <= 89){
            printf("A\n");
        }else if(a >= 80 && a <= 84){
            printf("A-\n");
        }else if(a >= 77 && a <= 79){
            printf("B+\n");
        }else if(a >= 73 && a <= 76){
            printf("B\n");
        }else if(a >= 70 && a <= 72){
            printf("B-\n");
        }else if(a >= 67 && a <= 69){
            printf("C+\n");
        }else if(a >= 63 && a <= 66){
            printf("C\n");
        }else if(a >= 60 && a <= 62){
            printf("C-\n");
        }else if(a >= 50 && a <= 59){
            printf("D\n");
        }else{
            printf("E\n");
        }
    }
    return 0;
}
*/

/*  {Baecar} 2
int main(){
    int size = 10;
    char number[11];
    int nnn;
    int vv=0;
    for(int i=0;i <= size;i++){
        if(i==10){
            scanf("%d",&nnn);
        }else{
            scanf("%c",&number[i]);
        }
    }
    if(nnn>=0 && nnn<=9){
        for(int j=0;j <= size;j++){
            if(j == size){
                vv = 1;
            }else if(number[j] >= 'A' && number[j] <= 'Z'){
                number[j] = (number[j]-'A'+nnn)%26+'A';
            }else if(number[j] >= 'a' && number[j] <= 'z'){
                number[j] = (number[j]-'a'+nnn)%26+'a';
            }else{
                break;
            }
        }
    }

    if(vv == 1){
        number[10] = 0;
        printf("%s",number);
        vv=0;
    }else{
    }
    return 0;
}
*/

/*  {Crab_Game} 3
int main(){
    int a,b,i,j;
    int k=0;
    int aa[6],bb[6];
    scanf("%d %d",&a,&b);
    if(a>=0 && b>=0 && a<=31 && b<=31){
        for(i=0;a>0;i++){
            aa[i] = a%2;
            bb[i] = b%2;
            a/=2;
            b/=2;
        }
        for(j=0;j<i;j++){
            if( aa[j] == bb[j] && aa[j] == 1 && bb[j] == 1 ){
                k++;
            }else{
                k = k;
            }
        }
        printf("%d",k);
    }
    return 0;
}
*/

/*  {Crab_Game} 3
int main(){
    int x,y,z,i,s=0;
    scanf("%d%d", &x, &y);
    z=x&y;
    printf("%d\n",z);
    for(i=1;i<=5;i++){
        if(z%2==1){
            s+=1;
        }
        z/=2;
        printf("%d\n",z);
    }
    printf("%d",s);

}
*/