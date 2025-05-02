/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
vector <int> ch[N];
int n, idx = 1, cnt, x, t;
int size[N], a[N], p[N], s[N], c[N], f[N];
void build(int x, int v){
    ch[x].push_back(++ idx);
    size[idx] = size[x] + 1;
    p[v] = idx;
    f[idx] = x;
}
void dfs(int x, int last){
    s[x] = last;
    c[x] = ch[x].size();
    for(int i = 0;i < ch[x].size();i ++){
        if(ch[x].size() > 1)
            dfs(ch[x][i], x);
        else
            dfs(ch[x][i], last);
    }
}
int find(int x){
    if(x == 1)
        return 1;
    //cout << x << ' ' << c[x] << "// ";
    if(c[x] >= 2)
        return size[x];
    return find(s[x]);
}
int main(){
    scanf("%d", &n);
    p[0] = 1;
    for(int i = 1;i <= n;i ++){
        scanf("%d", &a[i]);
        build(p[a[i]], i);
    }
    dfs(1, 1);
    for(int i = 1;i <= idx;i ++){
        //cout << ch[i].size() << ' ' << s[i] << ' ' << c[i] << endl;
        //cout << size[i] << ' ' << c[i] << endl;
        if(!ch[i].size())
            cnt ++;
    }
    t = cnt;
    for(int i = 1;i <= cnt;i ++){
        cin >> x;
        if(i == cnt){
            cout << '0' << endl;
            break;
        }
        // for(int i = 1;i <= n;i ++) 
        //     cout << c[i] << ' ';
        // cout << endl;
        int add = 0;
        if(c[s[s[x]]] >= 2)
            add = 1;
        cout << find(s[p[x]]) + add << endl;
        c[s[p[x]]] --;
    }
    return 0;
}*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int a[10][10], c[10], n, ans;
int pluss(int x){
    if(x == 9)
        return 0;
    return x + 1;
}
void dfs(int step){
    if(step > 5){
        int maxn = 0;
        for(int i = 1;i <= n;i ++){
            int cnt = 0, flag = 0;
            for(int j = 1;j <= 5;j ++){
                if(a[i][j] != c[j]){
                    cnt ++;
                    if(cnt == 2){
                        
                        int ff = 0, s1 = a[i][j], s2 = a[i][j - 1], e1 = c[j], e2 = c[j - 1];
                        for(int k = 1;k <= 9;k ++){
                            s1 = pluss(s1);
                            s2 = pluss(s2);
                            if(s1 == e1 && s2 == e2)
                                ff = 1;
                        }
                        if(!ff)
                            return;
                    }
                }
            }
            if(cnt > 2 || !cnt)
                return;
            maxn = max(maxn, cnt);
        }
        ans ++;
        // for(int j = 1;j <= 5;j ++)
        //     cout << c[j] << ' ';
        // cout << endl;
        return;
    }
    for(int x = 0; x <= 9; x ++){
        c[step] = x;
        dfs(step + 1);
    }
}
int main(){
    cin >> n;
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= 5;j ++){
            cin >> a[i][j];
        }
    }
    dfs(1);
    cout << ans << endl;
    return 0;
}*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e2 + 7;
struct str{
    string name; // name of struct
    int cnt; // number of members
    string mem[N], type[N], l[N]; // name of members, type of variable
    int maxn; // maximum  occupation
    int length; // memory usage
    int dis[N];
    map <string, int> find_idx; // find where the i'th is
}a[N];
struct var{
    string name; // name of variable
    string type; // type of variable
    int length; // length of memory occupied
    int st, ed; // where the variable start and ends at
}b[N];
int t, n, op, k, idx, idxb, pos, dis[N];
string s;
map <string, int> mp, mp2;
int change(string s){
    if(s == "int")
        return 4;
    if(s == "byte")
        return 1;
    if(s == "short")
        return 2;
    if(s == "long")
        return 8;
    return a[mp[s]].maxn;
}
int change2(string s){
    if(s == "int")
        return 4;
    if(s == "byte")
        return 1;
    if(s == "short")
        return 2;
    if(s == "long")
        return 8;
    return a[mp[s]].length;
}
signed main(){
    ofstream fout("1.out");
    ifstream fin("1.in");
    fin >> t;
    while(t --){
        fin >> op;
        if(op == 1){
            ++ idx;
            fin >> a[idx].name >> a[idx].cnt;
            //cout << a[idx].name << ' ' << a[idx].cnt << endl;
            a[idx].maxn = 0;
            int posit = 0;
            for(int i = 1;i <= a[idx].cnt;i ++){
                fin >> a[idx].type[i] >> a[idx].mem[i];
                int ch = change(a[idx].type[i]), lll = change2(a[idx].type[i]);
                a[idx].maxn = max(a[idx].maxn, ch);
                a[idx].find_idx[a[idx].mem[i]] = i;
                if(posit % ch == 0)
                    posit += lll;
                else {
                    posit = ceil(1.0 * posit / ch) * ch + lll;
                    a[idx].dis[i - 1] = posit - lll;
                }
                a[idx].dis[i] = posit;
                //cout << posit << ' ' << ch << endl;
            }
            a[idx].length = ceil(1.0 * posit / a[idx].maxn) * a[idx].maxn;
            a[idx].dis[a[idx].cnt] = a[idx].length;
            fout << a[idx].length << ' ' << a[idx].maxn << endl;
            mp[a[idx].name] = idx;
        }
        if(op == 2){
            ++ idxb;
            fin >> b[idxb].type >> b[idxb].name;
            fout << pos << endl;
            b[idxb].st = pos;
            if(b[idxb].type == "long" || b[idxb].type == "short" || b[idxb].type == "byte" || b[idxb].type == "int"){
                b[idxb].length = change(b[idxb].type);
                pos += b[idxb].length;
                b[idxb].ed = pos;
                dis[idxb] = pos;
            }
            else {
                b[idxb].length = a[mp[b[idxb].type]].length;
                pos += b[idxb].length;
                b[idxb].ed = pos;
                dis[idxb] = pos;
                mp2[b[idxb].name] = idxb;
            }
        }
        if(op == 3){
            string s2, s3;
            fin >> s;
            n = s.size() + 1;
            s = " " + s;
            s += ".";
            int last = 1, ans = 0;
            for(int i = 1;i <= n;i ++)
                if(s[i] == '.'){
                    s2 = s.substr(last, i - last); last = i + 1;
                    if(mp2.count(s2)){
                        ans += dis[mp2[s2] - 1];
                        s3 = b[mp2[s2]].type;
                    }
                    else {
                        int j = mp[s3], k = a[j].find_idx[s2];
                        string t1 = a[j].type[k];
                        //cout << " ** " << t1 << ' ' << j << " ** ";
                        ans += a[mp[s3]].dis[k - 1];
                        if(t1 == "int" || t1 == "long" || t1 == "short" || t1 == "byte")
                            break;
                        s3 = t1;
                    }
                    //cout << ans << ' ' << s2 << ' ' << s3 << " // ";
                }
            fout << ans << endl;
        }
        if(op == 4){
            fin >> k;
            if(k > pos){
                fout << "ERR" << endl;
                continue;
            }
            // for(int i = 1;i <= idxb;i ++)
            //     cout << dis[i] << ' ';
            // cout << endl;
            int index = lower_bound(dis + 1, dis + idxb + 1, k) - dis, cc = 0; //the index of the variable
            k -= dis[index - 1]; //exclude all before them
            string s2 = b[index].type, ans = b[index].name; //find the type of struct that variable is in
            while(k){
                if(s2 == "long" || s2 == "int" || s2 == "byte" || s2 == "short"){
                    if(k > change2(s2))
                        ans = "ERR";
                    break;
                }
                ans += ".";
                int tmp = mp[s2]; 
                index = lower_bound(a[tmp].dis + 1, a[tmp].dis + a[tmp].cnt + 1, k) - a[tmp].dis;
                //cout << " // " << s2 << ' ' << index << ' ' << k << "//";
                k -= a[tmp].dis[index - 1];
                s2 = a[tmp].type[index];
                ans += a[tmp].mem[index];
            }
            fout << ans << endl;
            //cout << "//" << index << ' ' << idxb << "//" << endl;
        }
    }
    return 0;
}
/*

10
1 a 4
int aa
short ab
long ac
byte ad
1 b 4
a ba
int bb
short bc
a bd
2 b x
2 a y
3 x.bd.ab
3 x.ba
3 y.ac
4 42
4 20
4 100

*/