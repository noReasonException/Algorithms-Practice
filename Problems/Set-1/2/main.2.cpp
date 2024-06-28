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
 * 		3. from nlog(n) to plain n with a constant initialization;
 */ 
void solve(){
	int size;
	string s;
	cin>>size;
	cin>>s;

	set<char> rset(s.begin(),s.end());
	vector<char>r(rset.begin(),rset.end());
	char map[26] = {'?'};
	
	int curr_index,refl_index,map_index;
	for(int i=0;i<26;i++){
		int find = distance(rset.begin(),rset.find('a'+i));
		if(find==size) continue; //character not used
		refl_index = refl(find,rset.size());
		map[i] = r[refl_index];
		//cout<<char('a'+i)<<"->"<<map[i]<<endl;
	}

	for(int i=0;i<size;i++){
		map_index = (char)s[i] - 'a';
		cout<<(char)map[map_index];
	}
	cout<<endl;
}

int main(){
	int size;
	cin>>size;
	while(size--) solve();
	cout<<"\n";
}