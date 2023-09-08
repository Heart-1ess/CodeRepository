#include <bits/stdc++.h>

using namespace std;

#define MAXN 101

struct Edge{
    vector<int> decs;
};

int depth[MAXN];
int fa[MAXN];

class Solution{
public:
    void dfs(Edge* E, int num, int dep){
        depth[num] = dep;
        for (int i : E[num].decs){
            dfs(E, i, dep + 1);
        }
    }

    int naive_LCA(int num1, int num2){
        if (depth[num1] < depth[num2]){
            swap(num1, num2);
        }
        while (depth[num1] > depth[num2]){
            num1 = fa[num1];
        }
        while (num1 != num2){
            num1 = fa[num1];
            num2 = fa[num2];
        }

        return num1;
    }
};

int main(){
    int count, queryTimes, N;
    Solution sol = Solution();
    scanf("%d", &count);
    for (int i = 0; i < count; i ++){
        Edge E[MAXN];
        scanf("%d", &N);
        for (int i = 0; i < N - 1; i ++){
            int u, v;
            scanf("%d%d", &u, &v);
            E[u].decs.push_back(v);
            fa[v] = u;
        }
        sol.dfs(E, 1, 1);
        scanf("%d", &queryTimes);
        for (int j = 0; j < queryTimes; j ++){
            int u, v;
            scanf("%d%d", &u, &v);
            printf("%d\n", sol.naive_LCA(u, v));
        }
    }
    return 0;
}

/*
test input:

1
10
1 2
1 3
2 4
4 5
5 6
6 7
7 8
8 9
9 10
1
3 10

2
3
1 2
1 3
1
2 3
4
1 2
1 3
3 4
2
2 3
3 4

*/