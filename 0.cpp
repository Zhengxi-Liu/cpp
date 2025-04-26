#include<bits/stdc++.h>
using namespace std;
const int N = 4e2 + 7;
int dp[N][N], n;
string s;
int main(){
    cin >> s;
    n = s.size();
    s = " " + s;
    memset(dp, 0x3f, sizeof(dp));
    for(int i = 1;i <= n;i ++)
        dp[i][i] = 1;
    for(int len = 2;len <= n;len ++)
        for(int i = 1;i + len - 1 <= n;i ++){
            int j = len + i - 1;
            if(s[i] == s[j])
                dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]);
            for(int k = i;k < j;k ++)
                dp[i][j] = min(dp[i][j], dp[i][k], dp[k + 1][j]);
        }
    cout << dp[1][n] << endl;
    return 0;
}















































