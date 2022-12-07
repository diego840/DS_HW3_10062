#include<stdio.h>
int main(){
    int Miles;
    double Kilometer = 1.6;
    while (scanf("%d",&Miles) != EOF){
        printf("%0.1f\n",Kilometer * (double)Miles);
    }
}