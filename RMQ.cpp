/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7, L = 20 + 7;
int st[N][L], lg[N], a[N], n, m;
#define FASTIO cin.tie(0), cout.tie(0);
#define read scanf("%d", &a[i]);
#define print printf("%d\n", max(st[l][k], st[r - (1 << k) + 1][k]));
int main(){
    cin >> n >> m;
    for(int i = 1;i <= n;i ++)
        read;
    lg[1] = 0;
    for(int i = 2;i <= n;i ++)
        lg[i] = lg[i / 2] + 1;
    for(int j = 0;j < L;j ++)
        for(int i = 1;i + (1 << j) - 1 <= n;i ++){
            if(j == 0)
                st[i][j] = a[i];
            else
                st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    int l, r, k;
    while(m --){
        cin >> l >> r;
        k = lg[r - l + 1];
        print
    }
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7, L = 20 + 7;
struct node{
    int to, last;
}a[N];
int pre[N], st[N][L], lg[N], dep[N]; 
int n, m, s, k = 0, x, y;
void add(int u, int v){
    k ++;
    a[k].to = v;
    a[k].last = pre[u];
    pre[u] = k;
}
void dfs(int p, int f){
    dep[p] = dep[f] + 1;
    st[p][0] = f;
    for(int i = pre[p];i;i = a[i].last)
        if(a[i].to != f)
            dfs(a[i].to, p);
}
int LCA(int x, int y){
    if(dep[x] < dep[y])
        swap(x, y);
    while(dep[x] > dep[y])
        x = st[x][lg[dep[x] - dep[y]]];
    if(x == y)
        return x;
    for(int i = L - 1;i >= 0;i --)
        if(st[x][i] != st[y][i]){
            x = st[x][i];
            y = st[y][i];
        }
    return st[x][0];
}
int main(){
    scanf("%d%d%d", &n, &m, &s);
    lg[1] = 0;
    for(int i = 1;i < n;i ++){
        scanf("%d%d", &x, &y);
        add(x, y);
        add(y, x);
        lg[i + 1] = lg[(i + 1) / 2] + 1;
    }
    dfs(s, 0);
    for(int j = 1;j < L;j ++){
        for(int i = 1;i <= n;i ++)
            st[i][j] = st[st[i][j - 1]][j - 1];
    }
    while(m --){
        scanf("%d%d", &x, &y);
        printf("%d\n", LCA(x, y));
    }
    return 0;
}*/
/*#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7, L = 20 + 7;
struct node {
    int to, last;
} a[N];
int pre[N], st[N][L], lg[N], dep[N], cnt[N];
int n, m, s, k = 0, x, y, ans = 0;

void add(int u, int v) {
    k++;
    a[k].to = v;
    a[k].last = pre[u];
    pre[u] = k;
}

void dfs(int p, int f) {
    dep[p] = dep[f] + 1;
    st[p][0] = f;
    for (int i = pre[p]; i; i = a[i].last)
        if (a[i].to != f)
            dfs(a[i].to, p);
}

void dfs2(int p, int f) {
    for (int i = pre[p]; i; i = a[i].last)
        if (a[i].to != f) {
            dfs2(a[i].to, p);
            cnt[p] += cnt[a[i].to];
        }
    ans = max(ans, cnt[p]);
}

int LCA(int x, int y) {
    if (dep[x] < dep[y])
        swap(x, y);
    while (dep[x] > dep[y])
        x = st[x][lg[dep[x] - dep[y]]];
    if (x == y)
        return x;
    for (int i = L - 1; i >= 0; i--)
        if (st[x][i] != st[y][i]) {
            x = st[x][i];
            y = st[y][i];
        }
    return st[x][0];
}

int main() {
    scanf("%d%d", &n, &m);
    lg[1] = 0;
    for (int i = 2; i <= n; i++)
        lg[i] = lg[i / 2] + 1;

    for (int i = 1; i < n; i++) {
        scanf("%d%d", &x, &y);
        add(x, y);
        add(y, x);
    }

    dfs(1, 0);

    for (int j = 1; j < L; j++) {
        for (int i = 1; i <= n; i++)
            st[i][j] = st[st[i][j - 1]][j - 1];
    }

    int lc;
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &x, &y);
        lc = LCA(x, y);
        cnt[x]++;
        cnt[y]++;
        cnt[lc]--;
        if (st[lc][0] != 0) 
            cnt[st[lc][0]]--;
    }

    dfs2(1, 0);
    cout << ans << endl;
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7, L = 20 + 7;
int a[N], st[N][L], lg[N], dis[N], cnt[N];
int n, m, x, y, num;

void prep() {
    memset(st, 0, sizeof(st));
    memset(dis, 0, sizeof(dis));
    memset(cnt, 0, sizeof(cnt));
    num = 0;
}

int find_left_group() {
    int l = 1, r = num, ans = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (dis[mid] < x) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    return ans + 1;
}

int find_right_group() {
    int l = 1, r = num, ans = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (dis[mid] < y) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    return ans;
}

int main() {
    for (int i = 2; i < N; i++) 
        lg[i] = lg[i / 2] + 1;
    while (cin >> n) {
        if (!n) break;
        cin >> m;
        prep();
        // 初始化第一个元素，避免访问a[0]
        cin >> a[1];
        cnt[++num] = 1;
        for (int i = 2; i <= n; i++) {
            cin >> a[i];
            if (a[i] == a[i - 1]) cnt[num]++;
            else cnt[++num]++;
        }
        // 计算dis数组
        for (int i = 1; i <= num; i++) {
            dis[i] = dis[i - 1] + cnt[i];
            st[i][0] = cnt[i];
        }
        // 构建ST表
        for (int j = 1; j < L; j++)
            for (int i = 1; i + (1 << j) - 1 <= num; i++)
                st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        // 处理查询
        while (m--) {
            cin >> x >> y;
            int l = find_left_group(), r = find_right_group();
            if (l > r) {
                cout << y - x + 1 << endl;
            } else if (l == r) {
                cout << max(dis[l] - x + 1, y - dis[r]) << endl;
            } else {
                int left = dis[l] - x + 1;
                int right = y - dis[r];
                int len = r - (l + 1) + 1;
                int max_mid = 0;
                if (len > 0) {
                    int s = lg[len];
                    max_mid = max(st[l + 1][s], st[r - (1 << s) + 1][s]);
                }
                cout << max(left, max(right, max_mid)) << endl;
            }
        }
    }
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int st1[N][21], st2[N][21], a[N], lg[N], n, q, l, r;
int main(){
    cin >> n >> q;
    lg[0] = -1;
    for(int i = 1;i <= n;i ++){
        cin >> a[i];
        st1[i][0] = st2[i][0] = a[i];
        lg[i] = lg[i / 2] + 1;
    }
    for(int j = 1;j <= lg[n];j ++)
        for(int i = 1;i + pow(2, j) - 1 <= n;i ++){
            st1[i][j] = max(st1[i][j - 1], st1[i + (1 << j - 1)][j - 1]);
            st2[i][j] = min(st2[i][j - 1], st2[i + (1 << j - 1)][j - 1]);
        }
    while(q --){
        cin >> l >> r;
        int x = max(st1[l][lg[r - l + 1]], st1[r - (1 << lg[r - l + 1]) + 1][lg[r - l + 1]]);
        int y = min(st2[l][lg[r - l + 1]], st2[r - (1 << lg[r - l + 1]) + 1][lg[r - l + 1]]);
        cout << x - y << endl;
    }
    return 0; 
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int st[N][21], lg[N];
int n, m, x, y;
#define FASTIO cin.tie(nullptr), cout.tie(nullptr);
int main(){
    cin >> n >> m;
    lg[0] = -1;
    for(int i = 1;i <= n;i ++){
        cin >> st[i][0];
        lg[i] = lg[i / 2] + 1;
    }
    for(int j = 1;j <= lg[n];j ++)
        for(int i = 1;i + (1 << j) - 1 <= n;i ++)
            st[i][j] = min(st[i][j - 1], st[i + (1 << j - 1)][j - 1]);
    while(m --){
        cin >> x >> y;
        int logg = lg[y - x + 1];
        cout << min(st[x][logg], st[y - (1 << logg) + 1][logg]) << ' ';
    }
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int minn[N * 4], a[N], n, m, x, y;
void push_up(int k){
    minn[k] = min(minn[k * 2], minn[k * 2 + 1]);
}
void build(int k, int l, int r){
    if(l == r){
        minn[k] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    if(l <= mid)
        build(k * 2, l, mid);
    if(mid + 1 <= r)
        build(k * 2 + 1, mid + 1, r);
    push_up(k);
}
int query(int k, int l, int r, int x, int y){
    if(l >= x && r <= y)
        return minn[k];
    int mid = (l + r) / 2, res = INT_MAX;
    if(x <= mid)
        res = min(res, query(k * 2, l, mid, x, y));
    if(y >= mid + 1)
        res = min(res, query(k * 2 + 1, mid + 1, r, x, y));
    return res;
}
int main(){
    cin >> n >> m;
    for(int i = 1;i <= n;i ++){
        cin >> a[i];
    }
    build(1, 1, n);
    while(m --){
        cin >> x >> y;
        cout << query(1, 1, n, x, y) << ' ';
    }
    return 0;
}*/

//区间最大值,线段树.
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 7;
int a[N], maxn[N * 4], add[N * 4], sett[N * 4], n, q;
void push_up(int k){
    maxn[k] = max(maxn[k * 2], maxn[k * 2 + 1]);//根据子节点更新父节点.
}
void build(int k, int l, int r){//建树
    if(l == r){
        maxn[k] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    if(l <= mid)
        build(k * 2, l, mid);
    if(r >= mid + 1)
        build(k * 2 + 1, mid + 1, r);
    push_up(k);
}
void change2(int k, int v){
    maxn[k] = v;
    add[k] = 0;
    sett[k] = v;
}
void push_down2(int k, int l, int r){
    if(!sett[k])
        return;
    change2(k * 2, sett[k]);
    change2(k * 2 + 1, sett[k]);
    sett[k] = 0;
}
void change(int k, int v){//将最大值增加v,因为整体增加了v.
    maxn[k] += v;
    add[k] += v;
}
void push_down1(int k, int l, int r){//将add(需要将最大值加上的部分)复制给子节点,让最大值上升.
    if(!add[k])
        return;
    push_down2(k, l, r);
    change(k * 2, add[k]);
    change(k * 2 + 1, add[k]);
    add[k] = 0;
}
void push_down(int k, int l, int r){
    push_down2(k, l, r);
    push_down1(k, l, r);
}
void add_to(int k, int l, int r, int x, int y, int v){
    if(x <= l && r <= y){
        push_down2(k, l, r);
        maxn[k] += v;
        add[k] += v;
        return;
    }
    push_down(k, l, r);//将add传下去,以便在更新时有正确的值.
    int mid = (l + r) / 2;
    if(mid >= x)
        add_to(k * 2, l, mid, x, y, v);
    if(mid + 1 <= y)
        add_to(k * 2 + 1, mid + 1, r, x, y, v);
    push_up(k);
}
void change_to(int k, int l, int r, int x, int y, int v){
    if(x <= l && r <= y){
        sett[k] = v;
        maxn[k] = v;
        add[k] = 0;
        return;
    }
    push_down(k, l, r);
    int mid = (l + r) / 2;
    if(mid >= x)
        change_to(k * 2, l, mid, x, y, v);
    if(mid + 1 <= y)
        change_to(k * 2 + 1, mid + 1, r, x, y, v);
    push_up(k);
}
int query(int k, int l, int r, int x, int y){
    if(l >= x && r <= y)
        return maxn[k];
    push_down(k, l, r);//将add传下去,以便在查询时有正确的值.
    int mid = (l + r) / 2, res = -1e18;
    if(mid >= x)
        res = max(res, query(k * 2, l, mid, x, y));
    if(mid + 1 <= y)
        res = max(res, query(k * 2 + 1, mid + 1, r, x, y));
    return res;
}
signed main(){
    scanf("%lld %lld", &n, &q);
    for(int i = 1;i <= n;i ++)
        scanf("%lld", &a[i]);
    build(1, 1, n);
    while(q --){
        int c, l, r, x;
        scanf("%lld %lld %lld", &c, &l, &r);
        if(c == 1){
            scanf("%lld", &x);
            change_to(1, 1, n, l, r, x);
        }
        else if(c == 2){
            scanf("%lld", &x);
            add_to(1, 1, n, l, r, x);
        }
        else {
            printf("%lld\n", query(1, 1, n, l, r));
        }
        // for(int i = 1;i <= 7;i ++)
        //     cout << sett[i] << ' ';
        // cout << endl;
        // for(int i = 1;i <= 7;i ++)
        //     cout << maxn[i] << ' ';
        // cout << endl;
    }
    return 0;
}