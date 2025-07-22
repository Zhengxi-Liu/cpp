// A. 奶牛舞会
/*#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

int dfn[N], low[N], times;
int id[N], sz[N], cnt;
bool f[N];
stack <int> st;

vector <int> a[N];

int n, m, x, y, ans;

void tarjan(int x){
    dfn[x] = low[x] = ++ times;
    f[x] = true;
    st.push(x);
    for(int to : a[x]){
        if(!dfn[to]){
            tarjan(to);
            low[x] = min(low[x], low[to]);
        }
        else if(f[to])
            low[x] = min(low[x], dfn[to]);
    }
    if(low[x] == dfn[x]){
        int tp;
        cnt ++;
        do {
            tp = st.top();
            st.pop();
            f[tp] = false;
            sz[cnt] ++;
            id[tp] = cnt;
        } while(tp != x);
    }
}

int main(){

    cin >> n >> m;

    for(int i = 1; i <= m; i ++){
        cin >> x >> y;
        a[x].push_back(y);
    }

    for(int i = 1; i <= n; i ++)
        if(!dfn[i])
            tarjan(i);
    
    for(int i = 1; i <= cnt; i ++)
        if(sz[i] > 1)
            ans ++;

    cout << ans << endl;

    return 0;
}*/

// B. 最受欢迎的牛
/*#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

int dfn[N], low[N], times;
int id[N], sz[N], cnt;
bool f[N];
stack <int> st;

vector <int> a[N], b[N];

int out[N], n, m, x, y, ans, mx;

void tarjan(int x){
    dfn[x] = low[x] = ++ times;
    f[x] = true;
    st.push(x);
    for(int to : a[x]){
        if(!dfn[to]){
            tarjan(to);
            low[x] = min(low[x], low[to]);
        }
        else if(f[to])
            low[x] = min(low[x], dfn[to]);
    }
    if(low[x] == dfn[x]){
        int tp;
        cnt ++;
        do {
            tp = st.top();
            st.pop();
            f[tp] = false;
            sz[cnt] ++;
            id[tp] = cnt;
        } while(tp != x);
    }
}

int main(){

    cin >> n >> m;

    for(int i = 1; i <= m; i ++){
        cin >> x >> y;
        a[x].push_back(y);
    }

    for(int i = 1; i <= n; i ++)
        if(!dfn[i])
            tarjan(i);
    
    for(int i = 1; i <= n; i ++)
        for(int to : a[i])
            if(id[to] != id[i])
                out[id[i]] ++;
    for(int i = 1; i <= cnt; i ++)
        if(!out[i]){
            mx ++;
            ans = i;
        }
    
    cout << ((mx == 1) ? sz[ans] : 0) << endl;

    return 0;
}*/

// C. 采集糖果
/*#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

int dfn[N], low[N], times;
int id[N], sz[N], cnt;
bool f[N];
stack <int> st;

vector <int> nxt[N];

int to[N], out[N], ans[N];

int n, m, x, y, mx;

void tarjan(int x){
    dfn[x] = low[x] = ++ times;
    f[x] = true;
    st.push(x);
    if(!dfn[to[x]]){
        tarjan(to[x]);
        low[x] = min(low[x], low[to[x]]);
    }
    else if(f[to[x]])
        low[x] = min(low[x], dfn[to[x]]);
    if(low[x] == dfn[x]){
        int tp;
        cnt ++;
        do {
            tp = st.top();
            st.pop();
            f[tp] = false;
            sz[cnt] ++;
            id[tp] = cnt;
        } while(tp != x);
    }
}

int main(){

    cin >> n;

    for(int i = 1; i <= n; i ++)
        cin >> to[i];

    for(int i = 1; i <= n; i ++)
        if(!dfn[i])
            tarjan(i);
    
    for(int i = 1; i <= n; i ++)
        if(id[to[i]] != id[i]){
            nxt[id[to[i]]].push_back(id[i]);
            out[id[i]] ++;
        }

    queue <int> q;

    for(int i = 1; i <= cnt; i ++)
        if(!out[i]) q.push(i);
    
    while(!q.empty()){
        x = q.front(); q.pop();
        ans[x] += sz[x];
        for(int to : nxt[x]){
            out[to] --;
            ans[to] += ans[x];
            if(!out[to]) q.push(to);
        }
    }

    for(int i = 1; i <= n; i ++)
        cout << ans[id[i]] << endl;

    return 0;
}*/

// D. 网络
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

int dfn[N], low[N], times;
int id[N], sz[N], cnt;
bool f[N];
stack <int> st;

vector <int> a[N];

int n, m, x, y, ans;

void tarjan(int x){
    dfn[x] = low[x] = ++ times;
    f[x] = true;
    st.push(x);
    for(int to : a[x]){
        if(!dfn[to]){
            tarjan(to);
            low[x] = min(low[x], low[to]);
        }
        else if(f[to])
            low[x] = min(low[x], dfn[to]);
    }
    if(low[x] == dfn[x]){
        int tp;
        cnt ++;
        do {
            tp = st.top();
            st.pop();
            f[tp] = false;
            sz[cnt] ++;
            id[tp] = cnt;
        } while(tp != x);
    }
}

int main(){

    cin >> n >> m;

    for(int i = 1; i <= m; i ++){
        cin >> x >> y;
        a[x].push_back(y);
    }

    for(int i = 1; i <= n; i ++)
        if(!dfn[i])
            tarjan(i);
    
    for(int i = 1; i <= cnt; i ++)
        if(sz[i] > 1)
            ans ++;

    cout << ans << endl;

    return 0;
}