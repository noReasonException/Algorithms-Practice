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

/**
 * Simpler, Extra Space Solution
 */
vector<int>partition_extra_space(vector<int>arr,int pivot_index){
    vector<int> b(arr.size(),0);
    int l=0;
    int h=arr.size() -1;
    for (int i = 0; i < arr.size(); i++)
    {
        if(i==pivot_index) continue;
        if(arr[i]>arr[pivot_index]){
            b[h]=arr[i];
            h--;
        }
        else{
            b[l]=arr[i];
            l++;
        }
    }
    b[h]=arr[pivot_index];
    return b;
}
void swap(int i,int j,vector<int>&arr){
    int c = arr[j];
    arr[j]=arr[i];
    arr[i]=c;
}
vector<int> partition_no_extra_space(vector<int>&arr,int l,int h,int pivot_index){
    // int l=0;
    // int h=arr.size()-1;
    while(l<h){
        while(arr[l]<arr[pivot_index]&&l<h) l++;
        while(arr[h]>arr[pivot_index]&&l<h) h--;
        if(l<h) swap(l,h,arr);
        l++;
        h--;
    }

    return arr;
}

void quicksort_recv(vector<int>&arr,int l,int h){
    if(l>=h)return;
    int pivot = l;
    partition_no_extra_space(arr,l,h,l);
    
    quicksort_recv(arr,l,h/2);
    quicksort_recv(arr,h/2,h);

}
vector<int> quicksort(vector<int>arr){
    quicksort_recv(arr,0,arr.size());
}
void solve(){
	int n;
    cin>>n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    cout<<"pivot is "<<arr[0]<<"\n";
    cout<<"n is "<<n<<"\n";
    vector<int> pivoted1 = partition_extra_space(arr,0);
    
    for (int i = 0; i < n; i++)
    {
        cout<<pivoted1[i]<<" ";
    }
    vector<int> pivoted2 = partition_no_extra_space(arr,0,n-1,0);
    cout<<"\n";
    for (int i = 0; i < n; i++)
    {
        cout<<pivoted2[i]<<" ";
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
    while(t--){
        solve();
    }
	return 0;
}