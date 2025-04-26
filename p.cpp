/*#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1e5 + 7;
LL a[N], dis[N], minn[N], n, m, s = 1, ans = 1e18;//s = initial velocity
LL b[N];
int main(){
    //cout << "Kimi es insimpático, bajo y feo." << endl;
    cin >> n;
    for(int i = 1;i <= n;i ++){
        minn[i] = 1e18;
        cin >> a[i];
        dis[i] = dis[i - 1] + a[i];
        if(dis[i] <= 0)
            s = min(s, dis[i]);
    }
    if(s == 1){
        cout << s << endl;
        return 0;
    }
    s = abs(s) + 1;
    LL temp = s;
    minn[0] = temp;
    b[0] = temp;
    for(int i = 1;i <= n;i ++){
        temp += a[i];
        minn[i] = min(minn[i - 1], temp);
        b[i] = temp;
    }
    //cout << s << endl;
    ans = s - s / 2;
    for(int i = 1;i <= n;i ++){
        LL t2 = b[i] / 2;
        ans = min(ans, s - min(b[i] / 2, minn[i - 1] - 1));
        //cout << minn[i - 1] - 1 << ' ' << b[i] / 2 << " / ";
    }
    cout << ans << endl;
    return 0;
}*/

/*for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= m;j ++){
            if(a[i][j] == 1){
                int flag = 0;
                for(int k = j + 1;k <= m;k ++)
                    if(b[i][k] >= 3){
                        a[i][j] = 0;
                        b[i][k] ++;
                        cnt -= 1;
                        flag ++;
                        break;
                    }
                if(!flag){
                    for(int k = 1;k + j <= m && i - k >= 1;k ++){
                        int t1 = i - k, t2 = j + k;
                        if(a[t1][t2] == 2){
                            a[i][j] = 0;
                            a[t1][t2] = 0;
                            b[i][t2] = 3;
                            cnt -= 2;
                            break;
                        }
                    }
                }
            }
            else if(a[i][j] == 2){
                for(int k = i + 1;k <= n;k ++)
                    if(b[k][j] >= 3){
                        a[i][j] = 0;
                        b[k][j] ++;
                        cnt -= 1;
                        break;
                    }
            }
            //if(!s && a[i][j] == 1 || a[i][j] == 2)
            //    ans ++;
        }*/
    /*cout << endl;
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= m;j ++)
            cout << a[i][j] << ' ';
        cout << endl;
    }*/
    /*for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= m;j ++)
            cout << b[i][j] << ' ';
        cout << endl;
    }
    for(int i = n;i >= 1;i --)
        for(int j = m;j >= 1;j --){
            if(a[i][j] == 1){
                int s = 0;
                for(int k = 1;k + j <= m;k ++){
                    if(b[i][k + j] >= 2){
                        a[i][j] = 0;
                        b[i][k + j] ++;
                        s ++;
                        cout << i << ' ' << j << "//" << endl;
                        break;
                    }
                    if(i - k >= 1 && a[i - k][j + k] == 2){
                        a[i - k][j + k] = 0;
                        a[i][j] = 0;
                        b[i][j + k] = 2;
                        s ++;
                        break;
                    }
                }
                if(!s){
                    a[i][j] = 0;
                    ans ++;
                }
            }
            if(a[i][j] == 2){
                int s = 0;
                for(int k = 1;k + i <= n;k ++){
                    if(b[i + k][j] >= 2){
                        a[i][j] = 0;
                        b[i + k][k] ++;
                        s ++;
                        cout << i << " 2\n";
                        break;
                    }
                    if(j - k >= 1 && a[i + k][j - k] == 1){
                        a[i + k][j - k] = 0;
                        a[i][j] = 0;
                        b[i][j + k] = 2;
                        s ++;
                        break;
                    }
                }
                if(!s){
                    a[i][j] = 0;
                    ans ++;
                }
            }
        }
    cout << endl;
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= m;j ++)
            cout << a[i][j] << ' ';
        cout << endl;
    }
    cout << endl;
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= m;j ++)
            cout << b[i][j] << ' ';
        cout << endl;
    }
    //for(int i = 1;i <= n;i ++)
      //  for(int j = 1;j <= m;j ++)
        //    if(b[i][j])
          //      ans += b[i][j];*/
/*for(int i = 1;i <= n;i ++){
                for(int j = 1;j <= m;j ++)
                    cout << a[i][j] << ' ';
                cout << endl;
            }*/
            //cout << i << ' ' << j << endl;
            //cout << cnt << ' ' << ans << endl;
/*for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= m;j ++)
            cout << a[i][j] << ' ';
        cout << endl;
    }*/ 
/*#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1e5 + 7;
LL a[N], n, k, ans = 0;
LL jerk(LL x, LL y){
    if(x % 2 == 0)
        return x / 2 * y;
    return y / 2 * x;
}
void cmp(LL x){
    if(jerk(k, k + 1) < x){
        cout << jerk(k, k + 1) << endl;
        exit(0);
    }
    LL l = 0, r = 1e9, c = 0;
    while(l < r && c <= 70){
        LL mid = (l + r) / 2;
        //cout << mid << ' ';
        if(jerk(mid, mid + 1) <= x)
            l = mid;
        else
            r = mid;
        c ++;
    }
    //cout << l << endl;
    if(jerk(l, l + 1) == x){
        cout << jerk(l - 1, l) << endl;
        exit(0);
    }
}
int main(){
    cin >> n >> k;
    for(int i = 1;i <= n;i ++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    for(int i = 1;i <= n;i ++)
        cmp(a[i]);
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int a[N], n, maxn, ans = 0;
int main(){
    cin >> n;
    for(int i = 1;i <= n;i ++)
        cin >> a[i];
    maxn = a[1];
    for(int i = 2;i <= n;i ++){
        ans += maxn;
        if(maxn < a[i])
            maxn = a[i];
    }
    cout << ans << endl;
    return 0;
}*/
/*

0 0 0 0 0
2 3 3 3 3
0 1 0 0 0
0 3 1 3 1
0 0 0 0 0


*/
#include<iostream>
using namespace std;
int main(){
    long long n = 7999999999, m;
    cin >> m;
    for(long long i = 3;i * i <= n;i += 2)
        if(n % i == 0)
            cout << n / i << ' ';
    return 0;
}