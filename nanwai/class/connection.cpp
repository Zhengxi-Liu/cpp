//B. Going from u to v or from v to u?
/*#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;

vector <int> a[N], b[N];

int dfn[N], low[N], clk;

int in[N], id[N];

bool f[N];

stack <int> st;

int n, m, t, x, y, cnt;

void dfs(int x){

    dfn[x] = low[x] = ++ clk;
    f[x] = true;
    st.push(x);

    for(int to : a[x]){
        if(!dfn[to]){
            dfs(to);
            low[x] = min(low[x], low[to]);
        }
        else if(f[to])
            low[x] = min(low[x], dfn[to]);
    }

    if(low[x] == dfn[x]){
        cnt ++;
        int tp;
        do {
            tp = st.top();
            f[tp] = false;
            id[tp] = cnt;
            st.pop();
        } while(tp != x);
    }

}

typedef pair <int, int> PI;

bool check(){

    int bg = 0, tot = 0;
    for(int i = 1; i <= cnt; i ++)
        if(!in[i]) bg = i;
    
    queue <PI> q;
    q.push({bg, 1});
    while(!q.empty()){
        PI now = q.front();
        q.pop();
        tot = max(tot, now.second);
        for(int to : b[now.first]){
            in[to] --;
            if(!in[to]) q.push({to, now.second + 1});
        }
    }
    return tot == cnt;
}


int main(){

    cin >> t;

    while(t --){

        cin >> n >> m;

        while(!st.empty()) st.pop();
        for(int i = 1; i <= n; i ++){
            f[i] = dfn[i] = low[i] = id[i] = in[i] = 0;
            a[i].clear();
            b[i].clear();
        }
        cnt = 0, clk = 0;

        for(int i = 1; i <= m; i ++){
            cin >> x >> y;
            a[x].push_back(y);
        }

        for(int i = 1; i <= n; i ++)
            if(!dfn[i]) dfs(i);

        for(int i = 1; i <= n; i ++){
            for(int to : a[i]){
                if(id[to] != id[i]){
                    in[id[to]] ++;
                    b[id[i]].push_back(id[to]);
                }
            }
        }
        
        cout << (check() ? "Yes" : "No") << endl;

    }

    return 0;
}*/

//C. 自行车道 Bike paths
/*#include<bits/stdc++.h>
using namespace std;

const int N = 5e4 + 7;

vector <int> a[N], b[N];

int dfn[N], low[N], clk;

int sz[N], id[N], cnt;

bool f[N];

stack <int> st;

int n, m, x, y, in[N], ans[N];

void dfs(int x){

    dfn[x] = low[x] = ++ clk;
    f[x] = true;
    st.push(x);

    for(int to : a[x]){
        if(!dfn[to]){
            dfs(to);
            low[x] = min(low[x], low[to]);
        }
        else if(f[to])
            low[x] = min(low[x], dfn[to]);
    }

    if(low[x] == dfn[x]){
        int tp;
        cnt ++;
        do {
            tp = st.top();
            st.pop();
            f[tp] = false;
            sz[cnt] ++;
            id[tp] = cnt;
        } while(tp != x);
    }

}


int main(){

    cin >> n >> m;

    for(int i = 1; i <= m; i ++){
        cin >> x >> y;
        a[x].push_back(y);
    }

    for(int i = 1; i <= n; i ++)
        if(!dfn[i]) dfs(i);

    for(int i = 1; i <= n; i ++)
        for(int to : a[i]){
            if(id[i] == id[to]) continue;
            in[id[i]] ++;
            b[id[to]].push_back(id[i]);
        }
    
    queue <int> q;

    for(int i = 1; i <= cnt; i ++)
        if(!in[i]) q.push(i);

    while(!q.empty()){

        int now = q.front();
        q.pop();
        ans[now] += sz[now];

        for(int to : b[now]){
            ans[to] += ans[now];
            in[to] --;
            if(!in[to]) q.push(to);
        }

    }

    for(int i = 1; i <= n; i ++)
        cout << ans[id[i]] - 1 << endl;

    return 0;
}*/

