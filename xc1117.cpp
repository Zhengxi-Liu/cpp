/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 7;
int a[N], dp[N], n, ans = 0;
int divisor(int x){
    int cnt = 0;
    for(int i = 1;i * i <= x;i ++)
        if(x % i == 0){
            if(i * i == x)
                cnt += 1;
            else
                cnt += 2;
        }
    return cnt;
}
int main(){
    cin >> n;
    for(int i = 1;i <= n;i ++)
        a[i] = divisor(i);
    for(int i = 1;i <= n;i ++)
        for(int j = n;j >= i;j --)
            dp[j] = max(dp[j], dp[j - i] + a[i]);
    for(int i = 1;i <= n;i ++)
        ans = max(ans, dp[i]);
    cout << dp[n] << endl;
    return 0;
}*/
#include<bits/stdc++.h>
using namespace std;
const int N = 5e3 + 7, M = 5e2 + 7;
int dp[M][N], a[N], b[N], ans[N], n, m, t, idx = 0, maxn = 0;
int main(){
    cin >> n >> m;
    for(int i = 1;i <= n;i ++){
        cin >> a[i] >> b[i] >> t;
        a[i] *= t;
        b[i] *= t;
    }
    for(int i = 1;i <= n;i ++)
        for(int j = a[i];j <= m;j ++){
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - a[i]] + b[i]);
            maxn = max(maxn, dp[i][j]);
        }
    t = 0;
    int temp = 0;
    for(int i = 1;i <= n;i ++)
        if(dp[i][m] > t){
            t = dp[i][m];
            temp = i;
        }
    cout << dp[n][m] << endl;
    for(int i = n;i >= 1;i --){
        if(dp[i][temp] != dp[i - 1][temp]){
            ans[++ idx] = i;
            //cout << i << ' ';
            temp -= a[i];
        }
        //cout << m << endl;
    }
    for(int i = idx;i >= 1;i --)
        cout << ans[i] << ' ';
    cout << endl;
    return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int a[N], dp[N], n, m = 0, cnt = 0;
int main(){
    cin >> n;
    for(int i = 1;i <= n;i ++){
        cin >> a[i];
        m += a[i];
    }
    dp[0] = 1;
    for(int i = 1;i <= n;i ++)
        for(int j = m;j >= a[i];j --)
            dp[j] += dp[j - a[i]];
    for(int i = 1;i <= m;i ++)
        if(dp[i]){
            cnt ++;
            a[cnt] = i;
        }
    cout << cnt << ' ';
    for(int i = 1;i <= cnt;i ++)
        cout << a[i] << ' ';
    cout << endl;
    return 0;
}
*/