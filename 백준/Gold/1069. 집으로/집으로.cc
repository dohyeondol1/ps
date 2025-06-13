#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);

	double X, Y, D, T;
	cin >> X >> Y >> D >> T;

	double dist = sqrt(X*X + Y*Y);
	double answer = dist;

	cout << fixed;
	cout.precision(9);

	if(D < T) {
		cout << dist << '\n';
		return 0;
	}

	int jumps = dist/D;
	double remain = dist - jumps*D;

	if(jumps == 0) answer = min(answer, min(T+D-dist, 2.0*T));
	else answer = min(answer, min(jumps*T + remain, (jumps + 1.0)*T));

	cout << answer << '\n';
	return 0;
}