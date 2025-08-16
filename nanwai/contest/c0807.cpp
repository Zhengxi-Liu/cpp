//E. 守卫树
/*#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e3 + 7, MOD = 1e9 + 7;

vector <int> a[N];

int f[N][N][3], dp[N][3];
// 0: 当前节点放了 1: 子节点放了 2: 两个都没放

int sz[N], n, x, y;

void DP(int x, int fa){

    sz[x] = f[x][1][0] = f[x][0][2] = 1;

    for(int to : a[x]){
        if(to == fa) continue;
        DP(to, x);
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i <= sz[x]; i ++){
            for(int j = 0; j <= sz[to]; j ++){
                (dp[i + j][2] += f[x][i][2] * (f[to][j][2] + f[to][j][1]) % MOD) %= MOD;
                if(i){
                    (dp[i + j][1] += f[x][i - 1][2] * f[to][j][0] % MOD + f[x][i][1] * (f[to][j][0] + f[to][j][1] + f[to][j][2]) % MOD) %= MOD;
                    (dp[i + j][0] += f[x][i][0] * ((j ? f[to][j - 1][2] : 0) + f[to][j][1] + f[to][j][0]) % MOD) %= MOD;
                }
            }
        }
        memcpy(f[x], dp, sizeof(dp));
        sz[x] += sz[to];
    }

}

signed main(){

    cin >> n;

    for(int i = 1; i < n; i ++){
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }

    DP(1, 0);

    for(int i = 0; i <= n; i ++)
        cout << (f[1][i][0] + f[1][i][1] + f[1][i][2]) % MOD << endl;

    return 0;
}*/
