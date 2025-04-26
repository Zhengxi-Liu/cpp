//单调队列,滑动窗口
/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
long long a[N], q[N], p[N];
int n, k, head = 1, tail;
int main(){
    cin >> n >> k;
    for(int i = 1;i <= n;i ++){
        cin >> a[i];
    }
    for(int i = 1;i <= n;i ++){
        while(head <= tail && q[tail] >= a[i])
            tail --;
        q[++ tail] = a[i];
        p[tail] = i;
        while(p[head] <= i - k)
            head ++;
        if(i >= k)
            cout << q[head] << ' ';
    }
    cout << endl;
    tail = 0;
    head = 1;
    for(int i = 1;i <= n;i ++){
        while(head <= tail && q[tail] <= a[i])
            tail --;
        q[++ tail] = a[i];
        p[tail] = i;
        while(p[head] <= i - k)
            head ++;
        if(i >= k)
            cout << q[head] << ' ';
    }
    cout << endl;
    return 0;
}*/

//AT_dp_m Candies
/*#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 7, M = 1e2 + 7, MOD = 1e9 + 7;
int dp[M][N], n, m, sum[N], x;
signed main(){
    cin >> n >> m;
    dp[0][0] = 1;
    for(int i = 1;i <= n;i ++){
        cin >> x;
        memset(sum, 0, sizeof(sum));
        for(int j = 0;j <= m;j ++)
            sum[j] = (((j ? sum[j - 1] : 0) + dp[i - 1][j]) % MOD + MOD) % MOD;
        for(int j = 0;j <= m;j ++)
            dp[i][j] += sum[j] - sum[(j - x - 1) < 0 ? N - 1 : j - x - 1], dp[i][j] = (dp[i][j] % MOD + MOD) % MOD;
    }
    cout << dp[n][m] << endl;
    return 0;
}*/

//CF833B The Bakery
/*#include<bits/stdc++.h>
using namespace std;
const int N = 35e3 + 7, M = 50 + 7;
int maxn[N * 4], add[N * 4];
int pre[N], pos[N];
int dp[M][N];
int a[N], n, m;
inline void push_up(int k){
    maxn[k] = max(maxn[k * 2], maxn[k * 2 + 1]);
}
inline void build(int k, int l, int r, int now){
    if(l == r){
        maxn[k] = dp[now][l - 1];
        return;
    }
    int mid = (l + r) >> 1;
    build(k * 2, l, mid, now);
    build(k * 2 + 1, mid + 1, r, now);
    push_up(k);
}
inline void change(int k, int l, int r, int s){
    maxn[k] += s;
    add[k] += s;
}
inline void push_down(int k, int l, int r){
    if(!add[k])
        return;
    int mid = (l + r) >> 1;
    change(k * 2, l, mid, add[k]);
    change(k * 2 + 1, mid + 1, r, add[k]);
    add[k] = 0;
}
inline void update(int k, int l, int r, int x, int y, int s){
    if(l >= x && r <= y){
        change(k, l, r, s);
        return;
    }
    push_down(k, l, r);
    int mid = (l + r) >> 1;
    if(mid >= x)
        update(k * 2, l, mid, x, y, s);
    if(mid < y)
        update(k * 2 + 1, mid + 1, r, x, y, s);
    push_up(k);
}
inline int query(int k, int l, int r, int x, int y){
    if(l >= x && r <= y)
        return maxn[k];
    push_down(k, l, r);
    int mid = (l + r) >> 1, res = 0;
    if(mid >= x)
        res = query(k * 2, l, mid, x, y);
    if(mid < y)
        res = max(res, query(k * 2 + 1, mid + 1, r, x, y));
    return res;
}
inline void init(){
    memset(maxn, 0, sizeof(maxn));
    memset(add, 0, sizeof(add));
}
int main(){
    cin >> n >> m;
    for(int i = 1;i <= n;i ++){
        cin >> a[i];
        pre[i] = pos[a[i]] + 1;
        pos[a[i]] = i;
    }
    for(int i = 1;i <= m;i ++){
        init();
        build(1, 1, n, i - 1);
        for(int j = 1;j <= n;j ++){
            update(1, 1, n, pre[j], j, 1);
            dp[i][j] = query(1, 1, n, 1, j);
        }
    }
    cout << dp[m][n] << endl;
    return 0;
}*/

//AT_dp_w Intervals
/*#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 7;
int val[N * 4], add[N * 4], n, m;
struct str{
    int x, y, v;
}a[N];
bool cmp(str a, str b){
    return a.y < b.y;
}
void push_up(int k){
    val[k] = max(val[k * 2], val[k * 2 + 1]);
}
void change(int k, int v){
    val[k] += v;
    add[k] += v;
}
void push_down(int k, int l, int r){
    if(!add[k]) return;
    change(k * 2, add[k]);
    change(k * 2 + 1, add[k]);
    add[k] = 0;
}
void update(int k, int l, int r, int x, int y, int v){
    if(l >= x && r <= y){
        change(k, v);
        return;
    }
    push_down(k, l, r);
    int mid = (l + r) >> 1;
    if(mid >= x)
        update(k * 2, l, mid, x, y, v);
    if(mid < y)
        update(k * 2 + 1, mid + 1, r, x, y, v);
    push_up(k);
}
signed main(){
    cin >> n >> m;
    for(int i = 1;i <= m;i ++)
        cin >> a[i].x >> a[i].y >> a[i].v;
    sort(a + 1, a + m + 1, cmp);
    for(int i = 1, j = 1;i <= n;i ++){
        update(1, 1, n, i, i, max(0ll, val[1]));
        while(a[j].y == i && j <= m)
            update(1, 1, n, a[j].x, a[j].y, a[j].v), j ++;
    }
    cout << max(0ll, val[1]) << endl;
    return 0;
}*/

