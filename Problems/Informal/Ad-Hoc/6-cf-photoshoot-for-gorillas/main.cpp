#include <iostream>
#include <vector>
#include <algorithm>    // std::min
using namespace std;
#define ll long long
//forward refs
template <typename container> void cinfoCon(container& genericSequence,string id="None", int depth=0);

//debug utils
#ifdef DEBUG
	#define cinfo cout
	#define add <<
	template <typename container> void cinfoCon(container& genericSequence,string id, int depth){
		cout<<"=============cinfoCon Debug ("<<id<<") START =============\n";
		string prefix = "";
		for(int i=0;i<depth;i++) prefix+="\t";

		for(auto every: genericSequence){
			cout<<prefix<<every<<"\n";
		}
		cout<<"=============cinfoCon Debug ("<<id<<") END =============\n";

	}
#endif
#ifndef DEBUG
	#define cinfo ;
	#define add ;
	template <typename container> void cinfoCon(container& genericSequence,string id, int depth){
		return ;
	}

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
	ll n,m,k,w;
	ll temp1,spectacle=0;
	cin>>n>>m>>k>>w;
	vector<ll> heights;
	vector<ll> weights;
	for(int i=0;i<w;i++) {
		cin>>temp1;
		heights.push_back(temp1);
		//cout<<temp1<<" ";
	}
	ll weight = 0;
	for(ll i=0;i<n;i++) {
		//rows
		for(ll j=0;j<m;j++) {
			ll weight_row = std::min(i+1,k)+(n-i-k>0?0:(n-i-k));
			ll weight_col = std::min(j+1,k)+(m-j-k>0?0:(m-j-k));
			ll weight = weight_row*weight_col;
			weights.push_back(weight);
		}
	}

	std::sort(weights.begin(),weights.end());
	std::sort(heights.begin(),heights.end());

	while(heights.size()>0){
		spectacle+=weights.back()*heights.back();
		weights.pop_back();
		heights.pop_back();
	}

	cout<<spectacle<<"\n";


	

	return;

}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n;
	cin>>n;
	while(n--)solve();
	return 0;
}