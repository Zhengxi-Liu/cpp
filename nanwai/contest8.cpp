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
/*#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;

int dp[N], n;

int main(){

    cin >> n;

    memset(dp, 0x3f, sizeof(dp));

    dp[1] = 0;

    for(int i = 1; i < N; i ++){
        for(int j = i + 1; j < N; j ++)
            dp[i] = min(dp[i], dp[j] + j - i);
        for(int j = i + i; j < N; j += i)
            dp[j] = min(dp[j], dp[i] + (j - i) / i + 1);
    }

    cout << dp[n] << endl;

    return 0;
}*/

//D. LCM的GCD
/*#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e5 + 7;

int mn1[N], mn2[N], c[N];

int fct[N], pw[N];

int a[N], n, cnt, ans = 1;

bool prime[N];

void prm(){
    prime[1] = true;
    for(int i = 2; i < N; i ++){
        if(prime[i]) continue;
        for(int j = i + i; j < N; j += i) prime[j] = true;
    }
}

void upd(int x){

    cnt = 0;

    for(int i = 2; i * i <= x; i ++){
        if(!prime[i] && x % i == 0){ fct[++ cnt] = i; pw[cnt] = 0; }
        while(!prime[i] && x % i == 0){
            pw[cnt] ++;
            x /= i;
        }
    }

    if(x != 1) fct[++ cnt] = x, pw[cnt] = 1;

    for(int i = 1; i <= cnt; i ++){
        x = fct[i];
        c[x] ++;
        if(mn1[x] >= pw[i]){
            mn2[x] = mn1[x];
            mn1[x] = pw[i];
        }
        else if(pw[i] > mn1[x] && pw[i] < mn2[x])
            mn2[x] = pw[i];
    }

}

signed main(){

    cin >> n;

    for(int i = 1; i <= n; i ++) cin >> a[i];

    prm();

    memset(mn1, 0x3f, sizeof(mn1));
    memset(mn2, 0x3f, sizeof(mn2));

    for(int i = 1; i <= n; i ++) upd(a[i]);

    for(int i = 2; i < N; i ++){
        if(c[i] == n){
            ans *= pow(i, mn2[i]);
        }
        else if(c[i] == n - 1){
            ans *= pow(i, mn1[i]);
        }
    }

    cout << ans << endl;

    return 0;
}*/

