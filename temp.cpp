/*#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
int ch[N][26], cnt[N], ne[N], ans[N];
int n, m, idx = 0;
string s, t[N];
void insert(string s){
    int p = 0;
    for(int i = 0;i < s.size();i ++){
        int x = s[i] - 'a';
        if(!ch[p][x])
            ch[p][x] = ++idx;
        p = ch[p][x];
    }
    t[p] = s;
    cnt[p] ++;
}
void prep(){
    queue <int> q;
    for(int i = 0;i < 26;i ++)
        if(ch[0][i])
            q.push(ch[0][i]);
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int i = 0;i < 26;i ++){
            int p = ch[now][i];
            if(p){
                ne[p] = ch[ne[now]][i];
                q.push(p);
            }
            else
                ch[now][i] = ch[ne[now]][i];
        }
    }
}
void init(){
    memset(ch, 0, sizeof(ch));
    memset(ne, 0, sizeof(ne));
    memset(cnt, 0, sizeof(cnt));
    memset(ans, 0, sizeof(ans));
    idx = 0;
}
int main(){
    while(cin >> n){
        if(!n)
            break;
        init();
        while(n --){
            cin >> s;
            insert(s);
        }
        prep();
        cin >> s;
        int maxn = 0;
        for(int i = 0,j = 0;i < s.size();i ++){
            int x = s[i] - 'a';
            while(j && !ch[j][x])
                j = ne[j];
            if(ch[j][x])
                j = ch[j][x];
            
            int p = j;
            while(p){
                ans[p] += cnt[p];
                maxn = max(maxn, ans[p]);
                p = ne[p];
            }
        }
        cout << maxn << endl;
        for(int i = 0;i < N;i ++)
            if(cnt[i] && ans[i] == maxn)
                cout << t[i] << endl;
    }
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 3e6 + 7, M = 1e5 + 7;
typedef long long LL;
LL ch[N][2], n, x[M], idx = 0;
LL AND(int x){
    if(!x)
        return 1;
    return 0;
}
void insert(LL s){
    int p = 0;
    for(int i = 31;i >= 0;i --){
        int x = (s >> i) & 1;
        if(!ch[p][x])
            ch[p][x] = ++idx;
        p = ch[p][x];
    }
}
LL query(LL num){
    LL p = 0, ret = 0;
    for(int i = 31;i >= 0;i --){
        int x = (num >> i) & 1, y = AND(x);
        if(ch[p][y]){
            p = ch[p][y];
            ret = ret^(1 << i);
        }
        else 
            p = ch[p][x];
    }
    return ret;
}
int main(){
    cin >> n;
    for(int i = 1;i <= n;i ++){
        cin >> x[i];
        insert(x[i]);
    }
    LL ans = 0;
    for(int i = 1;i <= n;i ++)
        ans = max(ans, query(x[i]));
    cout << ans << endl;
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 7;
typedef long long LL;
LL a[N][N], dp[N][N], n, m, x, y;
LL dx[8] = {1, 1, 2, 2,-1,-1, -2,-2};
LL dy[8] = {2,-2, 1,-1, 2,-2, -1, 1};
int main(){
    cin >> n >> m >> x >> y;
    n += 2; m += 2; x += 2; y += 2;
    for(int i = 0;i < 8;i ++){
        int nx = dx[i] + x, ny = dy[i] + y;
        a[nx][ny] = 1;
    }
    a[x][y] = dp[2][1] = 1;
    for(int i = 2;i <= n;i ++)
        for(int j = 2;j <= m;j ++){
            if(a[i][j])
                continue;
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    cout << dp[n][m] << endl;
    return 0;
}*/