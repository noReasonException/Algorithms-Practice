#include <iostream>
#include <set>
#include <vector>
#include <sstream>
#include <algorithm> 
using namespace std;



int refl(int index,int size){
	int half = size%2?((size-1)/2):(size/2);
	if(index<half) return size-1-index;
	else return half-(index-half)-(!(size%2));
}
/**
 * 		1. Removed unessesary set initialization - used containers instead
 * 		2. Removed extra overhead from sstream
 * 		3. query on set only and not on vector : from n^2 to nlog(n)
 */ 
void solve(){
	int size;
	string s;
	cin>>size;
	cin>>s;

	set<char> rset(s.begin(),s.end());
	vector<char>r(rset.begin(),rset.end());

	int curr_index,refl_index;
	for(int i=0;i<size;i++){
		//the index of this character into r
		curr_index = distance(rset.begin(),rset.find(s[i]));
		refl_index = refl(curr_index,rset.size());
		cout<<r[refl_index];
	}
	cout<<"\n";
}

int main(){
	int size;
	cin>>size;
	while(size--) solve();
	cout<<"\n";
}