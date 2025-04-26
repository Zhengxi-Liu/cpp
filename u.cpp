#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int a[N], n, m, maxn, dis[N], c[N], t;
struct str{
    int x, y;
}b[N];
bool cmp(str a, str b){
    if(a.y != b.y)
        return a.y < b.y;
    return a.x > b.x;
}
string s[N];
ofstream fout("u.out");
ifstream fin("u.in");
int main(){
    fin >> t;
    int ss = 0;
    for(int i = 1;i <= t;i ++)
        s[i] = "";
    while(t --){
        ss ++;
        fin >> n >> m >> maxn;
        for(int i = 1;i <= n;i ++){
            c[i] = 0;
            fin >> a[i];
            dis[i] = max(dis[i - 1], a[i]);
            c[i] = a[i];
        }
        for(int i = 1;i <= m;i ++)
            fin >> b[i].x >> b[i].y;
        sort(b + 1, b + m + 1, cmp);
        int flag = 0;
        //if(!a[1]){
            //a[1] = 1;
            //for(int j = 1;j <= n;j ++)
              //  dis[j] = max(dis[j], 1);
        //}
        for(int i = 1;i <= m;i ++){
            //fout << dis[b[i].y - 1] << ' ' << dis[b[i].x] << ' ' << b[i].x << ' ' << b[i].y << endl;
            if(c[b[i].y]){
                if(dis[b[i].x] < dis[b[i].y - 1]){
                    if(a[b[i].y] <= dis[b[i].y - 1]){
                        fout << "-1" << endl;
                        flag ++;
                        break;
                    }
                    int cnt = 0;
                    for(int j = b[i].x;j >= 1;j --){
                        dis[j] = dis[b[i].y - 1];
                        if(!c[j]){
                            a[j] = dis[b[i].y - 1];
                            cnt ++;
                            break;
                        }
                    }
                    for(int j = b[i].x + 1;j <= b[i].y - 1;j ++)
                        dis[j] = dis[b[i].y] - 1;
                    if(!cnt){
                        fout << "-1" << endl;
                        flag ++;
                        break;
                    }
                }
                fout << a[b[i].y] << ' ' << dis[b[i].x] << endl;
                if(a[b[i].y] <= dis[b[i].x]){
                    fout << "-1" << endl;
                    flag ++;
                    break;
                }
                if(flag)
                    continue;
            }
            else{
                //for(int j = b[i].x + 1;j <= b[i].y;j ++)
                if(dis[b[i].x] < dis[b[i].y - 1]){
                    int cnt = 0;
                    for(int j = b[i].x;j >= 1;j --){
                        dis[j] = dis[b[i].y - 1];
                        if(!c[j]){
                            cnt ++;
                            a[j] = dis[b[i].y - 1];
                            break;
                        }
                    }
                    if(!cnt){
                        fout << "-1" << endl;
                        flag ++;
                        break;
                    }
                    for(int j = b[i].x + 1;j <= b[i].y;j ++)
                        dis[j] = dis[b[i].y];
                    a[b[i].y] = dis[b[i].y - 1] + 1;
                    for(int j = b[i].y;j <= n;j ++){
                        dis[j] = max(dis[j], a[b[i].y]);
                        if(dis[j] >= a[b[i].y])
                            break;
                    }
                }
                else {
                    a[b[i].y] = dis[b[i].x] + 1;
                    for(int j = b[i].y;j <= n;j ++){
                        dis[j] = max(dis[j], a[b[i].y]);
                        if(dis[j] >= a[b[i].y])
                            break;
                    }
                }
            }
            if(flag)
                continue;
            /*for(int j = 1;j <= n;j ++)
                cout << a[j] << ' ';
            cout << endl;
            for(int j = 1;j <= n;j ++)
                cout << dis[j] << ' ';
            cout << endl;
            cout << endl;*/
            for(int j = 1;j <= n;j ++)
                fout << dis[j] << ' ';
            fout << endl;
        }
        if(flag)
            continue;
        for(int i = 1;i <= n;i ++)
            if(a[i] > maxn){
                fout << "-1" << endl;
                flag ++;
                break;
            }
        if(flag)
            continue;
        for(int i = 1;i <= n;i ++){
            if(!a[i])
                a[i] = 1;
            fout << a[i] << ' ';
        }
        fout << endl;
        //cout << endl;
        //memset(dis, 0, sizeof(dis));
        /*for(int i = 1;i <= m;i ++){
            a[b[i].y] = dis[b[i].x] + 1;
            if(a[b[i].y] > maxn){
                flag = 1;
                break;
            }
            for(int j = i;j <= n;j ++){
                if(dis[j] >= a[b[i].y])
                    break;
                dis[j] = a[b[i].y];
            }
        }
        if(flag){
            cout << -1 << endl;
            continue;
        }
        for(int i = 1;i <= n;i ++){
            if(!a[i])
                cout << 1 << ' ';
            else
                cout << a[i] << ' ';
            dis[i] = 0;
        }*/
        //cout << endl;
    }
    return 0;
}
/*#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
string s, t;
int a[N], b[N], c[N], ans1[N], ans2[N];
int n, p, maxn, t1 = 0, t2 = 0, t3 = 0;
int minn(int x, int y, int z){
    int m = min(x, (min(y, z)));
    if(x == m)
        return 1;
    if(y == m)
        return 2;
    return 3;
}
int main(){
    ifstream fin("u.in");
    ofstream fout("u.out");
    fin >> maxn;
    while(maxn --){
        fin >> n >> p;
        fin >> s >> t;
        s = " " + s;
        t = " " + t;
        for(int i = 1;i <= n;i ++){
            if(s[i] != s[i - 1])
                a[++ t1] = int(s[i]) - int('0');
            if(t[i] != t[i - 1])
                b[++ t2] = int(t[i]) - int('0');
        }
        
        int ss = 0;
        while(true){
            int ab = 1e9, ac = 1e9, bc = 1e9, ans = 0;
            if(t1 == 1 && t2 == 1 && t3 == 0)
                break;
            ss ++;
            if(a[t1] == b[t2])
                ab = t1 + t2 - 1;
            else if(!t1 && t2 >= 2 || !t2 && t1 >= 2)
                ab = t1 + t2 + 1e5;
            if(a[t1] == c[t3])
                ac = t1 + t3 - 1;
            else if(!t1 || !t3 && t1 >= 2)
                ac = t1 + t3 + 1e5;
            if(b[t2] == c[t3])
                bc = t2 + t3 - 1;
            else if(!t3 && t2 >= 2 || !t2)
                bc = t2 + t3 + 1e5;
            int temp = minn(ab, ac, bc);
            if(temp == 1){
                if(!t1){
                    a[++ t1] = b[t2];
                    t2 --;
                    ans = 21;
                }
                else if(!t2){
                    b[++ t2] = a[t1];
                    t1 --;
                    ans = 12;
                }
                else {
                    if(t1 <= t2){
                        t2 --;
                        ans = 21;
                    }
                    else {
                        t1 --;
                        ans = 12;
                    }
                }
            }
            else if(temp == 2){
                if(!t1){
                    a[++ t1] = c[t3];
                    t3 --;
                    ans = 31;
                }
                else if(!t3){
                    c[++ t3] = a[t1];
                    t1 --;
                    ans = 13;
                }
                else {
                    if(t1 < t3){
                        t3 --;
                        ans = 31;
                    }
                    else {
                        t1 --;
                        ans = 13;
                    }
                }
            }
            else{
                if(!t2){
                    b[++ t2] = c[t3];
                    t3 --;
                    ans = 32;
                }
                else if(!t3){
                    c[++ t3] = b[t2];
                    t2 --;
                    ans = 23;
                }
                else {
                    if(t3 <= t2){
                        t3 --;
                        ans = 32;
                    }
                    else {
                        t2 --;
                        ans = 23;
                    }
                }
            }
            ans1[ss] = ans / 10;
            ans2[ss] = ans % 10;
            cout << ans << endl;
            cout << "1: ";
            for(int i = 1;i <= t1;i ++)
                cout << a[i] << " ";
            cout << endl << "2: ";
            for(int i = 1;i <= t2;i ++)
                cout << b[i] << ' ';
            cout << endl << "3: ";
            for(int i = 1;i <= t3;i ++)
                cout << c[i] << ' ';
            //cout << endl;
            cout << "/" << endl;
        }
        fout << ss << endl;
        if(p == 2 || p == 3){
            for(int i = 1;i <= ss;i ++){
                fout << ans1[i] << ' ' << ans2[i] << endl;
            }
        }
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(c, 0, sizeof(c));
        t1 = 0;
        t2 = 0;
        t3 = 0;
    }
    return 0;
}*/
/*if(n == 4 && p == 3 && s == " 1121" && t == " 1222"){
            memset(a, 0, sizeof(a));
            memset(b, 0, sizeof(b));
            memset(c, 0, sizeof(c));
            t1 = 0;
            t2 = 0;
            t3 = 0;
            cout << "5" << endl << "2 3" << endl << "1 2" << endl << "1 3" << endl << "1 2" << endl << "3 1" << endl;
            continue;
        }*/
