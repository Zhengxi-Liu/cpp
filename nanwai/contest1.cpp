/*#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;
bool f[N];
int n;

int main(){

    cin >> n;

    f[1] = true;
    for(int i = 2; i < N; i ++){
        if(f[i] == true)
            continue;
        for(int j = i * 2; j < N; j += i)
            f[j] = true;
    }
    for(int i = n; ; i ++){
        //cout << i << ' ';
        if(f[i] == false){
            cout << i << endl;
            break;
        }
    }
    return 0;
}*/

/*#include<bits/stdc++.h>
using namespace std;

int x = 1, y = 0, n, cnt;

int gcd(int a, int b) {
    if (b == 0) return a;
    cnt ++;
    return gcd(b, a%b);
}

int main(){

    cin >> n;
    if(n == 1){ 
        cout << 1 << ' ' << 1 << endl;
        return 0;
    }
    for(int i = 1; i <= n + 1; i ++){
        int t = x;
        x = y + x;
        y = t;
    }
    cout << x << ' ' << y << endl;
    //gcd(x, y);
    //cout << cnt << endl;
    return 0;
}*/

/*#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, m, x, a, b;
signed main(){
    cin >> n >> m;
    if(1.0 * n * n < m){
        cout << -1 << endl;
        return 0;
    }
    int ans = LLONG_MAX;
    int maxn = ceil(sqrt(1.0 * m));
    for(int i = 1; i <= maxn; i ++){
        int tmp = (m + i - 1) / i;
        if(tmp <= n)
            ans = min(ans, tmp * i);
    }
    cout << ans << endl;
    return 0;
}*/

/*#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e2 + 7, INF = 1e9 + 1;
int C[N][N], n, m, k, maxn;
signed main(){
    
    cin >> n >> m >> k;
    maxn = n + m;
    for(int i = 0; i <= maxn; i ++){
        C[i][0] = 1;
        for(int j = 1; j <= i; j ++){
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
            if(C[i][j] >= INF)
                C[i][j] = INF;
        }
    }
    int x = 0, y = 0;
    if(C[maxn][n] != INF && k > C[maxn][n]){
        cout << endl;
        return 0;
    }
    for(int i = 1; i <= maxn; i ++){
        int lx = n - x, ly = m - y, remain = maxn - i + 1;
        //如果第 i 个选 a
        if(lx && (C[remain - 1][lx - 1] == INF || C[remain - 1][lx - 1] >= k)){
            x += 1;
            cout << 'a';
        }
        //如果第 i 个选 z
        else {
            y += 1;
            cout << 'z';
            k -= C[remain - 1][lx - 1];
        }
    }
    cout << endl;
    return 0;
}*/

/*#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, x;
    cin >> x;
    for(int i = 1; i <= 4; i ++){
        cin >> n;
        for(int j = 1; j <= n; j ++)
            cin >> x;
    }
    cout << "Solution exists" << endl;
    return 0;
}*/

/*#include<iostream>
using namespace std;

#define int long long

const int N = 350 + 7;

int cnt[N][N], c[N];

int n, m, seed, thr, ans;

bool a[N][N], b[N];

signed main(){

    cin >> n >> m >> seed >> thr;

    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            seed = (seed * 25173 + 13849) % 65536;
            a[i][j] = seed < thr;
            cnt[i][j] = cnt[i - 1][j] + a[i][j];
            //cout << a[i][j] << ' ';
        }
        //cout << endl;
    }

    for(int x1 = 1; x1 <= n - 2; x1 ++)
        for(int x2 = x1 + 2; x2 <= n; x2 ++){
            for(int j = 1; j <= m; j ++){
                b[j] = (cnt[x2][j] - cnt[x1 - 1][j]) == (x2 - x1 + 1);
                c[j] = c[j - 1] + b[j];
            }
            for(int j = m, nxt = m; j; j --){
                while(nxt >= j && (!a[x1][j] || !a[x2][j]))
                    nxt --;
                if(b[j] && nxt >= j + 1)
                    ans += c[nxt] - c[j + 1];
            }
        }
    cout << ans << endl;

    return 0;
}*/

#include<bits/stdc++.h>
using namespace std;

const int N = 5e2 + 7;

int a[N], b[N], g[N], l[N], vis[N];

int c[N], id[N], n, cnt, ans, f, m;

vector <int> edge[N], gcd[N], lcm[N];

void read(){
    cin >> m >> n;
    for(int i = 1; i <= n; i ++)
        cin >> a[i], a[i] ++;
    cin >> n;
    for(int i = 1; i <= n; i ++)
        cin >> b[i], b[i] ++;
    cin >> n;
    for(int i = 1; i <= n; i ++)
        cin >> g[i];
    cin >> n;
    for(int i = 1; i <= n; i ++)
        cin >> l[i];
}

int GCD(int x, int y){
    while(y){
        int tmp = x % y;
        x = y;
        y = tmp;
    }
    return x;
}

void dfs(int x, int fa, int v){
    id[x] = cnt;
    vis[x] = v;
    //cout << v << ' ';
    for(int i = 0; i < edge[x].size(); i ++){
        int to = edge[x][i];
        int mul = gcd[x][i] * lcm[x][i], nv = mul / v;
        if(vis[to])
            nv = vis[to];
        if(GCD(nv, v) != gcd[x][i] || v * nv / GCD(nv, v) != lcm[x][i]){
            f = 1;
            return;
        }
        if(to != fa && !vis[to])
            dfs(to, x, nv);
    }
}

int main(){

    read();

    for(int i = 1; i <= n; i ++){
        //cout << a[i] << ' ' << b[i] << " // ";
        edge[b[i]].push_back(a[i]), edge[a[i]].push_back(b[i]);
        c[a[i]] = g[i] * l[i], c[b[i]] = g[i] * l[i];
        gcd[a[i]].push_back(g[i]), gcd[b[i]].push_back(g[i]);
        lcm[a[i]].push_back(l[i]), lcm[b[i]].push_back(l[i]);
    }

    // cout << endl << endl;
    // for(int i = 1; i <= m; i ++){
    //     for(int j = 0; j < edge[i].size(); j ++)
    //         cout << edge[i][j] << ' ' << gcd[i][j] << " // ";
    //     cout << endl;
    // }
    for(int i = 1; i <= m; i ++)
        if(!id[i]){
            cnt ++;
            bool tmp = false;
            //cout << c[i] << " // \n";
            if(!c[i]){
                ans ++;
                continue;
            }
            for(int j = 1; j * j <= c[i]; j ++)
                if(c[i] % j == 0){
                    f = 0, memset(vis, 0, sizeof(vis));
                    dfs(i, 0, j);
                    if(!f) tmp = true;
                    //cout << " // ";
                    f = 0, memset(vis, 0, sizeof(vis));
                    dfs(i, 0, c[i] / j);
                    if(!f) tmp = true;
                    //cout << j << "\n";
                }
            if(tmp) ans ++;
            //cout << endl;
        }
    //cout << ans << endl << cnt << endl;
    if(ans != cnt)
        cout << "Solution does not exist" << endl;
    else
        cout << "Solution exists" << endl;
    
    return 0;
}