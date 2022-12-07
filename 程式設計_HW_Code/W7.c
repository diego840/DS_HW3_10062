
/* A{處理小數點相等}
#include<stdio.h>
const double x = 0.000001;
const double y = -0.000001;
int main(){
    double a,b,c,d,e;
    scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
    e = (a+b+c);
    //printf("%g\n",e);
    //printf("%g\n",d-e);
    if (d-e<x && d-e>y){
        printf("Equal to\n");
    }else if (d>e){
        printf("Less than\n");
    }else{
        printf("Greater than\n");
    }
    return 0;
}
*/

/* B{數學作業}
#include<stdio.h>
int homework(int c);
int a,b,c;
int main(){
    scanf("%d %d %d",&a,&b,&c);
    printf("%d",homework(c));
}
int homework(int c){
    if (c==1) return a;
    else if (c==2) return b;
    else{
        if (c%2==1){
            return homework(c-1)+homework(c-2);
        }else{
            return 2*homework(c-1);
        }
    }
}
*/

/* C{聯合運動會}
#include<stdio.h>
void challenge(int n,int rw,int ww,int r_n,int w_n);
int a,b;
int rw_number=0;
int main(){
    scanf("%d %d",&a,&b);
    challenge(a,1,0,1,0);
    //printf("\n");
    challenge(a,0,1,0,1);
    printf("%d",rw_number);
}
void challenge(int n,int rw,int ww,int r_n,int w_n){
    //printf("(n=%d,rw=%d,ww=%d,r_n=%d,w_n=%d)!\n",n,rw,ww,r_n,w_n);
    //printf("%d\n",rw_number);
    // printf("r_n is number:%d and w_n is number:%d\n",r_n,w_n);
    if (rw==b){
        rw_number+=1;
        return;
    }
    if(ww==b){
        return;
    }
    if (n==1){
        if (r_n>=w_n){
            rw_number+=1;
        }
        return ;
    }
    challenge(n-1,rw+1,0,r_n+1,w_n);
    challenge(n-1,0,ww+1,r_n,w_n+1);
    return;

}
*/