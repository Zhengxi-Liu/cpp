//P11839 [USACO25FEB] The Best Lineup S
/*#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7, INF = 1e9;

int n, t, s[N], ans[N], cnt;

struct str{
    int x, pos;
}a[N];

bool cmp(str a, str b){
    if(a.x != b.x) return a.x > b.x;
    return a.pos < b.pos;
}

int main(){

    cin >> t;

    while(t --){

        cin >> n;

        for(int i = 1; i <= n; i ++)
            cin >> s[i], a[i] = {s[i], i};

        sort(a + 1, a + n + 1, cmp);

        a[0] = {INF, 0}, s[0] = INF, cnt = 0;

        bool f = 0;

        int lst = 0, d;

        for(int i = 1; i <= n; i ++){
            int val = a[i].x, p = a[i].pos;
            if(lst > p){
                if(f || p < d) continue;
                f = 1;
            }
            ans[++ cnt] = val;
            d = lst;
            lst = p;
        }

        for(int i = 1; i <= cnt; i ++){
            cout << ans[i];
            if(i < cnt) cout << ' ';
        }
        cout << endl;

    }



    return 0;
}*/

//P11840 [USACO25FEB] Vocabulary Quiz S
/*#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;

vector <int> a[N];

int n, x, cnt;

int ans[N], fa[N], dep[N], sz[N];

void dfs(int x, int lst){

    dep[x] = !x ? 0 : dep[fa[x]] + 1;
    ans[x] = lst;
    sz[x] = a[x].size();

    if(a[x].empty()){
        cnt ++;
        return;
    }

    for(int to : a[x]){
        if(a[x].size() >= 2) dfs(to, to);
        else dfs(to, lst);
    }
    
}

int main(){

    cin >> n;

    for(int i = 1; i <= n; i ++){
        scanf("%d", &fa[i]);
        a[fa[i]].push_back(i);
    }

    dfs(0, 0);

    while(cnt --){

        scanf("%d", &x);

        if(!cnt){
            cout << 0 << endl;
            break;
        }

        int tmp = ans[x];
        sz[fa[tmp]] --;

        while(!sz[fa[tmp]]){
            tmp = ans[fa[tmp]];
            sz[fa[tmp]] --;
        }

        printf("%d\n", dep[tmp]);

    }

    return 0;
}*/

//P11841 [USACO25FEB] Transforming Pairs S
/*#include<bits/stdc++.h>
using namespace std;

#define int long long

int a, b, x, y, t;

int cal(int a, int b, int x, int y){
    if(a > x || b > y) return -1;
    if(a == x && b == y) return 0;
    int res = 0;
    while(a < x || b < y){
        if(x > y){
            if(!y) return -1;
            int tmp = (x - a) / y;
            if(!tmp) return -1;
            x -= tmp * y;
            res += tmp;
        }
        else if(x < y){
            if(!x) return -1;
            int tmp = (y - b) / x;
            if(!tmp) return -1;
            y -= tmp * x;
            res += tmp;
        }
        else return -1;
    }
    if(a == x & b == y) return res;
    return -1;
}

signed main(){

    cin >> t;

    while(t --){
        cin >> a >> b >> x >> y;
        cout << cal(a, b, x, y) << endl;
    }


    return 0;
}*/

//P9013 [USACO23JAN] Find and Replace S
/*#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;
typedef pair <int, int> PI;
int to[N], vis[N], t, n, ans;
string s1, s2;

vector <PI> a;
vector <int> e[N];
stack <int> st;
bool ff[N], as;

map <int, int> mp;

bool check(){

    a.clear();
    ans = as = 0;
    while(!st.empty()) st.pop();
    for(int i = 0; i < N; i ++)
        e[i].clear();
    
    memset(vis, 0, sizeof(vis));
    memset(ff, 0, sizeof(ff));
    memset(to, -1, sizeof(to));
    mp.clear();

    for(int i = 1; i <= n; i ++){
        if(s1[i] == s2[i]) mp[s1[i]] = 1;
        if(to[s1[i]] != -1 && s2[i] != to[s1[i]]) return false;
        if(to[s1[i]] == -1 && s1[i] != s2[i]){
            a.push_back({s1[i], s2[i]});
            e[s2[i]].push_back(s1[i]);
        }
        to[s1[i]] = s2[i];
    }
    return true;
}

void dfs(int x){
    st.push(x);
    ff[x] = true;
    ans ++;
    vis[x] = 1;
    for(int to : e[x]){
        if(ff[to]){
            int tp, f = 0;
            do {
                tp = st.top();
                mp[tp] = 1;
                if(e[tp].size() >= 2) f = 1;
                st.pop();
                ff[tp] = false;
            } while(tp != to);
            if(mp.size() >= 52) as = 1;
            if(!f) ans ++;
        }
        else if(!vis[to]) dfs(to);
    }
    if(!st.empty() && st.top() == x) st.pop();
    ff[x] = false;
}

int main(){

    cin >> t;
    
    while(t --){

        cin >> s1 >> s2;

        n = s1.size(), s1 = " " + s1, s2 = " " + s2;

        if(!check()){
            cout << -1 << endl;
            continue;
        }

        if(a.empty()){
            cout << 0 << endl;
            continue;
        }

        for(PI ans: a){
            int x = ans.first, y = ans.second;
            if(!vis[x]) dfs(x);
        }
        
        if(as) cout << -1 << endl;
        else cout << ans << endl;

    }


    return 0;
}*/

