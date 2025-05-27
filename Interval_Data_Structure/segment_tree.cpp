//两个模版
/*#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1e5 + 7;
struct node {
    LL sum, l, r;
}a[N * 4];
LL n, m, k, x, y;
void build(int k, int l, int r){
    node p;
    p.sum = 0, p.l = l, p.r = r;
    a[k] = p;
    if(l == r)
        return;
    int mid = l + r >> 1;
    build(k << 1, l, mid);
    build(k << 1 | 1, mid + 1, r);
}
void update(int k, int p, LL v){
    if(a[k].l == p && a[k].r == p){
        a[k].sum += v;
        return;
    }
    LL mid = a[k].l + a[k].r >> 1;
    if(p <= mid)
        update(k * 2, p, v);
    else
        update(k * 2 + 1, p, v);
    a[k].sum = a[k * 2].sum + a[k * 2 + 1].sum;
}
LL query(int k, int x, int y){
    if(a[k].l >= x && a[k].r <= y)
        return a[k].sum;
    int mid = a[k].l + a[k].r >> 1;
    LL res = 0;
    if(x <= mid)
        res += query(k * 2, x, y);
    if(y >= mid + 1)
        res += query(k * 2 + 1, x, y);
    return res;
}
int main(){
    scanf("%lld %lld", &n, &m);
    build(1, 1, n);
    while(m --){
        scanf("%lld %lld %lld", &k, &x, &y);
        if(!k)
            update(1, x, y);
        else 
            printf("%lld\n", query(1, x, y));
    }
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
typedef long long ll;
ll ma[N * 4], n, p, m, x, len = 0, ans = 0;
void update(int k, int l, int r, int p, ll v){
    if(p == l && p == r){
        ma[k] = v;
        return ;
    }
    int mid = (l + r) / 2;
    if(p <= mid)
        update(k * 2, l, mid, p, v);
    else
        update(k * 2 + 1, mid + 1, r, p, v);
    ma[k] = max(ma[k * 2], ma[k * 2 + 1]);
}
int query(int k, int l, int r, int x, int y){
    if(l >= x && r <= y)
        return ma[k];
    int mid = (l + r) / 2, res = 0;
    if(x <= mid)
        res = query(k * 2, l, mid, x, y);
    if(y >= mid + 1)
        res = max(res, query(k * 2 + 1, mid + 1, r, x, y));
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> m >> p;
    n = m;
    char c;
    while(m --){
        cin >> c >> x;
        if(c == 'A')
            update(1, 1, n, ++ len, (x + ans) % p);
        else {
            ans = query(1, 1, n, len - x + 1, len);
            cout << ans << endl;
        }
    }
    return 0;
}*/

//区间修改
/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
typedef long long LL;
LL sum[N * 4], add[N * 4];
int a[N], n, m;
void push_up(int k){
    sum[k] = sum[k * 2] + sum[k * 2 + 1];
}
void build(int k, int l, int r){
    if(l == r){
        sum[k] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(k * 2, l, mid);
    build(k * 2 + 1, mid + 1, r);
    push_up(k);
}
void change(int k, int l, int r, int v){
    sum[k] += 1ll * v * (r - l + 1);//一共从 l 到 r (r - l + 1) 个节点,所以有v * (r - l + 1)个值
    add[k] += v;
}
void push_down(int k, int l, int r){
    if(!add[k])
        return;
    int mid = (l + r) / 2;
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
    int mid = (l + r) / 2;
    if(x <= mid)
        update(k * 2, l, mid, x, y, v);
    if(y >= mid + 1)
        update(k * 2 + 1, mid + 1, r, x, y, v);
    push_up(k);
}
LL query(int k, int l, int r, int x, int y){
    if(l >= x && r <= y)
        return sum[k];
    push_down(k, l, r);
    int mid = (l + r) / 2;
    LL res = 0;
    if(x <= mid)
        res += query(k * 2, l, mid, x, y);
    if(y >= mid + 1)
        res += query(k * 2 + 1, mid + 1, r, x, y);
    return res;
}
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1;i <= n;i ++)
        scanf("%d", &a[i]);
    build(1, 1, n);
    char c;
    int x, y, d;
    while(m --){
        scanf(" %c%d%d", &c, &x, &y);
        if(c == 'C'){
            scanf("%d", &d);
            update(1, 1, n, x, y, d);
        }
        else
            printf("%lld\n", query(1, 1, n, x, y));
    }
    return 0;
}*/

