// P11232 [CSP-S 2024] 超速检测
/*#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 7;

int d[N], v[N], a[N], l[N], r[N], ans[N], ans2[N], k;

double p[N];

int n, m, t, L, V;

double posit(double v0, double a, double t){
    return v0 * t + 0.5 * a * t * t;
}

void range(int d, int v, int a, int cnt){
    if(a < 0){
        if(v <= V)
            l[cnt] = r[cnt] = -1;
        else {
            double ed = posit(1.0 * v, 1.0 * a, 1.0 * (V - v) / a) + d;
            l[cnt] = lower_bound(p + 1, p + m + 2, d) - p;
            r[cnt] = (lower_bound(p + 1, p + m + 2, ed) - p) - 1;
            if(ed > L)
                r[cnt] = m;
        }
    }
    if(a > 0){
        double st;
        if(v > V)
            st = d;
        else
            st = posit(v, a, 1.0 * (V - v) / a) + d;
        //cout << st << ' ' << L << endl;
        if(st > L)
            l[cnt] = r[cnt] = -1;
        else 
            l[cnt] = upper_bound(p + 1, p + m + 2, st) - p, r[cnt] = m;
    }
    if(!a){
        if(v > V)
            l[cnt] = lower_bound(p + 1, p + m + 2, d) - p, r[cnt] = m;
        else 
            l[cnt] = r[cnt] = -1;
    }
    if(l[cnt] > r[cnt] || l[cnt] > m || r[cnt] > m){
        l[cnt] = r[cnt] = -1;
    }
}

void init(){
    memset(d, 0, sizeof(d));
    memset(v, 0, sizeof(v));
    memset(a, 0, sizeof(a));
    memset(l, 0, sizeof(l));
    memset(r, 0, sizeof(r));
    memset(p, 0, sizeof(p));
}

struct str{
    int l, r;
}b[N];

bool cmp(str a, str b){
    return a.l < b.l;
}

signed main(){

    cin >> t;

    while(t --){
        init();
        cin >> n >> m >> L >> V;

        for(int i = 1;i <= n;i ++)
            cin >> d[i] >> v[i] >> a[i];

        for(int i = 1;i <= m;i ++)
            cin >> p[i];
        
        sort(p + 1, p + m + 1);
         
        p[m + 1] = 0x3f3f3f3f;

        for(int i = 1;i <= n;i ++)
            range(d[i], v[i], a[i], i);
        k ++;
        for(int i = 1;i <= n;i ++){
            // cout << l[i] << ' ' << r[i] << endl;
            if(l[i] != -1 && r[i] != -1)
                ans[k] ++;   
            b[i].l = l[i], b[i].r = r[i];
        }
        sort(b + 1, b + n + 1, cmp);
        int x, y = -1;
        for(int i = 1;i <= n;i ++){
            if(b[i].l > y){
                x = b[i].l;
                y = b[i].r;
                ans2[k] ++;
            }
            else {
                y = min(y, b[i].r);
            }
            //cout << b[i].l << ' ' << b[i].r << ' ' << x << ' ' << y << endl;
        }
        ans2[k] = m - ans2[k];
    }
    for(int i = 1;i <= k;i ++)
        cout << ans[i] << ' ' << ans2[i] << endl;
    return 0;
}*/

// P11233 [CSP-S 2024] 染色
/*#include<bits/stdc++.h>
using namespace std;

#define int long long
#define mid ((l + r) >> 1)
#define kl (k << 1)
#define kr ((k << 1) | 1)

const int N = 1e6 + 7;

int mx[N << 2], tag[N << 2];

void change(int k, int op, int v){ // 1: 单点更新最大值; 2: 区间加
    if(op == 1) mx[k] = max(mx[k], v);
    else {
        mx[k] += v;
        tag[k] += v;
    }
}

void push_down(int k){
    if(!tag[k]) return;
    change(kl, 2, tag[k]);
    change(kr, 2, tag[k]);
    tag[k] = 0;
}

void upd(int k, int l, int r, int x, int y, int op, int v){
    if(l >= x && r <= y){
        change(k, op, v);
        return;
    }
    push_down(k);
    if(mid >= x) upd(kl, l, mid, x, y, op, v);
    if(mid < y) upd(kr, mid + 1, r, x, y, op, v);
    mx[k] = max(mx[kl], mx[kr]);
}

int qry(int k, int l, int r, int x, int y){
    if(l >= x && r <= y) return mx[k];
    push_down(k);
    int res = 0;
    if(mid >= x) res = qry(kl, l, mid, x, y);
    if(mid < y) res = max(res, qry(kr, mid + 1, r, x, y));
    return res;
}

int a[N], b[N], lst[N], n, t;

signed main(){

    cin >> t;
    
    while(t --){

        cin >> n;

        int m = 0;

        for(int i = 1; i <= n; i ++)
            scanf("%lld", &a[i]), m = max(m, a[i]);

        memset(mx, 0, sizeof(mx));
        memset(tag, 0, sizeof(tag));
        memset(b, 0, sizeof(b));

        for(int i = 1; i <= n; i ++){
            lst[i] = b[a[i]];
            b[a[i]] = i;
        }

        for(int i = 2; i <= n; i ++){

            int d1 = qry(1, 1, m, 1, m), d2 = qry(1, 1, m, a[i], a[i]);
            
            if(a[i] == a[i - 1]) upd(1, 1, m, 1, m, 2, a[i]);
            if(lst[i]) upd(1, 1, m, a[i - 1], a[i - 1], 1, max(d1, d2 + a[i]));
            else upd(1, 1, m, a[i - 1], a[i - 1], 1, d1);

        }

        cout << qry(1, 1, m, 1, m) << endl;

    }

    return 0;
}*/
