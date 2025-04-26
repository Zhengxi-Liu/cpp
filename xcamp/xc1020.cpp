/*#include<bits/stdc++.h>
using namespace std;
string s, t;
const int N = 1e3 + 7;
int dp[N][N], n, m;
int main(){
    cin >> s >> t;
    n = s.size();
    m = t.size();
    s = " " + s;
    t = " " + t;
    for(int i = 1;i <= m;i ++){
        for(int j = 1;j <= n;j ++){
            int temp = dp[i - 1][j - 1];
            if(s[j] == t[i])
                temp ++;
            dp[i][j] = max(temp, max(dp[i - 1][j], dp[i][j - 1]));
            //cout << dp[i][j] << ' ';
        }
        //cout << endl;
    }
    cout << dp[m][n] << endl;
    return 0;
}*/
/*
    x j o i x j o i
j   0 1 1 1 1 2 2 2 
o   0 1 4 6 8 11 16 20 
y   0 1 6 16 30 49 76 112 
j   0 2 9 31 77 157 282 470 
o   0 2 14 54 162 396 836 1588 
y   0 2 18 86 302 860 2092 4516 
*/
/*
#include<bits/stdc++.h>
using namespace std;
string s, t, st;
const int N = 1e3 + 7;
int dp[N][N], n1, n2, n3;
int main(){
    cin >> s >> t >> st;
    n1 = s.size();s = " " + s;
    n2 = t.size();t = " " + t;
    n3 = st.size();st = " " + st;
    if(n1 + n2 != n3){
        cout << "no" << endl;
        exit(0);
    }
    if(s[1] == st[1])
        dp[1][0] = 1;
    if(t[1] == st[1])
        dp[0][1] = 1;
    for(int i = 0;i <= n1;i ++){
        for(int j = 0;j <= n2;j ++){
            int temp = i + j;
            //if(dp[i - 1][j] == i - 1 + j && t[j] == st[i - 1 + j])
              //  dp[i][j] = i + j;
            //else if(dp[i][j - 1] == i + j - 1 && s[i] == st[i + j - 1])
              //  dp[i][j] = i + j;
            if(dp[i][j]){
                if(s[i + 1] == st[temp + 1])
                    dp[i + 1][j] = temp + 1;
                if(t[j + 1] == st[temp + 1])
                    dp[i][j + 1] = temp + 1;
            }
            //cout << dp[i][j] << ' ';
        }
        //cout << endl;
    }
    if(dp[n1][n2] == n3)
        cout << "yes" << endl;
    else
        cout << "no" << endl;
    //cout << dp[n1][n2] << endl;
    return 0;                
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 7;
int dp[N][N], n, m;
string s, t;
int main(){
    cin >> s >> t;
    n = s.size(); s = " " + s;
    m = t.size(); t = " " + t;
    //for(int i = 0;i <= n;i ++)
      //  dp[i][0] = 1;
    //for(int i = 0;i <= m;i ++)
      //  dp[0][i] = 1;
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    if(s[1] == '*'){
        for(int i = 1;i <= n;i ++)
            dp[i][0] = 1;
    }
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= m;j ++){
            int temp = dp[i - 1][j - 1];
            if(t[j] == '?')
                dp[i][j] = dp[i - 1][j - 1];
            else if(t[j] == '*')
                dp[i][j] = max(temp, max(dp[i][j - 1], dp[i - 1][j]));
            else 
                if(t[j] == s[i])
                    dp[i][j] = temp;
            //cout << dp[i][j] << ' ';
        }
        //cout << endl;
    }
    if(dp[n][m])
        cout << "yes" << endl;
    else    
        cout << "no" << endl;
    return 0;
}
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 7;
int dp[N][N], n, m, s[N], t[N], ans = 0;
int main(){
    cin >> n >> m;
    for(int i = 1;i <= n;i ++)
        cin >> s[i];
    for(int i = 1;i <= m;i ++)
        cin >> t[i];
    for(int i = 1;i <= m;i ++){
        for(int j = 1;j <= n;j ++){
            int temp = dp[i - 1][j - 1];
            if(s[j] == t[i])
                dp[i][j] = temp + 1;
            //dp[i][j] = max(temp, max(dp[i - 1][j], dp[i][j - 1]));
            cout << dp[i][j] << ' ';
            ans = max(ans, dp[i][j]);
        }
        cout << endl;
    }
    cout << ans << endl;
    return 0;
}