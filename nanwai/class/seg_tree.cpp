//A. 3的倍数区间
/*#include<bits/stdc++.h>
using namespace std;

#define int long long
#define kl k << 1
#define kr (k << 1) | 1
#define mid ((l + r) >> 1)

const int N = 3e5 + 7, P = 3e8;

struct node{
    int L[3], R[3], sum[3], s;
    void tag(int l, int r, int v){
        for(int i = 0; i <= 2; i ++)
            L[i] = R[i] = sum[i] = 0;
        s = v;
        L[v % 3] = R[v % 3] = sum[v % 3] = 1;
    }
}T[N << 2];

int a[N], n, q, op, x, y;

void push_up(int k){
    T[k].s = T[kl].s + T[kr].s;
    for(int i = 0; i <= 2; i ++){
        T[k].sum[i] = T[kl].sum[i] + T[kr].sum[i];
        T[k].L[i] = T[kl].L[i] + T[kr].L[(i - T[kl].s + P) % 3];
        T[k].R[i] = T[kr].R[i] + T[kl].R[(i - T[kr].s + P) % 3];
    }
    for(int x = 0; x <= 2; x ++)
        for(int y = 0; y <= 2; y ++)
            T[k].sum[(x + y) % 3] += T[kl].R[x] * T[kr].L[y];
}

void build(int k, int l, int r){
    if(l == r){
        T[k].s = a[l];
        T[k].R[a[l] % 3] = T[k].L[a[l] % 3] = T[k].sum[a[l] % 3] = 1;
        return;
    }
    build(kl, l, mid);
    build(kr, mid + 1, r);
    push_up(k);
}

void upd(int k, int l, int r, int x, int v){
    if(l == x && r == x){
        T[k].tag(l, r, v);
        return;
    }
    if(mid >= x) upd(kl, l, mid, x, v);
    else upd(kr, mid + 1, r, x, v);
    push_up(k);
}

node qry(int k, int l, int r, int x, int y){
    if(l >= x && r <= y)
        return T[k];
    node ll, rr, res;
    ll.s = -1, rr.s = -1;
    if(mid >= x) ll = qry(kl, l, mid, x, y);
    if(mid < y) rr = qry(kr, mid + 1, r, x, y);
    if(ll.s == -1) return rr;
    if(rr.s == -1) return ll;
    res.s = ll.s + rr.s;
    for(int i = 0; i <= 2; i ++){
        res.sum[i] = ll.sum[i] + rr.sum[i];
        res.L[i] = ll.L[i] + rr.L[(i - ll.s + P) % 3];
        res.R[i] = rr.R[i] + ll.R[(i - rr.s + P) % 3];     
    }
    for(int x = 0; x <= 2; x ++)
        for(int y = 0; y <= 2; y ++)
            res.sum[(x + y) % 3] += ll.R[x] * rr.L[y];
    return res;
}

signed main(){

    cin >> n >> q;

    for(int i = 1; i <= n; i ++)
        cin >> a[i];

    build(1, 1, n);

    while(q --){

        cin >> op >> x >> y;

        if(op == 1)
            upd(1, 1, n, x, y);

        else {
            node ans = qry(1, 1, n, x, y);
            cout << ans.sum[0] << endl;
        }

    }

    return 0;
}*/

//B. 火车线路
/*#include<bits/stdc++.h>
using namespace std;

#define int long long
#define kl k << 1
#define kr (k << 1) | 1
#define mid ((l + r) >> 1)

const int N = 6e4 + 7;

struct node{
    int mx, add;
    void tag(int v){
        mx += v;
        add += v;
    }
}T[N << 2];

void push_up(int k){
    T[k].mx = max(T[kl].mx, T[kr].mx);
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

int qry(int k, int l, int r, int x, int y){
    if(l >= x && r <= y) return T[k].mx;
    push_down(k);
    int res = 0;
    if(mid >= x) res = qry(kl, l, mid, x, y);
    if(mid < y) res = max(res, qry(kr, mid + 1, r, x, y));
    return res;
}

int n, m, q, x, y, v;

signed main(){

    scanf("%lld %lld %lld", &n, &m, &q);

    while(q --){

        scanf("%lld %lld %lld", &x, &y, &v);

        y --;
        if(qry(1, 1, n, x, y) + v <= m){
            printf("T\n");
            upd(1, 1, n, x, y, v);
        }

        else printf("N\n");

    }

    return 0;
}*/

