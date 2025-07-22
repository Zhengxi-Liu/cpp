//E. 玩具车
/*#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 7;

typedef pair <int, int> PI;

set <PI> q;

int n, k, p, sz, ans;

int a[N], nxt[N], lst[N], vis[N];

set <PI> s;

int main(){

    cin >> n >> k >> p;

    for(int i = 1; i <= p; i ++)
        cin >> a[i];
    
    for(int i = 1; i <= n; i ++)    
        lst[i] = p + 1;

    for(int i = p; i >= 1; i --)
        nxt[i] = lst[a[i]], lst[a[i]] = i;

    for(int i = 1; i <= p; i ++){
        if(!vis[a[i]]){
            if(sz < k){
                s.insert({nxt[i], a[i]});
                sz ++, ans ++;
            }
            else {
                PI now = * --s.end();
                vis[now.second] = 0;
                s.erase(now);
                s.insert({nxt[i], a[i]});
                ans ++;
            }
            vis[a[i]] = 1;
        }
        else {
            PI now = *s.find({i, a[i]});
            s.erase(now);
            s.insert({nxt[i], a[i]});
        }
    }
    cout << ans << endl;

    return 0;
}*/

//F. 舞蹈组合
/*#include<bits/stdc++.h>
using namespace std;

const int N = 11, M = (1 << N) + 7;

int dp[N][M];

string s[N];

int n, m, k, ans;

int cal(int bex){
    int res = 0;
    while(bex){
        res += bex & 1;
        bex >>= 1;
    }
    return res;
}

int main(){

    cin >> n;

    for(int i = 1; i <= n; i ++){
        cin >> s[i];
        m = s[i].size();
    }
    cin >> k;

    int maxn = (1 << m) - 1;

    dp[0][0] = 1;

    for(int i = 1; i <= n; i ++)
        for(int bex = 0; bex <= maxn; bex ++){
            dp[i][bex] = dp[i - 1][bex];
            for(int j = 0; j < m; j ++){
                if(!((bex >> j) & 1)) continue;
                if(s[i][j] == 'N') continue;
                dp[i][bex] += dp[i - 1][bex - (1 << j)];
            }
        }

    for(int bex = 0; bex <= maxn; bex ++)
        if(cal(bex) == k) ans += dp[n][bex];
    cout << ans << endl;

    return 0;
}*/

//G. 知知树
/*#include<bits/stdc++.h>
using namespace std;

const int N = 3e2 + 7;

int dp[N][N], dis[N];

int n, x;

double k, c;

int main(){

    cin >> n >> k >> c;

    memset(dp, 0x3f, sizeof(dp));
    for(int i = 1; i <= n; i ++){
        cin >> x;
        dis[i] = dis[i - 1] + x;
        dp[i][i] = x;
        dp[i][i - 1] = 0;
    }
    dp[n + 1][n] = 0;
    for(int len = 2; len <= n; len ++)
        for(int i = 1; i + len - 1 <= n; i ++){
            int j = i + len - 1;
            for(int mid = i; mid <= j; mid ++)
                dp[i][j] = min(dp[i][j], dp[i][mid - 1] + dp[mid + 1][j]);
            dp[i][j] += dis[j] - dis[i - 1];
        }
    
    printf("%.3lf\n", c + k / dis[n] * dp[1][n]);

    return 0;
}*/

//H. 先序遍历的前K个点
/*#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mid ((l + r) >> 1)

const int N = 2e5 + 7;

vector <int> a[N];

int sz[N], s[N], sum[N];

int n, k, x, y, ans, t, root;

void find(int x, int fa){

    int mx1 = 0, mx2 = 0;
    sum[x] = sz[x] = 1;
    for(int to : a[x]){
        if(to == fa) continue;
        find(to, x);
        sz[x] += sz[to];
        if(sum[to] == sz[to]) 
            sum[x] += sum[to];
        else {
            if(sum[to] > mx1) swap(sum[to], mx1);
            if(sum[to] > mx2) swap(sum[to], mx2);
        }
    }
    sum[x] = (s[x] < t) ? 0 : sum[x] + mx1;
    ans = max(ans, sum[x] + mx2);
}

bool check(int x){
    find(root, ans = 0);
    return ans >= k;
}

int main(){

    cin >> n >> k;

    int l = 1e9, r = 0;

    s[0] = 1e9;
    for(int i = 1; i <= n; i ++){
        cin >> s[i];
        l = min(l, s[i]), r = max(r, s[i]);
        root = (s[i] < s[root]) ? i : root;
    }

    for(int i = 1; i < n; i ++){
        cin >> x >> y;
        a[x].pb(y);
        a[y].pb(x);
    }

    while(l <= r){
        if(check(t = mid)) l = mid + 1;
        else r = mid - 1;
    }
    cout << l - 1 << endl;

    return 0;
}*/
