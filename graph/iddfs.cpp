#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 7;
int a[N], n, ans = 0;
bool dfs(int step, int sum){
    if(step > ans)
        return false;
    if(sum << (ans - step) < n)
        return false;
    if(sum == n)
        return true;
    a[step] = sum;
    for(int i = 0;i <= step;i ++){
        if(dfs(step + 1, sum + a[i]))
            return true;
        if(dfs(step + 1, abs(sum - a[i])))
            return true;
    }
    return false;
}
int main(){
    while(cin >> n && n){
        memset(a, 0, sizeof(a));
        ans = 0;
        while(!dfs(0, 1)){
            ans ++;
            memset(a, 0, sizeof(a));
        }
        cout << ans << endl;
    }
    return 0;
}