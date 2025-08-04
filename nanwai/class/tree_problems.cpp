//A. Meet 紧急集合
/*#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 7;

vector <int> a[N];

int son[N], sz[N], top[N], dep[N], fa[N];

int n, m, x, y, z;

void dfs1(int x, int f){
    sz[x] = 1, dep[x] = dep[f] + 1, fa[x] = f;
    for(int to : a[x]){
        if(to == f) continue;
        dfs1(to, x);
        sz[x] += sz[to];
        if(sz[son[x]] < sz[to]) son[x] = to;
    }    
}

void dfs2(int x, int tp){
    top[x] = tp;
    if(!son[x]) return;
    dfs2(son[x], tp);
    for(int to : a[x]){
        if(to == fa[x] || son[x] == to) continue;
        dfs2(to, to);
    }
}

int LCA(int x, int y){
    while(top[x] != top[y]){
        if(dep[top[x]] < dep[top[y]]) swap(x, y);
        x = fa[top[x]];
    }
    return dep[x] < dep[y] ? x : y;
}

int main(){

    scanf("%d %d", &n, &m);

    for(int i = 1; i < n; i ++){
        scanf("%d %d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }

    dfs1(1, 0);

    dfs2(1, 1);

    while(m --){

        scanf("%d %d %d", &x, &y, &z);

        int a1 = LCA(x, y), a2 = LCA(x, z), a3 = LCA(y, z), ans;

        if(a1 == a2) ans = a3;
        if(a2 == a3) ans = a1;
        if(a1 == a3) ans = a2;
        
        printf("%d %d\n", ans, dep[x] + dep[y] + dep[z] - dep[a1] - dep[a2] - dep[a3]);

    }

    return 0;
}*/

//B. 松鼠的新家
/*#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 7;

vector <int> a[N];

int son[N], fa[N], sz[N], top[N], dep[N];

void dfs1(int x, int f){
    sz[x] = 1, fa[x] = f, dep[x] = dep[f] + 1;
    for(int to : a[x]){
        if(to == f) continue;
        dfs1(to, x);
        sz[x] += sz[to];
        if(sz[son[x]] < sz[to]) son[x] = to;
    }
}

void dfs2(int x, int id){
    top[x] = id;
    if(!son[x]) return;
    dfs2(son[x], id);
    for(int to : a[x]){
        if(to == fa[x] || to == son[x]) continue;
        dfs2(to, to);
    }
}

int LCA(int x, int y){
    while(top[x] != top[y]){
        if(dep[top[x]] < dep[top[y]]) swap(x, y);
        x = fa[top[x]];
    }
    return dep[x] < dep[y] ? x : y;
}

int n, x, y, vs[N], d[N];

void dif(int x){
    for(int to : a[x]){
        if(to == fa[x]) continue;
        dif(to);
        d[x] += d[to];
    }
}

int main(){

    cin >> n;

    for(int i = 1; i <= n; i ++)
        cin >> vs[i];

    for(int i = 1; i < n; i ++){
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }

    dfs1(1, 0);
    dfs2(1, 1);

    for(int i = 2; i <= n; i ++){
        int tmp = LCA(vs[i - 1], vs[i]);
        d[vs[i - 1]] ++;
        d[vs[i]] ++;
        d[tmp] --;
        d[fa[tmp]] --;
    }

    dif(1);

    d[vs[1]] ++;
    for(int i = 1; i <= n; i ++)
        cout << d[i] - 1 << endl;

    return 0;
}*/

