//A. 奥数题
/*#include<bits/stdc++.h>
using namespace std;

string a, b, c;

int d[10], bc[10], mk[10];

int n, m, len, ans;

void check(){
    int fi = 0, se = 0, lst = 0;
    for(int i = 1; i <= n; i ++){
        if(i == 1 && !d[a[i] - 'A'] && i != n) return;
        fi = fi * 10 + d[a[i] - 'A'];
    }
    for(int i = 1; i <= m; i ++){
        if(i == 1 && !d[b[i] - 'A'] && i != m) return;
        se = se * 10 + d[b[i] - 'A'];
    }
    for(int i = 1; i <= len; i ++){
        if(i == 1 && !d[c[i] - 'A'] && i != len) return;
        lst = lst * 10 + d[c[i] - 'A'];
    }
    if(fi + se == lst) ans ++;
    if(fi - se == lst) ans ++;
    if(fi * se == lst) ans ++;
    if(fi % se == 0 && se != 0 && fi / se == lst) ans ++;
}


void dfs(int step){
    if(step == 5){
        check();
        return;
    }
    if(!mk[step]){
        dfs(step + 1);
        return;
    }
    for(int i = 0; i <= 9; i ++){
        if(bc[i]) continue;
        d[step] = i;
        bc[i] = 1;
        dfs(step + 1);
        bc[i] = 0;
    }
}

int main(){

    ifstream fin("math.in");
    ofstream fout("math.out");

    fin >> a >> b >> c;

    n = a.size(), m = b.size(), len = c.size();
    a = " " + a, b = " " + b, c = " " + c;

    for(int i = 1; i <= n; i ++) mk[a[i] - 'A'] = 1;
    for(int i = 1; i <= m; i ++) mk[b[i] - 'A'] = 1;
    for(int i = 1; i <= len; i ++) mk[c[i] - 'A'] = 1;


    dfs(0);

    fout << ans << endl;

    return 0;
}*/

//B. 互质卡片
#include<bits/stdc++.h>
using namespace std;

const int N = 1e2 + 7;

int gcd(int x, int y){
    if(!y) return x;
    return gcd(y, x % y);
}

int l, r, b[N], ans;

void dfs(int step){
    if(step > r){
        for(int i = 0; i < r - l; i ++){
            if(!b[i]) continue;
            for(int j = i + 1; j <= r - l; j ++){
                if(!b[j]) continue;
                if(gcd(i + l, j + l) != 1) return;
            }
        }
        ans ++;
        return;
    }
    b[step - l] = 1;
    dfs(step + 1);
    b[step - l] = 0;
    dfs(step + 1);
}

int main(){

    ifstream fin("coprime.in");
    ofstream fout("coprime.out");

    fin >> l >> r;

    if(r - l <= 20){
        dfs(l);
        fout << ans << endl;
    }

    return 0;
}

//C. 押韵字符串
/*#include<bits/stdc++.h>
using namespace std;

const int N = 2e6 + 7;

int n, tot, ans;

vector <int> a[N];

int ch[N][27], s[N], in[N];

char c[N];

void insert(char c[]){
    int p = 0;
    for(int i = strlen(c) - 1; i >= 0; i --){
        int x = c[i] - 'a';
        if(!ch[p][x]) ch[p][x] = ++ tot;
        p = ch[p][x];
    }
    //cout << p << ' ';
    s[p] ++;
    //cout << s[cnt] << endl;
}

void dfs(int x){
    for(int i = 0; i < 26; i ++){
        int to = ch[x][i];
        if(!to) continue;
        if(s[to]){
            a[x].push_back(to);
            in[to] ++;
        }
        dfs(to);
    }
}

int DP(int x){
    int sz = 0, mx1 = 0, mx2 = 0;
    for(int to : a[x]){
        int tmp = DP(to);
        //if(x == 3) cout << "** " << tmp << " **\n";
        if(tmp >= mx1){
            mx2 = mx1;
            mx1 = tmp;
        }
        else if(tmp > mx2) mx2 = tmp;
        sz += s[to];
    }
    ans = max(ans, mx1 + mx2 + s[x] + sz);
    //cout << x << ": " << mx1 << ' ' << mx2 << endl;
    //if(x <= 4) cout << x << ": " << sz << ' ' << mx << endl;
    return sz + mx1;
}

int main(){

    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    scanf("%d", &n);

    while(n --){
        scanf("%s", c);
        //fout << t << endl;
        insert(c);
    }

    dfs(0);

    // for(int i = 0; i <= tot; i ++){
    //     fout << i << ": ";
    //     for(int out : a[i]) fout << out << ' ';
    //     fout << endl;
    // }

    for(int i = 0; i <= tot; i ++){
        if(!in[i]){
            ans = max(ans, DP(i) + s[i]);
        }
    }
    printf("%d\n", ans);
    
    return 0;
}*/

//D. 数字拆分


