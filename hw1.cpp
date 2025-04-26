/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
int a[N], b[N], dp[N];
int k, n, m, x;
int main(){
    cin >> n >> m;
    for(int i = 1;i <= n;i ++){
        cin >> a[++ k] >> b[k] >> x;
        int power = 1, sum = 1, t1 = a[k], t2 = b[k];
        while(sum + power * 2 <= x){
            power *= 2;
            sum += power;
            a[++ k] = t1 * power;
            b[k] = t2 * power;
        }
        if(sum < x){
            a[++ k] = (x - sum) * t1;
            b[k] = (x - sum) * t2;
        }
    }
    //cout << endl;
    for(int i = 1;i <= k;i ++){
        //cout << a[i] << ' ' << b[i] << endl;
        for(int j = m;j >= b[i];j --)
            dp[j] = max(dp[j], dp[j - b[i]] + a[i]);
    }
    cout << dp[m] << endl;
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 7;
long long dp[N], n, m, x, y;
int main(){
    scanf("%lld %lld", &m, &n);
    for(int i = 1;i <= n;i ++){
        scanf("%lld %lld", &x, &y);
        for(int j = m;j >= x;j --)
            dp[j] = max(dp[j], dp[j - x] + y);
    }
    printf("%lld\n", dp[m]);
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 2e3 + 7;
string s, t;
int dp[N][N], n, m;
int main(){
    cin >> t >> s;
    n = s.size(); s = " " + s;
    m = t.size(); t = " " + t;
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    for(int i = 1;i <= n;i ++)
        dp[i][0] = i;
    for(int j = 1;j <= m;j ++)
        dp[0][j] = j;
    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= m;j ++){
            int add = 1;
            if(s[i] == t[j])
                add = 0;
            dp[i][j] = min(min(dp[i - 1][j] + 1, dp[i][j - 1] + 1), dp[i - 1][j - 1] + add);
        }
    cout << dp[n][m] << endl;
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7, M = 1e3 + 7;
int a[N], b[N], dp[N], n, t;
map <int, int> mp;
int main(){
	cin >> n;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
		mp[a[i]] = i;
	}
	for(int i = 1;i <= n;i ++){
		cin >> b[i];
		dp[i] = 1e9;
	}
	int ans = 0;
	dp[0] = 0;
	for(int i = 1;i <= n;i ++){
		if(mp[b[i]] > dp[ans])
			dp[++ ans] = mp[b[i]];
		else {
			int l = 0, r = ans + 1;
			while(l < r){
				int mid = (l + r) / 2;
				if(dp[mid] > mp[b[i]])
					r = mid;
				else
					l = mid + 1;
			}
			dp[l] = min(mp[b[i]], dp[l]);
		}
	}
	cout << ans << endl;
	return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 5e3 + 7;
int a[N], dp[N], n, ans;
int main(){
    cin >> n;
    for(int i = 1;i <= n;i ++){
        cin >> a[i];
        dp[i] = 1;
        for(int j = 1;j < i;j ++)
            if(a[j] < a[i])
                dp[i] = max(dp[i], dp[j] + 1);
    }
    for(int i = 1;i <= n;i ++)
        ans = max(ans, dp[i]);
    cout << ans << endl;
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 5e3 + 7, M = 1e4 + 7;
struct str{
    int x, y, op;
}a[N];
int dp[N][N], dp2[M];
int n, m, k;
int main(){
    cin >> n >> m >> k;
    for(int i = 1;i <= n;i ++){
        cin >> a[i].x >> a[i].y;
        a[i].op = 0;
    }
    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= k;j ++)
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + a[i].y);
    int sum = k;
    for(int i = n;i >= 1;i --)
        if(dp[i][sum] != dp[i - 1][sum]){
            sum -= 1;
            cout << i << ' ';
            a[i].op = 1;
        }
    cout << dp[n][k] << endl;
    for(int i = 1;i <= n;i ++){
        if(a[i].op)
            continue;
        for(int j = m;j >= a[i].x;j --)
            dp2[j] = max(dp2[j], dp2[j - a[i].x] + a[i].y);
    }
    cout << dp[n][k] + dp2[m] << endl;
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e2 + 7;
int dp[N][N][N], a[N], n, x, t;
int main(){
    cin >> t;
    while(t --){
        cin >> n >> x;
        for(int i = 1;i <= n;i ++)
            cin >> a[i];
        memset(dp, 0x3f, sizeof(dp));
        for(int i = 1;i <= n;i ++)
            for(int k = 1;k <= x;k ++){
                if(a[i] == k)
                    dp[i][i][k] = 0;
                else
                    dp[i][i][k] = 1;
            }
        for(int len = 2;len <= n;len ++){
            for(int i = 1;i + len - 1 <= n;i ++){
                int j = len + i - 1;
                for(int k = i;k <= j;k ++){
                    for(int tar = 1;tar <= x;tar ++){
                        dp[i][j][tar] = min(dp[i][k][])
                    }
                }
            }
        }
    }
    return 0;
}*/
#include<bits/stdc++.h>
using namespace std;
const int N = 3e2 + 7;
int dp[N][N], a[N], dis[N], n;
int main(){
    cin >> n;
    for(int i = 1;i <= n;i ++)
        cin >> a[i];
    memset(dp, 0x3f, sizeof(dp));
    for(int i = 1;i <= n;i ++){
        dp[i][i] = 0;
        dis[i] = dis[i - 1] + a[i];
    }
    for(int len = 2;len <= n;len ++)
        for(int i = 1;i + len - 1 <= n;i ++){
            int j = i + len - 1;
            for(int k = i;k < j;k ++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + dis[j] - dis[i - 1]);
        }
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= n;j ++){
            if(dp[i][j] == 0x3f3f3f3f)
                dp[i][j] = -1;
            //cout << dp[i][j] << ' ';
        }
        //cout << endl;
    }
    cout << dp[1][n] << endl;
    return 0;
}