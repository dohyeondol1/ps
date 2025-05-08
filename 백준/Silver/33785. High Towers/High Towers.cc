#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	
	long long n;
	cin >> n;
	
	long long answer = n*(n+1)*(n+2)/6;
	cout << answer << '\n';
	
	return 0;
}