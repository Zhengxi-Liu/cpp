//C. 数列分块6
/*#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;

int tmp[N];

vector <int> b[N];

int n, op, l, r, c, block;

void rebuild(){
    int tot = 0;
    for(int i = 1; i <= block + 1; i ++){
        for(int j : b[i]) tmp[++ tot] = j;
        b[i].clear();
    }
    block = sqrt(tot);
    for(int i = 1; i <= tot; i ++)
        b[i / block].push_back(tmp[i]);
}

void insert(int pos, int v){
    int cnt = 0, idx;
    for(int i = 0; i <= block + 1; i ++){
        cnt += b[i].size();
        if(cnt >= pos){
            idx = i;
            cnt = pos - cnt + b[i].size();
            break;
        }
    }
    b[idx].insert(b[idx].begin() + cnt - 1, v);
    if(b[idx].size() > 5 * block) rebuild();
}

int qry(int pos){
    int cnt = 0;
    for(int i = 0; i <= block + 1; i ++){
        cnt += b[i].size();
        if(cnt >= pos) return b[i][pos - cnt + b[i].size() - 1];
    }
    return 0;
}

int main(){

    cin >> n;

    block = sqrt(n);

    for(int i = 1; i <= n; i ++){
        scanf("%d", &c);
        b[i / block].push_back(c);
    }

    while(n --){
        scanf("%d %d %d %d", &op, &l, &r, &c);
        if(!op) insert(l, r);
        else printf("%d\n", qry(r));
    }

    return 0;
}*/

//D. 小 Y 的背包计数问题
/*#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e5 + 7, M = 317 + 7, MOD = 23333333;

int n, m, sq, ans;

int dp1[N], dp2[M][N];

int sum[N];

signed main(){

    cin >> n;

    sq = sqrt(n);

    dp1[0] = 1;

    // 从 1 至 √n 的 这些物品

    for(int i = 1; i <= sq; i ++){

        // 对于所有 j, 统计 ∑ dp1[k], k + i <= j, 即所有能转移过来的值
        // sum[j] = dp[j] + dp[j - i] + dp[j - 2i] + dp[j - 3i] + ...
        for(int j = 0; j <= n; j ++)
            sum[j] = (dp1[j] + ((j >= i) ? sum[j - i] : 0)) % MOD;
        
        for(int j = 0; j <= n; j ++){
            dp1[j] = sum[j];
            // 如果超出了第 i 个物品的限制 (i + 1) * i, 就减去超出范围的和 (那些无法转移过来的, k + i * i < j)
            // sum[j] - sum[j - (i + 1) * i] = dp[j] + dp[j - i] + ... - dp[j - (i + 1)i] - dp[j - (i + 2)i] - ...
            if(j >= (i + 1) * i) dp1[j] = (dp1[j] - sum[j - (i + 1) * i] + MOD) % MOD;
        }
        
    }

    ans = dp1[n];

    // 从 √n + 1 至 n 的这些物品

    dp2[0][0] = 1;

    for(int i = 1; i <= sq; i ++) // 物品个数
        for(int j = i * (sq + 1); j <= n; j ++){ // i 个物品占用的最小空间
            // 每个都加 1 和 前面新加入一个物品 √n + 1
            dp2[i][j] = (dp2[i][j - i] + dp2[i - 1][j - (sq + 1)]) % MOD;
            (ans += dp2[i][j] * dp1[n - j] % MOD) %= MOD;
        }

    cout << ans << endl;

    return 0;
}*/

