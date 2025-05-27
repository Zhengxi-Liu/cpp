/*#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;

bool f[N], p[N];

int prime[N], n, t, l, r, k;

int main(){

    cin >> t;

    while(t --){

        scanf("%d %d", &l, &r);

        memset(f, 0, sizeof(f));
        memset(p, 0, sizeof(p));
        k = 0;

        n = ceil(sqrt(r));

        f[1] = true;

        for(int i = 2; i <= n; i ++){
            if(f[i])
                continue;
            prime[++ k] = i;
            for(int j = i * 2; j <= n; j += i)
                f[j] = true;
        }

        for(int i = 1; i <= k; i ++){
            int tmp = prime[i];
            //cout << tmp << " / ";
            for(int j = ceil(1.0 * l / tmp) * tmp; j <= r; j += tmp){
                if(j == tmp)
                    continue;
                //cout << j << ' ';
                p[j - l] = true;
            }
            //cout << endl;
        }
        for(int i = 0; i <= r - l; i ++)
            if(!p[i])
                printf("%d\n", l + i);
    }

    return 0;
}*/

/*#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;

bool f[N];

int prime[N], mx[N];

int n, k, ans = INT_MAX;

void calculate(int x){
    for(int i = 1; i < x; i ++){
        int new_n = n - i;
        //cout << new_n << ' ' << mx[new_n] << endl;
        if(mx[new_n] != new_n)
            ans = min(ans, new_n - mx[new_n] + 1);
    }
}

int main(){

    cin >> n;

    f[1] = true;
    for(int i = 2; i <= n; i ++){
        if(!f[i])
            prime[++ k] = i, mx[i] = i;
        for(int j = 1; j <= k && i * prime[j] <= n; j ++){
            f[i * prime[j]] = true;
            mx[i * prime[j]] = max(mx[i], mx[prime[j]]);
            if(i % prime[j] == 0)
                break;
        }
    }
    for(int i = 2; i * i <= n; i ++)
        if(n % i == 0){
            if(!f[i])
                calculate(i);
            if(!f[n / i])
                calculate(n / i);
        }
    if(ans == INT_MAX)
        ans = -1;
    cout << ans << endl;
    return 0;
}*/

// #include<bits/stdc++.h>
// using namespace std;

// const int N = 1e5 + 7;

// bool f[N];

// int prime[N];

// int n, k;

// int main(){

//     f[1] = true;
//     for(int i = 2; i < N; i ++){
//         if(f[i])
//             continue;
//         prime[++ k] = i;
//         for(int j = i * 2; j < N; j += i)
//             f[i] = true;
//     }

//     while(cin >> n){

//         if(cin.fail())
//             break;

//     }

//     return 0;
// }

/*#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 5e3, MOD = (1ll << 32);

int dis[N + 7], a[N + 7], cnt[N + 7];

int n, ans;

signed main(){

    cin >> n;

    for(int i = 1; i <= n; i ++){
        cin >> a[i];
        cnt[a[i]] ++;
    }
    
    sort(a + 1, a + n + 1, greater <int>());
    
    for(int i = 1; i <= n; i ++){ //枚举 b
        for(int j = 1; j <= N; j ++){ //处理所有 
            dis[j] = dis[j - 1];
            if(cnt[j])
                dis[j] += j / a[i];
        }
        for(int j = i + 1; j <= n; j ++){
            int tmp = 0;
            for(int k = 1; k <= N / a[j]; k ++)
                tmp += (dis[max(min(a[j] * (k + 1) - 1, N), a[i])] - dis[max(a[j] * k - 1, a[i])]) * k, tmp %= MOD;
            ans += tmp * (a[i] / a[j]), ans %= MOD;
        }
    }
    cout << ans << endl;

    return 0;
}*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e7 + 7;

bool f[N];

int prime[N], phi[N];

int n, t, k;

ll qpow(ll base, ll power, ll mod){
    ll res = 1;
    while(power){
        if(power & 1) 
            res = res * base % mod;
        base = base * base % mod;
        power >>= 1;
    }
    return res;
}

ll solve(ll m){
    if(m == 1)
        return 0;
    return qpow(2, phi[m] + solve(phi[m]), m);
}

int main(){
    f[1] = true;
    for(int i = 2; i < N; i ++){
        if(!f[i])
            prime[++ k] = i, phi[i] = i - 1;
        for(int j = 1; j <= k && i * prime[j] < N; j ++){
            f[i * prime[j]] = true;
            phi[i * prime[j]] = phi[i] * phi[prime[j]];
            if(i % prime[j] == 0){
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            }
        }
    }
    // for(int i = 1; i <= 20; i ++)
    //     cout << phi[i] << ' ';
    // cout << endl;
    cin >> t;
    while(t --){
        cin >> n;
        cout << solve(n) << endl;
    }
    return 0;
}