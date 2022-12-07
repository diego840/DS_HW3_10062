#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{ 
    int number;
    struct node *next;
}Node;

Node* head = NULL; //宣告一個開頭，並且指向NULL再輸入ADD之前都指向NULL

Node* NewNode(int num){  //將addNewNode中要配置的數字傳進來配置新的節點
    Node* temp = (Node*) malloc(sizeof(Node)); //使用malloc 配置節點
    temp->number = num; //將數字放進去
    temp->next = NULL; //先指向NULL後面有新配置節點在指向新節點
    return temp; //回傳新配置的節點記憶體位置
}

void AddNewNode(int num){  //add的function
    Node* temp = head;
    if(head==NULL){ //先處裡開頭的head
        head = NewNode(num);
    }else{
        while (temp->next!=NULL){ //這邊的will用來處理找到最後一個指向NULL的節點
            temp = temp->next;
        }
        temp->next=NewNode(num); //將上面wille找到的節點的NEXT指向新配置的節點位置並且配置新節點
    }
    printf("ADD_SUCC\n"); //配置成功後輸出
}

void Insert_Node(int original_value,int insert_number_value){  //insert的function
    Node* find = head; //要找的記憶體位置
    Node* remember = head; //前一個節點記憶體位置
    if(head!=NULL){  //這邊的if是特別處理insert在開頭位置而改變的是head要指向新增的節點位置
        if(original_value==find->number){
            Node* New_Node = (Node*) malloc(sizeof(Node)); 
            New_Node->next=find; //新增的節點裡面的next指向的是原本要插入的記憶體位置
            head=New_Node; //head 的地方指向新增的節點
            New_Node->number=insert_number_value; 
            printf("INSERT_SUCC\n");
            return;
        }
        find = find->next; //往下找下一個節點位置
    }else{
        printf("INSERT_FAIL\n"); 
        return;
    }
    while (find!=NULL){  //如果不是要insert在開頭就執行這裡
        if(original_value==find->number){
            Node* New_Node = (Node*) malloc(sizeof(Node)); 
            New_Node->next=find;    //新增的next指向insert的記憶體位置
            remember->next=New_Node; //前一個節點位置指向新配置的記憶體位置
            New_Node->number=insert_number_value;
            printf("INSERT_SUCC\n");
            return;
        }
        remember = find; //記住find的記憶體位置(記住要找的前一個記憶體位置)
        find = find->next; //往下找下個節點
    }
    printf("INSERT_FAIL\n");
}

void Search_Node(int Search_value){  //search的function
    Node* search = head; 
    if(search==NULL){ //如果沒有add就search就 not found
        printf("NOT FOUND\n");
        return;
    }
    while (search!=NULL){ //開始有找到就found
        if(search->number==Search_value){
            printf("FOUND\n");
            return;
        }
        search = search->next;
    }
    printf("NOT FOUND\n"); //沒找到就 not found
}

void Update_Node(int original_value,int change_value){ //update的function
    Node* update = head;
    if(update==NULL){ //如果沒有add就update就 update_fail
        printf("UPDATE_FAIL\n");
        return;
    }
    while (update!=NULL){ //有找到就更新數字並且輸出update_succ
        if(update->number==original_value){
            update->number=change_value;
            printf("UPDATE_SUCC\n");
            return;
        }
        update = update->next;
    }
    printf("UPDATE_FAIL\n"); //沒找就輸出update_fail
}

void Delete_Node(int delete_value){ //delete的function 
    Node* delete = head;
    Node* delete_before = head;
    if(delete!=NULL){
        if(delete->number==delete_value){
            head=delete->next;
            delete_before=delete->next;
            free(delete);
            printf("DELETE_SUCC\n");
            return;
        }
        delete = delete->next;
    }else{
        printf("DELETE_FAIL\n");
        return;
    }
    while (delete!=NULL){
        if(delete!=NULL){
            if(delete->number==delete_value){
                delete_before->next=delete->next;

                free(delete);
                printf("DELETE_SUCC\n");
                return;
            }
            delete_before = delete;
            delete = delete->next;
        }
    }
    printf("DELETE_FAIL\n");
}

void print(){ //print的function
    Node* printAll=head;
    if(printAll == NULL) printf("\n"); //如果沒add就換行輸出
    else{
        while (printAll!= NULL){ 
            printf("%d ",printAll->number); //把節點printf出來
            printAll = printAll->next;
        }
        printf("\n");
    }
}

void Clear_Node(){ //清除節點的function
    Node* Clear = (Node*)malloc(sizeof(Node)); //配置新的節點
    Clear = head; //新的節點存head
    while (Clear!=NULL){
        Clear = Clear->next; 
        free(head); //清除節點
        head = Clear; //將下一個要清除的節點存起來
    }
    free(head); //清除head
    free(Clear); //清除新配置的節點
}

int main(){
    int value_one,value_two; //宣告兩個變數當作(參數:target 參數:data)
    char* input_name=malloc(sizeof(char)*200); //用malloc配置一段記憶體空間存放Input的字串
    while (scanf("%s",input_name)!=EOF){    //用來判斷是不是EOF
        if(strcmp(input_name,"add")==0){  //add
            scanf("%d",&value_one);
            AddNewNode(value_one);
        }else if(strcmp(input_name,"insert")==0){ //insert
            scanf("%d %d",&value_one,&value_two);
            Insert_Node(value_one,value_two);
        }else if(strcmp(input_name,"search")==0){ //search
            scanf("%d",&value_one);
            Search_Node(value_one);
        }else if(strcmp(input_name,"update")==0){ //update
            scanf("%d %d",&value_one,&value_two);
            Update_Node(value_one,value_two);
        }else if(strcmp(input_name,"delete")==0){ //delete
            scanf("%d",&value_one);
            Delete_Node(value_one);
        }else if(strcmp(input_name,"print")==0){ //print
            print();
        }
    }
    Clear_Node(); //清除所有節點釋放記憶體
    return 0;   
}