/*#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 7, M = 1e4 + 10;
typedef pair <int, int> PI;
typedef pair <int, PI> PII;
struct node{
    int to, l, last;
} a[M * 2];
int pre1[N], pre2[N], dis[N], f[N], cnt[N];
int n, m, s, t, k, idx;
void add(int pre[], int u, int v, int len){
    a[++ idx] = {v, len, pre[u]};
    pre[u] = idx;
}
void dijkstra(){
    priority_queue < PI, vector <PI>, greater <PI> > q;
    q.push({0, t});
    memset(dis, 0x3f, sizeof(dis));
    dis[t] = 0;
    while(!q.empty()){
        PI now = q.top();
        q.pop();
        if(f[now.second])
            continue;
        f[now.second] = true;
        for(int i = pre2[now.second];i;i = a[i].last){
            int y = a[i].to;
            if(dis[now.second] + a[i].l < dis[y]){
                dis[y] = dis[now.second] + a[i].l;
                q.push({dis[y], y});
            }
        }
    }
}
void astar(){
    priority_queue < PII, vector <PII>, greater <PII> > q;
    q.push({s + dis[s], {0, s}});
    while(!q.empty()){
        PII now = q.top();
        q.pop();
        int p = now.second.second, d = now.second.first;
        cnt[p] ++;
        if(cnt[t] == k){
            cout << d << endl;
            return;
        }
        for(int i = pre1[p];i;i = a[i].last){
            int y = a[i].to;
            if(cnt[y] < k)
                q.push({d + dis[y] + a[i].l, {d + a[i].l, y}});
        }
    }
    cout << -1 << endl;
}
int main(){
    cin >> n >> m >> s >> t >> k;
    int u, v, len;
    while(m --){
        cin >> u >> v >> len;
        add(pre1, u, v, len);
        add(pre2, v, u, len);
    }
    dijkstra();
    astar();
    return 0;
}*/
#include<bits/stdc++.h>
using namespace std;
const int N = 5 + 7;
int t, s1, s2, dep;
char a[N][N];
char stan[10][10] = {
    "",
    " 11111",
    " 01111",
    " 00*11",
    " 00001",
    " 00000",
};
int dx[8] = {1, 1,-1,-1, 2, 2,-2,-2};
int dy[8] = {2,-2, 2,-2, 1,-1, 1,-1};
int f(){
    int cnt = 0;
    for(int i = 1;i <= 5;i ++)
        for(int j = 1;j <= 5;j ++)
            if(a[i][j] != stan[i][j])
                cnt ++;
    return cnt;
}
bool dfs(int step, int x, int y){
    if(dep == step){
        if(!f())
            return true;
        return false;
    }
    for(int i = 0;i < 8;i ++){
        int nx = dx[i] + x, ny = dy[i] + y;
        if(nx < 1 || nx > 5 || ny < 1 || ny > 5)
            continue;
        swap(a[nx][ny], a[x][y]);
        if(step + f() <= dep)
            if(dfs(step + 1, nx, ny))
                return true;
        swap(a[nx][ny], a[x][y]);
    }
    return false;
}
int main(){
    cin >> t;
    while(t --){
        for(int i = 1;i <= 5;i ++)
            for(int j = 1;j <= 5;j ++){
                cin >> a[i][j];
                if(a[i][j] == '*')
                    s1 = i, s2 = j;
            }
        for(dep = 0;dep <= 15;dep ++)
            if(dfs(0, s1, s2))
                break;
        if(dep == 16)
            dep = -1;
        cout << dep << endl;
    }
    return 0;
}