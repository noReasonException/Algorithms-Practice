#include <iostream>
#include <vector>
#include <set>
#include <sstream>
using namespace std;
#define ll long long

//forward refs
template <typename container> void debug(container& genericSequence,string id="None", int depth=0);
void debug_str(string info,string,int depth);


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
    void debug_str(string info, int depth){
        string prefix = "";
        for(int i=0;i<depth;i++) prefix+="\t";
        cout<<prefix<<info<<"\n";
    }

#endif
#ifndef DEBUG
	template <typename container> void debug(container& genericSequence,string id, int depth){
		return ;
	}
    void debug_str(string info, int depth){
        return ;
    }

#endif

/**
 * Simpler, Extra Space Solution
 * Reason on why we dont use this version:
 *  1. Objectively good reason: Uses extra space
 *  2. Personal bullshit reasons: It is extremely convinient for the partition function to return the position of the
 *         new pivot. This function does not perform swaps, it returns a new array
 *         we need to RETURN the new array PLUS the pivot index, so to we need a struct with the 
 *         new array + the pivot and blah blah blah move constructors blah blah
 *
 *         >>  yes, we could use global vectors, 
 *                  but every fundamental particle of my body resists that idea
 *                  i dont judge though  <<
 * 
 *   Therefore: Anyway, use the more performant version instead
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
    b[l]=arr[pivot_index];
    return b;
}
void swap(int i,int j,vector<int>&arr){
    if(i==j)return;
    int c = arr[j];
    arr[j]=arr[i];
    arr[i]=c;
}
int partition_no_extra_space(vector<int>&arr,int l,int h,int pivot_index){
    
    //you could just select always the first, with simpler initialization
    int lo=l;
    swap(lo,pivot_index,arr); //nessesary to select an arbitary pivot
    pivot_index=lo;
    l+=1;
    while(l<=h){
        while(arr[l]<arr[pivot_index]&&l<=h) l++;
        while(arr[h]>arr[pivot_index]&&l<=h) h--;
        if(l<=h) {
            swap(l,h,arr);
            l++;
            h--;
        }
    }
    swap(lo,h,arr);
    return h;
}

void quicksort_recv(vector<int>&arr,int l,int h){
    
    int pivot_index;
    if(l>=h)return;
    pivot_index = l;    //choose pivot, always the first element
    pivot_index = partition_no_extra_space(arr,l,h,pivot_index); //new pivot position

    quicksort_recv(arr,l,pivot_index-1);
    quicksort_recv(arr,pivot_index+1,h);

}
vector<int> quicksort(vector<int>&arr){
    quicksort_recv(arr,0,arr.size()-1);
    return arr;
}
void solve(){
	int n;
    cin>>n;
    vector<int> arr(n,0);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    quicksort(arr);
    cout<<n<<"\n";
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    
    
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

    //output to conform to judge's input
    int t;
    cin>>t;
    cout<<t<<"\n";
    while(t--){
        solve();
    }
	return 0;
}