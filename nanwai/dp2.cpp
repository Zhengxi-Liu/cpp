//A. 传递消息
/*#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;

vector <int> a[N];

int dp[N], n, x;

void DP(int x, int fa){
	pair <int, int> s[N];
	int cnt = 0;
	for(int i = 0; i < a[x].size(); i ++){
		int to = a[x][i];
		if(to == fa) continue;
		DP(to, x);
		s[++ cnt] = {dp[to], to};
	}
	//cout << x << ": ";
	sort(s + 1, s + cnt + 1);
	for(int i = 1; i <= cnt; i ++){
		int to = s[i].second;
		//cout << to << ' ' << dp[to] + cnt - i + 1 << " / "; 
		dp[x] = max(dp[x], dp[to] + cnt - i + 1);
	}
	
	//cout << dp[x] << endl;
} 

int main(){
	
	cin >> n;
	
	for(int i = 0; i < n; i ++){
		cin >> x;
		if(x != -1) a[x].push_back(i);
	}
	
	DP(0, -1);
	
	cout << dp[0] << endl;
	
	return 0;
} */

//B. Caves
/*#include<bits/stdc++.h>
using namespace std;

//dp[x][j][0/1]
// x: current node, j: number of nodes visited, 0/1: returned to root

const int N = 5e2 + 7;

vector <int> a[N], b[N];

int dp[N][N][2], sz[N], tmp[N][2];

int n, q, x, d;

void DP(int x, int fa){
	
	dp[x][1][0] = dp[x][1][1] = 0;
	sz[x] = 1;
	
	for (int i = 0; i < a[x].size(); i ++){
		
		int to = a[x][i], cst = b[x][i];
		
		if (to == fa) continue;
		
		DP(to, x);
		
		sz[x] += sz[to];
		
		for (int j = 1; j <= sz[x]; j ++) {
			tmp[j][0] = dp[x][j][0];
			tmp[j][1] = dp[x][j][1];
		}
		for (int j = 2; j <= sz[x]; j ++)
			for (int k = 1; k <= sz[to] && k < j; k ++){
				dp[x][j][0] = min(dp[x][j][0], dp[to][k][0] + tmp[j - k][1] + cst);
				dp[x][j][0] = min(dp[x][j][0], dp[to][k][1] + tmp[j - k][0] + cst * 2);
				dp[x][j][1] = min(dp[x][j][1], dp[to][k][1] + tmp[j - k][1] + cst * 2);
			}
		
	}

}

void prep(){
	for (int i = 0; i < n; i ++){
		a[i].clear();
		b[i].clear();
		sz[i] = 0;
	}
	memset(dp, 0x3f, sizeof(dp));
}

int main(){
	
	int cx = 0;
	while (cin >> n && n){
		
		cx ++;
		
		prep();
		
		for (int i = 1; i < n; i ++){
			cin >> x >> d;
			a[x].push_back(i);
			b[x].push_back(d); 
		}
		
		DP(0, -1);
		
		cin >> q;
		
		cout << "Case " << cx << ":\n";
		
		while (q --){
			
			cin >> x;
			for (int i = n; i >= 1; i --)
				if(dp[0][i][0] <= x){
					cout << i << endl;
					break;
				}
		}
		
	}
	
	return 0;
}*/

