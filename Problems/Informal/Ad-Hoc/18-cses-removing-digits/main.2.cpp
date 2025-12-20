#include <iostream>
#include <vector>
#include <set>
#include <math.h>
#define ll 			long long
#define MOD  		pow(10,9)+7;
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
	ll n,curr,digit,min;
	cin>>n;
	vector<ll> dp(n+1,0);
	for (int i = 1; i < 10; i++) dp[i]=1;
	
	for(int i=10;i<n+1;i++){
		min=INF_LL;
		curr=i;
		while(curr!=0){
			digit=curr%10;
			if(dp[i-digit]<min && digit!=0)min=dp[i-digit];
			curr/=10;
		}
		dp[i]=min+1;
	}
	cout<<dp[n]<<"\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	

	solve();
	return 0;
}