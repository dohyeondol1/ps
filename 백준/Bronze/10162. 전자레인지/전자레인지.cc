#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);

	int T;
	cin >> T;

	if(T%10 != 0) {
		cout << -1 << '\n';
		return 0;
	}

	int a = T/300;
	T %= 300;
	int b = T/60;
	T %= 60;
	int c = T/10;

	cout << a << ' ' << b << ' ' << c << '\n';
    return 0;
}