#include <iostream>
#include <vector>
using namespace std;
 
#define ll long long
 
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
void solve(ll n){
    ll seriesSum = (n*(n+1))/2;
    // S(6) = 1+2+3+4+5+6 = 3+3+4+5+6 = 15+6 = 21
    // S(7) = 1+2+3+4+5+6+7 = 21+7 = 28
    // 7 | 6,1
    // 7 , 5 , 2 | 6 , 1 , 4 , 3

    if(seriesSum%2!=0){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";

    vector<ll> set1;
    vector<ll> set2;
    if(n%2!=0) {
        set1.push_back(n);
        n-=1;
    }
    
    ll i = 0;
    bool isSet2=true;
    while(i<(n/2)){
        if(isSet2){
            set2.push_back(i+1);
            set2.push_back(n-i);
        }
        else{
            set1.push_back(i+1);
            set1.push_back(n-i);
        }
        i+=1;
        isSet2=!isSet2;
    }
    cout<<set1.size()<<"\n";
    for(ll i=0;i<set1.size();i++){
        cout<<set1[i]<<" ";
    }
    cout<<"\n";
    cout<<set2.size()<<"\n";
    for(ll i=0;i<set2.size();i++){
        cout<<set2[i]<<" ";
    }
    cout<<"\n";

	return;
}
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
 
	int n;
	cin>>n;
	solve(n);
	return 0;
}