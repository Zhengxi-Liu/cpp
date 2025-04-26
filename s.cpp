#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 7;
int a[N], b[N], n, cnt = 0;
int s[N], ans = 0;
vector <int> c[N];
int p(int l, int r){
    if(r < l)
        return 0;
    int x = r - l + 1;
    return x * (x + 1) / 2;
}
int main(){
    cin >> n;
    for(int i = 1;i <= n;i ++){
        cin >> a[i];
    }
    for(int i = 1;i <= n;i ++){
        cin >> b[i];
        c[b[i]].push_back(i);
        if(b[i] == a[i]){
            cnt ++;
            int s1 = i, s2 = n - i + 1;
            ans += p(1, i - 1) + p(i + 1, n);
        }
    }
    //ans += cnt * n;
    for(int i = 1;i <= n;i ++){
        for(int j = 0;j < c[a[i]].size();j ++){
            int l = min(c[a[i]][j], i), r = max(c[a[i]][j], i);
            s[i] += min(l, n - r + 1);
            //cout << l << ' ' << r << "/ ";
        }
        //cout << s[i] << endl;
        ans += s[i];
    }
    cout << ans << endl;
    return 0;
}
/*#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
typedef long long LL;
LL a[N], n, m, t;
LL minn(LL x){
    LL cnt = 0;
    for(int i = 1;i <= n;i ++){
        LL temp = abs(a[i] - x);
        cnt += min(max(m, temp) - min(temp, m), temp);
    }
    return cnt;
}
int main(){
    cin >> t;
    while(t --){
        cin >> n >> m;
        LL l = 0, r = 0, cr = 0, cl = 0, ma = -1, mi = 1e10;
        for(int i = 1;i <= n;i ++){
            cin >> a[i];
            a[i] %= m;
            if(a[i] > m - a[i]){
                r += m - a[i];
                cr ++;
            }
            else {
                l += a[i];
                cl ++;
            }
            ma = max(ma, a[i]);
            mi = min(mi, a[i]);
        }
        sort(a + 1, a + n + 1);
        LL ans = 1e9;
        for(int i = 1;i <= n;i ++){
            LL temp;
            if(a[i] < m - a[i])
                temp = a[i];
            else
                temp = -m + a[i];
            LL x = minn(temp);
            if(x < ans)
                ans = x;
        }
        cout << ans << endl;
    }
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 7, M = 1e6 + 7;
int a[N][N], b[M], c[M], vis[M], n;
vector <int> p[M];
int main(){
    cin >> n;
    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= n;j ++){
            cin >> a[i][j];
            c[a[i][j]] ++;
            b[i + j] += 1;
        }
    for(int i = 1;i <= n * 2;i ++)
        p[b[i]].push_back(i);
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= n;j ++){
            if(!vis[a[i][j]]){
                int num = c[a[i][j]];
                for(int k = 0;k < p[num].size();k ++){
                    if(p[num][k] != -1){
                        int t = p[num][k], s = a[i][j];
                        a[i][j] = t;
                        vis[s] = t;
                        p[num][k] = -1;
                        break;
                    }
                }
            }
            else {
                a[i][j] = vis[a[i][j]];
            }
        }
    }
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= n;j ++){
            cout << a[i][j];
            if(j < n)
                cout << ' ';
        }
        cout << endl;
    }
    return 0;
}*/