//C. 方差
/*#include<bits/stdc++.h>
using namespace std;

#define double long double
#define mid ((l + r) >> 1)
#define kl k << 1
#define kr (k << 1) | 1

const int N = 1e5 + 7;

double sum[N << 2], qsum[N << 2], tag[N << 2], a[N], v;

int n, q, op, x, y;

void push_up(int k){
	sum[k] = sum[kl] + sum[kr];
	qsum[k] = qsum[kl] + qsum[kr];
}

void build(int k, int l, int r){
	if(l == r){
		sum[k] = a[l];
		qsum[k] = a[l] * a[l];
		return;
	}
	build(kl, l, mid);
	build(kr, mid + 1, r);
	push_up(k);
}

void change(int k, int l, int r, double v){
	qsum[k] = qsum[k] + (r - l + 1) * v * v + 2 * v * sum[k]; 
	sum[k] += (r - l + 1) * v;
	tag[k] += v;
}

void push_down(int k, int l, int r){
	if(!tag[k]) return;
	change(kl, l, mid, tag[k]);
	change(kr, mid + 1, r, tag[k]);
	tag[k] = 0;
}

void upd(int k, int l, int r, int x, int y, double v){
	if(l >= x && r <= y){
		change(k, l, r, v);
		return;
	}
	push_down(k, l, r); 
	if(mid >= x) upd(kl, l, mid, x, y, v);
	if(mid + 1 <= y) upd(kr, mid + 1, r, x, y, v);
	push_up(k);
}

double qry(int k, int l, int r, int x, int y, int op){
	if(l >= x && r <= y){
		if(op == 1) return sum[k];
		return qsum[k];
	}
	push_down(k, l, r); 
	double res = 0;
	if(mid >= x) res = qry(kl, l, mid, x, y, op);
	if(mid + 1 <= y) res += qry(kr, mid + 1, r, x, y, op);
	return res; 
}

int main(){
	
	cin >> n >> q;
	
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
		
	build(1, 1, n);
	
	while(q --){
		
		cin >> op >> x >> y;
		
		if(op == 1){
			cin >> v;
			upd(1, 1, n, x, y, v);
		}
		
		if(op == 2)
			printf("%.4Lf\n", qry(1, 1, n, x, y, 1) / (y - x + 1));
		
		if(op == 3){
			double s = qry(1, 1, n, x, y, 1), t = qry(1, 1, n, x, y, 2);
			printf("%.4Lf\n", (t - s * s / (y - x + 1)) / (y - x + 1));
		}
		
	}
	
	return 0;
}*/

