//F. 黄金矿工
/*#include<bits/stdc++.h>
using namespace std;

#define up(i, n) for(int i = 1; i <= n; i ++)

const int N = 50 + 7;

int dp[N][N][N], a[N], b[N];

int n, m, k, ans;

int main() {

    cin >> n >> m >> k;
    
    n ++, m ++;

    up(i, k) cin >> a[i], a[i] ++;

    cin >> k;

    up(i, k) cin >> b[i], b[i] ++;

    up(i, k) up(x, k) up(y, k) {
        up(c, k)
            dp[i][x][y] = max(dp[i][x][y], dp[i - 1][c][y] + n + m - abs(a[x] - a[i]) - abs(b[y] - b[i]) - 2);
        up(d, k)
            dp[i][x][y] = max(dp[i][x][y], dp[i - 1][x][d] + n + m - abs(a[x] - a[i]) - abs(b[y] - b[i]) - 2);
    }

    up(x, k) up(y, k)
        ans = max(ans, dp[k][x][y]);

    cout << ans << endl;

    return 0;
}*/

//G. 012逆序对
/*#include<bits/stdc++.h>
using namespace std;

#define int long long
#define mid ((l + r) >> 1)

const int N = 1e5 + 7;

struct Tree{

    int cnt[3], res[3][3], tag[3]; // res[right][left]

    void prep(){
        for(int i = 0; i < 3; i ++) tag[i] = i;
    }

    void change(int a[3]){

        int cnt2[3], res2[3][3], tag2[3];
        memcpy(cnt2, cnt, sizeof(cnt));
        memcpy(res2, res, sizeof(res));
        memcpy(tag2, tag, sizeof(tag));
        memset(cnt, 0, sizeof(cnt));
        memset(res, 0, sizeof(res));

        for(int i = 0; i < 3; i ++) cnt[a[i]] += cnt2[i];
        
        for(int i = 0; i < 3; i ++)
            for(int j = 0; j < 3; j ++) 
                res[a[i]][a[j]] += res2[i][j];

        for(int i = 0; i < 3; i ++) tag[i] = a[tag2[i]];

    }

}T[N << 2];

int a[N], n, q, op, x, y, s, t, u;

void push_up(int k){

    for(int i = 0; i < 3; i ++) 
        T[k].cnt[i] = T[k << 1].cnt[i] + T[(k << 1) | 1].cnt[i];
    
    for(int i = 0; i < 3; i ++) 
        for(int j = 0; j < 3; j ++) 
            T[k].res[i][j] = T[k << 1].res[i][j] + T[(k << 1) | 1].res[i][j] + T[(k << 1) | 1].cnt[i] * T[k << 1].cnt[j];

}


void build(int k, int l, int r){
    T[k].prep();
    if(l == r){
        T[k].cnt[a[l]] = 1;
        return;
    }
    build(k << 1, l, mid);
    build((k << 1) | 1, mid + 1, r);
    push_up(k);
}

void push_down(int k){
    T[k << 1].change(T[k].tag);
    T[(k << 1) | 1].change(T[k].tag);
    T[k].tag[0] = 0;
    T[k].tag[1] = 1;
    T[k].tag[2] = 2;
}

void update(int k, int l, int r, int x, int y, int a[3]){
    if(l >= x && r <= y){
        T[k].change(a);
        return;
    }
    push_down(k);
    if(mid >= x) update(k << 1, l, mid, x, y, a);
    if(mid + 1 <= y) update((k << 1) | 1, mid + 1, r, x, y, a);
    push_up(k);
}

Tree query(int k, int l, int r, int x, int y){
    if(l >= x && r <= y)
        return T[k];
    push_down(k);
    int res = 0;
    if(mid >= x && mid + 1 <= y){
        Tree t1 = query(k << 1, l, mid, x, y), t2 = query((k << 1) | 1, mid + 1, r, x, y), res;
        for(int i = 0; i < 3; i ++) res.cnt[i] = t1.cnt[i] + t2.cnt[i];
        for(int i = 0; i < 3; i ++)
            for(int j = 0; j < 3; j ++) res.res[i][j] = t1.res[i][j] + t2.res[i][j] + t1.cnt[j] * t2.cnt[i];
        return res;
    }
    else if(mid >= x) return query(k << 1, l, mid, x, y);
    else if(mid + 1 <= y) return query((k << 1) | 1, mid + 1, r, x, y);
}

signed main(){

    cin >> n >> q;

    for(int i = 1; i <= n; i ++) cin >> a[i];

    build(1, 1, n);

    while(q --){ 

        cin >> op >> x >> y;

        if(op == 1){
            Tree tmp = query(1, 1, n, x, y);
            cout << tmp.res[0][2] + tmp.res[0][1] + tmp.res[1][2] << endl;
        }

        else {
            cin >> s >> t >> u;
            int b[3] = {s, t, u};
            update(1, 1, n, x, y, b);
        }

    }

    return 0;
}*/

