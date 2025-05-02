#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int a[10][10], b[N], n, ans;
int dis(int x, int y){
    if(x == 9)
        return min(x - y, y + 1);
    if(y == 9)
        return min(y - x, x + 1);
    if(x == 0)
        return min(y, 10 - y);
    if(y == 0)
        return min(x, 10 - x);
    return abs(x - y);
}
void dfs(int step){
    if(step > 5){
        ans ++;
    }
    for(int x = 0; x <= 9; x ++){
        int maxn = 0;
        for(int i = 1;i <= n;i ++)
            maxn = max(maxn, dis(x, a[i][step]));
        if(maxn <= 1){
            b[step] = x;
            dfs(step + 1);
        }
    }
}
int main(){
    cin >> n;
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= 5;j ++){
            cin >> a[i][j];
        }
    }
    dfs(1);
    cout << ans << endl;
    return 0;
}