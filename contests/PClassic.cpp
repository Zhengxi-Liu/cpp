#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 7, M = 5 + 7;
int dp1[M][M][M][M], dp2[M][M][M][M];
int ans = 1e9, n;
char a[M][M], b, c;
string s;
int move(int t1, int t2, int t3, int t4){
    int s1 = abs(t1 - t3), s2 = abs(t2 - t4);
    return max(s1, s2);
}
struct str{
    int x, y;
};
map <char, str> mp;
void prep(){
    for(int i = 1;i <= 5;i ++)
        for(int j = 1;j <= 5;j ++){
            cin >> a[i][j];
            mp[a[i][j]].x = i;
            mp[a[i][j]].y = j;
        }
    cin >> b >> c >> s;
    n = s.size();
    s = " " + s;
    for(int i1 = 1;i1 <= 5;i1 ++)
        for(int i2 = 1;i2 <= 5;i2 ++)
            for(int i3 = 1;i3 <= 5;i3 ++)
                for(int i4 = 1;i4 <= 5;i4 ++){
                    dp1[i1][i2][i3][i4] = 2e9;
                    dp2[i1][i2][i3][i4] = 2e9;
                }
    int x1 = mp[b].x, y1 = mp[b].y, x2 = mp[c].x, y2 = mp[c].y;
    dp1[x1][y1][x2][y2] = 0;
}
void restore(){
    for(int i1 = 1;i1 <= 5;i1 ++)
        for(int i2 = 1;i2 <= 5;i2 ++)
            for(int i3 = 1;i3 <= 5;i3 ++)
                for(int i4 = 1;i4 <= 5;i4 ++){
                    dp1[i1][i2][i3][i4] = dp2[i1][i2][i3][i4];
                    dp2[i1][i2][i3][i4] = 2e9;
                }
}
int main(){
    prep();
    for(int i = 1;i <= n;i ++){
        int t1 = mp[s[i]].x, t2 = mp[s[i]].y;
        for(int i1 = 1;i1 <= 5;i1 ++)
            for(int i2 = 1;i2 <= 5;i2 ++)
                for(int i3 = 1;i3 <= 5;i3 ++)
                    for(int i4 = 1;i4 <= 5;i4 ++){
                        if(dp1[i1][i2][i3][i4] == 2e9)
                            continue;
                        dp2[t1][t2][i3][i4] = min(dp2[t1][t2][i3][i4], (dp1[i1][i2][i3][i4] + move(i1, i2, t1, t2)));
                        dp2[i1][i2][t1][t2] = min(dp2[i1][i2][t1][t2], (dp1[i1][i2][i3][i4] + move(i3, i4, t1, t2)));
                    }
        restore();
    }
    for(int i1 = 1;i1 <= 5;i1 ++)
        for(int i2 = 1;i2 <= 5;i2 ++)
            for(int i3 = 1;i3 <= 5;i3 ++)
                for(int i4 = 1;i4 <= 5;i4 ++)
                    ans = min(ans, dp1[i1][i2][i3][i4]);
    cout << ans + n << endl;
    return 0;
}

