//双端对列bfs
#include<bits/stdc++.h>
using namespace std;
const int N = 5e2 + 7;
int dis[N][N], n, m, s1, s2, e1, e2;
bool f[N][N]; char a[N][N];
struct str{
    int x, y;
};
deque <str> q;
int dx[4] = {1, 0,-1, 0};
int dy[4] = {0,-1, 0, 1};
void init(){
    memset(f, 0, sizeof(f));
    memset(dis, 0x3f, sizeof(dis));
    q.clear();
}
int main(){
    while(cin >> n >> m){
        if(!n && !m)
            break;
        init();
        for(int i = 1;i <= n;i ++)
            for(int j = 1;j <= m;j ++)
                cin >> a[i][j];
        cin >> s1 >> s2 >> e1 >> e2;
        dis[s1][s2] = 0;
        q.push_front({s1, s2});
        while(!q.empty()){
            str now = q.front();
            q.pop_front();
            if(f[now.x][now.y])
                continue;
            f[now.x][now.y] = true;
            if(now.x == e1 && now.y == e2){
                cout << dis[now.x][now.y] << endl;
                break;
            }
            for(int i = 0;i < 4;i ++){
                int nx = dx[i] + now.x, ny = dy[i] + now.y, sum = (a[nx][ny] != a[now.x][now.y]);
                if(nx < 1 || nx > n || ny < 1 || ny > m)
                    continue;
                if(f[nx][ny])
                    continue;
                if(dis[nx][ny] <= dis[now.x][now.y] + sum)
                    continue;
                dis[nx][ny] = dis[now.x][now.y] + sum;
                if(!sum)
                    q.push_front({nx, ny});
                else
                    q.push_back({nx, ny});
            }
        }
    }
    return 0;
}