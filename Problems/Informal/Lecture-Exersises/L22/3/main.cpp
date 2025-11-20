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
    int qsize = (hi-lo)/3;
    int msize = (hi-lo)%3; //max branch size difference is +- 2, therefore a constant

    for (int i = 0; i < d; i++)
    {
        cout<<"\t";
    }

    if(qsize==0){
        //mod is either 1 or 2 (or 0 which is impossible, as our base cases are either 1 or 2)
        //for 1 its base case
        //for 2 , is a base case with 2 single-element arrays
        
        if(msize==1){
            // 1, base case
            cout<<" Base case 1 "<<lo<<"\n";
            vector<int> answer;
            answer.push_back(arr[lo]);
            return answer;
        }
        else if (msize==2){
            //2, 
            cout<<" Base case 2 "<<lo<<"-"<<lo+1<<"-"<<hi<<"\n";
            vector<int> left;
            vector<int> right;
            left.push_back(arr[lo]);
            right.push_back(arr[lo+1]);
            vector<int> result = merge(left,right);
            return result;
        }
        else{
            cout<<"impossible\n";
        }
    }else{
        cout<<" "<<qsize<<"/"<<msize<<" -> "<<lo<<"-"<<lo+qsize<<"-"<<"-"<<lo+2*qsize<<"-"<<hi<<"\n";
        vector<int> left = mergesort_recv2(arr,lo,lo+qsize,d+1);
        vector<int> center = mergesort_recv2(arr,lo+qsize,lo+2*qsize,d+1);
        vector<int> right = mergesort_recv2(arr,lo+2*qsize,hi,d+1);
        vector<int> merge1 = merge(left,center);
        vector<int> merge2 = merge(merge1,right);
        return merge2;
    }
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