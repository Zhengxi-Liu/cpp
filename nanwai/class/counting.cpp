//A. Barn Painting
/*#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e5 + 7, MOD = 1e9 + 7;

vector <int> a[N];

int n, k, x, y;

int dp[N][4], mark[N];

void dfs(int x, int fa){
	
	dp[x][1] = dp[x][2] = dp[x][3] = 1;
	
	for(int i = 0; i < a[x].size(); i ++){
		
		int to = a[x][i];
		if(to == fa) continue;
		
		dfs(to, x);
		
		(dp[x][1] *= (dp[to][2] + dp[to][3])) %= MOD;
		(dp[x][2] *= (dp[to][1] + dp[to][3])) %= MOD;
		(dp[x][3] *= (dp[to][1] + dp[to][2])) %= MOD; 
	}
	if(!mark[x]) return;
	for(int i = 1; i <= 3; i ++)
		if(i != mark[x]) dp[x][i] = 0; 
}

signed main(){
	
	cin >> n >> k;
	
	for(int i = 1; i < n; i ++){
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	
	for(int i = 1; i <= k; i ++){
		cin >> x >> y;
		mark[x] = y;
	}
	
	dfs(1, 0);
	
	cout << (dp[1][1] + dp[1][2] + dp[1][3]) % MOD << endl;
	
	return 0;
}*/

//B. 子串
/*#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e2 + 7, MOD = 1e9 + 7;

int n, m, K, ans;

string s, t;

int dp[N][N], d[N][N], tmp[N][N];

signed main(){
	
	cin >> n >> m >> K >> s >> t;
	
	s = " " + s;
	t = " " + t;
	
	for(int i = 1; i <= n; i ++){
		
		tmp[1][1] = 1;
		memcpy(dp, tmp, sizeof(tmp));
		memset(tmp, 0, sizeof(tmp));
		
		for(int j = min(i, m); j; j --){
			for(int k = min(i, K); k; k --){
				(dp[j][k] += d[j][k]) %= MOD;
				if(s[i] != t[j]) dp[j][k] = 0;
				if(s[i + 1] == t[j + 1]) (tmp[j + 1][k] += dp[j][k]) %= MOD; 
				(d[j + 1][k + 1] += dp[j][k]) %= MOD;
			}
		}
		
		(ans += dp[m][K]) %= MOD;
	}
	
	cout << ans << endl;
	return 0;
}*/

//C. 车的移动
/*#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e6 + 7, MOD = 998244353;

int n, m, k, sx, sy, ex, ey;

int dp[N][2][2];

signed main(){

    cin >> n >> m >> k >> sx >> sy >> ex >> ey;

    if(sx == ex && sy == ey) dp[0][1][1] = 1;
    else if(sx == ex) dp[0][1][0] = 1;
    else if(sy == ey) dp[0][0][1] = 1;
    else dp[0][0][0] = 1;

    for(int i = 1; i <= k; i ++){
        dp[i][1][1] = dp[i - 1][1][0] + dp[i - 1][0][1];
        dp[i][0][0] = dp[i - 1][1][0] * (n - 1) + dp[i - 1][0][1] * (m - 1) + dp[i - 1][0][0] * (n + m - 4);
        dp[i][1][0] = dp[i - 1][0][0] + dp[i - 1][1][1] * (m - 1) + dp[i - 1][1][0] * (m - 2);
        dp[i][0][1] = dp[i - 1][0][0] + dp[i - 1][1][1] * (n - 1) + dp[i - 1][0][1] * (n - 2);
        dp[i][1][1] %= MOD;
        dp[i][1][0] %= MOD;
        dp[i][0][1] %= MOD;
        dp[i][0][0] %= MOD;
    }

    cout << dp[k][1][1] << endl;

    return 0;
}*/

//D. 生成树计数
/*#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 250 + 7, MOD = 998244353;

int C[N][N], dp[N][N], sum[N][N];

int n, k, ans;

int qpow(int a, int b){
    int res = 1;
    while(b){
        if(b & 1) (res *= a) %= MOD;
        (a *= a) %= MOD;
        b >>= 1;
    }
    return res;
}

signed main(){

    cin >> n >> k;

    for(int i = 0; i <= n; i ++){

        C[i][0] = 1;

        for(int j = 1; j <= i; j ++)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;

    }

    dp[1][0] = 1;

    for(int i = 0; i <= k; i ++)
        sum[1][i] = 1;

    for(int i = 2; i <= n; i ++)
        for(int j = 1; j <= k; j ++){
            for(int x = 1; x < i; x ++)
                (dp[i][j] += sum[x][j - 1] * C[n - x][i - x] % MOD * qpow(k - j + 1, (i - x) * (i + x - 3) / 2) % MOD) %= MOD;
            sum[i][j] = (sum[i][j - 1] + dp[i][j]) % MOD;
        }
    
    for(int i = 1; i <= k; i ++)
        (ans += dp[n][i]) %= MOD;
    cout << ans << endl;

    return 0;
}*/

