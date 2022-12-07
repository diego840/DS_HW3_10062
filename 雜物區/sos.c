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
/*


    if (n==1){
        //printf("3\n");
        if (a%2==0){
            if (r_n>=w_n){
                rw_number+=1;
                printf("%d\n",rw_number);
            }
        }else if(a%2==1){
            if (r_n>w_n){
                rw_number+=1;
                printf("%d\n",rw_number);
            }
        }
        return ;
    }else if (rw==b){
        //printf("1\n");
        rw_number+=1;
        printf("%d\n",rw_number);
        return ;
    }else if(ww==b){
        //printf("2\n");
        return ;
    } 
*/