/*  {An_HQ_HW} 1
int main(){
    float x,y,f;
    int k;
    scanf("%f %f %d",&x, &y, &k);
    if(x>=0 && y>=0 && x<=1000 && y<=1000){
        if(k >= 0 && k <= 5){
            if(k==0){
                f = (x+y)+0.05;
                printf("%.0f\n",f);
            }else{
                printf("%.*f\n",k,x+y);
            }
        }
    }
    return 0;
}
*/

/*  {Be_More_Innovative} 2
#include<stdio.h>
#include <string.h>
int main(){
    int one,two,three;
    char first[50];     
    char second[50];    
    char copyfirst[50];
    char copysecond[50];
    char outout[50];    
    for(int i=0;i<21;i++){
        copyfirst[i] = 0;
        copysecond[i] = 0;
        outout[i] = 0;
    }
    scanf("%s",first);
    scanf("%s",second);
    one = strlen(first);
    two = strlen(second);
    if(one <= 20 && two <=20){   
        for(int j=0;j<20;j++){
            copyfirst[j]=first[j]-'0';
            copysecond[j]=second[j]-'0';
        }

        for(int ij=0;ij<20;ij++){      
            outout[ij] = copyfirst[ij] + copysecond[ij];
        }

        for(int x=19;x>=0;x--){         
            if(outout[x] >= 10){
                outout[x-1] = outout[x-1]+(outout[x]/10);
                outout[x] = outout[x]%10;
            }
        }


        for(int k=0;k<20;k++){          
            printf("%d",outout[k]);
        }
    }

    return 0;
}
*/

/*
