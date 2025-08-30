/*
** 网络流问题 **
注: 在不考虑复杂度的情况下，任何网络流问题的图都可以变成 DAG，且最大流值保持不变。
*/

// P3376 【模板】网络最大流

// FF 算法: 84 pts
/*#include<bits/stdc++.h>
using namespace std;

const int N = 5e3 + 7;

struct str{
    int to, lst, v;
}e[N * 2];

int st[N], vis[N], k = 1;

void add(int x, int y, int v){
    e[++ k] = {y, st[x], v};
    st[x] = k;
}

int n, m, bg, ed, x, y, v, flg;

long long ans;

int dfs(int x, int mn){
    
    vis[x] = 1;
    if(x == ed){
        ans += mn;
        flg = true;
        return mn;
    }

    for(int i = st[x]; i; i = e[i].lst){
        if(vis[e[i].to]) continue;
        if(!e[i].v) continue;
        int tmp = dfs(e[i].to, min(mn, e[i].v));
        if(tmp) {
            e[i].v -= tmp;
            e[i ^ 1].v += tmp;
            return tmp;
        }
    }

    return 0;

}

void cal(){
    int cnt = 0;
    dfs(bg, 1e9);
    while(flg){
        flg = false;
        memset(vis, 0, sizeof(vis));
        dfs(bg, 1e9);
    }

}

int main(){

    cin >> n >> m >> bg >> ed;

    while(m --){

        cin >> x >> y >> v;

        add(x, y, v);
        add(y, x, 0);

    }

    cal();

    cout << ans << endl;

    return 0;
}*/

// Dinic 算法: 100 pts
/*#include<bits/stdc++.h>
using namespace std;

const int N = 5e3 + 7;

#define int long long

struct str{
    int to, lst, v;
}e[N * 2];

int st[N], k = 1;

int dis[N], jump[N];

int n, m, bg, ed, x, y, v;

int ans;

void add(int x, int y, int v){
    e[++ k] = {y, st[x], v};
    st[x] = k;
}

queue <int> q;

bool bfs(){ // break the graph into different layers

    memset(dis, 0, sizeof(dis));
    while(!q.empty()) q.pop();
    q.push(bg);
    dis[bg] = 1;

    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int i = st[now]; i; i = e[i].lst){
            if(dis[e[i].to] || !e[i].v) continue; // we only include usable edges
            dis[e[i].to] = dis[now] + 1;
            q.push(e[i].to);
            if(e[i].to == ed) return true;
        }
    }

    return false;

}

int dfs(int x, int mn){

    if(x == ed) return mn;

    int sum = 0;

    for(int i = jump[x]; i; i = e[i].lst){
        jump[x] = i; // when get here again, we start from jump
        int to = e[i].to, v = e[i].v;
        if(!v || dis[to] != dis[x] + 1) continue;
        int tmp = dfs(to, min(mn, v));
        sum += tmp;
        e[i].v -= tmp;
        e[i ^ 1].v += tmp;
        mn -= tmp; // sum of flow left
        if(!mn) break;
    }

    if(!sum) dis[x] = 0; // if the current node can't even transport a single flow, then it's useless
    return sum;

}

void dinic(){
    
    while(bfs()){
        memcpy(jump, st, sizeof(st));
        ans += dfs(bg, LLONG_MAX);
    }

}

signed main(){

    cin >> n >> m >> bg >> ed;

    while(m --){
        cin >> x >> y >> v;
        add(x, y, v);
        add(y, x, 0);
    }
    
    dinic();

    cout << ans << endl;

    return 0;
}*/


//[USACO4.2] 草地排水 Drainage Ditches
/*#include<bits/stdc++.h>
using namespace std;

const int N = 2e2 + 7;

struct str{
    int to, v, nxt;
}a[N];

int lst[N], k = 1;

int m, n, x, y, v, ans;

void add(int x, int y, int v){
    a[++ k] = {y, v, lst[x]};
    lst[x] = k;
}

int dis[N], jump[N];

queue <int> q;

bool bfs(){

    while(!q.empty()) q.pop();
    q.push(1);
    memset(dis, 0, sizeof(dis));
    dis[1] = 1;

    while(!q.empty()){
        int now = q.front();
        q.pop();
        if(now == n) return true;
        for(int i = lst[now]; i; i = a[i].nxt){
            int to = a[i].to;
            if(dis[to] || !a[i].v) continue;
            dis[to] = dis[now] + 1;
            q.push(to);
        }
    }

    return false;

}

int dfs(int x, int mn){

    if(x == n) return mn;

    int sum = 0;

    for(int i = jump[x]; i; i = a[i].nxt){
        jump[x] = i;
        int to = a[i].to;
        if(dis[to] != dis[x] + 1 || !a[i].v) continue;
        int tmp = dfs(to, min(a[i].v, mn));
        sum += tmp;
        mn -= tmp;
        a[i].v -= tmp;
        a[i ^ 1].v += tmp;
        if(!mn) break;
    }

    if(!sum) dis[x] = 0;
    return sum;

}

void dinic(){
    while(bfs()){
        memcpy(jump, lst, sizeof(lst));
        ans += dfs(1, 1e9);
    }
}

int main(){

    cin >> m >> n;

    while(m --){
        cin >> x >> y >> v;
        add(x, y, v);
        add(y, x, 0);        
    }

    dinic();

    cout << ans << endl;

    return 0;
}*/