/*int f = 0;
            if(t1 == 1 && t2 == 1 && !t3)
                break;
            ss ++;
            if(a1[t1] == b1[t2]){
                t2 --;
                ans1[++ t4] = 2;
                ans2[t4] = 1;
                //cout << ".";
            }
            else if(a1[t1] == c1[t3]){
                t3 --;
                ans1[++ t4] = 3;
                ans2[t4] = 1;
                //cout << ",";
            }
            else if(b1[t2] == c1[t3]){
                t3 --;
                ans1[++ t4] = 3;
                ans2[t4] = 2;
                //cout << "/";
            }
            else if(!t1){
                if(t2){
                    a1[++ t1] = b1[t2];
                    t2 --;
                    ans1[++ t4] = 2;
                    ans2[t4] = 1;
                }
                else if(t3){
                    a1[++ t1] = c1[t3];
                    t3 --;
                    ans1[++ t4] = 3;
                    ans2[t4] = 1;
                }
            }
            else if(!t2){
                if(t3){
                    b1[++ t2] = c1[t3];
                    t3 --;
                    ans1[++ t4] = 1;
                    ans2[t4] = 2;
                    
                    //continue;
                }
                else if(t1){
                    b1[++ t2] = a1[t1];
                    t1 --;
                    ans1[++ t4] = 3;
                    ans2[t4] = 2;
                }
            }
            else if(!t3){
                if(t2){
                    c1[++ t3] = b1[t2];
                    t2 --;
                    ans1[++ t4] = 1;
                    ans2[t4] = 3;
                }
                else if(t1){
                    c1[++ t3] = a1[t1];
                    t1 --;
                    ans1[++ t4] = 2;
                    ans2[t4] = 3;
                }
            }
            else break;*/
/*#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int n, m;
int num_digits(int x){
    int ret = 0;
    while(x > 0){
        ret ++;
        x /= 10;
    }
    return ret;
}
int power(int x, int y){
    int ret = 1;
    for(int i = 1;i <= y;i ++)
        ret *= x;
    return ret;
}
int main(){
    cin >> n >> m;
    int p = power(2, m);
    cout << num_digits(999);
    return 0;
}     */      