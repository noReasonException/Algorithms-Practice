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
void solve(){
    int n,m;
    int e1,e2;
	cin>>n>>m;
    vector<vector<int>> v(n);
    vector<bool>visited(n);
    vector<int> disjoint_component_root;
    for(int i = 0 ; i<m;i++){
        cin>>e1>>e2;
        --e1,--e2;
        v[e1].push_back(e2);
        v[e2].push_back(e1);
    }
    auto dfs = [&](auto &&self,int u) -> void{
        visited[u] = true;    
        for(auto &w:v[u]){
            if(!visited[w]){
                self(self,w);
            }
        }
    };
    for(int i=0;i<n;i++){
        if(!visited[i]){
            disjoint_component_root.push_back(i);
            dfs(dfs,i);
        }
    }
    cout<<(disjoint_component_root.size()-1)<<"\n";
    for(int i=0;i<disjoint_component_root.size()-1;i++){
        cout<<disjoint_component_root[i]+1<<" "<<disjoint_component_root[i+1]+1<<"\n";
    }
    


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