//E. 猪圈
/*#include<iostream>
#include<cmath> 
using namespace std;

const int N = 5e5 + 7, M = 1e4 + 7;

int n, m, t, x, block;

int a[N];

long long s[M], ans;

long long qry(int x, int y){
	int l = x / block, r = y / block;
	long long res = 0;
	if(l == r){
		for(int i = x; i <= y; i ++)
			res += a[i];
		return res; 
	}
	for(int i = l + 1; i <= r - 1; i ++) 
		res += s[i];
	for(int i = x; i < (l + 1) * block; i ++)
		res += a[i];
	for(int i = r * block; i <= y; i ++)
		res += a[i];
	return res;	
}

int main(){
	
	cin >> n >> m >> t;
	
	block = sqrt(n);
	
	for(int i = 1; i <= n; i ++){
		scanf("%d", &a[i]);
		s[i / block] += a[i]; 		
	}
	
	while(m --){
		
		int l, r;
		
		scanf("%d %d", &l, &r); 
		
		if(t){
			if(ans < 0) ans *= -1;
			l = (l ^ ans) % n + 1;
			r = (r ^ ans) % n + 1;
		}
        if(l > r) swap(l, r);
        l = max(l, 1);
        r = min(r, n);
		ans = qry(l, r);
		printf("%lld\n", ans);
		
	}
	
	return 0;
}*/

//F. 教主的魔法
/*#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7, M = 1e3 + 7;

typedef pair <int, int> PI;

vector <PI> b[M];

int a[N], tag[M];

int n, q, l, r, v, sq;

char c;

void push_down(int k){
    for(int i = 0; i < b[k].size(); i ++)
        b[k][i].first += tag[k];
    tag[k] = 0;
}

void upd(int x, int y, int v){
    int l = x / sq, r = y / sq;
    if(l == r){
        push_down(l);
        for(int i = 0; i < b[l].size(); i ++)
            if(b[l][i].second >= x && b[l][i].second <= y)
                b[l][i].first += v;
        sort(b[l].begin(), b[l].end());
        return;
    }
    for(int i = l + 1; i < r; i ++)
        tag[i] += v;
    push_down(l), push_down(r);
    for(int i = 0; i < b[l].size(); i ++)
        if(b[l][i].second >= x) b[l][i].first += v;
    for(int i = 0; i < b[r].size(); i ++)
        if(b[r][i].second <= y) b[r][i].first += v;
    sort(b[l].begin(), b[l].end());
    sort(b[r].begin(), b[r].end());
}

int qry(int x, int y, int v){
    int l = x / sq, r = y / sq, res = 0;
    if(l == r){
        push_down(l);
        for(PI val : b[l])
            if(val.second >= x && val.second <= y && val.first >= v) 
                res ++;
        return res;
    }
    for(int i = l + 1; i < r; i ++){
        int k = lower_bound(b[i].begin(), b[i].end(), (PI){v - tag[i], 0}) - b[i].begin();
        res += b[i].size() - k;
    }
    push_down(l), push_down(r);
    for(PI val : b[l])
        if(val.second >= x && val.first >= v) res ++;
    for(PI val : b[r])
        if(val.second <= y && val.first >= v) res ++;
    return res;
}

int main(){

    cin >> n >> q;

    sq = sqrt(n);

    for(int i = 1; i <= n; i ++){
        scanf("%d", &a[i]);
        b[i / sq].push_back({a[i], i});
    }

    for(int i = 0; i <= sq + 1; i ++)
        sort(b[i].begin(), b[i].end());

    while(q --){
        cin >> c >> l >> r >> v;
        if(c == 'M') upd(l, r, v);
        else cout << qry(l, r, v) << endl;
    }

    return 0;
}*/

