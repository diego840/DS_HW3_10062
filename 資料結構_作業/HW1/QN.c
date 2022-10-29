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
int Node_list[MAX]; //main()
int Link_list[MAX][MAX]; //main()
int Req_list[max][max]; //main()
int visited[MAX]; //BFS()
int first_answer[MAX]; //BFS() 
int test,a;
int answer_counter = 0;
int end_number[MAX];
int check_line[MAX]; //main()
int print_line[max][MAX];
int shortest_path[max][MAX];
int END_list[max];
int hhhh = 0;

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
void Queue_initial(struct Queue* Queue){
    Queue->array = (struct QItem*)malloc(Queue_MAX*sizeof(struct QItem));
    memset(Queue->array,0,sizeof(Queue->array));
    Queue->front = -1;
    Queue->back = 0;
}
void Queue_push(struct Queue* Queue,struct QItem newItem){
    Queue->array[Queue->back] = newItem;
    visited[newItem.me_value] = 1;
    Queue->back += 1;
}
void Queue_pop(struct Queue* Queue){
    Queue->front += 1;
}

int BFS(int Node,int ReqSrc,int ReqDst){ // (節點數量,開始的節點,結束的節點)
    //printf("ReqSrc:%d ReqDst:%d\n",ReqSrc,ReqDst);
    struct Queue queue;
    struct QItem headnode;
    
    int Counter = 0;
    memset(visited,0,sizeof(visited)); // 初始化未被拜訪的點
    memset(first_answer,0,sizeof(first_answer));
    Queue_initial(&queue);
    
    headnode.me_value = ReqSrc;
    headnode.parent_value = -1;
    headnode.Location = 0;

    Queue_push(&queue,headnode);
    while (queue.front < queue.back){
        // printf("%d : 11\n",hhhh);
        // hhhh++;
        Queue_pop(&queue);
        if (queue.front >= queue.back){
            break;
        }
        
        for (int i = 0; i < Node; i++){
            int now_value = queue.array[queue.front].me_value ;
            struct QItem nownode;
            if (Link_list[now_value][i] != 0 && visited[i] != 1){
                nownode.me_value = i;
                nownode.parent_value = queue.front;
                nownode.Location = (queue.array[queue.front].Location)+1;
                Queue_push(&queue,nownode);

                if (i == ReqDst){
                    Counter = queue.array[queue.back-1].Location;
                    //printf("Counter:%d\n",Counter);
                    int tmp;
                    for (int j = 0; j <= Counter; j++){
                        if (j == 0){
                            tmp = queue.array[queue.back-1].parent_value;
                            first_answer[j] = queue.array[queue.back-1].me_value;
                            //printf("first_answer:%d\n",first_answer[j]);
                        }else{
                            first_answer[j] = queue.array[tmp].me_value;
                            tmp = queue.array[tmp].parent_value;
                            //printf("First_answer:%d\n",first_answer[j]);
                        }
                    }
                    return Counter;
                }
            }   
        }
    }
    return 0;
    
}
int Check_EN(int *arr,int End){
    for (int i = 0; i <= End; i++){
        if (i == 0 || i == End){
            if (Node_list[arr[i]] < 1){
                return 0;
            }    
        }else{
            if (Node_list[arr[i]] < 2){
                return 0;
            }
        }
    }
    for (int i = 0; i < End; i++){
        if (Link_list[arr[i]][arr[i+1]] < 1){
            return 0;
        }
    }
    return 1;
}
void delete_EN(int *arr,int End){
    int result;
    result = Check_EN(arr,End);
    if (result == 1 && End != 0){
        for (int i = 0; i <= End; i++){
            if (i == 0 || i == End){
                Node_list[arr[i]]-=1;
            }else{
                Node_list[arr[i]]-=2;
            }
        }
        for (int i = 0; i < End; i++){
            Link_list[arr[i]][arr[i+1]] -= 1;
            Link_list[arr[i+1]][arr[i]] -= 1;
        }

        for (int i = 0; i <= End; i++){
            print_line[answer_counter][i] = arr[i];
        }
        END_list[answer_counter] = End;

        answer_counter++;
        
    }
}
int main(){
    scanf("%d %d %d",&Nodes,&Links,&Req);
    memset(Node_list,0,sizeof(Node_list));
    memset(check_line,0,sizeof(check_line));
    memset(Link_list,0,sizeof(Link_list));
    for (int i = 0; i < Nodes; i++){
        scanf("%d %d",&NodeID,&QM);
        Node_list[NodeID]=QM;
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
        for (int j = 0,k= test; j <= test; k--,j++){
            shortest_path[i][j] =  first_answer[k]; 
        }    
    }

    for (int i = 0; i < Req; i++){
        delete_EN(shortest_path[i],end_number[i]);
    }
    
    printf("%d\n",answer_counter);
    for (int i = 0; i < answer_counter; i++){
        printf("%d ",i);
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