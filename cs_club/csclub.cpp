/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
long long a[N], n, dis[N], ans[N];
bool cmp(int a, int b){
    return a > b;
}
int main(){
    cin >> n;
    for(int i = 1;i <= n;i ++)
        cin >> a[i];
    sort(a + 1, a + n + 1, cmp);
    for(int i = 1;i <= n;i ++)
        dis[i] = dis[i - 1] + a[i]; 
    for(int i = 1;i <= n;i ++)
        ans[i] = ans[i - 1] + dis[i];
    for(int i = 1;i <= n;i ++)
        cout << ans[i] << ' ';
    cout << endl;
    return 0;
}*/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e7 + 7;
typedef long long LL;
LL m, n, dis1[N], dis2[N], d[N], ans = -1e18, temp;
int main(){
    cin >> n;
    for(int i = 1;i <= n;i ++){
        cin >> m;
        for(int j = 1;j <= m;j ++){
            cin >> temp;
            dis1[j] = dis1[j - 1];
            dis2[j] = dis2[j - 1];
            if(!temp)
                dis1[j] += 1;
            else
                dis2[j] += 1;
        }
        d[i] = max(dis1[m], dis2[m]);
        LL maxn = 0;
        for(int j = 1;j <= m + 1;j ++){
            maxn = max(maxn, dis1[j - 1] + dis2[m] - dis2[j - 1]);
            dis1[j - 1] = 0;
            dis2[j - 1] = 0;
        }
        if(maxn - d[i] > ans)
            ans = maxn - d[i];
    }
    for(int i = 1;i <= n;i ++)
            ans += d[i];
    cout << ans << endl;
    return 0;
}