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
	ll n,curr;
	cin>>n;
	ll max=-1;
	ll steps = 0;

	while(n!=0){
		// cout<<"No is "<<n<<"\n";
		curr=n;
		max=-1;
		while(curr!=0){
			// cout<<"\t"<<curr%10<<"\t";
			if(max<curr%10)max=curr%10;
			curr/=10;

		}
		// cout<<"\n\tMax is "<<max<<"\n";
		n-=max;
		steps++;
		
	}
	
	cout<<steps<<'\n';
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