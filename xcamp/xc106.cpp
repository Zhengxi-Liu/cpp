/*
#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 7;
int a[N], b[N], n, ans = 0;
int main(){
    cin >> n;
    for(int i = 1;i <= n;i ++)
        cin >> a[i];
    for(int i = 1;i <= n;i ++)
        for(int j = 0;j < n;j ++)
            if(a[j] < a[i])
                b[i] = max(b[j] + 1, b[i]);
    for(int i = 1;i <= n;i ++)
        ans = max(ans, b[i]);
    cout << ans << endl;
    return 0;
}
*/
/*
#include<bits/stdc++.h>                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
using namespace std;
const int N = 1e6 + 7, MOD = 1e9 + 7;
int a[N], b[N], n, x;
int main(){
    cin >> n >> x;
    for(int i = 1;i <= n;i ++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    b[0] = 1;
    for(int i = 1;i <= x;i ++)
        for(int j = 1;j <= n;j ++){
            if(i - a[j] < 0)
                break;
            if(b[i - a[j]])
                b[i] = (b[i] + b[i - a[j]]) % MOD;
        }
    cout << b[x] << endl;
    return 0;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
const int N = 1e2 + 7;
int a[N], b[N], n, ans = 0;
int main(){
    cin >> n;
    for(int i = 1;i <= n;i ++)
        cin >> a[i];
    for(int m = 1;m <= n;m ++){
        int x = 0, y = 0;
        for(int i = m - 1;i >= 1;i --)
            for(int j = m;j > i;j --)
                if(a[i] < a[j] && a[i] < a[m])
                    b[i] = max(b[i], b[j] + 1);
        for(int i = 1;i < m;i ++)
            x = max(x, b[i]);
        memset(b, 0, sizeof(b));
        for(int i = m + 1;i <= n;i ++)
            for(int j = m;j < i;j ++) 
                if(a[i] < a[j] && a[i] < a[m])
                    b[i] = max(b[i], b[j] + 1);
        for(int i = m + 1;i <= n;i ++)
            y = max(y, b[i]);
        memset(b, 0, sizeof(b));
        ans = max(ans, x + y);
    }
    cout << n - (ans + 1) << endl;
    return 0;
}
*/