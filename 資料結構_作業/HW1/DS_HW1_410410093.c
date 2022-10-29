// 410410093 Data Structure project01

#include <stdio.h>

struct Node{
    int nodeId, qm;
};
struct Request{
    int reqId, reqS, reqD, rep[1000];
};
//宣告變數
#define Max 1000
int Nodes, Links, Req;
struct Node node[Max];
int link[Max][Max] = {0};
struct Request req[Max];
//讀進input
void Inp(){
    int cnt;
    scanf("%d %d %d", &Nodes, &Links, &Req);
    for(cnt=0; cnt<Nodes; cnt++){
        scanf("%d %d", &node[cnt].nodeId, &node[cnt].qm);
    }
    for(cnt=0; cnt<Links; cnt++){
        int linkId, linkEnd1, linkEnd2, channel;
        scanf("%d %d %d %d", &linkId, &linkEnd1, &linkEnd2, &channel);
        link[linkEnd1][linkEnd2] = channel;
        link[linkEnd2][linkEnd1] = channel;
    }
    for(cnt=0; cnt<Req; cnt++){
        scanf("%d %d %d", &req[cnt].reqId, &req[cnt].reqS, &req[cnt].reqD);
    }
    return;
}
//accept the req or not
int AccReq(int ReqId){
    int dis[Nodes], book[Nodes], path[Nodes][Nodes];
    int cnt, cnt2, cnt3;
    int ReqSrc = req[ReqId].reqS, ReqDst = req[ReqId].reqD;
    for(cnt=0; cnt<Nodes; cnt++){//initialize dis
        if(link[ReqSrc][cnt]){//ReqSrc與各點的距離
            dis[cnt] = 1;
        }
        else{
            dis[cnt] = 9999;
        }
        book[cnt] = 0;
        for(cnt2=0; cnt2<Nodes; cnt2++){//initialize path
            path[cnt][cnt2] = 0;
        }
    }
    dis[ReqSrc] = 0;
    
    for(cnt=0; cnt<Nodes; cnt++){//dijkstra
        int min = 9999, minId = -1;
        for(cnt2=0; cnt2<Nodes; cnt2++){//尋找最接近ReqSrc的點且ID越小視為越接近
            if(book[cnt2] == 0 && dis[cnt2] < min){
                min = dis[cnt2];
                minId = cnt2;
            }
        }
        if(minId == -1){//找不到路直接return
            return 0;
        }
        book[minId] = 1;
        if(link[minId][ReqDst]){//如果找到的點和終點有連線，跳出迴圈
            dis[ReqDst] = dis[minId] + 1;
            path[ReqDst][minId] = 1;//ReqDst是路徑上第(cnt+1)個點
            break;
        }
        else{
            for(cnt3=0; cnt3<Nodes; cnt3++){//更新ReqSrc到各點的距離
                if(link[cnt2][cnt3]){
                    if(dis[cnt3] > dis[cnt2] + 1){
                        dis[cnt3] = dis[cnt2] + 1;
                        path[cnt3][cnt2] = 1;
                    }
                }
            }
        }
    }
    req[ReqId].rep[cnt+2] = -1;//設定req[ReqId].rep的結尾
    req[ReqId].rep[cnt+1] = ReqDst;
    for(cnt2=cnt; cnt2>=0; cnt2--){//由ReqDst往回找路徑並倒著存入req[ReqId].rep
        int N = req[ReqId].rep[cnt2+1];//N=現在的點，cnt2=N前面一個點的index
        for(cnt3=0; cnt3<Nodes; cnt3++){
            if(path[N][cnt3]){//有連線就存起來跳出迴圈
                req[ReqId].rep[cnt2] = cnt3;
                break;
            }
        }
    }
    return 1;
}
//main
int main(){
    int cnt, accepted = 0;
    Inp();
    int accReqs[Req];
    for(cnt=0; cnt<Req; cnt++){
        if(AccReq(cnt)){
            accReqs[accepted] = cnt;
            accepted++;
        }
    }
    printf("%d\n", accepted);
    for(cnt=0; cnt<accepted; cnt++){
        int cnt2 = 0;
        int id = accReqs[cnt];
        printf("%d", id);
        while(req[id].rep[cnt2] != -1){
            printf(" %d", req[id].rep[cnt2]);
            cnt2++;
        }
        printf("\n");
    }
}