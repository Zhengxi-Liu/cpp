// D. 赶集
/*#include<bits/stdc++.h>
using namespace std;

#define int long long
#define mid ((l + r) >> 1)

const int N = 2e5 + 7;

int mx1[N << 2], mx2[N << 2];
// mx1 为 左侧, mx2 为 右侧

int dp[N], p[N], t[N];

int n, m, C, ans = LLONG_MIN;

void push_up(int k){
    mx1[k] = max(mx1[k << 1], mx1[(k << 1) | 1]);
    mx2[k] = max(mx2[k << 1], mx2[(k << 1) | 1]);
}

void build(int k, int l, int r){
    if(l == r){
        mx1[k] = mx2[k] = LLONG_MIN;
        return;
    }
    build(k << 1, l, mid);
    build((k << 1) | 1, mid + 1, r);
    push_up(k);
}

void upd(int k, int l, int r, int x, int v){
    if(l == x && r == x){
        mx1[k] = v + x * C;
        mx2[k] = v - x * C;
        return;
    }
    if(mid >= x) upd(k << 1, l, mid, x, v);
    else upd((k << 1) | 1, mid + 1, r, x, v);
    push_up(k);
}

int qry(int k, int l, int r, int x, int y, int op){
    if(l >= x && r <= y){
        if(op == 1) return mx1[k];
        return mx2[k];
    }
    int res = LLONG_MIN;
    if(mid >= x) res = qry(k << 1, l, mid, x, y, op);
    if(mid + 1 <= y) res = max(res, qry((k << 1) | 1, mid + 1, r, x, y, op));
    return res;
}

signed main(){

    cin >> n >> C >> m;

    for(int i = 1; i <= n; i ++)
        dp[i] = LLONG_MIN;
    build(1, 1, n);

    dp[1] = 0;
    upd(1, 1, n, 1, 0);

    for(int i = 1; i <= m; i ++)
        cin >> t[i] >> p[i];
    
    for(int i = 1; i <= m; i ++){

        int ll = LLONG_MIN, rr = LLONG_MIN;
        if(t[i] > 1) ll = qry(1, 1, n, 1, t[i] - 1, 1) - t[i] * C;
        if(t[i] < n) rr = qry(1, 1, n, t[i] + 1, n, 2) + t[i] * C;
        int tmp = max(ll, rr);
        dp[t[i]] = max(dp[t[i]], tmp) + p[i];
        upd(1, 1, n, t[i], dp[t[i]]);
        
    }

    for(int i = 1; i <= n; i ++)
        ans = max(ans, dp[i]);
    
    cout << ans << endl;

    return 0;
}*/

// F. 最远点
/*#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 5e5 + 7;

int a[N], b[N], ans[N];

int n, t;

int dst(int s1, int s2, int e1, int e2){
    return (s1 - e1) * (s1 - e1) + (s2 - e2) * (s2 - e2);
}

void dfs(int l, int r, int x, int y){
    int mid = (l + r) >> 1, idx = mid;
    ans[mid] = 0;
    for(int i = max(mid + 1, x); i <= y; i ++){
        int tmp = dst(a[i], b[i], a[mid], b[mid]);
        if(tmp > ans[mid]) ans[mid] = tmp, idx = i;
    }
    if(mid - 1 >= l) dfs(l, mid - 1, x, idx);
    if(mid + 1 <= r) dfs(mid + 1, r, idx, y);
    if(idx > n) idx -= n;
    ans[mid] = idx;
}

signed main(){

    scanf("%lld", &t);
    
    while(t --){

        scanf("%lld", &n);

        for(int i = 1; i <= n; i ++)
            scanf("%lld %lld", &a[i], &b[i]), a[i + n] = a[i], b[i + n] = b[i];

        dfs(1, n, 1, n << 1);

        for(int i = 1; i <= n; i ++)
            printf("%lld\n", ans[i]);

    }

    return 0;
}*/

