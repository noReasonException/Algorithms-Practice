#include <iostream>
#include <vector>
#include <sstream>
#include <math.h>
#define ll long long
#define ull unsigned long long
#define ui unsigned int


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


	//12
	//12*100 = 1200
	//12*100 + 12 = 1212
	//
	//same on 26 base system, 26 lower case chars in ascii
	//
	//let original: 'abaa'
	//		2 solutions, aaaa(1) and abab(2), min is 1
	//Analysis of the original
	//		abaa = 1211 = 1*26^0 + 2*26^1 + 1*26^2 + 1*26^3
	//let call lookAhead('ab',4) 
	//		ab = 12 = 1*26^0 + 2*26^1 = 53
	//		totalSize is 4
	//		therefore, 'ab' needs to be repeated k times , where k = floor(prefix.size()/totalSize)
	//		k = 2
	//		
	// 		53


ull decode(string message){
	ull result=0;
	cinfo add "decoding message: " add message add "\n";
	for(int i=0;i<message.size();i++){
		cinfo add "\t character " add message[i] add " with value " add (message[i]-97+1)*(pow(26,i)) add "\n";
		result+=(message[i]-97+1)*(pow(26,i)); //'a' is 97 in char
	}
	return result;
}

//look-ahead-operation
ull decodeAhead(string message, int times){
	//given a message 'ab' and a number n, decodes the message produced
	//by concatenating 'ab' n times
	string messageToDecode(times,'a');
	return decode(messageToDecode);
}



void solve(){
	ui n;
	char temp;
	cin >>n;
	vector<char> input(n);
	stringstream buffer;
	for(int i=0;i<n;i++) {
		cin>>temp;
		input[i] = temp;
		buffer<< temp;
	}

	cout<<decode(buffer.str());


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