//UVA10330 电力传输
/*#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e6 + 7, INF = 1e18;

struct str{
    int to, v, nxt;
}a[N];

int s[N], d[N], lst[N], k;

int n, m, x, y, v, S, T, ans;

void add(int x, int y, int v){
    a[++ k] = {y, v, lst[x]};
    lst[x] = k;
}

int dis[N], jump[N];

queue <int> q;

bool bfs(){

    while(!q.empty()) q.pop();
    q.push(S);

    memset(dis, 0, sizeof(dis));
    dis[S] = 1;

    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int i = lst[now]; i; i = a[i].nxt){
            int to = a[i].to, dct = i & 1;
            if(dis[to] || !a[i].v) continue;
            if(!dct && d[to] == s[to] || dct && !d[to]) continue;
            dis[to] = dis[now] + 1;
            q.push(to);
            if(to == T) return true;
        }
    }

    return false;

}

int dfs(int x, int mn){

    if(x == T) return mn;

    int sum = 0;

    for(int i = jump[x]; i; i = a[i].nxt){

        jump[x] = i;
        int to = a[i].to, dct = i & 1; // 0 为正边, 1 为反边
        if(dis[to] != dis[x] + 1 || !a[i].v) continue;
        if(!dct && d[to] == s[to] || dct && !d[to]) continue;

        int flow = min(mn, a[i].v);
        if(!dct) flow = min(flow, s[to] - d[to]);
        else flow = min(flow, d[to]);
        int tmp = dfs(to, flow);

        mn -= tmp;
        sum += tmp;
        a[i].v -= tmp;
        a[i ^ 1].v += tmp;

        if(!dct) d[to] += tmp;
        else d[to] -= tmp;

    }
    
    if(!sum) dis[x] = 0;
    return sum;

}

void dinic(){
    while(bfs()){
        memcpy(jump, lst, sizeof lst);
        ans += dfs(S, INF);
    }
}

signed main(){

    while(true){

        k = 1, ans = 0;
        memset(d, 0, sizeof(d));
        memset(lst, 0, sizeof(lst));

        cin >> n;

        if(cin.fail()) break;

        for(int i = 1; i <= n; i ++)
            cin >> s[i];

        cin >> m;

        while(m --){
            cin >> x >> y >> v;
            add(x, y, v);
            add(y, x, 0);
        }

        cin >> S >> T;

        for(int i = 1; i <= S; i ++){
            cin >> x;
            add(n + 1, x, INF);
            add(x, n + 1, 0);
        }

        for(int i = 1; i <= T; i ++){
            cin >> x;
            add(x, n + 2, INF);
            add(n + 2, x, 0);
        }

        S = n + 1, T = n + 2;
        s[S] = s[T] = INF;

        dinic();

        cout << ans << endl;

    }

    return 0;
}*/

//P1343 地震逃生
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 4e3 + 7;

struct str{
    int to, v, nxt;
}a[N];

int lst[N], k = 1;

void add(int x, int y, int v){
    a[++ k] = {y, v, lst[x]};
    lst[x] = k;
}

int n, m, sum, x, y, v;

int dis[N], jump[N];
queue <int> q;

bool bfs(){

    while(!q.empty()) q.pop();
    q.push(1);

    memset(dis, 0, sizeof(dis));
    dis[1] = 1;

    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int i = lst[now]; i; i = a[i].nxt){
            int to = a[i].to;
            if(dis[to] || !a[i].v) continue;
            dis[to] = dis[now] + 1;
            q.push(to);
            if(to == n) return true;
        }
    }

    return false;

}

int dfs(int x, int mn){

    if(x == n) return mn;

    int sum = 0;

    for(int i = jump[x]; i; i = a[i].nxt){

        int to = a[i].to;

        if(dis[to] != dis[x] + 1 || !a[i].v) continue;

        int tmp = dfs(to, min(mn, a[i].v));

        sum += tmp;
        mn -= tmp;

        a[i].v -= tmp;
        a[i ^ 1].v += tmp;

        if(!mn) break;

    }

    if(!sum) dis[x] = 0;
    return sum;

}

int dinic(){

    int res = 0;

    while(bfs()){
        memcpy(jump, lst, sizeof lst);
        res += dfs(1, LLONG_MAX);
    }

    return res;

}

signed main(){

    cin >> n >> m >> sum;

    for(int i = 1; i <= m; i ++){
        cin >> x >> y >> v;
        add(x, y, v);
        add(y, x, 0);
    }

    int tmp = dinic();

    if(!tmp) cout << "Orz Ni Jinan Saint Cow!\n";
    else cout << tmp << ' ' << (sum - 1) / tmp + 1 << endl;

    return 0;
}