// E. 图上LIS
/*#include<bits/stdc++.h>
using namespace std;

#define mid ((l + r) >> 1)
const int N = 1e5 + 7, M = 1e5;

int n, m, tot, x, y, v;

int mx[N << 4], ls[N << 4], rs[N << 4], rt[N << 4];

void upd(int &k, int l, int r, int x, int v){
    if(!k) k = ++ tot;
    if(l == x && r == x){
        mx[k] = max(mx[k], v);
        return;
    }
    if(mid >= x) upd(ls[k], l, mid, x, v);
    else upd(rs[k], mid + 1, r, x, v);
    mx[k] = max(mx[ls[k]], mx[rs[k]]);
}

int qry(int k, int l, int r, int x, int y){
    if(!k || x > y) return 0;
    if(l >= x && r <= y) return mx[k];
    int res = 0;
    if(mid >= x) res = max(res, qry(ls[k], l, mid, x, y));
    if(mid + 1 <= y) res = max(res, qry(rs[k], mid + 1, r, x, y));
    return res;
}

int main(){

    cin >> n >> m;

    while(m --){

        cin >> x >> y >> v;
        v ++;
        int tmp = qry(rt[x], 1, M, 1, v - 1);
        upd(rt[y], 1, M, v, tmp + 1);

    }

    int ans = 0;
    for(int i = 1; i <= n; i ++)
        ans = max(ans, mx[rt[i]]);
    cout << ans << endl;

    return 0;
}*/

// G. 划分区间
/*#include<bits/stdc++.h>
using namespace std;

#define mid ((l + r) >> 1)

const int N = 35e3 + 7, M = 50 + 7;

int dp[M][N], a[N];

int lst[N], d[N];

int mx[N << 2], tag[N << 2];

int n, m;

void push_up(int k){
    mx[k] = max(mx[k << 1], mx[(k << 1) | 1]);
}

void build(int k, int l, int r, int v){
    mx[k] = tag[k] = 0;
    if(l == r){
        mx[k] = dp[v][l - 1];
        return;
    }
    build(k << 1, l, mid, v);
    build((k << 1) | 1, mid + 1, r, v);
    push_up(k);
}

void change(int k, int v){
    mx[k] += v;
    tag[k] += v;
}

void push_down(int k){
    if(!tag[k]) return;
    change(k << 1, tag[k]);
    change((k << 1) | 1, tag[k]);
    tag[k] = 0;
}

void upd(int k, int l, int r, int x, int y, int v){
    if(x > y) return;
    if(l >= x && r <= y){
        change(k, v);
        return;
    }
    push_down(k);
    if(mid >= x) upd(k << 1, l, mid, x, y, v);
    if(mid + 1 <= y) upd((k << 1) | 1, mid + 1, r, x, y, v);
    push_up(k);
}

int qry(int k, int l, int r, int x, int y){
    if(x > y) return 0;
    if(l >= x && r <= y) return mx[k];
    push_down(k);
    int res = 0;
    if(mid >= x) res = qry(k << 1, l, mid, x, y);
    if(mid + 1 <= y) res = max(res, qry((k << 1) | 1, mid + 1, r, x, y));
    return res;
}

int main(){
    
    cin >> n >> m;
    
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
        d[a[i]] = n + 1;
    }
    
    for(int i = n; i >= 1; i --){
        lst[d[a[i]]] = i;
        d[a[i]] = i;
    }
    
    for(int j = 1; j <= m; j ++){
        build(1, 1, n, j - 1);
        for(int i = j; i <= n; i ++){
            upd(1, 1, n, lst[i] + 1, i, 1);
            dp[j][i] = qry(1, 1, n, j, i);
        }
    }
    cout << dp[m][n] << endl;
    
    return 0;
}*/

