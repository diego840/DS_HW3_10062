#include<stdio.h>
int main(){
    int x1,y1,x2,y2,x3,y3,a,b,c;
    scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
    a = (x1+x3)-x2;
    b = (x1+x2)-x3;
    c = (x2+x3)-x1;
    printf("%d %d\n",(x1+x3)-x2,(y1+y3)-y2);
    printf("%d %d\n",(x1+x2)-x3,(y1+y2)-y3);
    printf("%d %d\n",(x2+x3)-x1,(y2+y3)-y1);
}