//add永久化
/*#include<bits/stdc++.h>
using namespace std;
#define FASTIO cin.tie(nullptr), cout.tie(nullptr);
const int N = 2e6 + 7;
typedef long long LL;
LL a[N], sum[N], add[N], d;
int n, m, c, x, y;
void build(int k, int l, int r){
    if(l == r){
        sum[k] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(k * 2, l, mid);
    build(k * 2 + 1, mid + 1, r);
    sum[k] = sum[k * 2] + sum[k * 2 + 1];
}
void update(int k, int l, int r, int x, int y, int v){
    if(l >= x && r <= y){
        add[k] += v;
        return;
    }
    sum[k] += (min(r, y) - max(l, x) + 1) * v;
    int mid = (l + r) / 2;
    if(x <= mid)
        update(k * 2, l, mid, x, y, v);
    if(y >= mid + 1)
        update(k * 2 + 1, mid + 1, r, x, y, v);
}
LL query(int k, int l, int r, int x, int y){
    if(l >= x && r <= y)
        return sum[k] + add[k] * (r - l + 1);
    LL res = (min(r, y) - max(x, l) + 1) * add[k];
    int mid = (l + r) / 2;
    if(x <= mid)
        res += query(k * 2, l, mid, x, y);
    if(y >= mid + 1)
        res += query(k * 2 + 1, mid + 1, r, x, y);
    return res;
}
int main(){
    FASTIO
    cin >> n >> m;
    for(int i = 1;i <= n;i ++)
        cin >> a[i];
    build(1, 1, n);
    while(m --){
        cin >> c;
        if(c == 1){//update
            cin >> x >> y >> d;
            update(1, 1, n, x, y, d);
        }
        else{//query
            cin >> x >> y;
            cout << query(1, 1, n, x, y) << endl;
        }
    }
    return 0;
}*/

//乘法操作
/*#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 7;
typedef long long LL;
LL a[N], sum[N], add[N], mul[N];
LL n, m, x, y, d, c, q;
void push_up(int k) {
    sum[k] = (sum[k * 2] + sum[k * 2 + 1]) % q;
}
void build(int k, int l, int r) {
    if (l == r) {
        sum[k] = a[l];
        mul[k] = 1;
        return;
    }
    int mid = (l + r) / 2;
    build(k * 2, l, mid);
    build(k * 2 + 1, mid + 1, r);
    push_up(k);
    mul[k] = 1;
}
void change(int k, int l, int r, LL va, LL vm) {
    sum[k] = (sum[k] * vm + (r - l + 1) * va) % q;
    mul[k] = mul[k] * vm % q;
    add[k] = (add[k] * vm + va) % q;
}
void push_down(int k, int l, int r) {
    if (mul[k] == 1 && add[k] == 0)
        return;
    int mid = (l + r) / 2;
    change(k * 2, l, mid, add[k], mul[k]);
    change(k * 2 + 1, mid + 1, r, add[k], mul[k]);
    add[k] = 0;
    mul[k] = 1;
}
void update(int k, int l, int r, int x, int y, LL va, LL vm) {
    if (l >= x && r <= y) {
        change(k, l, r, va, vm);
        return;
    }
    push_down(k, l, r);
    int mid = (l + r) / 2;
    if (x <= mid)
        update(k * 2, l, mid, x, y, va, vm);
    if (y > mid)
        update(k * 2 + 1, mid + 1, r, x, y, va, vm);
    push_up(k);
}
LL query(int k, int l, int r, int x, int y) {
    if (l >= x && r <= y)
        return sum[k];
    push_down(k, l, r);
    int mid = (l + r) / 2;
    LL res = 0;
    if (x <= mid)
        res = (res + query(k * 2, l, mid, x, y)) % q;
    if (y > mid)
        res = (res + query(k * 2 + 1, mid + 1, r, x, y)) % q;
    return res;
}
#define FASTIO cin.tie(nullptr), cout.tie(nullptr);
int main() {
    FASTIO
    cin >> n >> m >> q;
    for (int i = 1;i <= n;i ++)
        cin >> a[i];
    build(1, 1, n);
    while (m --){
        cin >> c;
        if (c == 1){
            cin >> x >> y >> d;
            update(1, 1, n, x, y, 0, d);
        }
        if (c == 2){
            cin >> x >> y >> d;
            update(1, 1, n, x, y, d, 1);
        }
        if (c == 3){
            cin >> x >> y;
            cout << query(1, 1, n, x, y) << endl;
        }
    }
    return 0;
}*/

