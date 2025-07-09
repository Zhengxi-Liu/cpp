//B. 中位数
/*#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 250007, MOD = 65536;

int a[N], mul, add, n, k, ans;

multiset<int> mx, mn;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> a[1] >> mul >> add >> n >> k;

    for (int i = 2; i <= n; i++) {
        a[i] = (a[i - 1] * mul + add) % MOD;
    }

    for (int i = 1; i <= k; i++) {
        mx.insert(a[i]);
        if (mx.size() > mn.size()) {
            int t = *mx.begin();
            mx.erase(mx.begin());
            mn.insert(t);
        }
        if (!mx.empty() && !mn.empty() && *mx.begin() < *--mn.end()) {
            int t1 = *mx.begin(), t2 = *--mn.end();
            mx.erase(mx.begin());
            mn.erase(--mn.end());
            mx.insert(t2);
            mn.insert(t1);
        }
    }

    if (!mn.empty()) ans += *--mn.end();

    for (int i = k + 1; i <= n; i++) {
        int x = a[i - k];
        auto it = mn.find(x);
        if (it != mn.end()) mn.erase(it);
        else {
            it = mx.find(x);
            if (it != mx.end()) mx.erase(it);
        }

        mx.insert(a[i]);
        if (mx.size() > mn.size()) {
            int t = *mx.begin();
            mx.erase(mx.begin());
            mn.insert(t);
        }
        while (mn.size() > mx.size() + 1) {
            int t = *--mn.end();
            mn.erase(--mn.end());
            mx.insert(t);
        }
        if (!mx.empty() && !mn.empty() && *mx.begin() < *--mn.end()) {
            int t1 = *mx.begin(), t2 = *--mn.end();
            mx.erase(mx.begin());
            mn.erase(--mn.end());
            mx.insert(t2);
            mn.insert(t1);
        }

        if (!mn.empty()) ans += *--mn.end();
    }

    cout << ans << '\n';
    return 0;
}*/

//F. 奶牛后移
/*#include<bits/stdc++.h>
using namespace std;

#define mid ((l + r) >> 1)

const int N = 1e5 + 7;

int a[N], n, cnt = 1;

int sum[N * 4], tag[N * 4];

void push_up(int k){
    sum[k] = sum[k * 2] + sum[k * 2 + 1];
}

void change(int x, int l, int r, int v){
    tag[x] += v;
    sum[x] += (r - l + 1) * v;
}

void push_down(int k, int l, int r){
    if(!tag[k]) return;
    change(k * 2, l, mid, tag[k]);
    change(k * 2 + 1, mid + 1, r, tag[k]);
    tag[k] = 0;
}

void update(int k, int l, int r, int x, int y, int v){
    if(l >= x && r <= y){
        change(k, l, r, v);
        return;
    }
    push_down(k, l, r);
    if(mid >= x) update(k * 2, l, mid, x, y, v);
    if(mid + 1 <= y) update(k * 2 + 1, mid + 1, r, x, y, v);
    push_up(k);
}

int query(int k, int l, int r, int x){
    if(l == x && r == x) return sum[k];
    push_down(k, l, r);
    if(mid >= x) return query(k * 2, l, mid, x);
    return query(k * 2 + 1, mid + 1, r, x);
}

int main(){

    cin >> n;

    for(int i = 1; i <= n; i ++)
        cin >> a[i];
    
    update(1, 1, n, a[n], n, 1);
    
    for(int i = n; i > 1; i --){
        if(a[i] > a[i - 1]){ 
            cnt ++;
            update(1, 1, n, a[i - 1], n, 1);
        }
        else break;
    }

    cout << n - cnt << endl;

    cnt = n - cnt;

    for(int i = 1; i <= cnt; i ++){
        cout << query(1, 1, n, a[i]) + cnt - i << ' ';
        update(1, 1, n, a[i], n, 1);
    }
    cout << endl;

    return 0;
}*/