/*
/*#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
int a[N], b[N], n, ans = 0, s = 0, dis[N], dis2[N], id[N], id2[N];
int main(){
    cin >> n;
    for(int i = 1;i <= n;i ++){
        cin >> a[i];
        if(dis[i - 1] < a[i]){
            dis2[i] = dis[i - 1];
            id2[i] = id[i - 1];
            dis[i] = a[i];
            id[i] = i;
        }
        else {
            dis2[i] = dis2[i - 1];
            dis[i] = dis[i - 1];
            id2[i] = id2[i - 1];
            id[i] = id[i - 1];
        }
    }
    //for(int i = 1;i <= n;){
      //  int t = i;
        //while(a[i] < a[i + 1])
          //  i ++;
        //for(int j = t;j <= i;j ++)
          //  b[j] = i - t;
    //}
    for(int i = 1;i <= n;i ++){
        //cout << dis[i] << ' ' << dis2[i] << " / " << id[i] << ' ' << id2[i] << " / ";
        if(a[i] < dis[i - 1] && dis2[i - 1] < a[i]){
            s = id[i - 1];
        }
        if(a[i] > dis[i - 1])
            s = i;
        //cout << s << endl;
    }
    for(int i = 1;i <= n;i ++){
        int temp = i;
        for(int j = 1;j <= n;j ++){
            if(j == i)
                continue;
            if(j == i + 1 && a[j] <= a[j - 2]){
                cout << a[j] << '/';
                temp = j - 1;
                break;
            }
            else if(a[j] <= a[j - 1]){
                cout << a[j] << ' ';
                temp = j;
                break;
            }
        }
        b[i] = temp;
        if(ans < temp){
            ans = temp;
            s = i;
        }
        cout << temp << endl;
    }//
    if(s == -1)
        for(int i = 1;i <= n;i ++)
            if(a[i] <= a[i - 1]){
                s = i - 1;
                break;
            }
    cout << s << endl;
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
long long a[N], dis[N], n, k, ans;
int main(){
    cin >> n >> k;
    for(int i = 1;i <= n;i ++){
        cin >> a[i];
        dis[i] = dis[i - 1] + a[i];
    }
    ans = a[1] * k;
    for(int i = 2;i <= n;i ++){
        if(k - i + 1 < 0)
            break;
        ans = max(ans, dis[i] - a[1] + (k - i + 1) * a[i]);
    }
    cout << ans << endl;
    return 0;
}*/
/*
#include<bits/stdc++.h>
using namespace std;
int n, t1 = 1, t2 = 1;
int main(){
    cin >> n;
    while((t1 + 1) * t2 <= n){
        t1 ++;
        t2 *= t1;
    }
    for(int i = t1;i >= 1;i --){
        int temp = n / t2;
        if(temp > 9)
            cout << char(int('A') + temp - 10);
        else
            cout << temp;
        n -= temp * t2;
        t2 /= i;
    }
    cout << endl;
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 25 + 7, M = 1e4 + 7;
char a[N][N], l, r;
string s;
int n, dp[M][N], ans = 0;
int main(){
    for(int i = 1;i <= 5;i ++)
        for(int j = 1;j <= 5;j ++)
            cin >> a[i][j];
    cin >> l >> r >> s;

    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 7;
int a[N], b[N], n, m, x, y;
int ans1 = 0, ans2 = 0;
int main(){
    cin >> x >> y;
    cin >> n;
    n += 2;
    a[1] = 0;a[n] = x;
    for(int i = 2;i < n;i ++)
        cin >> a[i];
    cin >> m;
    m += 2;
    b[1] = 0;b[m] = y;
    for(int i = 2;i < m;i ++)
        cin >> b[i];
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    //cout << a[n - 1] << ' ' << a[m - 1] << endl;
    //cout << x << ' ' << y << endl;
    for(int i = 1;i <= n;i ++){
        ans1 = max(ans1, a[i + 1] - a[i]);
        //cout << ans1 << ' ';
    }
    //cout << endl;
    for(int i = 1;i <= m;i ++){
        ans2 = max(ans2, b[i + 1] - b[i]);
       //cout << b[i] << ' ' << ans2 << ' ';
    }
    cout << ans1 * ans2 << endl;
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
int a[N], dis1[N], dis2[N], id1[N], id2[N], n, ans = 0, idx = 1;
int main(){
    cin >> n;
    for(int i = 1;i <= n;i ++)
        cin >> a[i];
    for(int i = n;i >= 1;i --){
        dis1[i] = dis1[i + 1];dis2[i] = dis2[i + 1];
        id1[i] = id1[i - 1];id2[i] = id2[i - 1];
        if(a[i] > dis1[i]){
            dis2[i] = dis1[i];
            id2[i] = id1[i];
            dis1[i] = a[i];
            id1[i] = i; 
        }
        else if(a[i] < dis1[i] && a[i] > dis2[i])
            dis2[i] = a[i];
        cout << dis1[i] << ' ';
    }
    cout << endl;
    for(int i = 1;i <= n;i ++){
        int temp = 0;
        for(int j = 1;j <= n;j ++){
            if(j == i + 1 && a[j] <= a[i - 1] && dis1[j + 1] <= a[j] || a[j] <= a[j - 1] && a[j] >= dis1[j + 1]){
                temp = j;
                break;
            }
            temp = j;
            cout << j << ' ' << dis1[j] << " / ";
        }
        if(ans < temp){
            ans = temp;
            idx = i;
        }
        cout << temp << endl;
    }
    cout << ans << endl;
    return 0;
}*/
/*
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
int a[N], m1[N], m2[N], num1[N], num2[N], dp[N];
int n, idx = 1, ans = 0, s = 0;
int main(){
    cin >> n;
    for(int i = 1;i <= n;i ++){
        cin >> a[i];
        m1[i] = m1[i - 1];
        m2[i] = m2[i - 1];
        num1[i] = num1[i - 1];
        if(s < a[i]){
            dp[i] = dp[i - 1] + 1;
            s = a[i];
        }
        else 
            dp[i] = dp[i - 1];
        if(a[i] > m1[i]){
            m2[i] = m1[i];
            num1[i] = 1;
            m1[i] = a[i];
        }
        else if(a[i] < m1[i] && a[i] > m2[i])
            m2[i] = a[i];
        else if(a[i] == m1[i])
            num1[i] ++;
    }
    for(int i = 1;i <= n;i ++){
        int maxn = m1[i - 1], cnt = 0;
        if(!(a[i] == m1[i] || a[i] == m2[i]))
            continue;
        for(int j = i + 1;j <= n;j ++){
            if(a[j] <= maxn)
                continue;
            else {
                maxn = a[j];
                cnt ++;
            }
        }
        if(cnt + dp[i - 1] > ans){
            idx = i;
            ans = cnt + dp[i - 1];
        }
        //cout << cnt << ' ' << dp[i - 1] << ' ' << m1[i - 1] << " // ";
    }
    cout << idx << endl;
    return 0;
}*/
/*
mixzd
qwgsc
bjynv
kflot
aephr
d b
xqm
*/
/*for(int ii = 1;ii <= n;ii ++){
        int t1 = mp[s[ii]].x, t2 = mp[s[ii]].y;
        for(int i = 1;i <= 5;i ++)
            for(int j = 1;j <= 5;j ++){
                int s1 = dp1[ii][t1][t2], s2 = dp2[ii][t1][t2];
                if(dp1[ii - 1][i][j] != 2e9){
                    if(dp1[ii][t1][t2] > dp1[ii - 1][i][j] + move(i, j, t1, t2)){
                        dp1[ii][t1][t2] = dp1[ii - 1][i][j] + move(i, j, t1, t2);
                        dp2[ii][i][j] = dp2[ii - 1][i][j];
                        ans = min(ans, dp1[ii][t1][t2] + dp2[ii][i][j]);
                    }
                }
                if(dp2[ii - 1][i][j] != 2e9){
                    if(dp2[ii][t1][t2] > dp2[ii - 1][i][j] + move(i, j, t1, t2)){
                        dp2[ii][t1][t2] = dp2[ii - 1][i][j] + move(i, j, t1, t2);
                        dp1[ii][i][j] = dp1[ii - 1][i][j];
                        ans = min(ans, dp2[ii][t1][t2] + dp1[ii][i][j]);
                    }
                }
            }
    }*/
    /*for(int ii = 0;ii <= n;ii ++){
        for(int i = 1;i <= 5;i ++){
            for(int j = 1;j <= 5;j ++){
                cout << dp1[ii][i][j] << ' ';
            }
            cout << "           ";
            for(int j = 1;j <= 5;j ++){
                cout << dp2[ii][i][j] << ' ';
            }
            cout << endl;
        }
        cout << endl;
    }
    for(int i = 1;i <= 5;i ++)
        for(int j = 1;j <= 5;j ++){
            ans = min(ans, dp1[n][i][j]);
            ans = min(ans, dp2[n][i][j]);   
        }
*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e2 + 7;
int a[N], b[N], c[N], n, m, temp, ans = 0;
void dfs(int step, int sum){
    if(step > n){
        ans = max(ans, sum);
        return ;
    }
    for(int i = 1;i <= n;i ++){
        if(c[i])
            continue;
        if(b[i])
            temp = sum * a[i];
        else
            temp = sum + a[i];
        c[i] = 1;
        dfs(step + 1, temp);
        c[i] = 0;
    }
}
int main(){
    cin >> m >> n;
    for(int i = 1;i <= n;i ++){
        cin >> a[i];
        b[i] = 1;
    }
    cin >> temp;
    for(int i = n + 1;i <= n + temp;i ++){
        cin >> a[i];
        b[i] = 0;
    }
    n += temp;
    dfs(1, m);
    cout << ans << endl;
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, t1, t2, t3, t4, t5;
    cin >> n;
    while(n --){
        cin >> t1 >> t2;
        t3 = t1;t4 = t1 + t2;
        int cnt = 0, cnt2 = 0;
        while(t3){
            cnt ++;
            t3 /= 10;
        }
        while(t4){
            cnt2 ++;
            t4 /= 10;
        }
        if(cnt == cnt2)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
void factor(long long sum){
    for(int i = 1;i <= sum;i ++)
        if(sum % i == 0)
            cout << i << ' ';
    cout << endl;
}
int main(){
    long long sum = 3;
    while(sum <= 1e9){
        cout << sum << endl;
        factor(sum);
        sum = sum * 2 + 1;
    }
    cout << endl;
}*/