//D. [BZOJ2140]稳定婚姻
/*#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

vector <int> a[N];

int dfn[N], low[N], clk;

int id[N], cnt;

bool f[N];

stack <int> st;

int n, m, tot;

void dfs(int x){

    dfn[x] = low[x] = ++ clk;
    f[x] = true;
    st.push(x);

    for(int to : a[x]){
        if(!dfn[to]){
            dfs(to);
            low[x] = min(low[x], low[to]);
        }
        else if(f[to])
            low[x] = min(low[x], dfn[to]);
    }

    if(low[x] == dfn[x]){
        int tp;
        cnt ++;
        do {
            tp = st.top();
            st.pop();
            f[tp] = false;
            id[tp] = cnt;
        } while(tp != x);
    }

}

map <string, int> mp;

string x, y, s[N], t[N];

int main(){

    cin >> n;

    for(int i = 1; i <= n; i ++){
        cin >> x >> y;
        if(!mp.count(x)) mp[x] = ++ tot;
        if(!mp.count(y)) mp[y] = ++ tot;
        a[mp[y]].push_back(mp[x]);
        s[i] = x, t[i] = y;
    }

    cin >> m;

    for(int i = 1; i <= m; i ++){
        cin >> x >> y;
        a[mp[x]].push_back(mp[y]);
    }

    for(int i = 1; i <= tot; i ++)
        if(!dfn[i]) dfs(i);

    for(int i = 1; i <= n; i ++){
        if(id[mp[s[i]]] == id[mp[t[i]]]) cout << "Unsafe" << endl;
        else cout << "Safe" << endl;
    }

    return 0;
}*/

//F. 通讯网破坏
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

vector <int> a[N], b[N];

map <int, int> mp[N];

int dfn[N], low[N], clk;

int id[N], mk[N], cnt;

int n, m, q, x, y, z;

stack <int> st;

void tarjan(int x){

    dfn[x] = low[x] = ++ clk;
    st.push(x);
    int son = 0;

    for(int to : a[x]){
        if(!dfn[to]){
            tarjan(to);
            low[x] = min(low[x], low[to]);
            son ++;
            if(low[to] >= dfn[x]){
                mk[x] = 1;
                int tp;
                do {
                    tp = st.top();
                    mp[x][tp] = 1;
                    st.pop();
                } while(tp != to);
            }
        }
        else low[x] = min(low[x], dfn[to]);
    }
    if(x == 1 && son < 2){
        mk[x] = 0;
        mp[x].clear();
    }

}

void dfs(int x){
    id[x] = cnt;
    for(int to : a[x]){
        if(mk[x]){
            //cout << to << ": " << mp[x].count(to) << ' ' << id[to] << " / ";
            if(!mp[x].count(to) && !id[to]) 
                dfs(to);
        }
        else if(!id[to]) dfs(to);
    }
}

int sz[N], dep[N], son[N], top[N], fa[N];

bool vis[N];

void dfs1(int x, int f){
    vis[x] = true, sz[x] = 1, dep[x] = dep[f] + 1, fa[x] = f;
    //cout << x << ": ";
    for(int to : b[x]){
        //cout << to << " ";
        if(vis[to] || to == f) continue;
        //cout << "*";
        dfs1(to, x);
        sz[x] += sz[to];
        if(sz[to] > sz[son[x]]) son[x] = to;
    }
    //cout << endl;
}

void dfs2(int x, int tp){
    vis[x] = true, top[x] = tp;
    if(!son[x]) return;
    dfs2(son[x], tp);
    for(int to : b[x]){
        if(to == fa[x] || to == son[x] || vis[to]) continue;
        dfs2(to, to);
    }
}

int LCA(int x, int y){
    int res = 0;
    while(top[x] != top[y]){
        if(dep[x] < dep[y]) swap(x, y);
        res += dep[x] - dep[top[x]];
        x = fa[top[x]];
    }
    if(dep[x] > dep[y]) swap(x, y);
    res += dep[y] - dep[x];
    return res;
}

int main(){

    cin >> n >> m;

    for(int i = 1; i <= m; i ++){
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }

    tarjan(1);

    for(int i = 1; i <= n; i ++)
        if(!id[i]){
            cnt ++;
            dfs(i);
        }
    //cout << endl;
    for(int i = 1; i <= n; i ++){
        //cout << id[i] << ' ' << mk[i] << " / ";
        for(int to : a[i]){
            if(id[to] == id[i]) continue;
            b[id[i]].push_back(id[to]);
            b[id[to]].push_back(id[i]);
        }
    }
    //cout << endl;

    dfs1(1, 0);

    memset(vis, 0, sizeof(vis));

    dfs2(1, 1);

    cin >> q;

    while(q --){
        
        cin >> x >> y >> z;
        
        if(id[x] == id[y] || !mk[z]){
            cout << "no" << endl;
            continue;
        }
        
        int ss = LCA(id[x], id[y]), t1 = LCA(id[x], id[z]), t2 = LCA(id[y], id[z]);
        // cout << id[x] << ' ' << id[y] << ' ' << id[z] << endl;
        // cout << ss << ' ' << t1 << ' ' << t2 << endl;
        if(ss == t1 + t2) cout << "yes" << endl;
        else cout << "no" << endl;
        
    }

    return 0;
}