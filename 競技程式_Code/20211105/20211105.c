#include<stdio.h>
#include<math.h>
#include<string.h>
int length();
double lengthh(int x, int y);
double lengthhh(int x, int y, int z);
char c[30];

int main(){
    int a,b,x,y,xx,yy,zz;
    scanf("%d",&a);
    for (int i = 0; i < a; i++){
        scanf("%d",&b);
        if (b==1){
            printf("%d\n",length());
        }else if (b==2){
            scanf("%d %d",&x,&y);
            printf("%.7f\n",lengthh(x,y));
        }else{
            scanf("%d %d %d",&xx,&yy,&zz);
            printf("%.7f\n",lengthhh(xx,yy,zz));
        }    
    }
    return 0;
}

int length(){
    int q;
    scanf("%s",c);
    q=strlen(c);
    return q;
}
double lengthh(int x, int y){
    double q;
    q = pow(x,2)+pow(y,2);
    return sqrt(q);
}
double lengthhh(int xx, int yy, int zz){
    double q;
    q = pow(xx,2)+pow(yy,2)+pow(zz,2);
    return sqrt(q);
}

// #include<stdio.h>
// long long int Golden_ratio(long long int a);
// int main(){
//     long long int a;
//     while (scanf("%lld",&a)){
//         if(a==-1){
//             break;
//         }else{
//             printf("%lld\n",Golden_ratio(a));
//         }
//     }
//     return 0;
// }
// long long int Golden_ratio(long long int a){
//     if (a==0)   return 1;
//     else if (a==1)  return 1;
//     else{
//         return Golden_ratio(a-1)+Golden_ratio(a-2);
//     }    
// }


// #include<stdio.h>
// int main(){
//     long long int a,b,c;
//     scanf("%lld %lld",&a,&b);
//     while (b){
//         c=a;
//         a=b;
//         b=c%a;
//     }    
//     printf("%lld\n",a);
//     return 0;
// }


// #include<stdio.h>
// void oo(char a,long long int b,long long int c);
// int main(){%d
//     char a;
//     long long int b,c;
//     while (scanf(" %c",&a) != EOF){
//         scanf("%lld %lld",&b,&c);
//         oo(a,b,c);
//     }
//     return 0;
// }
// void oo(char a,long long int b,long long int c){
//    if (a == '+'){
//         printf("%lld\n",b+c);
//     }else if (a == '-'){
//         printf("%lld\n",b-c);
//     }else if (a == '*'){
//         printf("%lld\n",b*c);
//     }
// }