/*
#include<bits/stdc++.h>
using namespace std;
const int N = 5e3 + 7;
int dp[N][N], n, m, x, y, z;
string s, t;
int main(){
    cin >> x >> y >> z >> s >> t;
    n = s.size(); s = " " + s;
    m = t.size(); t = " " + t;
    for(int i = 0;i <= n;i ++)
        dp[i][0] = i * y;
    for(int i = 0;i <= m;i ++)
        dp[0][i] = i * x;
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= m;j ++){
            if(s[i] == t[j])
                dp[i][j] = dp[i - 1][j - 1];
            else {
                dp[i][j] = min(dp[i - 1][j - 1] + z, min(dp[i - 1][j] + y, dp[i][j - 1] + x));
            }
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    }
    cout << dp[n][m] << endl;
    return 0;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
const int N = 5e3 + 7;
int dp[N][N], n, m;
string s, t;
int main(){
    cin >> s >> t;
    n = s.size(); s = " " + s;
    m = t.size(); t = " " + t;
    for(int i = 0;i < N;i ++)
        dp[0][i] = 1;
    for(int i = 1;i <= m;i ++){
        for(int j = 1;j <= n;j ++){
            if(t[i] != s[j])
                dp[i][j] = dp[i][j - 1];
            else {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
            }
            //cout << dp[i][j] << ' ';
        }
        //cout << endl;
    }
    cout << dp[m][n] << endl;
    return 0;
}
*/

#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 7;
int dp[N], n, ans = 0;
string s[N];
bool cmp(string s, string t){
    if(s.size() > t.size())
        return false;
    for(int i = 0;i < s.size();i ++)
        if(s[i] != t[i])
            return false;
    return true;
}
int main(){
    cin >> n;
    for(int i = 1;i <= n;i ++)
        cin >> s[i];
    for(int i = 1;i <= n;i ++){
        for(int j = i - 1;j >= 0;j --)
            if(cmp(s[j], s[i])){
                dp[i] = max(dp[i], dp[j] + 1);
                break;
            }
    }
    for(int i = 1;i <= n;i ++)
        ans = max(ans, dp[i]);
    cout << ans << endl;
    return 0;
}
/*
for(int i = 1;i <= n;i += 2)
i += 2
i = i + 2
i = i * i
i *= i
pow(i, 4) i^4
#include<bits/stdc++.h>
using namespace std;
void sqrt1(double x){
    double l = 0, r = 1e18, temp = 0.0000000001;
    while(l < r){
        double m = (l + r) / 2;
        if(m * m < x)
            l = m;
        else 
            r = m;
        if(m * m - x <= temp && m * m - x >= temp * -1){
            printf("%.6lf\n", m);
            return ;
        }
        if(r - l < temp){
            printf("%.6lf\n", m);
            return ;
        }
    }
}
int main(){
    double x;
    while(cin >> x)
        sqrt1(x);
    return 0;
}*/
/*
HarryPotter is a genius 
listen to HarryPotter
Malfoy is nothing
Ron is one hundred percent definately a very good friend of course
Neville is vey 
shout Neville
Hermione is the best
While Malfoy is less than Ron 
Let Hermione be Ron plus Malfoy 
shout Hermione 
Let Neville be Hermione over 2
if Neville times Neville is Harry Potter
shout Neville
OH
if Neville times Neville is less than Harry Potter
Malfoy is Neville
OH
if Neville times Neville is more than Harry Potter
Ron is Neville
OH
end
*/