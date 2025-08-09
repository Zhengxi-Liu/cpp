/*#include<bits/stdc++.h>
using namespace std;

#define mid ((l + r) >> 1)

const int N = 1e5 + 7, LL = -1e9, RR = 1e9;

int p[N], n, m, t;

int sum[N << 2], L[N << 2], R[N << 2];

int tot, rt, mk[N];

struct str{
    int l, r, t;
}a[N];

bool cmp(str a, str b){
    return a.l < b.l;
}

void upd(int &k, int l, int r, int x, int v){
    if(!k) k = ++ tot;
    if(l == r){
        sum[k] += v;
        return;
    }
    if(mid >= x) upd(L[k], l, mid, x, v);
    else upd(R[k], mid + 1, r, x, v);
    sum[k] = sum[L[k]] + sum[R[k]];
}

int qry(int k, int l, int r, int x, int y){
    if(!k) return 0;
    if(l >= x && r <= y) return sum[k];
    int res = 0;
    if(mid >= x) res = qry(L[k], l, mid, x, y);
    if(mid < y) res += qry(R[k], mid + 1, r, x, y);
    return res;
}


int main(){

    cin >> t;

    while(t --){

        cin >> n >> m;

        memset(sum, 0, sizeof(sum));
        memset(L, 0, sizeof(L));
        memset(R, 0, sizeof(R));
        memset(mk, 0, sizeof(mk));
        rt = 0;
        tot = 0;

        for(int i = 1; i <= n; i ++){
            cin >> p[i];
            upd(rt, LL, RR, p[i], 1);
        }

        sort(p + 1, p + n + 1);

        for(int i = 1; i <= m; i ++)
            cin >> a[i].l >> a[i].r >> a[i].t;
        
        sort(a + 1, a + m + 1, cmp);

        int ans = 0;

        //cout << qry(rt, LL, RR, LL, RR) << endl;

        for(int i = 1; i <= n; i ++)
            cout << p[i] << ' ';
        cout << endl;

        a[m + 1].l = RR + 1;

        int now = 1;

        for(int i = 1; i <= m; i ++){
            cout << a[i].l << ' ' << a[i].r << ' ' << a[i].t << ": ";
            while(true){
                int tmp = qry(rt, LL, RR, a[i].l, a[i].r);
                if(tmp <= a[i].t) break;
                int k = lower_bound(p + now, p + n + 1, a[i].l) - p;
                if(p[k] >= a[i + 1].l) break;
                mk[now] ++;
                mk[k] --;
                cout << tmp << ' ' << k << " / ";
                //cout << "*";
                now = k + 1;
                //ans ++;
                upd(rt, LL, RR, p[k], -1);
            }
            cout << endl;
        }

        if(now <= n){
            mk[now] ++;
            mk[a[m].r] --;
        }
        // 不能砍的都 mark 成 1
        for(int i = 1; i <= n; i ++){
            mk[i] += mk[i - 1];
            if(!mk[i]) ans ++;
            cout << mk[i] << ' ';
        }
        cout << endl;

        cout << ans << endl;

    }




    return 0;
}*/


#include<bits/stdc++.h>
using namespace std;

#define mid ((l + r) >> 1)

const int N = 1e5 + 7;

int p[N], n, m, t;

struct str{
    int l, r, t;
}a[N];

bool cmp(str a, str b){
    return a.l < b.l;
}

multiset <str> idx, val;

int main(){

    cin >> t;

    while(t --){

        cin >> n >> m;

        for(int i = 1; i <= n; i ++)
            cin >> p[i];

        sort(p + 1, p + n + 1);

        for(int i = 1; i <= m; i ++)
            cin >> a[i].l >> a[i].r >> a[i].t;

        sort(a + 1, a + m + 1, cmp);

        for(int i = 1; i <= m; i ++){

        }

    }

    return 0;
}