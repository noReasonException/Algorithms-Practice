#include <iostream>
#include <vector>
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
    //p : previous, n : now
	ll n,xp,xn,ans=0;
    cin>>n;
    if(n==0){
        cout<<0<<"\n";
        return;
    }
    if(n==1){
        cin>>xp;
        cout<<0<<"\n";
        return;
    }
    cin>>xp;
    for(ll i=1;i<n;i++){
        cin>>xn;
        if(xn<xp) {
            ans+=abs(xp-xn);
            xn+=abs(xp-xn);
        }
        xp=xn;
    }
    cout<<ans<<"\n";
    return;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	solve();
	return 0;
}