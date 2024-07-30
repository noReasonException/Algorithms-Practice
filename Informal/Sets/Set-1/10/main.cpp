#include <iostream>

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
 *	1. Maximum : Everyone in a single team, everyone else in isolation
 * 		1.1 Isolated teams do not form friendships
 * 	3[D]. Minimum: Everyone evenly spaced to all of the teams plus the last team with leftovers
 * 		3.1 n/m is the number of players per team
 * 		3.2 m are the teams
 * 		3.3 last team with leftovers
 * 			
 * 				Every team : (m-1) * choose2(floor(n/(m-1))) 
 * 				Last team, remaining players choose 2
 * 							(n - (m-1)*floor(n/(m-1)))
 * 				
*/


//(N choose 2) simplified, avoiding to calculate the whole number as it will overflow
int choose2(int n){
	return (n*(n-1))/2;
}

int main(){
	int n,m;
	int k=0;
	int l=0;
	cin>>n>>m;
	
	//min - max





	cout<<(m-1) * choose2(floor(n/m)) + choose2(n-(m-1)*floor(n/m))<<" "<<choose2(n-m+1);

	return 0;
}