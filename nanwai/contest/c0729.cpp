//F. 写诗
/*#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e5 + 7, MOD = 1e9 + 7;

vector <int> a[N];
int len[N], rym[N];
int dp[N], cnt[27], mul[N];
int n, m, k, ans = 1;;
char c;

int qp(int a, int b){
    int res = 1;
    while(b){
        if(b & 1) (res *= a) %= MOD;
        (a *= a) %= MOD;
        b >>= 1;
    }
    return res;
}

signed main(){

    cin >> n >> m >> k;

    dp[0] = 1;
    for(int i = 1; i <= n; i ++){
        cin >> len[i] >> rym[i];
        a[rym[i]].push_back(len[i]);
    }

    for(int i = 1; i <= k; i ++)
        for(int j = 1; j <= n; j ++)
            if(i >= len[j]) (dp[i] += dp[i - len[j]]) %= MOD;

    for(int i = 1; i <= n; i ++){
        if(!a[i].size()) continue;
        for(int v : a[i]) (mul[i] += dp[k - v]) %= MOD;
    }

    for(int i = 1; i <= m; i ++){
        cin >> c;
        cnt[c - 'A'] ++;
    }
    
    for(int i = 0; i < 26; i ++){
        if(!cnt[i]) continue;
        int tmp = 0;
        for(int j = 1; j <= n; j ++){
            if(!a[j].size()) continue;
            (tmp += qp(mul[j], cnt[i])) %= MOD;
        }
        (ans *= tmp) %= MOD;
    }
    
    cout << ans << endl;

    return 0;
}*/

//G. 涂抹油漆
/*#include<bits/stdc++.h>
using namespace std;

const int N = 5e2 + 7;

int d[N][N], mark[N][N];
int disx[N][N], disy[N][N], sum[N];
int mxl[N], mxr[N], mxu[N], mxd[N];

int n, k, s1, s2, e1, e2;
int ans, mx, mxn, mxm;

int main(){

    cin >> n >> k;

    for(int i = 1; i <= n; i ++){
        cin >> s1 >> s2 >> e1 >> e2;
        s1 ++, s2 ++, e1 ++, e2 ++;
        mxn = max(mxn, e1);
        mxm = max(mxm, e2);
        d[s1][s2] ++;
        d[e1][e2] ++;
        d[s1][e2] --;
        d[e1][s2] --;
    }

    //________________________________________

    for(int i = 1; i <= mxn; i ++)
        for(int j = 1; j <= mxm; j ++){
            d[i][j] += d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1];
            if(d[i][j] == k - 1) mark[i][j] = 1;
            if(d[i][j] == k) mark[i][j] = -1, ans ++;
        }
    
    for(int i = 1; i <= mxn; i ++)
        for(int j = 1; j <= mxm; j ++){
            disx[i][j] = disx[i - 1][j] + mark[i][j];
            disy[i][j] = disy[i][j - 1] + mark[i][j];
        }
    
    //________________________________________

    for(int st = 1; st <= mxn; st ++)
        for(int ed = st; ed <= mxn; ed ++){
            memset(sum, 0, sizeof(sum));
            for(int j = 1; j <= mxm; j ++){
                int tmp = disx[ed][j] - disx[st - 1][j];
                sum[j] = max(tmp, tmp + sum[j - 1]);
                mxl[j] = max(mxl[j], sum[j]);
            }
            memset(sum, 0, sizeof(sum));
            for(int j = mxm; j; j --){
                int tmp = disx[ed][j] - disx[st - 1][j];
                sum[j] = max(tmp, tmp + sum[j + 1]);
                mxr[j] = max(mxr[j], sum[j]);
            }
        }
    
    for(int j = 1; j <= mxm; j ++) mxl[j] = max(mxl[j], mxl[j - 1]);
    for(int j = mxm; j; j --) mxr[j] = max(mxr[j], mxr[j + 1]);
    for(int j = 0; j <= mxm; j ++) mx = max(mx, mxl[j] + mxr[j + 1]);

    //________________________________________

    for(int st = 1; st <= mxm; st ++)
        for(int ed = st; ed <= mxm; ed ++){
            memset(sum, 0, sizeof(sum));
            for(int i = 1; i <= mxn; i ++){
                int tmp = disy[i][ed] - disy[i][st - 1];
                sum[i] = max(tmp, tmp + sum[i - 1]);
                mxu[i] = max(mxu[i], sum[i]);
            }
            memset(sum, 0, sizeof(sum));
            for(int i = mxn; i; i --){
                int tmp = disy[i][ed] - disy[i][st - 1];
                sum[i] = max(tmp, tmp + sum[i + 1]);
                mxd[i] = max(mxd[i], sum[i]);
            }
        }
    
    for(int i = 1; i <= mxn; i ++) mxu[i] = max(mxu[i], mxu[i - 1]);
    for(int i = mxn; i; i --) mxd[i] = max(mxd[i], mxd[i + 1]);
    for(int i = 0; i <= mxn; i ++) mx = max(mx, mxu[i] + mxd[i + 1]);

    //________________________________________
    
    
    cout << ans + mx << endl;

    return 0;
}*/
