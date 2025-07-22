//A. 顶点覆盖
/*#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

vector <int> a[N], s1, s2;

int vis[N];

int n, m, x, y;

void dfs(int x){
    if(vis[x] == 1)
        s1.push_back(x);
    else
        s2.push_back(x);
    for(auto to : a[x]){
        if(vis[to] == -1){
            vis[to] = vis[x] ^ 1;
            dfs(to);
        }
        else if(vis[to] == vis[x]){
            cout << -1 << endl;
            exit(0);
        }
    }
}

int main(){

    cin >> n >> m;

    for(int i = 1; i <= m; i ++){
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }

    memset(vis, -1, sizeof(vis));

    for(int i = 1; i <= n; i ++)
        if(vis[i] == -1 && a[i].size() >= 1){
            vis[i] = 1;
            dfs(i);
        }

    cout << s1.size() << endl;
    for(auto ans : s1)
        cout << ans << ' ';
    cout << endl << s2.size() << endl;
    for(auto ans : s2)
        cout << ans << ' ';
    return 0;
}*/

//B. 加边二分图
/*#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

vector <int> a[N], s1, s2;

int vis[N];

int n, x, y;

void dfs(int x){
    if(vis[x] == 1)
        s1.push_back(x);
    else
        s2.push_back(x);
    for(auto to : a[x]){
        if(vis[to] == -1){
            vis[to] = vis[x] ^ 1;
            dfs(to);
        }
        else if(vis[to] == vis[x]){
            cout << -1 << endl;
            exit(0);
        }
    }
}

int main(){

    cin >> n;

    for(int i = 1; i < n; i ++){
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }

    memset(vis, -1, sizeof(vis));

    for(int i = 1; i <= n; i ++)
        if(vis[i] == -1 && a[i].size() >= 1){
            vis[i] = 1;
            dfs(i);
        }

    cout << s1.size() * s2.size() - n + 1 << endl;
    return 0;
}*/

//C. 抓小偷
/*#include<bits/stdc++.h> 
using namespace std;

const int N = 1e6 + 7;

vector <int> a[N];

int vis[N];

int n, m, x, y, t, s, mark, con;

void dfs(int x){
    for(auto to : a[x]){
        if(vis[to] == -1){
            vis[to] = vis[x] ^ 1;
            dfs(to);
        }
        else if(vis[to] == vis[x]){
            mark = 1;
        }
    }
}

int main(){

    scanf("%d", &t);
    int cnt = 0;

    while(++ cnt <= t){

        scanf("%d %d %d", &n, &m, &s); s ++;
        for(int i = 1; i <= n; i ++){
            a[i].clear();
            vis[i] = -1;
        }
        for(int i = 1; i <= m; i ++){
            scanf("%d %d", &x, &y); x ++, y ++;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        vis[s] = 0;
        mark = 0; con = 1;
        dfs(s);
        for(int i = 1; i <= n; i ++)
            if(vis[i] == -1){
                //cout << "//";
                con = 0;
                break;
            }
        printf("Case %d: %s\n", cnt, mark && con ? "YES" : "NO");
    }
    return 0;
}*/

//D. 设置点权
/*#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 3e5 + 7, MOD = 998244353;

vector <int> a[N];

int vis[N], sz1, sz2;

int n, m, t, x, y, f, ans;

int qpow(int x, int b){
    int res = 1;
    while(b){
        if(b & 1) res *= x, res %= MOD;
        x *= x, x %= MOD;
        b >>= 1;
    }
    return res;
}

void dfs(int x){
    if(vis[x] == 1)
        sz1 ++;
    else
        sz2 ++;
    for(auto to : a[x]){
        if(vis[to] == -1){
            vis[to] = vis[x] ^ 1;
            dfs(to);
        }
        else if(vis[to] == vis[x])
            f = 1;
    }
}

signed main(){

    cin >> t;

    while(t --){
        cin >> n >> m;
        for(int i = 1; i <= n; i ++){
            vis[i] = -1;
            a[i].clear();
        }
        for(int i = 1; i <= m; i ++){
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        ans = 1;
        f = 0;
        for(int i = 1; i <= n; i ++)
            if(vis[i] == -1){
                vis[i] = sz1 = sz2 = 0;
                dfs(i);
                if(f){ans = 0; break;}
                ans *= (qpow(2, sz1) + qpow(2, sz2));
                ans %= MOD;
            }
        cout << ans << endl;
    }

    return 0;
}*/


//E. 车辆安排
/*#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e5 + 7;

vector <int> a[N], b[N];

int vis[N], op[N], in[N];

int n, m, cnt, x[N], y[N], ans[N];

void dfs(int x){
    for(auto to : a[x]){
        if(vis[to] == -1){
            vis[to] = vis[x] ^ 1;
            dfs(to);
        }
        else if(vis[to] == vis[x]){ cout << "NO" << endl; exit(0);}
    }
}

signed main(){

    cin >> n >> m;

    for(int i = 1; i <= n; i ++)
        vis[i] = -1;
    
    for(int i = 1; i <= m; i ++){
        cin >> op[i] >> x[i] >> y[i];
        op[i] -= 1;
        a[x[i]].push_back(y[i]);
        a[y[i]].push_back(x[i]);
    }

    for(int i = 1; i <= n; i ++)
        if(vis[i] == -1){
            vis[i] = 1;
            dfs(i);
        }

    for(int i = 1; i <= m; i ++){
        if(op[i] ^ vis[x[i]]){ //找到关系, (即反向而行 / 相向而行) ^ (向左 / 向右)
            in[x[i]] ++;
            b[y[i]].push_back(x[i]);
        }
        else {
            in[y[i]] ++;
            b[x[i]].push_back(y[i]);
        }
    }
    
    queue <int> q;
    for(int i = 1; i <= n; i ++) 
        if(!in[i]) q.push(i);
    
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(auto to : b[now])
            if(! -- in[to]) q.push(to);
        ans[now] = ++ cnt;
    }

    if(cnt != n){ cout << "NO" << endl; exit(0);}
    cout << "YES" << endl;
    for(int i = 1; i <= n; i ++)
        cout << (vis[i] == 1 ? 'R' : 'L') << ' ' << ans[i] << endl;
    
    return 0;
}*/

