#include <iostream>
#include <vector>
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
//n Size, s Start, adjlist : Adjacent List
void _dfsv1(int n,int s,vector<vector<int>>&adjlist,vector<bool>& visited){
	if(visited[s]) return;
	//cause --a;--b;
	cout<<s+1<<"\n";
	visited[s]=true;
	for(auto next:adjlist[s]){
		_dfsv1(n,next,adjlist,visited);
	}
}
void _dfsv2(int n,int s,vector<vector<int>>&adjlist,vector<bool>& visited){
	
	//cause --a;--b;
	cout<<s+1<<"\n";
	visited[s]=true;
	for(auto next:adjlist[s]){
		if(!visited[next]) _dfsv2(n,next,adjlist,visited);
	}
}
void dfs_recv(int n,int s,vector<vector<int>>&adjlist){
	vector<bool>visited(n,false);
	_dfsv2(n,0,adjlist,visited);
}
void dfs_stack(int n,int s,vector<vector<int>>&adjlist){
	vector<bool>visited(n,false);
	stack<pair<int,int>> state;
	int root = s;
	do{
		visited[root]=true;
		cout<<root+1<<"\n";
		for(auto each:adjlist[root]){
			
			if(!visited[each]){
				state.push(make_pair(root,each));
			} 
		}
		if(state.empty()) break;
		root = state.top().second;
		state.pop();

	}while(1);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    ll n,edges,a,b;
    cin>>n>>edges;
    vector<vector<int>> adjlist(n);
    for (int i = 0; i < edges; i++)
    {
        cin>>a>>b;
        --a;--b;
        adjlist[a].push_back(b);
    }

	dfs_recv(n,0,adjlist);
	cout<<"---\n";
	dfs_stack(n,0,adjlist);
    

	

	
	return 0;
}