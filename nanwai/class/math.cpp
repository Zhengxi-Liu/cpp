//A. B进制数与B-1倍数查询问题
/*#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e6 + 7;

int a[N], dis[N], n, q, sum;

signed main(){

    cin >> n >> q;

    for(int i = 0; i < n; i ++)
        cin >> a[i], sum += a[i] * i;
        
    int tmp = sum % (n - 1);
    if(tmp) a[tmp] --;

    for(int i = 0; i < n; i ++)
        dis[i] = dis[max(0ll, i - 1)] + a[i];

    dis[n] = LLONG_MAX;

    while(q --){

        cin >> sum;

        if(dis[1] == dis[0] && n == 2){
            if(!sum) cout << 0 << endl;
            else cout << -1 << endl;
            break;
        }

        int k = lower_bound(dis, dis + n + 1, sum + 1) - dis;

        if(k == n) k = -1;

        cout << k << endl;

    }

    return 0;
}*/

//B. 放入糖果


