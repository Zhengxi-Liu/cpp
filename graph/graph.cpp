/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
struct str{
    int to, next;
}e[N];
int maxx[N], head[N], n, m, x, y, cnt;
void add(int u, int v){
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt ++;
}
void dfs(int u, int v){
    if(maxx[v])
        return ;
    maxx[v] = u;
    for(int i = head[v];i != -1;i = e[i].next){
        int v1 = e[i].to;
        dfs(u, v1);
    }
}
int main(){
    cin >> n >> m;
    memset(head, -1, sizeof(head));
    memset(maxx, 0, sizeof(maxx));
    for(int i = 1;i <= m;i ++){
        cin >> x >> y;
        add(y, x);
    }
    for(int i = n;i >= 1;i --)
        dfs(i, i);
    for(int i = 1;i <= n;i ++){
        cout << maxx[i] << ' ';
    }
    cout << endl;
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 20 + 7;
int x, y, a[N][N], b[N], idx = 0, n, e;
void dfs(int p){
    for(int i = 1;i <= n;i ++)
        if(a[p][i]){
            a[p][i] = 0;
            a[i][p] = 0;
            dfs(i);
        }
    b[++ idx] = p;
}
int main(){
    cin >> n >> e;
    for(int i = 1;i <= e;i ++){
        cin >> x >> y;
        a[x][y] = 1;
        a[y][x] = 1;
    }
    int i1 = 1;
    for(int i = 1;i <= n;i ++){
        int cnt = 0;
        for(int j = 1;j <= n;j ++)
            if(a[i][j])
                cnt ++;
        if(cnt % 2 == 1)
            i1 = i;
    }
    dfs(i1);
    for(int i = idx;i >= 1;i --){
        cout << b[i] << ' ';
    }
    cout << endl;
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 60 + 7;
int a[N][N], dis[N], vis[N], n, s;
int main(){
    cin >> n >> s;
    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= n;j ++)
            cin >> a[i][j];
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0;
    for(int i = 1;i <= n;i ++){
        int mi = -1;
        for(int j = 1;j <= n;j ++){
            if(!vis[j] && (mi == -1 || dis[j] < dis[mi]))
                mi = j;
        }
        vis[mi] = 1;
        for(int j = 1;j <= n;j ++){
            if(!vis[j] && a[mi][j] != 0 && dis[mi] + a[mi][j] < dis[j])
                dis[j] = dis[mi] + a[mi][j];
        }
    }
    for(int i = 1;i <= n;i ++){
        if(dis[i] == 0x3f3f3f3f)
            dis[i] = -1;
        if(i != s)
            cout << dis[i] << ' ';
    }
    cout << endl;
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 7;
int a[N][N], x, y, z, n, m, s, t;
int dis[N], last[N], vis[N], ans[N], idx = 0;
int main(){
    cin >> n >> m >> s >> t;
    memset(a, 0x3f, sizeof(a));
    for(int i = 1;i <= m;i ++){
        cin >> x >> y >> z;
        a[x][y] = min(a[x][y], z);
        a[y][x] = min(a[y][x], z);
    }
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0;
    for(int i = 1;i <= n;i ++){
        int mi = -1;
        for(int j = 1;j <= n;j ++)
            if(!vis[j] && (mi == -1 || dis[j] < dis[mi]))
                mi = j;
        vis[mi] = 1;
        for(int j = 1;j <= n;j ++)
            if(a[mi][j] && dis[j] > dis[mi] + a[mi][j]){
                last[j] = mi;
                dis[j] = dis[mi] + a[mi][j];
            }
    }
    if(dis[t] == 0x3f3f3f3f){
        cout << "can't arrive" << endl;
        return 0;
    }
    cout << dis[t] << endl;
    for(int i = t;i != last[s];i = last[i])
        ans[++ idx] = i;
    for(int i = idx;i >= 1;i --)
        cout << ans[i] << ' ';
    cout << endl;
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
//链式前向星
const int N = 1e6 + 7, M = 1e4 + 7;
struct str{
    int x, y, last_edge;
}a[M];
int latest_edge[N], n, m, idx = 0, s, t, ans[N];
void add(int from, int to){
    idx ++;
    a[idx].x = from;
    a[idx].y = to;
    a[idx].last_edge = latest_edge[from];
    //remember the index number of the last edge of point 'from'
    latest_edge[from] = idx;
}
void print(int xx){
    cout << xx << endl;
    int cnt = 0;
    for(int i = latest_edge[xx];i;i = a[i].last_edge)
        ans[++ cnt] =  a[i].y;
    sort(ans + 1, ans + cnt + 1);
    for(int i = 1;i <= cnt;i ++)
        cout << ans[i] << ' ';
    cout << endl;
}
int main(){
    cin >> n >> m;
    for(int i = 1;i <= m;i ++){
        cin >> s >> t;
        add(s, t);
    }
    for(int i = 1;i <= n;i ++)
        if(latest_edge[i])
            print(i);
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
//dijkstra
const int N =  50 + 7;
struct str{
    int x, y, sum, last_edge;
}a[N];
int latest_edge[N], n, m, s, t, idx = 0;
int dis[N], vis[N];
void add(int from, int to, int l){
    idx ++;
    a[idx].x = from;
    a[idx].y = to;
    a[idx].sum = l;
    a[idx].last_edge = latest_edge[from];
    latest_edge[from] = idx;
}
int main(){
    cin >> n >> m;
    for(int i = 1;i <= m;i ++){
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        add(t1, t2, t3);
        add(t2, t1, t3);
    }
    cin >> s >> t;
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0;
    for(int i = 1;i <= n;i ++){
        int mi = -1;
        for(int j = 1;j <= n;j ++)
            if(!vis[j] && (mi == -1 || dis[mi] > dis[j]))
                mi = j;
        vis[mi] = 1;
        for(int j = latest_edge[mi];j != 0;j = a[j].last_edge)
            if(!vis[a[j].y] && dis[a[j].y] > a[j].sum + dis[mi])
                dis[a[j].y] = a[j].sum + dis[mi];
    }
    if(dis[t] == 0x3f3f3f3f)
        cout << "No path" << endl;
    else
        cout << dis[t] << endl;
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
//SPFA
const int N = 2e5 + 7;
struct str{
    int from, to, sum, last;
}a[N];
int pre[N], n, m, u, v, l, idx = 0;
void add(int u, int v, int l){
    idx ++;
    a[idx].sum = l;
    a[idx].from = u;
    a[idx].to = v;
    a[idx].last = pre[u];
    pre[u] = idx;
}
int dis[N], vis[N];
void SPFA(int s){
    queue<int> q;
    q.push(s);
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0;
    vis[s] = 1;
    while(!q.empty()){
        int now = q.front();
        for(int i = pre[now];i != 0;i = a[i].last)
            if(a[i].sum + dis[now] < dis[a[i].to]){
                dis[a[i].to] = a[i].sum + dis[now];
                if(!vis[a[i].to]){
                    vis[a[i].to] = 1;
                    q.push(a[i].to);
                }
            }
        vis[now] = 0;
        q.pop();
    }
}
int main(){
    cin >> n >> m;
    for(int i = 1;i <= m;i ++){
        cin >> u >> v >> l;
        add(u, v, l);
    }
    SPFA(1);
    for(int i = 2;i <= n;i ++)
        cout << dis[i] << endl;
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
//Floyd
const int N = 1e2 + 7, INF = 0x3f3f3f3f;
int dp[N][N], n, m, u, v, l;
int main(){
    cin >> n >> m;
    memset(dp, 0x3f, sizeof(dp));
    for(int i = 1;i <= m;i ++){
        cin >> u >> v >> l;
        dp[u][v] = l;
    }
    for(int i = 1;i <= n;i ++)
        dp[i][i] = 0;
    for(int k = 1;k <= n;k ++)
        for(int i = 1;i <= n;i ++)
            for(int j = 1;j <= n;j ++){
                if(dp[i][k] != INF && dp[k][j] != INF)
                    dp[i][j] = min(dp[i][k] + dp[k][j], dp[i][j]);
            }
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= n;j ++){
            if(dp[i][j] == INF)
                cout << "N ";
            else
                cout << dp[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
//priority queue dijkstra
const int N = 1e5 + 7;
typedef pair < int, int > pnt;
priority_queue < pnt, vector < pnt > , greater < pnt > > q;
struct str{
    int x, y, last, v;
}a[N];
int pre[N], dis[N], vis[N];
int n, m, k = 0, t1, t2, t3;
void add(int from, int to, int z){
    k ++;
    a[k].x = from;
    a[k].y = to;
    a[k].last = pre[from];
    a[k].v = z;
    pre[from] = k;
}
int main(){
    cin >> n >> m;
    for(int i = 1;i <= m;i ++){
        cin >> t1 >> t2 >> t3;
        add(t1, t2, t3);
    }
    memset(dis, 0x3f, sizeof(dis));
    dis[1] = 0;
    q.push({0, 1});
    while(!q.empty()){
        pnt now = q.top();
        q.pop();
        int s1 = now.first, s2 = now.second;
        if(vis[s2])
            continue;
        for(int i = pre[s2];i;i = a[i].last){
            if(dis[a[i].y] > s1 + a[i].v){
                dis[a[i].y] = s1 + a[i].v;
                q.push({dis[a[i].y], a[i].y});
            }
        }
    }
    if(dis[n] == 0x3f3f3f3f)
        cout << "-1" << endl;
    else
        cout << dis[n] << endl;
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 5e2 + 7, M = 1e3 + 7;
int a[N][N], ans[M], f[N];
int m, x, y, idx, maxn = 0;
void dfs(int p){
    for(int i = 1;i <= maxn;i ++)
        if(a[p][i] >= 1){
            a[p][i] --;
            a[i][p] --;
            dfs(i);
        }
    ans[++ idx] = p;
}
int main(){
    cin >> m;
    for(int i = 1;i <= m;i ++){
        cin >> x >> y;
        a[x][y] ++;
        a[y][x] ++;
        f[x] ++;
        f[y] ++;
        maxn = max(maxn, max(x, y));
    }
    int s = 0;
    for(int i = 1;i <= maxn;i ++){
        if(f[i] && !s)
            s = i;
        if(f[i] % 2 == 1){
            s = i;
            break;
        }
    }
    dfs(s);
    for(int i = idx;i >= 1;i --)
        cout << ans[i] << endl;
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
typedef long long LL;
struct str {
    LL to, v, last;
}a[N * 2];
LL pre[N], k, v[N], n, m, x, y, z;
void add(LL x, LL y, LL v){
    a[++ k].to = y;
    a[k].v = v;
    a[k].last = pre[x];
    pre[x] = k;
}
LL dis[N];
int dijkstra(){
    
}
int main(){
    cin >> n >> m;
    for(int i = 1;i <= n;i ++)
        cin >> v[i];
    for(int i = 1;i <= m;i ++){
        cin >> x >> y >> z;
        add(x, y, z);
        add(y, x, z);
    }
    for(int i = 1;i <= n;i ++){

    }
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 7, MOD = 1e9 + 7;
struct str{
    int to, v, last;
}a[N];
typedef pair <int, int> PI;
int pre[N], dis[N], maxn[N], minn[N], cnt[N], vis[N];
int n, m, k, x, y, z;
void add(int x, int y, int z){
    a[++ k] = {y, z, pre[x]};
    pre[x] = k;
}
priority_queue < PI, vector <PI>, greater <PI> > q;
signed main(){
    cin >> n >> m;
    for(int i = 1;i <= m;i ++){
        cin >> x >> y >> z;
        add(x, y, z);
    }
    memset(dis, 0x3f, sizeof(dis));
    dis[1] = 0;
    q.push({0, 1});
    cnt[1] = 1;
    while(!q.empty()){
        PI now = q.top();
        q.pop();
        int p = now.second, s = now.first;
        if(vis[p])
            continue;
        vis[p] = 1;
        for(int i = pre[p]; i ;i = a[i].last){
            int to = a[i].to;
            if(dis[to] > dis[p] + a[i].v){
                dis[to] = dis[p] + a[i].v;
                maxn[to] = maxn[p] + 1;
                minn[to] = minn[p] + 1;
                cnt[to] = cnt[p];
                q.push({dis[to], to});
            }
            else if(dis[to] == dis[p] + a[i].v){
                maxn[to] = max(maxn[to], maxn[p] + 1);
                minn[to] = min(minn[to], minn[p] + 1);
                cnt[to] = (cnt[to] + cnt[p]) % MOD;
                q.push({dis[to], to});
            }
        }
    }
    cout << dis[n] << ' ' << cnt[n] << ' ' << minn[n] << ' ' << maxn[n] << endl;
    return 0;
}*/