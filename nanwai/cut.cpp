//A. 桥（割边）
/*#include<bits/stdc++.h>
using namespace std;

const int N = 3e4 + 7;

typedef pair <int, int> PI;

vector <PI> a[N];
map <int, int> mp[N];

int dfn[N], low[N], times;

int n, m, x, y, ans;

void tarjan(int x, int id){
    //cout << x << endl;
    dfn[x] = low[x] = ++ times;
    for(auto tow : a[x]){
        int to = tow.first, to_id = tow.second;
        if(!dfn[to]){
            tarjan(to, to_id);
            low[x] = min(low[x], low[to]);
            //cout << x << ' ' << dfn[x] << ' ' << low[to] << endl;
            if(low[to] > dfn[x] && mp[x][to] < 2)
                ans ++;
        }
        else if(to_id != id)
            low[x] = min(low[x], dfn[to]);
    }
}

int main(){

    while(cin >> n >> m){

        if(!n && !m)
            break;

        for(int i = 1; i <= m; i ++){
            cin >> x >> y;
            a[x].push_back({y, i}); mp[x][y] ++;
            a[y].push_back({x, i}); mp[y][x] ++;
        }
        for(int i = 1; i <= n; i ++)
            if(!dfn[i])
                tarjan(i, 0);
        cout << ans << endl;

        for(int i = 1; i <= n; i ++){
            a[i].clear();
            mp[i].clear();
            dfn[i] = low[i] = 0;
        }
        times = ans = 0;
    }


    return 0;
}*/

//B. 割点
/*#include<bits/stdc++.h>
using namespace std;

const int N = 1e4 + 7;

vector <int> a[N];

int dfn[N], low[N], times;

int b[N], n, x, y, ans;

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
	if(x == 1 && child < 2)
		flag = false;
	b[x] = flag == true;
}

int main(){
	
	while(cin >> n && n){
		while(cin >> x && x)
			while(true){
				cin >> y;
				a[x].push_back(y);
				a[y].push_back(x);
				if(getchar() == '\n')
					break;
			}
		tarjan(1);
		for(int i = 1; i <= n; i ++)
			if(b[i])
				ans ++;
		cout << ans << endl;
		times = ans = 0;
		memset(b, 0, sizeof(b));
		for(int i = 1; i <= n; i ++){
			a[i].clear();
			dfn[i] = low[i] = 0;
		}
	}
	
	return 0;
}*/

//C. 曹操的桥梁
/*#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;

typedef pair < int, pair <int, int> > PI;

vector <PI> a[N];

int dfn[N], low[N], times;

int n, m, x, y, v, ans;

void tarjan(int x, int id){
    dfn[x] = low[x] = ++ times;
    for(auto tow : a[x]){
        int to = tow.first, v = tow.second.first, id_to = tow.second.second;
        if(!dfn[to]){
            tarjan(to, id_to);
            low[x] = min(low[x], low[to]);
            if(low[to] > dfn[x])
                ans = min(ans, v);
        }
        else if(id_to != id)
            low[x] = min(low[x], dfn[to]);
    }
}

int main(){

    while(cin >> n >> m){
        if(cin.fail())
            break;

        for(int i = 1; i <= m; i ++){
            cin >> x >> y >> v;
            a[x].push_back({y, {v, i}});
            a[y].push_back({x, {v, i}});
        }
        ans = INT_MAX;
        for(int i = 1; i <= n; i ++)
            if(!dfn[i])
                tarjan(i, 0);

        cout << ((ans == INT_MAX) ? -1 : ans) << endl;

        for(int i = 1; i <= n; i ++){
            a[i].clear();
            dfn[i] = low[i] = 0;
        }
        times = 0;

    }
    return 0;
}*/

//D. 热身
/*#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;

typedef pair <int, int> PI;

vector <PI> a[N], b[N];

int dfn[N], low[N], times;
bool mark[N];

int id[N], dis[N], cnt;

int n, m, x, y, ans, maxn;

void tarjan(int x, int id){
    dfn[x] = low[x] = ++ times;
    for(auto tow : a[x]){
        int to = tow.first, id_to = tow.second;
        if(!dfn[to]){
            tarjan(to, id_to);
            low[x] = min(low[x], low[to]);
            if(low[to] > dfn[x])
                mark[id_to] = 1, maxn ++;
        }
        else if(id_to != id)
            low[x] = min(low[x], dfn[to]);
    }
}

void dfs(int x, int fa){
    id[x] = cnt;
    for(auto tow : a[x]){
        int to = tow.first, v = tow.second;
        if(to == fa || mark[v] || id[to])
            continue;
        dfs(to, x);
    }
}

void dfs2(int x, int fa){
    int res = 0;
    for(auto tow : b[x]){
        int to = tow.first;
        if(dis[to] || to == fa)
            continue;
        dfs2(to, x);
        res = max(res, dis[to]);
    }
    dis[x] = res + 1;
}

int main(){

    cin >> n >> m;

    for(int i = 1; i <= m; i ++){
        cin >> x >> y;
        a[x].push_back({y, i});
        a[y].push_back({x, i});
    }
    
    tarjan(1, 0);

    for(int i = 1; i <= n; i ++)
        if(!id[i]){
            cnt ++;
            dfs(i, 0);
        }

    for(int i = 1; i <= n; i ++)
        for(auto to : a[i])
            if(id[i] != id[to.first])
                b[id[i]].push_back({id[to.first], 0});
    // for(int i = 1; i <= cnt; i ++){
    //     cout << b[i].size() << endl;
    //     for(auto to : b[i])
    //         cout << to.first << ' ';
    //     cout << endl;
    // }
    dfs2(1, 0);
    for(int i = 1; i <= n; i ++)
        if(dis[i] > dis[ans])
            ans = i;
    memset(dis, 0, sizeof(dis));
    dfs2(ans, 0);
    for(int i = 1; i <= n; i ++)
        ans = max(ans, dis[i]);
    cout << maxn - (ans - 1) << endl;
    return 0;
}*/

//E. 网络
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

typedef pair <int, int> PI;

vector <PI> a[N];

int dfn[N], low[N], times;

int n, m, x, y, q;

void tarjan(int x, int id){

}

int main(){

    cin >> n >> m;

    for(int i = 1; i <= m; i ++){
        cin >> x >> y;
        a[x].push_back({y, i});
        a[y].push_back({x, i});
    }

    cin >> q;

    while(q --){
        cin >> x >> y;

    }

    return 0;
}