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

