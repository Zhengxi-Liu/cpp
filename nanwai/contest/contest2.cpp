//C. 美丑字符串
/*#include<bits/stdc++.h>
using namespace std;

const int N = 50 + 7;

string s;

bool dp[N][6][4][2];

int n;

bool change(char c){
    return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

int main(){

    cin >> s;

    n = s.size(); s = " " + s;

    dp[0][0][0][0] = 1;

    for(int i = 0; i < n; i ++) //第几个字符
        for(int j = 0; j <= 5; j ++) //前面辅音的数量
            for(int k = 0; k <= 3; k ++) //前面元音的数量
                for(int t = 0; t <= 1; t ++){ //是否为 ugly, 0为 nice, 1为 ugly
                    if(!dp[i][j][k][t])
                        continue;
                    if(s[i + 1] == '?'){
                        dp[i + 1][0][min(k + 1, 3)][t || k == 2] = 1;
                        dp[i + 1][min(j + 1, 5)][0][t || j == 4] = 1;
                    }
                    else if(change(s[i + 1]))
                        dp[i + 1][0][min(k + 1, 3)][t || k == 2] = 1;
                    else 
                        dp[i + 1][min(j + 1, 5)][0][t || j == 4] = 1;
                }

    bool nice = 0, ugly = 0;
    for(int i = 0; i <= 5; i ++)
        for(int j = 0; j <= 3; j ++){
            nice |= dp[n][i][j][0];
            ugly |= dp[n][i][j][1];
        }
    if(nice && !ugly)
        cout << "NICE" << endl;
    else if(nice && ugly)
        cout << 42 << endl;
    else
        cout << "UGLY" << endl;
    return 0;
}*/

//D. 极大不相交区间集
/*#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;

struct str{
    int l, r;
}a[N];

bool cmp(str x, str y){
    return x.r < y.r;
}

int dp[N], n;

int main(){

    cin >> n;

    for(int i = 1; i <= n; i ++)
        cin >> a[i].l;

    cin >> n;

    for(int i = 1; i <= n; i ++)
        cin >> a[i].r;
    
    sort(a + 1, a + n + 1, cmp);

    a[++ n] = {101, 101};

    dp[0] = 1;

    for(int i = 1; i <= n; i ++){

        int maxl = 0;

        for(int j = i - 1; j >= 0; j --){
            if(a[j].r >= a[i].l)
                continue;
            maxl = max(maxl, a[j].l);
        }

        for(int j = i - 1; j >= 0; j --)
            if(a[j].r < a[i].l && a[j].r >= maxl)
                dp[i] += dp[j];
    }

    cout << dp[n] << endl;

    return 0;
}*/

//https://www.youtube.com/watch?v=tqhtkG6glug