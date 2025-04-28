/*#include<iostream>
using namespace std;
const int N = 2e6 + 7;
int st[N][21], lg[N], n, m, l, r;
int main(){
    scanf("%d %d", &n, &m);
    lg[0] = -1;
    for(int i = 1;i <= n;i ++){
        scanf("%d", &st[i][0]);
        lg[i] = lg[i / 2] + 1;
    }
    for(int j = 1;j <= lg[n];j ++)
        for(int i = 1;i + (1 << j) - 1 <= n;i ++)
            st[i][j] = max(st[i][j - 1], st[i + (1 << j - 1)][j - 1]);
    while(m --){
        scanf("%d %d", &l, &r);
        int lgg = lg[r - l + 1];
        printf("%d\n", max(st[l][lgg], st[r - (1 << lgg) + 1][lgg]));
    }
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 8e2 + 7;
#define int long long
int a[N][N], n, k, dis[N][N];
bool OK(int x){
    memset(dis, 0, sizeof(dis));
    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= n;j ++){
            int y = 0;
            if(a[i][j] <= x)
                y = 1;
            if(a[i][j] > x)
                y = -1;
            dis[i][j] = dis[i - 1][j] + dis[i][j - 1] - dis[i - 1][j - 1] + y;
        }
    for(int i = k;i <= n;i ++){
        for(int j = k;j <= n;j ++){
            int t = dis[i][j] - dis[i - k][j] - dis[i][j - k] + dis[i - k][j - k];
            if(t >= 0)
                return true;
        }
    }
    return false;
}
signed main(){
    cin >> n >> k;
    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= n;j ++)
            cin >> a[i][j];
    int l = 0, r = 1e9;
    int ans=(int)1e9;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(OK(mid))
            r = mid-1, ans=mid;
        else
            l = mid+1;
    }
    cout << ans << endl;
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 7;
struct str{
    int s, v;
}a[N];
int v[N], sum[N], vis[N], to[N];
int n, x, y, ans, l, r;
map <int, int> mp;
void dfs(int k, int cnt){
    int ln = -1, rn = -1;
    bool flag = false;
    vis[k] = cnt;
    if(x - v[k] >= 0 && mp.count(x - v[k]))
        ln = mp[x - v[k]];
    if(y - v[k] >= 0 && mp.count(y - v[k]))
        rn = mp[y - v[k]];
    if(ln != -1 && !vis[ln]){
        flag = true;
        dfs(ln, cnt);
    }
    if(rn != -1 && !vis[rn]){
        flag = true;
        dfs(rn, cnt);
    }
    if(!flag){
        if(!l)
            l = k;
        else
            r = k;
    }
}
void find(int k){
    l = 0;
    r = k;
    dfs(k, k);
    if(l == r && l != k)
        cout << "//";
    //cout << l << ' ' << r << endl;
    int idx = l, last = 0, cnt = 0;
    while(idx != r){
        int ln = -1, rn = -1;
        if(mp.count(x - v[idx]))
            ln = mp[x - v[idx]];
        if(mp.count(y - v[idx]))
            rn = mp[y - v[idx]];
        if(ln != -1 && ln != last){
            last = idx;
            idx = ln;
        }
        else if(rn != -1 && rn != last){
            last = idx;
            idx = rn;
        }
        int t = min(sum[idx], sum[last]);
        cnt += t;
        sum[idx] -= t;
        sum[last] -= t;
        //cout << idx << ' ';
    }
    ans += cnt;
}
signed main(){
    cin >> n >> x >> y;
    for(int i = 1;i <= n;i ++){
        cin >> a[i].s >> a[i].v;
        sum[i] = a[i].s;
        v[i] = a[i].v;
        mp[v[i]] = i;
    }
    for(int i = 1;i <= n;i ++){
        if(!vis[i])
            find(i);
    }
    for(int i = 1;i <= n;i ++){
        if(v[i] * 2 == x || v[i] * 2 == y)
            ans += sum[i] / 2;
    }
    cout << ans << endl;
    return 0;
}*/

/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e2 + 7, M = 2e2 * N;
int dp[M], a[N], l[N], r[N];
int n, mid = M / 2;
int main(){
    int t = clock();
    cin >> n;
    for(int i = 1;i <= n;i ++)
        cin >> a[i];
    dp[mid] = 1;
    for(int i = 1;i <= n;i ++){
        if(a[i] < 0){
            for(int j = 0;j <= M - a[i];j ++)
                dp[j] += dp[j - a[i]];
        }
        if(a[i] >= 0){
            for(int j = M - 1;j >= a[i];j --)
                dp[j] += dp[j - a[i]];
        }
        // for(int j = mid - 10;j <= mid + 10;j ++)
        //     cout << dp[j] << ' ';
        // cout << endl;
    }
    cout << clock() - t << endl;
    cout << dp[mid] << endl;
    return 0;
}*/
