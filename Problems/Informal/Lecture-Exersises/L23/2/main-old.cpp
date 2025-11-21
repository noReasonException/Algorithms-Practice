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
	vector<ll> arr;
	ll n,k,c;

	auto cost = [&arr,&n,&k](ll r){
		assert(r>=n/2);
		assert(r<n);
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
	//k-cost(n-1) is the leftover moves after we attempt to make the last (and max (its sorted)) element of the array the median
	//if the leftover cost is at least n/2 + 1 or more, we can increase the median by increasing the median and all the elements right of the median by at least one
	//example, 1 1 1 1 2 , k = 8 -> 1 1 2 2 2 , k = 6 -> 1 1 3 3 3 , k = 3 -> 1 1 4 4 4 , k = 0.
	if((k-cost(n-1))>=n-n/2){
		//the max possible median is 
		// 1. the arr[n-1] element (with cost equal to cost(n-1))
		// 2. how many times can we add one to every element in [n/2 , n-1] ? 
		// 		this is described by (k-cost(n-1)) / (n - n/2)
		//      n - n/2 != n/2 as we are dealing with integer division	
		cout<<arr[n-1]+(k-cost(n-1))/(n-n/2)<<"\n";
	}
	else if(cost(n/2 + 1)>k){
		cout<<arr[n/2]+k<<"\n";
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