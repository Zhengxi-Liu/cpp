//A. 超级酷数
/*#include<bits/stdc++.h>
using namespace std;

const int N = 10 + 7;

int dgt[N], n, ans, cnt;

bool check(int x){
    if(x < 100) return true;
    cnt = 0;
    while(x){
        dgt[++ cnt] = x % 10;
        x /= 10;
    }
    for(int i = 2; i < cnt; i ++)
        if(dgt[i] - dgt[i - 1] != dgt[i + 1] - dgt[i]) return false;
    return true;
}

int main(){

    cin >> n;

    for(int i = 1; i <= n; i ++)
        if(check(i)) ans ++;

    cout << ans << endl;

    return 0;
}*/

//B. 食物中毒
/*#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e6 + 7;

int dp[N][2], n, x, y;

signed main(){

    cin >> n;

    for(int i = 1; i <= n; i ++){
        cin >> x >> y;
        if(!x){
            dp[i][0] = max(max(dp[i - 1][0], dp[i - 1][1]) + y, dp[i - 1][0]);
            dp[i][1] = dp[i - 1][1];
        }
        else {
            dp[i][1] = max(dp[i - 1][0] + y, dp[i - 1][1]);
            dp[i][0] = dp[i - 1][0];
        }
        //cout << dp[i][0] << ' ' << dp[i][1] << " / / ";
    }

    cout << max(dp[n][0], dp[n][1]) << endl;

    return 0;
}*/

//C. 笑脸符号
#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;

int dp[N], n;

int main(){

    cin >> n;

    memset(dp, 0x3f, sizeof(dp));

    dp[1] = 0;

    for(int i = 1; i < N; i ++){
        for(int j = 1; j < i; j ++)
            dp[j] = min(dp[j], dp[i] + i - j);
        for(int j = i + i; j < N; j += i){
            dp[j] = min(dp[j], dp[i] + (j - i) / i + 1);
        }
        // if(i % 2 == 0) dp[i] = min(dp[i], dp[i / 2] + 2);
    }

    // for(int i = 1; i <= n; i ++)
    //     cout << dp[i] << ' ';
    // cout << endl;

    cout << dp[n] << endl;

    return 0;
}
