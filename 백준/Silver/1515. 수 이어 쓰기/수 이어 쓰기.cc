#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);
    
	string N;
	cin >> N;
    int num = 1, idx = 0;
	while(1) {
		string str = to_string(num);
		for(int i = 0; i < str.length(); i++) {
			if(N[idx] == str[i]) idx++;
			if(idx == N.length()) {
				cout << num;
				return 0;
			}
		}
        num++;
	}
    
	return 0;
}