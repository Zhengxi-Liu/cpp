//D. 传送阵
/*#include <bits/stdc++.h>
using namespace std;

const int N = 3e2 + 7, M = 1e5 + 7, MOD = 998244353;

int n, m, a, b, c, d, e, f, ans;

int x[M], y[M];
long long dp[N][N][N];

map<pair<int, int>, bool> mp;

long long chg(long long n, long long m) {
    int tmp = m, mul = 1;
    while (tmp) {
        mul *= 10;
        tmp /= 10;
    }
    return n * mul * 10 + m;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> a >> b >> c >> d >> e >> f;

    for (int i = 1; i <= m; i++) {
        cin >> x[i] >> y[i];
        mp[{ x[i], y[i] }] = 1;
    }
    dp[0][0][0] = 1;
    for (int i = 0; i <= n; i++)
        for (int j = 0; i + j <= n; j++)
            for (int k = 0; i + j + k <= n; k++) {
                if (!i && !j && !k)
                    continue;
                int px = a * i + c * j + e * k, py = b * i + d * j + f * k;
                if (mp.count({ px, py }))
                    continue;
                if (i > 0)
                    dp[i][j][k] += dp[i - 1][j][k];
                if (j > 0)
                    dp[i][j][k] += dp[i][j - 1][k];
                if (k > 0)
                    dp[i][j][k] += dp[i][j][k - 1];
                dp[i][j][k] %= MOD;
                // cout << i << ' ' << j << ' ' << k << ": " << dp[i][j][k] << endl;
                if (i + j + k == n)
                    ans += dp[i][j][k];
                ans %= MOD;
            }
    cout << ans << endl;
    return 0;
}*/

//E. 木棍分割
/*#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 7, M = 1e3 + 7, MOD = 10007;

int n, m, a[N], dp[N], sum[N], dis[N];

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        dis[i] = dis[i - 1] + a[i];
    }

    int l = 1, r = 1e9;

    while (l < r) {
        int s = 0, mid = (l + r) >> 1, flg = 0, cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] > mid)
                flg = 1;
            if (s + a[i] >= mid) {
                s = 0;
                cnt++;
            }
            s += a[i];
        }
        if (cnt > m)
            flg = 1;
        if (flg)
            l = mid + 1;
        else
            r = mid;
    }
    l -= 1;
    for (int i = 1, lst = 0; i <= n; i++) {
        while (dis[i] - dis[lst] > l && lst + 1 <= n) lst++;
        // cout << i << ' ' << lst << endl;
        a[i] = lst;
    }
    for (int i = 0; i <= n; i++) sum[i] = 1;
    int ans = 0;
    for (int i = 0; i <= m; i++) {
        // cout << a[i] << ' ';
        for (int j = 1; j <= n; j++) {
            if (a[j] >= 1)
                dp[j] = sum[j - 1] - sum[a[j] - 1];
            else
                dp[j] = sum[j - 1];
            dp[j] %= MOD;
            // cout << dp[j] << ' ';
        }
        // cout << endl;
        sum[0] = 0;
        for (int j = 1; j <= n; j++) {
            sum[j] = (sum[j - 1] + dp[j]) % MOD;
            // cout << sum[j] << ' ';
        }
        // out << endl;
        ans += dp[n], ans %= MOD;
    }

    cout << l << ' ' << (ans + MOD) % MOD << endl;
    return 0;
}*/

