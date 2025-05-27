/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
struct str{
    int x, y, z;
}a[N];
int pre[N], dis[N], vis[N], k, n, m;
void add(int from, int to, int v){
    str t; t.x = to, t.y = v, t.z = pre[from];
    a[++ k] = t;
    pre[from] = k;
}
bool operator >(str a, str b){
    return a.x > b.x;
}
priority_queue < str, vector <str>, greater <str> > q;
int prim(){
    memset(dis, 0x3f, sizeof(dis));
    dis[1] = 0;
    str t;
    t.x = 0;
    t.y = 1;
    int ans = 0, cnt = 0;
    q.push(t);
    while(!q.empty()){
        int now = q.top().y;
        q.pop();
        if(vis[now])
            continue;
        vis[now] = 1;
        ans += dis[now];
        cnt ++;
        for(int i = pre[now];i;i = a[i].z)
            if(dis[a[i].x] > a[i].y){
                dis[a[i].x] = a[i].y;
                t.x = dis[a[i].x];
                t.y = a[i].x;
                q.push(t);
            }
    }
    if(cnt != n)
        return -1;
    return ans;
}
int main(){
    cin >> n >> m;
    int x, y, z;
    for(int i = 1;i <= m;i ++){
        cin >> x >> y >> z;
        add(x, y, z);
        add(y, x, z);
    }
    int s = prim();
    if(s == -1)
        cout << "orz" << endl;
    else
        cout << s << endl;
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
struct str{ int x, y, v; }a[N];
int fa[N], ans, cnt, n, m, k;
bool cmp(str a, str b){
    return a.v < b.v;
}
int find(int x){
    if(fa[x] == x)
        return x;
    return fa[x] = find(fa[x]);
}
bool kruskal(){
    for(int i = 1;i <= n;i ++)
        fa[i] = i;
    for(int i = 1;i <= m;i ++){
        int x = find(a[i].x), y = find(a[i].y);
        if(x != y){
            fa[x] = y;
            ans += a[i].v;
            cnt ++;
        }
        if(cnt >= n - k)
            return true;
    }
    return false;
}
int main(){
    cin >> n >> m >> k;
    for(int i = 1;i <= m;i ++)
        cin >> a[i].x >> a[i].y >> a[i].v;
    sort(a + 1,a + m + 1, cmp);
    bool s = kruskal();
    if(s == true)
        cout << ans << endl;
    else
        cout << "No Answer" << endl;
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 * 25 + 7;
struct str{
    int x, y, v;
}a[N], b[N];
int n, k, dsu[N], cnt, ans, t = 1;
int distance(int s1, int s2, int e1, int e2){
    return (s1 - e1) * (s1 - e1) + (s2 - e2) * (s2 - e2);
}
bool cmp(str a, str b){
    return a.x < b.x;
}
bool cmp2(str a, str b){
    return a.v < b.v;
}
int find(int x){
    if(dsu[x] == x)
        return x;
    return dsu[x] = find(dsu[x]);
}
signed main(){
    cin >> n;
    for(int i = 1;i <= n;i ++){
        cin >> a[i].x >> a[i].y;
        dsu[i] = i;
    }
    sort(a + 1, a + n + 1, cmp);
    for(int i = 1;i <= n;i ++){
        for(int j = max(t, i - 25);j <= i;j ++){
            b[++ k] = {i, j, distance(a[i].x, a[i].y, a[j].x, a[j].y)};
        }
    }
    sort(b + 1, b + k + 1, cmp2);
    for(int i = 1;i <= k;i ++){
        int x = find(b[i].x), y = find(b[i].y);
        if(x != y){
            dsu[x] = y;
            cnt ++;
            ans += b[i].v;
        }
        if(cnt >= n - 1)
            break;
    }
    cout << ans << endl;
    return 0;
}*/

//P2820 局域网
/*#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e2 + 7, M = 1e4 + 7;
struct node{
    int x, y, v;
}e[N];
int dsu[N], b[M], n, m, cnt = 1;
int find(int x){
    if(x == dsu[x])
        return x;
    return dsu[x] = find(dsu[x]);
}
void merge(int x, int y){
    dsu[find(x)] = find(y);
}
bool cmp(node a, node b){
    return a.v < b.v;
}
signed main(){
    cin >> n >> m;
    for(int i = 1;i <= n;i ++)
        dsu[i] = i;
    int idx = 0;
    for(int i = 1;i <= m;i ++){
        int x, y, z;
        cin >> x >> y >> z;
        if(z){
            idx ++;
            e[idx].x = x, e[idx].y = y, e[idx].v = z;
        }
    }
    m = idx;
    sort(e + 1, e + m + 1, cmp);
    for(int i = 1;i <= m;i ++){
        if(find(e[i].x) != find(e[i].y)){
            merge(e[i].x, e[i].y);
            cnt ++;
            b[i] = 1;
        }
        if(cnt == n)
            break;
    }
    cnt = 0;
    for(int i = 1;i <= m;i ++)
        if(!b[i])
            cnt += e[i].v;
    cout << cnt << endl;
    return 0;
}*/

//xiaohou X258建设道路
/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 7;
#define int long long
int dsu[N], x[N], y[N];
int find(int x){
    if(dsu[x] == x)
        return x;
    return dsu[x] = find(dsu[x]);
}
void merge(int x, int y){
    dsu[find(x)] = find(y);
}
int n, m, dis[N][N], u, v, k, cnt = 1;
double ans;
struct str{
    int l, r, v;
}a[N * N];
bool cmp(str a, str b){
    return a.v < b.v;
}
int distance(int s1, int s2, int e1, int e2){
    return (s1 - e1) * (s1 - e1) + (s2 - e2) * (s2 - e2);
}
signed main(){
    cin >> n >> m;
    for(int i = 1;i <= n;i ++){
        cin >> x[i] >> y[i];
        dsu[i] = i;
    }
    for(int i = 1;i <= m;i ++){
        cin >> u >> v;
        if(find(u) != find(v))
            cnt ++;
        merge(u, v);
        dis[u][v] = 1;
        dis[v][u] = 1;
    }
    for(int i = 1;i <= n;i ++)
        for(int j = 1;j < i;j ++){
            if(!dis[i][j]){
            	k ++;
                a[k].l = i; 
                a[k].r = j;
                a[k].v = distance(x[i], y[i], x[j], y[j]);
            }
        }
    sort(a + 1, a + k + 1, cmp);
    for(int i = 1;i <= k;i ++){
        if(find(a[i].l) != find(a[i].r)){
            merge(a[i].l, a[i].r);
            cnt ++;
            ans += sqrt(1.0 * a[i].v);
        }
        if(cnt == n)
            break;
    }
    printf("%.2lf\n", ans);
    return 0;
}*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 7;
struct str{
	int x, y, v;
}a[N];
int dsu[N], b[N], n, m, ans;
int find(int x){
	if(dsu[x] == x)
		return x;
	return dsu[x] = find(dsu[x]);
}
void merge(int x, int y){
	dsu[find(x)] = find(y);
}
bool cmp(str a, str b){
	return a.v < b.v;
}
map <int, int> mp;
signed main(){
	cin >> n >> m;
	for(int i = 1;i <= m;i ++)
		cin >> a[i].x >> a[i].y >> a[i].v;
	for(int i = 1;i <= n;i ++)
		dsu[i] = i;
	sort(a + 1, a + m + 1, cmp);
	for(int i = 1;i <= m;){
        int t = i;
        while(a[t].v == a[t + 1].v){
            if(find(a[t].x) == find(a[t].y)){
                b[t] = 1;
            }
            t ++;
        }
        for(int j = i;j <= t;j ++)
            if(!b[j]){
                merge(a[j].x, a[j].y);
                //cout << j << "// ";
            }
        i = t + 1;
        //cout << i << ' ';
	}
	for(int i = 1;i <= n;i ++){
        //cout << b[i] << ' ';
        dsu[i] = i;
    }
    //cout << endl << endl;
	for(int i = 1;i <= m;i ++){
        //cout << b[i] << ' ' << i << ' ' << a[i].x << ' ' << a[i].y << ' ' << a[i].v << endl;
        if(b[i])
            continue;
        //cout << i << ' ' << a[i].x << ' ' << a[i].y << ' ' << find(a[i].x) << ' ' << find(a[i].y) << endl;
		if(find(a[i].x) != find(a[i].y)){
			merge(a[i].x, a[i].y);
			mp[a[i].v] = 1;
			ans += a[i].v;
		}
		else if(mp.count(a[i].v)){
			cout << "Not Unique!" << endl;
			return 0;
		}
	}
	cout << ans << endl;
	return 0;
}