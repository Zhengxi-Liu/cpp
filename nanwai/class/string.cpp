//A. 大厨的特色菜
/*#include<bits/stdc++.h>
using namespace std;

#define yes { cout << "YES" << endl; continue; }
#define no { cout << "NO" << endl; continue; }

const int N = 2e5 + 7;

int t, n;

string s;

bool f1[N], f2[N];

bool check(string s){
	
	n = s.size();
	s = " " + s;
	
	if(n % 2 == 0){
		for(int i = 1; i <= n / 2; i ++)
			if(s[i] != s[i + n / 2]) return false;
		return true;
	}
	
	int mid = n / 2 + 1;
	
	memset(f1, 0, sizeof(f1));
	memset(f2, 0, sizeof(f2));
	
	f1[0] = f2[mid + 1] = 1;
	
	for(int i = 1; i <= mid; i ++){
		if(s[i] != s[i + mid]) break;
		f1[i] = true;
	}
	
	for(int i = mid; i; i --){
		if(s[i] != s[i + mid - 1]) break;
		f2[i] = true;
	}
	
	for(int i = 0; i < mid; i ++)
		if(f1[i] && f2[i + 2]) return true;
	
	return false;
	
}

int main(){
	
	cin >> t;
	
	while(t --){
		
		cin >> s;
		if(s.size() == 1) no
		if(check(s)) yes
		reverse(s.begin(), s.end());
		if(check(s)) yes
		no
		
	}
    
	return 0;
}*/

//B. POI2010 Beads
/*#include<bits/stdc++.h>
using namespace std;

#define int unsigned long long

const int N = 2e5 + 7;

const int P = 1e9 + 7;

int a[N], n, mx, tot, ans[N];

int power[N], h1[N], h2[N];

int get_hash(int l, int r, bool f){
    if(f) return h2[l] - h2[r + 1] * power[r - l + 1];
    return h1[r] - h1[l - 1] * power[r - l + 1];
}

map <int, int> mp;

signed main(){

    cin >> n;

    power[0] = 1;

    for(int i = 1; i <= n; i ++){
        cin >> a[i];
        power[i] = power[i - 1] * P;
    }

    for(int i = 1; i <= n; i ++)
        h1[i] = h1[i - 1] * P + a[i];

    for(int i = n; i >= 1; i --)
        h2[i] = h2[i + 1] * P + a[i];

    for(int k = 1; k <= n; k ++){

        if(n / k < mx) break;

        int cnt = 0;

        for(int i = k; i <= n; i += k){
            int t1 = get_hash(i - k + 1, i, 0), t2 = get_hash(i - k + 1, i, 1);
            if(!mp.count(t1) && !mp.count(t2)){
                cnt ++;
                mp[t1] = 1;
                mp[t2] = 1;
            }
        }

        mp.clear();

        if(cnt > mx) mx = cnt, ans[tot = 1] = k;
        else if(cnt == mx) ans[++ tot] = k;

    }

    cout << mx << ' ' << tot << endl;
    for(int i = 1; i <= tot; i ++)
        cout << ans[i] << ' ';
    cout << endl;

    return 0;
}*/

//C. 抄卡组
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

string s[N];

int n, t;

int h[N];


int main(){

    cin >> t;

    while(t --){

        cin >> n;

        for(int i = 1; i <= n; i ++)
            cin >> s[i];




    }


    return 0;
}

// Manacher 模版
/*#include<bits/stdc++.h>
using namespace std;

const int N = ((int)11e6 << 1) + 7;

char s[N], c;

int p[N], n, ans;

int main(){

    s[0] = '.';
    while(cin >> c){
        s[++ n] = '|';
        s[++ n] = c;
    }
    s[++ n] = '|';

    for(int i = 1, mid = 0, r = 0; i <= n; i ++){ // r 记录的是最右边的点的 下标
        if(i <= r) p[i] = min(p[mid * 2 - i], r - i + 1);
        while(s[i + p[i]] == s[i - p[i]]) p[i] ++;
        if(i + p[i] > r) r = i + p[i] - 1, mid = i;
        ans = max(ans, p[i]);
    }

    cout << ans - 1 << endl;

    return 0;
}*/

