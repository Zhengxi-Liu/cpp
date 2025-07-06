//A. 持久度
/*#include<bits/stdc++.h>
using namespace std;

int n, cnt;

int chg(int x){
    int res = 1;
    while(x){
        res *= (x % 10);
        x /= 10;
    }
    return res;
}

int main(){

    cin >> n;

    while(n / 10 != 0){
        n = chg(n);
        cnt ++;
    }

    cout << cnt << endl;

    return 0;
}*/

//B. 8的倍数
/*#include<bits/stdc++.h>
using namespace std;

#define YES { cout << "Yes" << endl; exit(0); }
#define NO { cout << "No" << endl; exit(0); }

const int N = 10 + 7;

int n, a[N], b[N];

string s;

int main(){

    cin >> s;

    n = s.size();
    s = " " + s;

    for(int i = 1; i <= n; i ++){
        a[s[i] - '0'] ++;
    }

    if(n == 2){
        int x = (s[1] - '0') * 10 + s[2], y = (s[2] - '0') * 10 + s[1];
        if(x % 8 == 0 || y % 8 == 0) YES
        NO
    }
    if(n == 1){
        if(s[1] == '8') YES
        NO
    }
    for(int i = 104; i < 1000; i += 8){
        b[i / 100] ++, b[(i / 10) % 10] ++, b[i % 10] ++;
        int flg = 0;
        for(int j = 0; j <= 9; j ++) {
            if(a[j] < b[j]) flg = 1;
            b[j] = 0;
        }
        if(!flg) YES
    }

    NO

    return 0;
}*/

//C. 除法游戏
/*#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 7;

int prime[N], d[N], cnt, ans;

long long n;

bool f[N];

int cal(int x){
    if(x == 1) return 1;
    int sum = 0, res = 0;
    for(int i = 1; i <= x; i ++){
        sum += i, res ++;
        if(sum > x) break;
    }
    return res - 1;
}

int main(){

    cin >> n;

    f[1] = true;
    for(int i = 2; i < N; i ++){
        if(!f[i]) prime[++ cnt] = i;
        for(int j = 1; j <= cnt && prime[j] * i < N; j ++){
            f[prime[j] * i] = true;
            if(i % prime[j] == 0) break;
        }
    }


    for(long long i = 1; i * i <= n; i ++){
        int flg = 0;
        while(!f[i] && n % i == 0){
            n /= i;
            flg ++;
        }
        if(flg) ans += cal(flg);
    }
    if(n != 1) ans ++;
    cout << ans << endl;

    return 0;
}*/