//C. 货车运输
/*#include<bits/stdc++.h>
using namespace std;

const int N = 5e4 + 7;

struct str{
    int x, y, v;
}a[N];

bool cmp(str a, str b){
    return a.v > b.v;
}

set <int> st[N];

int dsu[N], ans[N];

int n, m, q, x, y, v;

int find(int x){
    return dsu[x] == x ? x : dsu[x] = find(dsu[x]);
}

int main(){

    cin >> n >> m;

    for(int i = 1; i <= m; i ++)
        cin >> a[i].x >> a[i].y >> a[i].v;

    sort(a + 1, a + m + 1, cmp);

    for(int i = 1; i <= n; i ++)
        dsu[i] = i;

    cin >> q;

    for(int i = 1; i <= q; i ++){
        cin >> x >> y;
        st[x].insert(i);
        st[y].insert(i);
        ans[i] = -1;
    }

    for(int i = 1; i <= m; i ++){
        int s = find(a[i].x), t = find(a[i].y);
        if(s == t) continue;
        if(st[s].size() < st[t].size()) swap(st[s], st[t]); // s is the bigger set
        for(int j : st[t]){
            if(st[s].count(j)){
                ans[j] = a[i].v;
                st[s].erase(j);
            }
            else
                st[s].insert(j);
        }
        st[t].clear();
        dsu[t] = s;
    }

    for(int i = 1; i <= q; i ++)
        cout << ans[i] << endl;

    return 0;
}*/

//D. 奶牛政坛
/*#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;

int dep[N], fa[N], son[N], sz[N], top[N];

vector <int> a[N], b[N];

void dfs1(int x){
    sz[x] = 1, dep[x] = dep[fa[x]] + 1;
    for(int to : a[x]){
        if(to == fa[x]) continue;
        dfs1(to);
        sz[x] += sz[to];
        if(sz[to] > sz[son[x]]) son[x] = to;
    }
}

void dfs2(int x, int id){
    top[x] = id;
    if(!son[x]) return;
    dfs2(son[x], id);
    for(int to : a[x]){
        if(to == fa[x] || to == son[x]) continue;
        dfs2(to, to);
    }
}

int LCA(int x, int y){
    int t1 = x, t2 = y;
    while(top[x] != top[y]){
        if(dep[top[x]] < dep[top[y]]) swap(x, y);
        x = fa[top[x]];
    }
    int res = dep[x] < dep[y] ? x : y;
    return dep[t1] + dep[t2] - (dep[res] << 1);
}

int n, m, rt, x;

int main(){

    cin >> n >> m;

    for(int i = 1; i <= n; i ++){
        cin >> x >> fa[i];
        a[fa[i]].push_back(i);
        if(!fa[i]) rt = i;
        b[x].push_back(i);
    }

    dfs1(rt);

    dfs2(rt, rt);

    for(int i = 1; i <= m; i ++){
        int mx = 0, ans = 0;
        for(int ele : b[i])
            if(dep[ele] > dep[mx]) mx = ele;
        for(int ele : b[i])
            ans = max(ans, LCA(ele, mx));
        cout << ans << endl;
    }

    return 0;
}*/

//F. 选课加强版
/*#include<bits/stdc++.h>
using namespace std;

const int N = 5e3 + 7;

int dp[N][N], sz[N];

vector <int> a[N];

int n, m, x, s[N];

void dfs(int x, int fa){

    dp[x][1] = s[x];
    sz[x] = 1;
    
    for(int to : a[x]){
        if(to == fa) continue;
        dfs(to, x);
        sz[x] += sz[to];
        for(int j = min(sz[x], m); j >= 2; j --)
            for(int k = 1; k <= min({sz[to], j - 1, m}); k ++)
                dp[x][j] = max(dp[x][j], dp[x][j - k] + dp[to][k]);
    }

}


int main(){

    cin >> n >> m;

    m ++;

    for(int i = 1; i <= n; i ++){
        cin >> x >> s[i];
        a[x].push_back(i);
    }

    dfs(0, 0);

    cout << dp[0][m] << endl;

    return 0;
}*/

