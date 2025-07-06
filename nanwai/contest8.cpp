//A. 超级酷数
/*#include<bits/stdc++.h>
using namespace std;

const int N = 10 + 7;

int dgt[N], n, ans, cnt;

bool check(int x){
    if(x < 100) return true;
    cnt = 0;
    while(x){
        dgt[++ cnt] = x % 10;
        x /= 10;
    }
    for(int i = 2; i < cnt; i ++)
        if(dgt[i] - dgt[i - 1] != dgt[i + 1] - dgt[i]) return false;
    return true;
}

int main(){

    cin >> n;

    for(int i = 1; i <= n; i ++)
        if(check(i)) ans ++;

    cout << ans << endl;

    return 0;
}*/

//B. 食物中毒
/*#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e6 + 7;

int dp[N][2], n, x, y;

signed main(){

    cin >> n;

    for(int i = 1; i <= n; i ++){
        cin >> x >> y;
        if(!x){
            dp[i][0] = max(max(dp[i - 1][0], dp[i - 1][1]) + y, dp[i - 1][0]);
            dp[i][1] = dp[i - 1][1];
        }
        else {
            dp[i][1] = max(dp[i - 1][0] + y, dp[i - 1][1]);
            dp[i][0] = dp[i - 1][0];
        }
        //cout << dp[i][0] << ' ' << dp[i][1] << " / / ";
    }

    cout << max(dp[n][0], dp[n][1]) << endl;

    return 0;
}*/

//C. 笑脸符号
/*#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;

int dp[N], n;

int main(){

    cin >> n;

    memset(dp, 0x3f, sizeof(dp));

    dp[1] = 0;

    for(int i = 1; i < N; i ++){
        for(int j = i + 1; j < N; j ++)
            dp[i] = min(dp[i], dp[j] + j - i);
        for(int j = i + i; j < N; j += i)
            dp[j] = min(dp[j], dp[i] + (j - i) / i + 1);
    }

    cout << dp[n] << endl;

    return 0;
}*/

//D. LCM的GCD
/*#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e5 + 7;

int mn1[N], mn2[N], c[N];

int fct[N], pw[N];

int a[N], n, cnt, ans = 1;

bool prime[N];

void prm(){
    prime[1] = true;
    for(int i = 2; i < N; i ++){
        if(prime[i]) continue;
        for(int j = i + i; j < N; j += i) prime[j] = true;
    }
}

void upd(int x){

    cnt = 0;

    for(int i = 2; i * i <= x; i ++){
        if(!prime[i] && x % i == 0){ fct[++ cnt] = i; pw[cnt] = 0; }
        while(!prime[i] && x % i == 0){
            pw[cnt] ++;
            x /= i;
        }
    }

    if(x != 1) fct[++ cnt] = x, pw[cnt] = 1;

    for(int i = 1; i <= cnt; i ++){
        x = fct[i];
        c[x] ++;
        if(mn1[x] >= pw[i]){
            mn2[x] = mn1[x];
            mn1[x] = pw[i];
        }
        else if(pw[i] > mn1[x] && pw[i] < mn2[x])
            mn2[x] = pw[i];
    }

}

signed main(){

    cin >> n;

    for(int i = 1; i <= n; i ++) cin >> a[i];

    prm();

    memset(mn1, 0x3f, sizeof(mn1));
    memset(mn2, 0x3f, sizeof(mn2));

    for(int i = 1; i <= n; i ++) upd(a[i]);

    for(int i = 2; i < N; i ++){
        if(c[i] == n){
            ans *= pow(i, mn2[i]);
        }
        else if(c[i] == n - 1){
            ans *= pow(i, mn1[i]);
        }
    }

    cout << ans << endl;

    return 0;
}*/

//E. 打包正方体
/*#include<bits/stdc++.h>
using namespace std;

#define int long long

int n, m, l, x;

signed main(){

    cin >> n >> m >> l;

    x = l * l;

    int ans = m * x * l + (n - 1) / x * x + x;

    for(int i = l; i * i * i <= ans; i ++){
        for(int j = i; i * j * j <= ans; j ++){
            int p = (i / l) * (j / l);
            int h = (m - 1) / p * l + l;
            int lft = i * j * h - m * x * l - n;
            if(lft >= 0){ 
                ans = min(ans, i * j * h);
                //cout << "1: " << i << ' ' << j << ' ' << h << endl;
            }
            else {
                //cout << h << ' ' << lft << " // ";
                h = h + (-1 - lft) / (i * j) + 1;
                //cout << "2: " << i << ' ' << j << ' ' << h << endl;
                ans = min(ans, i * j * h);
            }
        }
    }
    cout << ans << endl;

    return 0;
}*/

//F. 建造警察局
/*#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

int dfn[N], low[N], clk;
int id[N], mn[N], cnt;
stack <int> st;
bool f[N];

int in[N], mk[N];
vector <int> a[N];
pair <int, int> s[N];

int n, nm, sum; char c; double avg;

void tarjan(int x){

    dfn[x] = low[x] = ++ clk;
    st.push(x);
    f[x] = true;

    for(int to : a[x]){
        if(!dfn[to]){
            tarjan(to);
            low[x] = min(low[x], low[to]);
        }
        else if(f[to]) low[x] = min(low[x], dfn[to]);
    }

    if(dfn[x] == low[x]){
        int tp;
        cnt ++;
        do {
            tp = st.top();
            st.pop();
            f[tp] = false;
            id[tp] = cnt;
            if(s[mn[cnt]].first > s[tp].first) mn[cnt] = tp;
        } while(x != tp);
    }

}

int main(){

    cin >> n;

    s[0].first = INT_MAX;
    for(int i = 1; i <= n; i ++){
        cin >> s[i].first;
        s[i].second = i;
    }

    cin >> n;

    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++){
            cin >> c;
            if(c == 'Y') a[i].push_back(j);
        }

    for(int i = 1; i <= n; i ++)
        if(!dfn[i]) tarjan(i);

    for(int i = 1; i <= n; i ++)
        for(int to : a[i]) if(id[i] != id[to]) in[id[to]] ++;

    for(int i = 1; i <= cnt; i ++)
        if(!in[i]) nm ++, sum += s[mn[i]].first, mk[mn[i]] = 1;
    
    avg = 1.0 * sum / nm;

    sort(s + 1, s + n + 1);

    for(int i = 1; i <= n; i ++){
        if(mk[s[i].second]) continue;
        if(1.0 * (sum + s[i].first) / (nm + 1) >= avg) break;
        sum += s[i].first, nm ++, avg = 1.0 * sum / nm;
    }

    printf("%.10lf\n", avg);

    return 0;
}*/

