#include <iostream>
#include <vector>
#include <queue>

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
void solve(){
	ll n,e,s,t;
	cin>>n>>e;

	vector<vector<int>> adj(n);
	for (ll i = 0; i < e; i++)
	{
		cin>>s>>t;
		--s;--t;
		adj[s].push_back(t);
	}

	for (ll i = 0; i < n; i++)
	{
		for (ll j = 0; j < adj[i].size(); j++)
		{
			cout<<i+1<<"-"<<adj[i][j]+1<<"\n";
		}
		
	}
	ll curr=0;
	vector<int> d(n,-1);
	queue<ll> q;
	vector<ll> visited(n,false);
	//let 0 be the root
	q.push(0);
	d[0]=0;
	while(!q.empty()){
		curr=q.front();q.pop();
		for(auto &next:adj[curr]){
			if(!visited[next]){
				visited[next]=true;
				q.push(next);
				d[next]=d[curr]+1;
			}
		}
	}

	for (ll i = 0; i < n; i++)
	{
		cout<<"Node "<<i+1<<" distance "<<d[i]<<" from root\n";
	}
	
	
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	

	solve();
}