#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

struct node{
    int num;
    struct node *next;
};

void add(struct node *ptr,int data){
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    struct node *tmp=(struct node*)malloc(sizeof(struct node));
    ptr->next=tmp;
    tmp->next=NULL;
    tmp->num=data;
    printf("ADD_SUCC\n");
}

void insert(struct node *ptr,int target,int data){
    bool success=false;
    struct node *check=ptr->next;
    while(check!=NULL){
        if(check->num==target){
            struct node *tmp=(struct node*)malloc(sizeof(struct node));
            ptr->next=tmp;
            tmp->next=check;
            tmp->num=data;
            success=true;
            break;
        }
        ptr=ptr->next;
        check=ptr->next;
    }
    if(success){
        printf("INSERT_SUCC\n");
    }
    else{
        printf("INSERT_FAIL\n");
    }

}

void deletes(struct node *ptr,int target){
    bool success=false;
    struct node *check=ptr->next;
    while(check!=NULL){
        if(check->num==target){
            success=true;
            struct node *tmp=(struct node*)malloc(sizeof(struct node));
            tmp=check->next;
            ptr->next=tmp;
            free(check);
            break;
        }
        ptr=ptr->next;
        check=ptr->next;
    }
    if(success){
        printf("DELETE_SUCC\n");
    }
    else{
        printf("DELETE_FAIL\n");
    }
}

void search(struct node *ptr,int target){
    bool success=false;
    ptr=ptr->next;
    while(ptr!=NULL){
        if(ptr->num==target){
            success=true;
            break;
        }
        ptr=ptr->next;
    }
    if(success){
        printf("FOUND\n");
    }
    else{
        printf("NOT FOUND\n");
    }
}

void update(struct node *ptr,int target,int data){
    bool success=false;
    ptr=ptr->next;
    while(ptr!=NULL){
        if(ptr->num==target){
            success=true;
            ptr->num=data;
            break;
        }
        ptr=ptr->next;
    }
    if(success){
        printf("UPDATE_SUCC\n");
    }
    else{
        printf("UPDATE_FAIL\n");
    }
}



void print(struct node *ptr){
    ptr=ptr->next;
    while(ptr!=NULL){
        printf("%d ",ptr->num);
        ptr=ptr->next;
    }
    printf("\n");
}

int main(){
    struct node *head=(struct node*)malloc(sizeof(struct node));
    head->next=NULL;
    char *str=malloc(sizeof(char)*100);
    int target,data;
    while(scanf("%s",str)!=EOF){
        if(strcmp(str,"add")==0){
            scanf("%d",&data);
            add(head,data);
        }
        else if(strcmp(str,"insert")==0){
            scanf("%d%d",&target,&data);
            insert(head,target,data);
        }
        else if(strcmp(str,"delete")==0){
            scanf("%d",&target);
            deletes(head,target);
        }
        else if(strcmp(str,"search")==0){
            scanf("%d",&target);
            search(head,target);
        }
        else if(strcmp(str,"update")==0){
            scanf("%d%d",&target,&data);
            update(head,target,data);
        }
        else if(strcmp(str,"print")==0){
            print(head);
        }

    }
    struct node *tmp=(struct node*)malloc(sizeof(struct node));
    tmp=head->next;
    while(tmp!=NULL){
        free(head);
        head=tmp;
        tmp=head->next;
    }
    free(head);
    free(tmp);
}
