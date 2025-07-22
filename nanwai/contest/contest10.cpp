//A. 偷吃苹果
/*#include<bits/stdc++.h>
using namespace std;

const int N = 2e2 + 7;

int n, l, sum, mn = 1e9;

int main(){

    cin >> n >> l;

    for(int i = 1; i <= n; i ++){
        sum += l + i - 1;
        if(abs(l + mn - 1) > l + i - 1)
            mn = i;
    }

    cout << sum - (l + mn - 1) << endl;


    return 0;
}*/

//B. 不要WR
/*#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;

char c[N];

int n, sum[N], ans;

queue <int> q;

int main(){

    cin >> n;

    for(int i = 1; i <= n; i ++){
        cin >> c[i];
        if(c[i] == 'W') q.push(i);
    }
    
    for(int i = n; i >= 1; i --){
        if(q.empty()) break;
        if(c[i] == 'R'){
            if(q.front() > i) break;
            ans ++;
            q.pop();
        }
    }
    cout << ans << endl;
    return 0;
}*/

//C. 拳打墙
/*#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;

struct str{
    int l, r;
}a[N];

bool cmp(str a, str b){
    if(a.r != b.r) return a.r < b.r;
    return a.l < b.l;
}

int n, d, ans;

int main(){

    cin >> n >> d;

    for(int i = 1; i <= n; i ++){
        cin >> a[i].l >> a[i].r;
    }

    sort(a + 1, a + n + 1, cmp);

    for(int i = 1; i <= n; i ++){
        int x = a[i].r;
        while(a[i + 1].l <= x + d - 1 && i + 1 <= n)
            i ++;
        ans ++;
    }
    cout << ans << endl;

    return 0;
}*/

//E. 循环左移逆序对
/*#include<bits/stdc++.h>
using namespace std;

#define int long long

#define mid ((l + r) >> 1)

const int N = 3e5 + 7;

int n, a[N], ans;

int sum[N << 2];

void push_up(int k){
    sum[k] = sum[k << 1] + sum[(k << 1) + 1];
}

void upd(int k, int l, int r, int x){
    if(l == x && r == x){
        sum[k] += 1;
        return;
    }
    if(mid >= x) upd(k << 1, l, mid, x);
    else upd((k << 1) + 1, mid + 1, r, x);
    push_up(k);
}

int query(int k, int l, int r, int x, int y){
    if(l >= x && r <= y) return sum[k];
    int res = 0;
    if(mid >= x) res += query(k << 1, l, mid, x, y);
    if(mid + 1 <= y) res += query((k << 1) + 1, mid + 1, r, x, y);
    return res;
}

signed main(){

    cin >> n;

    for(int i = 1; i <= n; i ++){
        cin >> a[i];
        a[i] += 1;
        ans += query(1, 1, n, a[i], n);
        upd(1, 1, n, a[i]);
    }

    for(int i = 1; i <= n; i ++){
        cout << ans << endl;
        ans = ans - (a[i] - 1) + (n - a[i]);
    }

    return 0;
}*/

//F. 三个字符串
/*#include<bits/stdc++.h>
using namespace std;

#define up(i, n) for(int i = 1; i <= n; i ++)
#define up2(i, n) for(int i = n; i >= 1; i --)
#define upr(i, b, n) for(int i = b; i <= n; i ++)

const int N = 50 + 7;

int n[4], f1[N][N], f2[N][N], nxt1[N], nxt2[N], ans;

string s[4], t;


int main(){

    for(int i = 1; i <= 3; i ++){
        cin >> n[i];
        s[i] = " ";
        while(n[i] --){
            cin >> t;
            s[i] += t;
        }
        n[i] = s[i].size() - 1;
    }

    up(i, n[1]) up(j, n[2]) {
        if(s[1][i] == s[2][j]) f1[i][j] = f1[i - 1][j - 1] + 1;
        f1[i][j] = max({f1[i - 1][j], f1[i][j - 1], f1[i][j]});
    }

    up2(i, n[1]) up2(j, n[2]) {
        if(s[1][i] == s[2][j]) f2[i][j] = f2[i + 1][j + 1] + 1;
        f2[i][j] = max({f2[i + 1][j], f2[i][j + 1], f2[i][j]});
    }

    up(i, n[1]) {
        int cnt = 0;
        upr(j, i, n[1]){
            if(s[1][j] == s[3][cnt + 1]) cnt ++;
            if(cnt == n[3]){
                nxt1[i] = j;
                break;
            }
        }
    }

    up(i, n[2]) {
        int cnt = 0;
        upr(j, i, n[2]){
            if(s[2][j] == s[3][cnt + 1]) cnt ++;
            if(cnt == n[3]){
                nxt2[i] = j;
                break;
            }
        }
    }

    up(i, n[1]) up(j, n[2]){ 
        if(!nxt1[i] || !nxt2[j]) break;
        ans = max(ans, f1[i - 1][j - 1] + f2[nxt1[i] + 1][nxt2[j] + 1] + n[3]);
    }
    cout << ans << endl;

    return 0;
}*/

