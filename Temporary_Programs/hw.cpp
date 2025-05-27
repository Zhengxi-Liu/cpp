/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
double a[N], dis[N], sum1 = 0, sum2 = 0;
int n = 0;
int main(){
    while(cin >> n){
        for(int i = 1;i <= n;i ++){
            cin >> a[i];
            dis[i] = dis[i - 1] + a[i];
        }
        for(int i = 1;i <= n;i ++)
            sum1 += (a[i] - dis[n] / n) * (a[i] - dis[n] / n);
        sum1 /= (n - 1);
        cout << sqrt(sum1) << endl;
        sum1 = 0;
        for(int i = 1;i <= n;i ++)
            dis[i] = 0;
    }
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int a[N], i1 = 0, i2 = 0, i3 = 0;
double b[N], c[N], d[N];
int n;
int factor(int x, double a[]){
    int t = 0;
    for(int i = 1;i <= x;i ++){
        if(x % i == 0){
            a[++ t] = i;
        }
    }
    return t;
}
double p(double x, int y){
    if(!y)
        return 1;
    double ret = 1;
    for(int i = 1;i <= y;i ++)
        ret *= x;
    return ret;
}
string t;
map <double, int> mp;
int main(){
    cin >> n;
    for(int i = 1;i <= n;i ++)
        cin >> a[i];
    i1 = factor(abs(a[1]), b);
    i2 = factor(abs(a[n]), c);
    for(int i = 1;i <= i1;i ++){
        for(int j = 1;j <= i2;j ++){
            if(mp.count(c[j] / b[i]))
                continue;
            d[++ i3] = c[j] / b[i];
            mp[c[j] / b[i]] ++;
        }
    }
    for(int i = 1;i <= i3;i ++){
        cout << d[i] << ",-" << d[i];
        if(i != i3)
            cout << ',';
    }
    cout << endl;
    for(int i = 1;i <= i3;i ++){
        double ans = 0, ans2 = 0;
        for(int j = 1;j <= n;j ++){
            ans += p(d[i], n - j) * a[j];
            ans2 += p(-1 * d[i], n - j) * a[j];
        }
        //88cout << ans << ' ' << ans2 << endl;
        if(ans == 0)
            cout << d[i] << ' ';
        if(ans2 == 0)
            cout << d[i] * -1 << ' ';
    }
    cout << endl;
    return 0;
}*/
/*#include<iostream>
using namespace std;
const int N = 1e5 + 7;
int a[N], b[N], c[N], dis[N], k;
vector <int> d[N];
int n, m, x, ans;
int main(){
    cin >> n >> m;
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= m;j ++){
            cin >> a[(i - 1) * n + j];
            b[(i - 1) * n + j] = i + j;
            c[++ k] = a[(i - 1) * n + j];
        }
    }
    sort(c + 1, c + k + 1);
    k = unique(c + 1, c + k + 1) - c - 1;
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= m;j ++){
            int idx = lower_bound(c + 1, c + k + 1, a[(i - 1) * n + j]) - c;
            //cout << a[(i - 1) * n + j];
            d[idx].push_back(i + j);
        }
        //cout << endl;
    }
    for(int i = 1;i <= k;i ++){
        sort(d[i].begin(), d[i].end());
    }
    for(int i = 1;i <= k;i ++){
        memset(dis, 0, sizeof(dis));
        for(int j = 0;j < d[i].size();j ++){
            dis[j] = dis[j - 1] + d[i][j];

        }
        for(int j = 0;j < d[i].size();j ++){
            if(j >= 1){
                ans += (d[i][j] * j - dis[j - 1]);
            }
        }
    }
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
long long a[N], dis[N], n, q, x;
int main(){
    cin >> n >> q;
    n ++;
    for(int i = 2;i <= n;i ++){
        cin >> a[i];
        dis[i] = dis[i - 1] + a[i];
    }
    while(q --){
        cin >> x;
        int k = lower_bound(dis + 1, dis + n + 1, x) - dis;
        cout << min(abs(x - dis[k - 1]), abs(x - dis[k])) << endl;
    }
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
double v, theta, x, y, t, g = -9.80665;
int main(){
    cin >> v >> theta >> x >> y >> t;
    double vx = v * cos(theta / 180.0 * 3.14159265358), vy = v * sin(theta / 180.0 * 3.14159265358);
    //cout << vx << ' ' << vy << endl;
    double vyf = vy + g * t;
    printf("%.5lf %.5lf\n", vx * t + x, y + vy * t + 0.5 * g * t * t);
    return 0;
}*/
#include<bits/stdc++.h>
using namespace std;
double a, b;
int main(){
    cin >> a >> b;
    cout << a * b << endl;
    return 0;
}