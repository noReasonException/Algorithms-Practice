#include <iostream>
#include <algorithm>
#include <vector>
#include <assert.h>
using namespace std;
#ifdef DEBUG
	#define cinfo cout
	#define add <<
#endif
#ifndef DEBUG
	#define cinfo ;
	#define add ;
#endif
 
 
/**
 *	Why?
*/
void solve(){
	int n;
	int nsize;
	int temp;
	cin >> n;
 
	nsize=n-1;
	vector<int> inp(nsize);
 
	for(int i=0;i<nsize;i++){
		cin >> inp[i];
	}
 
 
	sort(inp.begin(),inp.end());
 
 
	if(inp[0]!=1){
		cout<<1;
		return;
	}
	if(inp[nsize-1]!=n){
		cout<<n;
		return;
	}
 
	for(int i=1;i<nsize;i++){
		if(inp[i]-inp[i-1]!=1) {
			cout<<inp[i] - 1;
			return;
		}
	}
	
 
	assert(1!=1);
 
 
	
}
 
int main(){
	solve();
	
}