//H. 拉拉队排练 
/*#include<bits/stdc++.h>
using namespace std;

const int N = 2e6 + 7, MOD = 19930726;

typedef long long LL;

char s[N], c;

int n, m, p[N], cnt[N], idx;

LL ans = 1, d, K;

LL qpow(LL a, LL b){
    LL res = 1;
    while(b){
        if(b & 1) (res *= a) %= MOD;
        (a *= a) %= MOD;
        b >>= 1;
    }
    return res;
}

int main(){

    cin >> m >> K;

    s[0] = '.';

    while(m --){
        cin >> c;
        s[++ n] = '|';
        s[++ n] = c;
    }

    s[++ n] = '|';

    for(int i = 1, mid = 0, r = 0; i <= n; i ++){
        if(r >= i) p[i] = min(p[mid * 2 - i], r - i + 1);
        while(s[i - p[i]] == s[i + p[i]]) p[i] ++;
        if(i + p[i] > r) r = i + p[i] - 1, mid = i;
        p[i] --;
        if(p[i] % 2 == 0) continue;
        d += p[i];
        cnt[++ idx] = p[i];
    }

    if(d < K){
        cout << -1 << endl;
        return 0;
    }

    sort(cnt + 1, cnt + idx + 1, greater <int>());

    LL tot = 0;
    for(int i = 1; i <= idx; i ++){
        if(tot >= K) break;
        while(cnt[i] > cnt[i + 1] && tot < K){
            (ans *= qpow(cnt[i], min(1ll * i, K - tot))) %= MOD;
            cnt[i] -= 2;
            tot += i;
        }
    }

    cout << ans << endl;

    return 0;
}*/

//J. 串的周期
/*#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e6 + 7;

int n, ans, ne[N];

string s;

signed main(){

    cin >> n >> s;

    s = " " + s;

    for(int i = 2, j = 0; i <= n; i ++){
        while(j && s[i] != s[j + 1]) j = ne[j];
        if(s[i] == s[j + 1]) j ++;
        ne[i] = j;
    }

    for(int i = 2, j = 2; i <= n; i ++, j = i){
        while(ne[j]) j = ne[j]; // 找到最小能与后缀匹配的前缀
        if(ne[i]) ne[i] = j;
        ans += i - j;
    }
    cout << ans << endl;

    return 0;
}*/

//K. 编程作业
/*#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7, INF = 1e9;

int q, n, m;

string s, t;

int a[N], b[N];

int nxt[N], lst[26 + 7];

bool equiv(int x, int y, int j){
    if(x < 0 || y < 0) return x == y;
    return y == INF && x > j || x == y;
}

int main(){

    cin >> q;

    while(q --){

        cin >> s >> t;

        n = s.size(), m = t.size();

        s = " " + s, t = " " + t;

        memset(lst, 0, sizeof(lst));
        for(int i = 1; i <= n; i ++){
            if(s[i] >= 'A' && s[i] <= 'Z') a[i] = s[i] - 'A' - 100;
            else a[i] = (!lst[s[i] - 'a'] ? INF : i - lst[s[i] - 'a']), lst[s[i] - 'a'] = i;
        }

        memset(lst, 0, sizeof(lst));
        for(int i = 1; i <= m; i ++){
            if(t[i] >= 'A' && t[i] <= 'Z') b[i] = t[i] - 'A' - 100;
            else b[i] = (!lst[t[i] - 'a'] ? INF : i - lst[t[i] - 'a']), lst[t[i] - 'a'] = i;
        }
        
        memset(nxt, 0, sizeof(nxt));
        for(int i = 2, j = 0; i <= m; i ++){
            while(j && !equiv(b[i], b[j + 1], j)) j = nxt[j];
            if(equiv(b[i], b[j + 1], j)) j ++;
            nxt[i] = j;
        }
        
        int ans = 0;
        for(int i = 1, j = 0; i <= n; i ++){
            while(j && (!equiv(a[i], b[j + 1], j))) j = nxt[j];
            if(equiv(a[i], b[j + 1], j)) j ++;
            if(j == m) ans ++, j = nxt[j];
        }

        cout << ans << endl;

    }

    return 0;
}*/

