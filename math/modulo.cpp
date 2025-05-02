//https://www.luogu.com.cn/problem/P3811

#include<bits/stdc++.h>
using namespace std;
// #define int long long
const int N = 3e6 + 7;
int n, p, inv[N];
signed main(){
    cin >> n >> p;
    inv[1] = 1, cout << 1 << endl;
    for(int i = 2;i <= n;i ++)
        inv[i] = 1ll * (p - p / i) * inv[p % i] % p, printf("%lld\n", 1ll * inv[i]);
    return 0;
}