/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 7;
int dp[N], x, n, k;
int main(){
    cin >> n >> k;
    dp[0] = 1;
    for(int i = 1;i <= n;i ++){
        cin >> x;
        for(int j = k;j >= x;j --)
            dp[j] |= dp[j - x];
    }
    if(dp[k])
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 7;
int vis[N][N], n, m;
char a[N][N];
int dx[4] = {1, 0, 0,-1};
int dy[4] = {0, 1,-1, 0};
struct str{
    int x, y;
};
int bfs(int x, int y){
    queue <str> q;
    str t;t.x = x;t.y = y;
    q.push(t);
    int ret = 1;
    vis[x][y] = 1;
    while(!q.empty()){
        str now = q.front();
        q.pop();
        for(int i = 0;i < 4;i ++){
            int nx = now.x + dx[i], ny = now.y + dy[i];
            if(nx < 1 || nx > n || ny < 1 || ny > m)
                continue;
            if(vis[nx][ny])
                continue;
            if(a[nx][ny] == '#')
                continue;
            ret ++;
            t.x = nx, t.y = ny;
            q.push(t);
            vis[nx][ny] = 1;
        }
    }
    return ret;
}
int main(){
    cin >> m >> n;
    int x, y;
    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= m;j ++){
            cin >> a[i][j];
            if(a[i][j] == '@')
                x = i, y = j;
        }
    cout << bfs(x, y) << endl;
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 5e3 + 7;
int dp[N], a[N], n, m;
map <int, int> mp;
int main(){
    cin >> n >> m;
    for(int i = 1;i <= n;i ++){
        cin >> a[i];
        mp[a[i]] = i;
    }
    for(int i = 1;i < n;i ++)
        for(int j = i + 1;j <= n;j ++){
            int z = m - a[i] - a[j];
            if(a[i] + a[j] <= m && mp.count(z) && mp[z] != i && mp[z] != j){
                cout << i << ' ' << j << ' ' << mp[z] << endl;
                exit(0);
            }
        }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 3e2 + 7;
int dp[N][N], n, m, sx, sy, ex, ey;
int dx[8] = {1, 1, 2, 2,-1, -1,-2, -2};
int dy[8] = {2,-2, 1,-1, 2, -2, 1, -1};
struct str{
    int x, y;
};
int bfs(){
    queue <str> q;
    str s;s.x = sx, s.y = sy;
    q.push(s);
    dp[sx][sy] = 0;
    while(!q.empty()){
        str now = q.front();
        q.pop();
        for(int i = 0;i < 8;i ++){
            int nx = dx[i] + now.x, ny = dy[i] + now.y, t = dp[now.x][now.y] + 1;
            if(nx < 1 || nx > n || ny < 1 || ny > n)
                continue;
            if(dp[nx][ny] != -1)
                continue;
            str temp;
            temp.x = nx; temp.y = ny;
            q.push(temp);
            dp[nx][ny] = t;
        }
    }
    return dp[ex][ey];
}
int main(){
    cin >> n >> sx >> sy >> ex >> ey;
    sx ++; sy ++; ex ++; ey ++;
    memset(dp, -1, sizeof(dp));
    cout << bfs() << endl;
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 2e2 + 7;
int dp[N], a[N], x, y, n;
int bfs(){
    memset(dp, 0x3f, sizeof(dp));
    dp[x] = 0;
    queue <int> q;
    q.push(x);
    while(!q.empty()){
        int now = q.front();
        q.pop();
        if(now - a[now] >= 1)
            if(dp[now] + 1 < dp[now - a[now]]){
                dp[now - a[now]] = dp[now] + 1;
                q.push(now - a[now]);
            }
        if(now + a[now] <= n)
            if(dp[now] + 1 < dp[now + a[now]]){
                dp[now + a[now]] = dp[now] + 1;
                q.push(now + a[now]);
            }
    }
    if(dp[y] == 0x3f3f3f3f)
        dp[y] = -1;
    return dp[y];
}
int main(){
    while(cin >> n){
        if(!n)
            break;
        cin >> x >> y;
        for(int i = 1;i <= n;i ++)
            cin >> a[i];
        cout << bfs() << endl;
    }
    return 0;
}*/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 7, INF = 0x3f3f3f3f;
int dp[N][N], n, m, q, x, y, z;
int main(){
    cin >> n >> m >> q;
    memset(dp, 0x3f, sizeof(dp));
    for(int i = 1;i <= m;i ++){
        cin >> x >> y >> z;
        dp[x][y] = z;
        dp[y][x] = z;
    }
    for(int i = 1;i <= n;i ++)
        dp[i][i] = 0;
    for(int k = 1;k <= n;k ++)
        for(int i = 1;i <= n;i ++)
            for(int j = 1;j <= n;j ++){
                if(dp[i][k] != INF && dp[k][j] != INF)
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
    while(q --){
        cin >> x >> y;
        if(dp[x][y] == INF)
            dp[x][y] = -1;
        cout << dp[x][y] << endl;
    }
    return 0;
}