#include <iostream>
#include <set>
#include <vector>
#include <sstream>
#include <algorithm> 
#define SYMBOLS 26
using namespace std;



int refl(int index,int size){
	int half = size%2?((size-1)/2):(size/2);
	if(index<half) return size-1-index;
	else return half-(index-half)-(!(size%2));
}
void solve(){
	int size;
	string s;
	cin>>size;
	cin>>s;

	set<char> rset(s.begin(),s.end());
	vector<char>r(rset.begin(),rset.end());
	char map[SYMBOLS];
	
	//initialize symbols map
	for(int i=0;i<SYMBOLS;i++)map[i]='?';
	
	//
	int curr_index,refl_index,map_index;
	for(int i=0;i<s.size();i++){
		map_index = ((char)s[i]) - 'a';
		if(map[map_index]=='?'){
			int find = distance(rset.begin(),rset.find(s[i]));
			//find != end , definitely exists
			refl_index = refl(find,rset.size());
			map[map_index] = r[refl_index];
		}
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