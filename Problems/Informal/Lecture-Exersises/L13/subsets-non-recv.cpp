#include <iostream>
#include <vector>
#include <set>
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

//1. Given an integer 1 <= n <= 20, write a recursive algorithm that prints all the subsets of the set {1,2,3,...,n}.

void print_instance(set<int> level){
    cout<<"{";
    for(auto each:level) cout<<each<<",";
    if(level.size()!=0)cout<<"\b";
    cout<<"}\n";
}

void solve(int n){
    
    set<int> s ;
    int mask = 0;
    for(int i=0;i<n;i++){
        mask=pow(2,i);
        if(n&mask){
            s.insert(i);
        }
    }

    print_instance(s);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
    for(int i=0;i<pow(2,n);i++){
        solve(i);
    }
	return 0;
}