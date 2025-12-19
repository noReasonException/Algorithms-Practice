#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
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

int done(vector<int>&a){
    /*done is 
        either all same : result is 'depth', return 0
        increasing/decreasing :result is 'depth' + size() , return 'size()' -> i dont have a good proof for it, do i will omit it for now

        return -1 if not done
    */
   bool identical=true;
//    bool monotonicI=true;
//    bool monotonicD=true;
   if(a.size()<2) return 0;
   int prev = a[0];
   for (int i = 1; i < a.size(); i++){
        //if(prev>a[i])monotonicI=false;
        //if(prev<a[i])monotonicD=false;
        if(a[i]!=prev) {
            identical=false;
        }
        prev=a[i];
   }
   if(identical) return 0;
   //else if(monotonicD||monotonicI) return a.size()-1;
   else return -1;
}
vector<vector<int>> gen_states(vector<int>&a,int depth){
    vector<vector<int>>states;
    if(a.size()<2) return states;
    if(a[a.size()-1]<=a[0]){
        vector<int>stateRemoveFirst(a.begin()+1,a.end());
        vector<int>stateRemoveLast(a.begin(),a.end()-1);
        states.push_back(stateRemoveFirst);
        states.push_back(stateRemoveLast);
    }
    for (int i = 1; i < a.size(); i++){
       if(a[i-1]<=a[i]){
            vector<int>stateRemovePrevious(a.begin(),a.end());
            vector<int>stateRemoveLatter(a.begin(),a.end());
            stateRemovePrevious.erase(stateRemovePrevious.begin()+i-1);
            stateRemoveLatter.erase(stateRemoveLatter.begin()+i);
            states.push_back(stateRemovePrevious);
            states.push_back(stateRemoveLatter);
       }
    }
    return states;
}
int solution(vector<int>&a,int depth){
    int isDone = done(a);
    std::stringstream ab;
    if(isDone>=0) return isDone+depth;
    else{
        vector<vector<int>> states = gen_states(a,depth);
        vector<int> results;
        for(auto each:states){
            results.push_back(solution(each,depth+1));
        }
        std::sort(results.begin(),results.end());
        return results[0];
    }
    return -1; //this is an impossible state;
    
}

void solve(){
	int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin>>a[i];
    cout<<solution(a,0)<<"\n";
    
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