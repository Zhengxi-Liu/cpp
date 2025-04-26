/*#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1e6 + 7;
LL dp[N], f[N], ans;
LL a[N], n, m;
int main(){
    cin >> n >> m;
    for(int i = 1;i <= n;i ++){
        cin >> a[i];
        int id = (a[i] % m + m) % m, t;
        if(!id)
            t = 0;
        else
            t = m - id;
        f[id] = max(f[id], f[t] + a[i]);
    }
    for(int i = 0;i < m;i ++){
        ans = max(ans, f[i]);
    }
    cout << ans << endl;
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 7, MOD = 998244353;
long long a[N], n, b[N], dis[N], ans;
void dfs(int step){
    if(step > n){
        long long l = 1e9, r = 0, cnt = 0;
        for(long long i = 1;i <= n;i ++)
            if(b[i]){
                l = min(l, i);
                r = max(r, i);
                cnt += a[i];
            }
        if(!r)
            return;
        //cout << cnt << ' ';
        if(cnt == dis[r] - dis[l - 1])
            ans ++;
        ans %= MOD;
        return;
    }
    b[step] = 1;
    dfs(step + 1);
    b[step] = 0;
    dfs(step + 1);
}
int main(){
    cin >> n;
    for(int i = 1;i <= n;i ++){
        cin >> a[i];
        dis[i] = dis[i - 1] + a[i]; 
    }
    dfs(1);
    cout << ans << endl;
    return 0;
}*/

// #include<bits/stdc++.h>
// using namespace std;
// const int N = 1e3 + 7, MOD = 998244353;
// long long a[N], n, b[N], dis[N], ans;
// void dfs(int step){
//     if(step > n){
//         long long l = 1e9, r = 0, cnt = 0, t = 0;
//         for(long long i = 1;i <= n;i ++){
//             if(b[i]){
//                 t ++;
//                 l = min(l, i);
//                 r = max(r, i);
//                 cnt += a[i];
//             }
//         }
//         if(!r)
//             return;
//         //cout << cnt << ' ';
//         if(cnt == dis[r] - dis[l - 1]){
//             ans ++;
//             if(r - l + 1 != t){
//                 for(int i = 1;i <= n;i ++)
//                     cout << b[i] << ' ';
//                 cout << endl;
//             }
//         }
//         ans %= MOD;
//         return;
//     }
//     b[step] = 1;
//     dfs(step + 1);
//     b[step] = 0;
//     dfs(step + 1);
// }
// int main(){
//     cin >> n;
//     for(int i = 1;i <= n;i ++){
//         cin >> a[i];
//         dis[i] = dis[i - 1] + a[i]; 
//     }
//     dfs(1);
//     cout << ans << endl;
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
const int N = 10;
int dp[N][N][N][N];
int a[N][N], n, x, y, v;
int main(){
    cin >> n;
    while(cin >> x >> y >> v){
        if(!x && !y && !v)
            break;
        a[x][y] = max(a[x][y], v);
    }
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++)
            for(int l = 1; l <= n; l ++)
                for(int r = 1; r <= n; r ++){
                    dp[i][j][l][r] = max(max(dp[i - 1][j][l - 1][r], dp[i - 1][j][l][r - 1]), max(dp[i][j - 1][l - 1][r], dp[i][j - 1][l][r - 1])) + a[i][j] + a[l][r];
                    if(i == l && j == r)
                        dp[i][j][l][r] -= a[i][j];
                }
    cout << dp[n][n][n][n] << endl;
    return 0;
}