//created by gravitorious
#include <bits/stdc++.h>
using namespace std;
 
#ifdef XOX
#include "debug.h"
#else
#define debug(...) 77
#endif
 
using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
 
#define getunique(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}
 
double int_part(double x, double* intpart){
    //returns the real part
    return modf(x, intpart);
}
 
ll udiv(ll a, ll b) {
    return a / b + ((a ^ b) > 0 && a % b);
}  // divide a by b rounded up
ll ddiv(ll a, ll b) {
    return a / b - ((a ^ b) < 0 && a % b);
}  // divide a by b rounded down
 
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
 
long long myRand(long long B) {
    //0 to B-1
    return (unsigned long long)rng() % B;
}
 
int myUniRand(int a, int b){
    //a to b
    uniform_int_distribution<int> distribution(a,b);
    return distribution(rng);
}
 
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        string s;
        cin >> s;
        for(int j = 0; j < n; j++){
            if(n % (j + 1) == 0){
                string s1 = s.substr(0, j + 1);
                int x = 0, y = j;
                bool flag1 = false, flag2 = false;
                while(y < n){
                    string s2 = s.substr(x, j + 1);
                    for(int k = 0; k <= j; k++){
                        if(s1[k] != s2[k] && !flag1){
                            flag1 = true;
                        }
                        else if(s1[k] != s2[k] && flag1){
                            flag2 = true;
                            break;
                        }
                    }
                    if(flag2) break;
                    x += j + 1, y += j + 1;
                }
                if(!flag2){
                    cout << j + 1 << '\n';
                    break;
                }
                flag1 = false, flag2 = false;
                
                s1 = s.substr(n - j - 1, j + 1);
                x = 0, y = j;
                while(y < n){
                    string s2 = s.substr(x, j + 1);
                    for(int k = 0; k <= j; k++){
                        if(s1[k] != s2[k] && !flag1){
                            flag1 = true;
                        }
                        else if(s1[k] != s2[k] && flag1){
                            flag2 = true;
                            break;
                        }
                    }
                    if(flag2) break;
                    x += j + 1, y += j + 1;
                }
                if(!flag2){
                    cout << j + 1 << '\n';
                    break;
                }
                
            }
        }
    }
    return 0;
}