//C. 树上两条路径
/*#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e5 + 7;

vector <int> a[N];

int val[N], n, x, y;

int dp[N];  // 当前树内的最优解
int dm[N];  // 树内的直径 (端点不一定在根节点) a.k.a. 树内单条链的最大和值
int two[N]; // 两条链: 一条是从根节点到叶子的, 另一条没有限制 (这种情况下的最优解)
int mxs[N]; // 子节点单条链的最优解
int one[N]; // 一条从根节点到叶子的链的最大和值

void DP(int x, int fa){

    dp[x] = dm[x] = two[x] = one[x] = val[x];

    for(int to : a[x]){
        
        if(to == fa) continue;

        DP(to, x);

        // 应为更新次序原因, 考虑的是当前不包含这个子树的树 与 这个子树 合并

        dp[x] = max(dp[x], dp[to]);           // 用子树最优解更新 root 最优解
        dp[x] = max(dp[x], two[to] + one[x]); // 子树的一条 root - leaf 的链和当前的 root - leaf 并成一条链
        dp[x] = max(dp[x], two[x] + one[to]); // 与上同理, 只不过第二条链变了位置
        dp[x] = max(dp[x], dm[to] + dm[x]);   // 子树直径 + 当前直径

        dm[x] = max(dm[x], dm[to]);           // 用子树直径更新 root 直径
        dm[x] = max(dm[x], one[x] + one[to]); // 把子树的 root - leaf 链 和 当前的 root - leaf 链合并成直径

        two[x] = max(two[x], two[to] + val[x]);          // 把根节点接到 root - leaf 的链上去
        two[x] = max(two[x], one[x] + dm[to]);           // 当前的最长 root - leaf 链, 再加上子树的直径
        two[x] = max(two[x], mxs[x] + one[to] + val[x]); // 当前树中选一条 diameter, 再加上子树的 root - leaf 的链

        mxs[x] = max(mxs[x], dm[to]); // 统计子树最大直径

        one[x] = max(one[x], one[to] + val[x]); // 从子树到叶子

    }

}

signed main(){

    cin >> n;

    for(int i = 1; i <= n; i ++)
        cin >> val[i];

    for(int i = 1; i < n; i ++){
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }

    DP(1, 0);

    cout << dp[1] << endl;

    return 0;
}*/

//E. 购买商品
/*#include<bits/stdc++.h>
using namespace std;

const int N = 16 + 1, M = (1 << N);

int dp[M], tmp[M];

int n, m, x, y;

int main(){
	
	cin >> n >> m;
	
	memset(dp, 0x3f, sizeof(dp));
	dp[0] = 0;
	
	int maxn = (1 << m) - 1;
	
	for(int i = 1; i <= n; i ++){
		cin >> x;
		memcpy(tmp, dp, sizeof(dp));
		for(int j = 0; j < m; j ++){
			cin >> y;
			for(int b = 0; b <= maxn; b ++){
				if((b >> j) & 1) continue;
				dp[b + (1 << j)] = min(dp[b + (1 << j)], dp[b] + y);
			}
		}
		for(int b = 0; b <= maxn; b ++){
			dp[b] = min(dp[b] + x, tmp[b]);
			//cout << dp[b] << ' ';
		}
		//cout << endl;
	}
	cout << dp[maxn] << endl;
	
	return 0;
} */

//F. 田忌赛马
/*#include<bits/stdc++.h>
using namespace std;

const int N = (1 << 20);

int dp[N], tmp[N];

int n, m, P, g, A, p[21][21];

vector < pair <int, int> > gft[21];

int main(){
	
	cin >> n >> m;
	
	for(int i = 1; i <= m; i ++){
		cin >> P >> g >> A;
		gft[P].push_back({g, A});
	}
	
	int maxn = (1 << n) - 1;
	
	for(int i = 1; i <= n; i ++)	
		for(int j = 1; j <= n; j ++)
			cin >> p[i][j];
	
	for(int i = 1; i <= n; i ++){
		memcpy(tmp, dp, sizeof(dp));
		for(int j = 0; j < n; j ++){
			for(int b = 0; b <= maxn; b ++){
				if((b >> j) & 1) continue;
				int nw = b + (1 << j);
				dp[nw] = max(dp[nw], tmp[b] + p[j + 1][i]);
			}
		}
		for(int b = 0; b <= maxn; b ++){
			int pls = 0;
			for(int x = 0; x < gft[i].size(); x ++){
				int lm = gft[i][x].first, mn = gft[i][x].second;
				if(dp[b] >= lm) pls += mn;
			}
			dp[b] += pls;
		}
	}
	cout << dp[maxn] << endl;
	
	return 0;
}
*/

