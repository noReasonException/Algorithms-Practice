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
 *	Criterion
 *		let array a1,a2,a3,a4 sorted, then its good if a4 = a1+a2+a3
 *		let array a1,a2,a3,a4, then max(a1,a2,a3,a4) = others(a1,a2,a3,a4)
*/
int solve(){
	long long numbers=0,current=0,currentSum=0,max=0,indexes=0;
	cin>>numbers;
	cinfo add "numbers\t" add numbers add "\n";
	while(numbers--){
		cin>>current;
		if(current>max)max=current;
		if(max==currentSum+current-max) {
			indexes+=1;
			cinfo add "\t\t\t\tindex is now" add indexes add "\n";
		}
		cinfo add "number\t" add current add "\n";
		cinfo add "\tmax\t" add max add "\n";
		cinfo add "\tcurrent sum\t" add currentSum add "\n";
		currentSum+=current;

	}
	return indexes;
}

int main(){
	int n;
	cin>>n;
	while(n--)cout<<solve()<<"\n";
	return 0;

}