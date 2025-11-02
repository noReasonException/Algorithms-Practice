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
bool solve(int t){
	int n,prev,curr;
	cin>>n;
	cin>>prev;
	bool valid_solution=true;
	vector<int> v(n);
	for (int i = 1; i < n; i++)
	{
		cin>>curr;
		v[i]=curr;
		if(prev>curr) {
			cout<<"testcase "<<t<<" failed on "<<i<<"\n";
			valid_solution=false;
		}
		prev=curr;
	}
	if(!valid_solution) debug(v,"Invalid solution",0);
	return valid_solution;
	
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	

	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		if(!solve(t)){
			cout<<"Testcase "<<i<<" failed!\n";
			break;
		}
	}
	cout<<"All testcases passed\n";
	return 0;
}