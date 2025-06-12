// A. 单词游戏
/*#include<bits/stdc++.h>
using namespace std;

const int N = 26 + 7;

vector <int> a[N];

int in[N], out[N], b[N], n, t;

string s;

void dfs(int x){
    b[x] = 1;
    for(auto to : a[x]){
        if(b[to])
            continue;
        dfs(to);
    }
}

int main(){

    cin >> t;

    while(t --){

        cin >> n;

        for(int i = 1; i <= n; i ++){
            cin >> s;
            int st = s[0] - 'a' + 1, ed = s[s.size() - 1] - 'a' + 1;
            out[st] ++;
            in[ed] ++;
            a[st].push_back(ed);
        }

        

        int cnt = 0, ans = 0, st = 1;
        for(int i = 1; i <= 26; i ++){
            if(in[i] != out[i]){
                if(out[i] - in[i] == 1)
                    st = i;
                cnt ++;
                if(abs(in[i] - out[i]) >= 2)
                    ans = 1;
            }
        }

        dfs(st);

        for(int i = 1; i <= 26; i ++){
            //cout << b[i];
            if((in[i] || out[i]) && !b[i])
                ans = 1;
        }

        if((cnt == 2 || cnt == 0) && !ans)
            cout << "Ordering is possible." << endl;
        else
            cout << "The door cannot be opened." << endl;

        for(int i = 1; i <= 26; i ++){
            out[i] = in[i] = b[i] = 0;
            a[i].clear();
        }
    }
    return 0;
}*/

// B. Ant Trip
/*#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

vector <int> a[N];

int id[N], edg[N], cnt;

int n, m, x, y, tmp, ans;

void dfs(int x){
    if(edg[x] % 2 == 1)
        tmp ++;
    id[x] = cnt;
    for(int to : a[x]){
        if(id[to]) 
            continue;
        dfs(to);
    }
}

int main(){

    while(cin >> n >> m){

        if(cin.fail())
            break;

        for(int i = 1; i <= m; i ++){
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
            edg[x] ++; edg[y] ++;
        }

        for(int i = 1; i <= n; i ++)
            if(!id[i]){
                cnt ++;
                tmp = 0;
                dfs(i);
                if(edg[i]){
                    //cout << tmp << ' ';
                    ans += max(1, tmp / 2);
                }
            }
        cout << ans << endl;
        for(int i = 1; i <= n; i ++){
            id[i] = edg[i] = 0;
            a[i].clear();
        }
        cnt = ans = 0;
    }

    return 0;
}*/

// C. 欧拉回路
#include<bits/stdc++.h>
using namespace std;

#define no { printf("NO\n"); exit(0);}

const int N = 1e5 + 7;

typedef pair <int, pair <int, int> > PI;

vector <PI> a[N];

int vis[N], ans[N], in[N], out[N], b[N];

int op, n, m, x, y, cnt, idx = 1;

void dfs1(int x){
    for(PI tox : a[x]){
        int to = tox.first, id = tox.second.first, mul = tox.second.second;
        if(vis[id])
            continue;
        vis[id] = 1;
        dfs1(to);
        ans[++ cnt] = id * mul;
    }
}

void dfs2(int x){
    for(PI tox : a[x]){
        int to = tox.first, id = tox.second.first;
        if(vis[id])
            continue;
        vis[id] = 1;
        dfs2(to);
        ans[++ cnt] = id;
    }
}
void dfs(int x){
    b[x] = 1;
    for(PI tox : a[x]){
        int to = tox.first;
        if(b[to])
            continue;
        dfs(to);
    }
}
void work1(){
    for(int i = 1; i <= n; i ++)
        if(a[i].size() % 2 == 1) no
    dfs1(idx);
}
void work2(){
    for(int i = 1; i <= n; i ++)
        if(out[i] != in[i]) no
    dfs2(idx);
}

int main(){

    scanf("%d %d %d", &op, &n, &m);

    for(int i = 1; i <= m; i ++){
        scanf("%d %d", &x, &y);
        a[x].push_back({y, {i, 1}});
        out[x] ++;
        in[y] ++;
        idx = x;
        if(op == 1)
            a[y].push_back({x, {i, -1}});
    }
    
    if(op == 1)
        work1();
    else 
        work2();
    dfs(idx);
    for(int i = 1; i <= n; i ++)
        if(!b[i] && a[i].size()) no
    printf("YES\n");
    for(int i = cnt; i >= 1; i --)
        printf("%d ", ans[i]);
    printf("\n");

    return 0;
}