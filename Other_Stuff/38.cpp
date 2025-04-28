/*
ID: gsliu.t1
LANG: C++11
TASK: money
*/
#include<bits/stdc++.h>
using namespace std;
ifstream fin("money.in");
ofstream fout("money.out");
const int N = 25 + 7, M = 1e4 + 7;
long long a[N], b[M], n, m;
int main(){
    fin >> n >> m;
    for(int i = 1;i <= n;i ++)
        fin >> a[i];
    sort(a + 1, a + n + 1);
    b[0] = 1;
    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= m;j ++)
            if(j - a[i] > -1 && b[j - a[i]])
                b[j] += b[j - a[i]];
    fout << b[m] << endl;
    return 0;
}