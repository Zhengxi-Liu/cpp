/* 
#include<bits/stdc++.h>
using namespace std;
const int N = 6e2 + 7;
int a[N], dis[N], dp[N][N], n;
int func(int x, int y){
    if(x == y)
        return dp[x][y] = 0;
    if(dp[x][y])
        return dp[x][y];
    int ret = 1e9;
    for(int i = x;i < y;i ++)
        ret = min(ret, func(x, i) + func(i + 1, y));
    return dp[x][y] = dis[y] - dis[x - 1] + ret;
}
int main(){
    cin >> n;
    for(int i = 1;i <= n;i ++){
        cin >> a[i];
        dis[i] = a[i] + dis[i - 1];
    }
    cout << func(1, n) << endl;
    return 0;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 7;
int dp[N][N], a[N], n;
int func(int l, int r){
    if(dp[l][r])
        return dp[l][r];
    int ret = 1e9;
    for(int i = l + 1;i < r;i ++)
        ret = min(ret, func(l, i) + func(i, r) + a[l] * a[i] * a[r]);
    if(ret == 1e9)
        ret = 0;
    return dp[l][r] = ret;
}
int main(){
    cin >> n;
    for(int i = 1;i <= n;i ++)
        cin >> a[i];
    cout << func(1, n) << endl;
    return 0;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
long long a[N], n, s, ans = 0;
priority_queue <int, vector<int>, greater<int> > q;
int main(){
    cin >> s >> n;
    for(int i = 1;i <= n;i ++){
        cin >> a[i];
        q.push(a[i]);
    }
    while(q.size() >= 2){
        int ss = q.top();
        q.pop();
        ss += q.top();
        q.pop();
        ans += ss;
        q.push(ss);
    }
    cout << ans << endl;
    return 0;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
const int N = 6e2 + 7;
int a[N], dis[N], dp[N][N], n;
int func(int x, int y){
    if(x == y)
        return dp[x][y] = 0;
    if(dp[x][y])
        return dp[x][y];
    int ret = 1e9;
    for(int i = x;i < y;i ++)
        ret = min(ret, func(x, i) + func(i + 1, y));
    return dp[x][y] = dis[y] - dis[x - 1] + ret;
}
int main(){
    cin >> n;
    for(int i = 1;i <= n;i ++){
        cin >> a[i];
        dis[i] = a[i] + dis[i - 1];
    }
    for(int i = n + 1;i <= n * 2 - 1;i ++){
        a[i] = a[i - n];
        dis[i] = a[i] + dis[i - 1];
    }
    func(1, n * 2 - 1);
    cout << dp[n][2 * n - 1] << endl;
    return 0;
}
*/