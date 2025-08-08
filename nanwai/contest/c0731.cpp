//A. 炸弹
/*#include<bits/stdc++.h>
using namespace std;

bool f;

int n, k, ans, lst = 1;

int main(){

    cin >> n >> k;

    for(int i = 1; i <= n; i ++){
        cin >> f;
        if(f){
            ans += max(i - lst - 1, 0) / k;
            lst = i;
        }
    }
    cout << ans << endl;

    return 0;
}*/

//B. 传宝石
/*#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e5 + 7;

typedef pair <int, int> PI;

priority_queue < PI, vector <PI>, greater <PI> > q;

int nxt[N], n, ans[N], x;

bool f[N];


signed main(){

    cin >> n;

    for(int i = 1; i <= n; i ++)
        cin >> nxt[i];

    for(int i = 1; i <= n; i ++){
        cin >> x;
        q.push({x, i});
    }

    while(!q.empty()){

        int val = q.top().first, pos = q.top().second;
        q.pop();

        if(f[pos]) continue;
        f[pos] = 1;
        ans[pos] = val;

        int tmp = (pos == n ? 1 : pos + 1);
        if(f[tmp]) continue;
        q.push({val + nxt[pos], tmp});

    }

    for(int i = 1; i <= n; i ++)
        cout << ans[i] << endl;

    return 0;
}*/

//C. 最小正方形
/*#include<bits/stdc++.h>
using namespace std;

#define int long long
#define mid ((l + r) >> 1)

const int N = 1e2 + 7;

struct str{
    int x, y;
}a[N];

int n, m;

bool cmp(str a, str b){
    return a.x < b.x;
}

int tmp[N];

int find(int d){
    int r = 1, res = 0;
    for(int i = 1; i <= n; i ++){
        r = max(r, i);
        while(a[r + 1].x - a[i].x + 2 <= d && r < n) r ++;
        int rr = i, mx = 0;
        for(int j = i; j <= r; j ++) tmp[j - i + 1] = a[j].y;
        sort(tmp + 1, tmp + r - i + 2);
        for(int j = i; j <= r; j ++){
            rr = max(rr, j);
            while(tmp[rr - i + 2] - tmp[j - i + 1] + 2 <= d && rr < r) rr ++;
            mx = max(mx, rr - j + 1);
        }
        res = max(res, mx);
    }
    
    return res;
}

signed main(){

    cin >> n;

    for(int i = 1; i <= n; i ++)
        cin >> a[i].x;

    cin >> n;

    for(int i = 1; i <= n; i ++)
        cin >> a[i].y;

    cin >> m;

    sort(a + 1, a + n + 1, cmp);

    int l = 1, r = 1e10;

    while(l + 1 < r){
        if(find(mid) >= m) r = mid;
        else l = mid;
    }

    cout << r * r << endl;

    return 0;
}*/

