// A. 标点简化
/*#include<bits/stdc++.h>
using namespace std;

string s, ans;

int n;

int main(){

    getline(cin, s);

    n = s.size();
    s = " " + s;

    for(int i = 1; i <= n;){
        if(s[i] == '?' || s[i] == '!'){
            int flg = 0;
            while(s[i] == '?' || s[i] == '!')
                if(s[i ++] == '?') flg = 1;
            if(!flg) ans += "!";
            else ans += "?";
        }
        else ans += s[i ++];
    }

    cout << ans << endl;

    return 0;
}*/

// B. 优惠券
/*#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e5 + 7;

int p[N], n, k, x, ans;


signed main(){

    cin >> n >> k >> x;

    for(int i = 1; i <= n; i ++){
        cin >> p[i];
        ans += p[i];
    }

    sort(p + 1, p + n + 1, greater <int> ());

    for(int i = 1; i <= n; i ++){
        if(!k){ cout << ans << endl; return 0;}
        int nw = max(p[i] - k * x, p[i] % x);
        k -= (p[i] - nw) / x;
        ans -= (p[i] - nw);
        p[i] = nw;
    }

    sort(p + 1, p + n + 1, greater <int> ());

    for(int i = 1; i <= n; i ++){
        if(!k){ cout << ans << endl; return 0;}
        ans -= p[i];
        k --;
        p[i] = 0;
    }
    cout << ans << endl;

    return 0;
}*/

// C. 乘积为平方
/*#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e5 + 7;

bool prime[N];

int pf[N], pw[N], cnt, n;

long long ans;

void prm(){
    prime[1] = true;
    for(int i = 2; i <= n; i ++){
        if(prime[i]) continue;
        for(int j = i * 2; j <= n; j += i)
            prime[j] = true;
    }
}

void dfs(int step, int id, int s){
    if(step > cnt){
        if(s <= n && id * id / s <= n)
            ans ++;
        return;
    }
    int mul = 1;
    dfs(step + 1, id, s);
    for(int i = 1; i <= pw[step] * 2; i ++){
        mul *= pf[step];
        dfs(step + 1, id, s * mul);
    }
}

void cal(int n){
    cnt = 0;
    int m = n;
    for(int i = 2; i * i <= n; i ++){
        while(n % i == 0 && !prime[i]){
            if(pf[cnt] == i) pw[cnt] ++;
            else pf[++ cnt] = i, pw[cnt] = 1;
            n /= i;
        }
    }
    if(n > 1) pf[++ cnt] = n, pw[cnt] = 1;
    dfs(1, m, 1);
}

signed main(){

    cin >> n;

    prm();

    for(int i = 1; i <= n; i ++){
        cal(i);
    }
    
    cout << ans << endl;

    return 0;
}*/

// D. 子序列GCD
/*#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e3 + 7, MOD = 1e9 + 7;

int a[N], dp[N][N];

int n, goal, maxn;

int gcd(int x, int y){
    while(y){
        int t = y;
        y = x % y;
        x = t;
    }
    return x;
}

signed main(){

    cin >> n;

    for(int i = 1; i <= n; i ++)
        cin >> a[i], maxn = max(maxn, a[i]);

    cin >> goal;

    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= maxn; j ++)
            dp[i][j] = dp[i - 1][j];
        for(int j = 1; j <= maxn; j ++)
            dp[i][gcd(j, a[i])] = (dp[i][gcd(j, a[i])] + dp[i - 1][j]) % MOD;
        dp[i][a[i]] = (dp[i][a[i]] + 1) % MOD;
    }

    cout << dp[n][goal] << endl;

    return 0;
}*/

// E. 减去GCD
#include<bits/stdc++.h>
using namespace std;

#define int long long

int a, b;

int gcd(int x, int y){
    while(y){
        int t = y;
        y = x % y;
        x = t;
    }
    return x;
}

int dfs(int a, int b){
    if(a == b) return 1;
    if(a <= 0 || b <= 0) return 0;
    int t = gcd(a, b);
    if(t == 1){
        if(abs(a - b) == 1)
            return min(a, b);
        int minn = 1e18;
        for(int i = 1; i * i <= abs(a - b); i ++)
            if(abs(a - b) % i == 0){
                if(i > 1) minn = min(minn, a % i);
                minn = min(minn, a % (abs(a - b) / i));
            }
        return dfs(a - minn, b - minn) + minn;
    }
    return dfs(a / t, b / t);
}

signed main(){

    cin >> a >> b;

    cout << dfs(a, b) << endl;

    return 0;
}

