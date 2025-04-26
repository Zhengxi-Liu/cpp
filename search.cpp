/*#include<bits/stdc++.h>
using namespace std;
const int N = 20 + 7;
int dis[N], a[N], n, k, cnt = 0;
void dfs(int step, int sum){
	if(sum == k){
		cnt ++;
		return ;
	}
	if(sum > k)
		return ;
	if(sum + dis[step] < k)
		return ;
	if(step > n)
		return ;
	dfs(step + 1, sum + a[step]);
	dfs(step + 1, sum);
}
bool cmp(int a, int b){
	return a > b;
}
int main(){
	cin >> n >> k;
	for(int i = 1;i <= n;i ++)
		cin >> a[i];
	sort(a + 1, a + n + 1, cmp);
	for(int i = n;i >= 1;i --)
		dis[i] = dis[i + 1] + a[i];
	dfs(1, 0);
	cout << cnt << endl;
	return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 2e2 + 7;
int a[N], n, k, cnt;
void dfs(int step){
	if(step == k){
		if(n >= a[step - 1])
			cnt ++;
		return;
	}
	for(int i = a[step - 1];i <= n / (k - step + 1);i ++){
		a[step] = i;
		n -= i;
		dfs(step + 1);
		n += i;
	}
}
int main(){
	cin >> n >> k;
	a[0] = 1;
	dfs(1);
	cout << cnt << endl;
	return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 20 + 7;
int dis[N][N], vis[N], m[N], n, ans;
char c; string a[N];
void dfs(int step, int len){
	ans = max(ans, len);
	vis[step] ++;
	for(int i = 1;i <= n;i ++)
		if(vis[i] <= 1 && dis[step][i])
			dfs(i, len + m[i] - dis[step][i]);
	vis[step] --;
}
int main(){
	cin >> n;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
		m[i] = a[i].size();
		a[i] = " " + a[i];
	}
	cin >> c;
	for(int i = 1;i <= n;i ++)
		for(int j = 1;j <= n;j ++){
			for(int k = 1;k < min(m[i], m[j]);k ++)
				if(a[i].substr(m[i] - k + 1, k) == a[j].substr(1, k)){
					dis[i][j] = k;
					break;
				}
		}
	for(int i = 1;i <= n;i ++)
		if(a[i][1] == c)
			dfs(i, m[i]);
	cout << ans << endl;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int a[N], n, slen, len;
bool f[N];
bool dfs(int cnt, int sum, int step){
	if(cnt * len == slen)
		return true;
	if(sum == len)
		return dfs(cnt + 1, 0, 1);
	int fail = 0, rem = slen - (cnt * len + sum);
	if(rem < (len - sum))
		return false;
	for(int i = step;i <= n;i ++){
		if(f[i] || sum + a[i] > len || a[i] == fail)
			continue;
		if(a[i] == len - sum){
			f[i] = true;
			if(dfs(cnt, sum + a[i], i + 1))
				return true;
			f[i] = false;
			return false;
		}
		f[i] = true;
		if(dfs(cnt, sum + a[i], i + 1))
			return true;
		f[i] = false;
		fail = a[i];
		if(!sum || sum + a[i] == len)
			return false;
	}
	return false;
}
int main(){
	cin >> n;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
		slen += a[i];
	}
	sort(a + 1, a + n + 1);
	reverse(a + 1, a + n + 1);
	for(len = a[1];len <= slen;len ++)
		if(slen % len == 0 && dfs(0, 0, 1)){
			cout << len << endl;
			break;
		}
	return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 7;
int f[N][N], a[N][N], n, m;
int dx[4] = {1, 0, 0,-1};
int dy[4] = {0, 1,-1, 0};
int dfs(int x, int y){
	if(f[x][y])
		return f[x][y];
	int res = 1;
	for(int i = 0;i < 4;i ++){
		int nx = dx[i] + x, ny = dy[i] + y;
		if(nx < 1 || nx > n || ny < 1 || ny > m)
			continue;
		if(a[nx][ny] >= a[x][y])
			continue;
		res = max(res, dfs(nx, ny) + 1);
	}
	return f[x][y] = res;
}
int main(){
	cin >> n >> m;
	for(int i = 1;i <= n;i ++)
		for(int j = 1;j <= m;j ++)
			cin >> a[i][j];
	int ans = 0;
	for(int i = 1;i <= n;i ++)
		for(int j = 1;j <= m;j ++)
			ans = max(ans, dfs(i, j));
	cout << ans << endl;
	return 0;
}*/