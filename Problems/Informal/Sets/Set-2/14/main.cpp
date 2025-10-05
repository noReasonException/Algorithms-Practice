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
void solve(int n){
    if(n==1) cout<<1;
	else if(n==2||n==3) cout<<"NO SOLUTION\n";
    //The generalized solution does not work for n==4, however for n==4 a solution exists 
    else if(n==4) cout<<2<<" "<<4<<" "<<1<<" "<<3;
    else{
        //n>4 , a simple partition works
        /*
         * for n (let n=7 , n=8) 
         *      partition the array by hopping 2's (elements on odd and even positions)
         *                  n=7                 n=8
         *              1357 246            1357 2468       
         *      each partition is beatiful, as it is guaranteed that each element has distance of 2 from any neighboor.
         *      the only condition for the partitions to reunite, is if the last element of partition 1 has distance >1 from the first element of partition 2
         *      this holds for every n>4. Thats easy to prove
         *          Let a: Last element of partition 1
         *          Let b: First element of partition 2
         *              b = 2 (always)
         *              a = n%2!=0?n:n-1
         *          easy to see that abs(a-b)>1 for n>4
         *      Why this does not work for n==4?
         *              b=2
         *              a=3
         *              abs(3-2)==1
         */
        for(int i=1;i<=n;i+=2)cout<<(i==1?"":" ")<<i;
        for(int i=2;i<=n;i+=2)cout<<" "<<i;
    }
    cout<<"\n";

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