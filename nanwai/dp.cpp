//C. 01背包 II
/*#include<bits/stdc++.h>
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
}*/

//F. 选课加强版
/*#include<bits/stdc++.h>
using namespace std;

const int N = 5e3 + 7;

int dp[N][N], fa[N], sz[N];

vector <int> a[N];

int n, m;

void DP(int x){
    sz[x] = 1;
    for(int to : a[x]){
        if(to == fa[x]) continue;
        DP(to);
        sz[x] += sz[to];
        for(int i = sz[x]; i >= 2; i --)
            for(int j = 1; j <= sz[to] && j < i; j ++)
                dp[x][i] = max(dp[x][i], dp[to][j] + dp[x][i - j]);
    }
}
int main(){

    cin >> n >> m;

    for(int i = 1; i <= n; i ++){
        cin >> fa[i] >> dp[i][1];
        a[fa[i]].push_back(i);
    }

    DP(0);
    cout << dp[0][m + 1] << endl;

    return 0;
}*/

//H. 数位和
/*#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e4 + 7, M = 1e2 + 7, MOD = 1e9 + 7;

string s;

int m, n, a[N], dp[N][M], dp2[N][M][2];

signed main(){

    cin >> s >> m;
    n = s.size();
    for(int i = 1; i <= n; i ++)
        a[i] = s[i - 1] - '0';
    dp[0][0] = 1;
    for(int i = 1; i < n; i ++)
        for(int j = 0; j < m; j ++){
            for(int k = 0; k <= 9; k ++)
                (dp[i][j] += dp[i - 1][(j - k + m * 100) % m]) %= MOD;
        }

    dp2[0][0][1] = 1;
    for(int i = 1; i <= n; i ++)
        for(int j = 0; j < m; j ++)
            for(int k = i == 1 ? 1 : 0; k <= 9; k ++){
                (dp2[i][j][0] += dp2[i - 1][(j - k + m * 100) % m][0]) %= MOD;
                if(k < a[i]) (dp2[i][j][0] += dp2[i - 1][(j - k + m * 100) % m][1]) %= MOD;
                if(k == a[i]) (dp2[i][j][1] += dp2[i - 1][(j - k + m * 100) % m][1]) %= MOD;
            }
    
    cout << ((dp2[n][0][0] + dp2[n][0][1]) % MOD + dp[n - 1][0] - 1) % MOD << endl;
    return 0;
}*/

//I. Segment Sum
/*#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e3 + 50, MOD = 998244353;

int l, r, k, n;

int dp[20][N], mark[20][N], dp2[20][N][2], mark2[20][N][2], dis[20][N];

int cal(int x){
	int res = 0;
	while(x){
		res += x & 1;
		x >>= 1;
	}
	return res;
}

int DP(string s){
	if(s == "0") return 0;
	n = s.size();
	s = " " + s;
	memset(dp, 0, sizeof(dp)); memset(mark, 0, sizeof(mark)); 
    memset(dp2, 0, sizeof(dp2)); memset(mark2, 0, sizeof(mark2));
	dp[0][0] = 0;
	mark[0][0] = 1;
	int ans = 0;
	for(int i = 0; i < n - 1; i ++){
        for(int b = 0; b < (1 << 10); b ++)
		    for(int k = !b ? 1 : 0; k <= 9; k ++)
				if(mark[i][b]){
                    (dp[i + 1][b | (1 << k)] += dp[i][b] * 10 + k * mark[i][b]) %= MOD;
                    (mark[i + 1][b | (1 << k)] += mark[i][b]) %= MOD;
                }
        for(int b = 0; b < (1 << 10); b ++) dis[i + 1][b] = dis[i][b] + dp[i + 1][b];
    }
	for(int b = 1; b < (1 << 10); b ++) if(cal(b) <= k && dis[n - 1][b]) (ans += dis[n - 1][b]) %= MOD;
	dp2[0][0][1] = 0;
	mark2[0][0][1] = 1;
	for(int i = 0; i < n; i ++){
		int x = s[i + 1] - '0';
		for(int k = !i ? 1 : 0; k <= 9; k ++)
			for(int b = 0; b < (1 << 10); b ++){
				if(mark2[i][b][0]){
					(dp2[i + 1][b | (1 << k)][0] += dp2[i][b][0] * 10 + k * mark2[i][b][0]) %= MOD;
					(mark2[i + 1][b | (1 << k)][0] += mark2[i][b][0]) %= MOD;
				}
				if(k < x && mark2[i][b][1]) {
					(dp2[i + 1][b | (1 << k)][0] += dp2[i][b][1] * 10 + k * mark2[i][b][1]) %= MOD;
					(mark2[i + 1][b | (1 << k)][0] += mark2[i][b][1]) %= MOD;
				}
				if(k == x && mark2[i][b][1]){
					(mark2[i + 1][b | (1 << k)][1] += mark2[i][b][1]) %= MOD;
					(dp2[i + 1][b | (1 << k)][1] += dp2[i][b][1] * 10 + k * mark2[i][b][1]) %= MOD;
				}
			}
	}
    int t = ans;
	for(int b = 1; b < (1 << 10); b ++) if(cal(b) <= k) (ans += dp2[n][b][0] + dp2[n][b][1]) %= MOD;
	return ans;
}

string itos(int n){
    if(!n) return "0";
	string res = "";
	while(n){
		res += (n % 10 + '0');
		n /= 10;
	}
	reverse(res.begin(), res.end());
	return res;
}

signed main(){
	
	cin >> l >> r >> k;
	cout << (DP(itos(r)) - DP(itos(l - 1)) + MOD) % MOD << endl;

	return 0; 
}*/

