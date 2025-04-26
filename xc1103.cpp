/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 7;
int a[N][N], dp[N][N], n;
int main(){
    cin >> n;
    int t1, t2, t3;
    while(cin >> t1 >> t2 >> t3){
        if(!t1 && !t2 && !t3)
            break;
        a[t1][t2] = t3;
    }
    //for(int i = 1;i <= n;i ++)
      //  for(int j = 1;j <= n;j ++)
        //    cin >> a[i][j];
    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= n;j ++)
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
    cout << dp[n][n] << endl;
    return 0;
}*/
/*
#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 7;
int a[N][N], dp[N][N], n, m, x, y;
int dx[8] = {1, 2, 2,-1, -1, -2, 1,-2};
int dy[8] = {2, 1,-1, 2, -2, -1,-2, 1};
int main(){
    cin >> n >> m >> x >> y;
    for(int i = 0;i < 8;i ++){
        int nx = x + dx[i], ny = y + dy[i];
        if(nx < 0 || nx > n || ny < 0 || ny > m)
            continue;
        a[nx][ny] = 1;
    }
    dp[0][0] = 1;
    a[x][y] = 1;
    //cout << endl;
    for(int i = 0;i <= n;i ++){
        for(int j = 0;j <= m;j ++){
            if(a[i][j] || !i && !j)
                continue;  
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            //cout << dp[i][j] << ' ';
        }
        //cout << endl;
    }
    cout << dp[n][m] << endl;
    return 0;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 7;
int a[N][N], dp[N][N], n, m, ans = 0;
int dx[4] = {1, 0, 0,-1};
int dy[4] = {0,-1, 1, 0};
int maxlen(){
    int ret = 0;
    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= m;j ++){
            for(int k = 0;k < 4;k ++){
                int nx = i + dx[k], ny = j + dy[k];
                if(a[nx][ny] < a[i][j])
                    dp[nx][ny] = max(dp[i][j] + 1, dp[nx][ny]);
            }
        }
    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= m;j ++)
            ret = max(ret, dp[i][j]);
    return ret;
}
int main(){
    cin >> n >> m;
    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= m;j ++){
            cin >> a[i][j];
            dp[i][j] = 1;
        }
    cout << ans << endl;
    return 0;
}
*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 7;
int a[N][N], dp[N][N], dis[N][N], n, m, ans = 0;
int dx[4] = {1, 0, 0,-1};
int dy[4] = {0,-1, 1, 0};
struct str{
    int x, y;
};
int bfs(int xx, int yy){
    int ret = 0;
    memset(dis, 0, sizeof(dis));
    queue <str> q;
    dis[xx][yy] = 1;
    q.push({xx, yy});
    while(!q.empty()){
        str now = q.front();
        q.pop();
        for(int i = 0;i < 4;i ++){
            int nx = now.x + dx[i], ny = now.y + dy[i];
            if(nx < 1 || nx > n || ny < 1 || ny > m)
                continue;
            if(dis[nx][ny] >= dis[now.x][now.y] + 1)
                continue;
            if(a[nx][ny] >= a[now.x][now.y])
                continue;
            if(dis[now.x][now.y] < dp[nx][ny])
                continue;
            dis[nx][ny] = max(dis[nx][ny], dis[now.x][now.y] + 1);
            q.push({nx, ny});
        }
    }
    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= m;j ++){
            ret = max(ret, dis[i][j]);
            dp[i][j] = max(dp[i][j], dis[i][j]);
        }
    return ret;
}
int main(){
    cin >> n >> m;
    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= m;j ++)
            cin >> a[i][j];
    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= m;j ++){
            int flag = 0;
            for(int k = 0;k < 4;k ++)
                if(a[dx[k] + i][dy[k] + j] > a[i][j]){
                    flag = 1;
                    continue;
                }
            if(flag)
                continue;
            if(dp[i][j] > 0)
                continue;
            ans = max(ans, bfs(i, j));
        }
    cout << ans << endl;
    return 0;
}*/
/*
#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 7;
struct str{
    int x, y, z;
}a[N];
int dp[N], n;
bool cmp(str a, str b){
        return a.y < b.y;
}
int main(){
    cin >> n;
    for(int i = 1;i <= n;i ++)
        cin >> a[i].x >> a[i].y >> a[i].z;
    sort(a + 1, a + n + 1, cmp);
    for(int i = 1;i <= n;i ++){
        dp[i] = dp[i - 1];
        for(int j = i - 1;j >= 0;j --){
            if(a[j].y > a[i].x)
                continue ;
            dp[i] = max(dp[i], dp[j] + a[i].z);
        }
        //cout << dp[i] << ' ';
    }
    cout << dp[n] << endl;
    return 0;
}*/
#include<bits/stdc++.h>
using namespace std;
const int N = 10 + 7;
struct str{
    int x, y;
}a[N];
int n = 0, m, s, t, b[N], ans = 0;
void dfs(int step, int sum){
    if(step > n){
        //cout << sum << ' ';
        ans = max(ans, sum);
        return ;
    }
    for(int i = 1;i <= n;i ++){
        if(b[i])
            continue;
        int temp = sum;
        if(a[i].y)
            sum *= a[i].x;
        else    
            sum += a[i].x;
        b[i] = 1;
        dfs(step + 1, sum);
        b[i] = 0;
        sum = temp;
    }
}
int main(){
    cin >> m >> s;
    for(int i = 1;i <= s;i ++){
        cin >> a[++ n].x;
        a[n].y = 1;
    }
    cin >> t;
    for(int i = 1;i <= t;i ++){
        cin >> a[++ n].x;
        a[n].y = 0;
    }
    cout << n << endl;
    dfs(1, m);
    cout << ans << endl;
    return 0;
}