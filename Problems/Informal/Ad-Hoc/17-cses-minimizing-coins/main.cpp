#include <iostream>
#include <vector>
#include <set>
#include <math.h>
#define ll 			long long
#define MOD   		((ll) pow(10,9)+7);
#define INF_INT   	(1<<30)
#define INF_LL   	(1L<<62)

using namespace std;


//forward refs
template <typename container> void debug(container& genericSequence,string id="None", int depth=0);

//debug utils
#ifdef DEBUG
	template <typename container> void debug(container& genericSequence,string id, int depth){
		cout<<"=============Debug ("<<id<<") START =============\n";
		string prefix = "";
		for(int i=0;i<depth;i++) prefix+="\t";

		for(auto every: genericSequence){
			cout<<prefix<<every<<"\n";
		}
		cout<<"=============Debug ("<<id<<") END =============\n";

	}
#endif
#ifndef DEBUG
	template <typename container> void debug(container& genericSequence,string id, int depth){
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
	ll n,x,min;
	cin>>n>>x;
	vector<ll>dp(x+1,-1); 
	vector<ll>c(n,0); //coins
	for (ll i = 0; i < n; i++) {
		cin>>c[i];
		if(c[i]<x+1) dp[c[i]]=1; //if i have coin i then i can construct sum i with 1 coin. gets no better than that.
	}
	for (ll i = 1; i < x+1 ; i++)
	{
		if(dp[i]!=-1) continue;
		min=INF_LL;
		for(ll j=0;j<n;j++){
			if(i-c[j]<0 || dp[i-c[j]]==-1) continue; //we cant construct 
			if(dp[i-c[j]]<min) min=dp[i-c[j]];
		}
		if(min==INF_LL) dp[i]=-1;
		else dp[i] = min + 1;
	}

	if(dp[x]==0) cout<<"-1\n";
	else cout<<dp[x]<<"\n";
	

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