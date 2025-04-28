/*
ID: gsliu.t1
LANG: C++11
TASK: zerosum
*/
#include<bits/stdc++.h>
using namespace std;
ifstream fin("zerosum.in");
ofstream fout("zerosum.out");
const int N = 20 + 7;
int a[N], b[N], n, ans = 0;
void dfs(int step){
    if(step == n){
        int sum = 1;
        a[0] = 0;
        for(int i = 1;i < n;){
            if(a[i] == 3){
                int temp = i, s = i;
                while(a[i] == 3){
                    i ++;
                    temp = temp * 10 + i;
                }
                if(a[s - 1] == 1){
                    sum -= s;
                    sum += temp;
                }   
                if(a[s - 1] == 2){
                    sum += s;
                    sum -= temp;
                }
                if(! a[s - 1])
                    sum += temp - 1;
                i -= 1;
            }
            if(a[i] == 1)
                sum += (i + 1);
            if(a[i] == 2)
                sum -= (i + 1);
            i += 1;
        }
        if(! sum){
            ans ++;
            for(int i = 1;i <= n;i ++){
                fout << i;
                if(i != n){
                    if(a[i] == 1)
                        fout << '+';
                    if(a[i] == 2)
                        fout << '-';
                    if(a[i] == 3)
                        fout << ' ';
                }
            }
            fout << endl;
        }
        return ;
    }
    a[step] = 3;
    dfs(step + 1);
    a[step] = 1;
    dfs(step + 1);
    a[step] = 2;
    dfs(step + 1);
}
int main(){
    fin >> n;
    dfs(1);
    return 0;
}
/*void dfs(int step, int sum){
    if(sum > m)
        return ;
    if(step > n){
        if(sum == m)
            ans ++;
        return ;
    }
    dfs(step + 1, sum);
    for(int i = 1;i <= (m - sum) / a[step];i ++)
        dfs(step + 1, sum + a[step] * i);
}*/