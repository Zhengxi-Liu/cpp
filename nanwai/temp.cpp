//T1
//https://www.luogu.com.cn/problem/P7667
/*#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 5e5 + 7;

struct str{
    int x, v, dis, b;
}a[N];

int dp[N], n, ans, mx;

bool cmp(str l, str r){
    return l.x < r.x;
}

signed main(){

    cin >> n;

    for(int i = 1; i <= n; i ++)
        cin >> a[i].x >> a[i].v;    

    sort(a + 1, a + n + 1, cmp);

    for(int i = 1; i <= n; i ++)
        dp[i] = a[i].x + a[i].v - a[i + 1].x;

    for(int i = 1; i <= n; i ++){
        ans = max(ans, mx + a[i].v);
        mx = max(0ll, mx + dp[i]);
    }

    cout << ans << endl;

    return 0;

}*/

//T2
//https://www.luogu.com.cn/problem/P7668
/*#include<bits/stdc++.h>
using namespace std;

const int N = 3e3 + 7;

char a[N][N];

int dp[N][N][2];

int n, m, ans;

int main(){
    
    cin >> n >> m;

    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++)
            cin >> a[i][j];

    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++)
            if(a[i][j] == 'G'){
                if(a[i - 1][j] == 'R' && a[i + 1][j] == 'W') // 如果纵向可以, 标记为 1
                    dp[i][j][0] = 1;
                if(a[i][j - 1] == 'R' && a[i][j + 1] == 'W') // 如果横向可以, 标记为 1
                    dp[i][j][1] = 1;
                if(dp[i - 1][j + 1][0] | dp[i - 1][j + 1][1]){ // 如果发生了冲突
                    //如果不发生冲突的位置为 0, 则代表发生冲突的位置为 1, 则不能在 (i, j) 以当前方法放, & 成 0
                    dp[i][j][0] &= dp[i - 1][j + 1][0]; 
                    dp[i][j][1] &= dp[i - 1][j + 1][1]; 
                    
                    //      _
                    //  r r R  r
                    //    _
                    //  w(R G  W)
                    // (R G W) g
                    //      -
                    //  w W R  g
                    //    -
                    
                }
                ans += dp[i][j][0] | dp[i][j][1];
            }
    
    cout << ans << endl;

    return 0;
}*/

//T3
/*#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7, MOD = 1e9 + 7;

int a[N], l[N], r[N];

int dp[N][N]; // dp[i][j] 代表在第 i 位时, 以改变了 j 此方向

int n, k;

void read(){

    cin >> n >> k;

    char c;

    for(int i = 1; i < n; i ++)
        cin >> c, a[i] = (c == 'L' ? 0 : 1);

    cin >> c;
    for(int i = 1; i < n; i ++)
        cin >> c, l[i] = (c == '0' ? 0 : 1);
    
    for(int i = n - 1; i >= 1; i --){
        if(l[i]){
            l[i] = 0;
            break;
        }
        else 
            l[i] = 1;
    }

    cin >> c;
    for(int i = 1; i < n; i ++)
        cin >> c, r[i] = (c == '0' ? 0 : 1);
    
}

int DP(int x[]){
    int res = 0;
    for(int i = 1; i < n; i ++){
        for(int j = 0; j <= k; j ++){
            
        }
    }
    for(int i = 1; i < n; i ++)
        a[i] = a[i] ^ 1;
    for(int i = 1; i < n; i ++){
        for(int j = 0; j <= k; j ++){
            
        }
    }
    for(int i = 1; i < n; i ++)
        a[i] = a[i] ^ 1;
    return res;
}

int main(){
    
    read();
    
    // for(int i = 1; i < n; i ++)
    //     cout << l[i] << ' ';
    // cout << endl;
    // for(int i = 1; i < n; i ++)
    //     cout << r[i] << ' ';
    // cout << endl;

    cout << (DP(r) - DP(l) + MOD) % MOD << endl;
    
    return 0;
}*/

