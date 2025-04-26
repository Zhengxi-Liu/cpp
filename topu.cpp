/*#include<bits/stdc++.h>
using namespace std;
const int N = 2e3 + 7;
int a[N][N], d[N], ans[N];
int n, m, t, x, y, k;
queue <int> q;
int main(){
    cin >> t;
    while(t --){
        cin >> n >> m;
        memset(d, 0, sizeof(d));
        memset(a, 0, sizeof(a));
        for(int i = 1;i <= m;i ++){
            cin >> x >> y;
            d[y] ++;
            a[x][y] = 1;
        }
        for(int i = 1;i <= n;i ++){
            if(!d[i])
                q.push(i);
        }
        while(!q.empty()){
            int now = q.front();
            ans[++ k] = now;
            q.pop();
            for(int i = 1;i <= n;i ++)
                if(a[now][i]){
                    d[i] --;
                    if(!d[i])
                        q.push(i);
                }
        }
        if(k < n)
            cout << "Y" << endl;
        else
            cout << "N" << endl;
        k = 0;
    }
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 2e3 + 7;
int a[N][N], vis[N];
int n, m, t, x, y, k;
bool ans;
void dfs(int p){
    vis[p] = 1;
    for(int i = 1;i <= n;i ++)
        if(a[p][i]){
            if(vis[i] == 1){
                ans = true;
                return;
            }
            else if(!vis[i])
                dfs(i);
        }
    vis[p] = 2;
}
int main(){
    cin >> t;
    while(t --){
        cin >> n >> m;
        memset(a, 0, sizeof(a));
        memset(vis, 0, sizeof(vis));
        for(int i = 1;i <= m;i ++){
            cin >> x >> y;
            a[x][y] = 1;
        }
        ans = false;
        for(int i = 1;i <= n;i ++)
            if(!vis[i])
                dfs(i);
        if(ans == true)
            cout << "Y" << endl;
        else
            cout << "N" << endl;
    }
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
struct str{
    int to, last;
}a[N];
int pre[N], d[N], s[N];
int n, m, x, y, k, cnt;
void add(int x, int y){
    a[++ k].to = y;
    a[k].last = pre[x];
    pre[x] = k;
}
queue <int> q;
int main(){
    cin >> n >> m;
    for(int i = 1;i <= m;i ++){
        cin >> x >> y;
        add(y, x);
        d[x] ++;
    }
    for(int i = 1;i <= n;i ++)
        if(!d[i]){
            q.push(i);
            s[i] = 100;
        }
    while(!q.empty()){
        int now = q.front();
        cnt ++;
        q.pop();
        for(int i = pre[now]; i ;i = a[i].last){
            d[a[i].to] --;
            if(!d[a[i].to]){
                q.push(a[i].to);
                s[a[i].to] = s[now] + 1;
            }
        }
    }
    if(cnt < n)
        cout << "impossible" << endl;
    else {
        int ans = 0;
        for(int i = 1;i <= n;i ++)
            ans += s[i];
        cout << ans << endl;
    }
    return 0;
}*/

/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 7;
struct str{
    int to, v, last;
}a[N * 2];
int pre[N], k;
void add(int x, int y, int v){
    a[++ k].to = y;
    a[k].v = v;
    a[k].last = pre[x];
    pre[x] = k;
}
bool f[N];
int n, m, s, x, y, z;
int cnt[N], dis[N];
queue <int> q;
bool check(){
    for(int i = 1;i <= n;i ++){
        q.push(i);
        f[i] = true;
    }
    while(!q.empty()){
        int now = q.front();
        q.pop();
        f[now] = false;
        for(int i = pre[now];i;i = a[i].last)
            if(dis[now] + a[i].v < dis[a[i].to]){
                cnt[a[i].to] = cnt[now] + 1;
                dis[a[i].to] = dis[now] + a[i].v;
                if(cnt[a[i].to] == n)
                    return true;
                if(!f[a[i].to]){
                    q.push(a[i].to);
                    f[a[i].to] = true;
                }
            }
    }
    return false;
}
void spfa(){
    if(check()){
        cout << -1 << endl;
        return;
    }
    memset(dis, 0x3f, sizeof(dis));
    memset(f, 0, sizeof(f));
    while(!q.empty())
        q.pop();
    q.push(s);
    dis[s] = 0;
    f[s] = true;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        f[now] = false;
        for(int i = pre[now];i;i = a[i].last)
            if(dis[now] + a[i].v < dis[a[i].to]){
                dis[a[i].to] = dis[now] + a[i].v;
                if(!f[a[i].to]){
                    q.push(a[i].to);
                    f[a[i].to] = true;
                }
            }
    }
    for(int i = 1;i <= n;i ++){
        if(dis[i] == 0x3f3f3f3f)
            printf("NoPath\n");
        else
            printf("%d\n", dis[i]);
    }
}
int main(){
    cin >> n >> m >> s;
    for(int i = 1;i <= m;i ++){
        scanf("%d%d%d", &x, &y, &z);
        add(x, y, z);
    }
    spfa();
    return 0;
}*/

//P5960 【模板】差分约束
/*#include<bits/stdc++.h>
using namespace std;
const int N = 5e3 + 7;
struct str{
    int to, v, last;
}a[N * 2];
int pre[N], dis[N], vis[N], cnt[N];
int n, m, k, x, y, z;
void add(int x, int y, int z){
    a[++ k].to = y;
    a[k].last = pre[x];
    a[k].v = z;
    pre[x] = k;
}
queue <int> q;
bool spfa(){
    memset(dis, 0x3f, sizeof(dis));
    dis[0] = 0;
    q.push(0);
    vis[0] = 1;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        vis[now] = 0;
        for(int i = pre[now];i;i = a[i].last){
            int to = a[i].to;
            if(dis[to] > dis[now] + a[i].v){
                dis[to] = dis[now] + a[i].v;
                if(!vis[to]){
                    q.push(to);
                    vis[to] = 1;
                    cnt[to] ++;
                    if(cnt[to] == n + 1)
                        return false;
                }
            }
        }
    }
    return true;
}
int main(){
    cin >> n >> m;
    for(int i = 1;i <= n;i ++)
        add(0, i, 0);
    for(int i = 1;i <= m;i ++){
        cin >> x >> y >> z;
        add(y, x, z);
    }
    if(!spfa()){
        cout << "NO" << endl;
        return 0;
    }
    for(int i = 1;i <= n;i ++)
        cout << dis[i] << ' ';
    cout << endl;
    return 0;
}*/

#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
struct str{
    int to, last;
}a[N];
int pre[N], s[N], d[N], dp[N];
int n, m, t, x, y, k;
queue <int> q;
void add(int x, int y){
    a[++ k].to = y;
    a[k].last = pre[x];
    pre[x] = k;
}
int main(){
    cin >> n >> m;
    for(int i = 1;i <= n;i ++)
        cin >> s[i];
    for(int i = 1;i <= m;i ++){
        cin >> x >> y;
        d[y] ++;
        add(x, y);
    }
    for(int i = 1;i <= n;i ++)
        if(!d[i]){
            dp[i] = s[i];
            q.push(i);
        }
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int i = pre[now]; i; i = a[i].last){
            d[a[i].to] --;
            dp[a[i].to] = max(dp[a[i].to], dp[now] + s[a[i].to]);
            if(!d[a[i].to])
                q.push(a[i].to);
        }
    }
    int ans = 0;
    for(int i = 1;i <= n;i ++)
        ans = max(ans, dp[i]);
    cout << ans << endl;
    return 0;
}
