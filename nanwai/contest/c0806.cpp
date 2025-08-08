//A. S数
/*#include<bits/stdc++.h>
using namespace std;

#define int long long

int ans, l, r;

int cal(int x){
    int res = 0;
    while(x){
        res += x % 10;
        x /= 10;
    }
    return res;
}

void dfs(int sum, int step){
    if(sum > r) return;
    if(cal(sum) * cal(sum) == cal(sum * sum) && sum >= l)
        ans ++;
    if(step > 10) return;
    if(sum) dfs(sum * 10, step + 1);
    dfs(sum * 10 + 1, step + 1);
    dfs(sum * 10 + 2, step + 1);
    dfs(sum * 10 + 3, step + 1);
}


signed main(){

    ifstream fin("snum.in");
    ofstream fout("snum.out");

    fin >> l >> r;

    dfs(0, 1);
    
    fout << ans << endl;

    return 0;
}*/

//B. 字典序迷宫
/*#include<bits/stdc++.h>
using namespace std;

const int N = 2e3 + 7;

typedef pair <int, int> PI;

int n, m;

vector <PI> s[N * 2];

bool mk[N][N];

char c[N][N];

int main(){

    ifstream fin("maze.in");
    ofstream fout("maze.out");

    int t = clock();

    fin >> n >> m;

    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++){
            fin >> c[i][j];
            s[i + j - 1].push_back({i, j});
        }

    for(int i = 1; i <= n; i ++) mk[i][0] = 1;
    for(int j = 1; j <= m; j ++) mk[0][j] = 1;

    for(int i = 2; i <= n + m - 1; i ++){
        char cc = 'z' + 1;
        for(PI now : s[i]){
            int x = now.first, y = now.second;
            if(mk[x - 1][y] && mk[x][y - 1]){
                mk[x][y] = 1;
                continue;
            }
            cc = min(cc, c[x][y]);
        }
        for(PI now : s[i]){
            int x = now.first, y = now.second;
            if(mk[x - 1][y] && mk[x][y - 1]) continue;
            if(c[x][y] != cc) mk[x][y] = 1; 
        }
    }

    string ans;

    for(int x = n, y = m; !(x == 1 && y == 1);){
        ans += c[x][y];
        if(!mk[x - 1][y]) x --;
        else if(!mk[x][y - 1]) y --;
    }

    reverse(ans.begin(), ans.end());

    fout << c[1][1] + ans << endl;
    

    return 0;
}*/

//C. 区域发展
/*#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;

typedef pair <int, int> PI;

int n, q, m, x, y, sq, ans[N];

int id[N], fa[N], sz[N], cnt[N];

vector <int> a[N];
vector <PI> qry[N], sqry[N];

void dfs(int x){
    cnt[id[x]] ++;
    for(int to : a[x]) dfs(to);
    for(PI now : qry[id[x]]) ans[now.second] += cnt[now.first];
    cnt[id[x]] --;
}

void dfs2(int x){
    for(PI now : sqry[id[x]]) ans[now.second] -= cnt[now.first];
    for(int to : a[x]) dfs2(to);
    // 这样就能做到只统计当前子树里的和 (cnt 现在 - cnt 原来 = cnt当前子树)
    for(PI now : sqry[id[x]]) ans[now.second] += cnt[now.first];
    cnt[id[x]] ++;
}


int main(){

    ifstream fin("regions.in");
    ofstream fout("regions.out");

    fin >> n >> m >> q >> id[1];

    sq = sqrt(n);

    sz[id[1]] ++;

    for(int i = 2; i <= n; i ++){
        fin >> fa[i] >> id[i];
        a[fa[i]].push_back(i);
        sz[id[i]] ++;
    }

    for(int i = 1; i <= q; i ++){
        fin >> x >> y;
        if(sz[y] <= sq) qry[y].push_back({x, i});
        else sqry[x].push_back({y, i});
    }

    dfs(1);

    dfs2(1);

    for(int i = 1; i <= q; i ++)
        fout << ans[i] << endl;
    

    return 0;
}*/

//D. GCD数列
#include<bits/stdc++.h>
using namespace std;




int main(){


    return 0;
}