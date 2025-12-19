#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
#define ll 		long long
#define ull 	unsigned long long
#define ld 		long double
#define MOD  	pow(10,9)+7;
#define INF_INT	(1<<30)
#define INF_LL 	(1L<<62)
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

void _dfs(int n,int s,vector<vector<int>>&adjlist,vector<bool>& visited){
	
	//cause --a;--b;
	cout<<s+1<<"\n";
	visited[s]=true;
	for(auto next:adjlist[s]){
		if(!visited[next]) _dfs(n,next,adjlist,visited);
	}
}
void dfs(int n,int s,vector<vector<int>>&adjlist){
	vector<bool>visited(n,false);
	_dfs(n,0,adjlist,visited);
}

//undirected
void solve(){
    ll n,edges,a,b;
    cin>>n>>edges;
    vector<vector<int>> adjlist(n);
    for (int i = 0; i < edges; i++)
    {
        cin>>a>>b;
        --a;--b;
        adjlist[a].push_back(b);
    }
    //solution
}
// //directed
// void solve(){
//     ll n,edges,a,b,c;
//     cin>>n>>edges;
//     vector<vector<pair<int,int>>> adjlist(n);
//     for (int i = 0; i < edges; i++)
//     {
//         cin>>a>>b>>c;
//         --a;--b;
//         adjlist[a].push_back(make_pair(b,c));
//     }
//     //solution
// }


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