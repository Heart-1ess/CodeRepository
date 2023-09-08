#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;
#define MAXN 55

const int MAXD = 1e5;
int N;
int dp[MAXN][MAXD];
int ddl = 0;

struct Project{
    int P, L, D;
    bool operator<(const Project X){
        return D < X.D;
    }
}prj[MAXN];

void solve(){
    sort(prj + 1, prj + N + 1);
    for (int i = 1; i <= N; i ++){
        for (int j = 1; j <= ddl; j ++){
            if (j <= prj[i].D){
                if (j < prj[i].L){
                    dp[i][j] = dp[i - 1][j];
                }
                else if (j == prj[i].L){
                    dp[i][j] = max(dp[i - 1][j], prj[i].P);
                }
                else if (j > prj[i].L){
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - prj[i].L] + prj[i].P);
                }
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    printf("%d", dp[N][ddl]);
}

int main(){
    scanf("%d", &N);
    for (int i = 1; i <= N; i ++){
        scanf("%d%d%d", &prj[i].P, &prj[i].L, &prj[i].D);
        ddl = max(ddl, prj[i].D);
    }
    solve();
    return 0;
}