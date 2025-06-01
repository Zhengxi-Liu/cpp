/*
宝贵经验: 机场不适合写代码
华盛顿到北京: 17小时
*/
#include<bits/stdc++.h>
using namespace std;

int n, ans;

int main(){

    cin >> n;

    for(int i = 1; i <= n; i ++){
        if(n % i == 0)
            ans += (n - 1) / i;
        else
            ans += n / i;
    }

    cout << ans << endl;

    return 0;
}