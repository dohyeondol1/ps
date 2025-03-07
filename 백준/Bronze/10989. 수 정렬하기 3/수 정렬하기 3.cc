#include<iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int count_array[10001] = { 0 };
	int n,count;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> count;
		count_array[count]++;
	}

	for (int i = 1; i < 10001; i++)
		for (int j = 0; j < count_array[i]; j++)
			cout << i << '\n';
}