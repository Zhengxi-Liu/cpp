/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
int ne[N], n;
string s;
int main(){
    cin.tie();
    while(cin >> s){
        if(s == ".")
            break;
        n = s.size();
        s = " " + s;
        for(int i = 1,j = 0;i < n;i ++){
            while(j && s[i + 1] != s[j + 1])
                j = ne[j];
            if(s[i + 1] == s[j + 1])
                j ++;
            ne[i + 1] = j;
        }
        if(n % (n - ne[n]) == 0)
            cout << n / (n - ne[n]) << endl;
        else
            cout << '1' << endl;
    }
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
string s;
stack <int> ans;
int ne[N], n;
int main(){
    cin.tie();
    while(cin >> s){
        n = s.size();
        s = " " + s;
        for(int i = 1,j = 0;i < n;i ++){
            while(j && s[i + 1] != s[j + 1])
                j = ne[j];
            if(s[i + 1] == s[j + 1])
                j ++;
            ne[i + 1] = j;
        }
        ans.push(n);
        while(ne[n]){
            ans.push(ne[n]);
            n = ne[n];
        }
        while(!ans.empty()){
            cout << ans.top() << ' ';
            ans.pop();
        }
        cout << endl;
    }
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
//标准模版,绝对正确
const int N = 1e6 + 7;
int ne[N], n, m;
string s, t;
int main(){
    cin >> s >> t;
    n = s.size();m = t.size();
    s = " " + s;t = " " + t;
    for(int i = 2,j = 0;i <= m;i ++){
        while(j && t[i] != t[j + 1])
            j = ne[j];
        if(t[i] == t[j + 1])
            j ++;
        ne[i] = j;
    }
    for(int i = 1,j = 0;i <= n;i ++){
        while(j && s[i] != t[j + 1])
            j = ne[j];
        if(t[j + 1] == s[i])
            j ++;
        if(j == m){
            cout << i + 1 - m << endl;
            j = ne[j];
        }
    }
    for(int i = 1;i <= m;i ++)
        cout << ne[i] << ' ';
    cout << endl;
    return 0;
}*/

/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
int n, ne[N];
char a[N];
int main(){
    cin >> n;
    for(int i = 1;i <= n;i ++)
        cin >> a[i];
    for(int i = 2, j = 0;i <= n;i ++){
        if(j && a[j + 1] != a[i])
            j = ne[j];
        if(a[i] == a[j + 1])
            j ++;
        ne[i] = j;
    }
    cout << n - ne[n] << endl;
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
int ne[N], n;
char a[N];
int main(){
    cin >> n;
    for(int i = n + 2;i <= 2 * n + 1;i ++)
        cin >> a[i];
    a[n + 1] = '.';
    for(int i = 1, j = 2 * n + 1;i <= n;i ++, j --)
        a[i] = a[j];
    for(int i = 2, j = 0;i <= 2 * n + 1;i ++){
        while(j && a[j + 1] != a[i])
            j = ne[j];
        if(a[j + 1] == a[i])
            j ++;
        ne[i] = j;
    }
    cout << n - ne[n * 2 + 1] << endl;
    return 0;
}*/

#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 7;
string s, t;
int ne[N], pos[N], n, m, tt;
int main(){
    cin >> tt;
    while(tt --){
        cin >> s >> t;
        n = s.size(), m = t.size();
        s = " " + s, t = " " + t;
        memset(ne, 0, sizeof(ne));
        memset(pos, 0, sizeof(pos));
        for(int i = 2, j = 0;i <= m;i ++){
            while(j && t[j + 1] != t[i])
                j = ne[j];
            if(t[j + 1] == t[i])
                j ++;
            ne[i] = j;
        }
        for(int i = 1;i <= m;i ++)
            cout << ne[i] << ' ';
        cout << endl;
        t += "#";
        for(int i = 1, j = 0;i <= n;i ++){
            while(j && s[i] != t[j + 1])
                j = ne[j];
            if(s[i] == t[j + 1])
                j ++;
            pos[i] = j;
        }
        for(int i = 1;i <= n;i ++)
            cout << pos[i] << ' ';
        cout << endl;
        int ans = 1, x = n;
        while(x > 0){
            int y = pos[x];
            if(!y){
                cout << x << ' ';
                ans = 0;
                cout << "/";
                break;
            }
            x -= y;
        }
        cout << (ans == 1 ? "Yes" : "No") << endl;
    }
    return 0;
}
/*
3
apple
apaple
banana
banbabb
nanami
nanami
*/
