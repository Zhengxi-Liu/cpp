/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e2 + 7;
struct str{
    int from, to, last;
}a[N];
int n, idx = 0, pre[N], cnt[N], x, y;
void add(int u, int v){
    a[++ idx].from = u;
    a[idx].to = v;
    a[idx].last = pre[u];
    pre[u] = idx;
    cnt[u] ++;
}
int main(){
    cin >> n;
    for(int i = 1;i < n;i ++){
        cin >> x >> y;
        add(x, y);
    }
    for(int i = 1;i <= n;i ++)
        cout << cnt[i] << ' ';
    cout << endl;
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e2 + 7;
int cnt[N], n, x, y;
int main(){
    cin >> n;
    for(int i = 1;i < n;i ++){
        cin >> x >> y;
        cnt[x] ++;cnt[y] ++;
    }
    cnt[1] ++;
    for(int i = 1;i <= n;i ++)
        cout << cnt[i] - 1 << ' ';
    cout << endl;
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
vector <int> a[N];
int n, c[N], maxn = -1e9, idx;
int main(){
    cin >> n;
    for(int i = 1;i <= n;i ++){
        cin >> c[i];
        int x;
        for(int j = 1;j <= c[i];j ++){
            cin >> x;
            a[i].push_back(x);
        }
    }
    for(int i = 1;i <= n;i ++){
        int cnt = 0;
        for(int j = 0;j < a[i].size();j ++)
            cnt += c[a[i][j]];
        if(cnt > maxn){
            idx = i;
            maxn = cnt;
        }
    }
    cout << idx << ' ' << maxn << endl;
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 7;
int b[N], n, x, y, ma = 0;
vector <int> a[N];
int main(){
    cin >> n;
    for(int i = 1;i < n;i ++){
        cin >> x >> y;
        b[y] = x;
        a[x].push_back(y);
        if(a[ma].size() < a[x].size() || a[ma].size() == a[x].size() && ma < x)
            ma = x;
    }
    for(int i = x;i;i = b[i])
        x = i;
    cout << x << endl << ma << endl;
    sort(a[ma].begin(), a[ma].end());
    for(int i = 0;i < a[ma].size();i ++)
        cout << a[ma][i] << ' ';
    cout << endl;
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e2 + 7;
vector <int> a[N];
int n, x, y;
int dfs(int p){
    if(!a[p].size())
        return 1;
    int ret;
    for(int i = 0;i < a[p].size();i ++)
        ret = max(ret, dfs(a[p][i]) + 1);
    return ret;
}
int main(){
    cin >> n;
    for(int i = 1;i < n;i ++){
        cin >> x >> y;
        a[x].push_back(y);
    }
    cout << dfs(1) << endl;
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e2 + 7;
int a[N][N], father[N], depth[N], n, x, y;
void dfs(int p, int f){
    father[p] = f;
    depth[p] = depth[f] + 1;
    for(int i = 1;i <= n;i ++)
        if(a[p][i] && i != f)
            dfs(i, p);
}
int main(){
    cin >> n;
    for(int i = 1;i < n;i ++){
        cin >> x >> y;
        a[x][y] = 1;
        a[y][x] = 1;
    }
    dfs(1, 0);
    for(int i = 2;i <= n;i ++)
        cout << i << ' ' << father[i] << ' ' << depth[i] << endl;
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e2 + 7;
vector <int> a[N];
int dep[N], si[N], n, x, y;
void dfs(int x, int f){
    //cout << x << ' ' << f << " // ";
    dep[x] = dep[f] + 1;
    si[x] += 1;
    for(int i = 0;i < a[x].size();i ++)
        if(a[x][i] != f){
            dfs(a[x][i], x);
            si[x] += si[a[x][i]];
        }
}
int main(){
    cin >> n;
    for(int i = 1;i < n;i ++){
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(1, 0);
    for(int i = 1;i <= n;i ++)
        cout << si[i] << ' ' << dep[i] << endl;
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 7;
int a[N], b[N], n, x, y;
int main(){
    cin >> n >> x >> y;
    for(int i = 1;i < n;i ++){
        int t1, t2;
        cin >> t1 >> t2;
        a[t1] = t2;
    }
    for(int i = x;i;i = a[i])
        b[i] = 1;
    for(int i = y;i;i = a[i])
        if(b[i]){
            cout << i << endl;
            break;
        }
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e2 + 7;
vector <int> a[N];
int n, x, y, ans = 0;
int dfs(int x, int f){
    int ret = 0;
    for(int i = 0;i < a[x].size();i ++)
        if(a[x][i] != f)
            ret = max(ret, dfs(a[x][i], x) + 1);
    return ret;
}
int main(){
    cin >> n;
    for(int i = 1;i < n;i ++){
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for(int i = 1;i <= n;i ++)
        ans = max(ans, dfs(i, 0));
    cout << ans << endl;
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
struct str{
    int x, y, last_edge;
}a[N];
int pre[N], fa[N], dep[N];
int n, idx = 0, u, v;
void add(int l, int r){
    idx ++;
    a[idx].x = l;
    a[idx].y = r;
    a[idx].last_edge = pre[l];x
    pre[l] = idx;
}
void dfs(int p, int f){
    fa[p] = f;
    dep[p] = dep[f] + 1;
    for(int i = pre[p];i;i = a[i].last_edge)
        if(a[i].y != f)
            dfs(a[i].y, p);
}
int main(){
    cin >> n;
    for(int i = 1;i < n;i ++){
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }
    dfs(1, 0);
    u = 1;
    for(int i = 2;i <= n;i ++)
        if(dep[i] > dep[u])
            u = i;
    dfs(u, 0);
    v = 1;
    for(int i = 2;i <= n;i ++)
        if(dep[i] > dep[v])
            v = i;
    int d = dep[v];
    //for(int i = 1;i <= n;i ++)
      //  cout << fa[i] << ' ';
    //cout << endl << v << ' ' << u << ' ' << d << ' ' << dep[u] << ' ' << dep[v] << endl;
    if(d % 2 != 0){
        for(int i = 1;i <= d / 2;i ++)
            v = fa[v];
        cout << v << endl;
    }
    else {
        for(int i = 1;i < d / 2;i ++)
            v = fa[v];
        if(v > fa[v])
            cout << fa[v] << ' ' << v << endl;
        else
            cout << v << ' ' << fa[v] << endl;
    }
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
struct str{
    int from, to, last_edge;
}a[N * 2];
int pre[N], si[N], r[N], fa[N];
int n, x, y, k = 0, minn = 1e9;
void add(int u, int v){
    k ++;
    a[k].from = u;
    a[k].to = v;
    a[k].last_edge = pre[u];
    pre[u] = k;
}
void dfs(int x, int f){
    si[x] = 1;
    fa[x] = f;
    for(int i = pre[x];i;i = a[i].last_edge)
        if(a[i].to != f){
            dfs(a[i].to, x);
            si[x] += si[a[i].to];
        }
}
int main(){
    cin >> n;
    for(int i = 1;i < n;i ++){
        cin >> x >> y;
        add(x, y);
        add(y, x);
    }
    dfs(1, 0);
    for(int i = 1;i <= n;i ++){
        r[i] = n - si[i];
        for(int j = pre[i];j;j = a[j].last_edge)
            if(a[j].to != fa[i])
                r[i] = max(r[i], si[a[j].to]);
        minn = min(minn, r[i]);
    }
    for(int i = 1;i <= n;i ++)
        if(r[i] == minn)
            cout << i << ' ';
    cout << endl;
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
int dsu[N], ans[N], n, m, idx = 0;
int find(int x){
    if(dsu[x] == x)
        return x;
    return dsu[x] = find(dsu[x]);
}
void merge(int x, int y){
    int a = find(x);
    int b = find(y);
    dsu[a] = b;
}
int main(){
    cin >> n >> m;
    for(int i = 1;i <= n;i ++)
        dsu[i] = i;
    for(int i = 1;i <= m;i ++){
        int x, y;
        cin >> x >> y;
        merge(x, y);
    }
    for(int i = 1;i <= n;i ++){
        if(find(i) == i)
            ans[++ idx] = i;
    }
    if(idx > 1){
        cout << idx - 1 << endl;
        for(int i = 1;i < idx;i ++)
            cout << ans[i] << ' ' << ans[i + 1] << endl;
    }
    else{
        cout << 0 << endl;
    }
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e2 + 7;
int l[N], r[N], n;
void dfs(int x){
    cout << x << ' ';
    if(l[x] != -1)
        dfs(l[x]);
    if(r[x] != -1)
        dfs(r[x]);
}
int main(){
    cin >> n;
    for(int i = 1;i <= n;i ++)
        cin >> l[i] >> r[i];
    dfs(1);
    cout << endl;
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
struct str{
    int to, last;
}a[N];
int pre[N], fa[N], dep[N];
int n, x, y, k = 0;
void add(int x, int y){
    k ++;
    a[k].to = y;
    a[k].last = pre[x];
    pre[x] = k;
}
void dfs(int x, int f){
    fa[x] = f;
    dep[x] = dep[f] + 1;
    for(int i = pre[x];i;i = a[i].last){
        if(a[i].to == f)
            continue;
        //cout << a[i].to << ' ';
        dfs(a[i].to, x);
    }
}
int main(){
    cin >> n;
    for(int i = 1;i < n;i ++){
        cin >> x >> y;
        add(x, y);
        add(y, x);
    }
    dfs(1, 0);
    int idx = 0, ans = 0;
    for(int i = 1;i <= n;i ++){
        if(dep[i] > dep[idx])
            idx = i;
        //cout << dep[i] << ' ';
    }
    dfs(idx, 0);
    for(int i = 1;i <= n;i ++)
        ans = max(ans, dep[i]);
    cout << ans - 1 << endl;
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
string s, t;
void bt_out(int l, int r, int len){
    if(len <= 0)
        return;
    int idx = t.find(s[l]) - r;
    bt_out(l + 1, r, idx);
    bt_out(l + idx + 1, r + idx + 1, len - idx - 1);
    cout << s[l];
}
int main(){
    while(cin >> s >> t){
        bt_out(0, 0, s.size());
        cout << endl;
    }
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
struct str{
    int to, last;
}a[N];
int pre[N], fa[N], dep[N], d[N];
int n, x, y, k = 0;
void add(int x, int y){
    k ++;
    a[k].to = y;
    a[k].last = pre[x];
    pre[x] = k;
}
void dfs(int x, int f){
    fa[x] = f;
    dep[x] = dep[f] + 1;
    d[x] = max(d[x], dep[x]);
    for(int i = pre[x];i;i = a[i].last){
        if(a[i].to == f)
            continue;
        dfs(a[i].to, x);
    }
}
int main(){
    cin >> n;
    for(int i = 1;i < n;i ++){
        cin >> x >> y;
        add(x, y);
        add(y, x);
    }
    dfs(1, 0);
    int ma = 0;
    for(int i = 1;i <= n;i ++)
        if(dep[i] > dep[ma])
            ma = i;
    dfs(ma, 0);
    for(int i = 1;i <= n;i ++)
        if(dep[i] > dep[ma])
            ma = i;
    dfs(ma, 0);
    for(int i = 1;i <= n;i ++)
        cout << d[i] - 1 << ' ';
    cout << endl;
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 7;
int a[N], n;
void dfs(int x){
    if(x * 2 <= n && a[x * 2])
        dfs(x * 2);
   	if(x * 2 + 1 <= n && a[x * 2 + 1])
        dfs(x * 2 + 1);
    cout << a[x] << ' ';
}
int main(){
    cin >> n;
    for(int i = 1;i <= n;i ++){
        cin >> a[i];
    }
    cout << (int)log2(n) + 1 << endl;
    dfs(1);
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 7;
string s, t;
int n;
void dfs(int l1, int r1, int l2, int r2){
    int mid = t.find(s[l1]);
    if(mid != l2)
        dfs(l1 + 1,l1 + mid - 1, l2, mid - 1);
    if(mid != r2)
        dfs(l1 + mid - l2 + 1, r1, mid + 1, r2);
    cout << s[l1];
}
int main(){
    cin >> s >> t;
    n = s.size();
    s = " " + s;
    t = " " + t;
    dfs(1, n, 1, n);
    cout << endl;
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
int n, k;
int main(){
    while(cin >> n){
        if(!n)
            break;
        cin >> k;
        int t = pow(2, k - 1), s = t * 2 - 1;
        if(t > n)
            cout << "EMPTY" << endl;
        else {
            for(int i = t;i <= min(n, s);i ++)
                cout << i << ' ';
            cout << endl;
        }
    }
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 7;
int n, m, ans, cnt = 0;
int main(){
    cin >> m >> n;
    for(int i = m;i <= n;i = i * 2 + 1)
        cnt ++;
    ans = pow(2, cnt) - 1;
    int t = m * pow(2, cnt);
    if(t <= n)
        ans += n - t + 1;
    cout << ans << endl;
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
priority_queue <int, vector <int>, greater <int> > q;
int n, x, ans = 0;
int main(){
    cin >> n;
    while(n --){
        cin >> x;
        q.push(x);
    }
    while(!q.empty()){
        int t = q.top();
        q.pop();
        if(q.empty())
            break;
        t += q.top();
        q.pop();
        ans += t;
        q.push(t);
    }
    cout << ans << endl;
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
struct str{
    int v, l, r;
}a[N];
int n;
void insert(int x, int p){
    if(a[p].v > a[x].v){
        if(!a[p].l)
            a[p].l = x;
        else
            insert(x, a[p].l);
    }
    else {
        if(!a[p].r)
            a[p].r = x;
        else
            insert(x, a[p].r);
    }
}
void midd(int x){
    if(a[x].l)
        midd(a[x].l);
    cout << a[x].v << ' ';
    if(a[x].r)
        midd(a[x].r);
}
void last(int x){
    if(a[x].l)
        last(a[x].l);
    if(a[x].r)
        last(a[x].r);
    cout << a[x].v << ' ';
}
int main(){
    cin >> n;
    for(int i = 1;i <= n;i ++){
        cin >> a[i].v;
        if(i == 1)
            continue;
        insert(i, 1);
    }
    midd(1);
    cout << endl;
    last(1);
    cout << endl;
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 7;
int l[N], r[N], n;
void dfs(int x){
    if(l[x] != -1)
        dfs(l[x]);
    cout << x << ' ';
    if(r[x] != -1)
        dfs(r[x]);
}
int main(){
    cin >> n;
    for(int i = 1;i <= n;i ++)
        cin >> l[i] >> r[i];
    dfs(1);
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 5e2 + 7;
struct str{
    int v, l, r, f;
}a[N];
int n, s, t, k = 0, ra[N], st = 1;
void insert(int x, int p){
    if(a[x].v <= a[p].v){
        if(!a[p].l){
            a[p].l = x;
            a[x].f = p;
        }
        else
            insert(x, a[p].l);
    }
    else {
        if(!a[p].r){
            a[p].r = x;
            a[x].f = p;
        }
        else
            insert(x, a[p].r);
    }
}
int find(int x, int p){
    if(a[p].r && a[p].v < x)
        return find(x, a[p].r);
    if(a[p].l && a[p].v > x)
        return find(x, a[p].l);
    if(a[p].v == x)
        return p;
    return 0;
}
int rm(int p){
    if(a[p].r)
        return rm(a[p].r);
    return p;
}
void delet(int x){
    int id = find(x, st), fa = a[id].f;
    if(!id)
        return ;
    //cout << id << ' ';
    if(a[id].l && a[id].r){
        int r = rm(a[id].l);
        a[r].r = a[id].r;
        a[a[id].r].f = r;
        if(a[fa].l == id){
            a[fa].l = a[id].l;
            a[a[id].l].f = fa;
        }
        else {
            a[fa].r = a[id].l;
            a[a[id].l].f = fa;
        }
        if(id == st)
            st = a[id].l;
    }
    else if(a[id].l){
        if(a[fa].l == id){
            a[fa].l = a[id].l;
            a[a[id].l].f = fa;
        }
        else {
            a[fa].r = a[id].l;
            a[a[id].l].f = fa;
        }
        if(id == st)
            st = a[id].l;
    }
    else if(a[id].r){
        if(a[fa].l == id){
            a[fa].l = a[id].r;
            a[a[id].r].f = fa;
        }
        else {
            a[fa].r = a[id].r;
            a[a[id].r].f = fa;
        }
        if(id == st)
            st = a[id].r;
    }
    else {
        if(a[fa].l == id){
            a[fa].l = 0;
        }
        else {
            a[fa].r = 0;
        }
        if(id == st)
            st = k + 1;
    }
}
int ran(int x, int p){
    int ret = 0;
    if(a[p].v <= x)
        ret += 1;
    if(a[p].l)
        ret += ran(x, a[p].l);
    if(a[p].r)
        ret += ran(x, a[p].r);
    return ret;
}
int ran2(int x, int p){
    int ret = 1e9, t;
    if(ran(a[p].v, 1) == x)
        ret = a[p].v;
    if(a[p].l){
        t = ran2(x, a[p].l);
        if(t)
            ret = min(ret, t);
    }
    if(a[p].r){
        t = ran2(x, a[p].r);
        if(t)
            ret = min(ret, t);
    }
    return ret;
}
int le(int x, int p){
    int ret = 0;
    if(a[p].l)
        ret = max(ret, le(x, a[p].l));
    if(a[p].r)
        ret = max(ret, le(x, a[p].r));
    if(a[p].v < x)
        ret = max(ret, a[p].v);
    return ret;
}
int ge(int x, int p){
    int ret = 1e9;
    if(a[p].l)
        ret = min(ret, ge(x, a[p].l));
    if(a[p].r)
        ret = min(ret, ge(x, a[p].r));
    if(a[p].v > x)
        ret = min(ret, a[p].v);
    return ret;
}
int main(){
    cin >> n;
    while(n --){
        cin >> s >> t;
        if(s == 1){
            a[++ k].v = t;
            if(k == st)
                continue;
            insert(k, st);
        }
        if(s == 2)
            delet(t);
        if(s == 3)
            cout << ran(t, st) << endl;
        if(s == 4)
            cout << ran2(t, st) << endl;
        if(s == 5)
            cout << le(t, st) << endl;
        if(s == 6)
            cout << ge(t, st) << endl;
    }
    return 0;
}*/
