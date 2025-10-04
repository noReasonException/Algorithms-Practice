#include <iostream>
#include <vector>
#define ll long long
using namespace std;

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
	ll n,s,l,h;
	bool answer=true;
	cin>>n;
	if(n==0){
		cout<<"YES\n";
		return;
	}
	if(n==1){
		cin>>l;
		cout<<"YES\n";
		return;	
	}
	cin>>l;
	h=l;
	for(int i=1;i<n;i++){
		cin>>s;
		if(!answer) continue;
		if(!(abs(l-s)==1||abs(h-s)==1)){
			answer=false;
		}
		else{
			if(s<l) l=s;
			if(s>h) h=s;
		}
	}
	if(answer) cout<<"YES\n";
	else cout<<"NO\n";

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