//G. 旅游
/*#include<bits/stdc++.h>
using namespace std;

#define mid ((l + r) >> 1)
#define kl k << 1
#define kr (k << 1) | 1

const int N = 5e4 + 7;

vector <int> a[N];

int sz[N], fa[N], son[N], dep[N];

int top[N], dfn[N], cor[N], cnt;

int s[N], n, q, x, y, v;

void dfs1(int x, int f){
    sz[x] = 1, fa[x] = f, dep[x] = dep[f] + 1;
    for(int to : a[x]){
        if(to == f) continue;
        dfs1(to, x);
        sz[x] += sz[to];
        if(sz[to] > sz[son[x]]) son[x] = to;
    }
}

void dfs2(int x, int id){
    top[x] = id, dfn[x] = ++ cnt, cor[cnt] = x;
    if(!son[x]) return;
    dfs2(son[x], id);
    for(int to : a[x]){
        if(to == fa[x] || to == son[x]) continue;
        dfs2(to, to);
    }
}

struct node{
    int mx = -1e9, mn = 1e9, lr = 0, rl = 0, add = 0;
    void tag(int v){
        mx += v;
        mn += v;
        add += v;
    }
}T[N << 2];

void push_up(int k){
    T[k].mx = max(T[kl].mx, T[kr].mx);
    T[k].mn = min(T[kl].mn, T[kr].mn);
    T[k].lr = max({T[kr].mx - T[kl].mn, T[kl].lr, T[kr].lr});
    T[k].rl = max({T[kl].mx - T[kr].mn, T[kl].rl, T[kr].rl});
}

void build(int k, int l, int r){
    if(l == r){
        T[k] = {s[cor[l]], s[cor[l]], 0, 0, 0};
        return;
    }
    build(kl, l, mid);
    build(kr, mid + 1, r);
    push_up(k);
}

void push_down(int k){
    if(!T[k].add) return;
    T[kl].tag(T[k].add);
    T[kr].tag(T[k].add);
    T[k].add = 0;
}

void upd(int k, int l, int r, int x, int y, int v){
    if(l >= x && r <= y){
        T[k].tag(v);
        return;
    }
    push_down(k);
    if(mid >= x) upd(kl, l, mid, x, y, v);
    if(mid < y) upd(kr, mid + 1, r, x, y, v);
    push_up(k);
}

node qry(int k, int l, int r, int x, int y){
    if(l >= x && r <= y) return T[k];
    push_down(k);
    node ll, rr, res;
    ll.mx = rr.mx = -1;
    if(mid >= x) ll = qry(kl, l, mid, x, y);
    if(mid < y) rr = qry(kr, mid + 1, r, x, y);
    if(ll.mx == -1) return rr;
    if(rr.mx == -1) return ll;
    res.mx = max(ll.mx, rr.mx), res.mn = min(ll.mn, rr.mn);
    res.lr = max({ll.lr, rr.lr, rr.mx - ll.mn});
    res.rl = max({ll.rl, rr.rl, ll.mx - rr.mn});
    return res;
}

void work(node &res, node val, int op){
    res.lr = max(res.lr, val.lr);
    res.rl = max(res.rl, val.rl);
    if(op == 1) res.lr = max(res.lr, res.mx - val.mn);
    else res.rl = max(res.rl, val.mx - res.mn);
    res.mx = max(val.mx, res.mx), res.mn = min(val.mn, res.mn);
}

int cal(int x, int y, int v){
    int op = 0;
    node res[2];
    while(top[x] != top[y]){
        if(dep[top[x]] < dep[top[y]]) swap(x, y), op ^= 1;
        int tmp = top[x];
        upd(1, 1, n, dfn[tmp], dfn[x], v);
        node val = qry(1, 1, n, dfn[tmp], dfn[x]);
        work(res[op], val, op);
        x = fa[tmp];
    }
    if(dep[x] > dep[y]) swap(x, y), op ^= 1;
    upd(1, 1, n, dfn[x], dfn[y], v);
    node val = qry(1, 1, n, dfn[x], dfn[y]);
    work(res[op ^ 1], val, op ^ 1);
    return max({res[0].rl, res[1].lr, res[1].mx - res[0].mn});
}

int main(){

    cin >> n;

    for(int i = 1; i <= n; i ++)
        cin >> s[i];

    for(int i = 1; i < n; i ++){
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }

    dfs1(1, 0);
    dfs2(1, 1);
    build(1, 1, n);

    cin >> q;

    while(q --){
        cin >> x >> y >> v;
        cout << cal(x, y, v) << endl;
    }

    return 0;
}*/


//I. 遥远的国度
