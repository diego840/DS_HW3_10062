/*  {Automatic} 1
#include<stdio.h>
#include<math.h>
int one(int a,int b,int c);
int two(int a,int b,int c);
double three(int r,int h);
double four(int r,int h);
double five(int r);
double six(int r);
const double PI = 3.14159265;

int main(){
    int a,b,c;
    scanf("%d",&a);
    if (a==6){
        int sixx;
        scanf("%d",&sixx);
        printf("%.7f\n",six(sixx));
    }else if(a==5){
        int fivee;
        scanf("%d",&fivee);
        printf("%.7f\n",five(fivee));
    }else if(a==4){
        int four_x,four_y;
        scanf("%d %d",&four_x,&four_y);
        printf("%.7f\n",four(four_x,four_y));
    }else if(a==3){
        int three_one,three_two;
        scanf("%d %d",&three_one,&three_two);
        printf("%.7f\n",three(three_one,three_two));
    }else if(a==2){
        int two_x,two_y,two_z;
        scanf("%d %d %d",&two_x,&two_y,&two_z);
        printf("%d\n",two(two_x,two_y,two_z));
    }else{
        int one_x,one_y,one_z;
        scanf("%d %d %d",&one_x,&one_y,&one_z);
        printf("%d\n",one(one_x,one_y,one_z));
    }
    return 0;
}
int one(int a,int b,int c){
    return a*b*c;
}
int two(int a,int b,int c){
    return (a*b*2)+(b*c*2)+(a*c*2);
}
double three(int r,int h){
    return pow(r,2)*PI*h;
}
double four(int r,int h){
    return (pow(r,2)*PI*2)+(2*r*PI*h);
}
double five(int r){
    return pow(r,3)*4/3*PI;
}
double six(int r){
    return pow(r,2)*4*PI;
}
*/

/*  {Be_Distant} 2
#include<stdio.h>
#include<math.h>
double distance (double x1, double y1, double x2, double y2);
int main(){
    int a,b,c,d;
    while (scanf("%d %d %d %d",&a,&b,&c,&d) != EOF){
        printf("%.7f\n",distance(a,b,c,d));
    }
}
double distance (double x1, double y1, double x2, double y2) {
    double x3 = (x2-x1)*(x2-x1);
    double y3 = (y2-y1)*(y2-y1);
    double xy = x3+y3;
    return sqrt(xy);
}
*/

/*  {CrazyLove} 3
#include<stdio.h>
int isPrime(int b);
int good = 0;
int main(){
    int a,b;
    scanf("%d",&a);
    for (int i = 0; i < a; i++){
        scanf("%d",&b);
        isPrime(b); 
    }    
}
int isPrime(int b){
    if(b < 2) return printf("False\n");           
    for(int i = 2; i * i <= b; ++i){
        if(b % i == 0) return printf("False\n");
    } 
    return printf("True\n");                       
}
*/
// 請參考
// https://zh.wikipedia.org/wiki/%E7%B4%A0%E6%80%A7%E6%B5%8B%E8%AF%95



