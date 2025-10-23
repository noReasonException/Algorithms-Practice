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

vector<int>partition(vector<int>arr,int lo,int hi,int pivot){
    
}

vector<int>quicksort_recv(vector<int>arr,int lo,int hi){
    
	if(hi-lo==1){
        vector<int> answer;
		answer.push_back(arr[hi]);
	}
	int pivot = floor((lo+hi)/2);
	answer = partition(arr,lo,hi,pivot);
	quicksort_recv(arr,lo,pivot);
	quicksort_recv(arr,pivot,hi);
	return answer;

}

vector<int> quicksort(vector<int> arr){
    return quicksort_recv(arr,0,arr.size());
}

void solve(){
	int n;
    cin>>n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    vector<int> sorted = quicksort(arr);
    cout<<n<<"\n";
    for (int i = 0; i < n; i++)
    {
        cout<<sorted[i]<<" ";
    }
    cout<<"\n";
    
    
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

    int t;
    cin>>t;
    while(--t){
        solve();
    }

	// cout<<"start\n";
    // vector<int>left = {1,2,4,6,7};
    // vector<int>right = {3,4,5,9,10};
    // //1 2 3 4 4 5 6 7 9 10
	// vector<int>merged = merge(right,left);
    // debug(merged);
	return 0;
}