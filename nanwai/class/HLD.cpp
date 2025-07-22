// P3379 【模板】最近公共祖先（LCA）
// https://www.luogu.com.cn/problem/P3379
/*#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 7;

int son[N], fa[N], dep[N], top[N], sz[N];

vector <int> a[N];

int n, q, r, x, y;

void dfs1(int x, int f){
    fa[x] = f; dep[x] = dep[f] + 1, sz[x] = 1;
    for(int to : a[x]){
        if(to == f) continue;
        dfs1(to, x);
        sz[x] += sz[to];
        if(sz[son[x]] < sz[to]) son[x] = to; // 求重儿子
    }
}

void dfs2(int x, int id){
    top[x] = id;
    if(!son[x]) return; // 找到叶子结点
    dfs2(son[x], id); // 标记重儿子
    for(int to : a[x]){
        if(to == fa[x] || to == son[x]) continue;
        dfs2(to, to);
    }
}

int lca(int x, int y){
    while(top[x] != top[y]){
        if(dep[top[x]] < dep[top[y]]) swap(x, y);
        x = fa[top[x]];
    }
    return dep[x] < dep[y] ? x : y;
}

int main(){

    cin >> n >> q >> r;

    for(int i = 1; i < n; i ++){
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }

    dfs1(r, 0);
    dfs2(r, r);

    while(q --){
        cin >> x >> y;
        cout << lca(x, y) << endl;
    }

    return 0;
}*/

// P3384 【模板】重链剖分/树链剖分
// https://www.luogu.com.cn/problem/P3384
/*#include<bits/stdc++.h>
using namespace std;

#define int long long

#define mid ((l + r) >> 1)

const int N = 1e5 + 10;

int fa[N], son[N], sz[N], dep[N];
int id[N], top[N], nv[N], v[N];

int sum[N * 4], add[N * 4];

vector <int> a[N];

int n, q, r, MOD, cnt, x, y, z, op;

void dfs1(int x, int f){
    fa[x] = f, sz[x] = 1, dep[x] = dep[f] + 1;
    for(int to : a[x]){
        if(to == f) continue;
        dfs1(to, x);
        sz[x] += sz[to];
        if(sz[to] > sz[son[x]]) son[x] = to;
    }
}

void dfs2(int x, int t){
    top[x] = t, id[x] = ++ cnt, nv[cnt] = v[x];
    if(!son[x]) return;
    dfs2(son[x], t);
    for(int to : a[x]){
        if(to == fa[x] || son[x] == to) continue;
        dfs2(to, to);
    }
}

void push_up(int k){
    sum[k] = (sum[k * 2] + sum[k * 2 + 1]) % MOD;
}

void build(int k, int l, int r){
    if(l == r){
        sum[k] = nv[l];
        return;
    }
    build(k * 2, l, mid);
    build(k * 2 + 1, mid + 1, r);
    push_up(k);
}

void change(int k, int l, int r, int v){
    sum[k] += (r - l + 1) * v, sum[k] %= MOD;
    add[k] += v, add[k] %= MOD;
}

void push_down(int k, int l, int r){
    if(!add[k]) return;
    change(k * 2, l, mid, add[k]);
    change(k * 2 + 1, mid + 1, r, add[k]);
    add[k] = 0;
}

void update(int k, int l, int r, int x, int y, int v){
    if(l >= x && r <= y){
        change(k, l, r, v);
        return;
    }
    push_down(k, l, r);
    if(mid >= x) update(k * 2, l, mid, x, y, v);
    if(mid + 1 <= y) update(k * 2 + 1, mid + 1, r, x, y, v);
    push_up(k);
}

int query(int k, int l, int r, int x, int y){
    if(l >= x && r <= y) return sum[k];
    push_down(k, l, r);
    int res = 0;
    if(mid >= x) res += query(k * 2, l, mid, x, y);
    if(mid + 1 <= y) res += query(k * 2 + 1, mid + 1, r, x, y);
    return res % MOD;
}

void upd_path(int x, int y, int v){
    while(top[x] != top[y]){
        if(dep[top[x]] < dep[top[y]]) swap(x, y);
        update(1, 1, n, id[top[x]], id[x], v);
        x = fa[top[x]];
    }
    if(dep[x] < dep[y]) swap(x, y);
    update(1, 1, n, id[y], id[x], v);
}

int qry_path(int x, int y){
    int res = 0;
    while(top[x] != top[y]){
        if(dep[top[x]] < dep[top[y]]) swap(x, y);
        res += query(1, 1, n, id[top[x]], id[x]), res %= MOD;
        x = fa[top[x]];
    }
    if(dep[x] < dep[y]) swap(x, y);
    res += query(1, 1, n, id[y], id[x]), res %= MOD;
    return res;
}

void upd_tree(int x, int v){
    update(1, 1, n, id[x], id[x] + sz[x] - 1, v);
}

int qry_tree(int x){
    return query(1, 1, n, id[x], id[x] + sz[x] - 1);
}

signed main(){

    cin >> n >> q >> r >> MOD;

    for(int i = 1; i <= n; i ++)
        cin >> v[i];

    for(int i = 1; i < n; i ++){
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }

    dfs1(r, 0);
    dfs2(r, r);

    build(1, 1, n);

    while(q --){
        
        cin >> op >> x;
   
        if(op == 1){
            cin >> y >> z;
            upd_path(x, y, z);
        }
        if(op == 2){
            cin >> y;
            cout << qry_path(x, y) % MOD << endl;
        }
        if(op == 3){
            cin >> z;
            upd_tree(x, z);
        }
        if(op == 4)
            cout << qry_tree(x) % MOD << endl;
    }

    return 0;
}*/

//CF1009F Dominant Indices
//https://www.luogu.com.cn/problem/CF1009F
/*#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;

vector <int> a[N];

int son[N], len[N];

int buf[N], *f[N], *p = buf, ans[N];

int n, x, y;

void dfs(int x, int fa){
    for(int to : a[x]){
        if(to == fa) continue;
        dfs(to, x);
        if(len[son[x]] < len[to]) son[x] = to;
    }
    len[x] = len[son[x]] + 1;
}

void DP(int x, int fa){

    f[x][0] = 1; //自己

    if(son[x]){
        f[son[x]] = f[x] + 1; // 共享内存
        DP(son[x], x);
        ans[x] = ans[son[x]] + 1; // 继承答案
    }

    for(int to : a[x]){
        if(to == fa || to == son[x])
            continue;
        f[to] = p; p += len[to];
        DP(to, x);
        for(int i = 1; i <= len[to]; i ++){
            f[x][i] += f[to][i - 1];
            if(f[x][i] > f[x][ans[x]] || f[x][i] == f[x][ans[x]] && i < ans[x])
                ans[x] = i;
        }
    }

    if(f[x][ans[x]] == 1) ans[x] = 0;

}

int main(){

    scanf("%d", &n);

    for(int i = 1; i < n; i ++){
        scanf("%d %d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }

    dfs(1, 0);

    f[1] = p; p += len[1];

    DP(1, 0);

    for(int i = 1; i <= n; i ++)
        printf("%d\n", ans[i]);

    return 0;
}*/

