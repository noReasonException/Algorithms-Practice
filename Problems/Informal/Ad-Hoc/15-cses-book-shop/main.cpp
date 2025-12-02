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
    vector<vector<int>> dp(x+1,vector<int>(n+1,0));
    for(int i=0;i<n;i++)cin>>price[i];
    for(int i=0;i<n;i++)cin>>pages[i];

    cout<<"status of dp after \n";
    for(int i=2;i<x+1;i++){
        for(int j=2;j<n+1;j++){
            dp[i][j] = max(
                dp[i-price[j]][j] + pages[j],
                dp[i][j-1]
            );
        }
        cout<<"\n";
    }


    cout<<"status of dp before \n";
    for(int i=0;i<x+1;i++){
        for(int j=0;j<n+1;j++){
            cout<<dp[i][j]<<'\t';
        }
        cout<<"\n";
    }
    cout<<'\n';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	

	solve();
	return 0;
}