//4085 [USACO17DEC] Haybale Feast G
/*#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e5 + 7, M = 20;

int st[N][M], lg[N], a[N], b[N];

int n, m;

void prep(){
    lg[0] = -1;
    for(int i = 1; i <= n; i ++){
        lg[i] = lg[i / 2] + 1;
        st[i][0] = b[i];
    }
    for(int k = 1; k <= lg[n]; k ++)
        for(int i = 1; i <= n - (1 << k) + 1; i ++)
            st[i][k] = max(st[i][k - 1], st[i + (1 << (k - 1))][k - 1]);
}

int L = 1, R, sum, ans = 1e18;

int qry(int l, int r){
    int k = lg[r - l + 1];
    return max(st[l][k], st[r - (1 << k) + 1][k]);
}

signed main(){

    cin >> n >> m;

    for(int i = 1; i <= n; i ++)
        cin >> a[i] >> b[i];

    prep();

    for(int i = 1; i <= n; i ++){
        sum += a[i];
        if(L <= R && sum - a[L] >= m) sum -= a[L], L ++;
        R ++;
        if(sum >= m) ans = min(ans, qry(L, R));
    }

    cout << ans << endl;

    return 0;
}*/

//P4087 [USACO17DEC] Milk Measurement S
/*#include<bits/stdc++.h>
using namespace std;

#define kl (k << 1)
#define kr ((k << 1) | 1)
#define mid ((l + r) >> 1)

const int N = 1e5 + 7;

int mx[N << 2], sz[N << 2];

int b[N], cor[N], n, m, cnt, ans;

struct str{
    int date, id, val;
}a[N];

char c;

bool cmp(str a, str b){
    return a.date < b.date;
}

void push_up(int k){
    if(mx[kl] > mx[kr]) sz[k] = sz[kl];
    else if(mx[kr] > mx[kl]) sz[k] = sz[kr];
    else sz[k] = sz[kl] + sz[kr];
    mx[k] = max(mx[kl], mx[kr]);
}

void build(int k, int l, int r){
    if(l == r){
        mx[k] = m;
        sz[k] = 1;
        cor[l] = k;
        return;
    }
    build(kl, l, mid);
    build(kr, mid + 1, r);
    push_up(k);
}

void upd(int k, int l, int r, int pos, int chg){
    if(l == r){
        mx[k] += chg;
        return;
    }
    if(mid >= pos) upd(kl, l, mid, pos, chg);
    else upd(kr, mid + 1, r, pos, chg);
    push_up(k);
}

int main(){

    cin >> n >> m;

    for(int i = 1; i <= n; i ++){
        cin >> a[i].date >> a[i].id >> c >> a[i].val;
        if(c == '-') a[i].val *= -1;
        b[i] = a[i].id;
    }

    sort(a + 1, a + n + 1, cmp);
    sort(b + 1, b + n + 1);
    cnt = unique(b + 1, b + n + 1) - b - 1;

    for(int i = 1; i <= n; i ++)
        a[i].id = lower_bound(b + 1, b + cnt + 1, a[i].id) - b;

    build(1, 1, cnt + 1);

    for(int i = 1; i <= n;){

        int tmp = i, d1 = sz[1], d2 = mx[1], chg = 0, f = 0;

        do {
            if(mx[cor[a[i].id]] == d2){
                if(!chg) chg = a[i].val;
                else f = 1;
            }
            upd(1, 1, cnt + 1, a[i].id, a[i].val);
            i ++;
        } while(a[tmp].date == a[i].date);

        if(sz[1] != d1 || f || d2 + chg != mx[1]) ans ++;
        
    }

    cout << ans << endl;

    return 0;
}
*/

//P4186 [USACO18JAN] Cow at Large G
/*#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

vector <int> a[N];

int dep[N], mn[N];

int n, m, x, y, ans;

void dfs(int x, int fa){
    dep[x] = dep[fa] + 1;
    mn[x] = 1e9;
    for(int to : a[x]){
        if(to == fa) continue;
        dfs(to, x);
        mn[x] = min(mn[x], mn[to]);
    }
    if(a[x].size() == 1) mn[x] = 1;
    else mn[x] ++;
}

void find(int x, int fa){
    if(dep[x] >= mn[x]){
        ans ++;
        return;
    }
    for(int to : a[x]){
        if(to == fa) continue;
        find(to, x);
    }
}

int main(){

    cin >> n >> m;

    for(int i = 1; i < n; i ++){
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }

    dfs(m, 0);

    find(m, 0);

    cout << ans << endl;

    return 0;
}

*/

//P4187 [USACO18JAN] Stamp Painting G
/*#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e6 + 7, MOD = 1e9 + 7;

int dp[N], sum, n, m, k, ans = 1;

signed main(){

    cin >> n >> m >> k;

    for(int i = 1; i <= n; i ++)
        ans = ans * m % MOD;

    dp[0] = 1;

    for(int i = 1; i <= n; i ++){
        if(i < k) dp[i] = (dp[i - 1] * m) % MOD;
        else dp[i] = sum * (m - 1) % MOD;
        (sum += dp[i]) %= MOD;
        if(i >= k) (sum -= dp[i - k + 1]) %= MOD;
    }

    cout << ((ans - dp[n]) % MOD + MOD) % MOD << endl;

    return 0;
}

*/