//G. 找乐子1
/*#include<bits/stdc++.h>
using namespace std;

#define int long long

#define mid ((l + r) >> 1)

const int N = 1e5 + 7, INF = 1e9;

int n, a[N], ans;

int sum[N * 4], tag[N * 4];

void push_up(int k){
    sum[k] = sum[k * 2] + sum[k * 2 + 1];
}

void change(int k, int l, int r, int v){
    sum[k] = (r - l + 1) * v;
    tag[k] = v;
}

void push_down(int k, int l, int r){
    if(!tag[k]) return;
    change(k * 2, l, mid, tag[k]);
    change(k * 2 + 1, mid + 1, r, tag[k]);
    tag[k] = 0;
}

void update(int k, int l, int r, int x, int y, int v){
    if(l >= x && r <= y){
        change(k, l, r, v);
        return;
    }
    push_down(k, l, r);
    if(mid >= x) update(k * 2, l, mid, x, y, v);
    if(mid + 1 <= y) update(k * 2 + 1, mid + 1, r, x, y, v);
    push_up(k);
}

signed main(){

    cin >> n;

    for(int i = 1; i <= n; i ++){
        cin >> a[i];
    }

    stack <int> st;
    a[0] = INF; st.push(0);
    
    for(int i = 1; i <= n; i ++){
        while(!st.empty() && a[st.top()] <= a[i]) st.pop();
        update(1, 1, n, st.top() + 1, i, a[i]);
        ans += sum[1], ans %= INF;
        st.push(i);
    }
    cout << (ans + INF) % INF << endl;
    return 0;
}*/

//J. 找乐子2
/*#include<bits/stdc++.h>
using namespace std;

#define int long long

#define mid ((l + r) >> 1)

const int N = 1e5 + 7, MOD = 1e9;

int n, a[N], r1[N], r2[N], ans;

int sum[N * 4], suma[N * 4], sumb[N * 4], taga[N * 4], tagb[N * 4];

void push_up(int k){
    (sum[k] = sum[k * 2] + sum[k * 2 + 1]) %= MOD;
    (suma[k] = suma[k * 2] + suma[k * 2 + 1]) %= MOD;
    (sumb[k] = sumb[k * 2] + sumb[k * 2 + 1]) %= MOD;
}

void change(int k, int l, int r, int x, int y){
    //if(l == 1 && r == 1) cout << x << ' ' << y << " . " << endl;
    if(x && y){
        taga[k] = x, tagb[k] = y;
        suma[k] = (r - l + 1) * x % MOD;
        sumb[k] = (r - l + 1) * y % MOD;
        sum[k] = (r - l + 1) * x % MOD * y % MOD;
    }
    else if(x){
        taga[k] = x;
        suma[k] = (r - l + 1) * x % MOD;
        sum[k] = x * sumb[k] % MOD;
    }
    else if(y){
        tagb[k] = y;
        sumb[k] = (r - l + 1) * y % MOD;
        sum[k] = y * suma[k] % MOD;
    }
}

void push_down(int k, int l, int r){
    change(k * 2, l, mid, taga[k], tagb[k]);
    change(k * 2 + 1, mid + 1, r, taga[k], tagb[k]);
    taga[k] = tagb[k] = 0;
}

void upd(int k, int l, int r, int x, int y, int v1, int v2){
    if(l >= x && r <= y){
        change(k, l, r, v1, v2);
        return;
    }
    push_down(k, l, r);
    if(mid >= x) upd(k * 2, l, mid, x, y, v1, v2);
    if(mid + 1 <= y) upd(k * 2 + 1, mid + 1, r, x, y, v1, v2);
    push_up(k);
}

signed main(){

    cin >> n;

    for(int i = 1; i <= n; i ++){
        cin >> a[i];
    }

    stack <int> st1, st2;
    a[0] = MOD; 
    st1.push(0), st2.push(0);
    
    for(int i = 1; i <= n; i ++){
        while(!st1.empty() && a[st1.top()] <= a[i]) st1.pop();
        r1[i] = st1.top() + 1;
        st1.push(i);
    }
    a[0] = -1;
    for(int i = 1; i <= n; i ++){
        while(!st2.empty() && a[st2.top()] >= a[i]) st2.pop();
        r2[i] = st2.top() + 1;
        st2.push(i);
    }
    for(int i = 1; i <= n; i ++) {
        upd(1, 1, n, r1[i], i, a[i], 0);
        upd(1, 1, n, r2[i], i, 0, a[i]);
        ans += sum[1], ans %= MOD;
        //cout << r1[i] << ' ' << r2[i] << " / ";
        //cout << suma[1] << ' ' << sumb[1] << endl;
    }

    cout << (ans + MOD) % MOD << endl;
    return 0;
}*/

