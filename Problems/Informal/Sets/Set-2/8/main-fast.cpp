#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <array>
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
	int n,max_occ=0;
    cin >> n;
    vector<int> a(n,0),occ(101,0);
    for (int i = 0; i < n; i++) cin>>a[i];
    for (int i = 0; i < n; i++) {
        occ[a[i]]+=1;
        if(occ[a[i]]>max_occ) max_occ=occ[a[i]];
    }
    cout<<n-max_occ<<"\n";
    
    
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	

	int t;
	cin>>t;
	while(t--)solve();
	return 0;
}