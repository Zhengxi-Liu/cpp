/*#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;

int low[N], dfn[N], times;//最小能访问的点的时间序, 本点的时间序, 时间序记录器
int id[N], si[N], cnt;//id[i] = SCC编号, si[i] = 编号为i 的SCC内部有几个点
stack <int> st;
bool f[N];

int to[N], last[N], pre[N], n, m, k, x, y;

void add(int x, int y){
    to[++ k] = y;
    last[k] = pre[x];
    pre[x] = k;
}

void tarjan(int x){
    dfn[x] = low[x] = ++ times;
    st.push(x);
    f[x] = true;
    for(int i = pre[x]; i; i = last[i]){
        if(!dfn[to[i]]){
            tarjan(to[i]);
            low[x] = min(low[x], low[to[i]]);
        }
        else if(f[to[i]])
            low[x] = min(low[x], dfn[to[i]]);
    }
    if(dfn[x] == low[x]){
        cnt ++;
        int tp;
        do {
            tp = st.top();
            st.pop();
            f[tp] = false;
            si[cnt] ++;
            id[tp] = cnt;
        }while(tp != x);
    }
}
int main(){
    cin >> n >> m;
    for(int i = 1;i <= m;i ++){
        cin >> x >> y;
        add(x, y);
    }
    for(int i = 1;i <= n;i ++)
        if(!dfn[i])
            tarjan(i);
    int ans = 0;
    for(int i = 1;i <= cnt;i ++)
        if(si[i] > 1)
            ans ++;
    cout << ans << endl;
    return 0;
}*/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 7, M = 1e5 + 7;
struct str{
    int to, last;
}a[M], b[M];
int pre[N], s[N], k;
int pre2[N], tot, in[N], dp[N], ans;
int n, m, x, y;
void add(str a[], int pre[], int x, int y){
    a[++ k].to = y;
    a[k].last = pre[x];
    pre[x] = k;
}
int dfn[N], low[N], times;
int id[N], si[N], cnt;
stack <int> st;
bool f[N];
void dfs(int x){
    dfn[x] = low[x] = ++ times;
    st.push(x);
    f[x] = true;
    for(int i = pre[x]; i; i = a[i].last){
        int to = a[i].to;
        if(!dfn[to]){
            dfs(to);
            low[x] = min(low[x], low[to]);
        }
        else if(f[to])
            low[x] = min(low[x], dfn[to]);
    }
    if(dfn[x] == low[x]){
        cnt ++;
        int tp;
        do {
            tp = st.top();
            id[tp] = cnt;
            si[cnt] += s[tp];
            f[tp] = false;
            st.pop();
        }while(tp != x);
    }
}
queue <int> q;
int main(){
    cin >> n >> m;
    for(int i = 1;i <= n;i ++)
        cin >> s[i];
    for(int i = 1;i <= m;i ++){
        cin >> x >> y;
        add(a, pre, x, y);
    }
    for(int i = 1;i <= n;i ++)
        if(!dfn[i])
            dfs(i);
    for(int i = 1;i <= n;i ++)
        for(int j = pre[i]; j; j = a[j].last){
            int to = a[j].to;
            if(id[i] != id[to]){
                add(b, pre2, id[i], id[to]);
                in[id[to]] ++;
            }
        }
    for(int i = 1;i <= cnt;i ++){
        dp[i] = si[i];
        if(!in[i])
            q.push(i);
    }
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int i = pre2[now]; i; i = b[i].last){
            int to = b[i].to;
            dp[to] = max(dp[to], dp[now] + si[to]);
            in[to] --;
            if(!in[to])
                q.push(to);
        }
    }
    for(int i = 1;i <= cnt;i ++)
        ans = max(ans, dp[i]);
    cout << ans << endl;
    return 0;
}
