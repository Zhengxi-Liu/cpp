#include<bits/stdc++.h>
using namespace std;
const int N = 3e2 + 7;
int n, t, s1, s2, e1, e2;
struct str{
    int x, y;
};
bool f[2][N][N];
int dis[2][N][N];
int dx[8] = {2, 2, 1, 1,-2,-2,-1,-1};
int dy[8] = {1,-1, 2,-2, 1,-1, 2,-2};
queue <str> q[2];// q[0] is from start, q[1] is from end.
void init(){
    memset(dis, 0, sizeof(dis));
    memset(f, 0, sizeof(f));
    while(!q[0].empty()) q[0].pop();
    while(!q[1].empty()) q[1].pop();
}
bool expand(int k){
    str now = q[k].front();
    q[k].pop();
    for(int i = 0;i < 8;i ++){
        int nx = dx[i] + now.x, ny = dy[i] + now.y;
        if(nx < 1 || nx > n || ny < 1 || ny > n)
            continue;
        if(f[k][nx][ny])
            continue;
        q[k].push({nx, ny});
        f[k][nx][ny] = true;
        dis[k][nx][ny] = dis[k][now.x][now.y] + 1;
        if(f[1 - k][nx][ny]){
            cout << dis[k][nx][ny] + dis[1 - k][nx][ny] << endl;
            return true;
        }
    }
    return false;
}
void bfs(){
    if(s1 == e1 && s2 == e2){
        cout << 0 << endl;
        return;
    }
    q[0].push({s1, s2});
    q[1].push({e1, e2});
    f[0][s1][s2] = f[1][e1][e2] = true;
    while(!q[0].empty() && !q[1].empty()){
        if(q[0].size() < q[1].size()){
            if(expand(0))
                return;
        }
        else{
            if(expand(1))
                return;
        }
    }
}
int main(){
    cin >> t;
    while(t --){
        cin >> n >> s1 >> s2 >> e1 >> e2;
        s1 ++; s2 ++; e1 ++; e2 ++; 
        init();
        bfs();
    }
    return 0;
}