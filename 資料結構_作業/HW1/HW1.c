#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 1150
#define Queue_MAX 1000000
#define max 10000
int Nodes,Links,Req;
int NodeID,QM;
int LinkID,LinkEnd1,LinkEnd2,Channels;
int ReqID,ReqSrc,ReqDst;
int Node_list[MAX]; //存node
int Link_list[MAX][MAX]; //存chanel
int Req_list[max][max]; //存Req
int visited[MAX]; //在queue裡面存拜訪的點
int first_answer[MAX]; //暫存bfs找到的路徑
int test,a; // bfs回傳的值
int answer_counter = 0;
int end_number[MAX]; //存這條shortest path的經過的數量 
int print_line[max][MAX]; //存最後輸出的路徑
int shortest_path[max][MAX]; //存所有req的路徑(還未檢查) 
int END_list[max]; //存通過檢查路徑所經過的數量
int Counter,tmp; 
int accept_path[max]; //存通過的路徑的req ID

struct QItem{ 
    int me_value; //自己的ID
    int parent_value; //上個節點的ID (父結點)
    int Location; // 當前的位置
};
struct Queue{ //queue
    struct QItem* array;
    int front;
    int back;
};
int isEmpty(struct Queue* Queue){ //判斷queue裡面有沒有東西
    return Queue->front ==  Queue->back;
}
void Queue_initial(struct Queue* Queue){ //初始化queue
    Queue->array = (struct QItem*)malloc(Queue_MAX*sizeof(struct QItem));
    memset(Queue->array,0,sizeof(Queue->array));
    Queue->front = 0;
    Queue->back = 0;
}
void Queue_push(struct Queue* Queue,struct QItem newItem){ //queue 的 push
    Queue->back++;
    Queue->array[Queue->back] = newItem;
    //printf("!Push! Queue.back:%d \n",Queue->back);
}
struct QItem Queue_pop(struct Queue* Queue){ //queue 的 pop
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
//BFS 搜尋最短路徑並且每次都會從ID小開始找確保baseline
int BFS(int Node,int ReqSrc,int ReqDst){ // (節點數量,開始的節點,結束的節點)
    //printf("ReqSrc:%d ReqDst:%d\n",ReqSrc,ReqDst);
    struct Queue queue;
    struct QItem queue_pop; //接queue pop出來的值
    struct QItem* queue_save = (struct QItem*)malloc(MAX*sizeof(struct QItem)); //開QItem型態的陣列存放拜訪過的節點的相關資料

    memset(queue_save,0,sizeof(queue_save)); 
    memset(visited,0,sizeof(visited)); // 初始化未被拜訪的點
    memset(first_answer,0,sizeof(first_answer));
    

    Queue_initial(&queue); // 初始化queue
    
    queue_save[ReqSrc].me_value =  ReqSrc;
    queue_save[ReqSrc].parent_value = -1;
    queue_save[ReqSrc].Location = 0;
    visited[ReqSrc] = 1;
    Queue_push(&queue,queue_save[ReqSrc]); //將開始的節點放入queue

    while (!isEmpty(&queue)){ //判斷queue裡是否還有東西
        queue_pop=Queue_pop(&queue); //將queue的值pop出來
        for (int i = 0; i < Node; i++){
            if (Link_list[queue_pop.me_value][i] != 0 && visited[i] == 0){ //判斷是否有連結
                queue_save[i].me_value = i;
                queue_save[i].parent_value = queue_pop.me_value;
                queue_save[i].Location = (queue_pop.Location)+1;
                visited[i] = 1;
                Queue_push(&queue,queue_save[i]); //將找的的節點放入queue
            }
        }
    }
    Counter = queue_save[ReqDst].Location; //存走到reqDst所需要的經過的最少數量
    //printf("%d \n",Counter);
    tmp = ReqDst; 
    for (int k = 0; k <= Counter; k++){ //從reqDst一路找回去經過的節點
        first_answer[k] = tmp; //路徑暫時存放的list
        tmp = queue_save[tmp].parent_value;
    }
    return Counter; //回傳這條路徑經過的所有節點數量
}
int Check_EN(int *arr,int End){ //判斷符不符合可以走的函式 可以回傳1 不行回傳0
    if (End == 0){ //找不到的路徑
        return 0;
    }
    
    if (Node_list[arr[0]] < 1){ //開始的nodes數量要大於等於一
        return 0;
    }
    if (Node_list[arr[End]] < 1){ //結束的nodes數量要大於等於一
        return 0;
    }
    
    
    for (int i = 1; i < End; i++){ //中間經過的nodes數量要大於等於2
        if (Node_list[arr[i]] < 2){
            return 0;
        }
    }
    for (int i = 0; i < End; i++){ //判斷是否chanel可以走
        if (Link_list[arr[i]][arr[i+1]] == 0 || Link_list[arr[i+1]][arr[i]] == 0){
            return 0;
        }
    } 
    return 1;
}
void delete_EN(int *arr,int End,int ID){ //等帶判斷函式的回傳值 決定要不要扣Memories 跟 Link
    int result = 0;
    result = Check_EN(arr,End);
    
    if (result == 1){ //可以扣的才要扣，並且存入最後要輸出的list
        for (int i = 0; i <= End; i++){
            if (i == 0 || i == End){ 
                Node_list[arr[i]]-=1;
            }else{
                Node_list[arr[i]]-=2;
            }
        }
        for (int i = 0; i < End; i++){
            Link_list[arr[i]][arr[i+1]] --;
            Link_list[arr[i+1]][arr[i]] --;
        }

        for (int i = 0; i <= End; i++){ //將路徑存入最後輸出的list
            print_line[answer_counter][i] = arr[i];
        }
        END_list[answer_counter] = End; //存檢查通過後路徑後所經過的節點數量
        accept_path[answer_counter] = ID; //存檢查通過後路徑的ID
        answer_counter++;
    }
    
}
void inital_list(){ //初始化所有list
    memset(Node_list,0,sizeof(Node_list));
    memset(Link_list,0,sizeof(Link_list));
    memset(shortest_path,0,sizeof(shortest_path));
    memset(end_number,0,sizeof(end_number));
    memset(Req_list,0,sizeof(Req_list));
    memset(print_line,0,sizeof(print_line));
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
        end_number[i] = test;
        //printf("test:%d \n",test);
        for (int j = 0,k= test; j <= test; k--,j++){
            shortest_path[i][j] =  first_answer[k]; 
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
    
}