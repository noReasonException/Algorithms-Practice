#include <iostream>
#include <vector>
#include <sstream>
#include <math.h>
#include <set>
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define b char


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
			cout<<prefix<<"--->>"<<every<<"\n";
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
bool isOk(ui k_size,string &s,ui n){
	ui totalChanges=0;
	b localChar1='\0';
	b localChar2='\0';
	ui localChar1Hits = 0;
	ui localChar2Hits = 0;
	b currentChar='\0';
	for(ui each_char=0;each_char<k_size;each_char++){
		localChar1='\0';
		localChar2='\0';
		localChar1Hits = 0;
		localChar2Hits = 0;
		currentChar = '\0';
		for(ui each_segment=0;each_segment<(n/k_size);each_segment++){
			currentChar = s[(each_segment*k_size)+each_char];
			if(localChar1=='\0' && localChar2=='\0'){
				//no changes, set first variable here
				localChar1=currentChar;
				localChar1Hits++;
				
			}
			else if(localChar1==currentChar){
				localChar1Hits++;
			}
			else if(localChar1!='\0' && localChar1 != currentChar && localChar2=='\0'){
				//second character detected, if that happens once, we are good
				localChar2 = currentChar;
				localChar2Hits++;

			}
			else if(localChar1!=currentChar && localChar2==currentChar){
				localChar2Hits++;
			}
			else if (localChar1!='\0' && localChar2!='\0' && (localChar1!=currentChar && localChar2!=currentChar)){
				//conflict, shortcut, k_size is not possible
				return false;
			}
		}
		if(localChar1Hits>1 && localChar2Hits>1){
			//conflict, shortcut, k_size is not possible
			return false;

		}
		totalChanges+=min(localChar1Hits,localChar2Hits);
	}
	return totalChanges<2;
}
//A given candidate string k can only have a chance of being the minimum valid k if s.size() % k.size() == 0 (i.e 'fits exacly')
void solve(){
	ui n;
	string s;
	cin >> n;
	cin >> s;
	//see proof.pdf
	//complexity is n * k_size * (n/k_size) = n^2
	//solve is 0(n) and isOk2() is O(n) each call;
	for(ui i=1;i<n;i++){
		//does the current fit?
		if(!(n%(i))){ //yeap
			if(isOk(i,s,n)){
				cout<<i;
				return;
			}
		}
	}
	cout<<s.size();
}

int main(){
	ui t;
	cin>>t;
	while(t--){
		solve();
		cout<<"\n";
	}
	return 0;
}