#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main()  {
	cin.tie(nullptr)->sync_with_stdio(false);

	int n, answer = 0;
	cin >> n;
	if(n == 0) {
		cout << answer;
		return 0;
	}

	vector<int> numbers(n);
	for(int i = 0; i < n; i++)
		cin >> numbers[i];

	sort(numbers.begin(), numbers.end());

	int index = round(n * 0.15);
	double sum = 0;
	for(int i = index; i < n-index; i++)
		sum += numbers[i];

	answer = round(sum / (n-index*2));
	cout << answer << '\n';

	return 0;
}