//G. 蒲公英
/*#include<bits/stdc++.h>
using namespace std;

const int N = 4e4 + 7, M = 2e2 + 7;

int rg_mx[M][M], tmp[N], sum[M][N];

int L[N], R[N], tot;

int a[N], cmd[N], cnt;

int n, q, l, r, ans, block;

void prep(){

    for(int i = 0; i <= tot; i ++){
        int now = i, mx = 0;
        memset(tmp, 0, sizeof(tmp));
        for(int j = L[i]; j <= n; j ++){
            tmp[a[j]] ++;
            if(tmp[a[j]] > tmp[mx]) mx = a[j];
            else if(tmp[a[j]] == tmp[mx] && a[j] < mx) mx = a[j];
            if(j == R[now]){
                rg_mx[i][now] = mx;
                now ++;
            }
        }
    }

    for(int i = 0; i <= tot; i ++){
        for(int j = 1; j <= cnt; j ++)
            sum[i][j] += sum[max(0, i - 1)][j];
        for(int j = L[i]; j <= R[i]; j ++)
            sum[i][a[j]] ++;
    }

}

int qry(int x, int y){

    int l = x / block, r = y / block, res = 0;

    if(l == r){
        for(int i = x; i <= y; i ++)
            tmp[a[i]] = 0;
        for(int i = x; i <= y; i ++){
            tmp[a[i]] ++;
            if(tmp[a[i]] > tmp[res]) res = a[i];
            else if(tmp[a[i]] == tmp[res] && a[i] < res) res = a[i];
        }
        return res;
    }

    vector <int> val;

    for(int i = x; i <= R[l]; i ++)
        val.push_back(a[i]);
    for(int i = L[r]; i <= y; i ++)
        val.push_back(a[i]);
    
    for(int v : val) tmp[v] = sum[r - 1][v] - sum[l][v];
    for(int v : val) tmp[v] ++;
    for(int v : val){
        if(tmp[res] < tmp[v]) res = v;
        else if(tmp[res] == tmp[v] && v < res) res = v;
    }

    int d = rg_mx[l + 1][r - 1], S = sum[r - 1][d] - sum[l][d];

    if(tmp[res] < S) res = d;
    if(tmp[res] == S && d < res) res = d;

    return res;

}

int main(){

    scanf("%d %d", &n, &q);
    
    block = sqrt(n);

    for(int i = 1; i <= n; i ++){
        scanf("%d", &a[i]);
        cmd[++ cnt] = a[i];
    }

    sort(cmd + 1, cmd + cnt + 1);
    cnt = unique(cmd + 1, cmd + cnt + 1) - cmd - 1;

    for(int i = 1; i <= n; i ++){
        a[i] = lower_bound(cmd + 1, cmd + cnt + 1, a[i]) - cmd;
        if(!(i % block)) L[i / block] = i;
        if(i % block == block - 1) R[i / block] = i;
    }

    tot = n / block;
    L[0] = 1, R[tot] = n;
    
    prep();

    while(q --){

        scanf("%d %d", &l, &r);
        
        l = (l + ans - 1) % n + 1;
        r = (r + ans - 1) % n + 1;
        if(l > r) swap(l, r);

        ans = cmd[qry(l, r)];
        printf("%d\n", ans);
        
    }

    return 0;
}*/

//J. 小B的询问
/*#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 5e4 + 7;

int n, m, k, x, y, block, tot = 1;

struct str{
    int l, r, id;
};

vector <str> b[N];

int a[N], cnt[N], L[N], R[N], ans[N];

bool cmp(str a, str b){
    return a.r < b.r;
}

signed main(){

    cin >> n >> m >> k;

    block = sqrt(n);

    for(int i = 1; i <= n; i ++){
        cin >> a[i];
        if(!(i % block)) L[++ tot] = i;
        if(i % block == block - 1) R[tot] = i;
    }
    L[1] = 1, R[tot] = n;

    for(int i = 1; i <= m; i ++){
        cin >> x >> y;
        b[x / block + 1].push_back({x, y, i});
    }

    for(int i = 1; i <= tot; i ++)
        sort(b[i].begin(), b[i].end(), cmp);
    
    for(int i = 1; i <= tot; i ++){
        if(!b[i].size()) continue;
        str tmp = b[i][0];
        memset(cnt, 0, sizeof(cnt));
        int res = 0;
        for(int j = tmp.l; j <= tmp.r; j ++)
            res += 2 * cnt[a[j]] + 1, cnt[a[j]] ++;
        int l = tmp.l, r = tmp.r, f = 0;
        ans[tmp.id] = res;
        for(str now : b[i]){
            if(!(f ++)) continue;
            while(l > now.l) res += cnt[a[-- l]] * 2 + 1, cnt[a[l]] ++;
            while(l < now.l) res -= (cnt[a[l]] * 2 - 1), cnt[a[l]] --, l ++;
            while(r < now.r) res += cnt[a[++ r]] * 2 + 1, cnt[a[r]] ++;
            ans[now.id] = res;
        }
    }

    for(int i = 1; i <= m; i ++)
        cout << ans[i] << endl;

    return 0;
}*/

