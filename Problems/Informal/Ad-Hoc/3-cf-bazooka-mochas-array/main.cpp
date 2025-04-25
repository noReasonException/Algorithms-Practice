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

void solve(){
	
	unsigned int n;
	cin >> n;

	vector<unsigned long long> input(n);
	for(int i=0;i<n;i++) cin>>input[i];

	int monotonicity=0;
	for(int i=0;i<n && monotonicity<2;i++) {
		if(i>0 && input[i-1]>input[i]) monotonicity+=1;
	}
		

	if(monotonicity==0) cout<<"Yes";
	else if(monotonicity==1 && input[n-1]<=input[0]) cout<<"Yes";
	else cout<<"No";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	unsigned int t;
	cin>>t;
	while(t--){
		solve();
		cout<<"\n";
	}
	return 0;
}