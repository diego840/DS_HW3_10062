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
int *dis_ary;
int Edge_index, minispain_index = 0;
int belong[max];
int Node_one, Node_two;
int beast_ID,DFS_index = 0;
int DFS_after_ary[max];

typedef struct Edge
{
    int u;
    int v;
    double w;
} Edge;

Edge *Edge_ary;
Edge *minimum_spain_tree;

void sort(int left, int right)
{
    Edge temp;
    if (left < right)
    {
        int formula = (left + right) / 2;
        double pivot = Edge_ary[formula].w;
        int i = left - 1;
        int j = right + 1;

        while (1)
        {
            while (Edge_ary[++i].w < pivot)
                ;
            while (Edge_ary[--j].w > pivot)
                ;
            if (i >= j)
            {
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
    for (int i = 0; i < Nodes; i++)
    {
        for (int j = 0; j < Nodes; j++)
        {
            if (Node_distance_ary[i][j] != 0 && i != j)
            {
                Edge_ary[Edge_index].u = i;
                Edge_ary[Edge_index].v = j;
                Edge_ary[Edge_index].w = Node_distance_ary[i][j];
                Edge_index++;
            }
        }
    }

    sort(0, Edge_index - 1);

    for (int i = 0; i < Nodes; i++)
    {
        belong[i] = i;
    }

    for (int i = 0; i < Edge_index; i++)
    {
        Node_one = belong[Edge_ary[i].u];
        Node_two = belong[Edge_ary[i].v];

        if (Node_one != Node_two)
        {
            minimum_spain_tree[minispain_index++] = Edge_ary[i];
            for (int i = 0; i < Nodes; i++)
            {
                if (belong[i] == Node_two)
                {
                    // printf("\n%d %d %d\n",belong[i],i,Node_two);
                    belong[i] = Node_one;
                }
            }
        }
    }
    // for (int i = 0; i < Nodes; i++)
    // {
    //     printf("%d: %d ", i, belong[i]);
    // }
    // printf("\n");
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

int min(int ID[], double distance[], int total)
{
    double min_num = 0;
    int final_ID = 0;
    for (int i = 0; i < total; i++)
    {
        if (distance[i] > min_num)
        {
            min_num = distance[i];
            final_ID = ID[i];
        }
    }
    return final_ID;
}

void DFS(int i){
    int ID_ary[max];
    int tmp_index = 0;
    printf("i: %d\n",i);
    DFS_after_ary[DFS_index++] = i;
    Node_visited[i] = 1;
    
    for (int j = 0; j < Nodes; j++){
        if (Spain_minimum_ary[i][j] != 0 && Node_visited[j] == 0 && i != j){
            ID_ary[tmp_index++] = j;
        }
    }

    // for (int i = 0; i < tmp_index; i++){
    //     printf("%d ",ID_ary[i]);
    // }
    // printf("\n");
    

    for (int j = 0; j < tmp_index-1; j++){
        for (int k = 0; k < tmp_index-j-1; k++){
            int x = ID_ary[k]; 
            int y = ID_ary[k+1];
            if (Spain_minimum_ary[i][x] > Spain_minimum_ary[i][y]){
                int temp = ID_ary[k+1];
                ID_ary[k+1] = ID_ary[k];
                ID_ary[k] = temp;
            }   
        }    
    }

    // for (int i = 0; i < tmp_index; i++){
    //     printf("%d ",ID_ary[i]);
    // }
    // printf("\n");

    for (int i = 0; i < tmp_index; i++){
        DFS(ID_ary[i]);
    }
    
}

void INP_operation()
{
    memset(Node_X_Y_ary, 0, sizeof(Node_X_Y_ary));
    scanf("%d %d", &Nodes, &B);
    for (int i = 0; i < Nodes; i++)
    {
        int NodeID = 0;
        scanf("%d", &NodeID);
        scanf("%lf %lf", &Node_X_Y_ary[NodeID][0], &Node_X_Y_ary[NodeID][1]);
    }
    minimum_spain_tree = (Edge *)malloc((Nodes + 5) * sizeof(Edge));
    Edge_ary = (Edge *)malloc(((Nodes * Nodes) + 5) * sizeof(Edge));
}

double distance_formula(double x1, double y1, double x2, double y2)
{
    double n = ((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2));
    double value = sqrt(n);
    return value;
}
void Node_distance()
{
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

void Print_function()
{
    for (int i = 0; i < Nodes; i++)
    {
        printf("NodeID:%d CoordinateX:%lf CoordinateY:%lf\n", i, Node_X_Y_ary[i][0], Node_X_Y_ary[i][1]);
    }
    printf("\n");
    for (int i = 0; i < Nodes; i++)
    {
        for (int j = 0; j < Nodes; j++)
        {
            printf("%lf  ", Node_distance_ary[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for (int i = 0; i < Edge_index; i++)
    {
        printf("Node_1:%d Node_2:%d distance:%lf\n", Edge_ary[i].u, Edge_ary[i].v, Edge_ary[i].w);
    }
    printf("\nmini spain tree:\n");
    for (int i = 0; i < minispain_index; i++)
    {
        printf("Node_1:%d Node_2:%d distance:%lf\n", minimum_spain_tree[i].u, minimum_spain_tree[i].v, minimum_spain_tree[i].w);
    }
    printf("\n");
    for (int i = 0; i < Nodes; i++)
    {
        for (int j = 0; j < Nodes; j++)
        {
            printf("%lf    ", Spain_minimum_ary[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    INP_operation();
    Node_distance();
    Kruskal_Algorithm();
    Transform();
    memset(Node_visited, 0, sizeof(Node_visited));
    DFS(0);
    Print_function();
    return 0;
}