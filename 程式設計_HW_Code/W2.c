#include<stdio.h>
#include<math.h>
int main(){
    float x,y,a;
    scanf("%f %f",&x,&y);
    if(x>=0 && x<=1000 && y>=0 && y<=1000){
        a = round(x+y);
        printf("%.f",a);
    }
    return 0;
}
