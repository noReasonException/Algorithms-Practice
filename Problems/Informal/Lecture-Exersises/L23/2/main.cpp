#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
#define ll long long
#define ull unsigned long long

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

	//sort
	//find first i where a{n/2+i} != a{n/2}
	//start search from there, 

	//bounds : Low is n/2 + i , high is n

	auto state = [&arr,&n](ll i){
		ll cost=0;
		for (ull j = 0; j < i; j++)
		{
			//total cost of the state
			cost+=(arr[i] - arr[j]);
			
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
	//find first i where arr[n/2+i]!=arr[n/2];
	
	ll l=n/2,h=arr.size(),mid=0;
	//logn
	while(h-l>1){
		mid=(l+(h-l)/2);
		if(arr[mid]>arr[n/2]) h=mid;
		else l=mid;
	}
	int i = mid;
	if(i==arr.size()-1 && arr[n/2]==arr[i]){
		//is of kind 1 2 3 4 4 4 4
		//answer is k / (i - n/2);
		cout<<arr[n/2] + k/(i-n/2+1)<<'\n';
		return;
	}
	l=i;
	h = n;
	//nlogn
	while(h-l>1){
		mid=(l+(h-l)/2);
		if(state(mid)<=k) l=mid;
		else h=mid;
	}

	cout<<arr[mid]<<" with a cost of "<<state(mid)<<" leftover is "<<state(mid)-k<<'\n';

	


}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	

	solve();
	return 0;
}