//C. 打工之旅
/*#include<bits/stdc++.h>
using namespace std;

#define int long long
#define UP(i, n) for(int i = 1; i <= n; i ++)

const int N = 80 + 7, INF = 1e18;

struct str{
    int tm, money;
}dp[N][N][N][N];

int d[N][N], r[N][N], p[N][N], n;

str cost(str now, int incm, int cst){
    if(now.money < cst){
        if(!incm) return {INF, 0};
        int wait = (cst - now.money - 1) / incm + 1;
        return {now.tm + wait, wait * incm + now.money - cst};
    }
    return {now.tm, now.money - cst};
}

bool cmp(str a, str b){
    if(a.tm == b.tm) return a.money > b.money;
    return a.tm < b.tm;
}

signed main(){

    cin >> n;

    UP(i, n) UP(j, n) cin >> p[i][j];
    UP(i, n) UP(j, n - 1) cin >> r[i][j];
    UP(i, n - 1) UP(j, n) cin >> d[i][j];

    UP(i, n) UP(j, n) UP(x, i) UP(y, j) dp[i][j][x][y] = {INF, 0};
    dp[1][1][1][1] = {0, 0};

    UP(i, n) UP(j, n) UP(x, i) UP(y, j){
        if(j < n){
            str cstr = cost(dp[i][j][x][y], p[x][y], r[i][j]);
            if(cmp(cstr, dp[i][j + 1][x][y])) dp[i][j + 1][x][y] = cstr;
            if(cmp(cstr, dp[i][j + 1][i][j + 1])) dp[i][j + 1][i][j + 1] = cstr;
        }
        if(i < n){
            str cstd = cost(dp[i][j][x][y], p[x][y], d[i][j]);
            if(cmp(cstd, dp[i + 1][j][x][y])) dp[i + 1][j][x][y] = cstd;
            if(cmp(cstd, dp[i + 1][j][i + 1][j])) dp[i + 1][j][i + 1][j] = cstd;
        }
    }
    int ans = INF;
    UP(x, n) UP(y, n) ans = min(ans, dp[n][n][x][y].tm);
    cout << ans + (n - 1) * 2 << endl;

    return 0;
}*/

//E. 梦幻岛宝珠
/*#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e3 + 7, INF = -1e18;

int dp[N + 1], tmp[N + 1];

int n, w, v, m;

struct str{
    int w, v;
};

vector <str> a[N];

pair <int, int> cal(int x){
    int res = 0;
    while(x % 2 == 0){
        x /= 2;
        res ++;
    }
    return {x, res};
}

void prep(){
    for(int i = 0; i <= N; i ++) {
        a[i].clear();
        dp[i] = -1e9;
    }
}

signed main(){

    while(cin >> n >> m){

        if(n == -1 && m == -1) break;
    
        prep();

        for(int i = 1; i <= n; i ++){
            cin >> w >> v;
            //cout << cal(w).second << ' ' << cal(w).first << endl;
            a[cal(w).second].push_back({cal(w).first, v});
        }

        dp[0] = 0;
        
        for(int cnt = 30; cnt >= 0; cnt --){

            int dg = (m >> cnt) & 1;

            for(int i = 0; i <= N; i ++) tmp[i] = -1e9;

            for(int i = 0; i <= N; i ++)
                tmp[min((i * 2) + dg, N)] = dp[i]; // power 减小以后, 缝隙扩大了 2 倍, 再加上 m 给的附加

            for(int i = N - 1; i >= 0; i --)
                tmp[i] = max(tmp[i], tmp[i + 1]);

            memcpy(dp, tmp, sizeof(dp));

            for(str now : a[cnt]){
                for(int j = 0; j <= N - now.w; j ++)
                    dp[j] = max(dp[j], dp[j + now.w] + now.v);
            }
        }
        cout << dp[0] << endl;

    }

    return 0;
}*/