//区间gcd
/*#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 7;
typedef long long LL;
LL b[N], a[N], sum[N * 4], gcd_val[N * 4], add[N * 4], d;
int n, m, x, y;
char c;

LL GCD(LL x, LL y) {
    while (y != 0) {
        LL temp = y;
        y = x % y;
        x = temp;
    }
    return abs(x);
}

void push_up(int k) {
    sum[k] = sum[k * 2] + sum[k * 2 + 1];
    gcd_val[k] = GCD(gcd_val[k * 2], gcd_val[k * 2 + 1]);
}

void build(int k, int l, int r) {
    if (l == r) {
        sum[k] = a[l];
        gcd_val[k] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(k * 2, l, mid);
    build(k * 2 + 1, mid + 1, r);
    push_up(k);
}

void update(int k, int l, int r, int x, LL v) {
    if (l == r) {
        sum[k] += v;
        gcd_val[k] += v;
        return;
    }
    int mid = (l + r) / 2;
    if (x <= mid)
        update(k * 2, l, mid, x, v);
    else
        update(k * 2 + 1, mid + 1, r, x, v);
    push_up(k);
}

LL query_sum(int k, int l, int r, int x, int y) {
    if (l >= x && r <= y)
        return sum[k];
    int mid = (l + r) / 2;
    LL ret = 0;
    if (x <= mid)
        ret += query_sum(k * 2, l, mid, x, y);
    if (y > mid)
        ret += query_sum(k * 2 + 1, mid + 1, r, x, y);
    return ret;
}

LL query_gcd(int k, int l, int r, int x, int y) {
    if (l >= x && r <= y)
        return gcd_val[k];
    int mid = (l + r) / 2;
    LL ret = 0;
    if (x <= mid)
        ret = GCD(query_gcd(k * 2, l, mid, x, y), ret);
    if (y > mid)
        ret = GCD(ret, query_gcd(k * 2 + 1, mid + 1, r, x, y));
    return ret;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        a[i] = b[i] - b[i - 1];
    }
    build(1, 1, n);
    while (m--) {
        cin >> c >> x >> y;
        if (c == 'C') {
            cin >> d;
            update(1, 1, n, x, d);
            if (y + 1 <= n)
                update(1, 1, n, y + 1, -d);
        } else {
            LL t1 = query_gcd(1, 1, n, x + 1, y);
            LL t2 = query_sum(1, 1, n, 1, x);
            cout << GCD(t1, t2) << endl;
        }
    }
    return 0;
}*/

//P1253扶苏的问题
/*#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FASTIO cin.tie(nullptr), cout.tie(nullptr);
const int N = 1e6 + 7;
int maxn[N * 4], add[N * 4], sett[N * 4], a[N];
int n, m, l, r, c, x;
void push_up(int k) {
    maxn[k] = max(maxn[k * 2], maxn[k * 2 + 1]);
}
void build(int k, int l, int r) {
    sett[k] = LLONG_MAX;
    if (l == r) {
        maxn[k] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    if (mid >= l)
        build(k * 2, l, mid);
    if (mid + 1 <= r)
        build(k * 2 + 1, mid + 1, r);
    push_up(k);
}
void change(int k, int v, int t) {
    if (t == 1) {
        add[k] = 0;
        sett[k] = v;
        maxn[k] = v;
    } else {
        if (sett[k] == LLONG_MAX)
            add[k] += v;
        else
            sett[k] += v;
        maxn[k] += v;
    }
}
void push_down(int k) {
    if (sett[k] == LLONG_MAX) {
        change(k * 2, add[k], 2);
        change(k * 2 + 1, add[k], 2);
        add[k] = 0;
    } else {
        change(k * 2, sett[k], 1);
        change(k * 2 + 1, sett[k], 1);
        sett[k] = LLONG_MAX;
    }
}
void update(int k, int l, int r, int x, int y, int v, int type) {
    if (x <= l && r <= y) {
        change(k, v, type);
        return;
    }
    push_down(k);
    int mid = (l + r) / 2;
    if (x <= mid)
        update(k * 2, l, mid, x, y, v, type);
    if (y >= mid + 1)
        update(k * 2 + 1, mid + 1, r, x, y, v, type);
    push_up(k);
}
int query(int k, int l, int r, int x, int y) {
    if (x <= l && r <= y)
        return maxn[k];
    push_down(k);
    int mid = (l + r) / 2, res = LLONG_MIN;
    if (x <= mid)
        res = max(res, query(k * 2, l, mid, x, y));
    if (y >= mid + 1)
        res = max(res, query(k * 2 + 1, mid + 1, r, x, y));
    return res;
}
signed main() {
    scanf("%lld %lld", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    build(1, 1, n);
    while (m--) {
        scanf("%lld %lld %lld", &c, &l, &r);
        if (c == 1) {
            scanf("%lld", &x);
            update(1, 1, n, l, r, x, 1);
        } else if (c == 2) {
            scanf("%lld", &x);
            update(1, 1, n, l, r, x, 2);
        } else {
            printf("%lld\n", query(1, 1, n, l, r));
        }
    }
    return 0;
}*/

