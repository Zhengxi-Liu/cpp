// #include<bits/stdc++.h>
// using namespace std;
// const int N = 5e5 + 7;
// int a[N], dis[N], n, ans = 0;
// int main(){
//     cin >> n;
//     for(int i = 1;i <= n;i ++){
//         cin >> a[i];
//         dis[i] = dis[i - 1] + a[i];
//     }
//     for(int i = 1;i < n;i ++){
//         if(dis[i] == dis[n] - dis[i]){
//             ans ++;
//             //cout << i << ' ';
//         }
//     }
//     cout << ans << endl;
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// const int N = 1e4 + 7;
// string s;
// int n, a[N], dis[N], m = 0, ans = 0;
// int main(){
//     cin >> n;
//     getline(cin, s);
//     for(int i = 1;i <= n;i ++){
//         getline(cin, s);
//         for(int j = 0;j < s.size();j ++){
//             if(s[j] == '#')
//                 a[i] += 1;
//         }
//         m += a[i];
//     }
//     while(m > 0){
//         int flag = 0;
//         for(int i = 1;i <= n;i ++){
//             if(a[i] == 0 && flag == 1)
//                 break;
//             if(a[i] == 0)
//                 continue;
//             flag = 1;
//             if(a[i] < a[i - 1])
//                 break;
//             m -= 1;
//             a[i] -= 1;
//         }
//         if(!flag)
//             break;
//         ans ++;
//     }
//     cout << ans << endl;
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// const int N = 1e2 + 7;
// char a[N];
// int n, k, m, b[N], c[N], i1 = 0, i2 = 0;
// void find_power(){
//     for(int i = 0;pow(2, i) <= k;i ++)
//         c[++ i2] = pow(2, i);
// }
// int main(){
//     cin >> n >> k;
//     find_power();
//     m = n * 2 - 1;
//     a[0] = '+';
//     for(int i = 1;i <= m;i ++){
//         cin >> a[i];
//         if(a[i] == '?'){
//             if(a[i - 1] == '+')
//                 b[++ i1] = 1;
//             else
//                 b[i1] ++;
//         }
//     }
     
//     return 0;
// }


/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int a[N], b[N], c[N], n, m;
int main(){
    cin >> n >> m;
    for(int i = 1;i <= n;i ++)
        cin >> a[i];
    for(int i = 1;i <= m;i ++)
        cin >> b[i] >> c[i];
    for(int i = 1;i <= m;i ++){
        int ans = 1e9;
        for(int j = 1;j <= n;j ++){
            int cnt = 0;
            for(int k = b[i];k <= c[i];k ++)
                cnt = max(cnt, min(abs(a[j] + k - 70), abs(k - 70)));
            ans = min(ans, cnt);
        }
        cout << ans << endl;
    }
    return 0;
}*/


// #include<iostream>
// #include<algorithm>
// using namespace std;
// const int N = 1e3 + 7;
// int t, n;
// double a[N], b[N], c[N];
// double dis(double x1, double x2, double y1, double y2, double z1, double z2){
//     double x3 = (x1 - x2) * (x1 - x2);
//     double y3 = (y1 - y2) * (y1 - y2);
//     double z3 = (z1 - z2) * (z1 - z2);
//     return sqrt(x3 + y3 + z3);
// }
// int main(){
//     cin >> t;
//     while(t --){
//         cin >> n;
//         for(int i = 1;i <= n;i ++)
//             cin >> a[i] >> b[i] >> c[i];
//         double minn = 1e9;
//         for(int i = 1;i <= n;i ++){
//             for(int j = 1;j <= n;j ++){
//                 if(i == j)
//                     continue;
//                 minn = min(minn, dis(a[i], a[j], b[i], b[j], c[i], c[j]));
//             }
//         }
//         if(minn >= 128)
//             cout << "True" << endl;
//         else
//             cout << "False" << endl;
//     }
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
long long n, m, k, dsu[N];
struct str{
    long long a, b, c;
}s[N];
int find(long long x){
    if(dsu[x] == x)
        return x;
    return dsu[x] = find(dsu[x]);
}
void merge(long long x, long long y){
    int s1 = find(x);
    int s2 = find(y);
    dsu[s1] = dsu[s2];
}
bool cmp(str x, str y){
    return x.c > y.c;
}
int main(){
    cin >> n >> m >> k;
    for(int i = 1;i <= n;i ++)
        dsu[i] = i;
    for(int i = 1;i <= m;i ++)
        cin >> s[i].a >> s[i].b >> s[i].c;
    sort(s + 1, s + m + 1, cmp);
    long long cnt = n, ans = -1;
    for(int i = 1;i <= m;i ++){
        if(find(s[i].a) != find(s[i].b)){
            cnt -= 1;
            merge(s[i].a, s[i].b);
        }
        if(cnt == k){
            ans = i;
            break;
        }
    }
    if(ans == -1){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    for(int i = ans + 1;i <= m;i ++){
        if(find(s[i].a) != find(s[i].b)){
            cout << s[i].c + 1 << endl;
            break;
        }
    }
    return 0;
}