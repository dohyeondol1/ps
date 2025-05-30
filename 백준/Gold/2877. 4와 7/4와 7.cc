#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
	int K;
	cin >> K;
    int num = K+1;
	vector<int> temp;
	while(num > 0) {
		temp.push_back(num % 2);
		num /= 2;
	}
    
    vector<int> v;
	for(int i = temp.size()-1; i >= 0; i--)
		v.push_back(temp[i]);
    
	for(int i = 1; i < v.size(); i++) {
		if(v[i] == 0) cout << 4;
		else cout << 7;
	}
	cout << '\n';
    
    return 0;
}