/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
double v, theta, x, y, t, ay = -9.80665;
int main(){
    cin >> v >> theta >> x >> y >> t;
    double vx = v * cos(theta), vy = v * sin(theta);
    cout << vx << ' ';
    for(int i = 1;i <= t;i ++){
        x = x + vx;

    }
    cout << x << endl;
    // double vx = v * cos(theta), vy = v * sin(theta);
    // double xf = x + vx * t, ay = -9.80665;
    // double vyf = vy + ay * t;
    // double yf = y + ay * 0.5 * t * t + y * t;
    //cout << xf << ' ' << xf << endl;
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
#define int long long
struct str{
    int to, last;
}a[N];
int pre[N], n, x, y, z, k, dep[N], vis[N], ans = 0;
map <int, int> mp[N];
void add(int x, int y){
    a[++ k].to = y;
    a[k].last = pre[x];
    pre[x] = k;
}
void dfs(int p, int f){
    dep[p] = dep[f] + 1;
    vis[p] = 1;
    for(int i = pre[p];i;i = a[i].last){
        int to = a[i].to;
        if(to != f && !vis[to]){
            dfs(to, p);
        }
    }
}
signed main(){
    scanf("%lld", &n);
    for(int i = 1;i < n;i ++){
        scanf("%lld %lld", &x, &y);
        if(mp[x].count(y))
            continue;
        mp[x][y] = 1;
        mp[y][x] = 1;
        add(x, y);
        add(y, x);
    }
    dfs(1, 0);
    x = 0;
    for(int i = 1;i <= n;i ++){
        if(dep[i] > dep[x])
            x = i;
    }
    memset(dep, 0, sizeof(dep));
    memset(vis, 0, sizeof(vis));
    dfs(x, 0);
    for(int i = 1;i <= n;i ++)
        ans = max(ans, dep[i]);
    cout << ans - 1 << endl;
    return 0;
}*/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
#define int long long
int a[N], d[N], b[N], s[N];
int n, x, k, cnt, ans;
signed main(){
    cin >> n >> x;
    for(int i = 1;i <= n;i ++){
        cin >> a[i] >> d[i] >> b[i];
        s[++ k] = a[i];
        for(int j = 2;j <= b[i];j ++){
            ++ k;
            s[k] = s[k - 1] + d[i];
        }
    }
    sort(s + 1, s + k + 1);
    for(int i = 1;i <= k;i ++){
        if(s[i] + cnt <= x)
            ans ++;
        else
            break;
        cnt += s[i];
    }
    cout << ans << ' ' << cnt << endl;
    return 0;
}