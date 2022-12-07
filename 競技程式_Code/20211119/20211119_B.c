#include<stdio.h>
#define name_SIZE 1000
#define student_SIZE 1000
#define number_SIZE 1000
long long int ID;
typedef struct school school;
    
struct school{
    char name[name_SIZE];
    long long int student;
};

char *function_one(long long int ID,int b,school aa[]){
    for ( int i = 0; i < b; i++){
        if (aa[i].student==ID){
            return aa[i].name;
        }
    }
    return 0;
}

int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    school number[number_SIZE];
    for (int i = 0; i < a; i++){
        scanf("%s",number[i].name);
        scanf("%lld",&number[i].student);
    }
    for (int j = 0; j < b; j++){
        scanf("%lld",&ID);
        //printf("%d\n", function_one(ID,a,number));
        printf("%s\n",function_one(ID,a,number));
    }
    return 0;
}
