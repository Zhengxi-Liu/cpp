//CF1658D2 388535 (Hard Version)
//https://codeforces.com/problemset/problem/1658/D2

#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;

int a[N], ch[N][2], b[N];

int t, l, r, n, cnt;

void insert(int sum){

    int now = 0;

    for(int i = 17; i >= 0; i --){
        bool tmp = (1 << i) & sum; // 找到二进制下 sum 的第 i 位的值
        if(!ch[now][tmp])
            ch[now][tmp] = ++ cnt;
        now = ch[now][tmp];
    }

}

int Max(int sum){
    
    int now = 0, res = 0;

    for(int i = 17; i >= 0; i --){
        bool tmp = (1 << i) & sum; // 找到二进制下 sum 的第 i 位的值
        if(!ch[now][tmp ^ 1]) // 如果下一位是 1 的 a[i] 不存在, 找下一位是 0 的
            now = ch[now][tmp];
        else
            now = ch[now][tmp ^ 1], res += (1 << i); // 下一位是 1 的 a[i] 存在, 找下一位是 1 的
    }

    return res;

}

int Min(int sum){

    int now = 0, res = 0;

    for(int i = 17; i >= 0; i --){
        bool tmp = (1 << i) & sum; // 找到二进制下 sum 的第 i 位的值
        if(!ch[now][tmp]) // 如果下一位是 0 的 a[i] 不存在, 找下一位是 1 的
            now = ch[now][tmp ^ 1], res += (1 << i);
        else
            now = ch[now][tmp]; // 下一位是 0 的 a[i] 存在, 找下一位是 0 的
    }

    return res;

}

int main(){

    
    scanf("%d", &t);

    while(t --){

        scanf("%d %d", &l, &r);

        n = r - l + 1;

        for(int i = 0; i <= cnt; i ++)
            ch[i][0] = ch[i][1] = 0;

        cnt = 0;
        
        for(int i = 1; i <= n; i ++)
            scanf("%d", &a[i]), b[i] = a[i] ^ l, insert(a[i]);
        
        for(int i = 1; i <= n; i ++)
            if(Min(b[i]) == l && Max(b[i]) == r){ 
                // b[i] 代表了所有可能的值
                // 如果最大值和最小值分别为为 r l, 又因为 a[i] 互不相同, 可以保证所有的 l 到 r 都被覆盖了
                printf("%d\n", b[i]);
                break;
            }

    }
    return 0;
}