//J. 找乐子3
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define mid ((l + r) >> 1)

const int N = 5e5 + 7, MOD = 1e9;

struct Tree{
    struct node{
        int sum, sma, smb, tga, tgb, wei;
        void tag(int x, int y){
            if(x){
                tga = x; sma = wei * x % MOD;
                sum = x * smb % MOD;
            }
            if(y){
                tgb = y; smb = wei * y % MOD;
                sum = y * sma % MOD;
            }
        }
    }tree[N << 2];

    void push_up(int k){
        (tree[k].sum = tree[k << 1].sum + tree[(k << 1) + 1].sum) %= MOD;
        (tree[k].sma = tree[k << 1].sma + tree[(k << 1) + 1].sma) %= MOD;
        (tree[k].smb = tree[k << 1].smb + tree[(k << 1) + 1].smb) %= MOD;
        tree[k].wei = tree[k << 1].wei + tree[(k << 1) + 1].wei;
    }

    void push_down(int k){
        int &a = tree[k].tga, &b = tree[k].tgb;
        if(a || b){
            tree[k << 1].tag(a, b);
            tree[(k << 1) + 1].tag(a, b);
        }
        a = b = 0;
    }

    void build(int k, int l, int r, int op){
        tree[k].sum = tree[k].sma = tree[k].smb = tree[k].tga = tree[k].tgb = 0;
        //if(k == 1) cout << "___";
        if(l == r) {
            tree[k].wei = op ? l : 1; 
            //cout << l << ' ' << tree[k].wei << " * ";
            return;
        }
        build(k << 1, l, mid, op);
        build((k << 1) + 1, mid + 1, r, op);
        push_up(k);
        //cout << l << ' ' << r << ' ' << tree[k].wei << " * ";
    }

    void update(int k, int l, int r, int x, int y, int sa, int sb){
        if(l >= x && r <= y) {
            tree[k].tag(sa, sb);
            return;
        }
        push_down(k);
        if(mid >= x) update(k << 1, l, mid, x, y, sa, sb);
        if(mid + 1 <= y) update((k << 1) + 1, mid + 1, r, x, y, sa, sb);
        push_up(k);
    }

}T[2];

int n, a[N], L[N], R[N], ans;

stack <int> st1, st2;

signed main(){

    cin >> n;

    for(int i = 1; i <= n; i ++)
        cin >> a[i];

    a[0] = MOD;
    st1.push(0);

    for(int i = 1; i <= n; i ++){
        while(!st1.empty() && a[st1.top()] <= a[i]) st1.pop();
        L[i] = st1.top() + 1;
        st1.push(i);
    }

    a[0] = -1;
    st2.push(0);

    for(int i = 1; i <= n; i ++){
        while(!st2.empty() && a[st2.top()] >= a[i]) st2.pop();
        R[i] = st2.top() + 1;
        st2.push(i);
    }

    T[0].build(1, 1, n, 0);
    //cout << endl;
    T[1].build(1, 1, n, 1);
    //cout << endl;
    

    for(int i = 1; i <= n; i ++){
        T[0].update(1, 1, n, L[i], i, a[i], 0);
        T[0].update(1, 1, n, R[i], i, 0, a[i]);
        T[1].update(1, 1, n, L[i], i, a[i], 0);
        T[1].update(1, 1, n, R[i], i, 0, a[i]);
        //cout << L[i] << ' ' << R[i] << " / " << T[0].tree[1].sma << ' ' << T[0].tree[1].smb << " / ";
        //cout << (T[0].tree[1].sum * (i + 1)) << ' ' << T[1].tree[1].sum << endl;
        (ans += (T[0].tree[1].sum * (i + 1)) - T[1].tree[1].sum) %= MOD;
    }

    cout << ans << endl;

    return 0;
}