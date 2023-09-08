#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define MAXN 51
#define MAXM 2451

struct Edge{
    int to, next;
} edges[MAXM];

int isVisit[MAXN];
int dist[MAXN];
int length[MAXN];
int head[MAXM];
int w;

void add(int u, int v){
    w ++;
    edges[w].next = head[u];
    head[u] = w;
    edges[w].to = v;
}

void BFS(int node, int N){
    queue<int> q;
    int len = 1;
    memset(isVisit, 0, sizeof(int) * (N + 1));
    for (int i = 1; i <= N; i ++){
        dist[i] = N;
    }
    q.push(node);
    isVisit[node] = 1;
    dist[node] = 0;
    while (q.empty() == false){
        int temp = q.front();
        for (int i = head[temp]; i; i = edges[i].next){
            if (isVisit[edges[i].to] == 0){
                q.push(edges[i].to);
                isVisit[edges[i].to] = 1;
                dist[edges[i].to] = dist[temp] + 1;
            }
        }
        q.pop();
    }
    for (int i = 1; i <= N; i ++){
        length[node] += dist[i];
    }
}

int main(){
    int T;
    scanf("%d", &T);
    while (T --){
        int N, M, res = 1;
        w = 0;
        scanf("%d%d", &N, &M);
        memset(head, 0, sizeof(int) * (N + 1));
        memset(length, 0, sizeof(int) * (N + 1));
        for (int i = 0; i < M; i ++){
            int u, v;
            scanf("%d%d", &u, &v);
            add(u, v);
            add(v, u);
        }
        for (int i = 1; i <= N; i ++) { BFS(i, N); }
        for (int i = 1; i <= N; i ++){
            res = length[res] <= length[i] ? res : i;
        }
        printf("%d\n", res);
    }
    return 0;
}

/*
input:
2
3 3
1 2
1 3
2 3
4 2
1 2
2 3

*/