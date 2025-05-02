#include<bits/stdc++.h>
using namespace std;
const int N = 20 + 7;
int dp[N][N], sum[N], a[N], n, m;
int count(int x){
    int cnt = 0, ans;
    while(x){
        a[++ cnt] = x % 10;
        x /= 10;
    }
    ans = sum[cnt - 1];//有 cnt - 1 位的数的数量
    for(int i = 1;i < a[cnt];i ++) //首位比 x 的首位 小的 cnt 位的数
        ans += dp[cnt][i];
    for(int i = cnt - 1;i >= 1;i --){ //首位是 x 的首位 的数
        for(int j = 0;j < a[i];j ++) //枚举当前位的可能
            if(abs(j - a[i + 1]) > 1)
                ans += dp[i][j];
        if(abs(a[i + 1] - a[i]) < 2)
            break;
    }
    return ans;
}
int main(){
    cin >> n >> m;
    for(int i = 0;i < 10;i ++)
        dp[1][i] = 1;
    sum[0] = 1;
    sum[1] = 10;
    for(int i = 2;i <= 15;i ++){
        for(int j = 0;j < 10;j ++)
            for(int k = 0;k < 10;k ++)
                if(abs(j - k) > 1)
                    dp[i][j] += dp[i - 1][k];
        sum[i] = sum[i - 1];
        for(int j = 1;j < 10;j ++)
            sum[i] += dp[i][j];
    }
    cout << count(m + 1) - count(n) << endl;
    return 0;
}