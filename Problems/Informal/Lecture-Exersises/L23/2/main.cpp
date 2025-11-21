#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
#define ll long long
#define ull unsigned long long
#include <cassert>
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
	vector<int> arr;
	int n,k,c;

	auto cost = [&arr,&n,&k](ll r){
		assert(r>=n/2);
		ll cost=0;
		for (ll i = n/2; i < r; i++)
		{
			//total cost to make arr[r] the new median
			cost+=(arr[r] - arr[i]);
			
		}
		return cost;
	};
	//read data
	cin>>n;
	cin>>k;
	for (ll i = 0; i < n; i++)
	{
		cin>>c;
		arr.push_back(c);
	}
	//sort data
	sort(arr.begin(),arr.end());
	ll l=n/2,h=n,mid=0;
	
	
	if(k-cost(n-1)>=n/2){
		//leftovers should exist
		// arr[h] is the last element of the array, which is our next median
		// (k-state(n-1)) are the spent cost to get there
		// floor((k-state(n-1))/(n/2)) is the amount of extra additions we can make to our median without violating the cost
		cout<<arr[n-1]+(k-cost(n-1))/((n/2)+1)<<"\n";
	}
	else{
		while(h-l>1){
			mid=l+(h-l)/2;
			if(cost(mid)<=k) l=mid;
			else h=mid;
		}	
		cout<<arr[l]<<"\n";
	}
	
	


}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	

	solve();
	return 0;
}