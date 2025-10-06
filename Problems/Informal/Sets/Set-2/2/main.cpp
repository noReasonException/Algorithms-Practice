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
	ll a1,a2,b1,b2;
	int games=0;
	cin>>a1>>a2>>b1>>b2;
	



	if(a1>b1&&(a2>=b2)) games+=1;
	if(a1==b1&&(a2>b2)) games+=1;
	if(a1>b2&&(a2>=b1)) games+=1;
	if(a1==b2&&(a2>b1)) games+=1;
	if(a2>b1&&(a1>=b2)) games+=1;
	if(a2==b1&&(a1>b2)) games+=1;
	if(a2>b2&&(a1>=b1)) games+=1;
	if(a2==b2&&(a1>b1)) games+=1;

	



	return games;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	

	int n;
	cin>>n;
	while(n--) cout<<solve()<<"\n";
	return 0;
}