//D. 维护序列
/*#include<bits/stdc++.h>
using namespace std;

#define int long long
#define mid ((l + r) >> 1)
#define kl k << 1
#define kr (k << 1) | 1

const int N = 1e5 + 7;

int a[N], n, q, p, x, y, op, v;

struct node{
    int sum, mul, add;
    void tag(int a, int b, int l, int r){
        sum = (sum * a + b * (r - l + 1)) % p;
        (mul *= a) %= p;
        add = (add * a + b) % p;
    }
}T[N << 2];

void push_up(int k){
    T[k].sum = (T[kl].sum + T[kr].sum) % p;
}

void push_down(int k, int l, int r){
    T[kl].tag(T[k].mul, T[k].add, l, mid);
    T[kr].tag(T[k].mul, T[k].add, mid + 1, r);
    T[k].mul = 1, T[k].add = 0;
}

void build(int k, int l, int r){
    T[k].mul = 1;
    if(l == r){
        T[k].sum = a[l];
        return;
    }
    build(kl, l, mid);
    build(kr, mid + 1, r);
    push_up(k);
}

void upd(int k, int l, int r, int x, int y, int v1, int v2){
    if(l >= x && r <= y){
        T[k].tag(v1, v2, l, r);
        return;
    }
    push_down(k, l, r);
    if(mid >= x) upd(kl, l, mid, x, y, v1, v2);
    if(mid < y) upd(kr, mid + 1, r, x, y, v1, v2);
    push_up(k);
}

int qry(int k, int l, int r, int x, int y){
    if(l >= x && r <= y) return T[k].sum;
    int res = 0;
    push_down(k, l, r);
    if(mid >= x) res = qry(kl, l, mid, x, y);
    if(mid < y) res += qry(kr, mid + 1, r, x, y);
    return res % p;
}

signed main(){

    cin >> n >> p;

    for(int i = 1; i <= n; i ++)
        cin >> a[i];

    build(1, 1, n);

    cin >> q;

    while(q --){
        
        cin >> op >> x >> y;

        if(op != 3) cin >> v;

        if(op == 1) upd(1, 1, n, x, y, v, 0);

        if(op == 2) upd(1, 1, n, x, y, 1, v);

        if(op == 3) cout << qry(1, 1, n, x, y) << endl;
        
    }

    return 0;
}*/

//E. 打怪升级
/*#include<bits/stdc++.h>
using namespace std;

#define mid ((l + r) >> 1)
#define kl k << 1
#define kr (k << 1) | 1
#define se second
#define fi first
typedef pair <int, int> PI;

const int N = 1e4 + 7, M = 12, INF = 1e9;

int mx[M][N << 2], id[M][N << 2], add[M][N << 2];

void change(int lv, int k, int v){
    mx[lv][k] += v;
    add[lv][k] += v;
}

void push_up(int lv, int k){
    mx[lv][k] = max(mx[lv][kl], mx[lv][kr]);
    if(mx[lv][kl] == mx[lv][k]) id[lv][k] = id[lv][kl];
    if(mx[lv][kr] == mx[lv][k]) id[lv][k] = id[lv][kr];
}

void push_down(int lv, int k){
    if(!add[lv][k]) return;
    change(lv, kl, add[lv][k]);
    change(lv, kr, add[lv][k]);
    add[lv][k] = 0;
}

void build(int lv, int k, int l, int r){
    mx[lv][k] = (lv == 1) ? 0 : -INF;
    add[lv][k] = 0;
    if(l == r){
        id[lv][k] = l;
        add[lv][k] = 0;
        return;
    }
    build(lv, kl, l, mid);
    build(lv, kr, mid + 1, r);
    push_up(lv, k);
}

void upd(int lv, int k, int l, int r, int x, int y, int v, int op){
    if(l >= x && r <= y){
        if(op == 2) change(lv, k, v);
        else mx[lv][k] = v, add[lv][k] = v;
        return;
    }
    push_down(lv, k);
    if(mid >= x) upd(lv, kl, l, mid, x, y, v, op);
    if(mid < y) upd(lv, kr, mid + 1, r, x, y, v, op);
    push_up(lv, k);
}

PI qry(int lv, int k, int l, int r, int x, int y){
    if(l >= x && r <= y)
        return {mx[lv][k], id[lv][k]};
    push_down(lv, k);
    PI res = {-INF, 0};
    if(mid >= x) res = qry(lv, kl, l, mid, x, y);
    if(mid < y) res = max(res, qry(lv, kr, mid + 1, r, x, y));
    return res;
}

int nd[N];

int n, k, t, q, x, y, v;

char op;

int main(){

    cin >> t;

    for(int d = 1; d <= t; d ++){

        cin >> n >> k >> q;

        for(int i = 2; i <= k; i ++)
            cin >> nd[i];
        
        for(int i = 1; i <= k; i ++)
            build(i, 1, 1, n);
        
        nd[k + 1] = INF;
        
        cout << "Case " << d << ":\n";

        while(q --){

            cin >> op >> x >> y;

            if(op == 'W'){
                cin >> v;
                for(int i = 1; i <= k; i ++)
                    upd(i, 1, 1, n, x, y, v * i, 2);
                for(int i = k - 1; i; i --){
                    PI tmp = qry(i, 1, 1, n, x, y);
                    while(tmp.fi >= nd[i + 1]){
                        int idx = (upper_bound(nd + 1, nd + k + 2, tmp.fi) - nd) - 1;
                        upd(idx, 1, 1, n, tmp.se, tmp.se, tmp.fi, 1);
                        upd(i, 1, 1, n, tmp.se, tmp.se, -INF, 1);
                        tmp = qry(i, 1, 1, n, x, y);
                    }
                }
            }

            else {
                for(int i = k; i; i --){
                    int tmp = qry(i, 1, 1, n, x, y).fi;
                    if(tmp >= 0){
                        cout << tmp << endl;
                        break;
                    }
                }
            }

        }

        cout << "\n";

    }

    return 0;
}*/