//3870开关
/*#include<bits/stdc++.h>
using namespace std;
#define FASTIO cin.tie(nullptr), cout.tie(nullptr);
const int N = 1e6 + 7;
int sum[N * 4], add[N * 4];
int n, m, l, r, c;
void push_up(int k){
    sum[k] = sum[k * 2] + sum[k * 2 + 1];
}
void build(int k, int l, int r) {
    if (l == r) {
        sum[k] = 0;
        return;
    }
    int mid = (l + r) / 2;
    build(k * 2, l, mid);
    build(k * 2 + 1, mid + 1, r);
    push_up(k);
}
void change(int k, int l, int r){
    sum[k] = (r - l + 1) - sum[k];
    add[k] ^= 1;
}
void push_down(int k, int l, int r){
    if(!add[k])
        return;
    int mid = (l + r) / 2;
    change(k * 2, l, mid);
    change(k * 2 + 1, mid + 1, r);
    add[k] = 0;
}
void update(int k, int l, int r, int x, int y){
    if(l >= x && r <= y){
        change(k, l, r);
        return;
    }
    int mid = (l + r) / 2;
    push_down(k, l, r);
    if(mid >= x)
        update(k * 2, l, mid, x, y);
    if(mid + 1 <= y)
        update(k * 2 + 1, mid + 1, r, x, y);
    push_up(k);
}
int query(int k, int l, int r, int x, int y){
    if (x <= l && r <= y)
        return sum[k];
    push_down(k, l, r);
    int mid = (l + r) / 2, res = 0;
    if (x <= mid)
        res += query(k * 2, l, mid, x, y);
    if (y >= mid + 1)
        res += query(k * 2 + 1, mid + 1, r, x, y);
    return res;
}
int main(){
    FASTIO
    cin >> n >> m;
    build(1, 1, n);
    while(m --){
        cin >> c >> l >> r;
        if(c == 0)
            update(1, 1, n, l, r);
        if(c == 1)
            cout << query(1, 1, n, l, r) << endl;
    }
    return 0;
}*/

//P1438无聊的数列
/*#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FASTIO cin.tie(nullptr), cout.tie(nullptr);
const int N = 1e5 + 7;
int sum[N * 4], s[N * 4], add[N * 4], p[N * 4], a[N];
int n, m, l, r, op, K, D;
void push_up(int k){
    sum[k] = sum[k * 2] + sum[k * 2 + 1];
}
void build(int k, int l, int r){
    if(l == r){
        sum[k] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(k * 2, l, mid);
    build(k * 2 + 1, mid + 1, r);
    push_up(k);
}
void change(int k, int l, int r, int start, int pl){
    s[k] += start;
    add[k] += pl;
    int num = r - l + 1;
    sum[k] += num * (start + pl * (num - 1) + start) / 2;
    p[k] = 1;
}
void push_down(int k, int l, int r){
    if(p[k] == 0)
        return;
    int mid = (l + r) / 2;
    change(k * 2, l, mid, s[k], add[k]);
    change(k * 2 + 1, mid + 1, r, s[k] + (mid + 1 - l) * add[k], add[k]);
    add[k] = s[k] = p[k] = 0;
}
void update(int k, int l, int r, int x, int y, int K, int D){
    if(l >= x && r <= y){
        change(k, l, r, K + (l - x) * D, D);
        return;
    }
    push_down(k, l, r);
    int mid = (l + r) / 2;
    if(mid >= x)
        update(k * 2, l, mid, x, y, K, D);
    if(mid + 1 <= y)
        update(k * 2 + 1, mid + 1, r, x, y, K, D);
    push_up(k);
}
int query(int k, int l, int r, int x){
    if(l == r && r == x)
        return sum[k];
    push_down(k, l, r);
    int mid = (l + r) / 2;
    if(mid >= x)
        return query(k * 2, l, mid, x);
    else if(mid + 1 <= x)
        return query(k * 2 + 1, mid + 1, r, x);
}
signed main(){
    FASTIO
    cin >> n >> m;
    for(int i = 1;i <= n;i ++)
        cin >> a[i];
    build(1, 1, n);
    while(m --){
        cin >> op;
        if(op == 1){
            cin >> l >> r >> K >> D;
            update(1, 1, n, l, r, K, D);
        }
        else{
            cin >> D;
            cout << query(1, 1, n, D) << endl;
        }
    }
    return 0;
}*/

