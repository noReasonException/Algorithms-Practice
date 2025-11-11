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

vector<int>mergesort_recv(vector<int>arr,int lo,int hi,int d=0){

    vector<int> answer;
    int mid;

    if(hi-lo<=1) {
        answer.push_back(arr[lo]);
        return answer;
    }
    
    mid=floor((lo+hi)/2);

    vector<int> left = mergesort_recv(arr,lo,mid,d+1);
    vector<int> right = mergesort_recv(arr,mid,hi,d+1);
    answer = merge(left,right);
    return answer;

}
vector<int>mergesort_recv2(vector<int>arr,int lo,int hi,int d=0){

    if(hi-lo<=1) {
        vector<int> answer;
        answer.push_back(arr[lo]);
        return answer;
    }

    int size = hi-lo;
    int q1 = size*(0.3);
    int q3 = size*(0.6);

    for (int i = 0; i < d; i++)
    {
        cout<<"\t";
    }
    cout<<lo<<"-"<<lo+q1<<"-"<<"-"<<lo+q3<<"-"<<hi<<"\n";
    
    vector<int> left = mergesort_recv2(arr,lo,lo+q1,d+1);
    vector<int> center = mergesort_recv2(arr,lo+q1,lo+q3,d+1);
    vector<int> right = mergesort_recv2(arr,lo+q3,hi,d+1);

    if(q1==0){
        //for single-element arrays, we always return arr[lo]
        //every array will end up being single-element, and said element will be returned
        //if q1==0 means that left will return arr[lo]
        //also if q1==0 means that center will eventually also return arr[lo]
        //this results in arrays with duplicates, this condition stabilises that
        //this is not a thing on classic mergesort due to the rounding of lo and hi, arr[lo] element goes only on one branch of the tree.
        vector<int> merge1 = merge(center,right);
        return merge1;    
    }
    
    vector<int> merge1 = merge(left,center);
    vector<int> merge2 = merge(merge1,right);
    return merge2;

}

vector<int> mergesort(vector<int> arr){
    return mergesort_recv(arr,0,arr.size());
}
vector<int> mergesort2(vector<int> arr){
    return mergesort_recv2(arr,0,arr.size());
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
    vector<int> sorted2 = mergesort2(arr);
    cout<<n<<"\n";
    for (int i = 0; i < n; i++)
    {
        cout<<sorted[i]<<" ";
    }
    cout<<"\n";
    for (int i = 0; i < n; i++)
    {
        cout<<sorted2[i]<<" ";
    }
    cout<<"\n";
    
    
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

    int t;
    cin>>t;
    while(t--){
        solve();
    }
	return 0;
}