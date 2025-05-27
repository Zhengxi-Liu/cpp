//高斯消元的模版
/*#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;

long double a[N][N];

int n, m, cur = 1;

int main(){

    cin >> n >> m;

    for(int i = 1; i <= m; i ++)
        for(int j = 1; j <= n + 1; j ++)
            cin >> a[i][j];
    
    for(int i = 1; i <= n; i ++){
        int id = cur;
        for(int j = cur; j <= m; j ++)
            id = (abs(a[j][i]) > abs(a[id][i])) ? j : id;
        if(abs(a[id][i]) > 1e-10) swap(a[cur], a[id]);
        else continue;
        long double d = a[cur][i];
        for(int j = 1; j <= n + 1; j ++)
            a[cur][j] /= d;
        for(int j = 1; j <= m; j ++){
            d = a[j][i];
            if(cur != j)
                for(int k = i; k <= n + 1; k ++) a[j][k] -= d * a[cur][k];
        }
        cur ++;
    }

    for(int i = cur; i <= m; i ++)
        if(abs(a[i][n + 1]) > 1e-10){
            cout << "No solutions" << endl;
            return 0;
        }
    
    if(cur <= n){
        cout << "Many solutions" << endl;
        return 0;
    }

    for(int i = 1; i <= n; i ++)
        cout << a[i][n + 1] << endl;

    return 0;
}*/

//P4035 [JSOI2008] 球形空间产生器
//https://www.luogu.com.cn/problem/P4035
/*#include<bits/stdc++.h>
using namespace std;

const int N = 10 + 7;

double a[N][N], b[N][N];

int n;

int main(){

    cin >> n;

    for(int i = 1; i <= n + 1; i ++)
        for(int j = 1; j <= n; j ++)
            cin >> b[i][j];
    
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++)
            a[i][j] = 2.0 * (b[i][j] - b[i + 1][j]), a[i][n + 1] += (b[i][j] * b[i][j] - b[i + 1][j] * b[i + 1][j]);

    for(int i = 1; i <= n; i ++){
        int id = i;
        for(int j = i; j <= n; j ++)
            id = (abs(a[j][i]) > abs(a[id][i])) ? j : id;
        swap(a[id], a[i]);
        double d = a[i][i];
        for(int j = 1; j <= n + 1; j ++)
            a[i][j] /= d;
        for(int j = 1; j <= n; j ++){
            d = a[j][i];
            if(i == j) continue;
            for(int k = 1; k <= n + 1; k ++)
                a[j][k] -= d * a[i][k];
        }
    }

    for(int i = 1; i <= n; i ++)
        printf("%.3lf ", a[i][n + 1]);
    cout << endl;
    return 0;
}*/

//P3390 【模板】矩阵快速幂
//https://www.luogu.com.cn/problem/P3390
/*#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e2 + 7, MOD = 1e9 + 7;

struct matrix{
    int a[N][N];
    matrix() { memset(a, 0, sizeof(a)); }
}A, res;

int n, k;

matrix operator * (matrix &x, matrix &y){
    matrix t;
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++)
            for(int k = 1; k <= n; k ++)
                t.a[i][j] += x.a[i][k] * y.a[k][j], t.a[i][j] %= MOD;
    return t;
}

void qpow(){
    for(int i = 1; i <= n; i ++)
        res.a[i][i] = 1;
    while(k){
        if(k & 1)
            res = res * A;
        A = A * A;
        k >>= 1;
    }
}

signed main(){

    cin >> n >> k;

    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++)
            cin >> A.a[i][j];
    qpow();
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++)
            cout << res.a[i][j] << ' ';
        cout << endl;
    }
    return 0;
}*/

//P1962 斐波那契数列
//https://www.luogu.com.cn/problem/P1962
/*#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 3 + 7, MOD = 1e9 + 7;

struct matrix{
    int a[N][N];
    matrix() { memset(a, 0, sizeof(a)); }
}A, res;

int n = 2, k;

matrix operator * (matrix &x, matrix &y){
    matrix t;
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++)
            for(int k = 1; k <= n; k ++)
                t.a[i][j] += x.a[i][k] * y.a[k][j], t.a[i][j] %= MOD;
    return t;
}

void qpow(){
    res.a[1][1] = 1, res.a[1][2] = 1;
    while(k){
        if(k & 1)
            res = res * A;
        A = A * A;
        k >>= 1;
    }
}

signed main(){

    cin >> k;

    if(k == 1 || k == 2){
        cout << 1 << endl;
        return 0;
    }
        
    k -= 2;

    A.a[1][1] = 1, A.a[1][2] = 1, A.a[2][1] = 1;

    qpow();

    cout << res.a[1][1] << endl;

    return 0;
}*/

//E. 完全平方数
/*#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 500 + 7;

int prime[N], f[N], a[N][N];

int n, k, T, x;

void init(){
    f[1] = true;
    for(int i = 2; i <= n; i ++){
        if(!f[i])
            prime[++ k] = i;
        for(int j = 1; j <= k && i * prime[j] <= n; j ++){
            f[i * prime[j]] = true;
            if(i % prime[j] == 0)
                break;
        }
    }
}

int gauss(int n, int m){
    int res = 1;
    for(int i = 1; i <= n; i ++){
        int id = res;
        for(int j = id; j <= m; j ++)
            if(a[j][i]) id = j;
        if(!a[id][i]) continue;
        swap(a[id], a[res]);
        for(int j = 1; j <= m; j ++)
            if(j != res && a[j][i])
                for(int k = 1; k <= n + 1; k ++)
                    a[j][k] ^= a[res][k];
        res ++;
    }
    return n - res + 1;
}

signed main(){

    n = 500; init();
    
    cin >> T;

    while(T --){

        memset(a, 0, sizeof(a));

        cin >> n;

        for(int i = 1; i <= n; i ++){
            cin >> x;
            for(int j = 1; j <= k; j ++){
                int s = 0;
                while(x % prime[j] == 0) x /= prime[j], s ++;
                if(s & 1) a[j][i] = 1;
            }
        }
        int ans = 1, t = gauss(n, k);
        while(t --)
            ans *= 2;
        cout << ans - 1 << endl;
    }
    
    return 0;
}*/

