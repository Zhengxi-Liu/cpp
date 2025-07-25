//D. 版本保存
/*#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 7;

vector <int> a[N];

int fa[N], v[N];

map <int, int> pos; 

int now, n, x, tot;

string s;

int main(){
	
	cin >> n;
	
	v[0] = -1;
	
	while(n --){
		
		cin >> s;
		
		if(s != "DELETE") cin >> x;
		else now = fa[now];
		
		if(s == "ADD") a[now].push_back(++ tot), fa[tot] = now, v[tot] = x, now = tot;
		if(s == "SAVE") pos[x] = now;
		if(s == "LOAD") now = pos[x];
		cout << v[now] << ' ';
		
	}
	
	return 0;
}*/

//E. 种橙子
/*#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e3 + 7;

int up[N], stk[N], l[N], r[N];

int n, m, ans, top;

char c;

signed main(){

	cin >> n >> m;

    up[0] = up[m + 1] = -1;
	
    while(n --){

        for(int i = 1; i <= m; i ++){
            cin >> c;
            if(c == '#') up[i] = 0;
            else up[i] ++;
        }

        stk[top = 0] = 0;
        for(int i = 1; i <= m; i ++){
            while(top && up[stk[top]] >= up[i]) top --;
            l[i] = stk[top];
            stk[++ top] = i;
        }

        stk[top = 0] = m + 1;
        for(int i = m; i >= 1; i --){
            while(top && up[stk[top]] > up[i]) top --;
            r[i] = stk[top];
            stk[++ top] = i;
        }

        for(int i = 1; i <= m; i ++){
            int x = i - l[i], y = r[i] - i;
            cout << up[i] << ' ' << l[i] << ' ' << r[i] << " / ";
            ans += up[i] * (up[i] + 1) / 2 * (x + y) * x * y / 2;
        }
        cout << endl;
    
    }
	
	cout << ans << endl;

	return 0;
}*/

//F. LIS升级
/*#include<bits/stdc++.h>
using namespace std;

#define int long long
#define mid ((l + r) >> 1)
#define kl k << 1
#define kr (k << 1) | 1

const int N = 2e5 + 7;

int a[N], b[N], cmd[N << 1], dp[N];

int n, cnt, ans;

struct Tree{

    int mx[N << 3];
    
    void upd(int k, int l, int r, int x, int v){
        if(l == x && r == x){
            mx[k] = max(mx[k], v);
            return;
        }
        if(mid >= x) upd(kl, l, mid, x, v);
        else upd(kr, mid + 1, r, x, v);
        mx[k] = max(mx[kl], mx[kr]);
    }

    int query(int k, int l, int r, int x, int y){
        if(x > y) return 0;
        if(l >= x && r <= y) return mx[k];
        int res = -1e17;
        if(mid >= x) res = query(kl, l, mid, x, y);
        if(mid + 1 <= y) res = max(res, query(kr, mid + 1, r, x, y));
        return res;
    }

}T[2];


signed main(){

    cin >> n;

    for(int i = 1; i <= n; i ++){
        cin >> a[i] >> b[i];
        cmd[++ cnt] = a[i], cmd[++ cnt] = b[i];
    }

    sort(cmd + 1, cmd + cnt + 1);
    cnt = unique(cmd + 1, cmd + cnt + 1) - cmd - 1;
    
    memset(T[1].mx, -0x3f, sizeof(T[1].mx));

    // dp[i] = max(r_j < l_i: dp[j] + r_i - l_i + 1, r_j >= l_i and r_j <= r_i: dp[j] + r_i - r_j)
    for(int i = 1; i <= n; i ++){

        int l = lower_bound(cmd + 1, cmd + cnt + 1, a[i]) - cmd;
        int r = lower_bound(cmd + 1, cmd + cnt + 1, b[i]) - cmd;
        
        int x = T[0].query(1, 1, cnt, 1, l - 1) + b[i] - a[i] + 1;
        int y = T[1].query(1, 1, cnt, l, r) + b[i];
        
        dp[i] = max(x, y);
        ans = max(ans, dp[i]);

        T[0].upd(1, 1, cnt, r, dp[i]);
        T[1].upd(1, 1, cnt, r, dp[i] - b[i]);

    }

    cout << ans << endl;

    return 0;
}*/

//G. 序列
/*#include<bits/stdc++.h>
using namespace std;

// 考虑到 只有当 l ~ r 中所有元素都在 [l, r] 之间, 才能更新
// 因此, 可以用单调栈来找 第 i 个元素左边第一个比它 大/小 的元素
// ex (i 为最小): 从第一个比自己小的下一个出发, 剩下的都 >= 自己
// 这些大于等于自己的是严格递减的, 因为 单调栈 筛过了 ->
// 对于一个 j, 如果后面有比自己大的, 当前就变为 INF 了

#define mid ((l + r) >> 1)
#define kl k << 1
#define kr (k << 1) | 1

const int N = 1e5 + 7, INF = 1e9;

int a[N], dp[N];

int n;

struct Tree{

    int mn[N << 2];

    void upd(int k, int l, int r, int x, int v){
        if(l == x && r == x){
            mn[k] = v;
            return;
        }
        if(mid >= x) upd(kl, l, mid, x, v);
        else upd(kr, mid + 1, r, x, v);
        mn[k] = min(mn[kl], mn[kr]);
    }

    int query(int k, int l, int r, int x, int y){
        if(x > y) return INF;
        if(l >= x && r <= y) return mn[k];
        int res = INF;
        if(mid >= x) res = query(kl, l, mid, x, y);
        if(mid + 1 <= y) res = min(res, query(kr, mid + 1, r, x, y));
        return res;
    }

}T[2];

int st1[N], st2[N], tp1, tp2;

ifstream fin("seq.in");
ofstream fout("seq.out");

#define cin fin
#define cout fout

int main(){

    cin >> n;

    for(int i = 1; i <= n; i ++)
        cin >> a[i];
    
    dp[1] = 1;

    st1[++ tp1] = 1, st2[++ tp2] = 1;

    memset(T[0].mn, 0x3f, sizeof(T[0].mn));
    memset(T[1].mn, 0x3f, sizeof(T[1].mn));

    T[0].upd(1, 1, n, 1, 1), T[1].upd(1, 1, n, 1, 1);

    for(int i = 2; i <= n; i ++){

        while(tp1 && a[st1[tp1]] < a[i]) T[0].upd(1, 1, n, st1[tp1], INF), tp1 --;
        while(tp2 && a[st2[tp2]] > a[i]) T[1].upd(1, 1, n, st2[tp2], INF), tp2 --;

        int x = T[0].query(1, 1, n, st2[tp2] + 1, i);
        int y = T[1].query(1, 1, n, st1[tp1] + 1, i);
        dp[i] = min(x, y) + 1;

        st1[++ tp1] = i, st2[++ tp2] = i;
        T[0].upd(1, 1, n, i, dp[i]), T[1].upd(1, 1, n, i, dp[i]);
        
    }

    cout << dp[n] << endl;

    return 0;
}*/
