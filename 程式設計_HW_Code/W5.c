#include<stdio.h>
int main(){
    char a;
    int x=0,y=0;
    while (1){
        scanf("%c",&a);
        if(a == 'X'){
            break;
        }else{
            if(a == 'U'){
                y++;
            }else if(a == 'D'){
                y--;
            }else if(a == 'L'){
                x--;
            }else{
                x++;
            }            
        }
    }
    printf("%d %d\n",x,y);
    return 0;
}

/*  {AbsolutePass} 1
int main(){
    int a;
    int b[1001]={0};
    scanf("%d",&a);
    for (int j = 0; j < a; j++){
        printf("%d",b[j]);
    }
    return 0;
}
*/

/*  {BestStudent} 2
int main(){
    int a,b=0;
    while (scanf("%d",&a)!=EOF){
        b+=a;
    }
    printf("%d",b);
    return 0;
}
*/

/*  {Creator}     3
int main(){
    int a;
    scanf("%d",&a);
    if (a<=100 && a>=1){
        for (int i = a; i > 0 ; i--){
            for (int j = 0; j < i ; j++){
                printf("*");
            }
            printf("\n");      
        }
    }
    return 0;
}
*/

/*  {Delicacy}    4
int main(){
    long long int s,a,b,c,aa,bb;
    scanf("%lld %lld",&a,&b);
    aa = a;
    bb = b;
    while (b){
        c=a;
        a=b;
        b=c%a;
    }
    aa/=a;
    bb/=a;
    s = aa*bb*a;
    
    printf("%lld\n",s);
    return 0;
}
*/

/*  {Explorer}    5
int main(){
    char a;
    int x=0,y=0;
    while (1){
        scanf("%c",&a);
        if(a == 'X'){
            break;
        }else{
            if(a == 'U'){
                y++;
            }else if(a == 'D'){
                y--;
            }else if(a == 'L'){
                x--;
            }else{
                x++;
            }            
        }
    }
    printf("%d %d\n",x,y);
    return 0;
}
*/