#include<iostream>
#include<string>
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	
	string str;
	cin >> str;

	int count = 0;
	char current = str[0];
	for(int i = 1; i < str.length(); i++) {
		if(current != str[i]) {
			count++;
			current = str[i];
		}
	}

	if(count%2 == 1) {
		count /= 2;
		count++;
	}
	else count /= 2;

	cout << count << '\n';
	return 0;
}