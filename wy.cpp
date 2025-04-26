/*#include<bits/stdc++.h>
using namespace std;
const int N = 5e6 + 7;
int to[N], value[N], last[N], pre[N];
int n, m, K, x, y, len, k = 0, s, t;
void add(int u, int v, int l){
    k ++;
    to[k] = v;
    value[k] = l;
    last[k] = pre[u];
    pre[u] = k;
}
typedef pair <int, int> pnt;
priority_queue <pnt, vector <pnt>, greater <pnt> > q;
int d[N], vis[N];
int main(){
    cin >> n >> m >> K >> s >> t;
    for(int i = 1;i <= m;i ++){
        cin >> x >> y >> len;
        add(x, y, len);
        add(y, x, len);
        for(int j = 1;j <= K;j ++){
            add(x + j * n, y + j * n, len);
            add(y + j * n, x + j * n, len);
            add(x + (j - 1) * n, y + j * n, 0);
            add(y + (j - 1) * n, x + j * n, 0);
        }
    }
    pnt tt;
    tt.first = 0;tt.second = s;
    q.push(tt);
    memset(d, 0x3f, sizeof(d));
    d[s] = 0;
    while(!q.empty()){
        pnt now = q.top();
        q.pop();
        int length = now.first, idx = now.second;
        if(vis[idx])
            continue;
        vis[idx] = 1;
        for(int i = pre[idx];i;i = last[i])
            if(d[to[i]] > length + value[i]){
                d[to[i]] = length + value[i];
                tt.first = d[to[i]];tt.second = to[i];
                q.push(tt);
            }
    }
    int ans = INT_MAX;
    for(int i = 0;i <= K;i ++)
        ans = min(ans, d[t + i * n]);
    cout << ans << endl;
    return 0;
}*/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 7, M = 5e4 + 7, C = 10 + 7;
struct node{
    int p, cnt, dis;
    bool operator < (const node &n) const{
        return dis > n.dis;
    }
};
priority_queue <node> q;
struct edge{
    int len, to, last;
}a[M * 2];
int pre[N], k = 0;
void add(int u, int v, int l){
    k ++;
    a[k].to = v;
    a[k].len = l;
    a[k].last = pre[u];
    pre[u] = k;
}
int dp[N][C], vis[N][C];
int n, m, K, s, t, x, y, l;
int main(){
    cin >> n >> m >> K >> s >> t;
    for(int i = 1;i <= m;i ++){
        cin >> x >> y >> l;
        add(x, y, l);
        add(y, x, l);
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[s][0] = 0;
    q.push({s, 0, 0});
    while(!q.empty()){
        node now = q.top();
        int idx = now.p, cnt = now.cnt, dis = now.dis;
        q.pop();
        if(vis[idx][cnt])
            continue;
        vis[idx][cnt] = 1;
        for(int i = pre[idx];i;i = a[i].last){
            if(cnt < K && dp[idx][cnt] < dp[a[i].to][cnt + 1]){
            	dp[a[i].to][cnt + 1] = dp[idx][cnt];
                q.push({a[i].to, cnt + 1, dp[a[i].to][cnt + 1]});
            }
            
            if(dp[idx][cnt] + a[i].len < dp[a[i].to][cnt]){
            	
            	dp[a[i].to][cnt] = dp[idx][cnt] + a[i].len;
                q.push({a[i].to, cnt, dp[a[i].to][cnt]});
            }
        }
    }
    int ans = INT_MAX;
    for(int i = 0;i <= K;i ++)
        ans = min(ans, dp[t][i]);
    cout << ans << endl;
    return 0;
}