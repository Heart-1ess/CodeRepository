#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> space;
vector<int> ifUsed;

void solve(int memory, int N){
    int pos = -1;
    for (int i = 0; i < N; i ++){
        if (pos == -1){
            if (space[i] >= memory && ifUsed[i] == 0){ pos = i; }
        }
        else {
            if (space[i] >= memory && ifUsed[i] == 0){
                pos = space[pos] > space[i] ? i : pos;
            }
        }
    }
    if (pos == -1) { printf("NULL"); }
    else { 
        ifUsed[pos] = 1;
        printf("%d", space[pos]); 
    }
}

int main(){
    int T;
    scanf("%d", &T);
    while (T --){
        int N, M;
        scanf("%d", &N);
        space.clear();
        ifUsed.clear();
        for (int i = 0; i < N; i ++){
            int temp;
            scanf("%d", &temp);
            space.push_back(temp);
            ifUsed.push_back(0);
        }
        scanf("%d", &M);
        int memory;
        for (int i = 0; i < M - 1; i ++){
            scanf("%d", &memory);
            solve(memory, N);
            printf(" ");
        }
        scanf("%d", &memory);
        solve(memory, N);
        printf("\n");
    }

    return 0;
}

/*
input:
2
4
7 5 10 3
2
4 6
4
3 5 9 10
3
5 12 6

*/