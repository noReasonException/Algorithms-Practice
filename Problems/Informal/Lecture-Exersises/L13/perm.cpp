#include <iostream>
#include <set>
#include <vector>
using namespace std;
#define ll long long
//forward refs
template <typename container> void cinfoCon(container& genericSequence, string id = "None", int depth = 0);

//debug utils
#ifdef DEBUG
#define cinfo cout
#define add <<
template <typename container> void cinfoCon(container& genericSequence, string id, int depth) {
    cout << "=============cinfoCon Debug (" << id << ") START =============\n";
    string prefix = "";
    for(int i = 0; i < depth; i++) prefix += "\t";

    for(auto every : genericSequence) {
        cout << prefix << every << "\n";
    }
    cout << "=============cinfoCon Debug (" << id << ") END =============\n";

}
#endif
#ifndef DEBUG
#define cinfo ;
#define add ;
template <typename container> void cinfoCon(container& genericSequence, string id, int depth) {
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

void print_instance(vector<int> instanceVector) {
    cout << "{";
    for(auto each : instanceVector) cout << each << ",";
    if(instanceVector.size() != 0)cout << "\b";
    cout << "}\n";
}
//Given an integer 1 <= n <= 10, write a recursive algorithm that prints all the permutations of the set {1,2,3,...,n}.
void solve(set<int> &data, set<int> instance,vector<int> instanceVector) {
    //set because i want faster search
    //i was about to use an unordered_set but we taiked about avoiding this.
    //vector because ordering matters 
    if(data.size() == instance.size()) {
        print_instance(instanceVector);
    } else {
        for(auto s : data) {
            if(instance.find(s) == instance.end()) {
                set<int>cloneSet = instance;
                vector<int>cloneVector = instanceVector;
                cloneSet.insert(s);
                cloneVector.push_back(s);
                solve(data, cloneSet,cloneVector);
            }
        }
    }



}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    int size = 1;
    cin >> n;
    set<int> data;
    set<int> instanceSet;
    vector<int> instanceVector;
    for(int i = 0; i < n; i++) {
        size *= (i + 1);
        data.insert(i+1);
    }
    solve(data, instanceSet,instanceVector);
    return 0;
}