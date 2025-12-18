#include <iostream>
#include <vector>
#include <set>
#include <math.h>
#define ll long long
#define MOD   ((ll) pow(10,9)+7);

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
	int sum,tmp;
	cin>>sum;
	vector<int> dp(sum+1,0);
	for(int j = 1;j<sum+1;j++){
		tmp=(j>=1 && j<=6);
		for(int i=1;i<=6;i++){
			if(j-i>=0){
				tmp = (tmp + dp[j-i]) % MOD;
			}
		}
		dp[j] = tmp;
	}
	cout<<dp[sum]<<"\n";
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