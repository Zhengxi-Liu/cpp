// #include<bits/stdc++.h>
// using namespace std;
// const int N = 1e5 + 7;
// char a[N], b[N];
// int n, t;
// string s1, s2;
// map <char, char> mp, mp2;
// void prep(){
//     n = s1.size();
//     s1 = " " + s1;
//     s2 = " " + s2;
//     memset(a, 0, sizeof(a));
//     memset(b, 0, sizeof(b));
//     mp.clear();
//     mp2.clear();
// }
// int main(){
//     cin >> t;
//     while(t --){
//         cin >> s1 >> s2;
//         prep();
//         int flag = 0;
//         for(int i = 1;i <= n;i ++){
//             if(mp.count(s1[i]) && mp[s1[i]] != s2[i]){
//                 flag = 1;
//                 break;
//             }
//             mp[s1[i]] = s2[i];
//         }
//         if(flag == 1){
//             cout << "-1" << endl;
//             continue;
//         }
//         int idx = 0, ans = 0;
//         for(map <char, char>::iterator i = mp.begin();i != mp.end();i ++){
//             if(i -> first == i -> second)
//                 continue;
//             a[++ idx] = i -> first;
//             b[idx] = i -> second;
//             mp2[i -> first] = 1;
//         }
//         for(int i = 1;i <= idx;i ++){
//             //cout << a[i] << ' ' << b[i] << endl;
//             if(a[i] != b[i]){
//                 if(mp2.count(b[i])){
//                     ans += 2;
//                     mp2.erase(a[i]);
//                 }
//                 else{
//                     ans += 1;
//                     mp.erase(a[i]);
//                 }
//             }
//         }
//         cout << ans << endl;
//     }
//     return 0;
// }
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n;
LL num_of_numbers(LL x){
    return x - x / 3 - x / 5 + x / 15;
}
int main(){
    ifstream fin("moobuzz.in");
    ofstream fout("moobuzz.out");
    fin >> n;
    LL l = 0, r = 2e9;
    while(l + 1 < r){
        LL mid = (l + r) / 2;
        if(num_of_numbers(mid) < n)
            l = mid;
        else r = mid;
    }
    fout << r << endl;
    return 0;
}