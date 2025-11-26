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
int order=0;
int root = 0;


void tarjan(int curr){
    cout<<curr+1<<" -> ";
    visited[curr]=true;
    pre[curr]=order++;
    low[curr] = pre[curr];
    for (auto &x:adj[curr]) {
        
        if(!visited[x]) {
            //Span edge
            parent[x]=curr;
            tarjan(x);
            low[curr] = min(low[curr],low[x]);
        }
        //visited
        else{
            //Not your parent
            if(parent[curr]!=x){
                low[curr] = min(low[curr],low[x]);
            }
            //Your parent
            else{
                // ignore;
            }
        }
    }
}

void solve(){
	ll n,l,s,t;
    cin>>n>>l;
    adj = vector<vector<int>>(n);
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
    tarjan(root);
    cout<<"\n\n";
    cout<<"Node\tPre\tLow\tLow points to node\n";
    for(int i=0;i<n;i++){
        const auto found = find(pre.begin(),pre.end(),low[i]);
        cout<<i+1<<"\t"<<pre[i]<<"\t"<<low[i]<<"\t"<<*found + 1<<"\n";
        cout<<"----------------------------------------------\n";
    }
    cout<<"\n";
    cout<<"Node\tParent\t\n";
    for(int i=0;i<n;i++){
        cout<<i+1<<"\t"<<parent[i]+1<<"\t\n";
    }
    //Bridge Detection
    cout<<"\n";
    for(int s=0;s<n;s++){
        for(auto &t:adj[s]){
            if(pre[s]<low[t]) cout<<"Bridge\t"<<s+1<<"\t"<<t+1<<"\t\n";            
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