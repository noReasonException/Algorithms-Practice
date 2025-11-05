#include <iostream>
#include <vector>
#include <set>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ld long double

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


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	ull n,t,m;
	cin>>n>>t;
	ull x=0;
	vector<ull> arr; 

	for (ull i = 0; i <  n; i++)
	{

		cin>>m;
		arr.push_back(m);
	}

	auto predicate = [](vector<ull> &arr,ull n,ull target,ull n){
		ull sum=0;
		for (ull i = 0; i < n; i++)
		{
			sum+=secs/arr[i];
			if(sum>=target) return true;
		}
		return false;
	};
	ull l=0,h=1e18,mid=0;
	while(h-l>1){
		mid = l + (h-l)/2;
		if(predicate(arr,mid,t,n))h = mid;
		else l = mid;
	}
	cout<<h<<'\n';
	return 0;
	
}