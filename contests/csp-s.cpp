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
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e3 + 7;
int a[N], dp1[N][N], dp2[N][N]; // 上一个染的是红, dp1[当前 i][上一个染蓝的 j]; 上一个染的是蓝, dp2[当前 i][上一个染红的 j].
int n, t, ans;
int score(int x, int y){
    if(x == y)
        return x;
    return 0;
}
signed main(){
    cin >> t;
    while(t --){
        cin >> n;
        for(int i = 1; i <= n; i ++){
            cin >> a[i];
        }
        memset(dp1, 0, sizeof(dp1));
        memset(dp2, 0, sizeof(dp2));
        ans = 0;
        for(int i = 1; i <= n; i ++){
            for(int j = 0; j <= i - 2; j ++){
                dp1[i][j] = dp1[i - 1][j] + score(a[i - 1], a[i]);
                dp1[i][i - 1] = max(dp1[i][i - 1], dp2[i - 1][j] + score(a[j], a[i]));
                dp2[i][j] = dp2[i - 1][j] + score(a[i - 1], a[i]);
                dp2[i][i - 1] = max(dp2[i][i - 1], dp1[i - 1][j] + score(a[j], a[i]));
            }
            for(int j = 0; j < i; j ++)
                ans = max(ans, max(dp1[i][j], dp2[i][j]));
        }
        cout << ans << endl;
    }
    return 0;
}
