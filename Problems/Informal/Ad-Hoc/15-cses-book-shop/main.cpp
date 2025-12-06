#include <iostream>
#include <vector>
#include <set>
using namespace std;
#define ll long long

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
	int n,x;
    cin>>n>>x;
    vector<int>price(n,0);
    vector<int>pages(n,0);
    vector<vector<int>> dp(n+1,vector<int>(x+1,0));
    for(int i=0;i<n;i++)cin>>price[i];
    for(int i=0;i<n;i++)cin>>pages[i];

    cout<<"status of dp \n";
    for(int i=0;i<n+1;i++){
        for(int j=0;j<x+1;j++){
            cout<<dp[i][j]<<"\t";
        }
        cout<<"\n";
    }
    //i is the books
    //j is the capacity
    for(int i=1;i<n+1;i++){
        for(int j=1;j<x+1;j++){
            //if we reached out of capacity
            if(j>x) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(
                dp[i-1][j-1],
                dp[i-1][j]+
            )
        
        }
        cout<<"\n";
    }
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	

	solve();
	return 0;
}