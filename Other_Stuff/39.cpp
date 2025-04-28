/*
ID: gsliu.t1
LANG: C++11
TASK: concom 
*/
#include<bits/stdc++.h>
using namespace std;
ifstream fin("concom.in");
ofstream fout("concom.out");
const int N = 1e2 + 7;
int a[N][N], n, maxn = 0;
int main(){
    fin >> n;
    for(int i = 1;i <= n;i ++){
        int t1, t2, t3;
        fin >> t1 >> t2 >> t3;
        a[t1][t2] = t3;
        maxn = max(maxn, max(t1, t2));
    }
    for(int i = 1;i <= maxn;i ++){
        for(int j = 1;j <= maxn;j ++){
            if(j == i)
                continue ;
            int sum = 0;
            if(a[i][j] > 50)
                fout << i << ' ' << j << endl;
            else 
                for(int k = 1;k <= maxn;k ++){
                    if(a[i][k] <= 50)
                        continue ;
                    sum += a[k][j];
                }
            if(sum > 50){
                
                fout << i << ' ' << j << endl;
            }
        }
    }
    return 0;
}