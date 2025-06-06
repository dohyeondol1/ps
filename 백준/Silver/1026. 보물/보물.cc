#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int N, minS = 0;
	cin >> N;

	vector<int> A(N);
	vector<int> B(N);
	
	for(int &a : A) cin >> a;
	for(int &b : B) cin >> b;
	
	sort(A.begin(), A.end());
	sort(B.rbegin(), B.rend());
	
	for(int i = 0; i < N; i++) minS += A[i]*B[i];
	cout << minS;
	
	return 0;
}