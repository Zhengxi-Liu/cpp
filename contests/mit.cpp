/*#include<bits/stdc++.h>
using namespace std;
const int N = 10 + 7;
long long dis[N], n, t;
int main(){
    cin >> n;
    dis[0] = 1;
    for(int i = 1;i < N - 1;i ++)
        dis[i] = dis[i - 1] * 5;
    dis[N - 1] = 1e18;
    dis[0] = 0;
    while(n --){
        cin >> t;
        long long ans = 0;
        for(int i = 1;i < N;i ++){
            if(t > dis[i - 1] && t <= dis[i]){
                ans = i;
                break;
            }
        }
        if(ans == 1)
            cout << "MIT time" << endl;
        else 
            cout << "MIT^" << ans << " time" << endl;
    }
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
typedef long long LL;
LL a[N], n, t;
int main(){
    cin >> t;
    while(t --){
        cin >> n;
        LL t1, t2;
        for(int i = 1;i <= n;i ++){
            cin >> t1 >> t2;
            a[i] = t1 + t2;
        }
        sort(a + 1, a + n + 1);
        LL ans = 0;
        a[n + 1] = a[1];
        for(int i = 2;i <= n + 1;i ++){
            ans += abs(a[i] - a[i - 1]);
        }
        cout << ans << endl;
    }
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 7;
int dp[N][N], ma, n;
string s, t;
string re(string x){
    if(x == "AAB")
        return "BAA";
    if(x == "BAA")
        return "AAB";
    if(x == "BBA")
        return "ABB";
    if(x == "BBA")
        return "ABB";
    return "Z";
}
int main(){
    cin >> ma;
    while(ma --){
        memset(dp, 0,sizeof(dp));
        cin >> s >> t;
        n = s.size();
        s = " " + s;
        t = " " + t;
        int c1 = 0, c2 = 0, i1 = 0, i2 = 0;
        for(int i = 1;i <= n;i ++){
            //string temp = s[i - 2] + s[i - 1] + s[i], t2 = t[i - 2] + t[i - 1] + t[i];
            if(s[i] == 'B')
                i1 = i;
            if(t[i] == 'B')
                i2 = i;
            if(s[i] == 'B')
                c1 ++;
            if(t[i] == 'B')
                c2 ++;
        }
        if(c1 != c2){
            cout << "-1" << endl;
            continue;
        }
        int x = abs(i1 - i2);
        if(x % 2 != 0){
            cout << "-1" << endl;
            continue;
        }
        cout << x / 2 << endl;
    }
    return 0;
}*/
