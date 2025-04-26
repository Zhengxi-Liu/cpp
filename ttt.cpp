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
const int N = 2e5 + 7;
long long t, a[N], n, maxn, minn = 1e9, cnt1, cnt2;
int main(){
    cin >> t;
    while(t --){
        cin >> n;
        maxn = -1, minn = 1e12;
        cnt1 = cnt2 = 0;
        for(int i = 1;i <= n;i ++){
            cin >> a[i];
            maxn = max(maxn, a[i]);
            minn = min(minn, a[i]);
        }
        for(int i = 1;i <= n;i ++){
            if(a[i] == maxn)
                cnt1 ++;
            if(a[i] == minn)
                cnt2 ++;
        }
        if(maxn == minn)
            cout << n * (n - 1) << endl;
        else
            cout << cnt1 * cnt2 * 2 << endl;
    }
    return 0;
}