//G. 交换茸角
/*#include <bits/stdc++.h>
using namespace std;

const int N = 16, M = (1 << N);

int dp[M];

int a[N], b[N], tmp[N * 2];

int n, c, cnt, x, y;

int check(int bex) {
    cnt = 0;
    for(int j = 0; j < n; j++)
        if((bex >> j) & 1) tmp[++ cnt] = a[j + 1], tmp[++ cnt] = b[j + 1];
    sort(tmp + 1, tmp + cnt + 1);
    for(int i = 1; i <= cnt; i += 2)
        if (tmp[i + 1] - tmp[i] > c) return -1;
    return cnt / 2 - 1;
}

int main(){

    cin >> n >> c;

    int maxn = (1 << n) - 1;

    for(int i = 1; i <= n; i++) {
        cin >> x >> y;
        a[i] = min(x, y), b[i] = max(x, y);
    }
    dp[maxn] = check(maxn);

    for(int i = 1; i < maxn; i++) dp[i] = check(i);

    for(int i = 1; i <= maxn; i++) {
        if(dp[i] == -1)
            continue;
        for(int j = i & (i - 1); j != i; j = (j - 1) & i) {  // 遍历 i 的所有子集
            if(dp[j] == -1 || dp[i ^ j] == -1) continue;  // i ^ j 为 i 与 j 不相交的部分
            dp[i] = min(dp[i], dp[j] + dp[i ^ j]);
        }
    }
    cout << dp[maxn] << endl;

    return 0;
}*/

//H. 分裂
/*#include<bits/stdc++.h>
using namespace std;

const int N = 11, M = (1 << 10) + 7;

int dp[M][M], sz1[M], sz2[M];

int a[N], b[N], n, m, mxn, mxm;

void prep(){
    for(int bex = 1; bex <= mxn; bex ++){
        for(int j = 0; j < n; j ++) 
            if((bex >> j) & 1) sz1[bex] += a[j + 1];
    }
    for(int bex = 1; bex <= mxm; bex ++){
        for(int j = 0; j < m; j ++) 
            if((bex >> j) & 1) sz2[bex] += b[j + 1];
    }
}

int main(){

    cin >> n;
    mxn = (1 << n) - 1;
    for(int i = 1; i <= n; i ++)
        cin >> a[i];
    
    cin >> m;
    mxm = (1 << m) - 1;
    for(int i = 1; i <= m; i ++)
        cin >> b[i];
    
    prep();

    for(int i = 1; i <= mxn; i ++)
        for(int j = 1; j <= mxm; j ++){
            for(int k = 0; k < max(n, m); k ++){
                if(k < n && i & (1 << k)) dp[i][j] = max(dp[i][j], dp[i - (1 << k)][j]);
                if(k < m && j & (1 << k)) dp[i][j] = max(dp[i][j], dp[i][j - (1 << k)]);
            }
            if(sz1[i] == sz2[j]) dp[i][j] += 2; // 如果已经相等, 就不需要加上再合并一个的费用了
            // 其实就是每个国家已经加上了再合并另一个国家的费用, 这时候发现当前国家已经可以拆分了, 就不用再加了
        }
    cout << n + m - dp[mxn][mxm] << endl;
    
    return 0;
}*/

//I. 加分二叉树
/*#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define mid ((l + r) >> 1)

const int N = 30 + 7;

int a[N], dp[N][N], md[N][N], n, cnt;

int dfs(int l, int r){
	if(l > r) return 1ll; 
	if(dp[l][r] != -1) return dp[l][r];
	if(l == r) return dp[l][r] = a[l];
	int res = 0;
	for(int i = l; i <= r; i ++){
        int tmp = dfs(l, i - 1) * dfs(i + 1, r) + a[i];
		if(tmp > res){
            res = tmp;
            md[l][r] = i;
        }
    }
	return dp[l][r] = res;
} 

void print(int x, int l, int r){
    if(l > r) return;
    if(l == r){
        cout << l << ' ';
        return;
    }
    cout << md[l][r] << ' ';
    print(md[l][md[l][r] - 1], l, md[l][r] - 1);
    print(md[md[l][r] + 1][r], md[l][r] + 1, r);
}

signed main(){
	
	cin >> n;
	
	memset(dp, -1, sizeof(dp));
	
	for(int i = 1; i <= n; i ++)
		cin >> a[i];
	
	cout << dfs(1, n) << endl;
	
    print(md[1][n], 1, n);
    cout << endl;

	return 0;
}*/

