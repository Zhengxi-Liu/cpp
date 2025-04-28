/*#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 7;
typedef long long LL;
LL cnt[N], n, m, f, y, x;
LL lowbit(LL x){
    return x & -x;
}
void insert(LL x, LL y){
    for(int i = x;i <= n;i += lowbit(i))
        cnt[i] += y;
}
LL query(LL x){
    int ret = 0;
    for(int i = x;i > 0;i -= lowbit(i))
        ret += cnt[i];
    return ret;
}
int main(){
    cin >> n >> m;
    for(int i = 1;i <= n;i ++){
        cin >> x;
        insert(i, x);
    }
    while(m --){
        cin >> f >> x >> y;
        if(f == 1)
            insert(x, y);
        else
            cout << query(y) - query(x - 1) << endl;
    }
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
int l[N], r[N], n, m;
int lowbit(int x){
    return x & -x;
}
void add(int x, int y, int c[]){
    for(int i = x;i <= n;i += lowbit(i))
        c[i] += y;
}
int query(int x, int c[]){
    int ret = 0;
    for(int i = x;i > 0;i -= lowbit(i))
        ret += c[i];
    return ret;
}
int main(){
    cin >> n >> m;
    while(m --){
        int k, ll, rr;
        cin >> k >> ll >> rr;
        if(k == 1){
            add(ll, 1, l);
            add(rr, 1, r);
        }
        else
            cout << query(rr, l) - query(ll - 1, r) << endl;
    }
    return 0;
}*/
// #include<bits/stdc++.h>
// using namespace std;
// const int N = 5e5 + 7;
// typedef long long LL;
// LL sum[N * 4], n, m, a[N];
// LL lowbit(LL x){
//     return x & -x;
// }
// void update(int x, LL v){
//     for(int i = x;i <= n;i += lowbit(i))
//         sum[i] += v;
// }
// LL query(int x){
//     LL res = 0;
//     for(int i = x;i > 0;i -= lowbit(i))
//         res += sum[i];
//     return res;
// }
// int main(){
//     cin >> n >> m;
//     for(int i = 1;i <= n;i ++){
//         cin >> a[i];
//     }
//     while(m --){
//         int t, x, y, d;
//         cin >> t;
//         if(t == 1){
//             cin >> x >> y >> d;
//             update(x, d);
//             update(y + 1, -d);
//         }
//         else {
//             cin >> x;
//             cout << a[x] + query(x) << endl;
//         }
//     }
//     return 0;
// }
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 7;
int cnt[N], a[N], b[N], n, m, ans;
int lowbit(int x){
    return x & -x;
}
int sum(int x){
    int res = 0;
    for(int i = x;i > 0;i -= lowbit(i))
        res += cnt[i];
    return res;
}
void add(int x, int y){
    for(int i = x;i <= m;i += lowbit(i))
        cnt[i] += y;
}
signed main(){
    cin >> n;
    for(int i = 1;i <= n;i ++){
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b + 1, b + n + 1);
    m = unique(b + 1, b + n + 1) - b - 1;
    for(int i = n;i >= 1;i --){
        /*
        每次找到比他小并且在他前面的.
        b: 1 2 3 4 5 6
        a: 1 3 6 2 4 5
                                        ||
                                        \/
        第一次,找1,比1小的应在b数组里1的前面 (1, 2, 3, 4, 5, 6)
        在a数组里在他前面的应已被标记, 所以找到 (比1小[在b数组] && 已被标记过[在a数组]) 的数量
        */
        int k = lower_bound(b + 1, b + m + 1, a[i]) - b;
        ans += sum(k - 1);//找所有比自己小并且出现(在a数组)在自己前面的(应已被标记)
        add(k, 1);//标记以后所有的,只要比他大,就能用
    }
    cout << ans << endl;
    return 0;
}