#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 1150
#define Queue_MAX 1000000
#define max 10000
#define limited 99999999
int Nodes,Links,Req;
int NodeID,QM;
int LinkID,LinkEnd1,LinkEnd2,Channels;
int ReqID,ReqSrc,ReqDst;
int Node_list[MAX]; //存
int Link_list[MAX][MAX]; //main()
int Req_list[max][max]; //main()
int visited[MAX]; //BFS()
int first_answer[MAX]; //BFS() 
int test,a;
int answer_counter = 0;
int end_number[MAX];
int sec_end_number[MAX];
int check_line[MAX]; //main()
int print_line[max][MAX];
int shortest_path[max][MAX];
int END_list[max];
int Counter,tmp;
int accept_path[max];

struct QItem{
    int me_value;
    int parent_value;
    int Location;
};
struct Queue{
    struct QItem* array;
    int front;
    int back;
};
int isEmpty(struct Queue* Queue){
    return Queue->front ==  Queue->back;
}
void Queue_initial(struct Queue* Queue){
    Queue->array = (struct QItem*)malloc(Queue_MAX*sizeof(struct QItem));
    memset(Queue->array,0,sizeof(Queue->array));
    Queue->front = 0;
    Queue->back = 0;
}
void Queue_push(struct Queue* Queue,struct QItem newItem){
    Queue->back++;
    Queue->array[Queue->back] = newItem;
    //printf("!Push! Queue.back:%d \n",Queue->back);
}
struct QItem Queue_pop(struct Queue* Queue){
    struct QItem a;
    a.me_value = -1;
    a.parent_value = -1;
    a.Location = -1;
    if (!isEmpty(Queue)){
        Queue->front++;
        a = Queue->array[Queue->front];
        //printf("!PoP! Queue.front:%d \n",Queue->front);

    }
    return a;
}
int BFS(int Node,int ReqSrc,int ReqDst){ // (節點數量,開始的節點,結束的節點)
    //printf("ReqSrc:%d ReqDst:%d\n",ReqSrc,ReqDst);
    struct Queue queue;
    struct QItem queue_pop;
    struct QItem queue_save[1500];

    memset(queue_save,0,sizeof(queue_save));
    memset(visited,0,sizeof(visited)); // 初始化未被拜訪的點
    memset(first_answer,0,sizeof(first_answer));
    
    for (int i = 0; i < 1500; i++){
        queue_save[i].Location = limited;
    }
    
    
    Queue_initial(&queue);
    
    queue_save[ReqSrc].me_value =  ReqSrc;
    queue_save[ReqSrc].parent_value = -1;
    queue_save[ReqSrc].Location = 0;
    visited[ReqSrc] = 1;
    Queue_push(&queue,queue_save[ReqSrc]);

    while (!isEmpty(&queue)){
        queue_pop=Queue_pop(&queue);
        visited[queue_pop.me_value] = 1;
        for (int i = 0; i < Node; i++){
            int X = queue_pop.Location+1;
            if (Link_list[queue_pop.me_value][i] != 0 && visited[i] == 0 && X <= queue_save[i].Location){
                queue_save[i].me_value = i;
                queue_save[i].parent_value = queue_pop.me_value;
                queue_save[i].Location = (queue_pop.Location)+1;
                Queue_push(&queue,queue_save[i]);
            }
        }
    }
    Counter = queue_save[ReqDst].Location;
    if (Counter == limited){
        return 0;
    }
    
    //printf("%d \n",Counter);
    tmp = ReqDst;
    for (int k = 0; k <= Counter; k++){ 
        first_answer[k] = tmp;
        tmp = queue_save[tmp].parent_value;
    }
    return Counter;
}
int Check_EN(int *arr,int End){ //判斷符不符合可以走baseline的函式 可以回傳1 不行回傳0
    if (End == 0){
        return 0;
    }
    
    if (Node_list[arr[0]] < 1){
        return 0;
    }
    if (Node_list[arr[End]] < 1){
        return 0;
    }
    
    
    for (int i = 1; i < End; i++){
        if (Node_list[arr[i]] < 2){
            return 0;
        }
    }
    for (int i = 0; i < End; i++){
        if (Link_list[arr[i]][arr[i+1]] == 0 || Link_list[arr[i+1]][arr[i]] == 0){
            return 0;
        }
    } 
    return 1;
}
void delete_EN(int *arr,int End,int ID){ //等帶判斷函式的回傳值 決定要不要扣Memories 跟 Link
    int result = 0;
    result = Check_EN(arr,End);
    
    if (result == 1){
        for (int i = 0; i <= End; i++){
            if (i == 0 || i == End){ //頭尾扣2的memories 中間扣1的memories
                Node_list[arr[i]]-=1;
            }else{
                Node_list[arr[i]]-=2;
            }
        }
        for (int i = 0; i < End; i++){
            Link_list[arr[i]][arr[i+1]] --;
            Link_list[arr[i+1]][arr[i]] --;
        }

        for (int i = 0; i <= End; i++){
            print_line[answer_counter][i] = arr[i];
        }
        END_list[answer_counter] = End;
        accept_path[answer_counter] = ID;
        answer_counter++;
    }
    
}
void inital_list(){
    memset(Node_list,0,sizeof(Node_list));
    memset(check_line,0,sizeof(check_line));
    memset(Link_list,0,sizeof(Link_list));
    memset(shortest_path,0,sizeof(shortest_path));
    memset(end_number,0,sizeof(end_number));
    memset(Req_list,0,sizeof(Req_list));
    memset(print_line,0,sizeof(print_line));
    memset(end_number,0,sizeof(end_number));
}
int main(){
    inital_list();
    scanf("%d %d %d",&Nodes,&Links,&Req);
    for (int i = 0; i < Nodes; i++){
        scanf("%d %d",&NodeID,&QM);
        Node_list[i]=QM;
    }
    
    for (int i = 0; i < Links; i++){
        scanf("%d %d %d %d",&LinkID,&LinkEnd1,&LinkEnd2,&Channels);
        Link_list[LinkEnd1][LinkEnd2] = Channels;
        Link_list[LinkEnd2][LinkEnd1] = Channels;
    }
    

    for (int i = 0; i < Req; i++){
        scanf("%d %d %d",&ReqID,&ReqSrc,&ReqDst);
        Req_list[i][0] = ReqID;
        Req_list[i][1] = ReqSrc;
        Req_list[i][2] = ReqDst;
    }
    
    for (int i = 0; i < Req; i++){
        test = BFS(Nodes,Req_list[i][1],Req_list[i][2]);
        if (test != 0){
            end_number[i] = test;
            //printf("test:%d \n",test);
            for (int j = 0,k= test; j <= test; k--,j++){
                shortest_path[i][j] =  first_answer[k]; 
            }
        }
        else if (test == 0){
            end_number[i] = test;
            shortest_path[i][0] = 0;
        }
           
    }

    for (int i = 0; i < Req; i++){
        delete_EN(shortest_path[i],end_number[i],Req_list[i][0]);
    }
    
    printf("%d\n",answer_counter);
    for (int i = 0; i < answer_counter; i++){
        printf("%d ",accept_path[i]);
        for (int j = 0; j <= END_list[i]; j++){
            printf("%d ",print_line[i][j]);

        }
        printf("\n");
    }
    /*
    printf("\n");
    for (int i = 0; i < Req; i++){
        for (int j = 0; j <= end_number[i]; j++){
            printf("%d ",shortest_path[i][j]);
        }
        printf("\n");    
    }*/
    return 0;
}