//J. 祖玛
/*#include<bits/stdc++.h>
using namespace std;

const int N = 1e2 + 7;

int dp[N][N][10];
// dp[l][r][k]
// 在 区间 [l,r] 左侧有 k - 1 个与 l 相同的连续的数

int a[N], n, k;

int dfs(int l, int r, int cnt){

    cnt = min(cnt, k);
    if(l > r) return 0;

    int &res = dp[l][r][cnt];
    if(res != -1) return res;
    res = dfs(l + 1, r, 1) + k - cnt; // 将左边的 cnt - 1 个数以及 l 合并, 共需要增加 k - cnt 个数来达到 k

    for(int i = l + 1; i <= r; i ++)
        if(a[l] == a[i]){ // 如果 l 的颜色与分割点 i 相同
            res = min(res, dfs(l + 1, i - 1, 1) // 从 l + 1 到 i - 1 的这一段
                + dfs(i, r, cnt + 1)); // 从分割点 i 到 r
        }
    return res;

}

int main(){

    cin >> n >> k;

    memset(dp, -1, sizeof(dp));
    for(int i = 1; i <= n; i ++)
        cin >> a[i];

    cout << dfs(1, n, 1) << endl;

    return 0;
}*/

//K. 重排排列
/*#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e3 + 7;

int dp[N][N], n;

struct str{
    int v, p;
}a[N];

bool cmp(str a, str b){
    return a.v < b.v;
}

signed main(){

    cin >> n;

    for(int i = 1; i <= n; i ++)
        cin >> a[i].v, a[i].p = i;

    sort(a + 1, a + n + 1, cmp); // 贪心: 挪动最多的一定是最大的, 因为 + 第二大的 - 第一大的 绝对吃亏

    for(int len = 1; len <= n; len ++)
        for(int i = 1; i + len - 1 <= n; i ++){
            int j = i + len - 1;
            dp[i][j] = max(dp[i + 1][j] + a[len].v * abs(a[len].p - i), dp[i][j - 1] + a[len].v * abs(a[len].p - j));
        }
    cout << dp[1][n] << '\n';
    
    return 0;
}*/

//L. 替换区间
/*#include<bits/stdc++.h>
using namespace std;

const int N = 1e2 + 7;

int all[N][N][N], none[N][N][N], tmp[N][N][N];

// all [l][r][x] 代表将区间 [l, r] 内所有值都变为 x 的最小 cost
// none [l][r][x] 代表将区间 [l, r] 内所有值都改为非 x 的最小 cost

int n, x, y, t;

int solve(){

    memset(all, 0x3f, sizeof(all));
    memset(none, 0x3f, sizeof(none));
    memset(tmp, 0x3f, sizeof(tmp));

    cin >> n >> x;

    for(int i = 1; i <= n; i ++){
        cin >> y;
        for(int j = 1; j <= x; j ++){
            if(j == y){
                all[i][i][j] = 0;
                none[i][i][j] = 1;
            }
            else {
                all[i][i][j] = 1;
                none[i][i][j] = 0;
            }
        }
    }

    for(int len = 2; len <= n; len ++)
        for(int l = 1; l + len - 1 <= n; l ++){

            int r = l + len - 1;
            for(int j = 1; j <= x; j ++){
                for(int mid = l; mid + 1 <= r; mid ++){
                    all[l][r][j] = min(all[l][r][j], all[l][mid][j] + all[mid + 1][r][j]);
                    tmp[l][r][j] = min(tmp[l][r][j], none[l][mid][j] + none[mid + 1][r][j]);
                }
                all[l][r][j] = min(all[l][r][j], tmp[l][r][j] + 1); // 根据题意, 可以从没有 j 的情况转换, 将所有元素都变为 j
                for(int k = 1; k <= x; k ++){
                    if(k == j) continue;
                    none[l][r][k] = min(none[l][r][k], tmp[l][r][j] + 1); // 将所有元素都变为 j, 因此不包含非 j 的任何值
                }
            }
            for(int j = 1; j <= x; j ++) none[l][r][j] = min(none[l][r][j], tmp[l][r][j]);

        }

    int res = n;
    for(int j = 1; j <= x; j ++)
        res = min(res, all[1][n][j]);
    return res;

}

int main(){

    cin >> t;

    while(t --)
        cout << solve() << endl;

    return 0;
}*/
