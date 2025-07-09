//
/*#include<bits/stdc++.h>
using namespace std;

#define FOR(i, x, y) for(int i = x; i <= y; i ++)

const int N = 38 + 1, MOD = 1e6;


int x1, x2, x3, x4, n;

int main(){

    cin >> x1 >> x2 >> x3 >> x4;

    n = x1 + x2 + x3 + x4;


    
    return 0;
}*/

//C. 01背包 II

#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e5 + 7;

int dp[N], v, w, n, m, ans;

signed main(){

    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    cin >> n >> m;

    for(int i = 1; i <= n; i ++){
        cin >> w >> v;
        for(int j = N - 1; j >= v; j --)
            dp[j] = min(dp[j], dp[j - v] + w);
    } 
    for(int i = 1; i < N; i ++)
        if(dp[i] <= m) ans = i;

    cout << ans << endl;

    return 0;
}
