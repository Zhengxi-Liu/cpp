//https://www.luogu.com.cn/problem/P3388
//P3388 【模板】割点（割顶）
/*#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;

vector <int> a[N];

int dfn[N], low[N], times;

int b[N], n, x, y, ans, m, root;

void tarjan(int x){
	dfn[x] = low[x] = ++ times;
	bool flag = false;
	int child = 0;
	for(int i = 0; i < a[x].size(); i ++){
		int to = a[x][i];
		if(!dfn[to]){
			tarjan(to);
			child ++;
			low[x] = min(low[x], low[to]);
			if(low[to] >= dfn[x])
				flag = true;
		}
		else
			low[x] = min(low[x], dfn[to]);
	}
	if(x == root && child < 2)
		flag = false;
	b[x] = flag == true;
    if(b[x])
        ans ++;
}

int main(){
	
	cin >> n >> m;

    for(int i = 1; i <= m; i ++){
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    
	for(int i = 1; i <= n; i ++)
		if(!dfn[i]){
			root = i;
	    	tarjan(i);
		}
    cout << ans << endl;
    for(int i = 1; i <= n; i ++)
        if(b[i])
            cout << i << ' ';
    cout << endl;
	return 0;
}*/

//https://www.luogu.com.cn/problem/P8436
//P8436 【模板】边双连通分量
/*#include<bits/stdc++.h>
using namespace std;

const int N = 2e6 + 7;

vector <int> a[N], id[N], ans[N];

int dfn[N], low[N], mark[N], vis[N];

int n, m, x, y, times, cnt;

void tarjan(int x, int pre){

    dfn[x] = low[x] = ++ times;

    for(int i = 0; i < a[x].size(); i ++){
        int to = a[x][i], idto = id[x][i];
        if(idto == pre)
            continue;
        if(!dfn[to]){
            tarjan(to, idto);
            low[x] = min(low[x], low[to]);
            if(low[to] > dfn[x])
                mark[idto] = 1;
        }
        else
            low[x] = min(low[x], dfn[to]);
    }

}

void dfs(int x){
    vis[x] = 1;
    ans[cnt].push_back(x);
    for(int i = 0; i < a[x].size(); i ++){
        int to = a[x][i], idto = id[x][i];
        if(mark[idto])
            continue;
        if(vis[to])
            continue;
        dfs(to);
    }
}

int main(){

    cin >> n >> m;

    for(int i = 1; i <= m; i ++){
        cin >> x >> y;
        a[x].push_back(y), a[y].push_back(x);
        id[x].push_back(i), id[y].push_back(i);
    }

    for(int i = 1; i <= n; i ++)
        if(!dfn[i]) tarjan(i, -1);

    for(int i = 1; i <= n; i ++)
        if(!vis[i]){
            cnt ++;
            dfs(i);
        }

    cout << cnt << endl;

    for(int i = 1; i <= cnt; i ++){
        cout << ans[i].size() << ' ';
        for(auto x : ans[i])
            cout << x << ' ';
        cout << endl;
    }
    return 0;
}*/

//https://www.luogu.com.cn/problem/P8435
//P8435 【模板】点双连通分量
/*#include<bits/stdc++.h>
using namespace std;

const int N = 2e6 + 7;

vector <int> a[N], ans[N];

int dfn[N], low[N], cut[N];

int n, m, x, y, times, cnt;

stack <int> st;

void tarjan(int x, int fa){
    dfn[x] = low[x] = ++ times;
    int son = 0;
    st.push(x);
    for(auto to : a[x]){
        if(to == fa)
            continue;
        if(!dfn[to]){
            tarjan(to, x);
            son ++;
            low[x] = min(low[x], low[to]);
            if(low[to] >= dfn[x]){
                cnt ++;
                int tp;
                do {
                    tp = st.top();
                    ans[cnt].push_back(tp);
                    st.pop();
                } while(tp != to);
                ans[cnt].push_back(x);
            }
        }
        else
            low[x] = min(low[x], dfn[to]);
    }
    if(!fa && !son){
        cnt ++;
        ans[cnt].push_back(x);
    }
}

int main(){

    cin >> n >> m;

    for(int i = 1; i <= m; i ++){
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }

    for(int i = 1; i <= n; i ++)
        if(!dfn[i])
            tarjan(i, 0);
    cout << cnt << endl;
    for(int i = 1; i <= cnt; i ++){
        cout << ans[i].size() << ' ';
        for(auto out : ans[i])
            cout << out << ' ';
        cout << endl;
    }
    return 0;
}*/

