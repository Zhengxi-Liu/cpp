//P1352 没有上司的舞会
/*#include<bits/stdc++.h>
using namespace std;
const int N = 6e3 + 7;
vector <int> a[N];
int dp[N][2], v[N], cnt[N];
int n, x, y, f;
void dfs(int p, int fa){
    dp[p][0] = 0;
    dp[p][1] = v[p];
    for(int i = 0;i < a[p].size();i ++){
        int to = a[p][i];
        if(to != fa){
            dfs(to, p);
            dp[p][0] += max(dp[to][0], dp[to][1]);
            dp[p][1] += dp[to][0];
        }
    }
}
int main(){
    cin >> n;
    for(int i = 1;i <= n;i ++)
        cin >> v[i];
    for(int i = 1;i < n;i ++){
        cin >> x >> y;
        a[y].push_back(x);
        cnt[x] ++;
    }
    for(int i = 1;i <= n;i ++)
        if(!cnt[i]){
            f = i;
            break;
        }
    dfs(f, 0);
    cout << max(dp[f][0], dp[f][1]) << endl;
    return 0;
}*/

//P1807 最长路
/*#include<bits/stdc++.h>
using namespace std;
const int N = 5e4 + 7;
struct str{
    int to, v, last;
}a[N * 2];
int pre[N], in[N], maxn[N];
int n, m, x, y, z, k;
void add(int x, int y, int z){
    a[++ k].to = y;
    a[k].v = z;
    a[k].last = pre[x];
    pre[x] = k;
    in[y] ++;
}
void topo(){
    memset(maxn, 0x80, sizeof(maxn));
    maxn[n] = -1;
    maxn[1] = 0;
    queue <int> q;
    q.push(1);
    for(int i = 2;i <= n;i ++)
        if(!in[i])
            q.push(i);
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int i = pre[now];i;i = a[i].last){
            int to = a[i].to;
            maxn[to] = max(maxn[to], maxn[now] + a[i].v);
            in[to] --;
            if(!in[to])
                q.push(to);
        }
    }
}
int main(){
    cin >> n >> m;
    for(int i = 1;i <= m;i ++){
        cin >> x >> y >> z;
        add(x, y, z);
    }
    topo();
    cout << maxn[n] << endl;
    return 0;
}*/

//P2015 二叉苹果树
/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e2 + 7;
int son[N][2], val[N][2], siz[N], dp[N][N];
int n, q, x, op;
void dfs(int p){
    int l = son[p][0], r = son[p][1];
    if(!l && !r) //如果没有左右子树,直接返回
        return;
    dfs(l);
    dfs(r);
    siz[p] = siz[l] + siz[r] + 2;
    for(int i = -1;i <= siz[l];i ++)
        for(int j = -1;j <= siz[r];j ++){
            int x, y;
            if(i == -1) x = 0;
            else x = dp[l][i] + val[p][0];
            if(j == -1) y = 0;
            else y = dp[r][j] + val[p][1];
            dp[p][i + j + 2] = max(dp[p][i + j + 2], x + y);
        }
}
int main(){
    cin >> n >> q;
    for(int i = 1;i < n;i ++){
        cin >> x;
        op = son[x][0] > 0;//如果已有一个儿子,就读第二个儿子,否则读第一个.
        cin >> son[x][op] >> val[x][op];
    }
    dfs(1);
    cout << dp[1][q] << endl;
    return 0;
}*/

//P2014 [CTSC1997] 选课
/*#include<bits/stdc++.h>
using namespace std;
const int N = 3e2 + 7;
vector <int> a[N];
int dp[N][N];
int n, m, ans, x;
void dfs(int p){
    for(int i = 0;i < a[p].size();i ++) //遍历子节点
        dfs(a[p][i]);
    //背包
    for(int i = 0;i < a[p].size();i ++) //枚举子节点
        for(int j = m;j;j --) //枚举父节点容量
            for(int k = 0;k < j;k ++) //枚举子节点容量
                dp[p][j] = max(dp[p][j],    dp[p][j - k] +           dp[a[p][i]][k]); 
    //      父节点有 j 容量的情况         父节点有 j - k 容量的情况          子节点有 k 容量的情况
}
int main(){
    cin >> n >> m;
    ++ m;
    for(int i = 1;i <= n;i ++){
        cin >> x >> dp[i][1];
        a[x].push_back(i);
    }
    dfs(0);
    cout << dp[0][m] << endl;
    return 0;
}*/

//P2279 [HNOI2003] 消防局的设立