//E. 序列计数 (未完成)
#include<bits/stdc++.h>
using namespace std;

const int M = 2e7 + 7, N = 1e6 + 7, MX = 1e2 + 7;
const int MOD = 20170408;

bool f[M];

int prime[N], table[N], cnt;

int n, m, p;

struct matrix{

    int mat[MX][MX];

};

matrix operator * (matrix a, matrix b){
    matrix res;
    for(int i = 1; i <= p; i ++)
        for(int j = 1; j <= p; j ++)
            for(int k = 1; k <= p; k ++)
                (res.mat[i][j] += a.mat[i][k] * b.mat[k][j] % MOD) %= MOD;
    return res;
}

void init(){
    f[1] = 1;
    for(int i = 1; i <= m; i ++){
        if(!f[i]) prime[++ cnt] = i, table[prime[cnt] % p] ++;
        for(int j = 1; j <= cnt && prime[j] * i <= m; j ++){
            f[i * prime[j]] = 1;
            if(i % prime[j] == 0) break;
        }
    }
}

int main(){

    cin >> n >> m >> p;

    init();

    

    return 0;
}

//F. 幸运数字
/*#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e4 + 7;

int a[N], b[N];

int cnt = -1, cnt2, L, R, ans;

void init(int x){
    if(x > R) return;
    a[++ cnt] = x;
    init(x * 10 + 6);
    init(x * 10 + 8);
}

int lcm(int x, int y){
    int a = x, b = y;
    while(b){
        int t = a % b;
        a = b;
        b = t;
    }
    return x * y / a;
}

int dfs(int step, int sum, int l, int n){ // 枚举容斥原理中 a_1, a_2, a_3, ..., a_n 的子集
    if(l > n) return 0;
    if(step > cnt2){
        if(l == 1) return 0;
        if(sum % 2 == 1) return n / l;
        else return -n / l;
    }
    return dfs(step + 1, sum, l, n) + dfs(step + 1, sum + 1, lcm(l, b[step]), n);
}

signed main(){

    cin >> L >> R;
    
    init(0);
    sort(a + 1, a + cnt + 1);

    for(int i = 1; i <= cnt; i ++){
        bool f = true;
        for(int j = 1; j <= cnt2; j ++)
            if(a[i] % b[j] == 0) {f = false; break;}
        if(f) {
            if(a[i] <= R / 2) b[++ cnt2] = a[i];
            else ans += R / a[i] - (L - 1) / a[i]; //小优化
        }
    }
    sort(b + 1, b + cnt2 + 1, greater <int>());
    cout << dfs(1, 0, 1, R) - dfs(1, 0, 1, L - 1) + ans << endl;
    
    return 0;
}*/

//G. 硬币购物
/*#include<bits/stdc++.h>
using namespace std;

#define int long long
#define for(i, n) for(int i = 1; i <= n; i ++)

const int N = 1e5 + 7;

int dp[N], a[5], s[5], tmp[5], n, m, ans;

void dfs(int step, int mk[5]){
    if(step > 4){
        int sum = 0, cnt = 0;
        for(i, 4) if(mk[i]){
            cnt ++;
            sum += a[i] * (s[i] + 1);
        }
        if(sum <= m)
            ans += ((cnt & 1) ? -1 : 1) * dp[m - sum];
        return;
    }
    mk[step] = 1;
    dfs(step + 1, mk);
    mk[step] = 0;
    dfs(step + 1, mk);
}

signed main(){

    for(i, 4) cin >> a[i];
    cin >> n;

    dp[0] = 1;
    for(j, 4) for(i, N - 1) 
        if(i - a[j] >= 0) dp[i] += dp[i - a[j]];

    while(n --){
        for(i, 4) cin >> s[i];
        cin >> m;
        ans = 0;
        dfs(1, tmp);
        cout << ans << endl;
    }

    return 0;
}*/

//H. 能量采集
/*#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e5 + 7;

int sum[N], n, m, ans;

signed main(){

    cin >> n >> m;

    for(int i = min(n, m); i; i --){
        sum[i] = (n / i) * (m / i);
        for(int j = i + i; j <= min(n, m); j += i) sum[i] -= sum[j];
        ans += sum[i] * i;
    }
    cout << ans * 2 - n * m << endl;

    return 0;
}*/


