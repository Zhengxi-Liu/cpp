/*#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t --){
        string s;
        cin >> s;
        for(int i = 0;i < s.size();i ++){
            if(s[i] == 'O')
                cout << "[###OREO###]" << endl;
            else if(s[i] == 'R')
                cout << " [--------]" << endl;
            else if(s[i] == '&')
                cout << endl << endl;
        }
    }
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int t, idx = 0;
double sh, hs, dis, spe, dam, a[N];
int main(){
    cin >> t;
    while(t --){
        cin >> sh >> hs >> dis >> spe >> dam;
        double time = dis / spe, h = hs - dam;
        if(sh - time * dam < 0){
            if(h <= 0){
                //cout << "-1" << endl;
                a[++ idx] = -1;
            }
            else{
                //cout << time + (time * dam - sh) / h << endl;
                a[++ idx] = time + (time * dam - sh) / h;
            }
        }
        else {
            //cout << time << endl;
            a[++ idx] = time;
        }
    }
    for(int i = 1;i <= idx;i ++)
        cout << a[i] << endl;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 5e2 + 7;
long long a[N][N], dis[N][N], t, n, m, maxn = 0, b[N], idx = 0;
struct str{
    int x, y;
};
int dx[4] = {1, 0, 0,-1};
int dy[4] = {0, 1,-1, 0};
void bfs(int xx1, int yy1, int xx){
    queue <str> q;
    str s;
    s.x = xx1;
    s.y = yy1;
    q.push(s);
    while(!q.empty()){
        str now = q.front();
        q.pop();
        for(int i = 0;i < 4;i ++){
            int nx = dx[i] + now.x, ny = now.y + dy[i];
            if(nx < 1 || nx > n || ny > m || ny < 1)
                continue ;
            if(a[nx][ny] < xx)
                continue ;
            if(dis[nx][ny] != -1)
                continue;
            dis[nx][ny] = 1;
            str t;
            t.x = nx;
            t.y = ny;
            q.push(t);
        }
    }
}
int main(){
    cin >> t;
    memset(dis, -1, sizeof(dis));
    while(t --){
        cin >> n >> m;
        maxn = 0;
        for(int i = 1;i <= n;i ++)
            for(int j = 1;j <= m;j ++){
                cin >> a[i][j];
                maxn = max(maxn, a[i][j]);
            }
        int ans = 0;
        for(int ii = 0;ii <= maxn;ii ++){
            int maxnn = 0;
            for(int i = 1;i <= n;i ++)
                for(int j = 1;j <= m;j ++){
                    if(a[i][j] >= ii && dis[i][j] != 1){
                        //cout << ii << ' ' << i << ' ' << j <<  ' '  << dis[i][j] <<  endl;
                        bfs(i, j, ii);
                        maxnn += 1;
                    }
                }   
            ans = max(ans, maxnn);
            //cout << endl;
            //cout << maxnn << endl;
            //cout << endl << endl << endl;
            memset(dis, -1, sizeof(dis));
        }
        cout << ans << endl; 
        //b[++idx] = ans;
    }
    //for(int i = 1;i <= idx;i ++)
      //  cout << b[i] << endl;

    return 0;
}
*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 7;
string a[N], dis[N];
int n, m, t, k;
int main(){
    cin >> t;
    while(t --){
        cin >> n >> m >> k;
        int sx, sy, ex, ey;
        for(int i = 1;i <= n;i ++){
            cin >> a[i];
            a[i] = " " + a[i];
        }
        for(int i = 1;i <= n;i ++)
            dis[i] =  "";
        
    }
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
typedef long long LL;
LL a[N], n, b, t;
LL cmp1(LL x){
    LL ret = 0;
    for(int i = 1;i <= n;i ++)
        if(a[i] > x)
            ret += a[i] - x;
    return ret;

}
LL cmp2(LL x){
    LL ret = 0;
    for(int i = 1;i <= n;i ++)
        if(a[i] < x)
            ret += x - a[i];
    return ret;

}
int main(){
    cin >> t;
    while(t --){
        cin >> b >> n;
        for(int i = 1;i <= n;i ++)
            cin >> a[i];
        LL l = 0, r = 1e18 + 7;
        while(l + 1 < r){
            LL mid = (l + r) / 2;
            if(cmp1(mid) >= b)
                l = mid + 1;
            else
                r = mid;
        }
        if(cmp2(r) > cmp2(r - 1) && cmp1(r - 1) <= b)
            r -= 1;
        if(cmp2(l) < cmp2(r) && cmp1(l) <= b)
            r = l;
        cout << r << endl;
    }
}*/
