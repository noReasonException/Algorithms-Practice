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

void print_instance(set<int> level,int l){
    //for(int i=0;i<l;i++)cout<<"\t";
    cout<<"{";
    for(auto each:level) cout<<each<<",";
    if(level.size()!=0)cout<<"\b";
    cout<<"}\n";
}

void recv_subsets(vector<int>& data,set<int> level,int level_index){
    print_instance(level,level_index);
    for(int i=level_index;i<data.size();i++){
        int each = data[i];
        if(level.find(each)==level.end()){
            set<int>advance_level = level;
            advance_level.insert(each);
            recv_subsets(data,advance_level,i);
        }
    }
}

void subsets(vector<int>& data){
    set<int> root ;

    recv_subsets(data,root,0);

}

//1. Given an integer 1 <= n <= 20, write a recursive algorithm that prints all the subsets of the set {1,2,3,...,n}.
void solve(int n){
    vector<int> s;
    for(int i=0;i<n;i++) s.push_back(i);

    for(auto each:s) cout<<each<<"\n";

    subsets(s);

    
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	
    
	int n;
	cin>>n;

    solve(n);
	return 0;
}