//I. 神奇项链
/*#include<bits/stdc++.h>
using namespace std;

#define mid ((l + r) >> 1)
#define kl (k << 1)
#define kr ((k << 1) | 1)

const int N = 1e5 + 7;

string s;

char c[N];

int p[N], n;

int mn[N << 2], tag[N << 2];

void change(int k, int v){
    mn[k] = min(mn[k], v);
    if(tag[k] == -1) tag[k] = v;
    else tag[k] = min(tag[k], v);
}

void push_down(int k){
    if(tag[k] == -1) return;
    change(kl, tag[k]);
    change(kr, tag[k]);
    tag[k] = -1;
}

void upd(int k, int l, int r, int x, int y, int v){
    r = min(r, n);
    if(l >= x && r <= y){
        change(k, v);
        return;
    }
    push_down(k);
    if(mid >= x) upd(kl, l, mid, x, y, v);
    if(mid < y) upd(kr, mid + 1, r, x, y, v);
    mn[k] = min(mn[kl], mn[kr]);
}

int qry(int k, int l, int r, int x, int y){
    r = min(r, n);
    if(l >= x && r <= y) return mn[k];
    push_down(k);
    int res = 1e9;
    if(mid >= x) res = qry(kl, l, mid, x, y);
    if(mid < y) res = min(res, qry(kr, mid + 1, r, x, y));
    return res;
}

int main(){

    c[0] = '.';

    while(cin >> s){

        n = 0;
        for(int i = 0; i < s.size(); i ++){
            c[++ n] = '|';
            c[++ n] = s[i];
        }
        c[++ n] = '|';

        memset(p, 0, sizeof(p));
        for(int i = 1, md = 0, r = 0; i <= n; i ++){
            if(i <= r) p[i] = min(r - i + 1, p[md * 2 - i]);
            while(c[i + p[i]] == c[i - p[i]]) p[i] ++;
            if(i + p[i] - 1 > r) r = i + p[i] - 1, md = i;
            p[i] --;
        }

        memset(mn, 0x3f, sizeof(mn));
        memset(tag, -1, sizeof(tag));

        upd(1, 0, n, 0, 0, 0);
        for(int i = 1; i <= n; i ++){
            int tmp = qry(1, 0, n, i - p[i] - 1, i);
            upd(1, 0, n, i, i + p[i] - 1, tmp + 1);
        }
        
        cout << qry(1, 0, n, n - 1, n - 1) - 1 << endl;
        
    }

    return 0;
}*/

//D. Toponyms
/*#include<bits/stdc++.h>
using namespace std;

const int N = 1e7 + 7;

int sz[N];

short dep[N];

struct str{
    char c;
    int to;
};

vector <str> tr[N];

int n, tot;

long long ans;

string s;

void insert(string s){
    int p = 0;
    sz[0] ++;
    for(int i = 0; i < s.size(); i ++){
        int x = s[i], f = 0;
        for(str j : tr[p])
            if(j.c == x) f = j.to;
        if(!f) tr[p].push_back((str){(char)x, ++ tot}), f = tot;
        dep[f] = dep[p] + 1;
        p = f;
        sz[p] ++;
    }
}

void dfs(int x){
    long long tmp = 1ll * sz[x] * dep[x];
    if(tmp > ans) ans = tmp;
    for(str x : tr[x])
        dfs(x.to);
}

int main(){

    cin >> n;

    getline(cin, s);

    while(n --){
        getline(cin, s);
        insert(s);
    }

    dfs(0);

    cout << ans << endl;

    return 0;
}*/

