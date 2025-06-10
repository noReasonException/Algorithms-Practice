#include <iostream>
#include <vector>
using namespace std;

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


int bin_search(int l,int h,vector<int> &v,int key){
    
    int m = floor((l+h)/2);
    
    if(v[m]==key){
        return m; //found
    }
    else if(l>=h){
        return -1;//not found
    }
    else if(key<v[m]){
        return bin_search(l,m,v,key);
    }
    else{
        return bin_search(m,h,v,key);
    }
}



void solve(){
	vector<int> test = {1,2,3,4,5,6};

    cout<<bin_search(0,test.size(),test,6)<<"\n";


}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	
    solve();
	// int n;
	// cin>>n;
	// while(n--)solve();
	return 0;
}