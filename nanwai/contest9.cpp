//D. 幸运数字
/*#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e5 + 7;

int n, m, s[N], x[11], ans;

map <int, int> mp;


signed main(){

    cin >> n >> m;

    for(int i = 1; i < n; i ++)
        cin >> s[i];

    for(int i = 1; i <= m; i ++)
        cin >> x[i];

    int sum = 0;
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            if(i % 2 == 1) ans = max(ans, ++ mp[sum + x[j]]);
            else ans = max(ans, ++ mp[sum - x[j]]);
        }
        if(i % 2 == 1) sum += s[i];
        else sum -= s[i];
    }
    cout << ans << endl;

    return 0;
}*/

//E. 圆桌吃饭
/*#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 7;

#define int long long

int d[N * 2], x, n, ans = 1e18;

signed main(){

    cin >> n;

    for(int i = 1; i <= n; i ++){
        cin >> x;
        int st = (n + i - x) % n;
        d[st + 1] ++;
        d[st + n / 2 + 1] --;
        d[st + (n + 1) / 2 + 1] --;
        d[st + n + 1] ++;
    }

    for(int i = 1; i <= n + n; i ++)
        d[i] += d[i - 1];

    for(int i = 1; i <= n + n; i ++)
        d[i] += d[i - 1];

    for(int i = 1; i <= n; i ++)
        ans = min(ans, d[i] + d[n + i]);

    cout << ans << endl;

    return 0;
}*/

//F. 务农政策
/*#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e3 + 7;

int q[N], head, tail;

int dis[N][N], a[N][N], mx[N][N], mx2[N][N];

int n, m, t, x, y, ans;

int query(int s1, int s2, int e1, int e2){
    return dis[e1][e2] - dis[e1][s2 - 1] - dis[s1 - 1][e2] + dis[s1 - 1][s2 - 1];
}

signed main(){

    ifstream fin("policy.in");
    ofstream fout("policy.out");

    fin >> n >> m;

    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++){
            fin >> a[i][j];
            dis[i][j] = dis[i - 1][j] + dis[i][j - 1] - dis[i - 1][j - 1] + a[i][j];
        }
    fin >> t;
    while(t --){

        fin >> x >> y;

        for(int i = 1; i <= n; i ++){
            tail = 0, head = 1;
            for(int j = 1; j <= m; j ++){
                while(head <= tail && a[i][q[tail]] <= a[i][j]) tail --;
                q[++ tail] = j;
                while(q[head] < j - y + 1) head ++;
                if(j >= y){
                    mx[i][j] = a[i][q[head]];
                    //cout << mx[i][j] << ' ';
                }
            }
            //cout << endl;
        }
        //cout << endl;
        for(int j = y; j <= m; j ++){
            tail = 0, head = 1;
            for(int i = 1; i <= n; i ++){
                while(head <= tail && mx[q[tail]][j] <= mx[i][j]) tail --;
                q[++ tail] = i;
                while(q[head] < i - x + 1) head ++;
                if(i >= x) {
                    mx2[i][j] = mx[q[head]][j];
                    //cout << q[head] << ' ' << mx2[i][j] << " / ";
                }
            }
            //cout << endl;
        }
        ans = 1e18;
        for(int i = x; i <= n; i ++){
            for(int j = y; j <= m; j ++){
                ans = min(ans, mx2[i][j] * x * y - query(i - x + 1, j - y + 1, i, j));
                //cout << mx2[i][j] << ' ';
            }
            //cout << endl;
        }
        fout << ans << endl;

    }

    return 0;
}*/