//F. 车内听歌
/*#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e6 + 7;

multiset <int> mx, mn;

int n, w, k, a[N], t[N], l = 1, r, sumt, sum, ans;

signed main(){

    cin >> n >> w >> k;

    for(int i = 1; i <= n; i ++) cin >> a[i];

    for(int i = 1; i <= n; i ++) cin >> t[i];

    while(r < n){
        r ++;
        int now = *mx.begin();
        if(mx.size() < w && sumt + (t[r] + 1) / 2 <= k){ // 如果区间内的元素数量少于 w 个, 且总时间允许
            mx.insert(t[r]);
            sumt += (t[r] + 1) / 2;
            sum += a[r];
        }
        else if(t[r] > now && sumt + (t[r] + 1) / 2 + now / 2 <= k){ // 如果 / 2 的 w 个元素中最小的比当前元素还小
            mx.erase(mx.find(now));
            sumt += now / 2 + (t[r] + 1) / 2;
            mx.insert(t[r]);
            mn.insert(now);
            sum += a[r];
        }
        else if(sumt + t[r] <= k){ //如果剩余时间还允许再加一个
            mn.insert(t[r]);
            sumt += t[r];
            sum += a[r];
        }
        else { //如果当前元素在不调整区间的情况下加不进去了
            if(mx.empty()) continue; //如果元素太大了
            r --;
            if(mn.empty()){ // 如果元素全在 / 2 里面
                mx.erase(mx.find(t[l]));
                sumt -= (t[l] + 1) / 2;
            }
            else if(t[l] < now){
                mn.erase(mn.find(t[l]));
                sumt -= t[l];
            }
            else {
                int nowmn = * -- mn.end();
                mx.erase(mx.find(t[l]));
                mx.insert(nowmn);
                mn.erase(mn.find(nowmn));
                sumt = sumt - (t[l] + 1) / 2 - nowmn / 2;
            }
            sum -= a[l ++];
        }
        ans = max(ans, sum);
    }
    cout << ans << endl;

    return 0;
}*/

//G. 拍摄动物
/*#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pst1 sum[i][x + k - 1] + sum[i + 1][x + k - 1] - sum[i + 1][x - 1]
#define pst2 sum[i + 1][x + k - 1] - sum[i + 1][x - 1] - sum[i][x - 1]
#define pst3 sum[i + 1][x + k - 1] - sum[i + 1][x - 1] + sum[i][x + k - 1] - sum[i][x - 1]


const int M = 2e4 + 7, N = 50 + 7;

int n, m, k, ans;

int a[N][M], sum[N][M], dp[N][M];

multiset <int> d1, d2, d3;

signed main(){

    cin >> n >> m >> k;

    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++){
            cin >> a[i][j];
            sum[i][j] = sum[i][j - 1] + a[i][j];
        }
    
    for(int x = 1; x + k - 1 <= m; x ++)
        dp[1][x] = (sum[1][x + k - 1] - sum[1][x - 1]) + (sum[2][x + k - 1] - sum[2][x - 1]);
    
    for(int i = 2; i <= n; i ++){
        
        d1.clear(); d2.clear(); d3.clear();

        d1.insert(dp[i - 1][1] - sum[i][k]);
        for(int j = 1; j <= k; j ++) d2.insert(dp[i - 1][j] + sum[i][j - 1]);
        for(int j = k + 1; j <= m; j ++) d3.insert(dp[i - 1][j]);

        for(int x = 1; x + k - 1 <= m; x ++){

            dp[i][x] = max(dp[i][x], pst1 + * --d1.end());
            dp[i][x] = max(dp[i][x], pst2 + * --d2.end());
            if(!d3.empty()) dp[i][x] = max(dp[i][x], pst3 + * --d3.end());
            
            d1.insert(dp[i - 1][x + 1] - sum[i][x + k]);
            if(x > k) d1.erase(dp[i - 1][x - k] - sum[i][x - 1]);

            d2.erase(dp[i - 1][x] + sum[i][x - 1]);
            d2.insert(dp[i - 1][x + k] + sum[i][x + k - 1]);

            if(x >= k) d3.insert(dp[i - 1][x - k + 1]);
            if(!d3.empty()) d3.erase(dp[i - 1][x + k]);

        }

    }

    for(int i = 1; i <= m; i ++)
        ans = max(ans, dp[n][i]);
    cout << ans << endl;

    return 0;
}*/

//H. 幂树
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;


int main(){




    return 0;
}