//P1558色板游戏
/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7, M = 30 + 7;
int sum[M][N * 4], sett[N * 4], cnt[M];
int n, m, t, x, y, c;
void push_up(int k){
    for(int i = 1;i <= t;i ++)
        sum[i][k] = sum[i][k * 2] + sum[i][k * 2 + 1];
}
void build(int k, int l, int r){
    if(l == r){
        sum[1][k] = 1;
        return;
    }
    int mid = (l + r) / 2;
    build(k * 2, l, mid);
    build(k * 2 + 1, mid + 1, r);
    push_up(k);
}
void change(int k, int l, int r, int x){
    sett[k] = x;
    for(int i = 1;i <= t;i ++)
        sum[i][k] = 0;
    sum[x][k] = r - l + 1;
}
void push_down(int k, int l, int r){
    if(!sett[k])
        return;
    int mid = (l + r) / 2;
    change(k * 2, l, mid, sett[k]);
    change(k * 2 + 1, mid + 1, r, sett[k]);
    sett[k] = 0;
}
void update(int k, int l, int r, int x, int y, int s){
    if(l >= x && r <= y){
        change(k, l, r, s);
        return;
    }
    int mid = (l + r) / 2;
    push_down(k, l, r);
    if(mid >= x)
        update(k * 2, l, mid, x, y, s);
    if(mid < y)
        update(k * 2 + 1, mid + 1, r, x, y, s);
    push_up(k);
}
void query(int k, int l, int r, int x, int y){
    if(l >= x && r <= y){
        for(int i = 1;i <= t;i ++)
            cnt[i] += sum[i][k];
        //cout << k << ' ' << sum[1][k] << ' ' << sum[2][k] << endl;
        return;
    }
    int mid = (l + r) / 2;
    push_down(k, l, r);
    if(mid >= x)
        query(k * 2, l, mid, x, y);
    if(mid < y)
        query(k * 2 + 1, mid + 1, r, x, y);
}
int main(){
    cin >> n >> t >> m;
    build(1, 1, n);
    char op;
    while(m --){
        cin >> op >> x >> y;
        if(op == 'C'){
            cin >> c;
            update(1, 1, n, min(x, y), max(x, y), c);
        }
        else{
            memset(cnt, 0, sizeof(cnt));
            query(1, 1, n, min(x, y), max(x, y));
            int ans = 0;
            for(int i = 1;i <= t;i ++)
                if(cnt[i])
                    ans ++;
            cout << ans << endl;
        }
    }
    return 0;
}*/

//P1471 方差, 未完成❎
/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
double a[N], sum[N], add[N], square[N], v;
int n, m, op, x, y;
void push_up(int k){
    sum[k] = sum[k * 2] + sum[k * 2 + 1];
}
void build(int k, int l, int r){
    if(l == r){
        sum[k] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(k * 2, l, mid);
    build(k * 2 + 1, mid + 1, r);
    push_up(k);
}
void change(int k, int l, int r, double v){
    sum[k] += (r - l + 1) * v;
    add[k] += v; 
}
void push_down(int k, int l, int r){
    if(!add[k])
        return;
    int mid = (l + r) >> 1;
    change(k * 2, l, mid, add[k]);
    change(k * 2 + 1, mid + 1, r, add[k]);
    add[k] = 0;
}
void update(int k, int l, int r, int x, int y, double v){
    if(l >= x && r <= y){
        change(k, l, r, v);
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
double query_sum(int k, int l, int r, int x, int y){
    if(l >= x && r <= y)
        return sum[k];
    push_down(k, l, r);
    int mid = (l + r) >> 1;
    double res = 0;
    if(mid >= x)
        res += query_sum(k * 2, l, mid, x, y);
    if(mid < y)
        res += query_sum(k * 2 + 1, mid + 1, r, x, y);
    return res;
}
int main(){
    cin >> n >> m;
    for(int i = 1;i <= n;i ++)
        cin >> a[i];
    build(1, 1, n);
    while(m --){
        cin >> op >> x >> y;
        if(op == 1){
            cin >> v;
            update(1, 1, n, x, y, v);
        }
        else if(op == 2){
            double s = query_sum(1, 1, n, x, y);
            printf("%.4lf\n", s / (y - x + 1));
        }
        else {
            double s = query_sum(1, 1, n, x, y), mean = s / (y - x + 1);

        }
    }
    return 0;
}*/

//P6492 [COCI 2010/2011 #6] STEP
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;

int main(){

    return 0;
}