//F. 化学实验
/*#include<bits/stdc++.h>
using namespace std;

#define int long long
#define mid ((l + r) >> 1)

const int N = 3e6 + 7, INF = 1e9;

struct node{
    int L = 0, R = 0, sum = 0, cnt = 0;
}T[N];

int n, q, op, x, v, tot, root;

map <int, int> pos;

void push_up(int k){
    T[k].sum = T[T[k].L].sum + T[T[k].R].sum;
    T[k].cnt = T[T[k].L].cnt + T[T[k].R].cnt;
}

void upd(int &k, int l, int r, int x, int v){
    if(!k) k = ++ tot;
    if(l == x && r == x){
        T[k].sum += v * x;
        T[k].cnt += v;
        return;
    }
    if(mid >= x) upd(T[k].L, l, mid, x, v);
    else upd(T[k].R, mid + 1, r, x, v);
    push_up(k);
}

node qry(int k, int l, int r, int x, int y){
    if(!k) return (node){0, 0, 0, 0};
    if(l >= x && r <= y)
        return T[k];
    node ll, rr;
    if(mid >= x) ll = qry(T[k].L, l, mid, x, y);
    if(mid < y) rr = qry(T[k].R, mid + 1, r, x, y);
    return (node){0, 0, ll.sum + rr.sum, ll.cnt + rr.cnt};
}

signed main(){

    cin >> n >> q;

    for(int i = 1; i <= n; i ++){
        cin >> x;
        upd(root, 0, INF, x, 1);
        pos[i] = x;
    }
    
    while(q --){

        cin >> op >> x;

        if(op == 1){
            cin >> v;
            upd(root, 0, INF, pos[x], -1);
            upd(root, 0, INF, v, 1);
            pos[x] = v;
        }

        else {
            int l = 0, r = INF;
            while(l + 1 < r){
                node tmp = qry(root, 0, INF, 0, mid);
                if(tmp.cnt * mid - tmp.sum >= x) r = mid;
                else l = mid;
            }
            node tmp = qry(root, 0, INF, 0, l);
            printf("%.5lf\n", 1.0 * (x - (l * tmp.cnt - tmp.sum)) / tmp.cnt + l);
        }

    }

    return 0;
}*/

