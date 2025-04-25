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
	int n;
	ull sum=0,maxsum=0;
	cin >> n;
	vector<int> a(n);
	vector<int> bitset(30);
	for(int i =0;i<n;i++){
		cin>>a[i];
		
	}
	for(int i =0;i<n;i++){
		for(int j=0;j<30;j++){
			bitset[j] += (a[i]>>j)&1;
		}
	}
	for(int i =0;i<n;i++){
		sum=0;
		for(int j=0;j<30;j++){
			if(((a[i]>>j)&1)==0){
				sum += (1LL)*(bitset[j])*(1 << j);
			}
			else{
				sum += (1LL)*(n-bitset[j])*(1 << j);
			}
		}
		if(sum>maxsum)maxsum=sum;
		
	}
	cout<<maxsum<<"\n";
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