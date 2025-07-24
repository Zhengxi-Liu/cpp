//D. 赶集
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

//F. 最远点
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

//E. 图上LIS
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

//G. 划分区间
#include<bits/stdc++.h>
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
            dp[j][i] = qry(1, 1, n, j - 1, i);
        }
    }
    cout << dp[m][n] << endl;

    return 0;
}