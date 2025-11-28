#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
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

vector<vector<ll>> adj;
vector<bool> visited;  
vector<ll> pre;
vector<ll> low;
vector<ll> parent;
vector<pair<ll,ll>> bridges;
ll order=0;
ll root = 0;


void tarjan(int curr){
    visited[curr]=true;
    pre[curr]=order++;
    low[curr] = pre[curr];
    for (auto &x:adj[curr]) {
        
        if(!visited[x]) { //Span edge
            parent[x]=curr;
            tarjan(x);
            low[curr] = min(low[curr],low[x]);
        }
        
        else{ //either parent OR back edge. 
            
            if(parent[curr]!=x){ //select only the span edge
                low[curr] = min(low[curr],low[x]);
            }
        }
    }
}

void solve(ll caso){
	ll v,e,s,t;
    cin>>v>>e;
    adj = vector<vector<ll>>(v);
    visited = vector<bool>(v,false);
    parent = vector<ll>(v,-1);
    pre = vector<ll>(v,-1);
    low = vector<ll>(v,-1);
    bridges = vector<pair<ll,ll>>();
    for (ll i = 0; i < e; i++)
    {
        cin>>s>>t;
        s--;t--;
        adj[s].push_back(t);
        adj[t].push_back(s);
    }
    
    parent[root]=root;
    tarjan(root);
    ll lo,hi;
    for(ll s=0;s<v;s++){
        for(auto &t:adj[s]){
            if(pre[s]<low[t]) {
                lo=min(s,t);
                hi=max(s,t);
                bridges.push_back(std::make_pair(lo,hi));
            }
        }
    }
    sort(bridges.begin(),bridges.end());
    cout<<"Caso #"<<caso<<"\n";
    if(bridges.empty()){
        cout<<"Sin bloqueos\n";
    }
    else{  
        cout<<bridges.size()<<"\n";
        for(auto each:bridges){

            cout<<each.first+1<<" "<<each.second+1<<'\n';
        }
    }
    
    
    

    
    
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    ll t;
    cin>>t;
    for (ll i = 0; i < t; i++)
    {
        solve(i+1);
    }
	

	
	return 0 ;
}