// A. 操作进程
/*#include<bits/stdc++.h>
using namespace std;

const int N = 2e3 + 7;

vector <int> a[N];

int s[N], in[N], dfn[N];

queue <int> q;

int n, ans, cnt;

char c;

int main(){

    cin >> n;

    for(int i = 1; i <= n; i ++)
        cin >> s[i];
    
    cin >> n;

    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++){
            cin >> c;
            if(c == 'Y') a[i].push_back(j), in[j] ++;
        }

    for(int i = 1; i <= n; i ++)
        if(!in[i]) q.push(i);
    
    while(!q.empty()){
        int x = q.front();
        dfn[x] += s[x], cnt ++, q.pop();
        ans = max(ans, dfn[x]);
        for(int to : a[x]){
            in[to] --, dfn[to] = max(dfn[to], dfn[x]);
            if(!in[to]) q.push(to);
        }
    }

    if(cnt != n) {cout << -1 << endl; return 0;}

    cout << ans << endl;

    return 0;
}*/

// B. 逃跑
/*#include<bits/stdc++.h>
using namespace std;

const int N = 1e2 + 7, INF = 1e9;

int dp[N][N];

int n, ans;

char c;

int tran(char c){
    if(c == ' ') return INF;
    if(c <= 'Z' && c >= 'A') return c - 'A' + 36;
    if(c <= 'z' && c >= 'a') return c - 'a' + 10;
    return c - '0';
}

int main(){

    cin >> n;

    for(int i = 1; i <= n; i ++){

        cin.get(c);

        for(int j = 1; j <= n; j ++){
            cin.get(c);
            dp[i][j] = tran(c);
        }
    }

    for(int k = 1; k <= n; k ++)
        for(int i = 1; i <= n; i ++)
            for(int j = 1; j <= n; j ++){
                if(dp[i][k] == INF || dp[k][j] == INF) continue;
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
    
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++)
            ans = max(ans, dp[i][j]);
    
    cout << ((ans == INF) ? -1 : ans) << endl;

    return 0;
}*/

// C. 时光机商贩
/*#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;

typedef pair <int, pair <int, int> > PI;

PI a[N];

int dsu[N], n, m, k, ans, cnt;

string s, t;

int find(int x){
    return dsu[x] == x ? x : dsu[x] = find(dsu[x]);
}

void merge(int x, int y){
    dsu[find(x)] = find(y);
}

void prs(string s){
    //cout << s << ' ';
    int x = 0, y = 0, v = 0, cnt = 0;
    for(int i = 0; i <= s.size(); i ++){
        if(i == s.size() || s[i] == ' '){
            //cout << x << ' ' << y << ' ' << v << endl;
            x ++, y ++;
            a[++ k] = {v, {x, y}};
            x = y = v = cnt = 0;
            continue;
        }
        if(s[i] == ','){ 
            cnt ++; 
            continue;
        }
        if(!cnt) x = x * 10 + s[i] - '0';
        if(cnt == 1) y = y * 10 + s[i] - '0';
        if(cnt == 2) v = v * 10 + s[i] - '0';
    }
}

int main(){

    cin >> n >> m;
    getline(cin, t);
    while(m --){
        getline(cin, t);
        s += t;
    }
    prs(s);
    for(int i = 1; i <= n + 1; i ++) dsu[i] = i;
    sort(a + 1, a + k + 1, less <PI>());

    for(int i = 1; i <= k; i ++){
        int x = find(a[i].second.first), y = find(a[i].second.second);
        //cout << x << ' ' << y << ' ' << a[i].first << endl;
        if(x != y){
            cnt ++;
            merge(x, y);
            ans += a[i].first;
        }
    }
    if(cnt < n - 1){cout << -1 << endl; exit(0);}

    cout << ans << endl;

    return 0;
}*/

// D. 两棵树合并
/*#include<bits/stdc++.h>
using namespace std;

const int N = 10 + 7, INF = 1e9;

int dp1[N][N], dp2[N][N], b[N], a[N];

int n, k, ans;

char c;

void dfs(int step){
    if(step > n){
        int cnt = 0;
        for(int i = 1; i < n; i ++)
            for(int j = i + 1; j <= n; j ++)
                if(dp1[i][j] + dp2[a[i]][a[j]] + 2 == k)
                    cnt ++;
        ans = max(ans, cnt);
        return;
    }
    for(int i = 1; i <= n; i ++)
        if(!b[i]){
            a[step] = i;
            b[i] = 1;
            dfs(step + 1);
            b[i] = 0;
        }
}

int main(){

    cin >> n;
    for(int i = 1; i <= n; i ++) 
        for(int j = 1; j <= n; j ++){ 
            cin >> c; 
            if(c == 'X') dp1[i][j] = 1;
            else dp1[i][j] = INF;
        }
    cin >> n;
    for(int i = 1; i <= n; i ++) 
        for(int j = 1; j <= n; j ++){ 
            cin >> c; 
            if(c == 'X') dp2[i][j] = 1;
            else dp2[i][j] = INF;
        }
    cin >> k;

    for(int k = 1; k <= n; k ++)
        for(int i = 1; i <= n; i ++)
            for(int j = 1; j <= n; j ++){
                if(dp1[i][k] != INF && dp1[k][j] != INF) dp1[i][j] = min(dp1[i][j], dp1[i][k] + dp1[k][j]);
                if(dp2[i][k] != INF && dp2[k][j] != INF) dp2[i][j] = min(dp2[i][j], dp2[i][k] + dp2[k][j]);
            }

    dfs(1);

    cout << ans << endl;

    return 0;
}*/

// E. 图上点标号
/*#include<bits/stdc++.h>
using namespace std;

const int N = 2e3 + 7;

vector <int> a[N];

int in[N], ans[N], times, n;

char c;

priority_queue < int, vector <int>, less <int> > q;

int main(){

    cin >> n;

    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++){
            cin >> c;
            if(c == '1') a[j].push_back(i), in[i] ++;
        }

    for(int i = 1; i <= n; i ++)
        if(!in[i]) q.push(i);

    while(!q.empty()){
        int x = q.top();
        ans[x] = ++ times;
        q.pop();
        for(int to : a[x]){
            in[to] --;
            if(!in[to]) q.push(to);
        }
    }

    if(times != n) exit(0);

    for(int i = 1; i <= n; i ++)
        cout << n - ans[i] << ' ';

    cout << endl;

    return 0;
}*/

// F. 不同的两排
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;



int main(){



    return 0;
}