#include<bits/stdc++.h>
using namespace std;
const int N = 25, M = 100 + 7;
int a[N], b[M], n, m, maxn = (1 << N) - 1;
int dp[(1 << N) + 7], f[(1 << N) + 7];
int main(){
    cin >> n >> m;
    for(int i = 1;i <= n;i ++)
        cin >> a[i];
    for(int j = 1;j <= m;j ++)
        cin >> b[j];
    sort(b + 1, b + m + 1, greater <int>());
    for(int i = 1;i <= maxn;i ++)
        dp[i] = m + 1;
    for(int i = 0;i <= maxn;i ++)
        for(int j = 1;j <= n;j ++)
            if(i & (1 << (j - 1))){
                int op = i ^ (1 << (j - 1));
                if(dp2[op] >= a[j]){
                    
                }
                if()
            }
    return 0;
}