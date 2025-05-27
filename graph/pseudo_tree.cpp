//基环树
//P2607 [ZJOI2008] 骑士
//https://www.luogu.com.cn/problem/P2607
/*#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e6 + 7;

vector <int> a[N];

int s[N], vis[N], dp[N][2];

int n, x, r1, r2, ans;

void find(int x, int rt){
    vis[x] = 1;
    for(auto to : a[x]){
        if(to == rt){
            r1 = x, r2 = to;
            return;
        }
        if(vis[to])
            continue;
        find(to, rt);
    }
}

int DP(int x, int rt){
    dp[x][1] = s[x];
    dp[x][0] = 0;
    for(auto to : a[x]){
        if(to == rt)
            continue;
        DP(to, rt);
        dp[x][0] += max(dp[to][0], dp[to][1]);
        dp[x][1] += dp[to][0];
    }
    return dp[x][0];
}

signed main(){
    
    scanf("%lld", &n);

    for(int i = 1; i <= n; i ++){
        scanf("%lld %lld", &s[i], &x);
        a[x].push_back(i);
    }

    for(int i = 1; i <= n; i ++)
        if(!vis[i]){
            r1 = r2 = 0;
            find(i, i);
            if(r1){
                ans += max(DP(r1, r1), DP(r2, r2));
            }
        }
    printf("%lld\n", ans);

    return 0;
}*/

