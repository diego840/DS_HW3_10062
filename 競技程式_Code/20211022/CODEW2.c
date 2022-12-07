#include<stdio.h>
int main(){
    int a,b=1;
    int aa[100000];

    while (1)
    {
        scanf("%d",&a);
        if (a==0){
            break;
        }
        aa[a]=b;
        b++;
    }
    for (int i = 1; i < b; i++){
        printf("%d ",aa[i]);
    }    
}

/*
    int a,b=0;
    int aa[100000];
    int bb[100000];
    for (int i = 0; i < b+1; i++){
        scanf("%d",&a);
        if (a == 0){
            break;
        }else{
            aa[i]=a;
            b++;
        }        
    }
    for (int j = 1; j <= b; j++){
        for (int k = 0; k < b; k++){
            if (aa[k]==j){
                bb[j-1] = k+1;
            }           
        }
    }
    for (int l = 0; l < b; l++){
        printf("%d ",bb[l]);
    }   
    
*/