//G. 平面染色统计
/*#include<bits/stdc++.h>
using namespace std;

#define mid ((l + r) >> 1)

const int N = 2e7 + 1, M = 50 + 7;

int op, x, y, yy, v, tot;

int root[M], n = 1e6, m = 50;

struct str{
    int L, R, mn;
}T[N ];

void prep(){
    for(int i = 1; i <= tot; i ++)
        T[i].L = T[i].R = 0;
    for(int i = 0; i <= m; i ++)
        root[i] = 0;
    tot = 0;
}

void upd(int &k, int l, int r, int x, int v){
    int tmp = k;
    if(!k) k = ++ tot;
    if(l == x && r == x){
        if(!tmp) T[k].mn = v;
        else T[k].mn = min(T[k].mn, v);
        return;
    }
    if(mid >= x) upd(T[k].L, l, mid, x, v);
    else upd(T[k].R, mid + 1, r, x, v);
    T[k].mn = min(T[T[k].L].mn, T[T[k].R].mn);
}

int qry(int k, int l, int r, int x, int y){
    if(!k) return 1e9;
    if(l >= x && r <= y) return T[k].mn;
    int res = 1e9;
    if(mid >= x) res = qry(T[k].L, l, mid, x, y);
    if(mid < y) res = min(res, qry(T[k].R, mid + 1, r, x, y));
    return res;
}

int main(){

    T[0].mn = 1e9;

    while(scanf("%d", &op) && op != 3){

        if(!op)
            prep();

        if(op == 1){
            scanf("%d %d %d", &x, &y, &v);
            upd(root[v], 1, n, y, x);
        }

        if(op == 2){
            scanf("%d %d %d", &x, &y, &yy);
            int res = 0;
            for(int i = 0; i <= m; i ++){
                int tmp = qry(root[i], 1, n, y, yy);
                if(tmp <= x) res ++;
            }
            printf("%d\n", res);
        }

    }

    return 0;
}*/

//H. 子树中的最多颜色
/*#include<bits/stdc++.h>
using namespace std;

#define int long long
#define mid ((l + r) >> 1)

const int N = 1e5 + 7, M = 1e7;

struct str{
    int L, R, cnt, sum;
}T[M];

vector <int> a[N];

int c[N], n, x, y, tot;

int root[N];

void push_up(int k){
    T[k].cnt = max(T[T[k].L].cnt, T[T[k].R].cnt);
    T[k].sum = 0;
    if(T[T[k].L].cnt == T[k].cnt) T[k].sum += T[T[k].L].sum;
    if(T[T[k].R].cnt == T[k].cnt) T[k].sum += T[T[k].R].sum;
}

void upd(int &k, int l, int r, int x){
    if(!k) k = ++ tot;
    if(l == x && r == x){
        T[k].cnt = 1;
        T[k].sum = x;
        return;
    }
    if(mid >= x) upd(T[k].L, l, mid, x);
    else upd(T[k].R, mid + 1, r, x);
    push_up(k);
}

int merge(int x, int y, int l, int r){
    if(!x) return y;
    if(!y) return x;
    int k = ++ tot;
    if(l == r){
        T[k].sum = T[x].sum;
        T[k].cnt = T[x].cnt + T[y].cnt;
        return k;
    }
    T[k].L = merge(T[x].L, T[y].L, l, mid);
    T[k].R = merge(T[x].R, T[y].R, mid + 1, r);
    push_up(k);
    return k;
}

void dfs(int x, int fa){
    upd(root[x], 1, n, c[x]);
    for(int to : a[x]){
        if(to == fa) continue;
        dfs(to, x);
        root[x] = merge(root[x], root[to], 1, n);
    }
}

signed main(){

    cin >> n;

    for(int i = 1; i <= n; i ++)
        cin >> c[i];

    for(int i = 1; i < n; i ++){
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    
    dfs(1, 0);

    for(int i = 1; i <= n; i ++)
        cout << T[root[i]].sum << ' ';
    cout << endl;

    return 0;
}*/

