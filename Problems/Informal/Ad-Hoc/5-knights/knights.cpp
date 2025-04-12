#include <iostream>
#include <vector>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define b char

//forward refs
template <typename container> void cinfoCon(container& genericSequence,string id="None", int depth=0);

//debug utils
#ifdef DEBUG
	#define cinfo cout
	#define add <<
	template <typename container> void cinfoCon(container& genericSequence,string id, int depth){
		cout<<"=============cinfoCon Debug ("<<id<<") START =============\n";
		string prefix = "";
		for(int i=0;i<depth;i++) prefix+="\t";

		for(auto every: genericSequence){
			cout<<prefix<<every<<"\n";
		}
		cout<<"=============cinfoCon Debug ("<<id<<") END =============\n";

	}
#endif
#ifndef DEBUG
	#define cinfo ;
	#define add ;
	template <typename container> void cinfoCon(container& genericSequence,string id, int depth){
		return ;
	}

#endif


ull real_solve(ull k){
	ull all_ways = (k*k*(k*k-1))/2;
	ull attack = 0;
	for(ull i=0;i<k-2;i++){
		attack+=4+6+(4*(k-4));
	}
	//(k-4)*2+4
	attack+=(k-4)*2+4;
	return all_ways-attack;

}
/**
 *	Why?
*/
void solve(ull k){
	if(k==1){
		cout<<0;
	}
	else if(k==2){
		cout<<6;
	}
	else if(k==3){
		cout<<28;
	}
	else if(k==4){
		cout<<96;
	}
	else{
		cout<<real_solve(k);
	}
}
int main(){
	ull n;
	cin>>n;
	for(ull i=1;i<=n;i++){
		solve(i);
		cout<<"\n";
	}
	return 0;
}