#include <iostream>
#include <vector>
using namespace std;
#define ll long long
#define ull unsigned long long
//forward refs
template <typename container> void cinfoCon(container& genericSequence,string id="None", int depth=0);

//debug utils
#ifdef DEBUG
	template<typename T>void debug(vector<T> v){
		for(auto i:v){
			cout<<"\t"<<i<<"\n";
		}
		cout<<"\n";
	}
#endif
#ifndef DEBUG
	template<typename T>void debug(vector<T>v){}

#endif

/**
 	*
	? Stuff to look for ->
    * stay organised
    * int overflows, array bounds, etc.
    * special cases (n=1)?
    * do something instead of nothing
    * timebox your approach
    * simple is better than complex
    * n % mod = (n % mod + mod) % mod;
    * long long instead of int
    
*/
void solve(){
	int n,m,k;
    int result=-1;
    int r1=0,r2=0;
    
    cin>>n>>m>>k;

    cout<<min(n,k)*min(m,k)<<"\n";
    

}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	

	ull t;
	cin>>t;
	while(t--)solve();
	return 0;
}