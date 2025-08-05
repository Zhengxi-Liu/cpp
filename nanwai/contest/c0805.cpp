//E. 又一个子矩阵问题
/*#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 3e2 + 7;

int n, m, tp, ans;

int a[N][N], sum[N], mn[N];

int stk[N], l[N], r[N], dis[N];


signed main(){

    cin >> n >> m;

    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++)
            cin >> a[i][j];

    for(int s = 1; s <= n; s ++){
        
        mn[0] = mn[m + 1] = -1e9;
        for(int j = 1; j <= m; j ++)
            mn[j] = 1e9, dis[j] = 0;
        
        for(int t = s; t <= n; t ++){

            for(int j = 1; j <= m; j ++){
                mn[j] = min(mn[j], a[t][j]);
                sum[j] = sum[j - 1] + a[t][j];
                dis[j] += sum[j];
            }

            stk[tp = 1] = 0;
            for(int j = 1; j <= m; j ++){
                while(mn[stk[tp]] >= mn[j]) tp --;
                l[j] = stk[tp];
                stk[++ tp] = j;
            }

            stk[tp = 1] = m + 1;
            for(int j = m; j; j --){
                while(mn[stk[tp]] >= mn[j]) tp --;
                r[j] = stk[tp];
                stk[++ tp] = j;
            }

            for(int j = 1; j <= m; j ++)
                ans = max(ans, (dis[r[j] - 1] - dis[l[j]]) * mn[j]);

        }
    }

    cout << ans << endl;

    return 0;
}*/

//G. 图的计数
/*#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 800 + 7, MOD = 999999599 - 1;

int f[N], g[N][250 + 7];

int n, m, sq = 800;

long long ans;

long long qpow(long long a, long long b){
    long long res = 1;
    while(b){
        if(b & 1) (res *= a) %= (MOD + 1);
        (a *= a) %= (MOD + 1);
        b >>= 1;
    }
    return res;
}


signed main(){

    cin >> n >> m;

    f[0] = 1;

    for(int i = 1; i <= sq; i ++)
        for(int j = i; j <= n; j ++)
            (f[j] += f[j - i]) %= MOD;
    
    g[0][0] = 1;

    for(int i = 0; i <= n; i ++)
        for(int j = 0; j <= 250; j ++){
            (g[i + sq + 1][j + 1] += g[i][j]) %= MOD;
            if(j) (g[i + j][j] += g[i][j]) %= MOD;
        }
    for(int i = 0; i <= n; i ++){
        long long tot = 0;
        for(int j = 0; j <= 250; j ++)
            (tot += g[i][j]) %= MOD;
        (ans += tot * f[n - i] % MOD) %= MOD;
    }
    
    cout << qpow(m, (ans + MOD) % MOD) << endl;

    return 0;
}*/

