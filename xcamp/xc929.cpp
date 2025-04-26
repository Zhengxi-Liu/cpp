/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
int n, m, a[N], b[N];
int main(){
    cin >> n >> m;
    for(int i = 1;i <= n;i ++)
        cin >> a[i];
    b[0] = 0;
    for(int j = 1;j <= n;j ++)
        for(int i = a[j];i <= m;i ++)
            if(b[i - a[j]] || !(i - a[j])){
                if(b[i] != 0)
                    b[i] = min(b[i], b[i - a[j]] + 1);
                else
                    b[i] = b[i - a[j]] + 1;
            }
    cout << b[m] << endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int N = 1e2 + 7;
int a[N][N], n, b[N][N], ans = 0;
int main(){
    cin >> n;
    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= i;j ++)
            cin >> a[i][j];
    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= i;j ++)
            b[i][j] = max(b[i - 1][j - 1], b[i - 1][j]) + a[i][j];
    for(int i = 1;i <= n;i ++)
        ans = max(ans, b[n][i]);
    cout << ans << endl;
    return 0;
    int ans = 0;
    for(int i = 5;i <= 100;i += 5)
        ans += i * i;
    cout << ans << endl;
    return 0;
}*/