// H. 斜率
/*#include<bits/stdc++.h>
using namespace std;

// 如果 L - 1 和 L 形成的斜率 <= k, L 就废了
// 所以 while (slope(L - 1, L) <= k) L ++;
// 于是推出斜率需要严格递增 (如果越来越小, 就会一直 L ++ 嘛)

#define int long long
const int N = 1e5 + 7;

struct str{
    int x, y;
}a[N], stk[N], q[N];

bool cmp(str a, str b){
    if(a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}

int ans[N], n, m, head = 1, top = 2;

bool check(str a, str b, str c){
    return (b.y - a.y) * (c.x - b.x) <= (c.y - b.y) * (b.x - a.x);
}

int cal(str a, int k){
    return a.x * k + a.y;
}

signed main(){

    cin >> n >> m;

    for(int i = 1; i <= n; i ++) 
        cin >> a[i].x >> a[i].y;

    sort(a + 1, a + n + 1, cmp);

    stk[1] = a[1], stk[2] = a[2];
    for(int i = 3; i <= n; i ++){
        while(top >= 2 && check(stk[top - 1], stk[top], a[i])) top --;
        stk[++ top] = a[i];
    }
    
    for(int i = 1; i <= m; i ++)
        cin >> q[i].x, q[i].y = i;
    sort(q + 1, q + m + 1, cmp);
    
    for(int i = 1; i <= m; i ++){
        while(head < top && cal(stk[head], q[i].x) <= cal(stk[head + 1], q[i].x)) head ++;
        ans[q[i].y] = cal(stk[head], q[i].x);
    }
    
    for(int i = 1; i <= m; i ++)
        cout << ans[i] << endl;

    return 0;
}*/

// I. 土地并购

// 50 pts: 实在找不出这个版本的错误
/*#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N = 4e5 + 7;

struct str{
    int x, y;
}a[N], b[N], q[N];

int dp[N], n, cnt, tail;

bool cmp(str a, str b){
    if(a.x == b.x) return a.y > b.y;
    return a.x < b.x;
}

int cal(str a, int k){
    return a.x * k + a.y;
}

bool check(str a, str b, str c){
    return (c.y - b.y) * (b.x - a.x) >= (b.y - a.y) * (c.x - b.x); // 因为 slope 都是负的
}

double slope(str a, str b){
    return 1.0 * (b.y - a.y) / (b.x - a.x);
}

signed main(){

    cin >> n;

    for(int i = 1; i <= n; i ++)
        cin >> a[i].x >> a[i].y;

    sort(a + 1, a + n + 1, cmp);

    for(int i = n; i >= 1; i --){
        int tmp = i;
        while(i >= 2 && a[i - 1].x <= a[tmp].x && a[tmp].y >= a[i - 1].y) i --;
        b[++ cnt] = a[tmp];
    }
    n = cnt;
    
    for(int i = 1; i <= n; i ++)
        a[i] = b[n - i + 1];
    
    q[0] = {a[1].y, 0};
    for(int i = 1; i <= n; i ++){
        while(tail && cal(q[tail], a[i].x) > cal(q[tail - 1], a[i].x)) tail --;
        dp[i] = cal(q[tail], a[i].x);
        while(tail && slope(q[tail - 1], q[tail]) < slope(q[tail], {a[i + 1].y, dp[i]})) tail --;
        q[++ tail] = {a[i + 1].y, dp[i]};
    }
    cout << dp[n] << endl;
    return 0;
}*/

// 100 pts:
/*#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N = 4e5 + 7;

struct str{
    int x, y;
}a[N], b[N];

int dp[N], q[N], n, cnt, head, tail;

bool cmp(str a, str b){
    if(a.y == b.y) return a.x < b.x;
    return a.y > b.y;
}

double slope(int x, int y){
    return 1.0 * (dp[y] - dp[x]) / (a[x + 1].y - a[y + 1].y); // 反过来算
}

signed main(){

    cin >> n;

    for(int i = 1; i <= n; i ++)
        cin >> b[i].x >> b[i].y;

    sort(b + 1, b + n + 1, cmp);

    for(int i = 1; i <= n; i ++){
        if(b[i].x < a[cnt].x) continue;
        a[++ cnt] = {b[i].x, b[i].y};
    }
    n = cnt;
    
    q[head] = 0;
    for(int i = 1; i <= n; i ++){
        while(head < tail && slope(q[head], q[head + 1]) <= a[i].x) head ++;
        dp[i] = dp[q[head]] + a[q[head] + 1].y * a[i].x;
        while(head < tail && slope(q[tail - 1], i) <= slope(q[tail - 1], q[tail])) tail --;
        q[++ tail] = i;
    }
    cout << dp[n] << endl;
    return 0;
}*/

