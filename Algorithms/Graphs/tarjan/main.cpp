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

vector<vector<int>> adj;
vector<bool> visited;  
vector<int> pre;
vector<int> low;
vector<int> parent;
vector<vector<bool>> back_edge;
vector<pair<int,int>> back_edges;
int order=0;
int root = 0;
void dfs(int curr){
    
    cout<<curr+1<<" -> ";
    visited[curr]=true;
    pre[curr]=order++;
    low[curr] = pre[curr];
    for (auto &x:adj[curr]) {
        
        if(!visited[x]) {
            parent[x]=curr;
            dfs(x);
        }
        else{
            if(parent[curr]!=x)
                low[curr] = min(pre[curr],pre[x]);

            //detect back edges
            if(parent[curr]!=x && !back_edge[curr][x]){
                back_edge[curr][x] = true;
                back_edge[x][curr] = true;
                back_edges.push_back({curr,x});
            }
            
            
            
        }
    }
}

void solve(){
	ll n,l,s,t;
    cin>>n>>l;
    adj = vector<vector<int>>(n);
    back_edge = vector<vector<bool>>(n);
    for(auto &x:back_edge){
        x.reserve(n);
        fill(x.begin(),x.end(),0);
    }

    visited = vector<bool>(n,false);
    parent = vector<int>(n,-1);
    pre = vector<int>(n,-1);
    low = vector<int>(n,-1);
    for (ll i = 0; i < l; i++)
    {
        cin>>s>>t;
        s--;t--;
        adj[s].push_back(t);
        adj[t].push_back(s);
    }
    
    cout<<"\n";
    parent[root]=root;
    dfs(root);
    cout<<"\n\n";
    cout<<"Node\tPre\tLow\tLow Points to \n";
    for(int i=0;i<n;i++){
        const auto found = find(pre.begin(),pre.end(),low[i]);
        if(found==pre.end()){
            cout<<"Impossible\n";
        }
        cout<<i+1<<"\t"<<pre[i]<<"\t"<<low[i]<<"\t"<<*found + 1<<"\n";
        cout<<"----------------------------------\n";
    }
    cout<<"\n";
    cout<<"Node\tParent\t\n";
    for(int i=0;i<n;i++){
        cout<<i+1<<"\t"<<parent[i]+1<<"\t\n";
    }
    cout<<"\n";
    cout<<"Back Edges\n";
    cout<<"Source\tTarget\t\n";
    for(int i=0;i<back_edges.size();i++){
        cout<<back_edges[i].first+1<<"\t"<<back_edges[i].second+1<<"\n";
    }
    //Bridge Detection
    cout<<"\n";
    for(int s=0;s<n;s++){
        for(auto &t:adj[s]){
            if(pre[s]>low[t] && pre[s]<pre[t] && !back_edge[s][t]) cout<<"Bridge\t"<<s+1<<"\t"<<t+1<<"\t\n";            
        }
    }
    

    
    
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	

	solve();
	return 0 ;
}