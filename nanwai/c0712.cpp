//F. 黄金矿工
#include<bits/stdc++.h>
using namespace std;

#define up(i, n) for(int i = 1; i <= n; i ++)

const int N = 50 + 7;

int dp[N][N][N], a[N], b[N];

int n, m, k, ans;

int main() {

    cin >> n >> m >> k;
    
    n ++, m ++;

    up(i, k) cin >> a[i], a[i] ++;

    cin >> k;

    up(i, k) cin >> b[i], b[i] ++;

    up(i, k) up(x, k) up(y, k) {
        up(c, k)
            dp[i][x][y] = max(dp[i][x][y], dp[i - 1][c][y] + n + m - abs(a[x] - a[i]) - abs(b[y] - b[i]) - 2);
        up(d, k)
            dp[i][x][y] = max(dp[i][x][y], dp[i - 1][x][d] + n + m - abs(a[x] - a[i]) - abs(b[y] - b[i]) - 2);
    }

    up(x, k) up(y, k)
        ans = max(ans, dp[k][x][y]);

    cout << ans << endl;

    return 0;
}