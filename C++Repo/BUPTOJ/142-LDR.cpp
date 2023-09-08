#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

#define MAXN 101

struct Edge{
    int to, next;
} edges[MAXN];

char buf[MAXN];
int head[MAXN];
int isVisit[MAXN];
int w;

void LDR(string &str, int nodePos);
void findMin(int& minPoint, int nodePos);

void add(int u, int v){
    w ++;
    edges[w].next = head[u];
    head[u] = w;
    edges[w].to = v;
}

void solve(int nodeNum){
    string result[MAXN];
    for (int i = 0; i < nodeNum; i ++){
        memset(isVisit, 0, sizeof(int) * nodeNum);
        isVisit[i] = 1;
        LDR(result[i], i);
    }
    string res = result[0];
    for (int i = 1; i < nodeNum; i ++){
        res = strcmp(res.c_str(), result[i].c_str()) < 0 ? res : result[i];
    }
    cout << res << endl;
}

void LDR(string &str, int nodePos){
    int minPoint;
    findMin(minPoint, nodePos);
    if (minPoint == MAXN);
    else {
        LDR(str, minPoint);
    }
    str.append(buf, nodePos, 1);
    findMin(minPoint, nodePos);
    while (minPoint != MAXN){
        LDR(str, minPoint);
        findMin(minPoint, nodePos);
    }
}

void findMin(int& minPoint, int nodePos){
    minPoint = MAXN;
    for (int i = head[nodePos]; i; i = edges[i].next){
        if (isVisit[edges[i].to] == 0){
            minPoint = min(minPoint, edges[i].to);
        }
    }
    if (minPoint == MAXN){ return; }
    else {
        isVisit[minPoint] = 1;
    }
}

int main(){
    int nodeNum;
    while (scanf("%d", &nodeNum) != EOF){
        cin >> buf;
        w = 0;
        memset(head, 0, sizeof(int) * nodeNum);
        for (int i = 0; i < nodeNum - 1; i ++){
            int u, v;
            scanf("%d%d", &u, &v);
            add(u, v);
            add(v, u);
        }
        solve(nodeNum);
    }
    return 0;
}

/*
input:

3
bac
0 1
1 2
4
abcd
0 1
0 2
0 3
*/