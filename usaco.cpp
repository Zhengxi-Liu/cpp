/*#include<iostream>
using namespace std;
const int N = 2e5 + 7;
long long a[N], b[N], dis[N], n, m;
int main(){
    cin >> n >> m;
    for(int i = 1;i <= n;i ++){
        cin >> a[i];
        dis[i] = max(a[i], dis[i - 1]);
    }
    for(int i = 1;i <= m;i ++){
        cin >> b[i];
        long long l = 1;
        for(int j = 1;j <= n;j ++){
            if(a[j] >= l){
                long long t = a[j];
                a[j] += min(a[j] - l + 1, b[i] - l + 1);
                l = t + 1;
                if(l > b[i])
                    break;
            }
            //cout << l << '/';
        }
        //cout << endl;
    }
    for(int i = 1;i <= n;i ++)
        cout << a[i] << endl;
    return 0;
}*/
/*#include<iostream>
using namespace std;
const int N = 3e5 + 7;
long long a[N], b[N], idx = 0, n, minn = 1e9, ans = 0;
string s;
int main(){
    cin >> n;
    cin >> s;
    s = "0" + s;
    s += "0";
    for(int i = 1;i <= n;i ++){
        if(s[i] == '1' && s[i - 1] == '0')
            a[++ idx] = i;
        if(s[i] == '1' && s[i + 1] == '0'){
            b[idx] = i;
        }
    }
    for(int i = 1;i <= idx;i ++){
        if(a[i] == 1)
            minn = min(minn, b[i] * 2 - 1);
        else if(b[i] == n)
            minn = min(minn, (n - a[i]) * 2 + 1);
        else
            minn = min(minn, b[i] - a[i] + 1);
        //cout << "/" << minn << ' ' << i << " // ";
        //cout << b[i] << endl;
        //cout << minn << ' ';
    }
    //cout << minn << endl;
    if(minn % 2 == 0)
        minn -= 1;
    for(int i = 1;i <= idx;i ++){
        int t = 0, s = b[i] - a[i] + 1;
        if(s % minn != 0)
            t = 1;
        ans += s / minn + t;
        //cout << ans << ' ';
        //cout << a[i] << ' ' << b[i] << endl;
    }
    cout << ans << endl;
}*/
/*#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2e5 + 7;
LL a[N], b[N], c[N], d[N], d2[N], d3[N], n, t;
int main(){
    cin >> t;
    while(t --){
        cin >> n;
        for(int i = 1;i <= n;i ++)
            cin >> a[i];
        for(int i = 1;i <= n;i ++)
            cin >> b[i];
        for(int i = 1;i <= n;i ++){
            cin >> c[i];
            d[c[i] + 1] = a[i];
            d2[c[i] + 1] = b[i];
        }
        LL ans = 0, minn = 1e18;
        d[0] = 1e18;
        for(int i = 1;i <= n;i ++){
            //cout << d[i] << ' ' << d2[i] << endl;
            if(d[i - 1] <= d[i] && d2[i - 1] <= d2[i]){
                ans = -1;
                break;
            }
            else if(d[i - 1] <= d[i]){
                ans = max(ans, (d[i] - d[i - 1]) / (d2[i - 1] - d2[i]) + 1);
            }
            if(d[i - 1] > d[i] && d2[i - 1] < d2[i]){
                minn = min(minn, (d[i - 1] - d[i]) / (d2[i] - d2[i - 1]) + 1);
            }
        }
        if(minn <= ans)
            cout << "-1" << endl;
        else
            cout << ans << endl;
    }
    return 0;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
typedef long long LL;
struct str{
    LL x, y;
}s[N];
LL a[N], b[N], n, m, k, maxn = 0, cnt = 0;// a = weight, b = num
bool cmp(str a, str b){
    return a.x > b.x;
}
int main(){
    cin >> n >> m >> k;
    for(int i = 1;i <= n;i ++){
        cin >> s[i].x >> s[i].y;
        cnt += a[i].y;
    }
    sort(s + 1, s + n + 1, cmp);
    for(int i = 1;i <= n;i ++){
        a[i] = s[i].x;
        b[i] = s[i].y;
    }
    while(1){
        LL idx = 0, minn = 1e18;
        while(idx <= n){
            LL t = lower_bound(a + 1, a + n + 1, a[idx] + k * 2) - a;
        }
    }
    return 0;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
int n, m, k;
struct str{
    int x, y;
}a[N];
bool cmp(str a, str b){
    return a.x < b.x;
}
int main(){
    cin >> n >> m >> k;
    for(int i = 1;i <= n;i ++)
        cin >> a[i].x >> a[i].y;
    sort(a + 1, a + n + 1, cmp);

    return 0;
}
*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
int a[N], b[N], c[N], d[N], e[N], f1[N], f2[N], n, k, ans = 0;
int main(){
    cin >> n >> k;
    for(int i = 1;i <= k;i ++){
        cin >> a[i];
        e[a[i]] = i;
        c[a[i]] ++;
    }
    for(int i = 1;i <= k;i ++){
        cin >> b[i];
        c[b[i]] ++;
    }
    for(int i = 1;i <= n;i ++)
        if(!c[i])
            ans ++;
    for(int i = 1;i <= n;i ++){
        int t = e[b[i]];
        if(!t)
            continue;
        if(t == i)
            f1[0] ++;
        if(t > i){
            f1[t - i] ++;
            f2[i + k - t] ++;
        }
        if(t < i){
            f2[i - t] ++;
            f1[t + k - i] ++;
        }
    }
    int maxn = 0;
    for(int i = 0;i <= n;i ++){
        maxn = max(maxn, f1[i]);
        maxn = max(maxn, f2[i]);
    }
    memset(f1, 0, sizeof(f1));
    memset(f2, 0, sizeof(f2));
    for(int i = 1;i <= k;i ++)
        d[i] = b[k - i + 1];
    for(int i = 1;i <= n;i ++){
        int t = e[d[i]];
        if(!t)
            continue;
        if(t == i)
            f1[0] ++;
        if(t > i){
            f1[t - i] ++;
            f2[i + k - t] ++;
        }
        if(t < i){
            f2[i - t] ++;
            f1[t + k - i] ++;
        }
    }
    for(int i = 0;i <= n;i ++){
        maxn = max(maxn, f1[i]);
        maxn = max(maxn, f2[i]);
    }
    cout << maxn + ans << endl;
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
int a[N], p[N], d1[N], d2[N];
int n, k, s = 0;
char c[N];
map <int, int> mp;
int main(){
    cin >> n >> k;
    for(int i = 1;i <= n;i ++){
        cin >> a[i];
        mp[a[i]] = 1;
    }
    p[0] = 0;
    for(int i = 1;i <= k;i ++){
        cin >> c[i];
        d1[i] = d1[i - 1];
        d2[i] = d2[i - 1];
        if(c[i] == 'L')
            p[i] = p[i - 1] - 1;
        else if(c[i] == 'R')
            p[i] = p[i - 1] + 1;
        else{
            p[i] = p[i - 1];
            if(mp.count(a[i])){
                mp.erase(a[i]);
                s ++;
            }
        }
        d1[i] = s;
    }
    for(int i = 1;i <= n;i ++)
        mp[a[i]] = 1;
    for(int i = 1;i <= k;i ++){
        int temp = p[i - 1];
        int s1, s2;
        if(c[i] == 'L')
            s1 = -1;
        else if(c[i] == 'R')
            s1 = 1;
        else
            s1 = 0;
        //s2 = s1 + 1;// L(-1) to L: 0; R(1) to L: -2; F(0) to L: -1
        for(int j = i + 1;j <= k;j ++){
            
        }
    }
    cout << s << endl;
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
int a[N], b[N], c[N], n;
int main(){
    cin >> n;
    for(int i = 1;i <= n;i ++)
        cin >> a[i];
    for(int i = 1;i < n;i ++)
        cin >> b[i] >> c[i];
    1 - 2
    1 - 3
    3 - 4
    3 - 5
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 7;
int n, m, idx = 0;
struct str{
    int l, r;
}a[N], b[N];
bool cmp(str a, str b){
    return a.l < b.l;
}
int main(){
    cin >> m >> n;
    m += 1;
    for(int i = 1;i <= n;i ++)
        cin >> a[i].l >> a[i].r;
    sort(a + 1, a + n + 1, cmp);
    b[++ idx].l = a[1].l;
    b[idx].r = a[1].r;
    for(int i = 2;i <= n;i ++){
        if(a[i].l > b[idx].r){
            b[++ idx].l = a[i].l;
            b[idx].r = a[i].r;
        }
        if(a[i].r > b[idx].r){
            b[idx].r = a[i].r;
        }
    }
    for(int i = 1;i <= idx;i ++){
        m -= (b[i].r - b[i].l + 1);
    }
    cout << m << endl;
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
int a[N], b[N], maxn[N], cnt[N], id[N], ans[N];
int n, t, idx;
void prep(){
    idx = 0;
    memset(maxn, 0, sizeof(maxn));
    memset(cnt, 0, sizeof(cnt));
    memset(id, 0, sizeof(id));
    memset(ans, 0, sizeof(ans));
    memset(a, 0, sizeof(a));
}
int main(){
    cin >> t;
    while(t --){
        cin >> n;
        prep();
        for(int i = 1;i <= n;i ++){
            cin >> a[i];
            b[i] = a[i];
        }
        for(int i = n;i >= 1;i --)
            maxn[i] = max(maxn[i + 1], a[i]);
        sort(b + 1, b + n + 1, greater <int>());
        int i1 = 0, i2 = 0;
        for(int i = 1;i <= n;i ++)
            if(a[i] != b[i]){
                i1 = i;
                break;
            }
        if(i1){
            for(int i = n;i >= 1;i --)
                if(a[i] == maxn[i1 + 1]){
                    i2 = i;
                    break;
                }
            int i3 = 0;
            for(int i = 1;i <= n;i ++){
                if(i == i1){
                    b[++ i3] = a[i2];
                    b[++ i3] = a[i1];
                }
                else if(i == i2)
                    continue;
                else
                    b[++ i3] = a[i];
            }
        }
        // for(int i = 1;i <= n;i ++)
        //     cout << b[i] << ' ';
        // cout << endl;
        // cout << i1 << ' ' << i2 << endl;
        memset(maxn, 0, sizeof(maxn));
        for(int i = n;i >= 1;i --){
            maxn[i] = max(maxn[i + 1], b[i]);
            cnt[b[i]] ++;
            id[b[i]] = max(id[b[i]], i);
        }
        for(int i = 1;i <= n;){
            // if(b[i] == maxn[i]){
            //     ans[++ idx] = b[i];
            //     cnt[b[i]] --;
            // }
            // else {
            //     for(int j = 1;j <= cnt[maxn[i]];j ++)
            //         ans[++ idx] = maxn[i];
            //     cnt[maxn[i]] = 0;
            //     i = id[maxn[i]];
            // }
            // i ++;
            int ii = 0, x = 0;
            for(int j = i;j <= n;j ++)
                if(b[j] && b[j] > ii)
                    ii = b[j];
            for(int j = i;j <= n;j ++)
                if(b[j] && b[j] == ii){
                    ans[++ idx] = b[j];
                    x = j;
                    b[j] = 0;
                }
            i = x + 1;
        }
        for(int i = 1;i <= idx;i ++){
            cout << ans[i];
            if(i < idx)
                cout << ' ';
        }
        cout << endl;
    }
    return 0;
}*/
#include <bits/stdc++.h>
using namespace std;

template <class T> using V = vector<T>;
#define all(x) begin(x), end(x)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, A, B;
    cin >> N >> A >> B;

    map<int, int> cnt;
    while (N--) {
        int n, id;
        cin >> n >> id;
        cnt[id] = n;
    }
    map<int, set<int>> adj;
    vector<int> cands;
    for (auto [id, _] : cnt) {
        cands.push_back(id);
        adj[id] = {};
        for (int s : {A, B})
            if (cnt.count(s - id)) adj[id].insert(s - id);
    }
    int64_t ans = 0;
    while (!cands.empty()) {
        int x = cands.back();
        cands.pop_back();
        if (adj.at(x).size() != 1) continue;
        int y = *begin(adj.at(x));
        if (x == y) {
            ans += cnt.at(x) / 2;
        } else {
            int pairs = min(cnt.at(x), cnt.at(y));
            ans += pairs;
            cnt.at(y) -= pairs;
        }
        // note: cnt[x] is no longer used in any future steps,
        // so its value doesn't matter
        adj.at(x).erase(y);
        adj.at(y).erase(x);
        cands.push_back(y);
    }
    // sanity check: no edges remaining
    for (const auto &[id, s] : adj) assert(s.empty());
    cout << ans << "\n";
}