//P2569 [SCOI2010] 股票交易
/*#include<bits/stdc++.h>
using namespace std;
const int N = 2e3 + 7;
struct str{
    int ap, as, bp, bs;
}a[N];
int dp[N][N], q[N];//记录天数,持股数量
int n, maxn, w, ans, l, r;
int main(){
    cin >> n >> maxn >> w;
    for(int i = 1; i <= n; i ++)
        cin >> a[i].ap >> a[i].bp >> a[i].as >> a[i].bs;
    memset(dp, 0xbf, sizeof(dp));
    dp[0][0] = 0;
    for(int i = 1; i <= n; i ++){
        for(int j = 0;j <= a[i].as;j ++)
            dp[i][j] = -j * a[i].ap;
        for(int j = 0;j <= maxn;j ++)
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        if(i <= w)
            continue;
        l = 1, r = 0;
        for(int j = 0;j <= maxn;j ++){
            while(l <= r && q[l] < j - a[i].as)
                l ++;
            while(l <= r && dp[i - w - 1][q[r]] + q[r] * a[i].ap <= dp[i - w - 1][j] + j * a[i].ap)
                r --;
            q[++ r] = j;
            if(l <= r)
                dp[i][j] = max(dp[i][j], dp[i - w - 1][q[l]] + q[l] * a[i].ap - j * a[i].ap);
        }
        l = 1, r = 0;
        for(int j = maxn;j >= 0;j --){
            while(l <= r && q[l] > j + a[i].bs)
                l ++;
            while(l <= r && dp[i - w - 1][q[r]] + q[r] * a[i].bp <= dp[i - w - 1][j] + j * a[i].bp)
                r --;
            q[++ r] = j;
            if(l <= r)
                dp[i][j] = max(dp[i][j], dp[i - w - 1][q[l]] + q[l] * a[i].bp - j * a[i].bp);
        }
    }
    for(int j = 0; j <= maxn; j ++)
        ans = max(ans, dp[n][j]);
    cout << max(0, ans) << endl;
    return 0;
}*/

//P2605 [ZJOI2010] 基站选址
#include<bits/stdc++.h>
using namespace std;
const int N = 2e4 + 7, M = 1e2 + 7, INF = 0x3f3f3f3f;
int dp[N];
int sum[N * 4], add[N * 4];
int st[N], ed[N];
int n, m;
int d[N], c[N], s[N], w[N];
struct str{ int to, last; }a[N];
int pre[N], k;
void add_edge(int x, int y){
    a[++ k].to = y;
    a[k].last = pre[x];
    pre[x] = k;
}
void read(){
    cin >> n >> m;
    for(int i = 2; i <= n; i++)
        cin >> d[i];
    for(int i = 1; i <= n; i++)
        cin >> c[i];
    for(int i = 1; i <= n; i++)
        cin >> s[i];
    for(int i = 1; i <= n; i++)
        cin >> w[i];
}
void push_up(int k){
    sum[k] = min(sum[k << 1], sum[k << 1 | 1]);
}
void build(int k, int l, int r){
    add[k] = 0;
    if(l == r){
        sum[k] = dp[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(k << 1, l, mid);
    build(k << 1 | 1, mid + 1, r);
    push_up(k);
}
void change(int k, int v){
    sum[k] += v;
    add[k] += v;
}
void push_down(int k){
    if(!add[k]) return;
    change(k << 1, add[k]);
    change(k << 1 | 1, add[k]);
    add[k] = 0;
}
void update(int k, int l, int r, int x, int y, int v){
    if(x > y) return;
    if(l >= x && r <= y){
        change(k, v);
        return;
    }
    push_down(k);
    int mid = (l + r) >> 1;
    if(x <= mid) 
        update(k << 1, l, mid, x, y, v);
    if(y > mid) 
        update(k << 1 | 1, mid+1, r, x, y, v);
    push_up(k);
}
int query(int k, int l, int r, int x, int y){
    if(x > y) 
        return INF;
    if(l >= x && r <= y) 
        return sum[k];
    push_down(k);
    int mid = (l + r) >> 1, res = INF;
    if(x <= mid) 
        res = query(k << 1, l, mid, x, y);
    if(y > mid) 
        res = min(res, query(k << 1 | 1, mid + 1, r, x, y));
    return res;
}
int main(){
    read();
    n ++, m ++;
    d[n] = INF;
    for(int i = 1; i <= n; i ++){
        st[i] = lower_bound(d + 1, d + n + 1, d[i] - s[i]) - d;
        ed[i] = lower_bound(d + 1, d + n + 1, d[i] + s[i]) - d;
        if(ed[i] > n || d[ed[i]] > d[i] + s[i]) 
            ed[i]--;
        add_edge(ed[i], i);
    }
    int now = 0;
    for(int i = 1; i <= n; i ++){
        dp[i] = now + c[i];
        for(int j = pre[i]; j; j = a[j].last)
            now += w[a[j].to];
    }
    int res = dp[n];
    for(int i = 2; i <= m; i ++){
        build(1, 1, n);
        for(int j = 1; j <= n; j ++){
            dp[j] = query(1, 1, n, 1, j - 1) + c[j];
            for(int x = pre[j]; x; x = a[x].last){
                int to = a[x].to;
                update(1, 1, n, 1, st[to] - 1, w[to]);
            }
        }
        res = min(res, dp[n]);
    }
    cout << res << endl;
    return 0;
}