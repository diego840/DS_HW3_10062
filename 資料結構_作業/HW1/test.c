#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 2050
#define Queue_MAX 10000000
int Nodes,Links,Req;
int NodeID,QM;
int LinkID,LinkEnd1,LinkEnd2,Channels;
int ReqID,ReqSrc,ReqDst;
int Node_list[MAX];
int Link_list[MAX][MAX];
int Req_list[MAX][3];
int visited[MAX];
int first_answer[MAX];
int test,a;
int answer_counter = 0;
int end_number[MAX];
int check_line[MAX];
int print_line[MAX][MAX];

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
    struct Queue queue;
    struct QItem headnode;
    
    int counter = 0;
    memset(visited,0,sizeof(visited)); // 初始化未被拜訪的點
    memset(first_answer,0,sizeof(first_answer));
    Queue_initial(&queue);
    
    headnode.me_value = ReqSrc;
    headnode.parent_value = -1;
    headnode.Location = counter;

    Queue_push(&queue,headnode);
    while (queue.front < queue.back){
        struct QItem nownode;
        Queue_pop(&queue);
        if (queue.front >= queue.back){
            break;
        }
        for (int i = 0; i < Node; i++){
            int now_value = queue.array[queue.front].me_value ;
            if (Link_list[now_value][i] != 0 && i == ReqDst && visited[i] == 0){
                //printf("1:%d\n",i);
                nownode.me_value = i;
                nownode.parent_value = now_value;
                nownode.Location = queue.array[queue.front].Location+1;
                Queue_push(&queue,nownode);
                //printf("queue.front: %d \n",queue.front);
                //printf("queue.back: %d \n",queue.back);
                counter = queue.array[queue.back-1].Location;

                for (int j = 0; j < queue.back; j++){
                    //printf("%d\n",counter);
                    int tmp;    
                    if (j>0){
                        for (int k = 0; k < queue.back; k++){
                            if (tmp == -1){
                                break;
                            }else if (queue.array[k].me_value == tmp){
                                first_answer[j] = queue.array[k].me_value;
                                tmp = queue.array[k].parent_value;
                            }
                        }
                        
                    }else{
                        tmp = queue.array[queue.back-1].parent_value;
                        first_answer[j] = queue.array[queue.back-1].me_value;
                    }
                }
                /*
                for ( int i = 0; i < queue.back; i++){
                    printf("me_value: %d ",queue.array[i].me_value);
                    printf("Location: %d ",queue.array[i].Location);
                    printf("\n");
                }
                */
                return counter;
                
            }else if (Link_list[now_value][i] != 0 && i != ReqDst && visited[i] == 0){
                if (Node_list[i] > 1){
                    nownode.me_value = i;
                    nownode.parent_value = now_value;
                    nownode.Location = queue.array[queue.front].Location+1;
                    Queue_push(&queue,nownode);
                }
            }else{
                //printf("3\n");
            }
            
        }
    }
    /*
    printf("front: %d ",queue.front);
    printf("back: %d\n",queue.back);
    for ( int i = 0; i < queue.back; i++){
        printf("me_value: %d ",queue.array[i].me_value);
        printf("Location: %d ",queue.array[i].Location);
        printf("\n");
    }
    */
    return 0;
    
}

int delete_edge_node(int *arr,int End,int node){
    int x = 1;
    for (int i = 0; i <= End; i++){
        if (Node_list[arr[i]] < 1){
            x = -1;
            return x;
        }
    }
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
        if (Node_list[arr[i]] == 0){
            for (int j = 0; j < node; j++){ 
                Link_list[arr[i]][j] = 0;
                Link_list[j][arr[i]] = 0;
            }
        }
    }
    /*
    for (int i = 0; i <= End; i++){
        printf("\n123:%d ",arr[i]);
    }*/
    
    return x;
}
/*
int Print_link_list(int Nodes){
    printf("\n");
    for (int i = 0; i < Nodes; i++){
        printf("%d: %d\n",i,Node_list[i]);
    }
    
    for (int i = 0; i < Nodes; i++){
        for (int j = 0; j < Nodes; j++){
            printf("%d ",Link_list[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
*/
int main(){
    scanf("%d %d %d",&Nodes,&Links,&Req);
    memset(Node_list,0,sizeof(Node_list));
    memset(check_line,0,sizeof(check_line));
    for (int i = 0; i < Nodes; i++){
        scanf("%d %d",&NodeID,&QM);
        Node_list[NodeID]=QM;
    }
    /*
    for (int i = 0; i < Nodes; i++){
        printf("%d\n",Node_list[i]);
    }
    */
    
    memset(Link_list,0,sizeof(Link_list));
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
    /*
    for (int i = Req-1; i >= 0; i--){
        scanf("%d %d %d",&ReqID,&ReqSrc,&ReqDst);
        Req_list[i][0] = ReqID;
        Req_list[i][1] = ReqSrc;
        Req_list[i][2] = ReqDst;
    }*/
    
    for (int i = 0; i < Req; i++){
        test  = BFS(Nodes,Req_list[i][1],Req_list[i][2]);
        if (test > 0){
            
            for (int j = test,k = 0; j >= 0; j--,k++){
                check_line[k] = first_answer[j];
                //printf("123:%d ",first_answer[j]);
            }
            //printf("%d",delete_edge_node(check_line,test,Nodes));
            if (delete_edge_node(check_line,test,Nodes) == 1){
                //printf("\n123:%d ",test);
                for (int z = 0; z <= test; z++){
                    print_line[answer_counter][z] = check_line[z];
                    //printf("\ni:%d z:%d answer_counter:%d 123456789:%d ",i,z,answer_counter,print_line[i][z]);
                }
                end_number[answer_counter] = test;
                answer_counter++;
                //Print_link_list(Nodes);
            }
        }
    }
    /*
    printf("%d\n",answer_counter);
    for (int i = 0,x = answer_counter-1; x >= 0;x--,i++){
        printf("%d ",i);
        for (int j = 0; j < end_number[i]; j++){
            printf("%d ",print_line[x][j]);
        }
        printf("\n");
    }*/
    
    printf("%d\n",answer_counter);
    for (int i = 0; i < answer_counter; i++){
        printf("%d ",i);
        for (int j = 0; j <= end_number[i]; j++){
            printf("%d ",print_line[i][j]);
        }
        printf("\n");
    }
    return 0;
}

/*
    test = BFS(9,0,8);
    printf("test:%d",test);
    printf("\nAnswer: ");
    if (test>0){
        for (int i = test; i >= 0 ; i--){
            printf("%d ",first_answer[i]);
        }
        printf("\n");
    }else{
        printf("loser\n");
    }
*/