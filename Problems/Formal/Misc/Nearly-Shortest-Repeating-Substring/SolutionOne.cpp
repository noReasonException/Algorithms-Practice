////created by gravitorious
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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

template <class T>
void chkmax(T &x,T y){
    if(x < y) x = y;
}
 
template <class T>
void chkmin(T &x,T y){
    if(x > y) x = y;
}
 
constexpr int popcnt(int x){
    return __builtin_popcount(x);
}
 
constexpr int ctz(int x){
    return __builtin_ctz(x);
}

constexpr double int_part(double x, double *intpart){ 
	return modf(x, intpart); //returns the real part
}
 
ll udiv(ll a, ll b) {
	return a / b + ((a ^ b) > 0 && a % b);
}  // divide a by b rounded up
ll ddiv(ll a, ll b) {
	return a / b - ((a ^ b) < 0 && a % b);
}  // divide a by b rounded down
 
long long myRand(long long B) {
	//0 to B-1
	return (unsigned long long)rng() % B;
}
 
int myUniRand(int a, int b){
	//a to b
	uniform_int_distribution<int> distribution(a,b);
	return distribution(rng);
}
 
void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int hits = 0;
   	for(int i = 1; i < n; i++){
   		if(n % i == 0){
   			hits = 0;
   			int k_size = i;
   			for(int each_char = 0; each_char < k_size; each_char++){
   				bool flag = false;
   				char prev = s[each_char], current, next_char;
   				for(int each_segment = 1; each_segment <= n / k_size - 1; each_segment++){
   					if(flag == true){
   						next_char = s[(each_segment) * k_size + each_char];
   						if(prev != next_char && current != next_char){
   							hits++; // we don't need to continue, hits == 2
   							break;
   						}
   						else if(prev != next_char){ //nextchar == current
   							prev = current;
   						}
   						flag = false;
   						continue;
   					}
   					current = s[(each_segment) * k_size + each_char];
   					if(each_segment == 1 && prev != current){
   						flag = true;
   						hits++;
   					}
   					else if(prev != current){
   						hits++;	
   					}
   				}
   			}
   			if(hits <= 1){
   				cout << i << '\n';
   				return;
   			}
   		}	
   	}
   	cout << n << '\n';
}
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int tc;
	cin >> tc;
	while(tc--) solve();
	return 0;
}
