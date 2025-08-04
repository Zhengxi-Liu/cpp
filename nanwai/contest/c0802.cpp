//D. 复合函数查询
/*#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e5 + 7;

int n, q, a, t, l = -1e18, r = 1e18, add;

signed main(){

    cin >> n;

    for(int i = 1; i <= n; i ++){

        cin >> a >> t;

        if(t == 1){
            add += a;
            l += a;
            r += a;
        }

        if(t == 2){
            l = max(l, a);
            r = max(r, a);
        }

        if(t == 3){
            l = min(l, a);
            r = min(r, a);
        }

    }

    cin >> q;

    while(q --){

        cin >> a;

        a += add;

        if(a < l) a = l;
        if(a > r) a = r;

        cout << a << endl;

    }

    return 0;
}*/

//F. 树上游戏
/*#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e5 + 7;

vector <int> a[N];

int son[N], dep[N], fa[N];

int top[N], sz[N], sum[N];

int val[N], n, m, x, y, t, cnt;

void dfs1(int x, int f){
    dep[x] = dep[f] + 1, sz[x] = val[x], fa[x] = f;
    for(int to : a[x]){
        if(to == f) continue;
        dfs1(to, x);
        if(sz[to] > sz[son[x]]) son[x] = to;
    }
    sz[x] = sz[son[x]] + val[x];
}

void dfs2(int x, int id){
    top[x] = id;
    sum[id] += val[x];
    if(!son[x]) return;
    dfs2(son[x], id);
    for(int to : a[x]){
        if(to == fa[x] || to == son[x]) continue;
        dfs2(to, ++ cnt);
    }
}

signed main(){

    cin >> t;

    for(int cs = 1; cs <= t; cs ++){

        cin >> n >> m;

        for(int i = 1; i <= n; i ++){
            cin >> val[i];
            a[i].clear();
            sum[i] = top[i] = dep[i] = sz[i] = fa[i] = son[i] = 0;
        }

        for(int i = 1; i < n; i ++){
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
        }

        cnt = 1;
        dfs1(1, 0);
        dfs2(1, 1);

        sort(sum + 1, sum + cnt + 1, greater <int>());

        int ans = 0;
        for(int i = 1; i <= min(cnt, m); i ++)
            ans += sum[i];
        cout << "Case #" << cs << ": " << ans << endl;
        
    }

    return 0;
}*/

//H. 链加平方数
#include<bits/stdc++.h>
using namespace std;

#define mid ((l + r) >> 1)
#define kl (k << 1)
#define kr ((k << 1) | 1)

const int N = 1e5 + 7;

vector <int> a[N];

int son[N], fa[N], dep[N], sz[N];

int dfn[N], d[N], top[N], cnt;

void dfs1(int x, int f){
	dep[x] = dep[f] + 1, sz[x] = 1, fa[x] = f;
	for(int to : a[x]){
		if(to == f) continue;
		dfs1(to, x);
		sz[x] += sz[to];
		if(sz[to] > sz[son[x]]) son[x] = to;
	}
}

void dfs2(int x, int id){
	top[x] = id, dfn[x] = ++ cnt, d[cnt] = x;
	if(!son[x]) return;
	dfs2(son[x], id);
	for(int to : a[x]){
		if(to == fa[x] || to == son[x]) continue;
		dfs2(to, to);
	}
}

struct node{
	int qsum, sum, cnt;
}T[N << 2];

void push_down(int k, int l, int r){
	T[kl].qsum += T[k].qsum, T[kl].sum += T[k].sum, T[kl].cnt += T[k].cnt;
	int m = mid - l + 1;
	T[kr].qsum += T[k].qsum + 2 * m * T[k].sum + T[k].cnt * m * m;
	T[kr].sum += T[k].sum + m * T[k].cnt, T[kr].cnt += T[k].cnt;
	T[k].qsum = T[k].sum = T[k].cnt = 0;
}

void upd(int k, int l, int r, int x, int y, int v){
	if(l >= x && r <= y){
		int v = l - x + v;
		T[k].cnt ++, T[k].qsum += v * v, T[k].sum += v;
		return;
	}
	push_down(k, l, r);
	if(mid >= x) upd(kl, l, mid, x, y, v);
	if(mid < y) upd(kr, mid + 1, r, x, y, v);
}

int qry(int k, int l, int r, int x){
	if(l == r) return T[k].qsum;
	push_down(k, l, r);
	if(mid >= x) return qry(kl, l, mid, x);
	else return qry(kr, mid + 1, r, x);
}

int n, q, x, y, op;

void LCA(int x, int y){
	int t1 = x, t2 = y, tmp = 1;
	while(top[x] != top[y]){
		if(dep[top[x]] < dep[top[y]]) swap(x, y);
		x = fa[top[x]];
	}
	int lca = dep[x] < dep[y] ? x : y;
	x = t1, y = t2;
	while(top[x] != top[lca]){
		
	}
}


int main(){

	cin >> n;
	
	for(int i = 1; i <= n; i ++){
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}

	dfs1(1, 0);
	dfs2(1, 1);

	cin >> q;

	while(q --){

		cin >> op >> x;

		if(op == 1){
			cin >> y;
			LCA(x, y);
		}
		
		else{
			cout << qry(1, 1, n, x) << endl;
		}
		

		// for(int i = 1; i <= n; i ++)
		// 	cout << qry(1, 1, n, i) << ' ';
		// cout << endl;

	}



	return 0;
}