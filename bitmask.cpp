//状压DP

//P1171 售货员的难题
/*#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = (1 << 20), M = 20 + 1;
int a[M][M], dp[N][M], n, ans = LLONG_MAX;
signed main(){
    cin >> n;
    for(int i = 0;i < n;i ++)
        for(int j = 0;j < n;j ++)
            cin >> a[i][j];
    memset(dp, 0x3f, sizeof(dp));
    dp[1][0] = 0;
    for(int i = 0;i < (1 << n);i ++){
        for(int j = 0;j < n;j ++){
            if(!((i >> j) & 1))
                continue;
            for(int k = 0;k < n;k ++){
                if(i == k)
                    continue;
                if(!((i >> k) & 1))
                    continue;
                dp[i][j] = min(dp[i][j], dp[i ^ (1 << j)][k] + a[k][j]);
            }
        }
    }
    for(int i = 0;i < n;i ++)
        ans = min(ans, dp[(1 << n) - 1][i] + a[i][0]);
    cout << ans << endl;
    return 0;
}*/

//P1896 [SCOI2005] 互不侵犯
/*#include<bits/stdc++.h>
using namespace std;
const int N = 10;
long long dp[N][(1 << N)][N * N], ans; // dp[当前的行][上一行的状态(装压表示)][已有king的数量].
int situation[(1 << N)], num_of_K[(1 << N)];
int n, K, cnt;
void dfs(int binary_expression, int number_of_kings, int current_node){
    if(current_node >= n){
        situation[++ cnt] = binary_expression;
        num_of_K[cnt] = number_of_kings;
        return;
    }
    dfs(binary_expression, number_of_kings, current_node + 1);//不用第current_node个.
    dfs(binary_expression + (1 << current_node), number_of_kings + 1, current_node + 2); // 两个king不能挨着,所以加2.
}
int main(){
    cin >> n >> K;
    dfs(0, 0, 0);
    for(int i = 1;i <= cnt;i ++)
        dp[1][i][num_of_K[i]] = 1;
    for(int i = 2;i <= n;i ++)//枚举第几行
        for(int j = 1;j <= cnt;j ++)//i行国王分配的状态(装压表示)
            for(int k = 1;k <= cnt;k ++){//i-1行国王分配的状态(装压表示)
                if(situation[j] & situation[k]) continue;//如果这一行和上一行的国王在同一列

                //(situation[j 或者 k] << 1) 为将此行的king向右移动一位,看是否能对齐
                if((situation[j] << 1) & situation[k]) continue; //左上右下有重复king
                if(situation[j] & (situation[k] << 1)) continue; //右上左下有重复king

                for(int s = K;s >= num_of_K[j];s --) //背包枚举, num_of_K[j] 为当前状态下king的个数
                    dp[i][j][s] += dp[i - 1][k][s - num_of_K[j]];
            }
    for(int i = 1;i <= cnt;i ++)
        ans += dp[n][i][K]; //i 为第 n 行的所有状态
    cout << ans << endl;
    return 0;
}*/

//P5911 [POI 2004] PRZ
/*#include<bits/stdc++.h>
using namespace std;
const int N = 16 + 1;
int dp[(1 << N)], T[(1 << N)], W[(1 << N)];
int n, m, cnt, a[N], b[N];
int main(){
    cin >> m >> n;
    cnt = (1 << n) - 1;
    for(int i = 1;i <= n;i ++)
        cin >> a[i] >> b[i];
    for(int i = 0;i <= cnt;i ++)
        for(int j = 1;j <= n;j ++)
            if(i & (1 << (j - 1))){
                T[i] = max(T[i], a[j]);
                W[i] += b[j];
            }
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    for(int i = 0;i <= cnt;i ++)
        for(int j = i;;j = i & (j - 1)){
            if(W[i ^ j] <= m)
                dp[i] = min(dp[i], dp[j] + T[i ^ j]);
            if(!j)
                break;
        }
    cout << dp[cnt] << endl;
    return 0;
}*/

//P3959 [NOIP 2017 提高组] 宝藏
/*#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 12, inf = 0x3f3f3f3f;
LL cost[(1 << N)][(1 << N)], a[N][N], n, m;
LL dp[N][(1 << N)], ans = inf;
void init(){
    for(int i = 1;i < (1 << n);i ++)
        for(int j = i;j;j = (j - 1) & i){ //计算将状态 j 转换为 状态 i 的最小值
            if(j == i)
                continue;
            for(int t = 0;t < n;t ++){ //枚举需要加上的节点
                if(!(((i ^ j) >> t) & 1)) //当前状态中必须缺少第 t 个节点, 才能补上
                    continue;
                LL tmp = inf;
                for(int l = 0;l < n;l ++) //枚举 j 里面的点,作为左节点 (t 为右节点)
                    if(((j >> l) & 1)) //j 里面有这个节点
                        tmp = min(tmp, a[l][t]);
                if(tmp == inf){ //t 无法加进来
                    cost[i][j] = inf;
                    break;
                }
                cost[i][j] += tmp;
            }
        }
}
LL DP(int x){
    memset(dp, 0x3f, sizeof(dp));
    dp[0][1 << x] = 0;
    LL res = inf;
    for(int i = 1;i < n;i ++) //枚举节点
        for(int j = 1;j < (1 << n);j ++){ //枚举状态
            for(int k = j;k;k = (k - 1) & j){ //枚举子状态
                if(k == j)
                    continue;
                if(cost[j][k] == inf)
                    continue;
                dp[i][j] = min(dp[i][j], dp[i - 1][k] + 1ll * i * cost[j][k]);
            }
            if(j == (1 << n) - 1)
                res = min(res, dp[i][j]);
        }
    return res;
}
int main(){
    cin >> n >> m;
    if(n == 1){
        cout << 0 << endl;
        return 0;
    }
    memset(a, 0x3f, sizeof(a));
    for(int i = 1;i <= m;i ++){
        LL u, v, x;
        cin >> u >> v >> x;
        u --; v --;
        a[u][v] = a[v][u] = min(a[v][u], x);
    }
    init();
    for(int i = 0;i < n;i ++)
        ans = min(ans, DP(i));
    cout << ans << endl;
    return 0;
}*/

    