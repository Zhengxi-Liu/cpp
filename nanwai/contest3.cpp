//E
/*#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 100 + 7;

vector <int> a[N];

int x[N], y[N], cnt[N], n, ans = 1;

void dfs(int x, int fa){
    cnt[x] = 1;
    for(auto to : a[x]){
        if(to == fa)
            continue;
        dfs(to, x);
        cnt[x] *= (cnt[to] + 1);
    }
}

signed main(){

    cin >> n;
    for(int i = 1; i <= n; i ++)
        cin >> x[i];
    
    cin >> n;
    for(int i = 1; i <= n; i ++){
        cin >> y[i];
        a[x[i]].push_back(y[i]);
        a[y[i]].push_back(x[i]);
    }
    
    dfs(1, 0);

    for(int i = 1; i <= n + 1; i ++)
        ans += cnt[i];
    
    cout << ans << endl;

    return 0;
}*/

//F
/*#include<bits/stdc++.h>
using namespace std;

const int N = 5e2 + 7;

vector <int> a[N];

int b[N][N], vis[N], in[N], ans[N];

int n, m, x, y;

void dfs(int x){
    for(auto to : a[x]){
        if(vis[to] == -1){
            vis[to] = vis[x] ^ 1;
            dfs(to);
        }
        else if(vis[to] == vis[x]){
            cout << "No" << endl;
            exit(0);
        }
    }
}

int main(){
    
    cin >> n >> m;

    for(int i = 1; i <= m; i ++){
        cin >> x >> y;
        b[x][y] = b[y][x] = 1;
        in[x] ++, in[y] ++;
    }

    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++)
            if(!b[i][j] && i != j)
                a[i].push_back(j);
        vis[i] = -1;
    }
    
    for(int i = 1; i <= n; i ++)
        if(vis[i] == -1){
            vis[i] = 0;
            dfs(i);
        }
    
    for(int i = 1; i <= n; i ++){
        if(in[i] < n - 1){
            if(vis[i])
                ans[i] = 0;
            else
                ans[i] = 2;
        }
        else
            ans[i] = 1;
    }
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++){
            if(i == j || !b[i][j])
                continue;
            if(abs(ans[i] - ans[j]) > 1){
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    for(int i = 1; i <= n; i ++)
        cout << char(ans[i] + 'a');
    cout << endl;
    return 0;
}*/

//G
#include<bits/stdc++.h>
using namespace std;

#define YES {printf("1"); continue;};
#define NO {printf("0"); continue;};

const int N = 1e6 + 7;

vector <int> a[N];

int dsu1[N], dsu2[N], l[N], r[N];

int ll[N], rr[N], vis[N], jihuan[N];

int n, m, q, x, y;

char s[N];

int find(int dsu[], int x){
    return dsu[x] == x ? x : dsu[x] = find(dsu, dsu[x]);
}

bool dfs(int x){
    bool res = false;
    for(auto to : a[x]){
        if(vis[to] == -1){
            vis[to] = vis[x] ^ 1;
            res |= dfs(to);
        }
        else if(vis[to] == vis[x])
            res = true;
    }
    return res;
}

int main(){

    scanf("%d %d %d", &n, &m, &q);
    
    for(int i = 1; i <= n; i ++){
        cin >> s[i];
        dsu1[i] = dsu2[i] = i;
        vis[i] = -1;
    }

    for(int i = 1; i <= m; i ++){
        scanf("%d %d", &x, &y);
        a[x].push_back(y), a[y].push_back(x);
        dsu1[find(dsu1, x)] = find(dsu1, y);
        if(s[x] != s[y]) 
            dsu2[find(dsu2, x)] = find(dsu2, y);
        if(s[x] == '(' && s[y] == '(') l[x] = l[y] = 1;
        if(s[x] == ')' && s[y] == ')') r[x] = r[y] = 1;
    }
    
    for(int i = 1; i <= n; i ++)
        ll[find(dsu2, i)] |= l[i], rr[find(dsu2, i)] |= r[i];
    for(int i = 1; i <= n; i ++)
        if(dsu1[i] == i){
            vis[i] = 0;
            jihuan[i] = dfs(i);
        }
    while(q --){
        scanf("%d %d", &x, &y);
        if(find(dsu1, x) != find(dsu1, y) || s[x] != '(' || s[y] != ')') NO
        int nx = find(dsu2, x), ny = find(dsu2, y);
        if(nx == ny) YES
        if(ll[nx] && rr[ny] && (jihuan[find(dsu1, x)] || vis[x] != vis[y])) YES
        NO
    }
    cout << endl;

    return 0;
}
