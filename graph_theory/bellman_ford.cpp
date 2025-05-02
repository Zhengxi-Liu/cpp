/*#include<bits/stdc++.h>
using namespace std;
const int N = 8e3 + 7, INF = 0x3f3f3f3f;
int l[N], r[N], dis[N], n, m, s, t;
int main(){
    cin >> n >> m;
    for(int i = 1;i <= m;i ++)
        cin >> l[i] >> r[i];
    cin >> s >> t;
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0;
    for(int i = 1;i < n;i ++)
        for(int j = 1;j <= m;j ++){
            if(dis[l[j]] != INF)
                dis[r[j]] = min(dis[r[j]], dis[l[j]] + 1);
            if(dis[r[j]] != INF)
                dis[l[j]] = min(dis[l[j]], dis[r[j]] + 1);
        }
    if(dis[t] == INF)
        dis[t] = -1;
    cout << dis[t] << endl;
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int dis[N], l[N], r[N], v[N], n, m, t;
int main(){
    cin >> t;
    while(t --){
        cin >> n >> m;
        for(int i = 1;i <= m;i ++)
            cin >> l[i] >> r[i] >> v[i];
        bool ans = false;
        for(int i = 1;i <= n;i ++)
            for(int j = 1;j <= m;j ++)
                if(dis[r[j]] > dis[l[j]] + v[j]){
                    dis[r[j]] = dis[l[j]] + v[j];
                    if(i == n)
                        ans = true;
                }
        if(ans == true)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}*/
#include<bits/stdc++.h>
using namespace std;
const int N = 5e3 + 7;
typedef long long LL;
LL dis[N], l[N], r[N], v[N];
int pre[N], ans[N];
int n, m, idx = 0, last;
int main(){
    cin >> n >> m;
    for(int i = 1;i <= m;i ++)
        cin >> l[i] >> r[i] >> v[i];
    memset(pre, -1, sizeof(pre));
    for(int i = 1;i <= n;i ++){
        last = -1;
        for(int j = 1;j <= m;j ++)
            if(dis[r[j]] > dis[l[j]] + v[j]){
                dis[r[j]] = dis[l[j]] + v[j];
                pre[r[j]] = l[j];
                last = r[j];
            }
      }
    if(last == -1){
        cout << "NO" << endl;
        exit(0);
    }
    int x = last, t;
    for(int i = 1;i <= n;i ++)
        x = pre[x];
    t = x;
    while(true){
        ans[++ idx] = t;
        t = pre[t];
        if(t == x){
            ans[++ idx] = t;
            break;
        }
    }
    cout << "YES" << endl;
    for(int i = idx;i >= 1;i --)
        cout << ans[i] << ' ';
    cout << endl;
    return 0;
}