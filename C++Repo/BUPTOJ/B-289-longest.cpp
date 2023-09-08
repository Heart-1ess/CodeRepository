#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> seq;

void solve(){
    int length = 1, d = 1e5 + 1, maxLen = 1;
    vector<int>::iterator it = seq.begin();
    while (it != seq.end() - 1) {
        if (*it - *(it + 1) != d){
            length = 1;
            d = *it - *(it + 1);
        }
        length ++;
        maxLen = max(maxLen, length);
        it ++;
    }
    printf("%d\n", maxLen);
}

int main(){
    int T;
    scanf("%d", &T);
    while (T --){
        int N;
        seq.clear();
        scanf("%d", &N);
        while (N --){
            int temp;
            scanf("%d", &temp);
            seq.push_back(temp);
        }
        solve();
    }
    return 0;
}

/*
input:
2
2
1 3
5
1 6 4 2 4

*/