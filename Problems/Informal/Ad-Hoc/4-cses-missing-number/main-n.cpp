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
	long long n;
	cin >> n;
	long long expected = (n*(n+1)/2) ;
	long long sum = 0;
	long long tmp = 0;
	for(int i=0;i<n-1;i++){
		cin>>tmp;
		sum+=tmp;
	}
	cout<<expected-sum;
}
 
int main(){
	solve();
	cout<<"\n";
	
}