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

vector<int>merge(vector<int>left,vector<int>right){
    int left_index=0,right_index=0;
    int left_size = left.size();
    int right_size = right.size();
    vector<int> answer;
    while(left_index<left_size && right_index<right_size){
        if(left[left_index]<right[right_index]){
            answer.push_back(left[left_index]);
            left_index+=1;
        }
        else if (left[left_index]>right[right_index]){
            answer.push_back(right[right_index]);
            right_index+=1;
        }
        else/*equal*/{
            answer.push_back(right[right_index]);
            answer.push_back(right[right_index]);
            right_index+=1;
            left_index+=1;
        }
    }
    for (; left_index<left_size; left_index++){
        answer.push_back(left[left_index]);
    }
    for (; right_index<right_size; right_index++){
        answer.push_back(right[right_index]);
    }
    return answer;
}

vector<int>mergesort_recv(vector<int>arr,int lo,int hi){
    //cout<<"lo "<<lo<<" hi "<<hi<<"\n";
    vector<int> answer;
    int mid;
    if(hi-lo<=1) {
        answer.push_back(arr[lo]);
        return answer;
    }
    mid=floor((lo+hi)/2);
    vector<int> left = mergesort_recv(arr,lo,mid);
    vector<int> right = mergesort_recv(arr,mid,hi);
    answer = merge(left,right);
    return answer;

}

vector<int> mergesort(vector<int> arr){
    return mergesort_recv(arr,0,arr.size());
}

void solve(){
	int n;
    cin>>n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    vector<int> sorted = mergesort(arr);
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