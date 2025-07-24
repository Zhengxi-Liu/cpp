//C. LCIS
/*#include<bits/stdc++.h>
using namespace std;

#define Max(a, b) (a > b) ? a : b;

const short N = 5e3 + 1;

int a[N], x;

short dp[N], n, m, ans;

int main(){

    ifstream fin("lcis.in");
    ofstream fout("lcis.out");

    fin >> n;

    for(short i = 1; i <= n; i ++)
        fin >> a[i];

    fin >> m;

    for(short j = 1; j <= m; j ++){
        fin >> x;
        short mx = 0;
        for(short i = 1; i <= n; i ++){
            if(a[i] == x){
                dp[i] = Max(dp[i], mx + 1);
                ans = max(ans, dp[i]);
            }
            if(a[i] < x)
                mx = Max(mx, dp[i]);
        }
    }
    fout << ans << endl;

    return 0;
}*/

//B. 相加排序
/*#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e6 + 7;

int a[N], b[N], n, L, R;

priority_queue<int, vector<int>, greater<int> > q;

int check(int x) {
    int res = 0;
    for (int i = 1, j = n; i <= n; i ++) {
        while(j && a[i] + b[j] > x) j --;
        res += j;
    }
    return res;
}

int search(int x) {
    int l = 0, r = 2e9;
    while (l + 1 < r) {
        int mid = (l + r) >> 1;
        if (check(mid) >= x)
            r = mid;
        else
            l = mid;
    }
    return l + 1;
}

signed main() {

    ifstream fin("sort.in");
    ofstream fout("sort.out");

    fin >> n >> L >> R;

    for (int i = 1; i <= n; i ++) fin >> a[i];

    for (int i = 1; i <= n; i ++) fin >> b[i];

    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);

    b[n + 1] = INT_MAX;
    
    int bg = search(L), ed = search(R), cnt = 0;

    for (int i = 1; i <= n; i ++) {
        int x = upper_bound(b + 1, b + n + 1, bg - a[i]) - b;
        int y = (lower_bound(b + 1, b + n + 1, ed - a[i]) - b) - 1;
        cnt += x - 1;
        if (x > n || y > n || y < x)
            continue;
        for (int j = x; j <= y; j ++) q.push(a[i] + b[j]);
    }

    for (int i = cnt + q.size() + 1; i <= R; i ++) q.push(ed);
    for (int i = L; i <= min(cnt, R); i ++) q.push(bg);

    while (!q.empty()) {
        fout << q.top() << ' ';
        q.pop();
    }

    return 0;
}*/

//D. 球球
/*#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e5 + 7;

int n, m, q, x, cnt; 

int a[N], b[N];

struct str{
    int len, st;
};

bool operator < (str a, str b){
    if(a.len == b.len) return a.st < b.st;
    return a.len > b.len;
}

map <str, int> mp;

unordered_map <int, int> f;

int dfs(int a, int b){
    if(a < b) return 0;
    if(a == b) return 1;
    if(f[a]) return f[a];
    return f[a] = dfs(a >> 1, b) + dfs((a - 1) >> 1, b);
}

int find(int l, int r, int len, int s){
    int mid = (l + r) >> 1;
    if(r - l + 1 == len) return mid;
    if(dfs(mid - l, len) >= s)  
        return find(l, mid - 1, len, s);
    return find(mid + 1, r, len, s - dfs(mid - l, len));
}

signed main(){

    ifstream fin("ball.in");
    ofstream fout("ball.out");

    fin >> m >> n >> q;

    for(int i = 1; i <= n; i ++)
        fin >> a[i];

    a[n + 1] = m + 1;
    for(int i = 0; i <= n; i ++){
        x = a[i + 1] - a[i] - 1;
        if(x) mp[{x, i}] = 1;
    }

    cnt = n; // 取了几个球
    while(q --){

        fin >> x;
        if(x <= n){
            fout << a[x] << endl;
            continue;
        }
        
        while(true){
            auto now = *mp.begin();
            int sz = now.second, len = now.first.len;
            if(cnt + sz >= x) break;
            cnt += sz;
            mp.erase(now.first);
            if(len >> 1) mp[{len >> 1, now.first.st}] += sz;
            if((len - 1) >> 1) mp[{(len - 1) >> 1, now.first.st}] += sz;
        }

        auto now = *mp.begin();
        fout << find(a[now.first.st] + 1, a[now.first.st + 1] - 1, now.first.len, x - cnt) << endl;
        // 在最开始取球划分出的区间里, 找到一个长度为 len 的, 答案就是它
        f.clear();

    }

    return 0;
}*/
