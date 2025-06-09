#include <iostream>
#include <vector>
using namespace std;

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


int pow_trivial(int x,int n){
    long long result = 1;
	if(n==0) return 1;
	if(x==0&&n!=0) return 0;
	for(;n>=1;n--)result*=x;
	return result;
}
//(x^n/2)*(x^n/2)
//x*x^(n-1)
int pow_unbalanced_fast(int x,int n){
	long long acc;
	if(n==1) return x;
	if(n==0||x==1) return 1;
	if(x==0&&n!=0) return 0;
	if(x==0&&n==0) return -1;
	if(n%2==0){
		acc = pow_unbalanced_fast(x,n/2);
		return acc*acc;
	}
	else{
		acc = pow_unbalanced_fast(x,n-1);
		return x*acc;
	}
}
//(x^n/2)*(x^n/2)
//x*x^(⌊n/2⌋)*x^(⌊n/2⌋)
int pow_balanced_fast(int x,int n){
	long long acc;
	if(n==1) return x;
	if(n==0||x==1) return 1;
	if(x==0&&n!=0) return 0;
	if(x==0&&n==0) return -1;
	if(n%2==0){
		acc = pow_balanced_fast(x,n/2);
		return acc*acc;
	}
	else{
		acc = pow_balanced_fast(x,floor(n/2));
		return x*acc*acc;
	}
}
//(x^n/2)*(x^n/2)
//x*x^(⌊n/2⌋)*x^(⌊n/2⌋)
int pow_balanced_fast_refined(int x,int n){
	long long acc;
	if(n==1) return x;
	if(n==0||x==1) return 1;
	if(x==0&&n!=0) return 0;
	if(x==0&&n==0) return -1;
	acc = pow_balanced_fast(x,floor(n/2));
	return acc*acc*((n&1)!=0?x:1);
}

int pow_fued_up(int x,int n){
	long long acc;
	if(n==1) return x;
	if(n==0||x==1) return 1;
	if(x==0&&n!=0) return 0;
	if(x==0&&n==0) return -1;
	//n/2 is floored bc n is int
	acc = pow_balanced_fast(x,(n/2));
	return acc*acc*((n&1)!=0?x:1);
}





void solve(){
	vector<int> test = {12,11,9,6,5,4,7,1};

	for(int i=0;i<test.size();i++){
		cout<<pow_trivial(test[i],i)<<"\t\t\t\t"<<pow_unbalanced_fast(test[i],i)<<"\t\t\t\t"<<pow_balanced_fast(test[i],i)<<"\t\t\t\t"<<pow_balanced_fast_refined(test[i],i)<<"\n";
	}
    


}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	
    solve();
	// int n;
	// cin>>n;
	// while(n--)solve();
	return 0;
}