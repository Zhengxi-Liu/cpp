#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
bool f[N];
int primes[N], k = 0, n;
int main(){
    cin >> n;
    f[0] = f[1] = true;
    for(int i = 2;i <= n;i ++){
        if(f[i])
            continue;
        primes[++ k] = i;
        for(int j = 2;j * i <= n;j ++)
            f[i * j] = true;
    }
    cout << k << endl;
    return 0;
}