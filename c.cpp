#include<bits/stdc++.h>
using namespace std;
int a[4][4], ans, dis1[4], dis2[4];
void dfs(int step){
    if(step == 9){
        memset(dis1, 0, sizeof(dis1));
        memset(dis2, 0, sizeof(dis2));
        for(int i = 1;i <= 3;i ++)
            for(int j = 1;j <= 3;j ++){
                dis1[i] += a[i][j];
                dis2[j] += a[i][j];
            }
        for(int i = 1;i <= 3;i ++)
            if(dis1[i] == 1 || dis2[i] == 1)
                return;
        ans ++;
        for(int i = 1;i <= 3;i ++){
            for(int j = 1;j <= 3;j ++)
                cout << a[i][j] << ' ';
            cout << endl;
        }
        cout << endl;
        return;
    }
    int x = step / 3 + 1, y = step % 3 + 1;
    a[x][y] = 1;
    dfs(step + 1);
    a[x][y] = 0;
    dfs(step + 1);
}
int main(){
    dfs(0);
    cout << ans << endl;
    return 0;
}
