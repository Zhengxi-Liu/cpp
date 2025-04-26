/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e2 + 7;
int d[N], t[N], l[N], r[N], n;
void dfs(int k, int vis){
    if(vis == 1)
        cout << k << ' ';
    if(l[k] != 0)
        dfs(t[l[k]], vis);
    if(vis == 2)
        cout << k << ' ';
    if(r[k] != 0)
        dfs(t[r[k]], vis);
    if(vis == 3)
        cout << k << ' ';
}
int main(){
    cin >> n;
    for(int i = 1;i <= n;i ++){
        cin >> d[i] >> l[i] >> r[i];
        t[d[i]] = i;
    }
    dfs(1, 1);
    cout << endl;
    dfs(1, 2);
    cout << endl;
    dfs(1, 3);
    cout << endl;
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e2 + 7, INF = 0x3f3f3f3f;
int dp[N][N], n, m, k, q, x, y, z, ans, cnt;
signed main(){
    cin >> n >> m >> k >> q;
    memset(dp, 0x3f, sizeof(dp));
    for(int i = 1;i <= m;i ++){
        cin >> x >> y >> z;
        dp[x][y] = min(dp[x][y], z);
    }
    for(int i = 1;i <= n;i ++)
        dp[i][i] = 0;
    for(int k = 1;k <= n;k ++)
        for(int i = 1;i <= n;i ++)
            for(int j = 1;j <= n;j ++){
                if(dp[i][k] != INF && dp[k][j] != INF)
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
    while(q --){
        cin >> x >> y;
        int minn = INF;
        for(int i = 1;i <= k;i ++){
            if(dp[x][i] != INF && dp[i][y] != INF)
                minn = min(minn, dp[x][i] + dp[i][y]);
        }
        if(minn != INF){
            cnt ++;
            ans += minn;
        }
    }
    cout << cnt << endl << ans;
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
struct str{
    int to, v, last;
}a[N * 2];
int dis[N][2], pre[N];
bool vis[N];
int n, k, m, x, y, z;
void add(int x, int y, int z){
    a[++ k] = {y, z, pre[x]};
    pre[x] = k;
}
typedef pair <int, int> PI;
priority_queue < PI, vector <PI>, greater <PI> > q;
int main(){
    cin >> n >> m;
    for(int i = 1;i <= m;i ++){
        cin >> x >> y >> z;
        add(x, y, z);
        add(y, x, z);
    }
    memset(dis, 0x3f, sizeof(dis));
    dis[1][0] = dis[1][1] = 0;
    q.push({0, 1});
    while(!q.empty()){
        int p = q.top().second;
        q.pop();
        if(vis[p])
            continue;
        vis[p] = true;
        for(int i = pre[p];i;i = a[i].last){
            int to = a[i].to;
            bool flag = false;
            if(dis[to][0] < dis[p][1] + a[i].v / 2){
                dis[to][0] = dis[p][1] + a[i].v / 2;
                flag = true;
            }
            if(dis[to][0] < dis[p][0] + a[i].v){
                dis[to][0] = dis[p][0] + a[i].v;
                flag = true;
            }
            if(dis[to][1] < dis[p][1] + a[i].v){
                dis[to][1] = dis[p][1] + a[i].v;
                flag = true;
            }
            if(flag)
                q.push({dis[to][0] + dis[to][1], to});
        }
    }
    cout << min(dis[n][1], dis[n][0]) << endl;
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
multiset <int> a;
int b[N], n, m, x;
int main(){
    cin >> n >> m;
    for(int i = 1;i <= n;i ++)
        cin >> b[i];
    sort(b + 1, b + n + 1);
    for(int i = 1;i <= n;i ++)
        a.insert(b[i]);
    while(m --){
        cin >> x;
        auto k = a.upper_bound(x);
        if(k == a.begin())
            cout << -1 << endl;
        else {
            -- k;
            cout << *k << endl;
            a.erase(k);
        }
    }
    return 0;
}*/
