#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int a[N], n, k, ans;
void dfs(int step, int sum){
    if(sum > k)
        return;
    if(step > n){
        if(sum < k)
            return;
        if(a[1] + a[n] > 1)
            return;
        ans ++;
        return;
    }
    if(!a[step - 1]){
        a[step] = 1;
        dfs(step + 1, sum + 1);
        a[step] = 0;
        dfs(step + 1, sum);
    }
    else {
        a[step] = 0;
        dfs(step + 1, sum);
    }
}
int combination(int n, int k) {
    if (k > n)
        return 0;
    if (k > n - k)
        k = n - k;
    int result = 1;
    for (int i = 1; i <= k; i++) {
        result *= n--;
        result /= i;
    }
    return result;
}
int main(){
    cin >> n >> k;
    dfs(1, 0);
    cout << ans << endl;
    cout << combination(n - k + 1, k) - combination(n - k - 1, k - 2) << endl;
    return 0;
}