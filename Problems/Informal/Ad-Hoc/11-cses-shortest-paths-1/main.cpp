#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;
#define ll long long
#define PE pair<ll,ll>

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

//directed
void dijkstra(){
    ll inf = (ll)1e18+5;
    ll vertexes,edges,a,b,w;
    cin>>vertexes>>edges;
    vector<vector<pair<ll,ll>>> adjlist(vertexes);
    for (int i = 0; i < edges; i++)
    {
        cin>>a>>b>>w;
        --a;--b;
        adjlist[a].push_back(make_pair(w,b));
    }
    //solution
    vector<ll> d(vertexes,inf);
    d[0]=0;
    priority_queue<PE,vector<PE>,greater<PE>>  q;
    vector<bool>visited(vertexes,false);
    q.push(make_pair(0,0));
    while(!q.empty()){
        auto [distRoot,v] = q.top();q.pop();
        if(visited[v]) continue;
        visited[v]=true;
        for(auto [w,u]:adjlist[v]){
            if(d[u]>d[v]+w) {
                d[u]=d[v]+w;
                q.push(make_pair(d[v]+w,u));
            }
        }
    }
    for(auto each:d){
        cout<<each<<" ";
    }
    cout<<"\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    dijkstra();
	
	return 0;
}