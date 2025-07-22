//t1
/*#include <bits/stdc++.h>
using namespace std;
int n, cnt, x = 6, y = 10, z = 15;
int main() {
    cin >> n;
    for (int i = 10; i <= n + 9; i++) {
        if (i % 3 == 0)
            cout << x * i << endl;
        else if (i % 3 == 1)
            cout << y * i << endl;
        else
            cout << z * i << endl;
    }
    return 0;
}
*/

//t2
/*#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

int x[N], y[N], last[N], n;

int main(){

    cin >> n;

    for(int i = 1; i <= n; i ++){
        cin >> x[i] >> y[i];
        int ans = 0;
        for(int j = 1; j * j <= x[i]; j ++){
            if(x[i] % j != 0)
                continue;
            if(last[j] < i - y[i])
                ans ++;
            if(last[x[i] / j] < i - y[i] && j * j != x[i])
                ans ++;
            last[j] = last[x[i] / j] = i;
        }
        cout << ans << endl;
    }

    return 0;
}*/

//t3
/*#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mid ((l + r) >> 1)
const int N = 3e5 * 4 + 7;
bool prime[N];
int sum[N], vis[N], a[N];
int n, q, op, l, r;
void push_up(int k){
    sum[k] = sum[k * 2] + sum[k * 2 + 1];
    vis[k] = vis[k * 2] & vis[k * 2 + 1]; 
}
void build(int k, int l, int r){
    if(l == r){
        sum[k] = a[l];
        return;
    }
    build(k * 2, l, mid);
    build(k * 2 + 1, mid + 1, r);
    push_up(k);
}
int change(int x){
    int ret = 0;
    for(int i = 1; i * i <= x; i ++)
        if(x % i == 0){
            ret += 2;
            if(i * i == x)
                ret --;
        }
    return ret;
}
void update(int k, int l, int r, int x, int y){
    if(vis[k])
        return;
    if(l == r){
        sum[k] = change(sum[k]);
        if(sum[k] <= 2)
            vis[k] = 1;
        return;
    }
    if(mid >= x)
        update(k * 2, l, mid, x, y);
    if(mid < y)
        update(k * 2 + 1, mid + 1, r, x, y);
    push_up(k);
}
int query(int k, int l, int r, int x, int y){
    if(l >= x && r <= y)
        return sum[k];
    int ret = 0;
    if(mid >= x)
        ret = query(k * 2, l, mid, x, y);
    if(mid < y)
        ret += query(k * 2 + 1, mid + 1, r, x, y);
    return ret; 
}
signed main(){

    scanf("%lld %lld", &n, &q);
    for(int i = 1; i <= n; i ++)
        scanf("%lld", &a[i]);
    build(1, 1, n);
    while(q --){
        scanf("%lld %lld %lld", &op, &l, &r);
        if(op == 1)
            update(1, 1, n, l, r);
        else
            printf("%lld\n", query(1, 1, n, l, r));
    }
    return 0;
}*/

//t4
/*#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 7, MOD = 1e9 + 7;
map <int, int> mp[N];
vector <int> a[N];
int x[N], n, ans, u, v;

int gcd(int x, int y){
    while(y){
        int t = x % y;
        x = y;
        y = t;
    }
    return x;
}

void dfs(int p){
    mp[p][x[p]] ++;
    for(auto g : mp[p])
        ans += g.first * g.second, ans %= MOD;
    for(int i = 0; i < a[p].size(); i ++){
        int to = a[p][i];
        for(auto g : mp[p]){
            int tmp = gcd(x[to], g.first);
            mp[to][tmp] += g.second;
        }
        dfs(to);
    }
}

signed main(){
    
    cin >> n;

    for(int i = 1; i <= n; i ++)
        cin >> x[i];

    for(int i = 1; i < n; i ++){
        cin >> u >> v;
        a[u].push_back(v);
    }

    dfs(1);
    cout << ans << endl;

    return 0;
}*/

//t5
/*#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e5 + 7;

int a[N], b[N], n, p, t;

typedef pair <int, int> PI;

priority_queue < PI, vector <PI>, greater <PI> > q;

signed main(){

    scanf("%lld", &t);
    
    while(t --){
        scanf("%lld %lld", &n, &p);

        for(int i = 1; i <= n; i ++){
            scanf("%lld", &a[i]);
            q.push({a[i], i});
        }

        int ans = 0, len = 0;
        while(!q.empty()){
            int v = q.top().first, idx = q.top().second;
            q.pop();
            if(v >= p)
                break;
            int l = idx, r = idx;
            b[idx] = 1;
            while(-- l >= 1 && a[l] >= v && a[l] % v == 0 && !b[l])
                ans += v, len ++, b[l] = 1;
            while(++ r <= n && a[r] >= v && a[r] % v == 0 && !b[r])
                ans += v, len ++, b[r] = 1;
            
        }
        printf("%lld\n", ans + (n - len - 1) * p);

        for(int i = 1; i <= n; i ++)
            b[i] = 0;

    }

    return 0;
}*/

//t6
/*#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 3e5 + 7;

int n, p, k, x, ans;

map <int, int> mp;

signed main(){

    cin >> n >> p >> k;

    for(int i = 1; i <= n; i ++){
        cin >> x;
        mp[((x * x % p * x % p * x % p - k * x % p) + p) % p] ++;
    }

    for(auto x : mp){
        ans += x.second * (x.second - 1) / 2;
    }

    cout << ans << endl;

    return 0;
}*/

//t7
/*#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e5 + 7, INF = LLONG_MAX;

int a[N], n, ans = INF;

map <int, bool> vis;

void calc(int x){
    for(int j = 2; j * j <= x; j ++)
        while(x % j == 0)
            vis[j] = true, x /= j;
    if(x > 1)
        vis[x] = true;
}

signed main(){

    cin >> n;

    for(int i = 1; i <= n; i ++){
        cin >> a[i];
    }

    for(int i = 1; i <= min(n, 50ll); i ++){
        calc(a[i] - 1);
        calc(a[i]);
        if(a[i] > 1)
            calc(a[i] + 1);
    }

    for(auto x : vis){
        int sum = 0;
        for(int i = 1; i <= n; i ++){
            if(a[i] < x.first)
                sum += x.first - a[i];
            else
                sum += min(a[i] % x.first, x.first - a[i] % x.first);
        }
        ans = min(ans, sum);
    }
    
    cout << ans << endl;

    return 0;
}*/
