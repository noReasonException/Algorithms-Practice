#include <iostream>
#include <vector>
#include <set>
using namespace std;
#define ll long long
#define ld long double
//forward refs
template <typename container> void debug(container& genericSequence,string id="None", int depth=0);

//debug utils
#ifdef DEBUG
	template <typename container> void debug(container& genericSequence,string id, int depth){
		cout<<"=============Debug ("<<id<<") START =============\n";
		string prefix = "";
		for(int i=0;i<depth;i++) prefix+="\t";

		for(auto every: genericSequence){
			cout<<prefix<<every<<"\n";
		}
		cout<<"=============Debug ("<<id<<") END =============\n";

	}
#endif
#ifndef DEBUG
	template <typename container> void debug(container& genericSequence,string id, int depth){
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


int solve_actual_error(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	

	int n=10;
    ld d= 0.000001;
    ld l = 0, h = n;
    ld m,guess;
    //based on actual error
    do{
        m = l + (h-l)/2;
        guess = m*m;
        if(guess-n>0) h=m;
        else l=m;
    }while(abs(n-guess)>d);
    cout<<"approx "<<m<<" error is "<<n-guess<<"\n";
	
	return 0;
}

int solve_hl_diff(){
	
	int n=10;
    ld d= 0.000001;
    ld l = 0, h = n;
    ld m,guess;
    //based on h-l diff
    while(abs(h-l)>d){
        m = l + (h-l)/2;
        guess = m*m;
        if(guess-n>0) h=m;
        else l=m;
    }
    cout<<"approx "<<m<<" error is "<<n-guess<<"\n";
    
	
	return 0;
}

int main(){
    solve_actual_error();
    solve_hl_diff();
}