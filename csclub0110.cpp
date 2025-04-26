#include<bits/stdc++.h>
using namespace std;
const int N = 1e2 + 7;
vector <int> a[N];
int n;
int main(){
    cin >> n;
    for(int i = 1;i <= n;i ++){
        int t;
        while(cin >> t){
            if(!t)
                break;
            a[i].push_back(t);
        }
    }
    return 0;
}