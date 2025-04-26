/*#include<bits/stdc++.h>
using namespace std;
const int N = 3e3 + 7;
double dp[N][N], a[N], ans = 0;
int n;
int main(){
    cin >> n;
    dp[0][0] = 1;
    for(int i = 1;i <= n;i ++){
        cin >> a[i];
        dp[i][0] = dp[i - 1][0] * (1 - a[i]);
    }
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= i;j ++)
            dp[i][j] = a[i] * dp[i - 1][j - 1] + (1 - a[i]) * dp[i - 1][j];
    }
    for(int i = n / 2 + 1;i <= n;i ++)
        ans += dp[n][i];
    cout << setprecision(10) << ans << endl;
    //printf("%.10lf\n", ans);
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
double b[N], dp[N], m;
int n, t, a[N];
ifstream fin("xc.in");
ofstream fout("xc.out");
int main(){
    fin >> t;
    while(t --){
        fin >> m >> n;
        int ans = 0, maxn = 0;
        m = 1 - m;
        for(int i = 1;i <= n;i ++){
            fin >> a[i] >> b[i];
            b[i] = 1 - b[i];
            maxn += a[i];
            //dp[i][0] = 1;
        }
        dp[0] = 1;
        for(int i = 1;i <= n;i ++)
            for(int j = maxn;j >= a[i];j --){
                dp[j] = max(dp[j], dp[j - a[i]] * b[i]);
            }
        for(int i = 1;i <= maxn;i ++){
            //cout << dp[i] << ' ';
            if(dp[i] > m)
                ans = i;
            dp[i] = 0;
        }
        fout << ans << endl;
    }
    return 0;
}*/
