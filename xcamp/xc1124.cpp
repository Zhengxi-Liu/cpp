/*#include<bits/stdc++.h>
using namespace std;
const int N = 2e2 + 7;
int dp[N], a[N][N], b[N][N], cnt[N], n, t, m;
int main(){
    cin >> m >> n >> t;
    for(int i = 1;i <= n;i ++){
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        a[t3][++ cnt[t3]] = t1;
        b[t3][cnt[t3]] = t2;
    }
    for(int i = 1;i <= t;i ++){
        //for(int j = 1;j <= cnt[i];j ++)
          //  cout << a[i][j] << ' ' << b[i][j] << endl;
        for(int j = m;j >= 0;j --)
            for(int k = 1;k <= cnt[i];k ++)
                if(j - a[i][k] >= 0)
                    dp[j] = max(dp[j], dp[j - a[i][k]] + b[i][k]);
    }
    cout << dp[m] << endl;
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int a[N], b[N], c[N], dp[N], n, m;
int main(){
    cin >> m >> n;
    for(int i = 1;i <= n;i ++)
        cin >> a[i] >> b[i] >> c[i];
    for(int i = 1;i <= n;i ++){
        if(!c[i])
            for(int j = a[i];j <= m;j ++)
                dp[j] = max(dp[j], dp[j - a[i]] + b[i]);
        else
            for(int j = m;j >= a[i];j --)
                for(int k = 1;k <= c[i] && k * a[i] <= j;k ++)
                    dp[j] = max(dp[j], dp[j - k * a[i]] + b[i] * k);
    }
    cout << dp[m] << endl;
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
int a[N], dp[N], n, k, m = 0, ans = 0;
int main(){
    cin >> n >> k;
    for(int i = 1;i <= n;i ++){
        cin >> a[i];
        a[i] = abs(a[i]);
        a[i] %= k;
        m += a[i];
    }
    dp[0] = 1;
    //for(int i = 1;i <= n;i ++)
      //  cout << a[i] << ' ';
    //cout << endl;
    for(int i = 1;i <= n;i ++)
        for(int j = k;j >= a[i];j --){
            dp[j] += dp[j - a[i]];
        }
    //cout << m << endl;
    //for(int i = 1;i <= k;i ++)
      //  cout << dp[i] << ' ';
    for(int i = 1;i <= k;i ++){
        //cout << dp[i] << ' ';
        if(abs(m - 2 * i) % k == 0){
            cout << "Divisible" << endl;
            exit(0);
        }
    }
    //if(!dp[k])
        cout << "Not divisible" << endl;
    //else
      // cout << "Divisible" << endl; z
}*/