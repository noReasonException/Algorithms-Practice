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
int solve(){
    string dna;
    cin>>dna;
	if(dna.size()==1) return 1;
	ll answer=0,curr_best=1;
	char curr=dna[0];
	for(int i=1;i<dna.size();i++){
		if(dna[i]==curr) {
			curr_best++;
		}
		else {
			if(answer<curr_best) answer=curr_best;
			curr_best=1;
			curr=dna[i];

		}
	}
	if(curr_best>answer) answer=curr_best;
	return answer;
	

	
    
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	cout<<solve();
	return 0;
}