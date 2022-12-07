#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define max 1500
#define very_max 1000000

int Nodes, B;                       // Nides,B
double infinite = 9999999.999;      // Node 自己到自己的distance
double Node_X_Y_ary[max][4];        // save all Node 的 X and Y
double Node_distance_ary[max][max]; // between each point distance
double Spain_minimum_ary[max][max];
int Node_visited[max];
int DFS_after_ary[max];
int accept_ID[max][max];
int accept_total_ary[max];
int accept_index,accept_total,ans = 0;
int Edge_index, minispain_index = 0;
int belong[max];
int Node_one, Node_two;
int beast_ID,DFS_index = 0;


typedef struct Edge{
    int u;
    int v;
    double w;
} Edge;

Edge *Edge_ary;
Edge *minimum_spain_tree;

void sort(int left, int right){
    Edge temp;
    if (left < right){
        int formula = (left + right) / 2;
        double pivot = Edge_ary[formula].w;
        int i = left - 1;
        int j = right + 1;

        while (1){
            while (Edge_ary[++i].w < pivot);
            while (Edge_ary[--j].w > pivot);
            if (i >= j){
                break;
            }
            temp = Edge_ary[i];
            Edge_ary[i] = Edge_ary[j];
            Edge_ary[j] = temp;
        }
        sort(left, i - 1);
        sort(j + 1, right);
    }
}

void Kruskal_Algorithm(){
    for (int i = 0; i < Nodes; i++){
        for (int j = 0; j < Nodes; j++){
            if (Node_distance_ary[i][j] != 0 && i != j){
                Edge_ary[Edge_index].u = i;
                Edge_ary[Edge_index].v = j;
                Edge_ary[Edge_index].w = Node_distance_ary[i][j];
                Edge_index++;
            }
        }
    }

    sort(0, Edge_index - 1);

    for (int i = 0; i < Nodes; i++){
        belong[i] = i;
    }

    for (int i = 0; i < Edge_index; i++){
        Node_one = belong[Edge_ary[i].u];
        Node_two = belong[Edge_ary[i].v];

        if (Node_one != Node_two){
            minimum_spain_tree[minispain_index++] = Edge_ary[i];
            for (int i = 0; i < Nodes; i++){
                if (belong[i] == Node_two){
                    belong[i] = Node_one;
                }
            }
        }
    }
}

void Transform(){
    memset(Spain_minimum_ary, 0, sizeof(Spain_minimum_ary));
    for (int i = 0; i < minispain_index; i++)
    {
        int X = minimum_spain_tree[i].u;
        int Y = minimum_spain_tree[i].v;
        double content = minimum_spain_tree[i].w;
        Spain_minimum_ary[X][Y] = content;
        Spain_minimum_ary[Y][X] = content;
    }
}

void DFS(int i){
    DFS_after_ary[DFS_index++] = i;
    Node_visited[i] = 1;
    
    for (int j = 0; j < Nodes; j++){
        if (Spain_minimum_ary[i][j] != 0 && Node_visited[j] == 0 && i != j){
            DFS(j);
        }
    }
}

void UAV_tours(){
    double UAV_Distance = 0;
    memset(Node_visited,0,sizeof(Node_visited));
    for (int i = 0; i < DFS_index; i++){
        int x = DFS_after_ary[(i%Nodes)];
        int y = DFS_after_ary[((i+1)%Nodes)];
        accept_ID[accept_index][accept_total++] = x;
        Node_visited[x] = 1;
        if ( (UAV_Distance+Node_distance_ary[x][y]) > (B/2) || Node_visited[y] != 0){
            accept_total_ary[accept_index] = accept_total;
            accept_index++;
            accept_total = 0;
            UAV_Distance = 0;
        }else{
            UAV_Distance += Node_distance_ary[x][y];
        }
    }
}

void INP_operation(){
    memset(Node_X_Y_ary, 0, sizeof(Node_X_Y_ary));
    scanf("%d %d", &Nodes, &B);
    for (int i = 0; i < Nodes; i++){
        int NodeID = 0;
        scanf("%d", &NodeID);
        scanf("%lf %lf", &Node_X_Y_ary[NodeID][0], &Node_X_Y_ary[NodeID][1]);
    }
    minimum_spain_tree = (Edge *)malloc((Nodes + 5) * sizeof(Edge));
    Edge_ary = (Edge *)malloc(((Nodes * Nodes) + 5) * sizeof(Edge));
}

double distance_formula(double x1, double y1, double x2, double y2){
    double n = ((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2));
    double value = sqrt(n);
    return value;
}
void Node_distance(){
    memset(Node_distance_ary, 0, sizeof(Node_distance_ary));
    for (int i = 0; i < Nodes; i++)
    {
        for (int j = 0; j < Nodes; j++)
        {
            if (i == j)
            {
                Node_distance_ary[i][j] = infinite;
            }
            else
            {
                double x1 = Node_X_Y_ary[i][0];
                double y1 = Node_X_Y_ary[i][1];
                double x2 = Node_X_Y_ary[j][0];
                double y2 = Node_X_Y_ary[j][1];
                Node_distance_ary[i][j] = distance_formula(x1, y1, x2, y2);
            }
        }
    }
}

void Print_function(){
    printf("%d\n",accept_index);
    for (int i = 0; i < accept_index; i++){
        printf("%d ",i);
        for (int k = 0; k < accept_total_ary[i]; k++){
            printf("%d ",accept_ID[i][k]);
        }
        printf("\n");
    }
    
}
int main(){
    INP_operation();
    Node_distance();
    Kruskal_Algorithm();
    Transform();
    memset(Node_visited, 0, sizeof(Node_visited));
    DFS(0);
    UAV_tours();
    Print_function();
    return 0;
}