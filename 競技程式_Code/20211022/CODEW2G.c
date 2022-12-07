#include<stdio.h>

int main(){
    int a,b;
    int d=0,g=0;
    int e,f,h=0;
    scanf("%d %d",&a,&b);
    int c[a]; // a = 5, {3, 1, 2, 1, 1}

    for(int i=0;i<a;i++){
        c[i]=0;
    }

    for(int j=0;j<b;j++){
        scanf("%d %d",&e,&f);
        g+=e;
        c[g]=f;
    }
    printf("%d %d %d\n",c[0],c[1],c[2]);
    //printf("%d\n", c[3]);
    for(int k=0;k<b;k++){
        h = h+c[k];
    }

    printf("%d",h);
    return 0;

}
/*
    int a,i,j,k=1,e,f,d;
    int b[100000];
    int c[100000];

    for(i=0;i<100000;i++){
        scanf("%d",&a);
        if(a==0){
            break;
        }else{
            b[i] = a;
        }
    }

    for(j=0;j<100000;j++){

    }

    for(int l=0;l<100000;l++){
        if(b[l]==0){
            break;
        }else{
            printf("%d",b[l]);
        }
    }

*/

/*
        for(k=1;k<100000;k++){
            if(b[j]==k){
                d=b[k-1];
                b[k-1]=b[j];
                b[j]=d;

            }
        }
*/




/*
    for(i=0;i<100000;i++){
        scanf("%d",&a);
        if(a==0){
            break;
        }else{
            b[i] = a;
        }
    }
    for(j=0;j<100000;j++){
        for(k=1;k<100000;k++){
            if(b[j]==k){
                e=b[j]-1;
                c[e]=k;
                break;
            }
        }
    }
    for(f=0;b[f]!=0;f++){
        printf("%d",c[f]);
    }
    return 0;
*/
