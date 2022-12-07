#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 1000

int Input_number,a,b;
char input_name[10];
char* function_Name[6]={"add","insert","delete","search","update","print"};

int compare(){
    for (int i = 0; i <= 5; i++){
        if(strncmp(input_name,function_Name[i],3)==0){
            return i;
        }
    }
    return -1;
}

typedef struct node{
    int number;
    struct node *next;
}Node;

Node* head = NULL;

Node* NewNode(int num){
    Node* temp = (Node*) malloc(sizeof(Node));
    temp->number = num;
    temp->next = NULL;
    return temp;
}

void AddNewNode(int num){
    Node* temp = head;
    if(head==NULL){
        head = NewNode(num);
    }else{
        while (temp->next!=NULL){
            temp = temp->next;
        }
        temp->next=NewNode(num);
    }
}

void Insert_Node(int original_value,int insert_number_value){
    Node* find = head;
    Node* remember=find;
    while (find->next!=NULL){
        if(original_value==find->number){
            Node* New_Node = (Node*) malloc(sizeof(Node)); 
            New_Node->next=find;
            remember->next=New_Node;
            New_Node->number=insert_number_value;
            // New_Node->next=find->next;  
            // find->next=New_Node;
            // New_Node->number=original_value;
            // find->number=insert_number_value;
            printf("INSERT_SUCC\n");
            return;
        }
        remember = find;
        find = find->next;
    }
    if(find->number==original_value){
        Node* New_Node = (Node*) malloc(sizeof(Node)); 
        New_Node->next=NULL;
        find->next=New_Node;
        find->number=insert_number_value;
        New_Node->number=original_value;
        printf("INSERT_SUCC\n");
        return;
    }else{
        printf("INSERT_FAIL\n"); 
    }
}

void Search_Node(int Search_value){
    Node* search = head;
    if(search==NULL){
        printf("NOT FOUND\n");
        return;
    }
    while (search->next!=NULL){
        if(search->number==Search_value){
            printf("FOUND\n");
            return;
        }
        search = search->next;
    }
    if(search->number==Search_value){
        printf("FOUND\n");
        return;
    }
    printf("NOT FOUND\n");
}
void print(){
    Node* printAll=head;
    if(printAll == NULL) printf("\n");
    else{
        while (printAll->next != NULL){
            printf("%d ",printAll->number);
            printAll = printAll->next;
        }
        printf("%d\n",printAll->number);
    }
}

int main(){
    int v,c,b;
    while (scanf("%s %d",input_name,&v)!=EOF){
        if(strcmp(input_name,"add")==0){  //add
            // scanf("%d",&Input_number);
            AddNewNode(v);
            printf("ADD_SUCC\n");
        }else if(strcmp(input_name,"insert")==0){ //insert
            scanf("%d",&b);
            Insert_Node(v,b);
        }else if(strcmp(input_name,"search")==0){ //search
            Search_Node(v);
        }else if(strcmp(input_name,"print")==0){ //print
            print();
        }
    }
    return 0;   
}

/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 1000

int Input_number,a,b;
char input_name[10];
char* function_Name[6]={"add","insert","delete","search","update","print"};

int compare(){
    for (int i = 0; i <= 5; i++){
        if(strncmp(input_name,function_Name[i],3)==0){
            return i;
        }
    }
    return -1;
}

typedef struct node{
    int number;
    struct node *next;
}Node;

Node* head = NULL;

Node* NewNode(int num){
    Node* temp = (Node*) malloc(sizeof(Node));
    temp->number = num;
    temp->next = NULL;
    return temp;
}

void AddNewNode(int num){
    Node* temp = head;
    if(head==NULL){
        head = NewNode(num);
    }else{
        while (temp->next!=NULL){
            temp = temp->next;
        }
        temp->next=NewNode(num);
    }
}

void Insert_Node(int original_value,int insert_number_value){
    Node* find = head;
    Node* remember = head;
    while (find->next!=NULL){
        if(original_value==find->number){
            Node* New_Node = (Node*) malloc(sizeof(Node)); 
            New_Node->next=find;
            remember->next=New_Node;
            New_Node->number=insert_number_value;
            printf("INSERT_SUCC\n");
            return;
        }
        remember = find;
        find = find->next;
    }
    if(find->number==original_value){
        Node* New_Node = (Node*) malloc(sizeof(Node)); 
        New_Node->next=NULL;
        find->next=New_Node;
        find->number=insert_number_value;
        New_Node->number=original_value;
        printf("INSERT_SUCC\n");
        return;
    }else{
        printf("INSERT_FAIL\n"); 
    }
}

void Search_Node(int Search_value){
    Node* search = head;
    if(search==NULL){
        printf("NOT FOUND\n");
        return;
    }
    while (search->next!=NULL){
        if(search->number==Search_value){
            printf("FOUND\n");
            return;
        }
        search = search->next;
    }
    if(search->number==Search_value){
        printf("FOUND\n");
        return;
    }
    printf("NOT FOUND\n");
}
void print(){
    Node* printAll=head;
    if(printAll == NULL) printf("\n");
    else{
        while (printAll->next != NULL){
            printf("%d ",printAll->number);
            printAll = printAll->next;
        }
        printf("%d\n",printAll->number);
    }
}

int main(){
    int v,c,b;
    while (scanf("%s %d",input_name,&v)!=EOF){
        if(strcmp(input_name,"add")==0){  //add
            // scanf("%d",&Input_number);
            AddNewNode(v);
            printf("ADD_SUCC\n");
        }else if(strcmp(input_name,"insert")==0){ //insert
            scanf("%d",&b);
            Insert_Node(v,b);
        }else if(strcmp(input_name,"search")==0){ //search
            Search_Node(v);
        }else if(strcmp(input_name,"print")==0){ //print
            print();
        }
    }
    return 0;   
}
*/