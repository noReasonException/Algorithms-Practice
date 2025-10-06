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
    //lp left - previous 
    //rp right - previous
    //ln left - now
    //rn right - now
	ll n,s,m,lp,rp,ln,rn;
    cin>>n>>s>>m;
    if(n==0) {
        if(m>=s){
            cout<<"YES\n";
        }
        else cout<<"NO\n";
            
        return;
    }
    if(n==1){
        cin>>lp>>rp;    
        if(lp>=s||m-rp>=s) cout<<"YES\n";
        else cout<<"NO\n";
        return;
    }
    cin>>lp>>rp;
    ll maxBetweenIntervals = lp;
    for(ll i =1;i<n;i++){
        cin>>ln>>rn;
        if(ln-rp>maxBetweenIntervals) maxBetweenIntervals = ln-rp; 
        lp = ln;
        rp = rn;
    }
    
    if(maxBetweenIntervals>=s || m-rn>=s) cout<<"YES\n";
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