#include <iostream>
#include <vector>
using namespace std;

int main(){
	int T;
	cin >> T;
	
	
	for(int i = 0; i < T; i++){
	    int n, count = 0;
	    cin >> n;
	    vector<int> a(n);
	    for(int j = 0; j < n; j++) {
	        cin >> a[j];
	        for(int k = 0; k < j; k++) {
	            if(a[k] <= a[j]) count++;
	        }
	    }
	    cout << count << '\n';
	}
}