//J. 区间第K值
/*#include<bits/stdc++.h>
using namespace std;

#define int long long
#define mid ((l + r) >> 1)
#define kl T[k].L
#define kr T[k].R

const int N = 3e4 + 7, INF = (1ll << 31) - 1;

struct str{
    int sum, L, R;
}T[N * 40];

int n, q, x, y, v;

int rt[N], tot;

void push_up(int k){
    T[k].sum = T[kl].sum + T[kr].sum;
}

int upd(int &k, int lst, int l, int r, int x){
    k = ++ tot;
    if(l == x && r == x){
        T[k].sum = T[lst].sum + 1;
        return k;
    }
    T[k] = T[lst];
    if(mid >= x) kl = upd(kl, T[lst].L, l, mid, x);
    else kr = upd(kr, T[lst].R, mid + 1, r, x);
    push_up(k);
    return k;
}

int qry(int now, int lst, int l, int r, int x){
    if(l == r) return l;
    int difl = T[T[now].L].sum - T[T[lst].L].sum;
    if(difl >= x) return qry(T[now].L, T[lst].L, l, mid, x);
    else return qry(T[now].R, T[lst].R, mid + 1, r, x - difl);
}

signed main(){

    cin >> n >> q;

    for(int i = 1; i <= n; i ++){
        cin >> x;
        rt[i] = upd(rt[i], rt[i - 1], 1, INF, x);
    }
    
    while(q --){
        cin >> x >> y >> v;
        cout << qry(rt[y], rt[x - 1], 1, INF, (y - x + 1) - v + 1) << endl;
    }

    return 0;
}*/

//L. 排序
/*#include<bits/stdc++.h>
using namespace std;

#define mid ((l + r) >> 1)
#define kl k << 1
#define kr (k << 1) | 1

const int N = 2e5 + 7;

int val[N << 2], tag[N << 2];

int a[N], L[N], R[N], op[N];

int n, m, pos;

void push_up(int k){
    val[k] = val[kl] + val[kr];
}

void change(int k, int l, int r, int v){
    val[k] = v * (r - l + 1);
    tag[k] = v;
}

void push_down(int k, int l, int r){
    if(tag[k] == -1) return;
    change(kl, l, mid, tag[k]);
    change(kr, mid + 1, r, tag[k]);
    tag[k] = -1;
}

void build(int k, int l, int r, int x){
    tag[k] = -1;
    if(l == r){ 
        val[k] = (a[l] >= x);
        return;
    }
    build(kl, l, mid, x);
    build(kr, mid + 1, r, x);
    push_up(k);
}

int qry(int k, int l, int r, int x, int y){
    if(x > y) return 0;
    if(l >= x && r <= y) return val[k];
    push_down(k, l, r);
    int res = 0;
    if(mid >= x) res = qry(kl, l, mid, x, y);
    if(mid < y) res += qry(kr, mid + 1, r, x, y);
    return res;
}

void upd(int k, int l, int r, int x, int y, int v){
    if(x > y) return;
    if(l >= x && r <= y){
        change(k, l, r, v);
        return;
    }
    push_down(k, l, r);
    if(mid >= x) upd(kl, l, mid, x, y, v);
    if(mid < y) upd(kr, mid + 1, r, x, y, v);
    push_up(k);
}

bool check(int x){

    build(1, 1, n, x);
    
    for(int i = 1; i <= m; i ++){
        int cnt = qry(1, 1, n, L[i], R[i]);
        if(!op[i]){
            upd(1, 1, n, L[i], R[i] - cnt, 0);
            upd(1, 1, n, R[i] - cnt + 1, R[i], 1);
        }
        else {
            upd(1, 1, n, L[i], L[i] + cnt - 1, 1);
            upd(1, 1, n, L[i] + cnt, R[i], 0);
        }
    }

    return qry(1, 1, n, pos, pos) == 1;

}

int main(){

    cin >> n >> m;

    for(int i = 1; i <= n; i ++)
        cin >> a[i];

    for(int i = 1; i <= m; i ++){
        cin >> op[i] >> L[i] >> R[i];
    }

    cin >> pos;

    int l = 0, r = n + 1;

    while(l + 1 < r){
        
        if(check(mid)) l = mid; // 如果大于等于 mid 是可行的
        else r = mid;
    }

    cout << l << endl;

    return 0;
}*/
