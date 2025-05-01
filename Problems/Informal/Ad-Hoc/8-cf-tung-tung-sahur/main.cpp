#include <iostream>
#include <vector>
using namespace std;
#define ll long long
#define ull unsigned long long
//forward refs
template <typename container> void cinfoCon(container& genericSequence,string id="None", int depth=0);

//debug utils
#ifdef DEBUG
	template<typename T>void debug(vector<T> v){
		for(auto i:v){
			cout<<"\t"<<i<<"\n";
		}
		cout<<"\n";
	}
#endif
#ifndef DEBUG
	template<typename T>void debug(vector<T>v){}

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
void solve(){
	std::string p,s;
    cin>>p>>s;
    bool failed=false;
    if(p==s){
        cout<<"YES"<<"\n";
        return;
    }
    char state = p[0];
    int np = 0,ns = 0;
    int i=0,j=0;
    for(;i<p.size()&&(!failed);i++){
        if(p[i]==state) np+=1;
        else{
            //attempt to grab
            ns=0;
            for(;j<s.size();j++){
                if(s[j]==state){ns+=1;}
                else break;
            }
            if(ns<np || ns>2*np) {
                
                failed=true;
            }
            np=1;
            state=p[i];

        }
    }
    ns=0;
    for(;j<s.size();j++){
        if(s[j]==state){ns+=1;}
        else failed=true;
    }
    if(ns<np || ns>2*np) {
                
        failed=true;
    }
    cout<<(failed?("NO"):("YES"))<<"\n";

}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	

	ull t;
	cin>>t;
	while(t--)solve();
	return 0;
}