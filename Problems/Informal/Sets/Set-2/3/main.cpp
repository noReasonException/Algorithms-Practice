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
	int n;
	cin >> n;
	int ah,al,bh,bl,same=0;
	vector<int> alice(n,0), bob(n,0), alice_indexes(n+1,0), bob_indexes(n+1,0);
	alice_indexes[0]=-1;
	bob_indexes[0]=-1;
	ah=bh=n-1;
	al=bl=0;
	for (int i = 0; i < n; i++)
	{
		cin>>alice[i];
		alice_indexes[alice[i]]=i;
	}
	for (int i = 0; i < n; i++)
	{
		cin>>bob[i];
		bob_indexes[bob[i]]=i;
		if(bob[i]==alice[i]) same+=1;
	}
	if(same==n){
		cout<<"Bob\n";

	}
	else{
		for(int i=0;i<n-1;i++){
			//Alice
			if(alice[ah]!=bob[bh] && alice[al]==bob[bl]) al+=1;
			else if(alice[ah]==bob[bh] && alice[al]!=bob[bl]) ah-=1;
			else if(alice[ah]==bob[bh] && alice[al]==bob[bl]) {
				//worst case schenario for alice
				//choose worst for bob

			}
			else/* Both different */ {

			}


			//Bob
			if(alice[ah]!=bob[bh] && alice[al]==bob[bl]) bh-=1;
			else if(alice[ah]==bob[bh] && alice[al]!=bob[bl]) bl+=1;
			else if(alice[ah]==bob[bh] && alice[al]==bob[bl]) {
				//best case schenario for bob
				//choose worst for alice

			}
			else/* Both different */ {

			}

		}
	}
	
	debug(alice);
	debug(alice_indexes);
	debug(bob);
	debug(bob_indexes);


	
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