//D. 奶牛求幂
/*#include<bits/stdc++.h>
using namespace std;

int n, ans;

int gcd(int x, int y){
	while(y){
		int tmp = y;
		y = x % y;
		x = tmp;
	}
	return x;
}

void dfs(int x, int y, int t){
	if(x < y) swap(x, y);
	if(n % gcd(x, y)) return; 
	if(x == n || y == n){
		cout << ans << endl;
		exit(0);
	}
	if(x << (ans - t) < n) return;
	if(t >= ans) return;
	dfs(x + x, y, t + 1);
	dfs(x + x, x, t + 1);
	dfs(x + y, y, t + 1);
	dfs(x + y, x, t + 1);
	dfs(x - y, y, t + 1);
	dfs(x - y, x, t + 1);
}


signed main(){
	
	cin >> n;
	
	
	for(ans = 1; ans <= 18; ans ++)
		dfs(1, 0, 0);
	
	return 0;
}*/

//E. 方格路径K大和
/*#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 30 + 7;

int dp[N][N][N << 1];

int a[N][N];

int n, m, K, ans = 1e16;

vector <int> s;

signed main(){

    cin >> n >> m >> K;

    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++){
            cin >> a[i][j];
            s.push_back(a[i][j]);
        }

    for(int now : s){

        memset(dp, 0x3f, sizeof(dp));
        
        dp[1][0][0] = dp[0][1][0] = 0;

        for(int i = 1; i <= n; i ++)
            for(int j = 1; j <= m; j ++)
                for(int k = 0; k <= K; k ++){
                    if(a[i][j] >= now && k > 0) 
                        dp[i][j][k] = min({dp[i][j][k], dp[i - 1][j][k - 1], dp[i][j - 1][k - 1]}) + a[i][j];
                    if(a[i][j] <= now) 
                        dp[i][j][k] = min({dp[i][j][k], dp[i - 1][j][k], dp[i][j - 1][k]});
                }

        ans = min(ans, dp[n][m][K]);

    }
    
    cout << ans << endl;

    return 0;
}*/

//G. 树上权值
/*#include<bits/stdc++.h>
using namespace std;

// 真能卡时间

#define int unsigned int

const int N = 7e4 + 7, MSK = (1 << 8), MOD = 1e9 + 7;

vector<int> a[N];

int s[N], fa, n, t, ans;

int dp[MSK + 7][MSK + 7], tmp[N][MSK + 7], mk[MSK + 7];

string op;

int cal(int x, int y){
    if (op[0] == 'A')
        return x & y;
    if (op[0] == 'O')
        return x | y;
    return x ^ y;
}

// dp[R][L]

void dfs(int x){

    int R = s[x] >> 8, L = s[x] & 255, mx = 0;

    for(int i = 0; i < MSK; i ++)
        if(mk[i]) mx = max(mx, dp[i][L] + (cal(i, R) << 8));  // 枚举所有以前出现过的 R (L 已经提前计算)

    mk[R] ++;
    ans = (0ll + ans + 1ll * (0ll + mx + s[x]) * x) % MOD;

    for(int i = 0; i < MSK; i ++){
        tmp[x][i] = dp[R][i];
        dp[R][i] = max(dp[R][i], mx + cal(L, i));  // 枚举将来可能出现的 L, 但是 R 要锁定
    }

    for(int to : a[x]) dfs(to);

    mk[R] --;
    for(int i = 0; i < MSK; i ++) dp[R][i] = tmp[x][i];
}

signed main(){

    cin >> t;

    while(t --){

        scanf("%u", &n);

        cin >> op;

        for(int i = 1; i <= n; i ++){
            scanf("%u", &s[i]);
            a[i].clear();
        }

        for(int i = 2; i <= n; i ++){
            scanf("%u", &fa);
            a[fa].push_back(i);
        }

        ans = 0;
        dfs(1);
        printf("%u\n", ans);

    }

    return 0;
}*/

